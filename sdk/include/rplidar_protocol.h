/*
 *  RPLIDAR SDK
 *
 *  Copyright (c) 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *  Copyright (c) 2014 - 2018 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

// RP-Lidar Input Packets
 
#define RPLIDAR_CMD_SYNC_BYTE        0xA5    //请求报文开始字节
#define RPLIDAR_CMDFLAG_HAS_PAYLOAD  0x80     //情报报文负载


#define RPLIDAR_ANS_SYNC_BYTE1       0xA5   //应答报文起始标志1
#define RPLIDAR_ANS_SYNC_BYTE2       0x5A    //应答报文起始标志2

#define RPLIDAR_ANS_PKTFLAG_LOOP     0x1    //多次应答模式

#define RPLIDAR_ANS_HEADER_SIZE_MASK        0x3FFFFFFF
#define RPLIDAR_ANS_HEADER_SUBTYPE_SHIFT    (30)

#if defined(_WIN32)
#pragma pack(1)
#endif


//请求报文格式
typedef struct _rplidar_cmd_packet_t {
    _u8 syncByte; //must be RPLIDAR_CMD_SYNC_BYTE     //起始标志
    _u8 cmd_flag;                                    //请求命令
    _u8 size;                                        //负载长度
    _u8 data[0];                                    //请求负载数据
} __attribute__((packed)) rplidar_cmd_packet_t;     //__attribute__ ((packed)) 的作用就是告诉编译器取消结构在编译过程中的优化对齐,按照实际占用字节数进行对齐     //使用之后才会是几字节就是几字节，否则就每个变量的字节长度都跟结构体中变量字节长度最长相同


typedef struct _rplidar_ans_header_t {
    _u8  syncByte1; // must be RPLIDAR_ANS_SYNC_BYTE1           //起始标志1
    _u8  syncByte2; // must be RPLIDAR_ANS_SYNC_BYTE2           //起始标志2
    _u32 size_q30_subtype; // see _u32 size:30; _u32 subType:2;      //应答报文长度
    _u8  type;                                                 //应答模式
} __attribute__((packed)) rplidar_ans_header_t;

#if defined(_WIN32)
#pragma pack()
#endif
