//-----------------------------------------------
// Copyright 2009 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL license
//-----------------------------------------------
//
// Occurance.h - Data structure holding the number of times
// the letter b appears in the string S before position i
//
#ifndef OCCURANCE_H
#define OCCURANCE_H
#include "STCommon.h"

// Power of 2 macros

// return true if x is a power of 2
#define IS_POWER_OF_2(x) ((x) & (x) - 1) == 0

// return the x % y given that y is a power of 2
#define MOD_POWER_2(x, y) (x) & ((y) - 1)
class BWT;

class Occurance
{
	public:
		
		// Constructors
		Occurance() : m_sampleRate(1) {}

		// Initialize the counts from the bwt string b
		void initialize(const BWStr& bwStr, int sampleRate);

		//
		inline const AlphaCount get(const BWStr& bwStr, size_t idx) const
		{
			// Quick path
			if(MOD_POWER_2(idx,m_sampleRate) == 0)
				return m_values[idx >> m_shift];

			// Calculate the nearest sample to this index
			size_t lower_idx = idx >> m_shift;
			size_t upper_idx = lower_idx + 1;
			size_t lower_start = lower_idx << m_shift;
			size_t upper_start = upper_idx << m_shift;

			AlphaCount sum;

			// Choose the closest index or force the choice to lower_idx is the upper_idx is invalid
			if((idx - lower_start < upper_start - idx) || upper_idx == m_values.size())
			{
				for(size_t j = lower_start + 1; j <= idx; ++j)
					sum.increment(bwStr[j]);
				return m_values[lower_idx] + sum;
			}
			else
			{
				for(size_t j = idx + 1; j <= upper_start; ++j)
					sum.increment(bwStr[j]);
				return m_values[upper_idx] - sum;
			}
		}

		// Get the alphacount difference between idx1 and idx0
		inline AlphaCount getDiff(const BWStr& bwStr, size_t idx0, size_t idx1) const
		{
			return get(bwStr, idx1) - get(bwStr, idx0);
		}
		
		inline BaseCount get(const BWStr& bwStr, char a, size_t idx) const
		{
			// Quick path
			if(MOD_POWER_2(idx,m_sampleRate) == 0)
				return m_values[idx >> m_shift].get(a);

			// Calculate the nearest sample to this index
			size_t lower_idx = idx >> m_shift;
			size_t upper_idx = lower_idx + 1;
			size_t lower_start = lower_idx << m_shift;
			size_t upper_start = upper_idx << m_shift;
			BaseCount sum = 0;
		
			// Choose the closest index or force the choice to lower_idx is the upper_idx is invalid
			if((idx - lower_start < upper_start - idx) || upper_idx == m_values.size())
			{
				for(size_t j = lower_start + 1; j <= idx; ++j)
				{
					if(bwStr[j] == a)
						++sum;
				}
				return m_values[lower_idx].get(a) + sum;
			}
			else
			{
				for(size_t j = idx + 1; j <= upper_start; ++j)
				{
					if(bwStr[j] == a)
						++sum;
				}
				return m_values[upper_idx].get(a) - sum;
			}
			
			//return get(bwStr, idx).get(a);
		}

		
		void set(char a, size_t i, BaseCount s);
		void print() const;
		size_t getByteSize() const;
		void validate(const BWStr& bwStr) const;

		friend std::ostream& operator<<(std::ostream& out, const Occurance& o);
		friend std::istream& operator>>(std::istream& in, Occurance& o);

	private:
		void calculateShiftValue();

		int m_shift;
		int m_sampleRate;
		std::vector<AlphaCount> m_values;
};


#endif