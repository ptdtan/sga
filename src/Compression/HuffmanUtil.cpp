//-----------------------------------------------
// Copyright 2010 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL 
//-----------------------------------------------
//
// HuffmanUtil - Simple huffman encoder/decoder for small alphabet
//
#include "HuffmanUtil.h"
#include "Alphabet.h"
#include <assert.h>
#include <iostream>
#include <queue>

HuffmanTreeCodec<int> HuffmanUtil::buildRLHuffmanTree()
{
    // Hardcoded counts 
    typedef std::map<int, int> IntIntMap;
    IntIntMap input;

    input.insert(std::make_pair(1,32663330));
    input.insert(std::make_pair(2,6627699));
    input.insert(std::make_pair(3,1889314));
    input.insert(std::make_pair(4,836362));
    input.insert(std::make_pair(5,746639));
    input.insert(std::make_pair(6,991933));
    input.insert(std::make_pair(7,1353892));
    input.insert(std::make_pair(8,1705611));
    input.insert(std::make_pair(9,1942392));
    input.insert(std::make_pair(10,2001377));
    input.insert(std::make_pair(11,1887666));
    input.insert(std::make_pair(12,1646809));
    input.insert(std::make_pair(13,1332408));
    input.insert(std::make_pair(14,1022598));
    input.insert(std::make_pair(15,756765));
    input.insert(std::make_pair(16,559331));
    /*input.insert(std::make_pair(17,428257));
    input.insert(std::make_pair(18,345921));
    input.insert(std::make_pair(19,297472));
    input.insert(std::make_pair(20,268562));
    input.insert(std::make_pair(21,247393));
    input.insert(std::make_pair(22,226436));
    input.insert(std::make_pair(23,204497));
    input.insert(std::make_pair(24,180382));
    input.insert(std::make_pair(25,156150));
    input.insert(std::make_pair(26,133070));
    input.insert(std::make_pair(27,112234));
    input.insert(std::make_pair(28,94537));
    input.insert(std::make_pair(29,80767));
    input.insert(std::make_pair(30,69259));
    input.insert(std::make_pair(31,60695));
    */
    input.insert(std::make_pair(32,52863));
    /*
    input.insert(std::make_pair(33,46801));
    input.insert(std::make_pair(34,42216));
    input.insert(std::make_pair(35,37341));
    input.insert(std::make_pair(36,33860));
    input.insert(std::make_pair(37,29999));
    input.insert(std::make_pair(38,27147));
    input.insert(std::make_pair(39,24767));
    input.insert(std::make_pair(40,22479));
    input.insert(std::make_pair(41,20439));
    input.insert(std::make_pair(42,18672));
    input.insert(std::make_pair(43,17603));
    input.insert(std::make_pair(44,16201));
    input.insert(std::make_pair(45,15388));
    input.insert(std::make_pair(46,14724));
    input.insert(std::make_pair(47,13855));
    input.insert(std::make_pair(48,13664));
    input.insert(std::make_pair(49,12583));
    input.insert(std::make_pair(50,11960));
    input.insert(std::make_pair(51,11216));
    input.insert(std::make_pair(52,10682));
    input.insert(std::make_pair(53,10043));
    input.insert(std::make_pair(54,9077));
    input.insert(std::make_pair(55,8717));
    input.insert(std::make_pair(56,8254));
    input.insert(std::make_pair(57,7571));
    input.insert(std::make_pair(58,6973));
    input.insert(std::make_pair(59,6473));
    input.insert(std::make_pair(60,6000));
    input.insert(std::make_pair(61,5529));
    input.insert(std::make_pair(62,4989));
    input.insert(std::make_pair(63,4808));
    */
    input.insert(std::make_pair(64,78833));
    return HuffmanTreeCodec<int>(input);
    
    /*
    HuffmanTreeCodec<int> defaultTree;
    for(int i = 0; i <= 31; ++i)
    {
        defaultTree.hackCode(i, i, 5);
    }
    return defaultTree;
    */
}