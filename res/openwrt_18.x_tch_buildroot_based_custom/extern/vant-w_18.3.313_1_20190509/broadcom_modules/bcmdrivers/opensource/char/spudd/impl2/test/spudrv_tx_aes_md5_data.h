/*
<:copyright-BRCM:2007:DUAL/GPL:standard

   Copyright (c) 2007 Broadcom 
   All Rights Reserved

Unless you and Broadcom execute a separate written software license
agreement governing use of this software, this software is licensed
to you under the terms of the GNU General Public License version 2
(the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
with the following added to such license:

   As a special exception, the copyright holders of this software give
   you permission to link this software with independent modules, and
   to copy and distribute the resulting executable under terms of your
   choice, provided that you also meet, for each linked independent
   module, the terms and conditions of the license of that module.
   An independent module is a module which is not derived from this
   software.  The special exception does not apply to any modifications
   of the software.

Not withstanding the above, under no circumstances may you combine
this software in any way with any other Broadcom software provided
under a license other than the GPL, without Broadcom's express prior
written consent.

:>
*/
/***************************************************************************
 * File Name  : 
 *
 * Description: 
 *              
 ***************************************************************************/
#ifndef __SPUDRV_TX_AES_MD5_DATA_H__
#define __SPUDRV_TX_AES_MD5_DATA_H__

#if defined(CONFIG_BCM_SPU_TEST)
//

// Automatically generated vector file.

//

// Vector format is: {EOP, SOP, PKT_DATA}.

//

// Example vectors:

//     101234567 // EOP = 0, SOP = 1, PKT_DATA = 01234567

//     089abcdef // EOP = 0, SOP = 0, PKT_DATA = 89abcdef

//     213572468 // EOP = 1, SOP = 0, PKT_DATA = 13572468

//

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt0_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x80802830,// 4 SCX   2 

    0x00006300,// 5 SCX   3 

    0xad22b6d0,// 6 SCX   4 

    0x7bd8e197,// 7 SCX   5 

    0x98c622c6,// 8 SCX   6 

    0x28dd361a,// 9 SCX   7 

    0xf0ce73c9,// 10 SCX   8 

    0xcbe306fc,// 11 SCX   9 

    0x4522f72b,// 12 SCX  10 

    0xf44c7cb9,// 13 SCX  11 

    0x6cb32c5c,// 14 SCX  12 

    0x7d7d056d,// 15 SCX  13 

    0xeb51374d,// 16 SCX  14 

    0x54579a06,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 824 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 273 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 273 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 160 

/// BFD (ofst+len)cry  : 192 

/// BFD ofstiv         : 4 

/// BFD ofsticv        : 588 

    0x00000111,// 18 BFD   1 

    0x00a00020,// 19 BFD   2 

    0x024c0004,// 20 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : a 

    0x0a001577,// 21 MFM   1 

    0x6a991c00,// 22 MFM   2 

/// BDA is 207 words. 

/// BDA size     is 824 (0x338) 

/// BDA id       is 0xd8ea 

    0x0338d8ea,// 23 BDA   1 

/// PAY Generic Data size   : 824 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x5a0cbf1d,// 24 PAY   1 

    0xf5cd007c,// 25 PAY   2 

    0xc72a5e6a,// 26 PAY   3 

    0xfc9c85d5,// 27 PAY   4 

    0x26942087,// 28 PAY   5 

    0xfb3b5286,// 29 PAY   6 

    0x56fa3df1,// 30 PAY   7 

    0xb4f0fef8,// 31 PAY   8 

    0x45c876bb,// 32 PAY   9 

    0xe6bb8807,// 33 PAY  10 

    0x9455c8a9,// 34 PAY  11 

    0x4e237977,// 35 PAY  12 

    0x8e84ed67,// 36 PAY  13 

    0xd5e6e7a1,// 37 PAY  14 

    0xb6c4dc8b,// 38 PAY  15 

    0x4f790bd6,// 39 PAY  16 

    0x0318e91e,// 40 PAY  17 

    0xd4988d26,// 41 PAY  18 

    0x58be9890,// 42 PAY  19 

    0xfb342480,// 43 PAY  20 

    0xf6139bd5,// 44 PAY  21 

    0x70c21c11,// 45 PAY  22 

    0x0754561c,// 46 PAY  23 

    0xcf85b9d6,// 47 PAY  24 

    0xb2dbd063,// 48 PAY  25 

    0x6e3f2e10,// 49 PAY  26 

    0x9999e5a7,// 50 PAY  27 

    0xc5cd7736,// 51 PAY  28 

    0x7fa4c518,// 52 PAY  29 

    0x610de9a5,// 53 PAY  30 

    0x1563869b,// 54 PAY  31 

    0xc9cb03a7,// 55 PAY  32 

    0x4c0eb75d,// 56 PAY  33 

    0xbf7b6114,// 57 PAY  34 

    0xeeb6e552,// 58 PAY  35 

    0x20e71bc0,// 59 PAY  36 

    0x46928f0b,// 60 PAY  37 

    0x8eec144d,// 61 PAY  38 

    0x43656b82,// 62 PAY  39 

    0x2bf32eab,// 63 PAY  40 

    0x63e9b89b,// 64 PAY  41 

    0x7abe2380,// 65 PAY  42 

    0x4e996dc3,// 66 PAY  43 

    0xe3b89e52,// 67 PAY  44 

    0xbee741f8,// 68 PAY  45 

    0x1628a973,// 69 PAY  46 

    0xe9b989f3,// 70 PAY  47 

    0x39dff57c,// 71 PAY  48 

    0x9e319e04,// 72 PAY  49 

    0x8a85d69d,// 73 PAY  50 

    0x740559b8,// 74 PAY  51 

    0xbb10a234,// 75 PAY  52 

    0x5d2c8bf4,// 76 PAY  53 

    0x5dbcf3fe,// 77 PAY  54 

    0x1b39ea0a,// 78 PAY  55 

    0xa150f1ef,// 79 PAY  56 

    0x3a823713,// 80 PAY  57 

    0x9e94ddf4,// 81 PAY  58 

    0xadb0c443,// 82 PAY  59 

    0xe5bf3d16,// 83 PAY  60 

    0xad342dc4,// 84 PAY  61 

    0x0202620a,// 85 PAY  62 

    0x38dfc533,// 86 PAY  63 

    0x31fdc1c5,// 87 PAY  64 

    0x3fbeea00,// 88 PAY  65 

    0x449d3b5c,// 89 PAY  66 

    0xad81eea9,// 90 PAY  67 

    0x5967e2ca,// 91 PAY  68 

    0x7af5ccaf,// 92 PAY  69 

    0xe4425c78,// 93 PAY  70 

    0x9be653b7,// 94 PAY  71 

    0xf967c487,// 95 PAY  72 

    0xf5a618cc,// 96 PAY  73 

    0xd19fa0de,// 97 PAY  74 

    0x4faa12f6,// 98 PAY  75 

    0x9e0fbe3a,// 99 PAY  76 

    0xd6acaf72,// 100 PAY  77 

    0xd0895e06,// 101 PAY  78 

    0x80000d38,// 102 PAY  79 

    0x85f71e8d,// 103 PAY  80 

    0xe0a0cb72,// 104 PAY  81 

    0x52ae8c41,// 105 PAY  82 

    0xcc4b247c,// 106 PAY  83 

    0x014ce28e,// 107 PAY  84 

    0x7ee4b0c9,// 108 PAY  85 

    0xa8c45108,// 109 PAY  86 

    0x963846eb,// 110 PAY  87 

    0x14dd1391,// 111 PAY  88 

    0x3e058496,// 112 PAY  89 

    0xe4949e46,// 113 PAY  90 

    0xe71c4610,// 114 PAY  91 

    0x978564b0,// 115 PAY  92 

    0x71c4d072,// 116 PAY  93 

    0x598d7451,// 117 PAY  94 

    0x2c4d7beb,// 118 PAY  95 

    0xa8788caf,// 119 PAY  96 

    0x29a03f10,// 120 PAY  97 

    0x8a9be6c7,// 121 PAY  98 

    0x9b8e1585,// 122 PAY  99 

    0xd4bb5a96,// 123 PAY 100 

    0xee3bc58e,// 124 PAY 101 

    0x77f3c5a5,// 125 PAY 102 

    0x56738ab0,// 126 PAY 103 

    0x979aee5a,// 127 PAY 104 

    0xb97c6089,// 128 PAY 105 

    0x1b853d14,// 129 PAY 106 

    0xbd844109,// 130 PAY 107 

    0x264a05f6,// 131 PAY 108 

    0x13009385,// 132 PAY 109 

    0x7c55dd44,// 133 PAY 110 

    0xbd731af6,// 134 PAY 111 

    0xf43e93f9,// 135 PAY 112 

    0x503303df,// 136 PAY 113 

    0x1874ce3f,// 137 PAY 114 

    0x383f4ac8,// 138 PAY 115 

    0xcc76c488,// 139 PAY 116 

    0x22e9368c,// 140 PAY 117 

    0x75f22075,// 141 PAY 118 

    0x5d9ba284,// 142 PAY 119 

    0xe31e8feb,// 143 PAY 120 

    0xb0259a6c,// 144 PAY 121 

    0x1d8ecda5,// 145 PAY 122 

    0xb5373dea,// 146 PAY 123 

    0x5332e9ae,// 147 PAY 124 

    0x1c56ac52,// 148 PAY 125 

    0xa8cf3119,// 149 PAY 126 

    0x66b0aad3,// 150 PAY 127 

    0xbae5452a,// 151 PAY 128 

    0x0bb58c2d,// 152 PAY 129 

    0x56cc303e,// 153 PAY 130 

    0x2ce6a6c2,// 154 PAY 131 

    0xb162a135,// 155 PAY 132 

    0xefa0ed66,// 156 PAY 133 

    0xc3522e3e,// 157 PAY 134 

    0x05e25ce3,// 158 PAY 135 

    0xcb2f748b,// 159 PAY 136 

    0xd237ae06,// 160 PAY 137 

    0x909d1255,// 161 PAY 138 

    0xef8beff6,// 162 PAY 139 

    0x2e6ad892,// 163 PAY 140 

    0xcd1e459c,// 164 PAY 141 

    0xdf74e905,// 165 PAY 142 

    0x45d6c4eb,// 166 PAY 143 

    0xd94ee7cf,// 167 PAY 144 

    0x9c67cc94,// 168 PAY 145 

    0xa7ad4014,// 169 PAY 146 

    0xb31e419f,// 170 PAY 147 

    0x63062a8f,// 171 PAY 148 

    0x941b27d6,// 172 PAY 149 

    0x6b8ebe10,// 173 PAY 150 

    0x1755e1a8,// 174 PAY 151 

    0x6bbd727c,// 175 PAY 152 

    0x0528997d,// 176 PAY 153 

    0xd3663865,// 177 PAY 154 

    0xeb029feb,// 178 PAY 155 

    0x984551aa,// 179 PAY 156 

    0x6e194c20,// 180 PAY 157 

    0x63d5ec8b,// 181 PAY 158 

    0xa1050fac,// 182 PAY 159 

    0xcdfad5fd,// 183 PAY 160 

    0xe89d195c,// 184 PAY 161 

    0x09333d1b,// 185 PAY 162 

    0xd5434c67,// 186 PAY 163 

    0x8377359b,// 187 PAY 164 

    0x7b3a7743,// 188 PAY 165 

    0xc8eab1a0,// 189 PAY 166 

    0x16faee1e,// 190 PAY 167 

    0x839ed7f0,// 191 PAY 168 

    0xde6cecb0,// 192 PAY 169 

    0x790eda7b,// 193 PAY 170 

    0xab6864bf,// 194 PAY 171 

    0x6a1b969e,// 195 PAY 172 

    0x38462341,// 196 PAY 173 

    0xba9e3451,// 197 PAY 174 

    0x93daeb34,// 198 PAY 175 

    0xb7a914fb,// 199 PAY 176 

    0xf6fc457b,// 200 PAY 177 

    0x2ddcaec8,// 201 PAY 178 

    0x2a704908,// 202 PAY 179 

    0x992e0b25,// 203 PAY 180 

    0x5b6ec5bf,// 204 PAY 181 

    0x8dd03697,// 205 PAY 182 

    0xf4c2e939,// 206 PAY 183 

    0x896092ae,// 207 PAY 184 

    0x269984f0,// 208 PAY 185 

    0xfc2fa00e,// 209 PAY 186 

    0x71d1e9c8,// 210 PAY 187 

    0x3d1d7a8d,// 211 PAY 188 

    0x9f561d63,// 212 PAY 189 

    0xd322c8b6,// 213 PAY 190 

    0x046df476,// 214 PAY 191 

    0x772e50dd,// 215 PAY 192 

    0x9bdda5ff,// 216 PAY 193 

    0x8b649a68,// 217 PAY 194 

    0xa5c97dca,// 218 PAY 195 

    0x0b5aff7f,// 219 PAY 196 

    0x839f2697,// 220 PAY 197 

    0x6a3076de,// 221 PAY 198 

    0xc78fef59,// 222 PAY 199 

    0x9a968dfd,// 223 PAY 200 

    0xb1da9aaf,// 224 PAY 201 

    0x9339996d,// 225 PAY 202 

    0xfc7b0c5c,// 226 PAY 203 

    0xc13f3253,// 227 PAY 204 

    0x2b6687c8,// 228 PAY 205 

    0xe2d140f3,// 229 PAY 206 

/// STA is 1 words. 

/// STA num_pkts       : 99 

/// STA pkt_idx        : 152 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x93 

    0x02609363 // 230 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt1_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0b 

/// ECH pdu_tag        : 0x00 

    0x000b0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80842853,// 4 SCX   2 

    0x00001284,// 5 SCX   3 

    0xe967787a,// 6 SCX   4 

    0xbd27f8ed,// 7 SCX   5 

    0x2b6aafb4,// 8 SCX   6 

    0x2d829803,// 9 SCX   7 

    0x51a08fd2,// 10 SCX   8 

    0xd33276ae,// 11 SCX   9 

    0x6eb407cd,// 12 SCX  10 

    0xd45102f5,// 13 SCX  11 

    0x0f0a740c,// 14 SCX  12 

    0xf2ed4b38,// 15 SCX  13 

    0x2ed7675d,// 16 SCX  14 

    0x650d3851,// 17 SCX  15 

    0xeea36ccb,// 18 SCX  16 

    0x75f600bc,// 19 SCX  17 

    0xb9d12f80,// 20 SCX  18 

    0xba290c94,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 649 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 403 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 403 

/// BFD lencrypto      : 64 

/// BFD ofstcrypto     : 328 

/// BFD (ofst+len)cry  : 392 

/// BFD ofstiv         : 216 

/// BFD ofsticv        : 624 

    0x00000193,// 22 BFD   1 

    0x01480040,// 23 BFD   2 

    0x027000d8,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 7 

    0x0700458b,// 25 MFM   1 

    0xf0d00000,// 26 MFM   2 

/// BDA is 164 words. 

/// BDA size     is 649 (0x289) 

/// BDA id       is 0x3d82 

    0x02893d82,// 27 BDA   1 

/// PAY Generic Data size   : 649 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0xb575ed9c,// 28 PAY   1 

    0xd5a8c884,// 29 PAY   2 

    0xc909a88a,// 30 PAY   3 

    0x68a3d654,// 31 PAY   4 

    0xa9894a52,// 32 PAY   5 

    0xd766a30b,// 33 PAY   6 

    0xb6f28bf2,// 34 PAY   7 

    0x51b96760,// 35 PAY   8 

    0x90e7c55c,// 36 PAY   9 

    0xad423119,// 37 PAY  10 

    0x2cd9e26b,// 38 PAY  11 

    0xb6850d76,// 39 PAY  12 

    0x61d620c1,// 40 PAY  13 

    0x6e7b4edc,// 41 PAY  14 

    0x57344172,// 42 PAY  15 

    0x4d047828,// 43 PAY  16 

    0x6bc098e7,// 44 PAY  17 

    0xecd52ab6,// 45 PAY  18 

    0x64442b51,// 46 PAY  19 

    0xeb5545c0,// 47 PAY  20 

    0x7699a726,// 48 PAY  21 

    0xdc81ede5,// 49 PAY  22 

    0xaaa7cb0b,// 50 PAY  23 

    0xfee2cf9b,// 51 PAY  24 

    0x26bc2837,// 52 PAY  25 

    0x471dfa1d,// 53 PAY  26 

    0x36d22c0b,// 54 PAY  27 

    0xdea50b30,// 55 PAY  28 

    0xb0166f2d,// 56 PAY  29 

    0xf8fb0a8c,// 57 PAY  30 

    0xbb41fc45,// 58 PAY  31 

    0xdb02f966,// 59 PAY  32 

    0x6396b7a7,// 60 PAY  33 

    0xf77a0c65,// 61 PAY  34 

    0x38b77e0c,// 62 PAY  35 

    0xac7d2929,// 63 PAY  36 

    0xe96f7f09,// 64 PAY  37 

    0x49ebf04e,// 65 PAY  38 

    0xade20220,// 66 PAY  39 

    0x86e890d8,// 67 PAY  40 

    0x5f1c2437,// 68 PAY  41 

    0x4a50356f,// 69 PAY  42 

    0x5981f554,// 70 PAY  43 

    0xb8a746c9,// 71 PAY  44 

    0x6cfe9350,// 72 PAY  45 

    0x07aad8ec,// 73 PAY  46 

    0x7cc02c5f,// 74 PAY  47 

    0xe93c0867,// 75 PAY  48 

    0x4e122d56,// 76 PAY  49 

    0xc13b2c70,// 77 PAY  50 

    0xe819a591,// 78 PAY  51 

    0x09d64f38,// 79 PAY  52 

    0x81e25855,// 80 PAY  53 

    0x60038e25,// 81 PAY  54 

    0x6a1c7ef2,// 82 PAY  55 

    0xd537189a,// 83 PAY  56 

    0x2115dda8,// 84 PAY  57 

    0xeb552fcf,// 85 PAY  58 

    0x3c6bec36,// 86 PAY  59 

    0xd027b782,// 87 PAY  60 

    0xf9542110,// 88 PAY  61 

    0xbef9407a,// 89 PAY  62 

    0x319c892b,// 90 PAY  63 

    0xd11b1481,// 91 PAY  64 

    0x11b76615,// 92 PAY  65 

    0xfed8240a,// 93 PAY  66 

    0x4d5c6bd6,// 94 PAY  67 

    0xf070c82c,// 95 PAY  68 

    0x9681f0c0,// 96 PAY  69 

    0x2d24cf2b,// 97 PAY  70 

    0x043c7c29,// 98 PAY  71 

    0x1bca7090,// 99 PAY  72 

    0x2aa34bdf,// 100 PAY  73 

    0xba8bba4f,// 101 PAY  74 

    0x346625e1,// 102 PAY  75 

    0x419808ac,// 103 PAY  76 

    0x83b45019,// 104 PAY  77 

    0x19eb43d3,// 105 PAY  78 

    0x16c146bc,// 106 PAY  79 

    0x561b342b,// 107 PAY  80 

    0x00832e96,// 108 PAY  81 

    0xfb8a5175,// 109 PAY  82 

    0xc3cb0beb,// 110 PAY  83 

    0x396aea41,// 111 PAY  84 

    0x8a325659,// 112 PAY  85 

    0x3082193e,// 113 PAY  86 

    0xccad2fb7,// 114 PAY  87 

    0x5295cd3a,// 115 PAY  88 

    0x9324aefe,// 116 PAY  89 

    0x05cc3433,// 117 PAY  90 

    0xf7f2f50d,// 118 PAY  91 

    0xc529d5f0,// 119 PAY  92 

    0x3f4af490,// 120 PAY  93 

    0xd19ff3c9,// 121 PAY  94 

    0x50f08197,// 122 PAY  95 

    0x9a9e8805,// 123 PAY  96 

    0x35a55c8f,// 124 PAY  97 

    0x14af9838,// 125 PAY  98 

    0x72304c8b,// 126 PAY  99 

    0xe2f110bb,// 127 PAY 100 

    0xcb0be014,// 128 PAY 101 

    0x93daf9ea,// 129 PAY 102 

    0xb87bfc5f,// 130 PAY 103 

    0x723e859b,// 131 PAY 104 

    0x6b728bbc,// 132 PAY 105 

    0x280ade51,// 133 PAY 106 

    0x7c9a52ec,// 134 PAY 107 

    0x49a25a9e,// 135 PAY 108 

    0x850f33f1,// 136 PAY 109 

    0x2ded73b5,// 137 PAY 110 

    0xf9abedd5,// 138 PAY 111 

    0x8bf446ce,// 139 PAY 112 

    0xa42c1fc1,// 140 PAY 113 

    0x25a84981,// 141 PAY 114 

    0x5bbb94b7,// 142 PAY 115 

    0x43f28df3,// 143 PAY 116 

    0x8617cae2,// 144 PAY 117 

    0x779c042c,// 145 PAY 118 

    0x027ce365,// 146 PAY 119 

    0x429be128,// 147 PAY 120 

    0x9c9e4975,// 148 PAY 121 

    0x6fdc8891,// 149 PAY 122 

    0x575a9b39,// 150 PAY 123 

    0xe267e582,// 151 PAY 124 

    0xd4492ee9,// 152 PAY 125 

    0xa30a1df4,// 153 PAY 126 

    0x1f1ef35e,// 154 PAY 127 

    0xbfa5559e,// 155 PAY 128 

    0x28e16bb6,// 156 PAY 129 

    0x24ce19ee,// 157 PAY 130 

    0xffd21990,// 158 PAY 131 

    0x07cbd5ec,// 159 PAY 132 

    0x429a3cd4,// 160 PAY 133 

    0x8f6a2dec,// 161 PAY 134 

    0xdf5b685b,// 162 PAY 135 

    0x87de9fe1,// 163 PAY 136 

    0x82fe3002,// 164 PAY 137 

    0x001ff3a5,// 165 PAY 138 

    0xc718b5df,// 166 PAY 139 

    0x740d2bc8,// 167 PAY 140 

    0x8c10ca4f,// 168 PAY 141 

    0x8a4cda41,// 169 PAY 142 

    0xe16fb23a,// 170 PAY 143 

    0xab2881d8,// 171 PAY 144 

    0xdf26d1ce,// 172 PAY 145 

    0xba6b99f0,// 173 PAY 146 

    0x67d80176,// 174 PAY 147 

    0x4ffd6f48,// 175 PAY 148 

    0x08844072,// 176 PAY 149 

    0xe477d365,// 177 PAY 150 

    0xd1ce729b,// 178 PAY 151 

    0xe7594d13,// 179 PAY 152 

    0xe588b38b,// 180 PAY 153 

    0xdb1d5193,// 181 PAY 154 

    0x6a141d8e,// 182 PAY 155 

    0xc9f07ada,// 183 PAY 156 

    0xc5e00d0a,// 184 PAY 157 

    0xdbe3fb25,// 185 PAY 158 

    0x3dbe9115,// 186 PAY 159 

    0x80388e31,// 187 PAY 160 

    0x41ba948c,// 188 PAY 161 

    0xcdeeebcd,// 189 PAY 162 

    0xf1000000,// 190 PAY 163 

/// STA is 1 words. 

/// STA num_pkts       : 178 

/// STA pkt_idx        : 98 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x80 

    0x018880b2 // 191 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt2_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x80842860,// 4 SCX   2 

    0x000052c4,// 5 SCX   3 

    0xf6c4159e,// 6 SCX   4 

    0xe15e1eff,// 7 SCX   5 

    0x1433f120,// 8 SCX   6 

    0xd82a7e6d,// 9 SCX   7 

    0x5a7f7043,// 10 SCX   8 

    0x0751cfbf,// 11 SCX   9 

    0x1bac8e05,// 12 SCX  10 

    0xcaa7d499,// 13 SCX  11 

    0x37922e5a,// 14 SCX  12 

    0x85a9f912,// 15 SCX  13 

    0xb72fbaa0,// 16 SCX  14 

    0x8d3bfa85,// 17 SCX  15 

    0x921ef119,// 18 SCX  16 

    0x32929f12,// 19 SCX  17 

    0x95b62db6,// 20 SCX  18 

    0x04449932,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 452 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 282 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 282 

/// BFD lencrypto      : 208 

/// BFD ofstcrypto     : 60 

/// BFD (ofst+len)cry  : 268 

/// BFD ofstiv         : 24 

/// BFD ofsticv        : 384 

    0x0000011a,// 22 BFD   1 

    0x003c00d0,// 23 BFD   2 

    0x01800018,// 24 BFD   3 

/// MFM is 9 words. 

/// MFM vldnibs        : 40 

    0x4000862d,// 25 MFM   1 

    0x8655e19e,// 26 MFM   2 

    0x24878576,// 27 MFM   3 

    0xa3e15c21,// 28 MFM   4 

    0x45f63ac8,// 29 MFM   5 

    0xeb146452,// 30 MFM   6 

    0xcff79a9d,// 31 MFM   7 

    0xfc4a3a28,// 32 MFM   8 

    0x1faf0000,// 33 MFM   9 

/// BDA is 114 words. 

/// BDA size     is 452 (0x1c4) 

/// BDA id       is 0xb49d 

    0x01c4b49d,// 34 BDA   1 

/// PAY Generic Data size   : 452 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xeab765d3,// 35 PAY   1 

    0xafec0890,// 36 PAY   2 

    0x4ca2e265,// 37 PAY   3 

    0x1d1f3c0b,// 38 PAY   4 

    0x330d7a5b,// 39 PAY   5 

    0xcc02efa7,// 40 PAY   6 

    0xa2eb13a5,// 41 PAY   7 

    0x184a4246,// 42 PAY   8 

    0x77f3d7ff,// 43 PAY   9 

    0x66be2e12,// 44 PAY  10 

    0x14d12842,// 45 PAY  11 

    0x4067c40a,// 46 PAY  12 

    0xd6864edb,// 47 PAY  13 

    0xc7feea40,// 48 PAY  14 

    0x444c3a30,// 49 PAY  15 

    0xcd8a44a1,// 50 PAY  16 

    0x61333245,// 51 PAY  17 

    0xbbaf9e37,// 52 PAY  18 

    0x7758e5fd,// 53 PAY  19 

    0xb5c4410f,// 54 PAY  20 

    0x67fe054a,// 55 PAY  21 

    0xeffe3acf,// 56 PAY  22 

    0xe071b887,// 57 PAY  23 

    0xa1c7e754,// 58 PAY  24 

    0xefea3dee,// 59 PAY  25 

    0x3238a850,// 60 PAY  26 

    0x4c579788,// 61 PAY  27 

    0x97a030b6,// 62 PAY  28 

    0x6fb0a97e,// 63 PAY  29 

    0xe1d7bd43,// 64 PAY  30 

    0xacaaae17,// 65 PAY  31 

    0xc70be247,// 66 PAY  32 

    0x73f50bee,// 67 PAY  33 

    0x6d73a9e5,// 68 PAY  34 

    0x9583502c,// 69 PAY  35 

    0x901a49aa,// 70 PAY  36 

    0x0ddb633f,// 71 PAY  37 

    0xdda79e3e,// 72 PAY  38 

    0xfbfb82be,// 73 PAY  39 

    0xf0ae3ef3,// 74 PAY  40 

    0xc45a87a9,// 75 PAY  41 

    0x3d62ee0c,// 76 PAY  42 

    0x28f65e76,// 77 PAY  43 

    0x2e381f61,// 78 PAY  44 

    0x0cb9e79e,// 79 PAY  45 

    0x1ef83914,// 80 PAY  46 

    0x54746dea,// 81 PAY  47 

    0x9cad6848,// 82 PAY  48 

    0x29f23b03,// 83 PAY  49 

    0xdebad079,// 84 PAY  50 

    0xb4377dde,// 85 PAY  51 

    0xae3e7400,// 86 PAY  52 

    0x0b3ec81d,// 87 PAY  53 

    0x78aee0d0,// 88 PAY  54 

    0x0fa1cb40,// 89 PAY  55 

    0x9aba55ee,// 90 PAY  56 

    0x94a00069,// 91 PAY  57 

    0x91012ab0,// 92 PAY  58 

    0x2a7d111a,// 93 PAY  59 

    0xa92fd242,// 94 PAY  60 

    0x57c22a5f,// 95 PAY  61 

    0x816e8dbe,// 96 PAY  62 

    0x86a20d3d,// 97 PAY  63 

    0xb5624636,// 98 PAY  64 

    0x0ef927b6,// 99 PAY  65 

    0x7320b2b0,// 100 PAY  66 

    0x55381087,// 101 PAY  67 

    0x1b259093,// 102 PAY  68 

    0x9a71cad0,// 103 PAY  69 

    0xebad383c,// 104 PAY  70 

    0xd9090ab0,// 105 PAY  71 

    0x14ec767b,// 106 PAY  72 

    0xe2eeeb0a,// 107 PAY  73 

    0x9d5ac76a,// 108 PAY  74 

    0xc521cd55,// 109 PAY  75 

    0xd322833a,// 110 PAY  76 

    0x4b4b40de,// 111 PAY  77 

    0xbbf578ef,// 112 PAY  78 

    0xe1fdd233,// 113 PAY  79 

    0x94725939,// 114 PAY  80 

    0x9f2f6da4,// 115 PAY  81 

    0xbb034c40,// 116 PAY  82 

    0x9e582d54,// 117 PAY  83 

    0x286633f8,// 118 PAY  84 

    0xc9c9dd8e,// 119 PAY  85 

    0x556ac168,// 120 PAY  86 

    0x7299084b,// 121 PAY  87 

    0x0f7546f7,// 122 PAY  88 

    0x37a93c2f,// 123 PAY  89 

    0x9bea4349,// 124 PAY  90 

    0x0694358f,// 125 PAY  91 

    0x0ddf6e96,// 126 PAY  92 

    0x3802e97b,// 127 PAY  93 

    0x7f20b1df,// 128 PAY  94 

    0x26222888,// 129 PAY  95 

    0xf91c92a4,// 130 PAY  96 

    0x33e49f58,// 131 PAY  97 

    0x11013264,// 132 PAY  98 

    0x264d81ca,// 133 PAY  99 

    0xa27897b3,// 134 PAY 100 

    0x2c08aa34,// 135 PAY 101 

    0x7fa621c4,// 136 PAY 102 

    0xa1087fde,// 137 PAY 103 

    0x893e93e1,// 138 PAY 104 

    0x7e34dd6a,// 139 PAY 105 

    0x74d5a1a9,// 140 PAY 106 

    0x9987243b,// 141 PAY 107 

    0xf5399cd7,// 142 PAY 108 

    0xcb40610c,// 143 PAY 109 

    0x1b42ab9f,// 144 PAY 110 

    0xfad3c639,// 145 PAY 111 

    0xbca65842,// 146 PAY 112 

    0xd976fb97,// 147 PAY 113 

/// STA is 1 words. 

/// STA num_pkts       : 74 

/// STA pkt_idx        : 189 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xe9 

    0x02f5e94a // 148 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt3_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x09 

/// ECH pdu_tag        : 0x00 

    0x00090000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x808628c1,// 4 SCX   2 

    0x000042c4,// 5 SCX   3 

    0xb3b33cf9,// 6 SCX   4 

    0xe241f18d,// 7 SCX   5 

    0xecd16d96,// 8 SCX   6 

    0xf87d4776,// 9 SCX   7 

    0x44a376b7,// 10 SCX   8 

    0x43db68e8,// 11 SCX   9 

    0x6ccc55ff,// 12 SCX  10 

    0x18914a33,// 13 SCX  11 

    0x76c4b48b,// 14 SCX  12 

    0xbd55b020,// 15 SCX  13 

    0x02537519,// 16 SCX  14 

    0x209140c7,// 17 SCX  15 

    0x85e1f745,// 18 SCX  16 

    0xb7a3d9e9,// 19 SCX  17 

    0x615a0175,// 20 SCX  18 

    0xbc00af74,// 21 SCX  19 

    0x304c2868,// 22 SCX  20 

    0x1cda680f,// 23 SCX  21 

    0x4dcef08c,// 24 SCX  22 

    0x63e7647f,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1370 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 560 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 560 

/// BFD lencrypto      : 224 

/// BFD ofstcrypto     : 268 

/// BFD (ofst+len)cry  : 492 

/// BFD ofstiv         : 160 

/// BFD ofsticv        : 1124 

    0x00000230,// 26 BFD   1 

    0x010c00e0,// 27 BFD   2 

    0x046400a0,// 28 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 3 

    0x0300ec10,// 29 MFM   1 

/// BDA is 344 words. 

/// BDA size     is 1370 (0x55a) 

/// BDA id       is 0x61e 

    0x055a061e,// 30 BDA   1 

/// PAY Generic Data size   : 1370 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xd5184464,// 31 PAY   1 

    0x39c6be8e,// 32 PAY   2 

    0x26186106,// 33 PAY   3 

    0xae693102,// 34 PAY   4 

    0xf08e0d79,// 35 PAY   5 

    0x1de7702d,// 36 PAY   6 

    0x96170c04,// 37 PAY   7 

    0xbc2f9644,// 38 PAY   8 

    0xe07819f7,// 39 PAY   9 

    0xd40428b7,// 40 PAY  10 

    0x286ab3b4,// 41 PAY  11 

    0x231f5937,// 42 PAY  12 

    0xda47bf40,// 43 PAY  13 

    0x64686114,// 44 PAY  14 

    0x2897d627,// 45 PAY  15 

    0x95d78651,// 46 PAY  16 

    0xa7ad8244,// 47 PAY  17 

    0x397e0e44,// 48 PAY  18 

    0x3f2f1bcc,// 49 PAY  19 

    0x8731fcad,// 50 PAY  20 

    0x9c7dcbb5,// 51 PAY  21 

    0x9a90c55c,// 52 PAY  22 

    0x7d40e723,// 53 PAY  23 

    0x84501466,// 54 PAY  24 

    0x15145f99,// 55 PAY  25 

    0xd96005b0,// 56 PAY  26 

    0xff6fe2ac,// 57 PAY  27 

    0x95d90456,// 58 PAY  28 

    0x783005c6,// 59 PAY  29 

    0xc7533985,// 60 PAY  30 

    0x191d543a,// 61 PAY  31 

    0x1b409860,// 62 PAY  32 

    0x5601a72e,// 63 PAY  33 

    0x4ebd7b2e,// 64 PAY  34 

    0x82f0044a,// 65 PAY  35 

    0x84176321,// 66 PAY  36 

    0x2aa7298f,// 67 PAY  37 

    0xcc6913d8,// 68 PAY  38 

    0xefc72c54,// 69 PAY  39 

    0x79af1a98,// 70 PAY  40 

    0x18bb4b1f,// 71 PAY  41 

    0x612bb8bb,// 72 PAY  42 

    0xfc31b5dc,// 73 PAY  43 

    0x39312b0f,// 74 PAY  44 

    0xfc06f893,// 75 PAY  45 

    0x63f93f69,// 76 PAY  46 

    0x62931922,// 77 PAY  47 

    0xeb057a7f,// 78 PAY  48 

    0x9bf40680,// 79 PAY  49 

    0xc4d98aad,// 80 PAY  50 

    0xc6b920ea,// 81 PAY  51 

    0x2c1f6cf6,// 82 PAY  52 

    0x7166525e,// 83 PAY  53 

    0xd1067da3,// 84 PAY  54 

    0xa3ca216d,// 85 PAY  55 

    0x4212dfd1,// 86 PAY  56 

    0x539ffe62,// 87 PAY  57 

    0x5d3c4213,// 88 PAY  58 

    0xbf1bd7f8,// 89 PAY  59 

    0x834ac4b0,// 90 PAY  60 

    0x65b9d5ce,// 91 PAY  61 

    0xf8c4c718,// 92 PAY  62 

    0xd044d0fe,// 93 PAY  63 

    0x62e48565,// 94 PAY  64 

    0x80e5d09e,// 95 PAY  65 

    0x4ba985c9,// 96 PAY  66 

    0x96ad0613,// 97 PAY  67 

    0x5b940eb3,// 98 PAY  68 

    0x11dc1a76,// 99 PAY  69 

    0x78ac6f1d,// 100 PAY  70 

    0x95783800,// 101 PAY  71 

    0x0ed163e5,// 102 PAY  72 

    0x9d898d09,// 103 PAY  73 

    0x998860f7,// 104 PAY  74 

    0xc5046813,// 105 PAY  75 

    0x71f6bb94,// 106 PAY  76 

    0x94eb5d89,// 107 PAY  77 

    0x9fa7c0f0,// 108 PAY  78 

    0x26d7fb3e,// 109 PAY  79 

    0x22a7a32a,// 110 PAY  80 

    0x3839b014,// 111 PAY  81 

    0xcaef2f14,// 112 PAY  82 

    0x9b59f6ab,// 113 PAY  83 

    0x6094ab29,// 114 PAY  84 

    0x2961acdb,// 115 PAY  85 

    0x3f712782,// 116 PAY  86 

    0xfc93bdee,// 117 PAY  87 

    0xf7af9ac2,// 118 PAY  88 

    0xb89b54a8,// 119 PAY  89 

    0x0daf5d73,// 120 PAY  90 

    0xc0a1a070,// 121 PAY  91 

    0x27cc2f49,// 122 PAY  92 

    0xd075562c,// 123 PAY  93 

    0x8aad5445,// 124 PAY  94 

    0x8893beaa,// 125 PAY  95 

    0xd8d5a879,// 126 PAY  96 

    0x455c6dcc,// 127 PAY  97 

    0xce14bc3f,// 128 PAY  98 

    0x36edca36,// 129 PAY  99 

    0x6f302343,// 130 PAY 100 

    0x299c4bb4,// 131 PAY 101 

    0x10e99023,// 132 PAY 102 

    0x45704079,// 133 PAY 103 

    0x7c3e4d8f,// 134 PAY 104 

    0x196a0a01,// 135 PAY 105 

    0xd1e2411c,// 136 PAY 106 

    0x77aea68b,// 137 PAY 107 

    0x157a6e79,// 138 PAY 108 

    0xc64b614d,// 139 PAY 109 

    0x4ee5bf35,// 140 PAY 110 

    0x279bcedc,// 141 PAY 111 

    0x17d9bae0,// 142 PAY 112 

    0xbb33df34,// 143 PAY 113 

    0x1858d183,// 144 PAY 114 

    0x1c5447a5,// 145 PAY 115 

    0x8b56b2f1,// 146 PAY 116 

    0x51dd4d8c,// 147 PAY 117 

    0x50d4c369,// 148 PAY 118 

    0xcc4848dd,// 149 PAY 119 

    0x090a581f,// 150 PAY 120 

    0x7154c623,// 151 PAY 121 

    0x20e06f28,// 152 PAY 122 

    0xd230cd36,// 153 PAY 123 

    0x18387bc3,// 154 PAY 124 

    0x25e464e5,// 155 PAY 125 

    0x511942c3,// 156 PAY 126 

    0x1a734805,// 157 PAY 127 

    0x5e21ef4a,// 158 PAY 128 

    0x0a13095a,// 159 PAY 129 

    0x7c2df976,// 160 PAY 130 

    0xe5258e51,// 161 PAY 131 

    0x4423f165,// 162 PAY 132 

    0x9a7dd970,// 163 PAY 133 

    0xd346c855,// 164 PAY 134 

    0xb0d7a56f,// 165 PAY 135 

    0xf827f69c,// 166 PAY 136 

    0xc3ea28ac,// 167 PAY 137 

    0x2d1bc12d,// 168 PAY 138 

    0xb725a87e,// 169 PAY 139 

    0x20c55069,// 170 PAY 140 

    0xd1ab3607,// 171 PAY 141 

    0xe6345e47,// 172 PAY 142 

    0x130e20bf,// 173 PAY 143 

    0x76a80e35,// 174 PAY 144 

    0xcff34685,// 175 PAY 145 

    0x871029af,// 176 PAY 146 

    0xc3608935,// 177 PAY 147 

    0x82746d95,// 178 PAY 148 

    0xc261a3a0,// 179 PAY 149 

    0x85123bf2,// 180 PAY 150 

    0xe953c370,// 181 PAY 151 

    0xa1979407,// 182 PAY 152 

    0xa7666b02,// 183 PAY 153 

    0xc4c9bfff,// 184 PAY 154 

    0x3a0db88c,// 185 PAY 155 

    0xce456b2f,// 186 PAY 156 

    0x027094af,// 187 PAY 157 

    0x13ad8613,// 188 PAY 158 

    0xa184df19,// 189 PAY 159 

    0x1ddb8ee9,// 190 PAY 160 

    0xabc9e496,// 191 PAY 161 

    0x58412737,// 192 PAY 162 

    0xa1c59d75,// 193 PAY 163 

    0x7a984ba6,// 194 PAY 164 

    0x25d35471,// 195 PAY 165 

    0xa91da804,// 196 PAY 166 

    0x8634312c,// 197 PAY 167 

    0x69d68323,// 198 PAY 168 

    0x01bc0fab,// 199 PAY 169 

    0x1770a954,// 200 PAY 170 

    0xa886a10f,// 201 PAY 171 

    0x69500aa2,// 202 PAY 172 

    0xfc387129,// 203 PAY 173 

    0x6ae74e6b,// 204 PAY 174 

    0x7a1c05be,// 205 PAY 175 

    0x8ab1413d,// 206 PAY 176 

    0xef5924e3,// 207 PAY 177 

    0x493e5e4b,// 208 PAY 178 

    0x5cc6fe94,// 209 PAY 179 

    0x74d62d47,// 210 PAY 180 

    0xed206e13,// 211 PAY 181 

    0xecd0a2a1,// 212 PAY 182 

    0xa98002f3,// 213 PAY 183 

    0x7393cce8,// 214 PAY 184 

    0xce4fb080,// 215 PAY 185 

    0x1ae1f05e,// 216 PAY 186 

    0x16ec4186,// 217 PAY 187 

    0x1761dad0,// 218 PAY 188 

    0x7ce26159,// 219 PAY 189 

    0x85a07975,// 220 PAY 190 

    0x97cec0a3,// 221 PAY 191 

    0xbd305df9,// 222 PAY 192 

    0x3b4caa89,// 223 PAY 193 

    0xb8168ef9,// 224 PAY 194 

    0xc9a6626e,// 225 PAY 195 

    0x359b37d9,// 226 PAY 196 

    0x300cb76f,// 227 PAY 197 

    0xcea01f20,// 228 PAY 198 

    0x0622f4da,// 229 PAY 199 

    0xae0b233d,// 230 PAY 200 

    0xe523f60d,// 231 PAY 201 

    0x0950e533,// 232 PAY 202 

    0x36a1849e,// 233 PAY 203 

    0xf778e1e2,// 234 PAY 204 

    0x00750d48,// 235 PAY 205 

    0xca31f766,// 236 PAY 206 

    0x02ea14e9,// 237 PAY 207 

    0xe85bdeed,// 238 PAY 208 

    0x0a630409,// 239 PAY 209 

    0xa42be44e,// 240 PAY 210 

    0xa4055a37,// 241 PAY 211 

    0x3610843d,// 242 PAY 212 

    0x6dd9972b,// 243 PAY 213 

    0x88ce1b36,// 244 PAY 214 

    0x4dcc177c,// 245 PAY 215 

    0x5d8b2593,// 246 PAY 216 

    0x97869cd8,// 247 PAY 217 

    0x1af02d55,// 248 PAY 218 

    0x1a1fde42,// 249 PAY 219 

    0xe66dddbf,// 250 PAY 220 

    0x059a7124,// 251 PAY 221 

    0xd2e8f7ff,// 252 PAY 222 

    0x51bdab53,// 253 PAY 223 

    0x9b3e841c,// 254 PAY 224 

    0x2c8a1683,// 255 PAY 225 

    0xe412ad30,// 256 PAY 226 

    0x170b18db,// 257 PAY 227 

    0x182514f7,// 258 PAY 228 

    0xea775719,// 259 PAY 229 

    0x5e732298,// 260 PAY 230 

    0xdf5c2193,// 261 PAY 231 

    0x61baf9be,// 262 PAY 232 

    0x5518c6c3,// 263 PAY 233 

    0x4b77ffe9,// 264 PAY 234 

    0xe5a073bf,// 265 PAY 235 

    0x79aabf6f,// 266 PAY 236 

    0xd578986c,// 267 PAY 237 

    0xa3ab7be7,// 268 PAY 238 

    0x6ed1c469,// 269 PAY 239 

    0xf4cdc9d2,// 270 PAY 240 

    0x0701ed05,// 271 PAY 241 

    0x56716e73,// 272 PAY 242 

    0xbbb3eb0f,// 273 PAY 243 

    0x0a809d8a,// 274 PAY 244 

    0x48cf0ee1,// 275 PAY 245 

    0x9f76a68a,// 276 PAY 246 

    0x61d4cc62,// 277 PAY 247 

    0xc3b35c40,// 278 PAY 248 

    0x1e8f7098,// 279 PAY 249 

    0xea712371,// 280 PAY 250 

    0xdec9aaf3,// 281 PAY 251 

    0x4c0e0b48,// 282 PAY 252 

    0x72529453,// 283 PAY 253 

    0x9861866c,// 284 PAY 254 

    0xb5f62c4a,// 285 PAY 255 

    0x0d171464,// 286 PAY 256 

    0x8c34a1ac,// 287 PAY 257 

    0x74e21190,// 288 PAY 258 

    0x766a9f1b,// 289 PAY 259 

    0x8b35a38a,// 290 PAY 260 

    0x0609d668,// 291 PAY 261 

    0x36647635,// 292 PAY 262 

    0x349390b4,// 293 PAY 263 

    0x922eba96,// 294 PAY 264 

    0xaa416ee5,// 295 PAY 265 

    0x826cbff9,// 296 PAY 266 

    0xc2dc4e36,// 297 PAY 267 

    0x59298811,// 298 PAY 268 

    0xcc38f797,// 299 PAY 269 

    0x8a8e1516,// 300 PAY 270 

    0x08cce90d,// 301 PAY 271 

    0xbbd88e8a,// 302 PAY 272 

    0x532de01d,// 303 PAY 273 

    0x3dfa1a82,// 304 PAY 274 

    0xad0f6d47,// 305 PAY 275 

    0x3e76235d,// 306 PAY 276 

    0xf047eeaa,// 307 PAY 277 

    0x5c37a513,// 308 PAY 278 

    0xa7d3aa7e,// 309 PAY 279 

    0xb9f38fd3,// 310 PAY 280 

    0x46f66432,// 311 PAY 281 

    0x1b745376,// 312 PAY 282 

    0xc9a0c318,// 313 PAY 283 

    0xa22c7b1e,// 314 PAY 284 

    0xdafc38cd,// 315 PAY 285 

    0xcd0bb840,// 316 PAY 286 

    0x69ad876e,// 317 PAY 287 

    0xeb1746ec,// 318 PAY 288 

    0x8bb65def,// 319 PAY 289 

    0x48e42211,// 320 PAY 290 

    0xaff69937,// 321 PAY 291 

    0x890d7904,// 322 PAY 292 

    0x2645c30b,// 323 PAY 293 

    0x4d15039d,// 324 PAY 294 

    0x2da9edf5,// 325 PAY 295 

    0x239ed126,// 326 PAY 296 

    0x26b2bee3,// 327 PAY 297 

    0x44693ffb,// 328 PAY 298 

    0xd845bbf4,// 329 PAY 299 

    0x073a2193,// 330 PAY 300 

    0x64a32fd1,// 331 PAY 301 

    0xe67e3e9b,// 332 PAY 302 

    0xddb148b3,// 333 PAY 303 

    0x8c9cca9b,// 334 PAY 304 

    0x21e933da,// 335 PAY 305 

    0x08d07b6f,// 336 PAY 306 

    0x9f2814ac,// 337 PAY 307 

    0x28e3a119,// 338 PAY 308 

    0x38a4c30f,// 339 PAY 309 

    0xad7f328c,// 340 PAY 310 

    0xf65bc813,// 341 PAY 311 

    0xb37275d2,// 342 PAY 312 

    0x0407c360,// 343 PAY 313 

    0x42838d66,// 344 PAY 314 

    0x60fdd401,// 345 PAY 315 

    0xcf57abc0,// 346 PAY 316 

    0x8a1e658a,// 347 PAY 317 

    0x2609394c,// 348 PAY 318 

    0xa2c663d5,// 349 PAY 319 

    0x71cddf17,// 350 PAY 320 

    0xbe8fb0e7,// 351 PAY 321 

    0xc59c35f5,// 352 PAY 322 

    0xacc4fb12,// 353 PAY 323 

    0xf96b41fc,// 354 PAY 324 

    0x65da2988,// 355 PAY 325 

    0xa9dfe988,// 356 PAY 326 

    0x711fb787,// 357 PAY 327 

    0xcee88a88,// 358 PAY 328 

    0xf42ab9f1,// 359 PAY 329 

    0xb12370e7,// 360 PAY 330 

    0x2b59f368,// 361 PAY 331 

    0x95717141,// 362 PAY 332 

    0x43f4e93c,// 363 PAY 333 

    0xd9fe3631,// 364 PAY 334 

    0x417479f6,// 365 PAY 335 

    0xa0f884e0,// 366 PAY 336 

    0x1b1257b3,// 367 PAY 337 

    0x4b856b06,// 368 PAY 338 

    0xb43c3fa1,// 369 PAY 339 

    0xde3286db,// 370 PAY 340 

    0xbf09bc60,// 371 PAY 341 

    0x4d0ea9d9,// 372 PAY 342 

    0x595b0000,// 373 PAY 343 

/// STA is 1 words. 

/// STA num_pkts       : 112 

/// STA pkt_idx        : 18 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xb1 

    0x0049b170 // 374 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt4_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8086280d,// 4 SCX   2 

    0x00002344,// 5 SCX   3 

    0x4184ce82,// 6 SCX   4 

    0xbfc876e6,// 7 SCX   5 

    0xaa0b2483,// 8 SCX   6 

    0xbe153dab,// 9 SCX   7 

    0x049046dd,// 10 SCX   8 

    0x4850632c,// 11 SCX   9 

    0x65f3341f,// 12 SCX  10 

    0x1062a2fb,// 13 SCX  11 

    0x0e004ff2,// 14 SCX  12 

    0xa0c6d91c,// 15 SCX  13 

    0x5893dd9f,// 16 SCX  14 

    0x193d62e5,// 17 SCX  15 

    0x7316f137,// 18 SCX  16 

    0xdabd5c4b,// 19 SCX  17 

    0x1a1a0212,// 20 SCX  18 

    0x2ee9aac3,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 888 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 275 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 275 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 108 

/// BFD (ofst+len)cry  : 140 

/// BFD ofstiv         : 92 

/// BFD ofsticv        : 408 

    0x00000113,// 22 BFD   1 

    0x006c0020,// 23 BFD   2 

    0x0198005c,// 24 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : d 

    0x0d00e8c5,// 25 MFM   1 

    0x28a8b53b,// 26 MFM   2 

    0x70000000,// 27 MFM   3 

/// BDA is 223 words. 

/// BDA size     is 888 (0x378) 

/// BDA id       is 0xff9 

    0x03780ff9,// 28 BDA   1 

/// PAY Generic Data size   : 888 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xa4c95238,// 29 PAY   1 

    0x60fa19cd,// 30 PAY   2 

    0xa850065e,// 31 PAY   3 

    0x84fd25ac,// 32 PAY   4 

    0x4a676e02,// 33 PAY   5 

    0x56cc6287,// 34 PAY   6 

    0xbe5963b0,// 35 PAY   7 

    0xaeee4bf4,// 36 PAY   8 

    0xf5579467,// 37 PAY   9 

    0x41da59ec,// 38 PAY  10 

    0x122e52be,// 39 PAY  11 

    0xb8da859d,// 40 PAY  12 

    0x3cc1c619,// 41 PAY  13 

    0x00f5ddc7,// 42 PAY  14 

    0x0b54faca,// 43 PAY  15 

    0x7fb1a00d,// 44 PAY  16 

    0xca36c0fe,// 45 PAY  17 

    0x987f9e50,// 46 PAY  18 

    0xc760e710,// 47 PAY  19 

    0xe16f0238,// 48 PAY  20 

    0x5b328b89,// 49 PAY  21 

    0x3742cc34,// 50 PAY  22 

    0x75fc7a22,// 51 PAY  23 

    0x0b395458,// 52 PAY  24 

    0x8544dc38,// 53 PAY  25 

    0x2f7bf171,// 54 PAY  26 

    0x22bb2b6e,// 55 PAY  27 

    0x4dd13e82,// 56 PAY  28 

    0x7dd974c7,// 57 PAY  29 

    0x5ee1ac37,// 58 PAY  30 

    0x30c8e937,// 59 PAY  31 

    0x53a41ae2,// 60 PAY  32 

    0x0278f0e7,// 61 PAY  33 

    0xd1e1a12d,// 62 PAY  34 

    0x2c716492,// 63 PAY  35 

    0x379f2fcc,// 64 PAY  36 

    0xaebdc9aa,// 65 PAY  37 

    0xc4f5d18f,// 66 PAY  38 

    0xf04fc99e,// 67 PAY  39 

    0xbebe6017,// 68 PAY  40 

    0xbe17a86d,// 69 PAY  41 

    0xb6861baa,// 70 PAY  42 

    0x0e4d5f68,// 71 PAY  43 

    0xc8d14490,// 72 PAY  44 

    0x91769e8b,// 73 PAY  45 

    0x0be3ad28,// 74 PAY  46 

    0x6d7fc0bd,// 75 PAY  47 

    0x05b755a7,// 76 PAY  48 

    0x135671e0,// 77 PAY  49 

    0xeeaa2d6f,// 78 PAY  50 

    0x952c1735,// 79 PAY  51 

    0xfc54cbf9,// 80 PAY  52 

    0x072391f9,// 81 PAY  53 

    0x94e6081d,// 82 PAY  54 

    0xc420c988,// 83 PAY  55 

    0xb1665448,// 84 PAY  56 

    0x877b61de,// 85 PAY  57 

    0x3431561d,// 86 PAY  58 

    0x13930043,// 87 PAY  59 

    0xef0ad1eb,// 88 PAY  60 

    0xe9f8cac3,// 89 PAY  61 

    0xa6ecfabf,// 90 PAY  62 

    0xb272f0e7,// 91 PAY  63 

    0x4dfbeb43,// 92 PAY  64 

    0x4a430343,// 93 PAY  65 

    0xe546afeb,// 94 PAY  66 

    0x4aca0e97,// 95 PAY  67 

    0xde3d73eb,// 96 PAY  68 

    0x965ea15a,// 97 PAY  69 

    0x03ed58a6,// 98 PAY  70 

    0x51ddffb5,// 99 PAY  71 

    0x65d5664c,// 100 PAY  72 

    0x4f3c3448,// 101 PAY  73 

    0xca1ac0ff,// 102 PAY  74 

    0x7009fe17,// 103 PAY  75 

    0xb4507d31,// 104 PAY  76 

    0xc7493345,// 105 PAY  77 

    0x607303b1,// 106 PAY  78 

    0x3a5cddf1,// 107 PAY  79 

    0xfd592b8a,// 108 PAY  80 

    0x0f144e7f,// 109 PAY  81 

    0xe3365cd2,// 110 PAY  82 

    0x6f2f1d68,// 111 PAY  83 

    0xeefd7a40,// 112 PAY  84 

    0x61ad4a74,// 113 PAY  85 

    0x38504f8d,// 114 PAY  86 

    0x5481dadc,// 115 PAY  87 

    0x6f5b049b,// 116 PAY  88 

    0x7ea1d21a,// 117 PAY  89 

    0x76476bfe,// 118 PAY  90 

    0x7ea799e8,// 119 PAY  91 

    0x0d237105,// 120 PAY  92 

    0x1b3c13b1,// 121 PAY  93 

    0x23b89a46,// 122 PAY  94 

    0xa0e4f5bf,// 123 PAY  95 

    0x21e3f1ed,// 124 PAY  96 

    0x2b01599d,// 125 PAY  97 

    0x7a05f786,// 126 PAY  98 

    0xd9fc0b49,// 127 PAY  99 

    0x5b9b7a6d,// 128 PAY 100 

    0xb0473b73,// 129 PAY 101 

    0xe1d352d1,// 130 PAY 102 

    0x86501747,// 131 PAY 103 

    0xcde073ba,// 132 PAY 104 

    0xce434bb5,// 133 PAY 105 

    0xea33e395,// 134 PAY 106 

    0x3d5d550d,// 135 PAY 107 

    0x43395db7,// 136 PAY 108 

    0x58428cbc,// 137 PAY 109 

    0xaa4e6068,// 138 PAY 110 

    0xa02f4c05,// 139 PAY 111 

    0xe03f5fa8,// 140 PAY 112 

    0x74aec080,// 141 PAY 113 

    0x7d4f4966,// 142 PAY 114 

    0xc263ab75,// 143 PAY 115 

    0x0b4f5ad2,// 144 PAY 116 

    0x591025ea,// 145 PAY 117 

    0x482b578b,// 146 PAY 118 

    0x01d684ed,// 147 PAY 119 

    0x220ab8df,// 148 PAY 120 

    0x8430ba45,// 149 PAY 121 

    0xa8f56e83,// 150 PAY 122 

    0xe7fc1c20,// 151 PAY 123 

    0xabc50c0a,// 152 PAY 124 

    0x9cd7db82,// 153 PAY 125 

    0xae2f8cfc,// 154 PAY 126 

    0x5fc230c1,// 155 PAY 127 

    0x2081d301,// 156 PAY 128 

    0x83c386d8,// 157 PAY 129 

    0xf9b79e7a,// 158 PAY 130 

    0x0213824b,// 159 PAY 131 

    0xfb8e34d0,// 160 PAY 132 

    0xa270b7a0,// 161 PAY 133 

    0x04b40780,// 162 PAY 134 

    0xb65480d0,// 163 PAY 135 

    0x4c17e57a,// 164 PAY 136 

    0xf956f3ce,// 165 PAY 137 

    0x50f284e7,// 166 PAY 138 

    0xbed5f332,// 167 PAY 139 

    0x3ef08e62,// 168 PAY 140 

    0xd0e77981,// 169 PAY 141 

    0xf8f0ba1c,// 170 PAY 142 

    0xd9f79ed4,// 171 PAY 143 

    0x3057e87c,// 172 PAY 144 

    0xe9d63259,// 173 PAY 145 

    0x4b464d65,// 174 PAY 146 

    0x141b2bbe,// 175 PAY 147 

    0xae74f3f0,// 176 PAY 148 

    0x34c15605,// 177 PAY 149 

    0xaf71562f,// 178 PAY 150 

    0x6e49e2ee,// 179 PAY 151 

    0xb59942a1,// 180 PAY 152 

    0x1b51f826,// 181 PAY 153 

    0x4a73113f,// 182 PAY 154 

    0x640eba58,// 183 PAY 155 

    0x2b163ef0,// 184 PAY 156 

    0xa4d3c018,// 185 PAY 157 

    0x83ef563a,// 186 PAY 158 

    0xe39f11ef,// 187 PAY 159 

    0x23ef7055,// 188 PAY 160 

    0x4a3cc2c3,// 189 PAY 161 

    0x8741858f,// 190 PAY 162 

    0xf4a023e9,// 191 PAY 163 

    0x144cf4be,// 192 PAY 164 

    0xc2531afe,// 193 PAY 165 

    0xf7ae99ce,// 194 PAY 166 

    0xcd9f338e,// 195 PAY 167 

    0x8467d369,// 196 PAY 168 

    0x1d51d005,// 197 PAY 169 

    0x3d5f4569,// 198 PAY 170 

    0xe48bf5e4,// 199 PAY 171 

    0x28776b32,// 200 PAY 172 

    0x3f382c3c,// 201 PAY 173 

    0xa1cec91e,// 202 PAY 174 

    0x77bd6663,// 203 PAY 175 

    0x88ee59c9,// 204 PAY 176 

    0x15c1728c,// 205 PAY 177 

    0x789ebcc8,// 206 PAY 178 

    0xad18dbc2,// 207 PAY 179 

    0x883ebc4a,// 208 PAY 180 

    0xdc7a7d89,// 209 PAY 181 

    0x54472eb8,// 210 PAY 182 

    0x2a20f0e4,// 211 PAY 183 

    0x00a2c8a1,// 212 PAY 184 

    0x50c4f110,// 213 PAY 185 

    0x73df4672,// 214 PAY 186 

    0x5498649a,// 215 PAY 187 

    0xfca132ff,// 216 PAY 188 

    0xa41b4410,// 217 PAY 189 

    0x5ca52e2b,// 218 PAY 190 

    0xa33c3e41,// 219 PAY 191 

    0xb01629a3,// 220 PAY 192 

    0x3847ed47,// 221 PAY 193 

    0x7181d28b,// 222 PAY 194 

    0xcb059f47,// 223 PAY 195 

    0xab2bd516,// 224 PAY 196 

    0xc9c1c692,// 225 PAY 197 

    0x1b73406c,// 226 PAY 198 

    0x6c16fd19,// 227 PAY 199 

    0xd8486a1b,// 228 PAY 200 

    0x573b2570,// 229 PAY 201 

    0x78289c34,// 230 PAY 202 

    0x7ad75cde,// 231 PAY 203 

    0xb884e70e,// 232 PAY 204 

    0xb68a7e8a,// 233 PAY 205 

    0x69cae614,// 234 PAY 206 

    0xef66a6ba,// 235 PAY 207 

    0x3cc7c0e8,// 236 PAY 208 

    0x647a5120,// 237 PAY 209 

    0x412613da,// 238 PAY 210 

    0x85949fd2,// 239 PAY 211 

    0x44d135a9,// 240 PAY 212 

    0x545a071a,// 241 PAY 213 

    0x48b401fe,// 242 PAY 214 

    0x3c605946,// 243 PAY 215 

    0xc3ef674b,// 244 PAY 216 

    0x5d4b1578,// 245 PAY 217 

    0x3f71533a,// 246 PAY 218 

    0x974454ff,// 247 PAY 219 

    0x62332356,// 248 PAY 220 

    0xc5dd4c62,// 249 PAY 221 

    0xea4ac58f,// 250 PAY 222 

/// STA is 1 words. 

/// STA num_pkts       : 162 

/// STA pkt_idx        : 20 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xce 

    0x0051cea2 // 251 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt5_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x0d 

/// ECH pdu_tag        : 0x00 

    0x000d0000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x809228aa,// 4 SCX   2 

    0x000013c2,// 5 SCX   3 

    0xe4662f53,// 6 SCX   4 

    0x4b8f6f66,// 7 SCX   5 

    0xce369a32,// 8 SCX   6 

    0xffc51cc0,// 9 SCX   7 

    0x645da58f,// 10 SCX   8 

    0xffafdafc,// 11 SCX   9 

    0x0309a2b8,// 12 SCX  10 

    0x2a091b0c,// 13 SCX  11 

    0x8642474a,// 14 SCX  12 

    0x42f220f1,// 15 SCX  13 

    0x67f213b9,// 16 SCX  14 

    0xc6969c97,// 17 SCX  15 

    0x22852d37,// 18 SCX  16 

    0x7281c970,// 19 SCX  17 

    0x498fe167,// 20 SCX  18 

    0x949935cc,// 21 SCX  19 

    0xa95b62d3,// 22 SCX  20 

    0xa27b4bf0,// 23 SCX  21 

    0x2f913d52,// 24 SCX  22 

    0xb03d584d,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1668 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 184 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 184 

/// BFD lencrypto      : 24 

/// BFD ofstcrypto     : 148 

/// BFD (ofst+len)cry  : 172 

/// BFD ofstiv         : 104 

/// BFD ofsticv        : 752 

    0x000000b8,// 26 BFD   1 

    0x00940018,// 27 BFD   2 

    0x02f00068,// 28 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : 11 

    0x1100f2d4,// 29 MFM   1 

    0x795b2413,// 30 MFM   2 

    0xce3b4000,// 31 MFM   3 

/// BDA is 418 words. 

/// BDA size     is 1668 (0x684) 

/// BDA id       is 0x93b0 

    0x068493b0,// 32 BDA   1 

/// PAY Generic Data size   : 1668 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x859bdb70,// 33 PAY   1 

    0x1b44da2f,// 34 PAY   2 

    0xcca7e3a2,// 35 PAY   3 

    0x781c4a0f,// 36 PAY   4 

    0xd1c5b0f9,// 37 PAY   5 

    0x5e421ec9,// 38 PAY   6 

    0x0ffc7201,// 39 PAY   7 

    0x84d51b29,// 40 PAY   8 

    0x2776564e,// 41 PAY   9 

    0x9d142aae,// 42 PAY  10 

    0x6dfe9486,// 43 PAY  11 

    0x0e0bcb54,// 44 PAY  12 

    0xff3c70e6,// 45 PAY  13 

    0x514ebae5,// 46 PAY  14 

    0x598a5d4d,// 47 PAY  15 

    0xc8d6fedf,// 48 PAY  16 

    0x73214929,// 49 PAY  17 

    0x3cfff304,// 50 PAY  18 

    0x0369c8ba,// 51 PAY  19 

    0xfd8fc0bb,// 52 PAY  20 

    0xd333ac1e,// 53 PAY  21 

    0x3992e941,// 54 PAY  22 

    0x311439cd,// 55 PAY  23 

    0x5886a9f9,// 56 PAY  24 

    0xaaa5ec2f,// 57 PAY  25 

    0xf71806d8,// 58 PAY  26 

    0x60281b3b,// 59 PAY  27 

    0x93b7c3ed,// 60 PAY  28 

    0x43c3921c,// 61 PAY  29 

    0xe0d26ee2,// 62 PAY  30 

    0xda9595db,// 63 PAY  31 

    0x2eebb757,// 64 PAY  32 

    0x293ad3dd,// 65 PAY  33 

    0x244f28ea,// 66 PAY  34 

    0xf6963a39,// 67 PAY  35 

    0x8fdfccad,// 68 PAY  36 

    0x862a84cc,// 69 PAY  37 

    0x6f90915e,// 70 PAY  38 

    0x8d4909dc,// 71 PAY  39 

    0x2ae3c0b6,// 72 PAY  40 

    0x6c690532,// 73 PAY  41 

    0x2c49a395,// 74 PAY  42 

    0xa198af91,// 75 PAY  43 

    0x94d78ddf,// 76 PAY  44 

    0xccb1ccbf,// 77 PAY  45 

    0x68058d40,// 78 PAY  46 

    0xb13faa40,// 79 PAY  47 

    0xfd235483,// 80 PAY  48 

    0xb58e7c98,// 81 PAY  49 

    0x6ebde46d,// 82 PAY  50 

    0xc773e68c,// 83 PAY  51 

    0x5697d2df,// 84 PAY  52 

    0x36e2e9c1,// 85 PAY  53 

    0x86d3bd3a,// 86 PAY  54 

    0xf3a61b89,// 87 PAY  55 

    0x96dc0490,// 88 PAY  56 

    0x7115148b,// 89 PAY  57 

    0x6a12b146,// 90 PAY  58 

    0x66c53c6e,// 91 PAY  59 

    0x92db6a64,// 92 PAY  60 

    0xe33b0886,// 93 PAY  61 

    0x16099a3b,// 94 PAY  62 

    0x9c36dd73,// 95 PAY  63 

    0x023e5bf1,// 96 PAY  64 

    0xcdf6d58c,// 97 PAY  65 

    0x18c31709,// 98 PAY  66 

    0x557b5cfc,// 99 PAY  67 

    0x8303c857,// 100 PAY  68 

    0xccbebb85,// 101 PAY  69 

    0x4fe96170,// 102 PAY  70 

    0x4a962de1,// 103 PAY  71 

    0x90506cef,// 104 PAY  72 

    0x3f798d21,// 105 PAY  73 

    0x7784bbde,// 106 PAY  74 

    0x8cf6bb8d,// 107 PAY  75 

    0xf29e4545,// 108 PAY  76 

    0x8a13e251,// 109 PAY  77 

    0xffda1fc5,// 110 PAY  78 

    0xb97c4f84,// 111 PAY  79 

    0x29179a3f,// 112 PAY  80 

    0x944e6bc0,// 113 PAY  81 

    0x5cbbe72e,// 114 PAY  82 

    0x14473f46,// 115 PAY  83 

    0x2a380928,// 116 PAY  84 

    0x89a50759,// 117 PAY  85 

    0x8579ab0f,// 118 PAY  86 

    0x07911953,// 119 PAY  87 

    0x1121d11e,// 120 PAY  88 

    0x23d7062b,// 121 PAY  89 

    0xc80cce02,// 122 PAY  90 

    0x506f616f,// 123 PAY  91 

    0x463e3ac3,// 124 PAY  92 

    0xf73b3189,// 125 PAY  93 

    0x65263aa9,// 126 PAY  94 

    0xea22d3ec,// 127 PAY  95 

    0x24ba946c,// 128 PAY  96 

    0xb132df82,// 129 PAY  97 

    0x44f1f1fc,// 130 PAY  98 

    0xc2997c01,// 131 PAY  99 

    0x4a045646,// 132 PAY 100 

    0x10b21ac1,// 133 PAY 101 

    0x9a525509,// 134 PAY 102 

    0x53dad7ca,// 135 PAY 103 

    0x00160dd2,// 136 PAY 104 

    0x3a12c010,// 137 PAY 105 

    0xd7c6acf9,// 138 PAY 106 

    0x3d95c33b,// 139 PAY 107 

    0x71c687bd,// 140 PAY 108 

    0xc00612a2,// 141 PAY 109 

    0x546c3b5e,// 142 PAY 110 

    0xc29d1448,// 143 PAY 111 

    0x1049063f,// 144 PAY 112 

    0x989ac79b,// 145 PAY 113 

    0x8dcf7d38,// 146 PAY 114 

    0xacaecc3d,// 147 PAY 115 

    0x19af538b,// 148 PAY 116 

    0x58435560,// 149 PAY 117 

    0x2636ed2d,// 150 PAY 118 

    0x46bf5c07,// 151 PAY 119 

    0x1b699171,// 152 PAY 120 

    0x5ce77a63,// 153 PAY 121 

    0x4502a6cf,// 154 PAY 122 

    0x99015c98,// 155 PAY 123 

    0x66347fdf,// 156 PAY 124 

    0x62207176,// 157 PAY 125 

    0x926942a8,// 158 PAY 126 

    0x60b4ff39,// 159 PAY 127 

    0x845b1122,// 160 PAY 128 

    0x99f87b91,// 161 PAY 129 

    0xf0ea5e93,// 162 PAY 130 

    0x8aac17d5,// 163 PAY 131 

    0xcc18c2e5,// 164 PAY 132 

    0x20254fac,// 165 PAY 133 

    0x1fb69c76,// 166 PAY 134 

    0x3460ea61,// 167 PAY 135 

    0x4b56dda8,// 168 PAY 136 

    0xd7d352ab,// 169 PAY 137 

    0x3fc4b935,// 170 PAY 138 

    0xbfaf2419,// 171 PAY 139 

    0x5a12ede5,// 172 PAY 140 

    0xf7d0496d,// 173 PAY 141 

    0x24301a6b,// 174 PAY 142 

    0x4bd63197,// 175 PAY 143 

    0xafe29e9e,// 176 PAY 144 

    0x3b8d1618,// 177 PAY 145 

    0x96f3a574,// 178 PAY 146 

    0xd79a8957,// 179 PAY 147 

    0x4d466390,// 180 PAY 148 

    0x8fa4b618,// 181 PAY 149 

    0x7b028dd6,// 182 PAY 150 

    0x03d19e17,// 183 PAY 151 

    0xb3cf22c2,// 184 PAY 152 

    0x1190df1b,// 185 PAY 153 

    0x0444c148,// 186 PAY 154 

    0x3cbd0066,// 187 PAY 155 

    0xd0bc3659,// 188 PAY 156 

    0x87cfd9ca,// 189 PAY 157 

    0xe2681a70,// 190 PAY 158 

    0x6a8b9dfd,// 191 PAY 159 

    0x8079ca0e,// 192 PAY 160 

    0x74cb2f3a,// 193 PAY 161 

    0xc9ec5319,// 194 PAY 162 

    0x86377421,// 195 PAY 163 

    0x57058b19,// 196 PAY 164 

    0x721f7513,// 197 PAY 165 

    0x65670a79,// 198 PAY 166 

    0xf9bb96aa,// 199 PAY 167 

    0xb64ce6d1,// 200 PAY 168 

    0x535d414d,// 201 PAY 169 

    0x9c3949da,// 202 PAY 170 

    0x01dac872,// 203 PAY 171 

    0x9d9c8d1a,// 204 PAY 172 

    0xb53f35c3,// 205 PAY 173 

    0x23068041,// 206 PAY 174 

    0x832aff31,// 207 PAY 175 

    0x377cec9f,// 208 PAY 176 

    0xffa8ea98,// 209 PAY 177 

    0x9e548eea,// 210 PAY 178 

    0x52ee8a41,// 211 PAY 179 

    0x31eba8a1,// 212 PAY 180 

    0xf5bcebd1,// 213 PAY 181 

    0x656c1c62,// 214 PAY 182 

    0xb0562511,// 215 PAY 183 

    0x38c1ec94,// 216 PAY 184 

    0x0eb47a0b,// 217 PAY 185 

    0x0f938c95,// 218 PAY 186 

    0x142c8c91,// 219 PAY 187 

    0x39667f16,// 220 PAY 188 

    0xbe5211c3,// 221 PAY 189 

    0x40f3eab8,// 222 PAY 190 

    0x3ec05799,// 223 PAY 191 

    0x63beca2c,// 224 PAY 192 

    0x0ce90189,// 225 PAY 193 

    0xf2f523be,// 226 PAY 194 

    0x0521f5af,// 227 PAY 195 

    0x28c5b335,// 228 PAY 196 

    0x41a454b3,// 229 PAY 197 

    0xf0a4a0a8,// 230 PAY 198 

    0x92c32f7a,// 231 PAY 199 

    0xdd54ffd4,// 232 PAY 200 

    0x8f48332e,// 233 PAY 201 

    0x5e309e3b,// 234 PAY 202 

    0xab1ddd2c,// 235 PAY 203 

    0x213f8019,// 236 PAY 204 

    0x9b265515,// 237 PAY 205 

    0xf5a912c0,// 238 PAY 206 

    0xc7689eba,// 239 PAY 207 

    0x46dfa4a2,// 240 PAY 208 

    0xe735b70b,// 241 PAY 209 

    0x2cdbb296,// 242 PAY 210 

    0x9f020ff1,// 243 PAY 211 

    0x4b60ae59,// 244 PAY 212 

    0x49dcc81f,// 245 PAY 213 

    0xf3ae6dbd,// 246 PAY 214 

    0x3f295801,// 247 PAY 215 

    0x22123895,// 248 PAY 216 

    0x2af91b11,// 249 PAY 217 

    0x4a7eb985,// 250 PAY 218 

    0x9cb1c441,// 251 PAY 219 

    0x85dc1439,// 252 PAY 220 

    0x5fd167cb,// 253 PAY 221 

    0x1b402a27,// 254 PAY 222 

    0xca7c73f1,// 255 PAY 223 

    0xc740e0fd,// 256 PAY 224 

    0xce2042df,// 257 PAY 225 

    0x174394a0,// 258 PAY 226 

    0xec486231,// 259 PAY 227 

    0xb5fcb45b,// 260 PAY 228 

    0xd43278a6,// 261 PAY 229 

    0x604301a6,// 262 PAY 230 

    0x6b40149b,// 263 PAY 231 

    0x28d55eb5,// 264 PAY 232 

    0x09c65999,// 265 PAY 233 

    0xfec805f3,// 266 PAY 234 

    0xd3033dd0,// 267 PAY 235 

    0xa538f918,// 268 PAY 236 

    0xeb7966f5,// 269 PAY 237 

    0x3a891b6b,// 270 PAY 238 

    0x702efb09,// 271 PAY 239 

    0x8168c724,// 272 PAY 240 

    0x4f941595,// 273 PAY 241 

    0x7908f5f0,// 274 PAY 242 

    0xf3513a28,// 275 PAY 243 

    0xb326c0b0,// 276 PAY 244 

    0x6a6c4d11,// 277 PAY 245 

    0x70b7b3d6,// 278 PAY 246 

    0xbc2e9f1d,// 279 PAY 247 

    0x25062c6d,// 280 PAY 248 

    0x887cfa08,// 281 PAY 249 

    0x4936ae61,// 282 PAY 250 

    0xa1a9c71d,// 283 PAY 251 

    0x5ecc4fbc,// 284 PAY 252 

    0x93db76d2,// 285 PAY 253 

    0x646b0872,// 286 PAY 254 

    0x6d42e156,// 287 PAY 255 

    0xbd29aed2,// 288 PAY 256 

    0x8808b23e,// 289 PAY 257 

    0x39abd139,// 290 PAY 258 

    0x4bd26a78,// 291 PAY 259 

    0xb792f5e1,// 292 PAY 260 

    0x2253d1a2,// 293 PAY 261 

    0x6b74d983,// 294 PAY 262 

    0x4e71411c,// 295 PAY 263 

    0xe5440340,// 296 PAY 264 

    0x3e622e13,// 297 PAY 265 

    0x09bf1658,// 298 PAY 266 

    0xb21a0815,// 299 PAY 267 

    0x80300d61,// 300 PAY 268 

    0x88b9e24d,// 301 PAY 269 

    0x28521ce1,// 302 PAY 270 

    0xcd18319f,// 303 PAY 271 

    0x9c76a0ce,// 304 PAY 272 

    0x4a3006cc,// 305 PAY 273 

    0xa2f26ebd,// 306 PAY 274 

    0xe4f8e9d5,// 307 PAY 275 

    0x650e3fd5,// 308 PAY 276 

    0xddfe95d7,// 309 PAY 277 

    0xc6f557ac,// 310 PAY 278 

    0x95eeabef,// 311 PAY 279 

    0x10aa9f1a,// 312 PAY 280 

    0x6a4d0ebf,// 313 PAY 281 

    0x9a212275,// 314 PAY 282 

    0xbe2bc602,// 315 PAY 283 

    0xa1e3c1ed,// 316 PAY 284 

    0xb95832e3,// 317 PAY 285 

    0xd11c419d,// 318 PAY 286 

    0xc4417b36,// 319 PAY 287 

    0xe09e9118,// 320 PAY 288 

    0x80660847,// 321 PAY 289 

    0x9f0bb8dd,// 322 PAY 290 

    0x2a57c097,// 323 PAY 291 

    0xc2ff1367,// 324 PAY 292 

    0xf77681f9,// 325 PAY 293 

    0x07ce3428,// 326 PAY 294 

    0x27087e23,// 327 PAY 295 

    0xc4c63a96,// 328 PAY 296 

    0x9b7f6fba,// 329 PAY 297 

    0xad6bab7b,// 330 PAY 298 

    0xc195fdcc,// 331 PAY 299 

    0x0d8839d8,// 332 PAY 300 

    0xa7926fe0,// 333 PAY 301 

    0x4cd56601,// 334 PAY 302 

    0xab0e1140,// 335 PAY 303 

    0x77e961d6,// 336 PAY 304 

    0x7aeaffce,// 337 PAY 305 

    0x4e534b1d,// 338 PAY 306 

    0x80d9c182,// 339 PAY 307 

    0x6c27c05e,// 340 PAY 308 

    0x976a6f33,// 341 PAY 309 

    0xd59c33d5,// 342 PAY 310 

    0xf7a0e752,// 343 PAY 311 

    0xa62da4dd,// 344 PAY 312 

    0x64e0197f,// 345 PAY 313 

    0x70509560,// 346 PAY 314 

    0x544f0ce1,// 347 PAY 315 

    0xbda549fc,// 348 PAY 316 

    0xc4a050aa,// 349 PAY 317 

    0xd7c57a27,// 350 PAY 318 

    0x5c100d58,// 351 PAY 319 

    0xc4d9f17d,// 352 PAY 320 

    0x53d8ebaf,// 353 PAY 321 

    0x035cc7b7,// 354 PAY 322 

    0x19b94e92,// 355 PAY 323 

    0x774db318,// 356 PAY 324 

    0xfdc0a61f,// 357 PAY 325 

    0x20e49b95,// 358 PAY 326 

    0x8d8c38b7,// 359 PAY 327 

    0x8576719f,// 360 PAY 328 

    0x403402f1,// 361 PAY 329 

    0x04b5e7cf,// 362 PAY 330 

    0x4f944bfe,// 363 PAY 331 

    0xb1e42617,// 364 PAY 332 

    0x50aa9b84,// 365 PAY 333 

    0xae022f87,// 366 PAY 334 

    0xd0456977,// 367 PAY 335 

    0xb0fd77ab,// 368 PAY 336 

    0x7a715674,// 369 PAY 337 

    0xe8f297cd,// 370 PAY 338 

    0x846526cb,// 371 PAY 339 

    0xc071e2f1,// 372 PAY 340 

    0x8a5b0c58,// 373 PAY 341 

    0x1b81169a,// 374 PAY 342 

    0x511ff082,// 375 PAY 343 

    0x2e00a3d4,// 376 PAY 344 

    0xf244abb8,// 377 PAY 345 

    0xc7dcebc9,// 378 PAY 346 

    0xaf26ab6b,// 379 PAY 347 

    0x3a0910ff,// 380 PAY 348 

    0xf074286b,// 381 PAY 349 

    0x888bea09,// 382 PAY 350 

    0x63970b76,// 383 PAY 351 

    0x25c51e22,// 384 PAY 352 

    0xa1faba6d,// 385 PAY 353 

    0x9f93d510,// 386 PAY 354 

    0x3fd05b43,// 387 PAY 355 

    0xf7073999,// 388 PAY 356 

    0xa3e1b965,// 389 PAY 357 

    0xb572a0be,// 390 PAY 358 

    0x3ddb8688,// 391 PAY 359 

    0x6fcb767f,// 392 PAY 360 

    0x67145efa,// 393 PAY 361 

    0xbefd8062,// 394 PAY 362 

    0x40d382ae,// 395 PAY 363 

    0xc060e924,// 396 PAY 364 

    0x2b16a2ca,// 397 PAY 365 

    0x9945e9d0,// 398 PAY 366 

    0x42b5f3df,// 399 PAY 367 

    0xd3b3e58e,// 400 PAY 368 

    0x8894b7d2,// 401 PAY 369 

    0xeb2937f3,// 402 PAY 370 

    0x0db6ae60,// 403 PAY 371 

    0xfef4f9ca,// 404 PAY 372 

    0x6f34ec46,// 405 PAY 373 

    0x874fa141,// 406 PAY 374 

    0x1e50a112,// 407 PAY 375 

    0x2187f56c,// 408 PAY 376 

    0xffb3519d,// 409 PAY 377 

    0x95350b20,// 410 PAY 378 

    0xf6634c9e,// 411 PAY 379 

    0x71f3e920,// 412 PAY 380 

    0x706c5a8a,// 413 PAY 381 

    0xe925f846,// 414 PAY 382 

    0x9d1d4980,// 415 PAY 383 

    0x39921b1d,// 416 PAY 384 

    0xd737259e,// 417 PAY 385 

    0x6564c0c5,// 418 PAY 386 

    0x88cc3aca,// 419 PAY 387 

    0x694a44a8,// 420 PAY 388 

    0xae8df30c,// 421 PAY 389 

    0xfd390fb8,// 422 PAY 390 

    0x4b9d3b38,// 423 PAY 391 

    0xa440e0f1,// 424 PAY 392 

    0xc8e1d5cd,// 425 PAY 393 

    0x688a7997,// 426 PAY 394 

    0x52956f97,// 427 PAY 395 

    0x4ac115bd,// 428 PAY 396 

    0x5ac2f51a,// 429 PAY 397 

    0x70668846,// 430 PAY 398 

    0x43e5d4c8,// 431 PAY 399 

    0x83b4d207,// 432 PAY 400 

    0x4cc21236,// 433 PAY 401 

    0xf982e2d6,// 434 PAY 402 

    0x647f5e1f,// 435 PAY 403 

    0x9c6cca6e,// 436 PAY 404 

    0x7799fb1d,// 437 PAY 405 

    0xcef89f5d,// 438 PAY 406 

    0xd7889140,// 439 PAY 407 

    0xdcefa07f,// 440 PAY 408 

    0x388d7622,// 441 PAY 409 

    0x8c11b723,// 442 PAY 410 

    0x558f5839,// 443 PAY 411 

    0xd60e96e6,// 444 PAY 412 

    0xf013c9ad,// 445 PAY 413 

    0x41302c10,// 446 PAY 414 

    0xedc5c112,// 447 PAY 415 

    0x5f0a810b,// 448 PAY 416 

    0xdd947454,// 449 PAY 417 

/// STA is 1 words. 

/// STA num_pkts       : 83 

/// STA pkt_idx        : 146 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x20 

    0x02492053 // 450 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt6_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x809028e9,// 4 SCX   2 

    0x000023c2,// 5 SCX   3 

    0xb65d5a5e,// 6 SCX   4 

    0xa9a4ce8c,// 7 SCX   5 

    0xea98e03d,// 8 SCX   6 

    0x5480c503,// 9 SCX   7 

    0x262afaa6,// 10 SCX   8 

    0xd17aea40,// 11 SCX   9 

    0x7bf5fe52,// 12 SCX  10 

    0xc1f89506,// 13 SCX  11 

    0xe677f69c,// 14 SCX  12 

    0x7e633525,// 15 SCX  13 

    0xf115518f,// 16 SCX  14 

    0x1ea8eed3,// 17 SCX  15 

    0x7cbea924,// 18 SCX  16 

    0x4b36fae8,// 19 SCX  17 

    0x23a4f8ff,// 20 SCX  18 

    0xf3ea8453,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1020 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 148 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 148 

/// BFD lencrypto      : 40 

/// BFD ofstcrypto     : 72 

/// BFD (ofst+len)cry  : 112 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 196 

    0x00000094,// 22 BFD   1 

    0x00480028,// 23 BFD   2 

    0x00c40010,// 24 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : 14 

    0x14003464,// 25 MFM   1 

    0x42284ca1,// 26 MFM   2 

    0xc7b29b7f,// 27 MFM   3 

/// BDA is 256 words. 

/// BDA size     is 1020 (0x3fc) 

/// BDA id       is 0x4456 

    0x03fc4456,// 28 BDA   1 

/// PAY Generic Data size   : 1020 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x5b771adb,// 29 PAY   1 

    0xc88449a0,// 30 PAY   2 

    0xf9ee1d00,// 31 PAY   3 

    0x1d26ea03,// 32 PAY   4 

    0xb931d1f2,// 33 PAY   5 

    0x9e94eeff,// 34 PAY   6 

    0x8e4cce2b,// 35 PAY   7 

    0xa9cca7b8,// 36 PAY   8 

    0xd139ac02,// 37 PAY   9 

    0xb254164a,// 38 PAY  10 

    0xa5ca2171,// 39 PAY  11 

    0xa86fc941,// 40 PAY  12 

    0x25ea8c83,// 41 PAY  13 

    0x6eca2ec0,// 42 PAY  14 

    0x21df7d8e,// 43 PAY  15 

    0x2f39cb04,// 44 PAY  16 

    0xf2176c2e,// 45 PAY  17 

    0xee91288d,// 46 PAY  18 

    0x11a566f5,// 47 PAY  19 

    0xcf960bdc,// 48 PAY  20 

    0xbb61d764,// 49 PAY  21 

    0xde89521b,// 50 PAY  22 

    0x01c42aab,// 51 PAY  23 

    0x7d50efbc,// 52 PAY  24 

    0x107e9d20,// 53 PAY  25 

    0x180a36a3,// 54 PAY  26 

    0xa06ac66d,// 55 PAY  27 

    0x21e32514,// 56 PAY  28 

    0x3bc31dd9,// 57 PAY  29 

    0x0a8f75b4,// 58 PAY  30 

    0x3a911387,// 59 PAY  31 

    0xc6dd1961,// 60 PAY  32 

    0x6580891f,// 61 PAY  33 

    0x91c27be1,// 62 PAY  34 

    0x484be6cd,// 63 PAY  35 

    0x7f1afb86,// 64 PAY  36 

    0x7d2f5f19,// 65 PAY  37 

    0x06f6a856,// 66 PAY  38 

    0x82ae7fec,// 67 PAY  39 

    0xd0b98dfd,// 68 PAY  40 

    0x0db859a1,// 69 PAY  41 

    0xd15e61dc,// 70 PAY  42 

    0x5ad313b4,// 71 PAY  43 

    0x5b44e27b,// 72 PAY  44 

    0xe6698e99,// 73 PAY  45 

    0xe2eb9c28,// 74 PAY  46 

    0xa6c67960,// 75 PAY  47 

    0x00ceb51b,// 76 PAY  48 

    0x2a436959,// 77 PAY  49 

    0x9266a1dc,// 78 PAY  50 

    0xf6c532ad,// 79 PAY  51 

    0x6b12d76a,// 80 PAY  52 

    0x2fe16663,// 81 PAY  53 

    0x0f591eea,// 82 PAY  54 

    0x35289d4a,// 83 PAY  55 

    0x016e6d27,// 84 PAY  56 

    0xf68a5841,// 85 PAY  57 

    0x78196903,// 86 PAY  58 

    0x23f2c675,// 87 PAY  59 

    0x9fe61437,// 88 PAY  60 

    0x533c0c0a,// 89 PAY  61 

    0x2f38dd2a,// 90 PAY  62 

    0x46c13b4b,// 91 PAY  63 

    0x76081e60,// 92 PAY  64 

    0x94712d99,// 93 PAY  65 

    0x189e3c4e,// 94 PAY  66 

    0x332a397e,// 95 PAY  67 

    0x8abe0574,// 96 PAY  68 

    0x1ce4ca2a,// 97 PAY  69 

    0x3c7452a6,// 98 PAY  70 

    0xa0783dd5,// 99 PAY  71 

    0xd5758451,// 100 PAY  72 

    0x7d2c7f7a,// 101 PAY  73 

    0x9ff87980,// 102 PAY  74 

    0x6142d783,// 103 PAY  75 

    0xdb817157,// 104 PAY  76 

    0x6e2423ca,// 105 PAY  77 

    0x39910e9f,// 106 PAY  78 

    0x79960acf,// 107 PAY  79 

    0xd499ba46,// 108 PAY  80 

    0x81eef62e,// 109 PAY  81 

    0xa6ccc6f0,// 110 PAY  82 

    0x40e078e3,// 111 PAY  83 

    0x2dcb285c,// 112 PAY  84 

    0x3a4f3608,// 113 PAY  85 

    0x765e658a,// 114 PAY  86 

    0x7c48a3db,// 115 PAY  87 

    0xefacfb19,// 116 PAY  88 

    0x14d2b986,// 117 PAY  89 

    0x1d40c4e0,// 118 PAY  90 

    0xbd66d086,// 119 PAY  91 

    0xf094d2db,// 120 PAY  92 

    0x5d05711a,// 121 PAY  93 

    0xa58cc855,// 122 PAY  94 

    0x40e6500b,// 123 PAY  95 

    0x6a056baf,// 124 PAY  96 

    0xdf5f9cc5,// 125 PAY  97 

    0x38064a44,// 126 PAY  98 

    0x2e3232ea,// 127 PAY  99 

    0xe9ca61ca,// 128 PAY 100 

    0xa767233c,// 129 PAY 101 

    0x7b7d59d1,// 130 PAY 102 

    0xb36257c9,// 131 PAY 103 

    0x8d377a3e,// 132 PAY 104 

    0xfdd95d90,// 133 PAY 105 

    0x33732497,// 134 PAY 106 

    0x7305e5f3,// 135 PAY 107 

    0x3d44e229,// 136 PAY 108 

    0xde0821aa,// 137 PAY 109 

    0xc376b2fa,// 138 PAY 110 

    0xc023dd47,// 139 PAY 111 

    0xf1092d09,// 140 PAY 112 

    0x540c6fef,// 141 PAY 113 

    0x7a76c0f1,// 142 PAY 114 

    0xdbca7e3a,// 143 PAY 115 

    0x891d8354,// 144 PAY 116 

    0x1e8b70e3,// 145 PAY 117 

    0xe4099b5f,// 146 PAY 118 

    0xf111ff68,// 147 PAY 119 

    0x919bfc92,// 148 PAY 120 

    0x14db5fe1,// 149 PAY 121 

    0xb731034e,// 150 PAY 122 

    0x5b41de56,// 151 PAY 123 

    0x2dc48a73,// 152 PAY 124 

    0xe7db8c47,// 153 PAY 125 

    0x169efc1a,// 154 PAY 126 

    0xa1a92c8a,// 155 PAY 127 

    0x1fdc7704,// 156 PAY 128 

    0xbef344bf,// 157 PAY 129 

    0xf8ebaa92,// 158 PAY 130 

    0x1814ab84,// 159 PAY 131 

    0x7e90971c,// 160 PAY 132 

    0xed09d208,// 161 PAY 133 

    0xe989f44d,// 162 PAY 134 

    0x39dbf19e,// 163 PAY 135 

    0x8d82a3bc,// 164 PAY 136 

    0xce120aed,// 165 PAY 137 

    0x7bd1da77,// 166 PAY 138 

    0x313ae237,// 167 PAY 139 

    0x6b4427f4,// 168 PAY 140 

    0x2c9289cd,// 169 PAY 141 

    0xe1cad597,// 170 PAY 142 

    0x6ae1bc01,// 171 PAY 143 

    0xe94a1699,// 172 PAY 144 

    0x4d5c50e4,// 173 PAY 145 

    0xf41962ef,// 174 PAY 146 

    0xe5e1629f,// 175 PAY 147 

    0x2b700d2f,// 176 PAY 148 

    0x706cd74a,// 177 PAY 149 

    0x9f0abfc1,// 178 PAY 150 

    0x545e4f8e,// 179 PAY 151 

    0x809c2787,// 180 PAY 152 

    0xa00a3a1e,// 181 PAY 153 

    0xfd318b33,// 182 PAY 154 

    0xd09b44f1,// 183 PAY 155 

    0xa928b4c6,// 184 PAY 156 

    0xd43c4b2c,// 185 PAY 157 

    0x70863114,// 186 PAY 158 

    0xcb4fb3b6,// 187 PAY 159 

    0xed9865c1,// 188 PAY 160 

    0x6a6abfd2,// 189 PAY 161 

    0x3329faba,// 190 PAY 162 

    0x829015a9,// 191 PAY 163 

    0x16581954,// 192 PAY 164 

    0x5ebc682d,// 193 PAY 165 

    0xe205d2ba,// 194 PAY 166 

    0x7d850073,// 195 PAY 167 

    0x15365694,// 196 PAY 168 

    0x961c07ba,// 197 PAY 169 

    0x647aacc1,// 198 PAY 170 

    0x74924e19,// 199 PAY 171 

    0x5ec9b543,// 200 PAY 172 

    0xa5a3db26,// 201 PAY 173 

    0x30120dfc,// 202 PAY 174 

    0xba168120,// 203 PAY 175 

    0x6f237746,// 204 PAY 176 

    0x552ca354,// 205 PAY 177 

    0xd7aaa735,// 206 PAY 178 

    0xa3f566c6,// 207 PAY 179 

    0xd0f404c4,// 208 PAY 180 

    0xfe3dbc3f,// 209 PAY 181 

    0x84d57ac8,// 210 PAY 182 

    0x1727618d,// 211 PAY 183 

    0x7df06c4c,// 212 PAY 184 

    0x6496b658,// 213 PAY 185 

    0x31b3c80b,// 214 PAY 186 

    0x2d97e322,// 215 PAY 187 

    0x6c770c68,// 216 PAY 188 

    0x69756623,// 217 PAY 189 

    0x8639ebae,// 218 PAY 190 

    0xd7105f92,// 219 PAY 191 

    0x9bdb4b18,// 220 PAY 192 

    0x110d2d86,// 221 PAY 193 

    0x67ad4d3a,// 222 PAY 194 

    0xcf270391,// 223 PAY 195 

    0x732b424e,// 224 PAY 196 

    0xeed2405c,// 225 PAY 197 

    0xb24df920,// 226 PAY 198 

    0x4515a6b7,// 227 PAY 199 

    0x74282536,// 228 PAY 200 

    0x1eef2183,// 229 PAY 201 

    0x7dea220b,// 230 PAY 202 

    0xa498a567,// 231 PAY 203 

    0x57ca2d8f,// 232 PAY 204 

    0x45aca0d8,// 233 PAY 205 

    0xb69fe4dd,// 234 PAY 206 

    0x469fd455,// 235 PAY 207 

    0xdbfe1a08,// 236 PAY 208 

    0xce268376,// 237 PAY 209 

    0x9481d97e,// 238 PAY 210 

    0x19918f54,// 239 PAY 211 

    0x8ad5481e,// 240 PAY 212 

    0x0dbc6726,// 241 PAY 213 

    0xdf13a634,// 242 PAY 214 

    0x1b60fec6,// 243 PAY 215 

    0xb5a064fc,// 244 PAY 216 

    0x355ec299,// 245 PAY 217 

    0x57b733b8,// 246 PAY 218 

    0x8d9a7e82,// 247 PAY 219 

    0x806e1a5d,// 248 PAY 220 

    0xde5bac48,// 249 PAY 221 

    0x70867048,// 250 PAY 222 

    0xba437dfd,// 251 PAY 223 

    0xd403c90d,// 252 PAY 224 

    0x273e89f5,// 253 PAY 225 

    0x9d36b1f2,// 254 PAY 226 

    0x1401ea32,// 255 PAY 227 

    0x932325f9,// 256 PAY 228 

    0x3c23aba9,// 257 PAY 229 

    0x0f168df4,// 258 PAY 230 

    0x8c9b3a27,// 259 PAY 231 

    0x9d15d8bc,// 260 PAY 232 

    0x76f0d5ea,// 261 PAY 233 

    0xce1e5604,// 262 PAY 234 

    0x0ddec7e2,// 263 PAY 235 

    0x67f6281c,// 264 PAY 236 

    0x073739a8,// 265 PAY 237 

    0x205c56e4,// 266 PAY 238 

    0xef63ec94,// 267 PAY 239 

    0x6fd392dc,// 268 PAY 240 

    0x91890090,// 269 PAY 241 

    0x7085ed17,// 270 PAY 242 

    0xb073ceab,// 271 PAY 243 

    0x558ee07c,// 272 PAY 244 

    0xffeb1a97,// 273 PAY 245 

    0x1b55ac65,// 274 PAY 246 

    0x4b74a900,// 275 PAY 247 

    0x72fd231e,// 276 PAY 248 

    0x42f4c8d2,// 277 PAY 249 

    0x80b32f98,// 278 PAY 250 

    0x7dea680c,// 279 PAY 251 

    0x5e264605,// 280 PAY 252 

    0x83176bb5,// 281 PAY 253 

    0x3c818bb7,// 282 PAY 254 

    0x7b360e31,// 283 PAY 255 

/// STA is 1 words. 

/// STA num_pkts       : 34 

/// STA pkt_idx        : 231 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xdf 

    0x039cdf22 // 284 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt7_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x808528c1,// 4 SCX   2 

    0x00007384,// 5 SCX   3 

    0xfe8afac4,// 6 SCX   4 

    0xdccd60d0,// 7 SCX   5 

    0xa013a76b,// 8 SCX   6 

    0x19de45af,// 9 SCX   7 

    0x4e26a28f,// 10 SCX   8 

    0xaf97c581,// 11 SCX   9 

    0xd6c7b8a4,// 12 SCX  10 

    0xeb6e0ad1,// 13 SCX  11 

    0xc2974028,// 14 SCX  12 

    0x19230a38,// 15 SCX  13 

    0xb8b0186c,// 16 SCX  14 

    0x8d36c595,// 17 SCX  15 

    0x38b3920a,// 18 SCX  16 

    0x4fd31fcc,// 19 SCX  17 

    0x4825ca59,// 20 SCX  18 

    0x5483eef2,// 21 SCX  19 

    0x625542b1,// 22 SCX  20 

    0x51c56f0d,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 490 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 333 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 333 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 144 

/// BFD (ofst+len)cry  : 224 

/// BFD ofstiv         : 24 

/// BFD ofsticv        : 448 

    0x0000014d,// 24 BFD   1 

    0x00900050,// 25 BFD   2 

    0x01c00018,// 26 BFD   3 

/// MFM is 11 words. 

/// MFM vldnibs        : 4e 

    0x4e00f48a,// 27 MFM   1 

    0xc195121e,// 28 MFM   2 

    0x4cb57182,// 29 MFM   3 

    0xfa2f9ac2,// 30 MFM   4 

    0x9a447090,// 31 MFM   5 

    0xd6d3d075,// 32 MFM   6 

    0x8d304215,// 33 MFM   7 

    0xa1b28ef5,// 34 MFM   8 

    0xc0671280,// 35 MFM   9 

    0xf72edde0,// 36 MFM  10 

    0xa9000000,// 37 MFM  11 

/// BDA is 124 words. 

/// BDA size     is 490 (0x1ea) 

/// BDA id       is 0xd61 

    0x01ea0d61,// 38 BDA   1 

/// PAY Generic Data size   : 490 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x18095884,// 39 PAY   1 

    0xfd235b3e,// 40 PAY   2 

    0x2c9cde9b,// 41 PAY   3 

    0x2a2e2eb3,// 42 PAY   4 

    0xc7294421,// 43 PAY   5 

    0x130f7947,// 44 PAY   6 

    0x8f6fc691,// 45 PAY   7 

    0x2c0ddd8e,// 46 PAY   8 

    0x017960a6,// 47 PAY   9 

    0x75b23f87,// 48 PAY  10 

    0x63efbead,// 49 PAY  11 

    0xa4111f6a,// 50 PAY  12 

    0x63048c58,// 51 PAY  13 

    0x246a8061,// 52 PAY  14 

    0x3329669e,// 53 PAY  15 

    0x833939a3,// 54 PAY  16 

    0x364738f1,// 55 PAY  17 

    0xd305bfb2,// 56 PAY  18 

    0x1be52755,// 57 PAY  19 

    0xeab155d2,// 58 PAY  20 

    0xd4090b26,// 59 PAY  21 

    0x92240d75,// 60 PAY  22 

    0x87aa63f8,// 61 PAY  23 

    0xe2bf9fb4,// 62 PAY  24 

    0x63c29f54,// 63 PAY  25 

    0x654c96f7,// 64 PAY  26 

    0x449ac839,// 65 PAY  27 

    0x634c2195,// 66 PAY  28 

    0x0f1bb796,// 67 PAY  29 

    0x12a48fac,// 68 PAY  30 

    0xd446f50d,// 69 PAY  31 

    0x145cc428,// 70 PAY  32 

    0xa65a66fb,// 71 PAY  33 

    0xe0842f32,// 72 PAY  34 

    0x94ab320f,// 73 PAY  35 

    0xeeaeac5c,// 74 PAY  36 

    0xc454949d,// 75 PAY  37 

    0x777e481e,// 76 PAY  38 

    0xcb85330a,// 77 PAY  39 

    0x203ff863,// 78 PAY  40 

    0xfb35447f,// 79 PAY  41 

    0x15f99fff,// 80 PAY  42 

    0x69006161,// 81 PAY  43 

    0xff70c516,// 82 PAY  44 

    0x7147cf41,// 83 PAY  45 

    0x4cda6868,// 84 PAY  46 

    0x0f52c255,// 85 PAY  47 

    0x77e40da4,// 86 PAY  48 

    0xf6d8df99,// 87 PAY  49 

    0xd05e4944,// 88 PAY  50 

    0x546931dd,// 89 PAY  51 

    0x7df70067,// 90 PAY  52 

    0xdb9a553c,// 91 PAY  53 

    0x6b342883,// 92 PAY  54 

    0x72bcdcdd,// 93 PAY  55 

    0xdebecf17,// 94 PAY  56 

    0x6625216e,// 95 PAY  57 

    0xf53daf8b,// 96 PAY  58 

    0xfc39668c,// 97 PAY  59 

    0x99e796b2,// 98 PAY  60 

    0xd5d83ed9,// 99 PAY  61 

    0x1fd2d42f,// 100 PAY  62 

    0x83799589,// 101 PAY  63 

    0xfbd64c09,// 102 PAY  64 

    0xbbbfa2eb,// 103 PAY  65 

    0xd3ab0817,// 104 PAY  66 

    0x0dc590fb,// 105 PAY  67 

    0x79d16e68,// 106 PAY  68 

    0x97e365d1,// 107 PAY  69 

    0xd71a67f7,// 108 PAY  70 

    0x05739977,// 109 PAY  71 

    0xcc301d89,// 110 PAY  72 

    0x9cd900ed,// 111 PAY  73 

    0x29288a5f,// 112 PAY  74 

    0x64bda180,// 113 PAY  75 

    0xe996ed50,// 114 PAY  76 

    0xdd9ed543,// 115 PAY  77 

    0xf08c778d,// 116 PAY  78 

    0xd8dd67ea,// 117 PAY  79 

    0x7ea887f6,// 118 PAY  80 

    0x191f55f9,// 119 PAY  81 

    0xa9518ef4,// 120 PAY  82 

    0xc3cb978c,// 121 PAY  83 

    0x95c47680,// 122 PAY  84 

    0xa309130e,// 123 PAY  85 

    0xc7972f83,// 124 PAY  86 

    0xd5abfad6,// 125 PAY  87 

    0x6b1c837f,// 126 PAY  88 

    0xe9e79b17,// 127 PAY  89 

    0xa9975c98,// 128 PAY  90 

    0x1422218f,// 129 PAY  91 

    0x2ac304e4,// 130 PAY  92 

    0x0beee17a,// 131 PAY  93 

    0x05e4ff9d,// 132 PAY  94 

    0x49c0d20c,// 133 PAY  95 

    0xa8e2cac3,// 134 PAY  96 

    0x5fa1cca8,// 135 PAY  97 

    0xa2cc7d67,// 136 PAY  98 

    0x69299eb8,// 137 PAY  99 

    0x0778a559,// 138 PAY 100 

    0x7ca6ef2b,// 139 PAY 101 

    0x5ac06dce,// 140 PAY 102 

    0xd989b21f,// 141 PAY 103 

    0x43d4bf59,// 142 PAY 104 

    0x93adb471,// 143 PAY 105 

    0x45d9092b,// 144 PAY 106 

    0x51c14524,// 145 PAY 107 

    0xa987f025,// 146 PAY 108 

    0xf09a295b,// 147 PAY 109 

    0xd5904c8c,// 148 PAY 110 

    0xcd8d6854,// 149 PAY 111 

    0xeed87893,// 150 PAY 112 

    0x570adf93,// 151 PAY 113 

    0x9174e1df,// 152 PAY 114 

    0xca5debca,// 153 PAY 115 

    0x31d63649,// 154 PAY 116 

    0x216b7ef0,// 155 PAY 117 

    0x263d24e4,// 156 PAY 118 

    0xec05dc83,// 157 PAY 119 

    0xde932c64,// 158 PAY 120 

    0x2bcdef9e,// 159 PAY 121 

    0xa399ca56,// 160 PAY 122 

    0x6d2d0000,// 161 PAY 123 

/// STA is 1 words. 

/// STA num_pkts       : 140 

/// STA pkt_idx        : 203 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xee 

    0x032dee8c // 162 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt8_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x8080283a,// 4 SCX   2 

    0x00002100,// 5 SCX   3 

    0xac66a979,// 6 SCX   4 

    0xed35f50f,// 7 SCX   5 

    0xb0ac20c5,// 8 SCX   6 

    0xa4583730,// 9 SCX   7 

    0x121499bf,// 10 SCX   8 

    0x3fc80561,// 11 SCX   9 

    0x500616f6,// 12 SCX  10 

    0x6a601b4a,// 13 SCX  11 

    0x387953d0,// 14 SCX  12 

    0x29783ddd,// 15 SCX  13 

    0x51414020,// 16 SCX  14 

    0xbab1b284,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 229 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 100 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 100 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 48 

/// BFD (ofst+len)cry  : 64 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 108 

    0x00000064,// 18 BFD   1 

    0x00300010,// 19 BFD   2 

    0x006c000c,// 20 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 9 

    0x09005bd9,// 21 MFM   1 

    0x8dff0000,// 22 MFM   2 

/// BDA is 59 words. 

/// BDA size     is 229 (0xe5) 

/// BDA id       is 0x5dfa 

    0x00e55dfa,// 23 BDA   1 

/// PAY Generic Data size   : 229 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x3e2ee230,// 24 PAY   1 

    0x13f7c291,// 25 PAY   2 

    0x2c645c17,// 26 PAY   3 

    0x16510abb,// 27 PAY   4 

    0xed7b740f,// 28 PAY   5 

    0xc007cd87,// 29 PAY   6 

    0x2d37ebb7,// 30 PAY   7 

    0x060b943e,// 31 PAY   8 

    0x17246f73,// 32 PAY   9 

    0xf611133f,// 33 PAY  10 

    0x2c0874a8,// 34 PAY  11 

    0xb6ccac69,// 35 PAY  12 

    0x717a0dce,// 36 PAY  13 

    0x5a910a12,// 37 PAY  14 

    0x7cb71b34,// 38 PAY  15 

    0x90af7c24,// 39 PAY  16 

    0x5c2421d8,// 40 PAY  17 

    0xe79391fa,// 41 PAY  18 

    0x3a5d3bd7,// 42 PAY  19 

    0xc3c5443a,// 43 PAY  20 

    0x491263c0,// 44 PAY  21 

    0xc5fbd274,// 45 PAY  22 

    0x9b55af85,// 46 PAY  23 

    0xb82d4ad4,// 47 PAY  24 

    0x33d1a0ad,// 48 PAY  25 

    0xae45ceb9,// 49 PAY  26 

    0xc9b821be,// 50 PAY  27 

    0x46194333,// 51 PAY  28 

    0x4681feec,// 52 PAY  29 

    0x6ee0f2b3,// 53 PAY  30 

    0xf9e3ebf1,// 54 PAY  31 

    0x10e6a604,// 55 PAY  32 

    0xa2a60d81,// 56 PAY  33 

    0xbb6ea3d2,// 57 PAY  34 

    0x24089873,// 58 PAY  35 

    0x51469cac,// 59 PAY  36 

    0x3a6b80a7,// 60 PAY  37 

    0x2f43b8d7,// 61 PAY  38 

    0xf1ed8e61,// 62 PAY  39 

    0x1b319d89,// 63 PAY  40 

    0x2b7fe13f,// 64 PAY  41 

    0x7273a9a4,// 65 PAY  42 

    0xa75d686f,// 66 PAY  43 

    0x0b9c9b42,// 67 PAY  44 

    0x7b8a43b7,// 68 PAY  45 

    0x61d7c6ad,// 69 PAY  46 

    0xe13024cd,// 70 PAY  47 

    0x7bfb789c,// 71 PAY  48 

    0xb3816e92,// 72 PAY  49 

    0x41d96de9,// 73 PAY  50 

    0x0ad5eda8,// 74 PAY  51 

    0x470b6722,// 75 PAY  52 

    0x3435e535,// 76 PAY  53 

    0x7e409c05,// 77 PAY  54 

    0xef5f9fb0,// 78 PAY  55 

    0x76551dfd,// 79 PAY  56 

    0xb57a5f05,// 80 PAY  57 

    0x88000000,// 81 PAY  58 

/// STA is 1 words. 

/// STA num_pkts       : 239 

/// STA pkt_idx        : 63 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x1c 

    0x00fc1cef // 82 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt9_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000011,// 3 SCX   1 

    0x808128c1,// 4 SCX   2 

    0x00005100,// 5 SCX   3 

    0x2d5cd40f,// 6 SCX   4 

    0x549f273c,// 7 SCX   5 

    0x2e706369,// 8 SCX   6 

    0xee7099cd,// 9 SCX   7 

    0xf4f62df7,// 10 SCX   8 

    0xa84dcf82,// 11 SCX   9 

    0xeaa37947,// 12 SCX  10 

    0xd0b131b4,// 13 SCX  11 

    0x4732f694,// 14 SCX  12 

    0xa8ed2776,// 15 SCX  13 

    0xffb041c2,// 16 SCX  14 

    0xadaf1720,// 17 SCX  15 

    0xf7eafa70,// 18 SCX  16 

    0xa176d648,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 997 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 557 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 557 

/// BFD lencrypto      : 96 

/// BFD ofstcrypto     : 460 

/// BFD (ofst+len)cry  : 556 

/// BFD ofstiv         : 388 

/// BFD ofsticv        : 980 

    0x0000022d,// 20 BFD   1 

    0x01cc0060,// 21 BFD   2 

    0x03d40184,// 22 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : a 

    0x0a00f638,// 23 MFM   1 

    0xa99c4b00,// 24 MFM   2 

/// BDA is 251 words. 

/// BDA size     is 997 (0x3e5) 

/// BDA id       is 0xc580 

    0x03e5c580,// 25 BDA   1 

/// PAY Generic Data size   : 997 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x5f37921d,// 26 PAY   1 

    0xa7dcc3f4,// 27 PAY   2 

    0xef661c74,// 28 PAY   3 

    0x718e525a,// 29 PAY   4 

    0xcbf42f6c,// 30 PAY   5 

    0x3fbe0265,// 31 PAY   6 

    0x1c2a6329,// 32 PAY   7 

    0x8b4e8044,// 33 PAY   8 

    0x642c96a0,// 34 PAY   9 

    0x87395eb5,// 35 PAY  10 

    0xf60fb5c3,// 36 PAY  11 

    0x76925841,// 37 PAY  12 

    0x2873ede5,// 38 PAY  13 

    0x1493eb0f,// 39 PAY  14 

    0xa58aed0c,// 40 PAY  15 

    0xe06bb36d,// 41 PAY  16 

    0xd59e695d,// 42 PAY  17 

    0x74d1f9b7,// 43 PAY  18 

    0xdc17b52a,// 44 PAY  19 

    0x3103242c,// 45 PAY  20 

    0x95da9776,// 46 PAY  21 

    0x33ad7110,// 47 PAY  22 

    0x88b62a17,// 48 PAY  23 

    0x01987dc8,// 49 PAY  24 

    0xd675e4c1,// 50 PAY  25 

    0x07d5e376,// 51 PAY  26 

    0xaaec28f5,// 52 PAY  27 

    0x3752f0b3,// 53 PAY  28 

    0x69bc8db6,// 54 PAY  29 

    0x7ebdd597,// 55 PAY  30 

    0x8c814f7e,// 56 PAY  31 

    0xf7d659b9,// 57 PAY  32 

    0xbeed46ed,// 58 PAY  33 

    0x0b704ec9,// 59 PAY  34 

    0xa5c8f69d,// 60 PAY  35 

    0x24c91bd8,// 61 PAY  36 

    0x08fb3091,// 62 PAY  37 

    0x91ed390c,// 63 PAY  38 

    0x59c732cc,// 64 PAY  39 

    0x27042b42,// 65 PAY  40 

    0x88e6166e,// 66 PAY  41 

    0x13d5af35,// 67 PAY  42 

    0xba4b4963,// 68 PAY  43 

    0x526a5518,// 69 PAY  44 

    0x8e9dab28,// 70 PAY  45 

    0x7082dde0,// 71 PAY  46 

    0x83c07b70,// 72 PAY  47 

    0xffee1d25,// 73 PAY  48 

    0x86d6d12f,// 74 PAY  49 

    0xd39fcb20,// 75 PAY  50 

    0x1b05a45a,// 76 PAY  51 

    0xe5855ba4,// 77 PAY  52 

    0x0c3fd84d,// 78 PAY  53 

    0xac5e9a9f,// 79 PAY  54 

    0x37cbe98f,// 80 PAY  55 

    0xa86edb60,// 81 PAY  56 

    0xc44509b4,// 82 PAY  57 

    0x4a92ae32,// 83 PAY  58 

    0xe1270a08,// 84 PAY  59 

    0xe80f58fd,// 85 PAY  60 

    0x30bf9db3,// 86 PAY  61 

    0xf1cef3d4,// 87 PAY  62 

    0x22f4d1ae,// 88 PAY  63 

    0xa78ed5e0,// 89 PAY  64 

    0xfcb0143e,// 90 PAY  65 

    0xfc9819d8,// 91 PAY  66 

    0x543b2d8d,// 92 PAY  67 

    0x18166120,// 93 PAY  68 

    0xd974cb27,// 94 PAY  69 

    0xb71c5a56,// 95 PAY  70 

    0x5cc1d42a,// 96 PAY  71 

    0xd53fba8d,// 97 PAY  72 

    0xadb7eae7,// 98 PAY  73 

    0x068d1d97,// 99 PAY  74 

    0x1f3a5114,// 100 PAY  75 

    0xe43006ba,// 101 PAY  76 

    0x7b3bec11,// 102 PAY  77 

    0xf639d4f8,// 103 PAY  78 

    0x30b1cdac,// 104 PAY  79 

    0xe3614b00,// 105 PAY  80 

    0xa6d06b99,// 106 PAY  81 

    0x40d01937,// 107 PAY  82 

    0x2964d657,// 108 PAY  83 

    0x77e5caed,// 109 PAY  84 

    0xe0717519,// 110 PAY  85 

    0x2392827c,// 111 PAY  86 

    0xd816075e,// 112 PAY  87 

    0x53d6f83d,// 113 PAY  88 

    0xfd2a8ae5,// 114 PAY  89 

    0x27ed129f,// 115 PAY  90 

    0x95339c85,// 116 PAY  91 

    0x2ea5a47e,// 117 PAY  92 

    0xf01a3c00,// 118 PAY  93 

    0x557f9118,// 119 PAY  94 

    0x4295a6d5,// 120 PAY  95 

    0x895e79fc,// 121 PAY  96 

    0xea90ce7b,// 122 PAY  97 

    0x171a393a,// 123 PAY  98 

    0xce4f1998,// 124 PAY  99 

    0xefe5203c,// 125 PAY 100 

    0x9d1e0e61,// 126 PAY 101 

    0x00b71487,// 127 PAY 102 

    0x55331314,// 128 PAY 103 

    0xe79af46a,// 129 PAY 104 

    0x1f3d9024,// 130 PAY 105 

    0x1a003c4c,// 131 PAY 106 

    0xcee3d0ba,// 132 PAY 107 

    0xd9e97424,// 133 PAY 108 

    0xad06e774,// 134 PAY 109 

    0xdc1cb956,// 135 PAY 110 

    0xf38c9868,// 136 PAY 111 

    0xb8d1bfcb,// 137 PAY 112 

    0x2d444f57,// 138 PAY 113 

    0x0b13d700,// 139 PAY 114 

    0x1db93204,// 140 PAY 115 

    0x0c066207,// 141 PAY 116 

    0x0b65e886,// 142 PAY 117 

    0x3973fdc2,// 143 PAY 118 

    0x28e1f542,// 144 PAY 119 

    0x7dc5359e,// 145 PAY 120 

    0x1374ad24,// 146 PAY 121 

    0x426f0995,// 147 PAY 122 

    0x2886e1ac,// 148 PAY 123 

    0x032ba02e,// 149 PAY 124 

    0xee7ab24a,// 150 PAY 125 

    0x5db48297,// 151 PAY 126 

    0x964fe445,// 152 PAY 127 

    0x8cc068a1,// 153 PAY 128 

    0x4a788030,// 154 PAY 129 

    0xbdda7e72,// 155 PAY 130 

    0x910d4bc5,// 156 PAY 131 

    0x9d416d0b,// 157 PAY 132 

    0xc3cb1d09,// 158 PAY 133 

    0x90713fcb,// 159 PAY 134 

    0xfb014fa5,// 160 PAY 135 

    0x7498690c,// 161 PAY 136 

    0x578234aa,// 162 PAY 137 

    0xb99c6b4c,// 163 PAY 138 

    0x27d23037,// 164 PAY 139 

    0x948bc3c8,// 165 PAY 140 

    0xebd92812,// 166 PAY 141 

    0x26fe8434,// 167 PAY 142 

    0x955c8cc6,// 168 PAY 143 

    0x8d59d506,// 169 PAY 144 

    0x1d85baef,// 170 PAY 145 

    0x0d44d39a,// 171 PAY 146 

    0xf038a808,// 172 PAY 147 

    0x5a45ea17,// 173 PAY 148 

    0x1dc8c391,// 174 PAY 149 

    0x6999e266,// 175 PAY 150 

    0x4cd32da7,// 176 PAY 151 

    0x289383c2,// 177 PAY 152 

    0x7250ca89,// 178 PAY 153 

    0x706aea8f,// 179 PAY 154 

    0x1bac50e1,// 180 PAY 155 

    0x56304ff0,// 181 PAY 156 

    0x6956f12e,// 182 PAY 157 

    0x15d70d1d,// 183 PAY 158 

    0xbb8aea55,// 184 PAY 159 

    0x66037fae,// 185 PAY 160 

    0xabc38722,// 186 PAY 161 

    0x414bd574,// 187 PAY 162 

    0xd59170c0,// 188 PAY 163 

    0x7f333b9d,// 189 PAY 164 

    0xa70497b5,// 190 PAY 165 

    0x248bca3d,// 191 PAY 166 

    0xf17f2aa0,// 192 PAY 167 

    0x56291fb6,// 193 PAY 168 

    0xcea91870,// 194 PAY 169 

    0x93d4956d,// 195 PAY 170 

    0x4d8409e3,// 196 PAY 171 

    0x67ca620d,// 197 PAY 172 

    0x654b1bde,// 198 PAY 173 

    0xc4cef84d,// 199 PAY 174 

    0x13b2d1b7,// 200 PAY 175 

    0x03fd1f04,// 201 PAY 176 

    0x9cf71d85,// 202 PAY 177 

    0x3102b2ba,// 203 PAY 178 

    0xa2eab23a,// 204 PAY 179 

    0x5cc5071f,// 205 PAY 180 

    0xae13f401,// 206 PAY 181 

    0x672a6420,// 207 PAY 182 

    0x2ca93146,// 208 PAY 183 

    0xeb59fcf5,// 209 PAY 184 

    0x99c14911,// 210 PAY 185 

    0x2a472931,// 211 PAY 186 

    0x07cce5a5,// 212 PAY 187 

    0xc80f05e3,// 213 PAY 188 

    0x85c4a973,// 214 PAY 189 

    0xa23cdc22,// 215 PAY 190 

    0xc140fbc2,// 216 PAY 191 

    0xbf62f425,// 217 PAY 192 

    0x5bd96823,// 218 PAY 193 

    0xf2e5ab45,// 219 PAY 194 

    0xf09c2ac7,// 220 PAY 195 

    0x083fd084,// 221 PAY 196 

    0x27774f88,// 222 PAY 197 

    0xa491c271,// 223 PAY 198 

    0xe7711103,// 224 PAY 199 

    0x7456aaa9,// 225 PAY 200 

    0xac4d04ed,// 226 PAY 201 

    0x4198a83f,// 227 PAY 202 

    0x204f2cc5,// 228 PAY 203 

    0x0ff26bef,// 229 PAY 204 

    0xd75e4eee,// 230 PAY 205 

    0x18e63571,// 231 PAY 206 

    0xb5eba53e,// 232 PAY 207 

    0x318567de,// 233 PAY 208 

    0x45d5eb28,// 234 PAY 209 

    0x2117e443,// 235 PAY 210 

    0xeb3474db,// 236 PAY 211 

    0xb2cdb58b,// 237 PAY 212 

    0x8f96612f,// 238 PAY 213 

    0x20fbe3aa,// 239 PAY 214 

    0xbb332ac9,// 240 PAY 215 

    0x0aa49b37,// 241 PAY 216 

    0xf9dafab1,// 242 PAY 217 

    0xe55db4cc,// 243 PAY 218 

    0x9e600a70,// 244 PAY 219 

    0xdd2a6bd1,// 245 PAY 220 

    0xd2d7f14e,// 246 PAY 221 

    0xc67c34f5,// 247 PAY 222 

    0xaa166dbc,// 248 PAY 223 

    0x640524dd,// 249 PAY 224 

    0xa47b144c,// 250 PAY 225 

    0xab4b809b,// 251 PAY 226 

    0xa2da8e78,// 252 PAY 227 

    0xf560e23e,// 253 PAY 228 

    0xd0afa329,// 254 PAY 229 

    0x71ea0bcb,// 255 PAY 230 

    0x6fa17160,// 256 PAY 231 

    0x39f7fe3f,// 257 PAY 232 

    0xec32211a,// 258 PAY 233 

    0xc922d321,// 259 PAY 234 

    0x353bba67,// 260 PAY 235 

    0x8a26c74a,// 261 PAY 236 

    0x340afb63,// 262 PAY 237 

    0x1b670d8e,// 263 PAY 238 

    0x796b0f3f,// 264 PAY 239 

    0x1c358c30,// 265 PAY 240 

    0xba187d41,// 266 PAY 241 

    0x02163283,// 267 PAY 242 

    0xd0873f0b,// 268 PAY 243 

    0xd3325c42,// 269 PAY 244 

    0x87e3d1f4,// 270 PAY 245 

    0x46db7403,// 271 PAY 246 

    0x92f13eda,// 272 PAY 247 

    0xbc2ed5f1,// 273 PAY 248 

    0x4f81a5e3,// 274 PAY 249 

    0x09000000,// 275 PAY 250 

/// STA is 1 words. 

/// STA num_pkts       : 73 

/// STA pkt_idx        : 76 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x71 

    0x01317149 // 276 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt10_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0b 

/// ECH pdu_tag        : 0x00 

    0x000b0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x808428f6,// 4 SCX   2 

    0x000071c4,// 5 SCX   3 

    0x16811a67,// 6 SCX   4 

    0x7b44f299,// 7 SCX   5 

    0x557af4d8,// 8 SCX   6 

    0xb2b9a8d0,// 9 SCX   7 

    0xd58d4a01,// 10 SCX   8 

    0x745b345c,// 11 SCX   9 

    0x8fec857e,// 12 SCX  10 

    0x1f7a318e,// 13 SCX  11 

    0x195a5957,// 14 SCX  12 

    0xf67a65b7,// 15 SCX  13 

    0x25db0802,// 16 SCX  14 

    0xa5ec2f6f,// 17 SCX  15 

    0xf8fa9103,// 18 SCX  16 

    0xc6f5faee,// 19 SCX  17 

    0x0c3c99d6,// 20 SCX  18 

    0xb67d1b9d,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1199 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1077 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1077 

/// BFD lencrypto      : 512 

/// BFD ofstcrypto     : 236 

/// BFD (ofst+len)cry  : 748 

/// BFD ofstiv         : 24 

/// BFD ofsticv        : 1096 

    0x00000435,// 22 BFD   1 

    0x00ec0200,// 23 BFD   2 

    0x04480018,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00960a,// 25 MFM   1 

    0xbcefab1f,// 26 MFM   2 

    0xd861f1df,// 27 MFM   3 

    0x133857c0,// 28 MFM   4 

    0x98ef50a4,// 29 MFM   5 

    0x45958f50,// 30 MFM   6 

    0xfbdebd3f,// 31 MFM   7 

    0xb6afe31e,// 32 MFM   8 

    0x6de65822,// 33 MFM   9 

    0x314cc1ef,// 34 MFM  10 

    0xb2607402,// 35 MFM  11 

    0x5eaa80cf,// 36 MFM  12 

    0x1f31f26e,// 37 MFM  13 

    0x93256590,// 38 MFM  14 

    0xf0e91013,// 39 MFM  15 

    0x0ade8dca,// 40 MFM  16 

/// BDA is 301 words. 

/// BDA size     is 1199 (0x4af) 

/// BDA id       is 0xdf39 

    0x04afdf39,// 41 BDA   1 

/// PAY Generic Data size   : 1199 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x80c98037,// 42 PAY   1 

    0x3502ffec,// 43 PAY   2 

    0x61068449,// 44 PAY   3 

    0xf286b041,// 45 PAY   4 

    0xac21181d,// 46 PAY   5 

    0xc405afc2,// 47 PAY   6 

    0x050e719a,// 48 PAY   7 

    0x6f19c8c5,// 49 PAY   8 

    0x00a05f83,// 50 PAY   9 

    0x2704ba1d,// 51 PAY  10 

    0x399ed128,// 52 PAY  11 

    0x5f74a05d,// 53 PAY  12 

    0x227fb08d,// 54 PAY  13 

    0x84a3feef,// 55 PAY  14 

    0x377df743,// 56 PAY  15 

    0x651da685,// 57 PAY  16 

    0x32249b21,// 58 PAY  17 

    0x50c59867,// 59 PAY  18 

    0x2e55c3bc,// 60 PAY  19 

    0x58a21851,// 61 PAY  20 

    0x1dfe2c31,// 62 PAY  21 

    0x26ab6eb4,// 63 PAY  22 

    0xb08f8209,// 64 PAY  23 

    0xc915e0e0,// 65 PAY  24 

    0xa0072546,// 66 PAY  25 

    0xe69acccf,// 67 PAY  26 

    0xe7592f96,// 68 PAY  27 

    0xe53bca2a,// 69 PAY  28 

    0x7307368c,// 70 PAY  29 

    0xccb8bee6,// 71 PAY  30 

    0x9860d730,// 72 PAY  31 

    0xf563ffde,// 73 PAY  32 

    0x4831ee20,// 74 PAY  33 

    0xaefa450a,// 75 PAY  34 

    0x7e2c4ae5,// 76 PAY  35 

    0x357b2f17,// 77 PAY  36 

    0x0e476945,// 78 PAY  37 

    0xa266861e,// 79 PAY  38 

    0x731e4cb1,// 80 PAY  39 

    0xcff114c8,// 81 PAY  40 

    0x4cd95c9c,// 82 PAY  41 

    0x129d1446,// 83 PAY  42 

    0xb1370e3c,// 84 PAY  43 

    0x323704f5,// 85 PAY  44 

    0xf8de3d31,// 86 PAY  45 

    0xeae9b371,// 87 PAY  46 

    0x3c086e73,// 88 PAY  47 

    0x89781bbe,// 89 PAY  48 

    0xcb19a761,// 90 PAY  49 

    0x9a116659,// 91 PAY  50 

    0xd4b08352,// 92 PAY  51 

    0xa59c21a1,// 93 PAY  52 

    0xe8e64ea3,// 94 PAY  53 

    0xde5cf81f,// 95 PAY  54 

    0x08e3ecd9,// 96 PAY  55 

    0x9a2b892b,// 97 PAY  56 

    0xf19a21a7,// 98 PAY  57 

    0xb8595511,// 99 PAY  58 

    0x5a5dc19d,// 100 PAY  59 

    0x77126b19,// 101 PAY  60 

    0xeef32feb,// 102 PAY  61 

    0x3a0770c0,// 103 PAY  62 

    0x78562a13,// 104 PAY  63 

    0x575e7a66,// 105 PAY  64 

    0x5415b4f4,// 106 PAY  65 

    0xda01089f,// 107 PAY  66 

    0xd8b9bffd,// 108 PAY  67 

    0x608331bc,// 109 PAY  68 

    0xc8e89fc9,// 110 PAY  69 

    0x1cdaa371,// 111 PAY  70 

    0x9d2304c1,// 112 PAY  71 

    0xbc6d000c,// 113 PAY  72 

    0x6593f82d,// 114 PAY  73 

    0x487e0f1b,// 115 PAY  74 

    0x33154307,// 116 PAY  75 

    0x72fa24ad,// 117 PAY  76 

    0x804e21ee,// 118 PAY  77 

    0xecf9b0b4,// 119 PAY  78 

    0xee5bc011,// 120 PAY  79 

    0x35dda8e1,// 121 PAY  80 

    0x57c93ca6,// 122 PAY  81 

    0x9cb597a8,// 123 PAY  82 

    0x11b6dd62,// 124 PAY  83 

    0x5a9e8905,// 125 PAY  84 

    0xd2e4500b,// 126 PAY  85 

    0x71427b2f,// 127 PAY  86 

    0xb1268535,// 128 PAY  87 

    0x521a914e,// 129 PAY  88 

    0x47bc6d94,// 130 PAY  89 

    0x4626eaef,// 131 PAY  90 

    0x20089b5a,// 132 PAY  91 

    0xacab9605,// 133 PAY  92 

    0x0c176eeb,// 134 PAY  93 

    0xba06b277,// 135 PAY  94 

    0xca82b088,// 136 PAY  95 

    0x896e158c,// 137 PAY  96 

    0x8fdbc8f6,// 138 PAY  97 

    0x1165f3c0,// 139 PAY  98 

    0x1e44b796,// 140 PAY  99 

    0xb98577f6,// 141 PAY 100 

    0x82165757,// 142 PAY 101 

    0xc3131caa,// 143 PAY 102 

    0xceeb0952,// 144 PAY 103 

    0x23ecff2e,// 145 PAY 104 

    0x58090595,// 146 PAY 105 

    0x401bb488,// 147 PAY 106 

    0x4989e96f,// 148 PAY 107 

    0x7504105b,// 149 PAY 108 

    0xe3a7fdf0,// 150 PAY 109 

    0x1bddc016,// 151 PAY 110 

    0x4e216f66,// 152 PAY 111 

    0xb74c79be,// 153 PAY 112 

    0xa73d0773,// 154 PAY 113 

    0xabbff555,// 155 PAY 114 

    0x65856c7f,// 156 PAY 115 

    0x2cbead87,// 157 PAY 116 

    0x0e48c667,// 158 PAY 117 

    0xa98f0cd9,// 159 PAY 118 

    0xdd2c1414,// 160 PAY 119 

    0x0aacfc35,// 161 PAY 120 

    0x26985f22,// 162 PAY 121 

    0x4fd5e27a,// 163 PAY 122 

    0x2b0d69b9,// 164 PAY 123 

    0xd2efc702,// 165 PAY 124 

    0xa60c7f21,// 166 PAY 125 

    0x4e979bed,// 167 PAY 126 

    0xbb207fe4,// 168 PAY 127 

    0xec26f60f,// 169 PAY 128 

    0x09824878,// 170 PAY 129 

    0x73428fb4,// 171 PAY 130 

    0x3e31a880,// 172 PAY 131 

    0x87d66a22,// 173 PAY 132 

    0x95ac3dbd,// 174 PAY 133 

    0xa2e26413,// 175 PAY 134 

    0x4517358f,// 176 PAY 135 

    0xbd6d787f,// 177 PAY 136 

    0xd7c219e9,// 178 PAY 137 

    0x5eb63092,// 179 PAY 138 

    0xd58dcecf,// 180 PAY 139 

    0x59cd70dc,// 181 PAY 140 

    0x7132313f,// 182 PAY 141 

    0x0bdbeb87,// 183 PAY 142 

    0x73b401a4,// 184 PAY 143 

    0x3811a040,// 185 PAY 144 

    0x36a6bec0,// 186 PAY 145 

    0x27f10a31,// 187 PAY 146 

    0x4408b0b2,// 188 PAY 147 

    0x6ff2d755,// 189 PAY 148 

    0x1b3fee5a,// 190 PAY 149 

    0xcab6e804,// 191 PAY 150 

    0xb2cae300,// 192 PAY 151 

    0x75eb3a7e,// 193 PAY 152 

    0x7d346d19,// 194 PAY 153 

    0x7fc8970d,// 195 PAY 154 

    0xeb71730b,// 196 PAY 155 

    0x0fe5e5e3,// 197 PAY 156 

    0x76138ca5,// 198 PAY 157 

    0xb9390f95,// 199 PAY 158 

    0xcf9a678d,// 200 PAY 159 

    0xc7801367,// 201 PAY 160 

    0x1416beb3,// 202 PAY 161 

    0x12dbe285,// 203 PAY 162 

    0xf6d22914,// 204 PAY 163 

    0xee9a5eb8,// 205 PAY 164 

    0x86be8ecd,// 206 PAY 165 

    0x806cf01d,// 207 PAY 166 

    0x85b9fe08,// 208 PAY 167 

    0xee9583b3,// 209 PAY 168 

    0xd4370941,// 210 PAY 169 

    0xebe75b02,// 211 PAY 170 

    0xdc4e004e,// 212 PAY 171 

    0x106c4f18,// 213 PAY 172 

    0x58c4df01,// 214 PAY 173 

    0x74b3ecc1,// 215 PAY 174 

    0x0d8182a0,// 216 PAY 175 

    0x6b1f09a4,// 217 PAY 176 

    0x5d1ca9d6,// 218 PAY 177 

    0x68406d13,// 219 PAY 178 

    0xacdd014c,// 220 PAY 179 

    0x5e118e6b,// 221 PAY 180 

    0xfba260ab,// 222 PAY 181 

    0x934c3971,// 223 PAY 182 

    0xb38ae27e,// 224 PAY 183 

    0x35b71893,// 225 PAY 184 

    0x2d677fdf,// 226 PAY 185 

    0x5b685184,// 227 PAY 186 

    0x10d9e005,// 228 PAY 187 

    0xfc5757aa,// 229 PAY 188 

    0x0b8bdf6e,// 230 PAY 189 

    0x15d8d2f9,// 231 PAY 190 

    0xe15a1479,// 232 PAY 191 

    0xe7aa90ae,// 233 PAY 192 

    0x08ee9461,// 234 PAY 193 

    0x98873b21,// 235 PAY 194 

    0x48a03d94,// 236 PAY 195 

    0x598310a9,// 237 PAY 196 

    0x4ef7b002,// 238 PAY 197 

    0x3d88ff20,// 239 PAY 198 

    0x342ff87f,// 240 PAY 199 

    0x4a1a247d,// 241 PAY 200 

    0xf0b09c86,// 242 PAY 201 

    0x92ce69bf,// 243 PAY 202 

    0x0a40a108,// 244 PAY 203 

    0x3d0b2343,// 245 PAY 204 

    0xd59d0621,// 246 PAY 205 

    0xfb4f6faf,// 247 PAY 206 

    0x4e10f570,// 248 PAY 207 

    0x91110629,// 249 PAY 208 

    0xf2543b8c,// 250 PAY 209 

    0x7f8b8209,// 251 PAY 210 

    0x62b799ec,// 252 PAY 211 

    0xd7e45172,// 253 PAY 212 

    0xd00619ac,// 254 PAY 213 

    0xfad4c023,// 255 PAY 214 

    0xa5c30c0a,// 256 PAY 215 

    0x4f40b384,// 257 PAY 216 

    0x106c3a5e,// 258 PAY 217 

    0xc74e8459,// 259 PAY 218 

    0x8d52d170,// 260 PAY 219 

    0x85b96ad9,// 261 PAY 220 

    0xd9c3602f,// 262 PAY 221 

    0x30bb0afd,// 263 PAY 222 

    0xa75a10ca,// 264 PAY 223 

    0x7048882e,// 265 PAY 224 

    0xa1e3af75,// 266 PAY 225 

    0xf43d5ec1,// 267 PAY 226 

    0x855e81f9,// 268 PAY 227 

    0x4cdf224b,// 269 PAY 228 

    0x9c517b3f,// 270 PAY 229 

    0xd896a0f8,// 271 PAY 230 

    0x59ea09a5,// 272 PAY 231 

    0xf6f0d70a,// 273 PAY 232 

    0x86c09788,// 274 PAY 233 

    0x1d362962,// 275 PAY 234 

    0xbfe18611,// 276 PAY 235 

    0xf5d9e029,// 277 PAY 236 

    0x6378459f,// 278 PAY 237 

    0x5c9a913f,// 279 PAY 238 

    0x61736d81,// 280 PAY 239 

    0x2b580906,// 281 PAY 240 

    0x2425eed7,// 282 PAY 241 

    0x89872ab6,// 283 PAY 242 

    0x58137ffd,// 284 PAY 243 

    0xb1d003a7,// 285 PAY 244 

    0xb380a91c,// 286 PAY 245 

    0xb20220bf,// 287 PAY 246 

    0x39b03a64,// 288 PAY 247 

    0xaa589a88,// 289 PAY 248 

    0xc6a7e2f4,// 290 PAY 249 

    0x4729679d,// 291 PAY 250 

    0xb8bf4328,// 292 PAY 251 

    0x6cc97e95,// 293 PAY 252 

    0x9271119c,// 294 PAY 253 

    0x95eaa203,// 295 PAY 254 

    0x5c2e29a6,// 296 PAY 255 

    0x0a51c195,// 297 PAY 256 

    0x74eb3c4e,// 298 PAY 257 

    0x208adde1,// 299 PAY 258 

    0xba63b0db,// 300 PAY 259 

    0x2859b924,// 301 PAY 260 

    0xba329231,// 302 PAY 261 

    0x35d348de,// 303 PAY 262 

    0x564db057,// 304 PAY 263 

    0xa2590888,// 305 PAY 264 

    0xc9e4d201,// 306 PAY 265 

    0xa88a219c,// 307 PAY 266 

    0xb5094516,// 308 PAY 267 

    0x573211fa,// 309 PAY 268 

    0xc70d6640,// 310 PAY 269 

    0xc108424c,// 311 PAY 270 

    0x66676195,// 312 PAY 271 

    0xb2037bbb,// 313 PAY 272 

    0xc86f96db,// 314 PAY 273 

    0xbfca5b71,// 315 PAY 274 

    0x56ccc9f3,// 316 PAY 275 

    0xfd588c8a,// 317 PAY 276 

    0x9cb76b6b,// 318 PAY 277 

    0xe30c32d7,// 319 PAY 278 

    0x2bb40f05,// 320 PAY 279 

    0x7e75e330,// 321 PAY 280 

    0x0a721893,// 322 PAY 281 

    0x51ba6eaa,// 323 PAY 282 

    0x3cd1af8d,// 324 PAY 283 

    0xfa2fa0d0,// 325 PAY 284 

    0x4a9abc7e,// 326 PAY 285 

    0x37dce466,// 327 PAY 286 

    0x9d596c67,// 328 PAY 287 

    0xb314d903,// 329 PAY 288 

    0x6999765f,// 330 PAY 289 

    0xb775fe36,// 331 PAY 290 

    0xcd536020,// 332 PAY 291 

    0x67ff5b9c,// 333 PAY 292 

    0xa6bbda34,// 334 PAY 293 

    0xc1e14885,// 335 PAY 294 

    0x19f29324,// 336 PAY 295 

    0xce9d55d7,// 337 PAY 296 

    0x04631560,// 338 PAY 297 

    0xac8c6a24,// 339 PAY 298 

    0x6241bc2a,// 340 PAY 299 

    0x0be06100,// 341 PAY 300 

/// STA is 1 words. 

/// STA num_pkts       : 44 

/// STA pkt_idx        : 214 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xe8 

    0x0359e82c // 342 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt11_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x01 

/// ECH pdu_tag        : 0x00 

    0x00010000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8082283e,// 4 SCX   2 

    0x00007100,// 5 SCX   3 

    0xa853915b,// 6 SCX   4 

    0x9dfa6d09,// 7 SCX   5 

    0x90b32ee7,// 8 SCX   6 

    0xeb86faca,// 9 SCX   7 

    0x930daf0f,// 10 SCX   8 

    0x12b5f68d,// 11 SCX   9 

    0x753cd196,// 12 SCX  10 

    0xea7b56d4,// 13 SCX  11 

    0x99a3fee8,// 14 SCX  12 

    0x9d153eec,// 15 SCX  13 

    0x2f492576,// 16 SCX  14 

    0x43de03f6,// 17 SCX  15 

    0xdc0409dd,// 18 SCX  16 

    0xd7e84ab5,// 19 SCX  17 

    0xbec2581a,// 20 SCX  18 

    0xa9b299e4,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1719 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 72 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 72 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 20 

/// BFD (ofst+len)cry  : 52 

/// BFD ofstiv         : 4 

/// BFD ofsticv        : 1144 

    0x00000048,// 22 BFD   1 

    0x00140020,// 23 BFD   2 

    0x04780004,// 24 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 4 

    0x04008e48,// 25 MFM   1 

/// BDA is 431 words. 

/// BDA size     is 1719 (0x6b7) 

/// BDA id       is 0x906 

    0x06b70906,// 26 BDA   1 

/// PAY Generic Data size   : 1719 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x16c4ca72,// 27 PAY   1 

    0x1d5638cc,// 28 PAY   2 

    0x4ec9462d,// 29 PAY   3 

    0xbc41e252,// 30 PAY   4 

    0x3f45b515,// 31 PAY   5 

    0x07e349eb,// 32 PAY   6 

    0x6c58d6fa,// 33 PAY   7 

    0x020f392e,// 34 PAY   8 

    0xd3402d5c,// 35 PAY   9 

    0x4e207148,// 36 PAY  10 

    0xc16080ea,// 37 PAY  11 

    0xf5e07952,// 38 PAY  12 

    0x3d0b289f,// 39 PAY  13 

    0x9adc7377,// 40 PAY  14 

    0x0c767033,// 41 PAY  15 

    0x57f22069,// 42 PAY  16 

    0x10deb861,// 43 PAY  17 

    0x51f8fa8c,// 44 PAY  18 

    0x377da9e0,// 45 PAY  19 

    0x8b15948f,// 46 PAY  20 

    0xc4a75584,// 47 PAY  21 

    0xce301c55,// 48 PAY  22 

    0x9e4e4343,// 49 PAY  23 

    0x05e1efdc,// 50 PAY  24 

    0x0bb3afde,// 51 PAY  25 

    0xd7cb01f1,// 52 PAY  26 

    0x116e963c,// 53 PAY  27 

    0xda0ef758,// 54 PAY  28 

    0xe163e7e7,// 55 PAY  29 

    0x8135dd80,// 56 PAY  30 

    0xab219028,// 57 PAY  31 

    0xb46226d6,// 58 PAY  32 

    0x061dce89,// 59 PAY  33 

    0xa675ebb7,// 60 PAY  34 

    0x2fd4e882,// 61 PAY  35 

    0xeaecf66d,// 62 PAY  36 

    0x936dc6dc,// 63 PAY  37 

    0x7c83b482,// 64 PAY  38 

    0x92dca69f,// 65 PAY  39 

    0x9d19902d,// 66 PAY  40 

    0xf3740af5,// 67 PAY  41 

    0x3e2d3c4b,// 68 PAY  42 

    0xd0c0edd7,// 69 PAY  43 

    0x07a290d5,// 70 PAY  44 

    0xbebaae21,// 71 PAY  45 

    0xb40250c8,// 72 PAY  46 

    0xf1c63574,// 73 PAY  47 

    0x40faf6e7,// 74 PAY  48 

    0xe66d6e98,// 75 PAY  49 

    0x51818ab5,// 76 PAY  50 

    0xe98ee1ea,// 77 PAY  51 

    0x2e2505be,// 78 PAY  52 

    0x7cf242b3,// 79 PAY  53 

    0x06503ae0,// 80 PAY  54 

    0x64cfd232,// 81 PAY  55 

    0x48517bbb,// 82 PAY  56 

    0x71f92ea2,// 83 PAY  57 

    0x1afa333b,// 84 PAY  58 

    0xae1b048f,// 85 PAY  59 

    0xbb2e05c4,// 86 PAY  60 

    0x2db80574,// 87 PAY  61 

    0xfae3f99a,// 88 PAY  62 

    0x892364df,// 89 PAY  63 

    0x8473bf09,// 90 PAY  64 

    0x069a54aa,// 91 PAY  65 

    0x474f20ef,// 92 PAY  66 

    0x967f29c2,// 93 PAY  67 

    0xe38ab447,// 94 PAY  68 

    0x29216060,// 95 PAY  69 

    0x6780b14c,// 96 PAY  70 

    0x2d2d366d,// 97 PAY  71 

    0xb53570f9,// 98 PAY  72 

    0x900f37aa,// 99 PAY  73 

    0x43da70aa,// 100 PAY  74 

    0x2df95bdc,// 101 PAY  75 

    0xa2261e88,// 102 PAY  76 

    0x54bfa20c,// 103 PAY  77 

    0x15285bbd,// 104 PAY  78 

    0xd7e9767f,// 105 PAY  79 

    0x7e2d4031,// 106 PAY  80 

    0x61ce1d65,// 107 PAY  81 

    0x2c2773a9,// 108 PAY  82 

    0x7385065e,// 109 PAY  83 

    0xfc323a68,// 110 PAY  84 

    0xa19b5ef1,// 111 PAY  85 

    0x96c9dea1,// 112 PAY  86 

    0xa4791d8c,// 113 PAY  87 

    0xadd1535b,// 114 PAY  88 

    0xef0cf2f8,// 115 PAY  89 

    0x1722b98e,// 116 PAY  90 

    0xafbb5e33,// 117 PAY  91 

    0x84a9b599,// 118 PAY  92 

    0x9e613fc6,// 119 PAY  93 

    0xc9106f1a,// 120 PAY  94 

    0x4b2a21de,// 121 PAY  95 

    0xe880e04f,// 122 PAY  96 

    0x3182082b,// 123 PAY  97 

    0xb1d56124,// 124 PAY  98 

    0xfbd1d3dd,// 125 PAY  99 

    0x71eff672,// 126 PAY 100 

    0x830bca62,// 127 PAY 101 

    0x6fc626c3,// 128 PAY 102 

    0xffb8a0e8,// 129 PAY 103 

    0x18712a15,// 130 PAY 104 

    0x493ef91c,// 131 PAY 105 

    0x89df42ed,// 132 PAY 106 

    0x27b14441,// 133 PAY 107 

    0x021b028b,// 134 PAY 108 

    0x679b15fe,// 135 PAY 109 

    0x7e609a5a,// 136 PAY 110 

    0x4f1a680f,// 137 PAY 111 

    0x15e8faa2,// 138 PAY 112 

    0xb0d97702,// 139 PAY 113 

    0xe1dc9d08,// 140 PAY 114 

    0x3c9ed106,// 141 PAY 115 

    0x29960426,// 142 PAY 116 

    0x01733e5e,// 143 PAY 117 

    0x23e5249b,// 144 PAY 118 

    0x391eade7,// 145 PAY 119 

    0xa289ec20,// 146 PAY 120 

    0x3d52e060,// 147 PAY 121 

    0xe60e6545,// 148 PAY 122 

    0x834db967,// 149 PAY 123 

    0xdc811068,// 150 PAY 124 

    0x75a14112,// 151 PAY 125 

    0x11303d84,// 152 PAY 126 

    0x87610325,// 153 PAY 127 

    0x030a8d32,// 154 PAY 128 

    0x8852c39f,// 155 PAY 129 

    0x8698e6ba,// 156 PAY 130 

    0x262b4f8a,// 157 PAY 131 

    0xcd9c22e5,// 158 PAY 132 

    0x25e0be13,// 159 PAY 133 

    0x9c13ded9,// 160 PAY 134 

    0xa2bc8f30,// 161 PAY 135 

    0xd70d8625,// 162 PAY 136 

    0x1fa3e70b,// 163 PAY 137 

    0x1a67f926,// 164 PAY 138 

    0x310c979c,// 165 PAY 139 

    0x09f9b299,// 166 PAY 140 

    0xe4ce7f6d,// 167 PAY 141 

    0xd4e57816,// 168 PAY 142 

    0xa78c34e4,// 169 PAY 143 

    0x48d91e78,// 170 PAY 144 

    0xec0992cd,// 171 PAY 145 

    0xc170cb31,// 172 PAY 146 

    0xd710abca,// 173 PAY 147 

    0xae9450e5,// 174 PAY 148 

    0x79c995ac,// 175 PAY 149 

    0x45edf4cf,// 176 PAY 150 

    0xc8298f0d,// 177 PAY 151 

    0xd078f952,// 178 PAY 152 

    0xf66b2f97,// 179 PAY 153 

    0x971657ed,// 180 PAY 154 

    0xe1bee98d,// 181 PAY 155 

    0xddeb3839,// 182 PAY 156 

    0xe909424d,// 183 PAY 157 

    0xa6937576,// 184 PAY 158 

    0x1a742ce2,// 185 PAY 159 

    0x1b63584d,// 186 PAY 160 

    0x07d6ecc3,// 187 PAY 161 

    0x1ad0e828,// 188 PAY 162 

    0xc046a839,// 189 PAY 163 

    0xad5c63ad,// 190 PAY 164 

    0x6e0498f4,// 191 PAY 165 

    0xdc68db06,// 192 PAY 166 

    0x4e6f81f7,// 193 PAY 167 

    0x2289d39a,// 194 PAY 168 

    0x62e59c03,// 195 PAY 169 

    0x21efdf46,// 196 PAY 170 

    0x666daa99,// 197 PAY 171 

    0x36c74db0,// 198 PAY 172 

    0xd8be80a8,// 199 PAY 173 

    0xcb4c1c9e,// 200 PAY 174 

    0xb5d141eb,// 201 PAY 175 

    0x56dea846,// 202 PAY 176 

    0x1152c64e,// 203 PAY 177 

    0xf84ce48c,// 204 PAY 178 

    0x5a7abf22,// 205 PAY 179 

    0xbd883130,// 206 PAY 180 

    0x8a6d4cac,// 207 PAY 181 

    0x5c75bce0,// 208 PAY 182 

    0xb39da914,// 209 PAY 183 

    0x53f9502a,// 210 PAY 184 

    0x72fc0cec,// 211 PAY 185 

    0xf0b7f4e0,// 212 PAY 186 

    0x57bda404,// 213 PAY 187 

    0x49caf248,// 214 PAY 188 

    0x080c76f6,// 215 PAY 189 

    0xd704771d,// 216 PAY 190 

    0x18e97603,// 217 PAY 191 

    0xbdbc14e9,// 218 PAY 192 

    0x2e1d33bd,// 219 PAY 193 

    0xd99d5f3a,// 220 PAY 194 

    0x84466ec7,// 221 PAY 195 

    0x739a4cf1,// 222 PAY 196 

    0x9acc5fad,// 223 PAY 197 

    0x76071ddf,// 224 PAY 198 

    0x0ed2c5a7,// 225 PAY 199 

    0xb582882f,// 226 PAY 200 

    0xc93d8bfd,// 227 PAY 201 

    0x35e4048b,// 228 PAY 202 

    0x99f156fe,// 229 PAY 203 

    0x59ed701f,// 230 PAY 204 

    0xacd5d308,// 231 PAY 205 

    0xc352d5d0,// 232 PAY 206 

    0xec7b28cb,// 233 PAY 207 

    0xeb699384,// 234 PAY 208 

    0x87f08884,// 235 PAY 209 

    0xb1453dc1,// 236 PAY 210 

    0x25b49613,// 237 PAY 211 

    0x381b74b6,// 238 PAY 212 

    0xd836b821,// 239 PAY 213 

    0x0636ebe5,// 240 PAY 214 

    0x18fd95b7,// 241 PAY 215 

    0xc3688ac4,// 242 PAY 216 

    0x73077f55,// 243 PAY 217 

    0xc8224672,// 244 PAY 218 

    0xace3adb7,// 245 PAY 219 

    0x67176420,// 246 PAY 220 

    0x12780302,// 247 PAY 221 

    0xa96c2719,// 248 PAY 222 

    0x7dcb06cc,// 249 PAY 223 

    0x71039b8d,// 250 PAY 224 

    0x0c2edbb1,// 251 PAY 225 

    0x3955df1b,// 252 PAY 226 

    0x16f4e577,// 253 PAY 227 

    0xafe6bd41,// 254 PAY 228 

    0x60f12995,// 255 PAY 229 

    0x7c645fd9,// 256 PAY 230 

    0x89e5e43b,// 257 PAY 231 

    0x4d9dc067,// 258 PAY 232 

    0x2cb70083,// 259 PAY 233 

    0xd814fd3e,// 260 PAY 234 

    0x0ec62343,// 261 PAY 235 

    0xc0c8eb01,// 262 PAY 236 

    0x9f367c14,// 263 PAY 237 

    0x06b4fa27,// 264 PAY 238 

    0xfb70d926,// 265 PAY 239 

    0x6c6d1e4b,// 266 PAY 240 

    0x20c7dc03,// 267 PAY 241 

    0xb76282d2,// 268 PAY 242 

    0xa6e386de,// 269 PAY 243 

    0x51fe008a,// 270 PAY 244 

    0xb658313b,// 271 PAY 245 

    0xf032c6c4,// 272 PAY 246 

    0x51f98c7b,// 273 PAY 247 

    0x5b38b541,// 274 PAY 248 

    0xb0e0e6a4,// 275 PAY 249 

    0x16747b4b,// 276 PAY 250 

    0x581098c3,// 277 PAY 251 

    0x091a7dbb,// 278 PAY 252 

    0x21206286,// 279 PAY 253 

    0x2bfcb130,// 280 PAY 254 

    0x90f6b16b,// 281 PAY 255 

    0x7d2532ad,// 282 PAY 256 

    0x952fb801,// 283 PAY 257 

    0xf05f27a3,// 284 PAY 258 

    0xe203a3cc,// 285 PAY 259 

    0x3af05450,// 286 PAY 260 

    0x3d3497d3,// 287 PAY 261 

    0x88cf9143,// 288 PAY 262 

    0x7f59aa97,// 289 PAY 263 

    0xe3caf8a7,// 290 PAY 264 

    0x393f66b2,// 291 PAY 265 

    0xddefea42,// 292 PAY 266 

    0x8aae8f92,// 293 PAY 267 

    0x6fca552f,// 294 PAY 268 

    0x323f6395,// 295 PAY 269 

    0x50ad7c67,// 296 PAY 270 

    0xc046dabd,// 297 PAY 271 

    0xdd42371c,// 298 PAY 272 

    0x0a5fcced,// 299 PAY 273 

    0xc26e9cc2,// 300 PAY 274 

    0xcfd80174,// 301 PAY 275 

    0xfafe318a,// 302 PAY 276 

    0x211edc03,// 303 PAY 277 

    0x38175470,// 304 PAY 278 

    0x8f3ae7c9,// 305 PAY 279 

    0xdc5b1787,// 306 PAY 280 

    0x6f16548a,// 307 PAY 281 

    0xe89f9cd3,// 308 PAY 282 

    0x49908891,// 309 PAY 283 

    0x03fb2584,// 310 PAY 284 

    0x20d5b349,// 311 PAY 285 

    0xfbde5fab,// 312 PAY 286 

    0x281a7968,// 313 PAY 287 

    0x8945cff6,// 314 PAY 288 

    0x242b1d85,// 315 PAY 289 

    0x669971a4,// 316 PAY 290 

    0x2a1eeb1b,// 317 PAY 291 

    0x1843cf3d,// 318 PAY 292 

    0x05e0adbb,// 319 PAY 293 

    0x6e441854,// 320 PAY 294 

    0x8285792d,// 321 PAY 295 

    0xfe922c31,// 322 PAY 296 

    0x86ebc963,// 323 PAY 297 

    0x04cf465f,// 324 PAY 298 

    0xce9f5a02,// 325 PAY 299 

    0xe7fd9226,// 326 PAY 300 

    0x0ad9ee69,// 327 PAY 301 

    0x9f598e83,// 328 PAY 302 

    0x9c4e66cb,// 329 PAY 303 

    0xef26feed,// 330 PAY 304 

    0xaf32caad,// 331 PAY 305 

    0x0241030f,// 332 PAY 306 

    0x9e1d59e8,// 333 PAY 307 

    0xf20c7c3b,// 334 PAY 308 

    0xa806c465,// 335 PAY 309 

    0x1a388640,// 336 PAY 310 

    0x495a3f0b,// 337 PAY 311 

    0xa1b2946e,// 338 PAY 312 

    0x6e84db7b,// 339 PAY 313 

    0xaed7c922,// 340 PAY 314 

    0x47cf11e9,// 341 PAY 315 

    0x23493f5f,// 342 PAY 316 

    0x69f419c8,// 343 PAY 317 

    0x2749a187,// 344 PAY 318 

    0x5a4347b7,// 345 PAY 319 

    0xddd65d6a,// 346 PAY 320 

    0x9210d460,// 347 PAY 321 

    0xdb11088f,// 348 PAY 322 

    0x831386f0,// 349 PAY 323 

    0x183f69e6,// 350 PAY 324 

    0x881ed6e4,// 351 PAY 325 

    0x6b653f56,// 352 PAY 326 

    0x1a6f8111,// 353 PAY 327 

    0x125dd0df,// 354 PAY 328 

    0xe674ea8a,// 355 PAY 329 

    0x9d5ed9d1,// 356 PAY 330 

    0xf270bf60,// 357 PAY 331 

    0xf86c1f88,// 358 PAY 332 

    0x432d994d,// 359 PAY 333 

    0xcd245632,// 360 PAY 334 

    0xae973ffb,// 361 PAY 335 

    0xae3976ab,// 362 PAY 336 

    0xd98802ba,// 363 PAY 337 

    0xbb966db4,// 364 PAY 338 

    0xf92e7a1a,// 365 PAY 339 

    0x9f35701c,// 366 PAY 340 

    0xc3b81626,// 367 PAY 341 

    0x6de4c956,// 368 PAY 342 

    0xbd73a86a,// 369 PAY 343 

    0x76eeda10,// 370 PAY 344 

    0x409a76e6,// 371 PAY 345 

    0x2370c406,// 372 PAY 346 

    0x2cf06569,// 373 PAY 347 

    0xd676e733,// 374 PAY 348 

    0x2d09d7db,// 375 PAY 349 

    0x58c6219e,// 376 PAY 350 

    0xce48921e,// 377 PAY 351 

    0x388c8ed7,// 378 PAY 352 

    0x6937189f,// 379 PAY 353 

    0xba92e108,// 380 PAY 354 

    0xb70ebf58,// 381 PAY 355 

    0xe262d00a,// 382 PAY 356 

    0x16ae0651,// 383 PAY 357 

    0x2bb4ab74,// 384 PAY 358 

    0xa45d3698,// 385 PAY 359 

    0x0afd1aa7,// 386 PAY 360 

    0x36c9b4a9,// 387 PAY 361 

    0xc15fc2a1,// 388 PAY 362 

    0xea161c2e,// 389 PAY 363 

    0x96d2ab0b,// 390 PAY 364 

    0x42d3e3e0,// 391 PAY 365 

    0xdf1c891a,// 392 PAY 366 

    0x50666fca,// 393 PAY 367 

    0xb69eb97e,// 394 PAY 368 

    0xc427b202,// 395 PAY 369 

    0xd55436a5,// 396 PAY 370 

    0xc044a2e6,// 397 PAY 371 

    0x6bc0e24f,// 398 PAY 372 

    0x05ae00a3,// 399 PAY 373 

    0xd069cd2a,// 400 PAY 374 

    0x9c65f476,// 401 PAY 375 

    0xfd03cb96,// 402 PAY 376 

    0x898c8fd6,// 403 PAY 377 

    0xe5094fe9,// 404 PAY 378 

    0x0c25ba47,// 405 PAY 379 

    0xcb2c94b5,// 406 PAY 380 

    0x7de7927c,// 407 PAY 381 

    0xa9aa21a2,// 408 PAY 382 

    0x6014dbac,// 409 PAY 383 

    0x31351246,// 410 PAY 384 

    0x304b649a,// 411 PAY 385 

    0x472e34b5,// 412 PAY 386 

    0x2ba30fc3,// 413 PAY 387 

    0x28452a15,// 414 PAY 388 

    0x9e10b59c,// 415 PAY 389 

    0x182e6a0a,// 416 PAY 390 

    0x2e2b4db8,// 417 PAY 391 

    0x0c2ff5d8,// 418 PAY 392 

    0x3eb23f8e,// 419 PAY 393 

    0x334f5537,// 420 PAY 394 

    0x6c9f9471,// 421 PAY 395 

    0xe6046115,// 422 PAY 396 

    0xf0c0aba8,// 423 PAY 397 

    0xfbfc4bbd,// 424 PAY 398 

    0xbf031c15,// 425 PAY 399 

    0x7fa1f758,// 426 PAY 400 

    0x3e8bf106,// 427 PAY 401 

    0x706fc565,// 428 PAY 402 

    0xb245b6b0,// 429 PAY 403 

    0xbaced57e,// 430 PAY 404 

    0xb03e5da3,// 431 PAY 405 

    0xf27233f1,// 432 PAY 406 

    0xd1688303,// 433 PAY 407 

    0xd5a4e6e5,// 434 PAY 408 

    0x917fb94a,// 435 PAY 409 

    0xdf4e978b,// 436 PAY 410 

    0x6b32b2c5,// 437 PAY 411 

    0xb0970987,// 438 PAY 412 

    0xeaa832c5,// 439 PAY 413 

    0x7f0c69e3,// 440 PAY 414 

    0x9c320b42,// 441 PAY 415 

    0x60d5f5b2,// 442 PAY 416 

    0x0b67f975,// 443 PAY 417 

    0xe267efaf,// 444 PAY 418 

    0x19c44204,// 445 PAY 419 

    0xfebaa6ef,// 446 PAY 420 

    0x9defc1cb,// 447 PAY 421 

    0x52550f1a,// 448 PAY 422 

    0x92ca8566,// 449 PAY 423 

    0xaef3b83a,// 450 PAY 424 

    0xa7ae5e07,// 451 PAY 425 

    0x0f8428d6,// 452 PAY 426 

    0x8c4d2304,// 453 PAY 427 

    0x125529a0,// 454 PAY 428 

    0x2c228b74,// 455 PAY 429 

    0xa640a000,// 456 PAY 430 

/// STA is 1 words. 

/// STA num_pkts       : 10 

/// STA pkt_idx        : 216 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x7c 

    0x03607c0a // 457 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt12_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x808428b2,// 4 SCX   2 

    0x00003184,// 5 SCX   3 

    0xf36283e5,// 6 SCX   4 

    0x449e04d1,// 7 SCX   5 

    0xf71e710a,// 8 SCX   6 

    0x88ac42c0,// 9 SCX   7 

    0x45540f99,// 10 SCX   8 

    0xdaf9c2f7,// 11 SCX   9 

    0xa557bda1,// 12 SCX  10 

    0xda0e1b55,// 13 SCX  11 

    0x7d872c05,// 14 SCX  12 

    0x8618da5c,// 15 SCX  13 

    0x897cdbc3,// 16 SCX  14 

    0xc46711f9,// 17 SCX  15 

    0x9ae20df5,// 18 SCX  16 

    0x3ecc5cc4,// 19 SCX  17 

    0x06ede13e,// 20 SCX  18 

    0xaadc61ff,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1937 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 42 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 42 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 20 

/// BFD (ofst+len)cry  : 36 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 548 

    0x0000002a,// 22 BFD   1 

    0x00140010,// 23 BFD   2 

    0x02240000,// 24 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 4 

    0x0400a5aa,// 25 MFM   1 

/// BDA is 486 words. 

/// BDA size     is 1937 (0x791) 

/// BDA id       is 0x79ee 

    0x079179ee,// 26 BDA   1 

/// PAY Generic Data size   : 1937 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x29ad4d16,// 27 PAY   1 

    0xdec9ad19,// 28 PAY   2 

    0xe6a43e37,// 29 PAY   3 

    0xb4a14e11,// 30 PAY   4 

    0x95ad3741,// 31 PAY   5 

    0x75f0b8cf,// 32 PAY   6 

    0xc4ec5404,// 33 PAY   7 

    0x0b6f70fd,// 34 PAY   8 

    0xb25ff5ad,// 35 PAY   9 

    0x91598154,// 36 PAY  10 

    0xc2f0fb97,// 37 PAY  11 

    0xdbc6b6ee,// 38 PAY  12 

    0xf314e5c6,// 39 PAY  13 

    0x7fdea901,// 40 PAY  14 

    0x849bcc52,// 41 PAY  15 

    0x277cc372,// 42 PAY  16 

    0x88639561,// 43 PAY  17 

    0x138f9796,// 44 PAY  18 

    0x650ba079,// 45 PAY  19 

    0xefe11bd4,// 46 PAY  20 

    0xdc614875,// 47 PAY  21 

    0xd6b56d32,// 48 PAY  22 

    0x1d000eb3,// 49 PAY  23 

    0xaf92b4d6,// 50 PAY  24 

    0x6bc5497a,// 51 PAY  25 

    0xb719666d,// 52 PAY  26 

    0x19ef9618,// 53 PAY  27 

    0xec8aea68,// 54 PAY  28 

    0x70f3c731,// 55 PAY  29 

    0x33984ab4,// 56 PAY  30 

    0x14154dc8,// 57 PAY  31 

    0xa0b9f4ff,// 58 PAY  32 

    0xca68d849,// 59 PAY  33 

    0xaa31dd0c,// 60 PAY  34 

    0x4dfa42d7,// 61 PAY  35 

    0x09761b22,// 62 PAY  36 

    0x236c828f,// 63 PAY  37 

    0x1526a848,// 64 PAY  38 

    0xa22d9e15,// 65 PAY  39 

    0x36ece59f,// 66 PAY  40 

    0x19d8b86e,// 67 PAY  41 

    0xc656bbcc,// 68 PAY  42 

    0x1e9aba43,// 69 PAY  43 

    0x20ea8645,// 70 PAY  44 

    0x6402dbd0,// 71 PAY  45 

    0x741ea35e,// 72 PAY  46 

    0x79be86da,// 73 PAY  47 

    0x6aec87a7,// 74 PAY  48 

    0x94c56ad0,// 75 PAY  49 

    0x75e4b2ac,// 76 PAY  50 

    0x27cc49f8,// 77 PAY  51 

    0x7ab86750,// 78 PAY  52 

    0xc37d063d,// 79 PAY  53 

    0x54f3355a,// 80 PAY  54 

    0x81f5c57d,// 81 PAY  55 

    0xf737a763,// 82 PAY  56 

    0x6f429854,// 83 PAY  57 

    0x9480c4ee,// 84 PAY  58 

    0x2539bd4c,// 85 PAY  59 

    0x6b49d37c,// 86 PAY  60 

    0x01b34ad6,// 87 PAY  61 

    0x50e0495d,// 88 PAY  62 

    0x61bc1bb1,// 89 PAY  63 

    0xb14c0e1c,// 90 PAY  64 

    0x669b1dbc,// 91 PAY  65 

    0xc804c4cb,// 92 PAY  66 

    0xc3d10b07,// 93 PAY  67 

    0x9f2f6a0f,// 94 PAY  68 

    0x65d2457e,// 95 PAY  69 

    0x5141d781,// 96 PAY  70 

    0xf8b31267,// 97 PAY  71 

    0x1f0cc512,// 98 PAY  72 

    0x6366b112,// 99 PAY  73 

    0xacd4bf6f,// 100 PAY  74 

    0x63945765,// 101 PAY  75 

    0x7d769c64,// 102 PAY  76 

    0x5b6d9f47,// 103 PAY  77 

    0x50bdf654,// 104 PAY  78 

    0xecc2da01,// 105 PAY  79 

    0x1410db3b,// 106 PAY  80 

    0x94845df4,// 107 PAY  81 

    0xc7c82e44,// 108 PAY  82 

    0xc82d6312,// 109 PAY  83 

    0xbc367860,// 110 PAY  84 

    0xf97e9676,// 111 PAY  85 

    0xbf0ba480,// 112 PAY  86 

    0x9959aec6,// 113 PAY  87 

    0x81d4dbc7,// 114 PAY  88 

    0x35e61e31,// 115 PAY  89 

    0xccd584a5,// 116 PAY  90 

    0xc7b88e5a,// 117 PAY  91 

    0xa468eabc,// 118 PAY  92 

    0x2241c371,// 119 PAY  93 

    0x1d42d93d,// 120 PAY  94 

    0x88babd01,// 121 PAY  95 

    0xaf02c04d,// 122 PAY  96 

    0x5c96f279,// 123 PAY  97 

    0x93801ffb,// 124 PAY  98 

    0x707741c9,// 125 PAY  99 

    0x174fcaca,// 126 PAY 100 

    0x7e2fef27,// 127 PAY 101 

    0xcae18e65,// 128 PAY 102 

    0xd7310d0c,// 129 PAY 103 

    0x431b3c11,// 130 PAY 104 

    0x54fc0548,// 131 PAY 105 

    0x68df36d8,// 132 PAY 106 

    0x75aaa62a,// 133 PAY 107 

    0xd2aea238,// 134 PAY 108 

    0x6e5c111b,// 135 PAY 109 

    0x1e7b728a,// 136 PAY 110 

    0xf1055e4a,// 137 PAY 111 

    0xf454fa0f,// 138 PAY 112 

    0xde3c771c,// 139 PAY 113 

    0x67663e9d,// 140 PAY 114 

    0x2494046e,// 141 PAY 115 

    0x6068a1eb,// 142 PAY 116 

    0xbe1988f5,// 143 PAY 117 

    0xf109946a,// 144 PAY 118 

    0x8684ee85,// 145 PAY 119 

    0x255bd29e,// 146 PAY 120 

    0x5596b77f,// 147 PAY 121 

    0x0c8aa184,// 148 PAY 122 

    0x7acec6a3,// 149 PAY 123 

    0x2d6ece8b,// 150 PAY 124 

    0x8e35abd8,// 151 PAY 125 

    0x4e47a77f,// 152 PAY 126 

    0x4f1f5635,// 153 PAY 127 

    0x02eba323,// 154 PAY 128 

    0xf219ee99,// 155 PAY 129 

    0xc1166bb3,// 156 PAY 130 

    0x7c7efcec,// 157 PAY 131 

    0xc5d9acd0,// 158 PAY 132 

    0x721a1587,// 159 PAY 133 

    0x95235f1c,// 160 PAY 134 

    0x0e754f6a,// 161 PAY 135 

    0x7ac7f15c,// 162 PAY 136 

    0x1b6edf46,// 163 PAY 137 

    0x093ac08f,// 164 PAY 138 

    0xe685573c,// 165 PAY 139 

    0xaadf90fe,// 166 PAY 140 

    0xca4f4e61,// 167 PAY 141 

    0xe2f92cd9,// 168 PAY 142 

    0x968cc4d6,// 169 PAY 143 

    0x165c03e8,// 170 PAY 144 

    0x5e1c241b,// 171 PAY 145 

    0x128abe65,// 172 PAY 146 

    0xe7ba07ac,// 173 PAY 147 

    0x54791b4c,// 174 PAY 148 

    0xc718b896,// 175 PAY 149 

    0x8d2837e5,// 176 PAY 150 

    0xb2efcfcf,// 177 PAY 151 

    0xc92cbdac,// 178 PAY 152 

    0x60116439,// 179 PAY 153 

    0xeada5876,// 180 PAY 154 

    0xe383db4a,// 181 PAY 155 

    0x7134d267,// 182 PAY 156 

    0x8bf39504,// 183 PAY 157 

    0x04590152,// 184 PAY 158 

    0x2111af35,// 185 PAY 159 

    0x846fc7a5,// 186 PAY 160 

    0xbb7eb771,// 187 PAY 161 

    0xa7442f9b,// 188 PAY 162 

    0x8ba1abf4,// 189 PAY 163 

    0xd4730f32,// 190 PAY 164 

    0xec359a8e,// 191 PAY 165 

    0x741558c1,// 192 PAY 166 

    0x7d482140,// 193 PAY 167 

    0x75fc9c54,// 194 PAY 168 

    0x5209067c,// 195 PAY 169 

    0xd61f891d,// 196 PAY 170 

    0xf4061f4e,// 197 PAY 171 

    0xb023b4a4,// 198 PAY 172 

    0xd9cdd109,// 199 PAY 173 

    0x849e41e7,// 200 PAY 174 

    0x9290b5b3,// 201 PAY 175 

    0x8d1a1ac9,// 202 PAY 176 

    0x5cddc926,// 203 PAY 177 

    0x076e988d,// 204 PAY 178 

    0x26dbf318,// 205 PAY 179 

    0x1887eb25,// 206 PAY 180 

    0xd514177f,// 207 PAY 181 

    0x2c9d78d7,// 208 PAY 182 

    0x2a167582,// 209 PAY 183 

    0x0920fb7f,// 210 PAY 184 

    0x38fa8d59,// 211 PAY 185 

    0xbb5c8493,// 212 PAY 186 

    0xb5d46d5c,// 213 PAY 187 

    0x88af5e55,// 214 PAY 188 

    0x5aca8666,// 215 PAY 189 

    0x1ce86d33,// 216 PAY 190 

    0xd3271ba2,// 217 PAY 191 

    0x21e79df9,// 218 PAY 192 

    0xb8f25f64,// 219 PAY 193 

    0x40b4df1d,// 220 PAY 194 

    0xbab2fad5,// 221 PAY 195 

    0x67ec02f6,// 222 PAY 196 

    0xfb6dda31,// 223 PAY 197 

    0x291b6061,// 224 PAY 198 

    0xcf660fdb,// 225 PAY 199 

    0x70418c30,// 226 PAY 200 

    0x3b3b4cfa,// 227 PAY 201 

    0xc817ae50,// 228 PAY 202 

    0xc73ff68b,// 229 PAY 203 

    0xc1824ec9,// 230 PAY 204 

    0xd78aec57,// 231 PAY 205 

    0x5912fbdc,// 232 PAY 206 

    0xee1bf2e6,// 233 PAY 207 

    0xf452d10c,// 234 PAY 208 

    0x85914ff2,// 235 PAY 209 

    0xf46bb6ff,// 236 PAY 210 

    0xca3b02c8,// 237 PAY 211 

    0x179d3321,// 238 PAY 212 

    0x40bc7475,// 239 PAY 213 

    0x6939b2d6,// 240 PAY 214 

    0xfb346fc5,// 241 PAY 215 

    0x1d9dc3b7,// 242 PAY 216 

    0x5a276947,// 243 PAY 217 

    0xe12f0469,// 244 PAY 218 

    0xcdb142b0,// 245 PAY 219 

    0x582450bd,// 246 PAY 220 

    0x082dc4f0,// 247 PAY 221 

    0xdb61169d,// 248 PAY 222 

    0xd70d8214,// 249 PAY 223 

    0x71093e50,// 250 PAY 224 

    0xe6d46826,// 251 PAY 225 

    0x544547ce,// 252 PAY 226 

    0x4aebcdce,// 253 PAY 227 

    0xcfb5fc5f,// 254 PAY 228 

    0x7e78963d,// 255 PAY 229 

    0x3c098fab,// 256 PAY 230 

    0x99a04fbf,// 257 PAY 231 

    0x215bf313,// 258 PAY 232 

    0x648f4358,// 259 PAY 233 

    0x21dfa479,// 260 PAY 234 

    0x3ff61a7f,// 261 PAY 235 

    0x091c03e4,// 262 PAY 236 

    0xf6b59947,// 263 PAY 237 

    0x7ecf2943,// 264 PAY 238 

    0x5b75308f,// 265 PAY 239 

    0xbd93d5d9,// 266 PAY 240 

    0xc693ce4c,// 267 PAY 241 

    0x2250d1a3,// 268 PAY 242 

    0x215cd62e,// 269 PAY 243 

    0x203fb0e0,// 270 PAY 244 

    0x10d44d56,// 271 PAY 245 

    0x600b65a5,// 272 PAY 246 

    0x0ef18eee,// 273 PAY 247 

    0x897bf6a8,// 274 PAY 248 

    0xd1b72c47,// 275 PAY 249 

    0x5cbd95bc,// 276 PAY 250 

    0xbac4a43e,// 277 PAY 251 

    0xa5b39e40,// 278 PAY 252 

    0x20b7501f,// 279 PAY 253 

    0xb55fd748,// 280 PAY 254 

    0x7a17b832,// 281 PAY 255 

    0xb0f0bff3,// 282 PAY 256 

    0x37ae3c0a,// 283 PAY 257 

    0xfc5acb2e,// 284 PAY 258 

    0x623b85bf,// 285 PAY 259 

    0x79ca7d62,// 286 PAY 260 

    0x4797b17e,// 287 PAY 261 

    0xa1013847,// 288 PAY 262 

    0x90b68566,// 289 PAY 263 

    0x251dbe84,// 290 PAY 264 

    0xbb521501,// 291 PAY 265 

    0x254209d7,// 292 PAY 266 

    0xb481ee7d,// 293 PAY 267 

    0xcca6c4f2,// 294 PAY 268 

    0x73c77860,// 295 PAY 269 

    0xccccf6ab,// 296 PAY 270 

    0x7f30b95b,// 297 PAY 271 

    0xaff7a182,// 298 PAY 272 

    0x33e5eb96,// 299 PAY 273 

    0x7c13d8ec,// 300 PAY 274 

    0x05a60ea7,// 301 PAY 275 

    0xdaccf557,// 302 PAY 276 

    0xc971e42a,// 303 PAY 277 

    0x70092fbd,// 304 PAY 278 

    0x5a378c3e,// 305 PAY 279 

    0x417f4264,// 306 PAY 280 

    0xd8047429,// 307 PAY 281 

    0x3806fba2,// 308 PAY 282 

    0xc98a737e,// 309 PAY 283 

    0x43f41260,// 310 PAY 284 

    0xa3f9307e,// 311 PAY 285 

    0xfd2943ec,// 312 PAY 286 

    0x340e78d7,// 313 PAY 287 

    0xf379c5e8,// 314 PAY 288 

    0x51e58937,// 315 PAY 289 

    0xb46807da,// 316 PAY 290 

    0xa7a46b3b,// 317 PAY 291 

    0xad12e26c,// 318 PAY 292 

    0xcb90248e,// 319 PAY 293 

    0x97414d59,// 320 PAY 294 

    0x7c605e1d,// 321 PAY 295 

    0x55bf1166,// 322 PAY 296 

    0x392cc722,// 323 PAY 297 

    0x2893d899,// 324 PAY 298 

    0xb6fa206c,// 325 PAY 299 

    0x3dd1b205,// 326 PAY 300 

    0x26a67dd2,// 327 PAY 301 

    0x8a363609,// 328 PAY 302 

    0x581cec8c,// 329 PAY 303 

    0x282624f7,// 330 PAY 304 

    0xeaf6e7eb,// 331 PAY 305 

    0xa3fbfa90,// 332 PAY 306 

    0x505f5aac,// 333 PAY 307 

    0xaa4f9896,// 334 PAY 308 

    0xbb4f8dda,// 335 PAY 309 

    0x95a95f18,// 336 PAY 310 

    0x88a3f1a3,// 337 PAY 311 

    0xbdd667bf,// 338 PAY 312 

    0xac89a848,// 339 PAY 313 

    0x74db39bd,// 340 PAY 314 

    0x5dbc50fb,// 341 PAY 315 

    0x868aaf42,// 342 PAY 316 

    0x1d46926b,// 343 PAY 317 

    0x28998aa1,// 344 PAY 318 

    0xcc8a850d,// 345 PAY 319 

    0x75a3b33c,// 346 PAY 320 

    0x34370c38,// 347 PAY 321 

    0x1007d2d7,// 348 PAY 322 

    0x5e208c02,// 349 PAY 323 

    0x9d535bfc,// 350 PAY 324 

    0x1d32e921,// 351 PAY 325 

    0xd9e33271,// 352 PAY 326 

    0x7ac1141b,// 353 PAY 327 

    0x55281aad,// 354 PAY 328 

    0x8b8ef928,// 355 PAY 329 

    0x8ead79b1,// 356 PAY 330 

    0x8f3723da,// 357 PAY 331 

    0x7dc15b2a,// 358 PAY 332 

    0xdd465fd7,// 359 PAY 333 

    0xd177c562,// 360 PAY 334 

    0x80795d2c,// 361 PAY 335 

    0x0748e006,// 362 PAY 336 

    0x27334e67,// 363 PAY 337 

    0x9d1c40c5,// 364 PAY 338 

    0xfc9647e7,// 365 PAY 339 

    0x28256c28,// 366 PAY 340 

    0x242b5c04,// 367 PAY 341 

    0xb78c30b2,// 368 PAY 342 

    0x4d7b0e42,// 369 PAY 343 

    0x06e1588d,// 370 PAY 344 

    0xc73a2744,// 371 PAY 345 

    0x388810f2,// 372 PAY 346 

    0xae418c6b,// 373 PAY 347 

    0xcfcb4cc5,// 374 PAY 348 

    0x3a9f6e87,// 375 PAY 349 

    0x43852f53,// 376 PAY 350 

    0x6e856d8c,// 377 PAY 351 

    0xb09fadd4,// 378 PAY 352 

    0xdd7dadb2,// 379 PAY 353 

    0x729433ec,// 380 PAY 354 

    0xb59e2f80,// 381 PAY 355 

    0x97187eeb,// 382 PAY 356 

    0x259d7782,// 383 PAY 357 

    0x5f4b2f78,// 384 PAY 358 

    0x7c9f9459,// 385 PAY 359 

    0xe2b32441,// 386 PAY 360 

    0xebc6bdc0,// 387 PAY 361 

    0x806333b1,// 388 PAY 362 

    0x7c482afe,// 389 PAY 363 

    0xfe960f66,// 390 PAY 364 

    0x04fb96a0,// 391 PAY 365 

    0xddbb9ffb,// 392 PAY 366 

    0x8b982a3b,// 393 PAY 367 

    0xc2f5cca7,// 394 PAY 368 

    0x408144bf,// 395 PAY 369 

    0xe325347e,// 396 PAY 370 

    0xdb2b17a5,// 397 PAY 371 

    0xdbae6bcb,// 398 PAY 372 

    0x4821ec4e,// 399 PAY 373 

    0x9051edbc,// 400 PAY 374 

    0x61643ead,// 401 PAY 375 

    0x67d23f62,// 402 PAY 376 

    0xb4ff714e,// 403 PAY 377 

    0x6d406be7,// 404 PAY 378 

    0x18ec2796,// 405 PAY 379 

    0x110211af,// 406 PAY 380 

    0x75776ad5,// 407 PAY 381 

    0x879adc70,// 408 PAY 382 

    0x29ec0cbd,// 409 PAY 383 

    0xe5d9b18a,// 410 PAY 384 

    0x6ff39f74,// 411 PAY 385 

    0x8a21d946,// 412 PAY 386 

    0x9a804654,// 413 PAY 387 

    0x868bfdd9,// 414 PAY 388 

    0x7d42706e,// 415 PAY 389 

    0x30aa3a11,// 416 PAY 390 

    0x702b87ee,// 417 PAY 391 

    0x191397e1,// 418 PAY 392 

    0xe125f8c2,// 419 PAY 393 

    0xc339efbc,// 420 PAY 394 

    0xe44a287a,// 421 PAY 395 

    0x35d22e61,// 422 PAY 396 

    0xecb449ad,// 423 PAY 397 

    0x9db764c5,// 424 PAY 398 

    0x423dc51f,// 425 PAY 399 

    0x12b31864,// 426 PAY 400 

    0xa9090c9d,// 427 PAY 401 

    0xa8690700,// 428 PAY 402 

    0x1090116b,// 429 PAY 403 

    0x8c54df86,// 430 PAY 404 

    0x3aa14744,// 431 PAY 405 

    0x1e564b9e,// 432 PAY 406 

    0x144012f6,// 433 PAY 407 

    0xad3ff031,// 434 PAY 408 

    0x10b6df8a,// 435 PAY 409 

    0xfab6988c,// 436 PAY 410 

    0xb0f48a97,// 437 PAY 411 

    0xaa908c81,// 438 PAY 412 

    0x6b318090,// 439 PAY 413 

    0x1027b3ae,// 440 PAY 414 

    0xf6f82248,// 441 PAY 415 

    0x408bfdd5,// 442 PAY 416 

    0x05c1d5fe,// 443 PAY 417 

    0xb82dd639,// 444 PAY 418 

    0x7dd9b21b,// 445 PAY 419 

    0x87b60540,// 446 PAY 420 

    0x50f8752d,// 447 PAY 421 

    0xe8f0cbad,// 448 PAY 422 

    0x4284027f,// 449 PAY 423 

    0x3b8f6e08,// 450 PAY 424 

    0xd1b37864,// 451 PAY 425 

    0x1043b7b1,// 452 PAY 426 

    0x1db2205b,// 453 PAY 427 

    0x506db5f7,// 454 PAY 428 

    0x791c71d7,// 455 PAY 429 

    0xac73a605,// 456 PAY 430 

    0xad211e73,// 457 PAY 431 

    0x26e7bd45,// 458 PAY 432 

    0xba519b2e,// 459 PAY 433 

    0x7081f36a,// 460 PAY 434 

    0x3d0813c4,// 461 PAY 435 

    0x65ff7bf9,// 462 PAY 436 

    0x4f14436d,// 463 PAY 437 

    0xb5cb3cea,// 464 PAY 438 

    0x67e60c4e,// 465 PAY 439 

    0x3d939651,// 466 PAY 440 

    0x0e8e46ff,// 467 PAY 441 

    0x83a1c9a5,// 468 PAY 442 

    0xdf062ae9,// 469 PAY 443 

    0xf275883d,// 470 PAY 444 

    0xe9f3cfc1,// 471 PAY 445 

    0x1ba8f031,// 472 PAY 446 

    0xc5f8f6ce,// 473 PAY 447 

    0x27748d78,// 474 PAY 448 

    0xb1cb3b3b,// 475 PAY 449 

    0xefd16e93,// 476 PAY 450 

    0xb9dd327a,// 477 PAY 451 

    0x5b4ca43f,// 478 PAY 452 

    0x3a971a1c,// 479 PAY 453 

    0xaa8fa868,// 480 PAY 454 

    0x2e9c8905,// 481 PAY 455 

    0x52f87326,// 482 PAY 456 

    0x0d0354f9,// 483 PAY 457 

    0x79a090b0,// 484 PAY 458 

    0xdbafda81,// 485 PAY 459 

    0x0f0c2351,// 486 PAY 460 

    0x126055a7,// 487 PAY 461 

    0x424f5e6c,// 488 PAY 462 

    0x73b3384c,// 489 PAY 463 

    0xef422d63,// 490 PAY 464 

    0xd83e5f52,// 491 PAY 465 

    0x12a37b30,// 492 PAY 466 

    0x66696ab0,// 493 PAY 467 

    0xaf8dd456,// 494 PAY 468 

    0xc3c02fad,// 495 PAY 469 

    0x62797a37,// 496 PAY 470 

    0x4d220697,// 497 PAY 471 

    0x8533cb32,// 498 PAY 472 

    0x55bbdca5,// 499 PAY 473 

    0x31f4b3ff,// 500 PAY 474 

    0x11d0afa2,// 501 PAY 475 

    0x81e695b6,// 502 PAY 476 

    0x8e4ea732,// 503 PAY 477 

    0x2a7d2fb9,// 504 PAY 478 

    0x03153249,// 505 PAY 479 

    0x2be30d51,// 506 PAY 480 

    0x93c542e3,// 507 PAY 481 

    0x7ff2a896,// 508 PAY 482 

    0xef3c2eda,// 509 PAY 483 

    0x34e080c5,// 510 PAY 484 

    0x7d000000,// 511 PAY 485 

/// STA is 1 words. 

/// STA num_pkts       : 116 

/// STA pkt_idx        : 70 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xcf 

    0x0119cf74 // 512 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt13_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x808228b7,// 4 SCX   2 

    0x00006400,// 5 SCX   3 

    0xa9d2d89c,// 6 SCX   4 

    0x709938a9,// 7 SCX   5 

    0x93fa1aa6,// 8 SCX   6 

    0x8d32dddf,// 9 SCX   7 

    0x2bd4e7b2,// 10 SCX   8 

    0x95316421,// 11 SCX   9 

    0x549243a8,// 12 SCX  10 

    0x35c4e3f7,// 13 SCX  11 

    0x20b24ad1,// 14 SCX  12 

    0x93e976d3,// 15 SCX  13 

    0x8c7b82ea,// 16 SCX  14 

    0x713db1e2,// 17 SCX  15 

    0x7426a498,// 18 SCX  16 

    0x3056c034,// 19 SCX  17 

    0x7b9d4e33,// 20 SCX  18 

    0xb65972cf,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1441 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 748 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 748 

/// BFD lencrypto      : 64 

/// BFD ofstcrypto     : 536 

/// BFD (ofst+len)cry  : 600 

/// BFD ofstiv         : 232 

/// BFD ofsticv        : 964 

    0x000002ec,// 22 BFD   1 

    0x02180040,// 23 BFD   2 

    0x03c400e8,// 24 BFD   3 

/// MFM is 10 words. 

/// MFM vldnibs        : 45 

    0x45006431,// 25 MFM   1 

    0xfaf31da1,// 26 MFM   2 

    0xd3b2350e,// 27 MFM   3 

    0xeea1f788,// 28 MFM   4 

    0x498c84ec,// 29 MFM   5 

    0xe221d8a0,// 30 MFM   6 

    0x268b1ae1,// 31 MFM   7 

    0x13c16f55,// 32 MFM   8 

    0x3be5bd26,// 33 MFM   9 

    0x10000000,// 34 MFM  10 

/// BDA is 362 words. 

/// BDA size     is 1441 (0x5a1) 

/// BDA id       is 0x91a 

    0x05a1091a,// 35 BDA   1 

/// PAY Generic Data size   : 1441 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x73a62440,// 36 PAY   1 

    0x97a59904,// 37 PAY   2 

    0xda4b990a,// 38 PAY   3 

    0xc20c764b,// 39 PAY   4 

    0x0d03f0bd,// 40 PAY   5 

    0xe167a0d6,// 41 PAY   6 

    0xec2b0e57,// 42 PAY   7 

    0xc379a17a,// 43 PAY   8 

    0x3bacbe89,// 44 PAY   9 

    0x7eaa7ade,// 45 PAY  10 

    0xaa102562,// 46 PAY  11 

    0xf95478dc,// 47 PAY  12 

    0x6bcd9ccd,// 48 PAY  13 

    0x21adb193,// 49 PAY  14 

    0x6c93a565,// 50 PAY  15 

    0x166f7124,// 51 PAY  16 

    0xecd272c4,// 52 PAY  17 

    0xe0933108,// 53 PAY  18 

    0xd6880d1d,// 54 PAY  19 

    0xc4105c9b,// 55 PAY  20 

    0x277432c2,// 56 PAY  21 

    0xc30a8b78,// 57 PAY  22 

    0x9ced9b95,// 58 PAY  23 

    0x1446d2a9,// 59 PAY  24 

    0x9560c5c1,// 60 PAY  25 

    0xb1656469,// 61 PAY  26 

    0x6585fc3a,// 62 PAY  27 

    0x5a3dfe46,// 63 PAY  28 

    0xbd60cd8c,// 64 PAY  29 

    0x1a8a0cfb,// 65 PAY  30 

    0xe1a72da2,// 66 PAY  31 

    0x416c8514,// 67 PAY  32 

    0x2e932ee9,// 68 PAY  33 

    0xcb5ed8a0,// 69 PAY  34 

    0xb38cce61,// 70 PAY  35 

    0xbeb0a704,// 71 PAY  36 

    0x41b0f536,// 72 PAY  37 

    0x54ff7bee,// 73 PAY  38 

    0x950e5313,// 74 PAY  39 

    0xf503b557,// 75 PAY  40 

    0xdacba06c,// 76 PAY  41 

    0x4a4c4e0b,// 77 PAY  42 

    0x35a841bd,// 78 PAY  43 

    0xde508424,// 79 PAY  44 

    0x2fab6984,// 80 PAY  45 

    0x7d6db8ee,// 81 PAY  46 

    0x0e7d04a4,// 82 PAY  47 

    0x54d3042a,// 83 PAY  48 

    0xa08c504f,// 84 PAY  49 

    0x7737506a,// 85 PAY  50 

    0x32fcc2d9,// 86 PAY  51 

    0xbdcdcd1f,// 87 PAY  52 

    0x3a29edda,// 88 PAY  53 

    0xc9c85418,// 89 PAY  54 

    0x585741b1,// 90 PAY  55 

    0x94b9c742,// 91 PAY  56 

    0xbb6c2553,// 92 PAY  57 

    0xaff12e29,// 93 PAY  58 

    0x2ae46f42,// 94 PAY  59 

    0xa0ff06df,// 95 PAY  60 

    0x4343994b,// 96 PAY  61 

    0xdd131482,// 97 PAY  62 

    0x7ba9e498,// 98 PAY  63 

    0x73a51dbb,// 99 PAY  64 

    0xa3e8a7b8,// 100 PAY  65 

    0xa062be02,// 101 PAY  66 

    0x5381da81,// 102 PAY  67 

    0x9ec04b8b,// 103 PAY  68 

    0xca2b3e22,// 104 PAY  69 

    0x24b14d45,// 105 PAY  70 

    0xf1e9aa44,// 106 PAY  71 

    0x72c8069f,// 107 PAY  72 

    0x10aa87af,// 108 PAY  73 

    0xfa00f9b6,// 109 PAY  74 

    0x126c6630,// 110 PAY  75 

    0x187af8d8,// 111 PAY  76 

    0xcb6e5ad3,// 112 PAY  77 

    0x9403e84b,// 113 PAY  78 

    0x4b69121e,// 114 PAY  79 

    0x84c385f6,// 115 PAY  80 

    0xad0277ee,// 116 PAY  81 

    0xb4ddd5ef,// 117 PAY  82 

    0x8bba353c,// 118 PAY  83 

    0x3e7dec84,// 119 PAY  84 

    0x010b0da9,// 120 PAY  85 

    0xc8088058,// 121 PAY  86 

    0x25a81c0b,// 122 PAY  87 

    0xbda826c4,// 123 PAY  88 

    0x4e7c21cc,// 124 PAY  89 

    0x73f3d61d,// 125 PAY  90 

    0xe739ae09,// 126 PAY  91 

    0x7791aabb,// 127 PAY  92 

    0xd9fc40dd,// 128 PAY  93 

    0x69a4dbc9,// 129 PAY  94 

    0x88fffb9e,// 130 PAY  95 

    0x6d8d5609,// 131 PAY  96 

    0xfd308f38,// 132 PAY  97 

    0x10b1911e,// 133 PAY  98 

    0xc8c294d6,// 134 PAY  99 

    0xc4bbb7e5,// 135 PAY 100 

    0xd967c849,// 136 PAY 101 

    0x88e750e4,// 137 PAY 102 

    0xadbd7f91,// 138 PAY 103 

    0x7efd05dd,// 139 PAY 104 

    0x866efb02,// 140 PAY 105 

    0x12391a15,// 141 PAY 106 

    0xf55eb464,// 142 PAY 107 

    0x317e0f29,// 143 PAY 108 

    0xf25d5037,// 144 PAY 109 

    0x71a833b6,// 145 PAY 110 

    0x1648e696,// 146 PAY 111 

    0xcb9949a1,// 147 PAY 112 

    0xe8f83439,// 148 PAY 113 

    0xa06cc068,// 149 PAY 114 

    0x3b0c095c,// 150 PAY 115 

    0x6cc70313,// 151 PAY 116 

    0xacab14c6,// 152 PAY 117 

    0xfd51b6bf,// 153 PAY 118 

    0x08754a4b,// 154 PAY 119 

    0xd4615f45,// 155 PAY 120 

    0x998ecf25,// 156 PAY 121 

    0xc8d8fd59,// 157 PAY 122 

    0xab0fb83b,// 158 PAY 123 

    0x4e8ac1c6,// 159 PAY 124 

    0x96fee4d9,// 160 PAY 125 

    0x7d8fc21e,// 161 PAY 126 

    0x22627f0e,// 162 PAY 127 

    0xcd90384b,// 163 PAY 128 

    0xb5b66c99,// 164 PAY 129 

    0x4c1061f8,// 165 PAY 130 

    0xb068a0ee,// 166 PAY 131 

    0x08fef841,// 167 PAY 132 

    0xfaf8a575,// 168 PAY 133 

    0xb813de9c,// 169 PAY 134 

    0xffca4834,// 170 PAY 135 

    0x1fde74cd,// 171 PAY 136 

    0x9830d318,// 172 PAY 137 

    0x094dbef0,// 173 PAY 138 

    0xb3f55d3f,// 174 PAY 139 

    0xfbcd9b22,// 175 PAY 140 

    0xbb0bb01c,// 176 PAY 141 

    0x47227fa6,// 177 PAY 142 

    0x8f10d1bc,// 178 PAY 143 

    0x23c5cec4,// 179 PAY 144 

    0xd8175542,// 180 PAY 145 

    0x675228f5,// 181 PAY 146 

    0xea286bbe,// 182 PAY 147 

    0x594bc07a,// 183 PAY 148 

    0xddf51572,// 184 PAY 149 

    0xfa38423a,// 185 PAY 150 

    0x9958aabe,// 186 PAY 151 

    0xadad8167,// 187 PAY 152 

    0xd71e9aa8,// 188 PAY 153 

    0x93518a69,// 189 PAY 154 

    0xf494939c,// 190 PAY 155 

    0x0237e022,// 191 PAY 156 

    0xedd14f98,// 192 PAY 157 

    0x85c08de7,// 193 PAY 158 

    0xe4e59b7d,// 194 PAY 159 

    0xe3925297,// 195 PAY 160 

    0xaa0a91cd,// 196 PAY 161 

    0x9128a168,// 197 PAY 162 

    0xe6abc90f,// 198 PAY 163 

    0x86a6052c,// 199 PAY 164 

    0xb47342aa,// 200 PAY 165 

    0xe3b106b0,// 201 PAY 166 

    0x7671395b,// 202 PAY 167 

    0xe0d0d9c7,// 203 PAY 168 

    0x67edc5af,// 204 PAY 169 

    0x405d83cf,// 205 PAY 170 

    0x9d3942a0,// 206 PAY 171 

    0x5258282a,// 207 PAY 172 

    0x51732f05,// 208 PAY 173 

    0xe363d5d8,// 209 PAY 174 

    0xb826efa5,// 210 PAY 175 

    0xb3a95439,// 211 PAY 176 

    0x881fa2a4,// 212 PAY 177 

    0xa04d2df1,// 213 PAY 178 

    0x5a8dc412,// 214 PAY 179 

    0xaded396b,// 215 PAY 180 

    0x1834a98b,// 216 PAY 181 

    0x898391a9,// 217 PAY 182 

    0x0c6531de,// 218 PAY 183 

    0xef7dd1d8,// 219 PAY 184 

    0x387276fa,// 220 PAY 185 

    0x618f2c95,// 221 PAY 186 

    0xbb84c89a,// 222 PAY 187 

    0xa69f8a61,// 223 PAY 188 

    0x714e2fef,// 224 PAY 189 

    0xcd719bf0,// 225 PAY 190 

    0xf538704d,// 226 PAY 191 

    0x9448a395,// 227 PAY 192 

    0x88e06ce4,// 228 PAY 193 

    0x1ade376a,// 229 PAY 194 

    0x5df95e5d,// 230 PAY 195 

    0x94bd1ce2,// 231 PAY 196 

    0x7201d5a3,// 232 PAY 197 

    0x97f496fc,// 233 PAY 198 

    0x5b3d9525,// 234 PAY 199 

    0xddf2f8ac,// 235 PAY 200 

    0x8976c38e,// 236 PAY 201 

    0xee16a877,// 237 PAY 202 

    0xd95d774f,// 238 PAY 203 

    0x793ebd99,// 239 PAY 204 

    0x0600857e,// 240 PAY 205 

    0xe90c9640,// 241 PAY 206 

    0x0d723895,// 242 PAY 207 

    0x160f5cee,// 243 PAY 208 

    0xd0a3599d,// 244 PAY 209 

    0x7351462a,// 245 PAY 210 

    0x76b7e299,// 246 PAY 211 

    0x13c5dd27,// 247 PAY 212 

    0x8eb11bf7,// 248 PAY 213 

    0xc9ce8933,// 249 PAY 214 

    0x2337fb2b,// 250 PAY 215 

    0x62896df6,// 251 PAY 216 

    0x7d91e9ad,// 252 PAY 217 

    0x4dadf760,// 253 PAY 218 

    0xc0724ac2,// 254 PAY 219 

    0x2d102bb6,// 255 PAY 220 

    0xdb46a07f,// 256 PAY 221 

    0x1eaa06f1,// 257 PAY 222 

    0x91692df1,// 258 PAY 223 

    0xf7eab869,// 259 PAY 224 

    0xc3b20574,// 260 PAY 225 

    0xe19bf4c4,// 261 PAY 226 

    0xc15da5c3,// 262 PAY 227 

    0x24b7f79d,// 263 PAY 228 

    0xf1d5ab72,// 264 PAY 229 

    0x016d8988,// 265 PAY 230 

    0x6373c78b,// 266 PAY 231 

    0xe41ad8a2,// 267 PAY 232 

    0x50c570a1,// 268 PAY 233 

    0x9c557c3e,// 269 PAY 234 

    0x9082c806,// 270 PAY 235 

    0xbf25879f,// 271 PAY 236 

    0x5bd1cbb8,// 272 PAY 237 

    0xcbf8bee0,// 273 PAY 238 

    0xb3e2b971,// 274 PAY 239 

    0x10d38568,// 275 PAY 240 

    0x3dc947ba,// 276 PAY 241 

    0x7c6ac4f2,// 277 PAY 242 

    0xdb8abeec,// 278 PAY 243 

    0x9be7658d,// 279 PAY 244 

    0x123659ad,// 280 PAY 245 

    0x4d199c2f,// 281 PAY 246 

    0x4c623984,// 282 PAY 247 

    0xaba96ccc,// 283 PAY 248 

    0xd8c6ac42,// 284 PAY 249 

    0x6f825c19,// 285 PAY 250 

    0xa0ef5588,// 286 PAY 251 

    0x1f324b30,// 287 PAY 252 

    0x3e48bae0,// 288 PAY 253 

    0x524fbfb5,// 289 PAY 254 

    0x4870fe17,// 290 PAY 255 

    0x039ebc44,// 291 PAY 256 

    0x7d9908db,// 292 PAY 257 

    0x73d0b925,// 293 PAY 258 

    0x80236510,// 294 PAY 259 

    0xf808c71a,// 295 PAY 260 

    0x4c02e872,// 296 PAY 261 

    0x3eb71bb0,// 297 PAY 262 

    0x8d970c7a,// 298 PAY 263 

    0x60411262,// 299 PAY 264 

    0x009d0204,// 300 PAY 265 

    0xb019451f,// 301 PAY 266 

    0x6d51377e,// 302 PAY 267 

    0xda649e2f,// 303 PAY 268 

    0x88d2e594,// 304 PAY 269 

    0x53eefeb0,// 305 PAY 270 

    0xe7ef110f,// 306 PAY 271 

    0x8b09a8b7,// 307 PAY 272 

    0xbb1611f6,// 308 PAY 273 

    0x3352a938,// 309 PAY 274 

    0x3954c5ef,// 310 PAY 275 

    0x4ffeb2ae,// 311 PAY 276 

    0x982779ed,// 312 PAY 277 

    0x176b023a,// 313 PAY 278 

    0x5f24552b,// 314 PAY 279 

    0x9543135b,// 315 PAY 280 

    0x47a29bf5,// 316 PAY 281 

    0x629ab7b5,// 317 PAY 282 

    0x05960861,// 318 PAY 283 

    0xce5fd20f,// 319 PAY 284 

    0x2d67bc6c,// 320 PAY 285 

    0x998308e9,// 321 PAY 286 

    0x4ae3ec89,// 322 PAY 287 

    0x7e2e0e42,// 323 PAY 288 

    0x74189848,// 324 PAY 289 

    0xcb6e2041,// 325 PAY 290 

    0xb816ae5e,// 326 PAY 291 

    0x9fad92d0,// 327 PAY 292 

    0x5c92bd67,// 328 PAY 293 

    0x1b192721,// 329 PAY 294 

    0xeb93652f,// 330 PAY 295 

    0xc104bcb7,// 331 PAY 296 

    0xe9c9975e,// 332 PAY 297 

    0x2481f8a0,// 333 PAY 298 

    0xb110d244,// 334 PAY 299 

    0x9843be5e,// 335 PAY 300 

    0x405eb80d,// 336 PAY 301 

    0x5385c5b9,// 337 PAY 302 

    0xbd466b20,// 338 PAY 303 

    0x510af210,// 339 PAY 304 

    0x26467813,// 340 PAY 305 

    0x00735a92,// 341 PAY 306 

    0x905b7edd,// 342 PAY 307 

    0x514c0e54,// 343 PAY 308 

    0x1810e595,// 344 PAY 309 

    0x1059845a,// 345 PAY 310 

    0x3b8f2324,// 346 PAY 311 

    0xae6d7ab3,// 347 PAY 312 

    0xce58e1ce,// 348 PAY 313 

    0xf568761e,// 349 PAY 314 

    0x672b4eec,// 350 PAY 315 

    0x92426fcc,// 351 PAY 316 

    0x4cbee6b7,// 352 PAY 317 

    0x8a91aa14,// 353 PAY 318 

    0x8805bd1c,// 354 PAY 319 

    0x21527953,// 355 PAY 320 

    0x0c2edbd8,// 356 PAY 321 

    0x40d41120,// 357 PAY 322 

    0x95b186ba,// 358 PAY 323 

    0x7a8de434,// 359 PAY 324 

    0xd2ac05de,// 360 PAY 325 

    0x5efebf5d,// 361 PAY 326 

    0x29e49c37,// 362 PAY 327 

    0xf80db2be,// 363 PAY 328 

    0xb0f02b15,// 364 PAY 329 

    0x0e483d02,// 365 PAY 330 

    0x2be58b6d,// 366 PAY 331 

    0xa05165ad,// 367 PAY 332 

    0xdac5bd2f,// 368 PAY 333 

    0x3fc95823,// 369 PAY 334 

    0x4240fbf0,// 370 PAY 335 

    0x75428b2a,// 371 PAY 336 

    0xd535f1e3,// 372 PAY 337 

    0x7216c36f,// 373 PAY 338 

    0xf7f8b7b1,// 374 PAY 339 

    0x7df709b3,// 375 PAY 340 

    0x20115765,// 376 PAY 341 

    0xcfcb6f49,// 377 PAY 342 

    0x5cf1216e,// 378 PAY 343 

    0xd2758d44,// 379 PAY 344 

    0xe51ed5d1,// 380 PAY 345 

    0x6cd98e4d,// 381 PAY 346 

    0x501dd550,// 382 PAY 347 

    0x827ae6b9,// 383 PAY 348 

    0xefaa9668,// 384 PAY 349 

    0x5ecafdf3,// 385 PAY 350 

    0xa3f44401,// 386 PAY 351 

    0x056e5e45,// 387 PAY 352 

    0x4022a876,// 388 PAY 353 

    0xe540b7ed,// 389 PAY 354 

    0x19ee1847,// 390 PAY 355 

    0x035825ca,// 391 PAY 356 

    0xeb990693,// 392 PAY 357 

    0x4ef4b8fa,// 393 PAY 358 

    0xdebb2777,// 394 PAY 359 

    0x9292866d,// 395 PAY 360 

    0x98000000,// 396 PAY 361 

/// STA is 1 words. 

/// STA num_pkts       : 168 

/// STA pkt_idx        : 182 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x3e 

    0x02d93ea8 // 397 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt14_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80902874,// 4 SCX   2 

    0x000023c2,// 5 SCX   3 

    0xe004c7fb,// 6 SCX   4 

    0x08e69a98,// 7 SCX   5 

    0x425e03a1,// 8 SCX   6 

    0x710df3fa,// 9 SCX   7 

    0x300b7870,// 10 SCX   8 

    0x88f5abc2,// 11 SCX   9 

    0xff541346,// 12 SCX  10 

    0x574d4b11,// 13 SCX  11 

    0xeec12d9f,// 14 SCX  12 

    0x95f65d53,// 15 SCX  13 

    0x9664a2e8,// 16 SCX  14 

    0x8f9926f2,// 17 SCX  15 

    0xba6f4283,// 18 SCX  16 

    0x31d12fe2,// 19 SCX  17 

    0x124ebcd2,// 20 SCX  18 

    0x9e72b65e,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1223 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 508 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 508 

/// BFD lencrypto      : 104 

/// BFD ofstcrypto     : 84 

/// BFD (ofst+len)cry  : 188 

/// BFD ofstiv         : 32 

/// BFD ofsticv        : 716 

    0x000001fc,// 22 BFD   1 

    0x00540068,// 23 BFD   2 

    0x02cc0020,// 24 BFD   3 

/// MFM is 14 words. 

/// MFM vldnibs        : 6a 

    0x6a00861f,// 25 MFM   1 

    0xa6557f2a,// 26 MFM   2 

    0x30c2bf6e,// 27 MFM   3 

    0x029419de,// 28 MFM   4 

    0xd98b843f,// 29 MFM   5 

    0x05374238,// 30 MFM   6 

    0x49e113b6,// 31 MFM   7 

    0xd38258df,// 32 MFM   8 

    0x931e85b5,// 33 MFM   9 

    0x58f42cc4,// 34 MFM  10 

    0x76941123,// 35 MFM  11 

    0x5ddbadc8,// 36 MFM  12 

    0x4e0e7bbb,// 37 MFM  13 

    0xd2c92900,// 38 MFM  14 

/// BDA is 307 words. 

/// BDA size     is 1223 (0x4c7) 

/// BDA id       is 0x241b 

    0x04c7241b,// 39 BDA   1 

/// PAY Generic Data size   : 1223 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x81c03aa5,// 40 PAY   1 

    0x09da4a78,// 41 PAY   2 

    0xb3427d9c,// 42 PAY   3 

    0xc6e5a3c2,// 43 PAY   4 

    0x743061ac,// 44 PAY   5 

    0x4ea492cb,// 45 PAY   6 

    0x76515bf1,// 46 PAY   7 

    0x2b8022d2,// 47 PAY   8 

    0x257034b2,// 48 PAY   9 

    0x422ac679,// 49 PAY  10 

    0x73c319ab,// 50 PAY  11 

    0x06b056c5,// 51 PAY  12 

    0xbfd1f217,// 52 PAY  13 

    0x4b83ca9b,// 53 PAY  14 

    0x3f8d53ae,// 54 PAY  15 

    0x881a5d53,// 55 PAY  16 

    0xd10c08ce,// 56 PAY  17 

    0x71ef1af1,// 57 PAY  18 

    0x07f9dbe8,// 58 PAY  19 

    0xaf6224de,// 59 PAY  20 

    0xdc23a71f,// 60 PAY  21 

    0x1ae067c5,// 61 PAY  22 

    0xa66cb0b9,// 62 PAY  23 

    0xcfdd10cc,// 63 PAY  24 

    0x5ea8399c,// 64 PAY  25 

    0xc577c50b,// 65 PAY  26 

    0x807ba7b1,// 66 PAY  27 

    0x2f4c725c,// 67 PAY  28 

    0xd852c9d5,// 68 PAY  29 

    0x7c98ed45,// 69 PAY  30 

    0x6c55c36f,// 70 PAY  31 

    0x3309a79e,// 71 PAY  32 

    0x01fbf30f,// 72 PAY  33 

    0xe48e564d,// 73 PAY  34 

    0x7afecf1b,// 74 PAY  35 

    0xc8920722,// 75 PAY  36 

    0x4b728136,// 76 PAY  37 

    0xedd58608,// 77 PAY  38 

    0xb130ff6b,// 78 PAY  39 

    0xc7bd75d6,// 79 PAY  40 

    0x8dc5fc38,// 80 PAY  41 

    0x41574534,// 81 PAY  42 

    0x8987586e,// 82 PAY  43 

    0xd6b26ed7,// 83 PAY  44 

    0xc8655b12,// 84 PAY  45 

    0x621c1c42,// 85 PAY  46 

    0x158f31ef,// 86 PAY  47 

    0xfbbf9fc6,// 87 PAY  48 

    0xd0808cf3,// 88 PAY  49 

    0xaa555001,// 89 PAY  50 

    0x5a026e27,// 90 PAY  51 

    0x9afd7829,// 91 PAY  52 

    0x64600b20,// 92 PAY  53 

    0x6262029f,// 93 PAY  54 

    0x3c0606e1,// 94 PAY  55 

    0x29eb2d20,// 95 PAY  56 

    0x7292e06a,// 96 PAY  57 

    0x89ce8e3b,// 97 PAY  58 

    0x857df85e,// 98 PAY  59 

    0x0d58669a,// 99 PAY  60 

    0x7df2bfce,// 100 PAY  61 

    0xf3faa90d,// 101 PAY  62 

    0x8b953730,// 102 PAY  63 

    0xe1da9a0b,// 103 PAY  64 

    0xf461a904,// 104 PAY  65 

    0x99e11925,// 105 PAY  66 

    0x9fb9cbb4,// 106 PAY  67 

    0xbef5be75,// 107 PAY  68 

    0x5f5495d3,// 108 PAY  69 

    0xc9e7b6e5,// 109 PAY  70 

    0xf17410ff,// 110 PAY  71 

    0x2a665850,// 111 PAY  72 

    0x868a2201,// 112 PAY  73 

    0xfda41e4e,// 113 PAY  74 

    0x08de0e03,// 114 PAY  75 

    0x6c1baf41,// 115 PAY  76 

    0xdd44d23c,// 116 PAY  77 

    0x67a8c950,// 117 PAY  78 

    0x2521c791,// 118 PAY  79 

    0x68bf1c3c,// 119 PAY  80 

    0xf2614413,// 120 PAY  81 

    0x61b4927c,// 121 PAY  82 

    0x80dc3580,// 122 PAY  83 

    0x110f8683,// 123 PAY  84 

    0x31da77ee,// 124 PAY  85 

    0x9ab219e3,// 125 PAY  86 

    0xd98ea79b,// 126 PAY  87 

    0x13e366d5,// 127 PAY  88 

    0xc5963aaf,// 128 PAY  89 

    0xfcb31b4f,// 129 PAY  90 

    0x7274b7a0,// 130 PAY  91 

    0xdbfe69f3,// 131 PAY  92 

    0x0d0793ce,// 132 PAY  93 

    0x4a92f5de,// 133 PAY  94 

    0xf4ba4827,// 134 PAY  95 

    0x109ead96,// 135 PAY  96 

    0x1191e4c7,// 136 PAY  97 

    0x1d0b70a1,// 137 PAY  98 

    0xef4206dc,// 138 PAY  99 

    0x5fba0ee1,// 139 PAY 100 

    0xecb8a7ae,// 140 PAY 101 

    0x1663b533,// 141 PAY 102 

    0x959d47a0,// 142 PAY 103 

    0x020fce43,// 143 PAY 104 

    0xccfad243,// 144 PAY 105 

    0x3472f9ae,// 145 PAY 106 

    0x1193bcf4,// 146 PAY 107 

    0x5d6525f0,// 147 PAY 108 

    0x254d3a1b,// 148 PAY 109 

    0x1bdb8fbb,// 149 PAY 110 

    0x7dcde2cb,// 150 PAY 111 

    0x8b1c72ca,// 151 PAY 112 

    0xda00e207,// 152 PAY 113 

    0xef5cf690,// 153 PAY 114 

    0xf819b5d4,// 154 PAY 115 

    0x217f8f27,// 155 PAY 116 

    0x49d2a6ff,// 156 PAY 117 

    0xc83b2f92,// 157 PAY 118 

    0x35bcb58f,// 158 PAY 119 

    0x5e117217,// 159 PAY 120 

    0xf52bb811,// 160 PAY 121 

    0xed76b3f4,// 161 PAY 122 

    0xf7138d47,// 162 PAY 123 

    0xec368332,// 163 PAY 124 

    0xcfb6cd39,// 164 PAY 125 

    0x1cf2d476,// 165 PAY 126 

    0x971a681e,// 166 PAY 127 

    0x209e7e7c,// 167 PAY 128 

    0xe54816fb,// 168 PAY 129 

    0x2b7c8ca3,// 169 PAY 130 

    0x75515b15,// 170 PAY 131 

    0xd6788929,// 171 PAY 132 

    0xc7c3c436,// 172 PAY 133 

    0xf3241fb1,// 173 PAY 134 

    0x95a69561,// 174 PAY 135 

    0xe13b129a,// 175 PAY 136 

    0x5d3d4189,// 176 PAY 137 

    0x7ec298d3,// 177 PAY 138 

    0x2395f052,// 178 PAY 139 

    0x1c9f1ba5,// 179 PAY 140 

    0x4330091c,// 180 PAY 141 

    0xb417f212,// 181 PAY 142 

    0x94cfa75e,// 182 PAY 143 

    0xfe931f1d,// 183 PAY 144 

    0xb6a9844e,// 184 PAY 145 

    0x346c6f11,// 185 PAY 146 

    0xc2d50b8f,// 186 PAY 147 

    0x97b1acaa,// 187 PAY 148 

    0x12a837d2,// 188 PAY 149 

    0x2d5148fa,// 189 PAY 150 

    0x9b7c69d3,// 190 PAY 151 

    0x04c38b92,// 191 PAY 152 

    0x7e2674ac,// 192 PAY 153 

    0x7decebd0,// 193 PAY 154 

    0x12b813ff,// 194 PAY 155 

    0xe71aacfd,// 195 PAY 156 

    0xdace2528,// 196 PAY 157 

    0xfe4ec648,// 197 PAY 158 

    0x28efbd93,// 198 PAY 159 

    0x894d4715,// 199 PAY 160 

    0x80670c8a,// 200 PAY 161 

    0x3d359da1,// 201 PAY 162 

    0x505c2303,// 202 PAY 163 

    0xe8f15ec1,// 203 PAY 164 

    0xf63616db,// 204 PAY 165 

    0x887ca7c6,// 205 PAY 166 

    0xea0b99e8,// 206 PAY 167 

    0x4dfc9e10,// 207 PAY 168 

    0xdaa06570,// 208 PAY 169 

    0xf990b1f9,// 209 PAY 170 

    0x7f28a01f,// 210 PAY 171 

    0x9d1642a5,// 211 PAY 172 

    0x742bdd03,// 212 PAY 173 

    0x139d793d,// 213 PAY 174 

    0x89f747c9,// 214 PAY 175 

    0x0fcf5dc7,// 215 PAY 176 

    0x367d465f,// 216 PAY 177 

    0x17f0044b,// 217 PAY 178 

    0xc444f68c,// 218 PAY 179 

    0x86232840,// 219 PAY 180 

    0xe9d38b1b,// 220 PAY 181 

    0xaff53d6c,// 221 PAY 182 

    0x1fcbad8f,// 222 PAY 183 

    0x5e8ff0a6,// 223 PAY 184 

    0x3567ba28,// 224 PAY 185 

    0x8c6888e4,// 225 PAY 186 

    0x4a6ad06e,// 226 PAY 187 

    0xed2c566d,// 227 PAY 188 

    0x76834dec,// 228 PAY 189 

    0x8985f9c9,// 229 PAY 190 

    0xafe5ba33,// 230 PAY 191 

    0x4357b0a0,// 231 PAY 192 

    0xf709da7b,// 232 PAY 193 

    0x6898e65c,// 233 PAY 194 

    0xcdb4af06,// 234 PAY 195 

    0x57fcda92,// 235 PAY 196 

    0xebf21972,// 236 PAY 197 

    0x5407cb06,// 237 PAY 198 

    0x12df2c8b,// 238 PAY 199 

    0xa4fec5b5,// 239 PAY 200 

    0x10d2c3a7,// 240 PAY 201 

    0x9d5644ef,// 241 PAY 202 

    0x94db09bb,// 242 PAY 203 

    0x792b7f0b,// 243 PAY 204 

    0x58ec9e9b,// 244 PAY 205 

    0x07e58ae5,// 245 PAY 206 

    0xdeadfd22,// 246 PAY 207 

    0xdce73b86,// 247 PAY 208 

    0xf38b405f,// 248 PAY 209 

    0x696a32ee,// 249 PAY 210 

    0x9da76370,// 250 PAY 211 

    0x4d65bcbb,// 251 PAY 212 

    0xe77cde02,// 252 PAY 213 

    0xa7555f8f,// 253 PAY 214 

    0xf9fae6c4,// 254 PAY 215 

    0x3abad1ad,// 255 PAY 216 

    0xa1a30665,// 256 PAY 217 

    0x5e3c1767,// 257 PAY 218 

    0xc3cbe564,// 258 PAY 219 

    0x3cb44328,// 259 PAY 220 

    0x36bf0fde,// 260 PAY 221 

    0x2dd6b67e,// 261 PAY 222 

    0x81a38aef,// 262 PAY 223 

    0x231bc893,// 263 PAY 224 

    0x27cdba01,// 264 PAY 225 

    0x588a6e22,// 265 PAY 226 

    0x4f91c11c,// 266 PAY 227 

    0xa30d2fc4,// 267 PAY 228 

    0x65d55aba,// 268 PAY 229 

    0xe0f23984,// 269 PAY 230 

    0x9d138bf6,// 270 PAY 231 

    0xc9f872b3,// 271 PAY 232 

    0xebfaf92b,// 272 PAY 233 

    0x6c61e483,// 273 PAY 234 

    0xfb21b7aa,// 274 PAY 235 

    0xd2f5f7ce,// 275 PAY 236 

    0x0cdab480,// 276 PAY 237 

    0x14880a40,// 277 PAY 238 

    0x162e5f89,// 278 PAY 239 

    0x798ecfb2,// 279 PAY 240 

    0xcb18754f,// 280 PAY 241 

    0xf7985220,// 281 PAY 242 

    0x89f769e9,// 282 PAY 243 

    0xc0623efb,// 283 PAY 244 

    0xbde03d41,// 284 PAY 245 

    0xcf3a3dc7,// 285 PAY 246 

    0x14f9569f,// 286 PAY 247 

    0xa27b4db3,// 287 PAY 248 

    0x1ead972a,// 288 PAY 249 

    0xf9d1afc5,// 289 PAY 250 

    0xd8f8aed7,// 290 PAY 251 

    0x1828cacd,// 291 PAY 252 

    0x53329e7d,// 292 PAY 253 

    0xfe2f5354,// 293 PAY 254 

    0x420cf69e,// 294 PAY 255 

    0xc552004c,// 295 PAY 256 

    0xf47ced60,// 296 PAY 257 

    0xfc9e4d6f,// 297 PAY 258 

    0x1c90d564,// 298 PAY 259 

    0xa01c1297,// 299 PAY 260 

    0xc7ff3af8,// 300 PAY 261 

    0xbac3ecf2,// 301 PAY 262 

    0xbb37d29b,// 302 PAY 263 

    0xd3ae7bf8,// 303 PAY 264 

    0x2bb1c68a,// 304 PAY 265 

    0xcb2ab7f9,// 305 PAY 266 

    0xfb2a02c1,// 306 PAY 267 

    0xdbc3c1a1,// 307 PAY 268 

    0x7aaa02cf,// 308 PAY 269 

    0x69c0d0cb,// 309 PAY 270 

    0xf65108a3,// 310 PAY 271 

    0x95164fa5,// 311 PAY 272 

    0xef399a05,// 312 PAY 273 

    0x48fcd8cc,// 313 PAY 274 

    0xb66e8f94,// 314 PAY 275 

    0x30434aa5,// 315 PAY 276 

    0x5e9e4adc,// 316 PAY 277 

    0x92feb4c0,// 317 PAY 278 

    0x1a9004a6,// 318 PAY 279 

    0xf9f1d325,// 319 PAY 280 

    0x17a22db9,// 320 PAY 281 

    0x0a7386a2,// 321 PAY 282 

    0xc2540209,// 322 PAY 283 

    0xf6ca307a,// 323 PAY 284 

    0x0e90a0e6,// 324 PAY 285 

    0x027b61aa,// 325 PAY 286 

    0x98f6c962,// 326 PAY 287 

    0x65226f7a,// 327 PAY 288 

    0x3bb39a0c,// 328 PAY 289 

    0x5b784039,// 329 PAY 290 

    0x2ce534e5,// 330 PAY 291 

    0x46ad479c,// 331 PAY 292 

    0x54755434,// 332 PAY 293 

    0x14255b50,// 333 PAY 294 

    0xeb6eef52,// 334 PAY 295 

    0x350008ab,// 335 PAY 296 

    0x4d18142c,// 336 PAY 297 

    0xd6728619,// 337 PAY 298 

    0x8e619ee4,// 338 PAY 299 

    0x47a0b7d7,// 339 PAY 300 

    0x0b8573b2,// 340 PAY 301 

    0xe6ae1253,// 341 PAY 302 

    0x11d38b28,// 342 PAY 303 

    0x870e03f6,// 343 PAY 304 

    0x0529f0e3,// 344 PAY 305 

    0xb7b13e00,// 345 PAY 306 

/// STA is 1 words. 

/// STA num_pkts       : 132 

/// STA pkt_idx        : 124 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x26 

    0x01f12684 // 346 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt15_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x808228cc,// 4 SCX   2 

    0x00003100,// 5 SCX   3 

    0x862562e5,// 6 SCX   4 

    0x15ae2cc8,// 7 SCX   5 

    0x0e4b2bf0,// 8 SCX   6 

    0x7281fb5b,// 9 SCX   7 

    0x3bc20a0b,// 10 SCX   8 

    0x5bb02459,// 11 SCX   9 

    0xb2f9de07,// 12 SCX  10 

    0x33024147,// 13 SCX  11 

    0x274cf14c,// 14 SCX  12 

    0x58680721,// 15 SCX  13 

    0xc0267ff2,// 16 SCX  14 

    0xde37de17,// 17 SCX  15 

    0x526d7767,// 18 SCX  16 

    0x9785df81,// 19 SCX  17 

    0x6625f84a,// 20 SCX  18 

    0xf2456d58,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1662 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 195 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 195 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 148 

/// BFD (ofst+len)cry  : 180 

/// BFD ofstiv         : 80 

/// BFD ofsticv        : 1624 

    0x000000c3,// 22 BFD   1 

    0x00940020,// 23 BFD   2 

    0x06580050,// 24 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 1 

    0x01005000,// 25 MFM   1 

/// BDA is 417 words. 

/// BDA size     is 1662 (0x67e) 

/// BDA id       is 0xa24 

    0x067e0a24,// 26 BDA   1 

/// PAY Generic Data size   : 1662 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x3c66e4be,// 27 PAY   1 

    0xe10b142e,// 28 PAY   2 

    0x46d83752,// 29 PAY   3 

    0x9c4f050d,// 30 PAY   4 

    0xd6e31735,// 31 PAY   5 

    0xe3e210eb,// 32 PAY   6 

    0x5f63eb5e,// 33 PAY   7 

    0x4832241a,// 34 PAY   8 

    0x9391fb26,// 35 PAY   9 

    0x9ab6f13b,// 36 PAY  10 

    0x3ca4fc48,// 37 PAY  11 

    0x3e17bc71,// 38 PAY  12 

    0xb6aae146,// 39 PAY  13 

    0x0a7eaa1d,// 40 PAY  14 

    0x979273ec,// 41 PAY  15 

    0x58ac19a8,// 42 PAY  16 

    0x9c0e6b4e,// 43 PAY  17 

    0x1e5039d3,// 44 PAY  18 

    0x9973e208,// 45 PAY  19 

    0xf3129683,// 46 PAY  20 

    0x188c6f88,// 47 PAY  21 

    0xded0d901,// 48 PAY  22 

    0x8ee9e5bb,// 49 PAY  23 

    0xd3d0840a,// 50 PAY  24 

    0xaf9c4b00,// 51 PAY  25 

    0xe62ea681,// 52 PAY  26 

    0xa5424d69,// 53 PAY  27 

    0xbd88e3e3,// 54 PAY  28 

    0x034e7a9b,// 55 PAY  29 

    0x06f517bb,// 56 PAY  30 

    0x2a0920a8,// 57 PAY  31 

    0xb5eb6b03,// 58 PAY  32 

    0x53b2b36b,// 59 PAY  33 

    0xe11c35cd,// 60 PAY  34 

    0x81ab9427,// 61 PAY  35 

    0x4cfbe5f1,// 62 PAY  36 

    0x4ef5bbbc,// 63 PAY  37 

    0x923b0b2b,// 64 PAY  38 

    0x42afe34a,// 65 PAY  39 

    0xd65647fa,// 66 PAY  40 

    0x47e96d07,// 67 PAY  41 

    0x1050e6eb,// 68 PAY  42 

    0x38652302,// 69 PAY  43 

    0x77de08e2,// 70 PAY  44 

    0xe53aa417,// 71 PAY  45 

    0x6d73538c,// 72 PAY  46 

    0x41671a2e,// 73 PAY  47 

    0xa4d7262c,// 74 PAY  48 

    0x299c361c,// 75 PAY  49 

    0xcf8ee44a,// 76 PAY  50 

    0xe1f0718b,// 77 PAY  51 

    0x4c0fbb15,// 78 PAY  52 

    0xb0ec5e28,// 79 PAY  53 

    0x91ee192f,// 80 PAY  54 

    0x4317fe4e,// 81 PAY  55 

    0x3af24aea,// 82 PAY  56 

    0xc0218034,// 83 PAY  57 

    0xb89e3498,// 84 PAY  58 

    0x0b59cb20,// 85 PAY  59 

    0xa47306c2,// 86 PAY  60 

    0xa34d8471,// 87 PAY  61 

    0x8985c317,// 88 PAY  62 

    0x9ade2522,// 89 PAY  63 

    0x73d90b7d,// 90 PAY  64 

    0x8562b706,// 91 PAY  65 

    0x891d935d,// 92 PAY  66 

    0xd90169ed,// 93 PAY  67 

    0xf3dc8f77,// 94 PAY  68 

    0xc00eb1df,// 95 PAY  69 

    0xd6167769,// 96 PAY  70 

    0x4a80f055,// 97 PAY  71 

    0x69f4a0aa,// 98 PAY  72 

    0x21dafb33,// 99 PAY  73 

    0xc0e86492,// 100 PAY  74 

    0x9e172f9a,// 101 PAY  75 

    0x7a860d77,// 102 PAY  76 

    0xba15523e,// 103 PAY  77 

    0x5ab63413,// 104 PAY  78 

    0x1e4ad7a0,// 105 PAY  79 

    0x676884d8,// 106 PAY  80 

    0x42a661a6,// 107 PAY  81 

    0xd424197f,// 108 PAY  82 

    0xe65e67a5,// 109 PAY  83 

    0xd2935102,// 110 PAY  84 

    0xfb872641,// 111 PAY  85 

    0xc8c23594,// 112 PAY  86 

    0x851daa1f,// 113 PAY  87 

    0x75808b8d,// 114 PAY  88 

    0x6a203307,// 115 PAY  89 

    0x09e27ec6,// 116 PAY  90 

    0x6444aec5,// 117 PAY  91 

    0xc08ceb94,// 118 PAY  92 

    0xe2120c3d,// 119 PAY  93 

    0x4c5c1b62,// 120 PAY  94 

    0xa0976123,// 121 PAY  95 

    0x1e36d279,// 122 PAY  96 

    0x2b132926,// 123 PAY  97 

    0x9a5a958e,// 124 PAY  98 

    0xc994c466,// 125 PAY  99 

    0x79909822,// 126 PAY 100 

    0x6a60e9ed,// 127 PAY 101 

    0x4c491282,// 128 PAY 102 

    0xdb3f9e99,// 129 PAY 103 

    0x54edc82c,// 130 PAY 104 

    0x4ebaac16,// 131 PAY 105 

    0xcc85d225,// 132 PAY 106 

    0xd49ba18d,// 133 PAY 107 

    0xd500a44a,// 134 PAY 108 

    0x1fc7b762,// 135 PAY 109 

    0x2fe46644,// 136 PAY 110 

    0x188b817d,// 137 PAY 111 

    0xc966db06,// 138 PAY 112 

    0xc600e5d2,// 139 PAY 113 

    0xa32dc3e9,// 140 PAY 114 

    0xae638ef5,// 141 PAY 115 

    0x4ac4e7f9,// 142 PAY 116 

    0x74a67a46,// 143 PAY 117 

    0x44664bd4,// 144 PAY 118 

    0x160a328d,// 145 PAY 119 

    0xe852d851,// 146 PAY 120 

    0x21ca2df5,// 147 PAY 121 

    0x073992ad,// 148 PAY 122 

    0xabf45422,// 149 PAY 123 

    0x60272d7a,// 150 PAY 124 

    0x38c680dc,// 151 PAY 125 

    0xf50bbb87,// 152 PAY 126 

    0x14de4e2d,// 153 PAY 127 

    0xa7545acf,// 154 PAY 128 

    0x03b5678a,// 155 PAY 129 

    0x06490826,// 156 PAY 130 

    0x82727016,// 157 PAY 131 

    0x4c02981a,// 158 PAY 132 

    0x5e5b594f,// 159 PAY 133 

    0x66f5d7ea,// 160 PAY 134 

    0x5165a38f,// 161 PAY 135 

    0x4f974266,// 162 PAY 136 

    0x1336428f,// 163 PAY 137 

    0x2cd64f23,// 164 PAY 138 

    0xb7dd3008,// 165 PAY 139 

    0x4e7add85,// 166 PAY 140 

    0xc86afb6e,// 167 PAY 141 

    0x7ec8bb52,// 168 PAY 142 

    0xc2e43ef0,// 169 PAY 143 

    0xc338d83f,// 170 PAY 144 

    0x03522299,// 171 PAY 145 

    0x96c470b5,// 172 PAY 146 

    0x71a4dcd2,// 173 PAY 147 

    0xcf0ed51a,// 174 PAY 148 

    0x5901bbf8,// 175 PAY 149 

    0xbc507f0c,// 176 PAY 150 

    0xd6bb5e85,// 177 PAY 151 

    0xa35b032d,// 178 PAY 152 

    0xd1fd2599,// 179 PAY 153 

    0x0961a0b4,// 180 PAY 154 

    0x8781a3e8,// 181 PAY 155 

    0x885ef828,// 182 PAY 156 

    0x9dec9650,// 183 PAY 157 

    0xb538e7a7,// 184 PAY 158 

    0x2fd0fadb,// 185 PAY 159 

    0x152ebe69,// 186 PAY 160 

    0x4d871d18,// 187 PAY 161 

    0x8dd99a99,// 188 PAY 162 

    0x14e1117e,// 189 PAY 163 

    0xf496233b,// 190 PAY 164 

    0x9c3cae31,// 191 PAY 165 

    0x7eef3dc9,// 192 PAY 166 

    0xc92ba0d8,// 193 PAY 167 

    0x3c48e908,// 194 PAY 168 

    0xc7c34d88,// 195 PAY 169 

    0x425eeba3,// 196 PAY 170 

    0xa0772a4e,// 197 PAY 171 

    0x54925fbf,// 198 PAY 172 

    0x28ba5444,// 199 PAY 173 

    0x822409e1,// 200 PAY 174 

    0x74554429,// 201 PAY 175 

    0x91891957,// 202 PAY 176 

    0x5ca7a8bc,// 203 PAY 177 

    0x1dd443f8,// 204 PAY 178 

    0x96c51073,// 205 PAY 179 

    0xee4c78bb,// 206 PAY 180 

    0x2f3cbebc,// 207 PAY 181 

    0x2e5acc04,// 208 PAY 182 

    0x6ae178e6,// 209 PAY 183 

    0x3a3df664,// 210 PAY 184 

    0xe13d0c59,// 211 PAY 185 

    0xd8b2018e,// 212 PAY 186 

    0x0cfde799,// 213 PAY 187 

    0xdbbe7d21,// 214 PAY 188 

    0x7a203619,// 215 PAY 189 

    0xda86d627,// 216 PAY 190 

    0xeb9efd81,// 217 PAY 191 

    0x013a66a1,// 218 PAY 192 

    0xe46499ef,// 219 PAY 193 

    0xac222d56,// 220 PAY 194 

    0x9df40cbc,// 221 PAY 195 

    0xe186b2b8,// 222 PAY 196 

    0x63c0e84a,// 223 PAY 197 

    0x5912af9d,// 224 PAY 198 

    0x41ffc26e,// 225 PAY 199 

    0x1a0d4266,// 226 PAY 200 

    0x58a17a2b,// 227 PAY 201 

    0xe684d98c,// 228 PAY 202 

    0x9aa7b72b,// 229 PAY 203 

    0x5025fa47,// 230 PAY 204 

    0x81b09dc6,// 231 PAY 205 

    0x1ad82d7f,// 232 PAY 206 

    0xc9fce28f,// 233 PAY 207 

    0xe15ef6f9,// 234 PAY 208 

    0xa70e5f1d,// 235 PAY 209 

    0xc8e56611,// 236 PAY 210 

    0x6c35ba86,// 237 PAY 211 

    0x4d426555,// 238 PAY 212 

    0x3dee1173,// 239 PAY 213 

    0xd07e44b9,// 240 PAY 214 

    0xdae3672f,// 241 PAY 215 

    0x72a02c39,// 242 PAY 216 

    0x9fd95b4e,// 243 PAY 217 

    0xbd203c75,// 244 PAY 218 

    0x4b79e5f3,// 245 PAY 219 

    0xd27e93a9,// 246 PAY 220 

    0x81832c4b,// 247 PAY 221 

    0xe2ba0e4f,// 248 PAY 222 

    0x380f6eaa,// 249 PAY 223 

    0xcadfdec5,// 250 PAY 224 

    0x7d6aecfd,// 251 PAY 225 

    0x2f7e4a47,// 252 PAY 226 

    0x12d823f9,// 253 PAY 227 

    0x880b6f3c,// 254 PAY 228 

    0x0313aaab,// 255 PAY 229 

    0xe1b49c9a,// 256 PAY 230 

    0x67659b6e,// 257 PAY 231 

    0xa08e082c,// 258 PAY 232 

    0x713cb6ca,// 259 PAY 233 

    0x2859adc4,// 260 PAY 234 

    0x1232832c,// 261 PAY 235 

    0x888464d3,// 262 PAY 236 

    0xdadcb1f6,// 263 PAY 237 

    0xc0e4fc13,// 264 PAY 238 

    0x0bb385dd,// 265 PAY 239 

    0x1cf77281,// 266 PAY 240 

    0x1996b53c,// 267 PAY 241 

    0x8f85f32c,// 268 PAY 242 

    0x302802b5,// 269 PAY 243 

    0xbb419e9f,// 270 PAY 244 

    0x249eeb07,// 271 PAY 245 

    0x64ba7f22,// 272 PAY 246 

    0xb5efb080,// 273 PAY 247 

    0x114304a7,// 274 PAY 248 

    0xf6dcafeb,// 275 PAY 249 

    0x6f983696,// 276 PAY 250 

    0xe3b1cb50,// 277 PAY 251 

    0xe85f56f0,// 278 PAY 252 

    0x6b2a226b,// 279 PAY 253 

    0x8691a5c7,// 280 PAY 254 

    0xb7314df5,// 281 PAY 255 

    0xb22045ac,// 282 PAY 256 

    0x14082c1a,// 283 PAY 257 

    0x5458e446,// 284 PAY 258 

    0xcda752c7,// 285 PAY 259 

    0x62b03c64,// 286 PAY 260 

    0x2779cba7,// 287 PAY 261 

    0x94403a70,// 288 PAY 262 

    0x4336c8b6,// 289 PAY 263 

    0xc901d9c2,// 290 PAY 264 

    0x1c3c0857,// 291 PAY 265 

    0xec42c629,// 292 PAY 266 

    0xc9b1494c,// 293 PAY 267 

    0x58d427a3,// 294 PAY 268 

    0xb74359ce,// 295 PAY 269 

    0xf63d8dea,// 296 PAY 270 

    0xcbf75dfa,// 297 PAY 271 

    0xd799c2df,// 298 PAY 272 

    0xb7dee07c,// 299 PAY 273 

    0x65c7c80c,// 300 PAY 274 

    0xd6e713ae,// 301 PAY 275 

    0x3ad528c2,// 302 PAY 276 

    0xc728eee0,// 303 PAY 277 

    0x43286501,// 304 PAY 278 

    0xc1cec45c,// 305 PAY 279 

    0xb21f3758,// 306 PAY 280 

    0x7be78208,// 307 PAY 281 

    0xd06f0a8e,// 308 PAY 282 

    0xab3f4701,// 309 PAY 283 

    0xe40761cd,// 310 PAY 284 

    0x5faf9cb1,// 311 PAY 285 

    0x4d835cc7,// 312 PAY 286 

    0x243f471c,// 313 PAY 287 

    0x2a3719d8,// 314 PAY 288 

    0x2f903d5f,// 315 PAY 289 

    0x1b927f0b,// 316 PAY 290 

    0x19522491,// 317 PAY 291 

    0x7db843d3,// 318 PAY 292 

    0xe209286a,// 319 PAY 293 

    0x23431f95,// 320 PAY 294 

    0xf9d8a4e0,// 321 PAY 295 

    0x8fe36d9d,// 322 PAY 296 

    0xf7446f72,// 323 PAY 297 

    0xc9fe2731,// 324 PAY 298 

    0xd023ae23,// 325 PAY 299 

    0xb2a11d92,// 326 PAY 300 

    0x846f0e84,// 327 PAY 301 

    0xf3e6e47c,// 328 PAY 302 

    0xb13b6f5e,// 329 PAY 303 

    0xf6344083,// 330 PAY 304 

    0x6755ca08,// 331 PAY 305 

    0x10b2312f,// 332 PAY 306 

    0x2e6fa8ae,// 333 PAY 307 

    0xd427529a,// 334 PAY 308 

    0xf83e0f0e,// 335 PAY 309 

    0x69d29a24,// 336 PAY 310 

    0x655cbdd7,// 337 PAY 311 

    0x3095ee69,// 338 PAY 312 

    0x48a392a7,// 339 PAY 313 

    0xcabaac65,// 340 PAY 314 

    0x64c343b8,// 341 PAY 315 

    0xfacf2976,// 342 PAY 316 

    0x0d4ee041,// 343 PAY 317 

    0xe59ffbe1,// 344 PAY 318 

    0x8d750442,// 345 PAY 319 

    0xe7c65a76,// 346 PAY 320 

    0xec71bcc3,// 347 PAY 321 

    0x6ebef965,// 348 PAY 322 

    0xcaf6d8f5,// 349 PAY 323 

    0xc3625f25,// 350 PAY 324 

    0x15c8c488,// 351 PAY 325 

    0xe90b662b,// 352 PAY 326 

    0x8ab4dfca,// 353 PAY 327 

    0x3cec9618,// 354 PAY 328 

    0x3f6f0af7,// 355 PAY 329 

    0x8fec12be,// 356 PAY 330 

    0xccc8bb0b,// 357 PAY 331 

    0x404ce64d,// 358 PAY 332 

    0x2b037e12,// 359 PAY 333 

    0x254ab6f6,// 360 PAY 334 

    0x46ea25e6,// 361 PAY 335 

    0xad64eb55,// 362 PAY 336 

    0x4a74e9fb,// 363 PAY 337 

    0x19216ce3,// 364 PAY 338 

    0x2a59280c,// 365 PAY 339 

    0x87a4d5b5,// 366 PAY 340 

    0x0c8602db,// 367 PAY 341 

    0x43f7a5b9,// 368 PAY 342 

    0xb1726816,// 369 PAY 343 

    0x4b8a5020,// 370 PAY 344 

    0x3ff75de2,// 371 PAY 345 

    0xd8c83726,// 372 PAY 346 

    0x49dda4c2,// 373 PAY 347 

    0x83e27fcf,// 374 PAY 348 

    0x2800dd1a,// 375 PAY 349 

    0x92ddf78b,// 376 PAY 350 

    0x0a944ca4,// 377 PAY 351 

    0x583db4ce,// 378 PAY 352 

    0xf61331b7,// 379 PAY 353 

    0x86fe966e,// 380 PAY 354 

    0x9cfc09a0,// 381 PAY 355 

    0xb05c4aa8,// 382 PAY 356 

    0x3d6ef679,// 383 PAY 357 

    0xf0ff747e,// 384 PAY 358 

    0xd886d34b,// 385 PAY 359 

    0x099906ac,// 386 PAY 360 

    0x979a2504,// 387 PAY 361 

    0x018419ca,// 388 PAY 362 

    0x5f0313be,// 389 PAY 363 

    0x60fa39ed,// 390 PAY 364 

    0x468654f0,// 391 PAY 365 

    0xd41ccf1a,// 392 PAY 366 

    0x275fc545,// 393 PAY 367 

    0xdaac7016,// 394 PAY 368 

    0x6543429d,// 395 PAY 369 

    0x527ab93a,// 396 PAY 370 

    0x841f867a,// 397 PAY 371 

    0x6ace82e9,// 398 PAY 372 

    0x71c97049,// 399 PAY 373 

    0xc2308aa1,// 400 PAY 374 

    0xdef2a769,// 401 PAY 375 

    0xf768e050,// 402 PAY 376 

    0x89b08e13,// 403 PAY 377 

    0x07897d61,// 404 PAY 378 

    0xf0d90582,// 405 PAY 379 

    0x09a8959c,// 406 PAY 380 

    0x48e6dcbe,// 407 PAY 381 

    0xf4bd2a4b,// 408 PAY 382 

    0xec882cbf,// 409 PAY 383 

    0x330711d7,// 410 PAY 384 

    0x93a29386,// 411 PAY 385 

    0x34944943,// 412 PAY 386 

    0xd3eb792d,// 413 PAY 387 

    0xec64e611,// 414 PAY 388 

    0x8fd856e7,// 415 PAY 389 

    0x6c0f280e,// 416 PAY 390 

    0x62e04de8,// 417 PAY 391 

    0x938b8971,// 418 PAY 392 

    0x1d973874,// 419 PAY 393 

    0x3e678ff8,// 420 PAY 394 

    0xd102c596,// 421 PAY 395 

    0xc34a82ed,// 422 PAY 396 

    0xf518cbb3,// 423 PAY 397 

    0xd7d01058,// 424 PAY 398 

    0x83f958c8,// 425 PAY 399 

    0x378599b6,// 426 PAY 400 

    0x4b3dd9f0,// 427 PAY 401 

    0x37a5719c,// 428 PAY 402 

    0x68f29a39,// 429 PAY 403 

    0xbbf1a8ce,// 430 PAY 404 

    0x61cfe5a9,// 431 PAY 405 

    0xb40cfffa,// 432 PAY 406 

    0xbba63383,// 433 PAY 407 

    0x10ed55c2,// 434 PAY 408 

    0xc19be824,// 435 PAY 409 

    0x9b45cf8a,// 436 PAY 410 

    0xce98d0b3,// 437 PAY 411 

    0x35a39f85,// 438 PAY 412 

    0x8b11e32e,// 439 PAY 413 

    0x680f7a61,// 440 PAY 414 

    0xd9520a00,// 441 PAY 415 

    0xba510000,// 442 PAY 416 

/// STA is 1 words. 

/// STA num_pkts       : 92 

/// STA pkt_idx        : 100 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xde 

    0x0191de5c // 443 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt16_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x09 

/// ECH pdu_tag        : 0x00 

    0x00090000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x80802838,// 4 SCX   2 

    0x00003400,// 5 SCX   3 

    0x40c18299,// 6 SCX   4 

    0xacaba97e,// 7 SCX   5 

    0x7437eda9,// 8 SCX   6 

    0x43b9df14,// 9 SCX   7 

    0x491a0a9e,// 10 SCX   8 

    0xe4878813,// 11 SCX   9 

    0x12234475,// 12 SCX  10 

    0xc691e6de,// 13 SCX  11 

    0xa5a04fb5,// 14 SCX  12 

    0xef10eaee,// 15 SCX  13 

    0x24042f1b,// 16 SCX  14 

    0x0956ef0b,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1531 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1317 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1317 

/// BFD lencrypto      : 144 

/// BFD ofstcrypto     : 888 

/// BFD (ofst+len)cry  : 1032 

/// BFD ofstiv         : 824 

/// BFD ofsticv        : 1328 

    0x00000525,// 18 BFD   1 

    0x03780090,// 19 BFD   2 

    0x05300338,// 20 BFD   3 

/// MFM is 7 words. 

/// MFM vldnibs        : 30 

    0x300058f0,// 21 MFM   1 

    0xde884265,// 22 MFM   2 

    0x32ce86ce,// 23 MFM   3 

    0xa436ab46,// 24 MFM   4 

    0x8c1acd37,// 25 MFM   5 

    0x1673ddf8,// 26 MFM   6 

    0x375f0000,// 27 MFM   7 

/// BDA is 384 words. 

/// BDA size     is 1531 (0x5fb) 

/// BDA id       is 0x8a3d 

    0x05fb8a3d,// 28 BDA   1 

/// PAY Generic Data size   : 1531 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0xf617e73c,// 29 PAY   1 

    0x1ba74023,// 30 PAY   2 

    0x5b22a1eb,// 31 PAY   3 

    0x5183e98b,// 32 PAY   4 

    0x8f5686db,// 33 PAY   5 

    0x59bcc42a,// 34 PAY   6 

    0x688d52e0,// 35 PAY   7 

    0x3012599b,// 36 PAY   8 

    0xad64884a,// 37 PAY   9 

    0xca85f6a2,// 38 PAY  10 

    0x83734012,// 39 PAY  11 

    0x52931309,// 40 PAY  12 

    0x9cb8e00d,// 41 PAY  13 

    0xc8330a9d,// 42 PAY  14 

    0x41381a13,// 43 PAY  15 

    0x5831e3a2,// 44 PAY  16 

    0x2e867799,// 45 PAY  17 

    0x20b7a915,// 46 PAY  18 

    0x7d0466f5,// 47 PAY  19 

    0x0141c46b,// 48 PAY  20 

    0x52b3c909,// 49 PAY  21 

    0xc74048ac,// 50 PAY  22 

    0x4a2b06f7,// 51 PAY  23 

    0xfc596634,// 52 PAY  24 

    0x60bfd96d,// 53 PAY  25 

    0x973825c1,// 54 PAY  26 

    0xb2197a6b,// 55 PAY  27 

    0x4c07ed61,// 56 PAY  28 

    0x60ac7204,// 57 PAY  29 

    0x8e414ad5,// 58 PAY  30 

    0x89a29eea,// 59 PAY  31 

    0x4cfc098f,// 60 PAY  32 

    0x459e3445,// 61 PAY  33 

    0xaf5d9944,// 62 PAY  34 

    0x043de07f,// 63 PAY  35 

    0x07e13ea3,// 64 PAY  36 

    0x40de6cce,// 65 PAY  37 

    0x3816a8c0,// 66 PAY  38 

    0x5fdd5658,// 67 PAY  39 

    0x88814f31,// 68 PAY  40 

    0x603f5b0d,// 69 PAY  41 

    0xed6a97b8,// 70 PAY  42 

    0x793d2c4d,// 71 PAY  43 

    0x75672a82,// 72 PAY  44 

    0xba1c2c50,// 73 PAY  45 

    0xb503b137,// 74 PAY  46 

    0x66bb7486,// 75 PAY  47 

    0x521a8884,// 76 PAY  48 

    0xa0611a7d,// 77 PAY  49 

    0x5c7060f5,// 78 PAY  50 

    0xf9e05076,// 79 PAY  51 

    0xfa5c19ee,// 80 PAY  52 

    0x123fe2ff,// 81 PAY  53 

    0x59f34ff1,// 82 PAY  54 

    0x7e408c9e,// 83 PAY  55 

    0x2ea7d032,// 84 PAY  56 

    0x90e09599,// 85 PAY  57 

    0x04dc99d8,// 86 PAY  58 

    0x304f681c,// 87 PAY  59 

    0x9fcbe92e,// 88 PAY  60 

    0x8f4f0dd5,// 89 PAY  61 

    0x636ddf99,// 90 PAY  62 

    0xe13e59ff,// 91 PAY  63 

    0x730c666c,// 92 PAY  64 

    0xa776b700,// 93 PAY  65 

    0x94970b5b,// 94 PAY  66 

    0x0b12376b,// 95 PAY  67 

    0x0fd7ec10,// 96 PAY  68 

    0x56e8b793,// 97 PAY  69 

    0xb3cb9a2a,// 98 PAY  70 

    0x5827c04d,// 99 PAY  71 

    0xc603be4b,// 100 PAY  72 

    0xec55653b,// 101 PAY  73 

    0xf2a65bd0,// 102 PAY  74 

    0x218444fb,// 103 PAY  75 

    0x5f4b28b6,// 104 PAY  76 

    0x591da092,// 105 PAY  77 

    0x2ef26275,// 106 PAY  78 

    0xe9f0acca,// 107 PAY  79 

    0x6f0a1c4f,// 108 PAY  80 

    0x6ea0d3de,// 109 PAY  81 

    0xe66eda49,// 110 PAY  82 

    0xf9b79eeb,// 111 PAY  83 

    0xae19bf8f,// 112 PAY  84 

    0xcb7ec243,// 113 PAY  85 

    0x9d972237,// 114 PAY  86 

    0xe585145c,// 115 PAY  87 

    0x73e96d8b,// 116 PAY  88 

    0x98e4c85e,// 117 PAY  89 

    0x9502eb85,// 118 PAY  90 

    0x11c5e5b2,// 119 PAY  91 

    0xcda94419,// 120 PAY  92 

    0xeb87ccb4,// 121 PAY  93 

    0x735207a4,// 122 PAY  94 

    0x0142a3f1,// 123 PAY  95 

    0x12ae01bb,// 124 PAY  96 

    0x762c9a20,// 125 PAY  97 

    0xd6ed756f,// 126 PAY  98 

    0xe95012d7,// 127 PAY  99 

    0xc788ab2f,// 128 PAY 100 

    0x4cd4ca07,// 129 PAY 101 

    0x0796f52f,// 130 PAY 102 

    0xe8596103,// 131 PAY 103 

    0xd7b2ee6c,// 132 PAY 104 

    0xd567e5a0,// 133 PAY 105 

    0xb985406a,// 134 PAY 106 

    0xb4b7275d,// 135 PAY 107 

    0x883d76fe,// 136 PAY 108 

    0x2143e0b4,// 137 PAY 109 

    0xe71717e3,// 138 PAY 110 

    0x71992a77,// 139 PAY 111 

    0x58c8bff9,// 140 PAY 112 

    0x3437c4a5,// 141 PAY 113 

    0x7726812f,// 142 PAY 114 

    0x9ac84ce2,// 143 PAY 115 

    0x9a9c70bc,// 144 PAY 116 

    0x0e4488ba,// 145 PAY 117 

    0xa7df9304,// 146 PAY 118 

    0xa520a211,// 147 PAY 119 

    0x2a558082,// 148 PAY 120 

    0x36b1f8a5,// 149 PAY 121 

    0x861cbd7f,// 150 PAY 122 

    0xf7071ae6,// 151 PAY 123 

    0x78da234a,// 152 PAY 124 

    0xce202278,// 153 PAY 125 

    0x9b736fa9,// 154 PAY 126 

    0x2f8e3647,// 155 PAY 127 

    0x5fe2a3a7,// 156 PAY 128 

    0x9e9adbbf,// 157 PAY 129 

    0xc31626de,// 158 PAY 130 

    0x70a48080,// 159 PAY 131 

    0x5e2dca66,// 160 PAY 132 

    0x80934dc4,// 161 PAY 133 

    0x6d92eaec,// 162 PAY 134 

    0x8e351bcf,// 163 PAY 135 

    0xb34d68f9,// 164 PAY 136 

    0xaa95fca2,// 165 PAY 137 

    0xdf2e2e9d,// 166 PAY 138 

    0x192e92ca,// 167 PAY 139 

    0xe0d908dd,// 168 PAY 140 

    0xca430ac7,// 169 PAY 141 

    0x30d33324,// 170 PAY 142 

    0x44852822,// 171 PAY 143 

    0x62f4051d,// 172 PAY 144 

    0x723e0872,// 173 PAY 145 

    0xc4faf0d4,// 174 PAY 146 

    0x9f677260,// 175 PAY 147 

    0x62eca482,// 176 PAY 148 

    0xa847aef0,// 177 PAY 149 

    0x3ad882a5,// 178 PAY 150 

    0x9e5f5f9c,// 179 PAY 151 

    0x8b95f3d1,// 180 PAY 152 

    0xa1fce808,// 181 PAY 153 

    0xa8934f6e,// 182 PAY 154 

    0x0ddea223,// 183 PAY 155 

    0x0065f5f8,// 184 PAY 156 

    0xd8411fbe,// 185 PAY 157 

    0x28d51493,// 186 PAY 158 

    0x3d61007c,// 187 PAY 159 

    0x9efa4373,// 188 PAY 160 

    0xdc671253,// 189 PAY 161 

    0x1b2e1ab0,// 190 PAY 162 

    0x91e342e0,// 191 PAY 163 

    0x3aba8c37,// 192 PAY 164 

    0x13418c52,// 193 PAY 165 

    0xd4d60898,// 194 PAY 166 

    0xd18182a6,// 195 PAY 167 

    0x7c6c78a4,// 196 PAY 168 

    0x9465bf36,// 197 PAY 169 

    0xff48aefd,// 198 PAY 170 

    0xfd2146ed,// 199 PAY 171 

    0xdbc4e65f,// 200 PAY 172 

    0xb0bcff69,// 201 PAY 173 

    0x2e268788,// 202 PAY 174 

    0xabeed82f,// 203 PAY 175 

    0x2f1a551e,// 204 PAY 176 

    0x4dabb84e,// 205 PAY 177 

    0xb7d0d11b,// 206 PAY 178 

    0x3dc5c57d,// 207 PAY 179 

    0x96080e3c,// 208 PAY 180 

    0x74cbc46f,// 209 PAY 181 

    0xbb485385,// 210 PAY 182 

    0xe81a8f3b,// 211 PAY 183 

    0xd22fe9f5,// 212 PAY 184 

    0xceaa7cbf,// 213 PAY 185 

    0x1632efcc,// 214 PAY 186 

    0x51864b27,// 215 PAY 187 

    0x4bbb4b80,// 216 PAY 188 

    0x8cee77e7,// 217 PAY 189 

    0x8cc016f3,// 218 PAY 190 

    0x31ccacae,// 219 PAY 191 

    0xac38845d,// 220 PAY 192 

    0x1e50e608,// 221 PAY 193 

    0xa75daef0,// 222 PAY 194 

    0x7bc79b78,// 223 PAY 195 

    0x8083601c,// 224 PAY 196 

    0x74b8394a,// 225 PAY 197 

    0x90e440ed,// 226 PAY 198 

    0x5a8772bc,// 227 PAY 199 

    0x536dbf30,// 228 PAY 200 

    0x6aa08a31,// 229 PAY 201 

    0x600f5bc0,// 230 PAY 202 

    0xbd69882e,// 231 PAY 203 

    0xcf8bc893,// 232 PAY 204 

    0x0a62e73e,// 233 PAY 205 

    0x7c51462a,// 234 PAY 206 

    0x73ab0cf5,// 235 PAY 207 

    0x522a6ecf,// 236 PAY 208 

    0xb912f556,// 237 PAY 209 

    0xbeac222c,// 238 PAY 210 

    0xb369ff16,// 239 PAY 211 

    0x04f1a7e8,// 240 PAY 212 

    0x7b213220,// 241 PAY 213 

    0xea17c627,// 242 PAY 214 

    0x17e44ff8,// 243 PAY 215 

    0x78ef1275,// 244 PAY 216 

    0xb11e5025,// 245 PAY 217 

    0xefaaa37c,// 246 PAY 218 

    0xf9ea90ec,// 247 PAY 219 

    0x4c6b9632,// 248 PAY 220 

    0xc5724688,// 249 PAY 221 

    0x546db111,// 250 PAY 222 

    0x5613e076,// 251 PAY 223 

    0x4324777f,// 252 PAY 224 

    0x1683eeb0,// 253 PAY 225 

    0xbba007fc,// 254 PAY 226 

    0xae8a3f5d,// 255 PAY 227 

    0x6da9084a,// 256 PAY 228 

    0x5c33315b,// 257 PAY 229 

    0xcd3d479a,// 258 PAY 230 

    0x86ad952e,// 259 PAY 231 

    0x55bdbca6,// 260 PAY 232 

    0x0bd64827,// 261 PAY 233 

    0x9aa6a5a6,// 262 PAY 234 

    0x9c17bc71,// 263 PAY 235 

    0x95996f76,// 264 PAY 236 

    0x2a31f141,// 265 PAY 237 

    0x130b3e4e,// 266 PAY 238 

    0x82751407,// 267 PAY 239 

    0xe8986861,// 268 PAY 240 

    0x927f517c,// 269 PAY 241 

    0x73e98a97,// 270 PAY 242 

    0x16983d8a,// 271 PAY 243 

    0xd83e7845,// 272 PAY 244 

    0xdbb181e8,// 273 PAY 245 

    0xbf846519,// 274 PAY 246 

    0xfd10ba96,// 275 PAY 247 

    0x20bde263,// 276 PAY 248 

    0xa653f1fa,// 277 PAY 249 

    0x348e674f,// 278 PAY 250 

    0xcb2fcc5a,// 279 PAY 251 

    0xc74d33d7,// 280 PAY 252 

    0x60decee9,// 281 PAY 253 

    0xfca4b0e6,// 282 PAY 254 

    0x1ab5cd21,// 283 PAY 255 

    0xbae06db7,// 284 PAY 256 

    0xcfffe5e9,// 285 PAY 257 

    0x3e4ccf3d,// 286 PAY 258 

    0xf9695bbc,// 287 PAY 259 

    0xda092272,// 288 PAY 260 

    0x382f6db7,// 289 PAY 261 

    0x58a83c6d,// 290 PAY 262 

    0x6141f5eb,// 291 PAY 263 

    0x9c130718,// 292 PAY 264 

    0x24cdbae5,// 293 PAY 265 

    0x4ebf7281,// 294 PAY 266 

    0xb5e22747,// 295 PAY 267 

    0x92edc4b5,// 296 PAY 268 

    0xc19a4bbd,// 297 PAY 269 

    0x2361b47f,// 298 PAY 270 

    0xc7169c07,// 299 PAY 271 

    0x69361fbe,// 300 PAY 272 

    0xbd79a90b,// 301 PAY 273 

    0x0e841e51,// 302 PAY 274 

    0xdb66476a,// 303 PAY 275 

    0xdf2786df,// 304 PAY 276 

    0x435f719c,// 305 PAY 277 

    0x2938f58f,// 306 PAY 278 

    0x4d6603c2,// 307 PAY 279 

    0x29493f2b,// 308 PAY 280 

    0x6ec3258a,// 309 PAY 281 

    0xb9ab7588,// 310 PAY 282 

    0xe9bf9713,// 311 PAY 283 

    0x49cbd518,// 312 PAY 284 

    0xb50a1709,// 313 PAY 285 

    0x90b1cb0a,// 314 PAY 286 

    0x9b73bbd1,// 315 PAY 287 

    0x57ceee80,// 316 PAY 288 

    0xc62df69b,// 317 PAY 289 

    0x4fbfb668,// 318 PAY 290 

    0x8db814f7,// 319 PAY 291 

    0x3122cce9,// 320 PAY 292 

    0x5ba7d9a3,// 321 PAY 293 

    0x21b99f87,// 322 PAY 294 

    0x7cf3f8ed,// 323 PAY 295 

    0xbee8228b,// 324 PAY 296 

    0x5303aa81,// 325 PAY 297 

    0xc0feb368,// 326 PAY 298 

    0x922dd8a4,// 327 PAY 299 

    0xbd86e794,// 328 PAY 300 

    0xd5b7b8a8,// 329 PAY 301 

    0x13bcef17,// 330 PAY 302 

    0x80b5e900,// 331 PAY 303 

    0x886a212d,// 332 PAY 304 

    0x31b51011,// 333 PAY 305 

    0xeb6546a1,// 334 PAY 306 

    0xdebd9cc2,// 335 PAY 307 

    0x0f91759c,// 336 PAY 308 

    0x5ea9e83c,// 337 PAY 309 

    0xcdddc529,// 338 PAY 310 

    0x15cc9308,// 339 PAY 311 

    0xec13847d,// 340 PAY 312 

    0xc0ced4a5,// 341 PAY 313 

    0x276b7eff,// 342 PAY 314 

    0x7d22bf96,// 343 PAY 315 

    0x5bf7c067,// 344 PAY 316 

    0x0e5d5280,// 345 PAY 317 

    0xb671ade5,// 346 PAY 318 

    0x67d7a130,// 347 PAY 319 

    0xe63f51a3,// 348 PAY 320 

    0xfd28773b,// 349 PAY 321 

    0x5f28c63d,// 350 PAY 322 

    0xe75a1aa7,// 351 PAY 323 

    0xc382f564,// 352 PAY 324 

    0x17776950,// 353 PAY 325 

    0xd00b9849,// 354 PAY 326 

    0xd94c3b7f,// 355 PAY 327 

    0x963a3224,// 356 PAY 328 

    0xa363c0f4,// 357 PAY 329 

    0x835980b4,// 358 PAY 330 

    0xbfdb0a6e,// 359 PAY 331 

    0x2271fbab,// 360 PAY 332 

    0xf4da84cf,// 361 PAY 333 

    0xfbdabd02,// 362 PAY 334 

    0xb9740215,// 363 PAY 335 

    0xaf57bf0b,// 364 PAY 336 

    0x9ec79676,// 365 PAY 337 

    0xc5642db7,// 366 PAY 338 

    0x63918551,// 367 PAY 339 

    0x8125df92,// 368 PAY 340 

    0xd815eed8,// 369 PAY 341 

    0x7add9ee2,// 370 PAY 342 

    0x47aa6194,// 371 PAY 343 

    0xac5d0be4,// 372 PAY 344 

    0xd40d3f53,// 373 PAY 345 

    0xe24a569e,// 374 PAY 346 

    0x418e493c,// 375 PAY 347 

    0x0ab6f72c,// 376 PAY 348 

    0xdf5a11c8,// 377 PAY 349 

    0xe4e0ab53,// 378 PAY 350 

    0x388a4278,// 379 PAY 351 

    0x2ccf7699,// 380 PAY 352 

    0x38ad4102,// 381 PAY 353 

    0xfcdd290a,// 382 PAY 354 

    0x874f6d46,// 383 PAY 355 

    0x7ab94b28,// 384 PAY 356 

    0xced073f3,// 385 PAY 357 

    0x6f27b6f4,// 386 PAY 358 

    0xa54a17ae,// 387 PAY 359 

    0x287350ed,// 388 PAY 360 

    0x9195a2a9,// 389 PAY 361 

    0x2a2354fb,// 390 PAY 362 

    0x0c56e25c,// 391 PAY 363 

    0xaed29bc7,// 392 PAY 364 

    0xcd026b8c,// 393 PAY 365 

    0x3eeb7911,// 394 PAY 366 

    0x0be12220,// 395 PAY 367 

    0x29fa3f47,// 396 PAY 368 

    0xcce266c4,// 397 PAY 369 

    0xe2300172,// 398 PAY 370 

    0x05bec114,// 399 PAY 371 

    0x2bcc3875,// 400 PAY 372 

    0x94d5f33b,// 401 PAY 373 

    0x09d01443,// 402 PAY 374 

    0x9f2a561c,// 403 PAY 375 

    0xffc452ed,// 404 PAY 376 

    0x032a82cb,// 405 PAY 377 

    0x44d3ba43,// 406 PAY 378 

    0x42fc8b33,// 407 PAY 379 

    0xc30366a0,// 408 PAY 380 

    0xfb09f0ed,// 409 PAY 381 

    0x431d8963,// 410 PAY 382 

    0xa3ddb600,// 411 PAY 383 

/// STA is 1 words. 

/// STA num_pkts       : 124 

/// STA pkt_idx        : 247 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xc5 

    0x03dcc57c // 412 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt17_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0f 

/// ECH pdu_tag        : 0x00 

    0x000f0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x8080287b,// 4 SCX   2 

    0x00002400,// 5 SCX   3 

    0x645d57b7,// 6 SCX   4 

    0xb4b092d3,// 7 SCX   5 

    0xa5757684,// 8 SCX   6 

    0xbe89e9fb,// 9 SCX   7 

    0xae9ecf92,// 10 SCX   8 

    0x719c5dc9,// 11 SCX   9 

    0xaec511ee,// 12 SCX  10 

    0x5d5eb4a0,// 13 SCX  11 

    0x3a781ee5,// 14 SCX  12 

    0x740619b5,// 15 SCX  13 

    0x429f85fc,// 16 SCX  14 

    0x557ec84d,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 321 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 157 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 157 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 80 

/// BFD (ofst+len)cry  : 96 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 228 

    0x0000009d,// 18 BFD   1 

    0x00500010,// 19 BFD   2 

    0x00e4000c,// 20 BFD   3 

/// MFM is 5 words. 

/// MFM vldnibs        : 24 

    0x24005339,// 21 MFM   1 

    0x87f2a5be,// 22 MFM   2 

    0x95dfc6a3,// 23 MFM   3 

    0xa5f7d78c,// 24 MFM   4 

    0x20662c5e,// 25 MFM   5 

/// BDA is 82 words. 

/// BDA size     is 321 (0x141) 

/// BDA id       is 0xc3ba 

    0x0141c3ba,// 26 BDA   1 

/// PAY Generic Data size   : 321 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x10e8b99d,// 27 PAY   1 

    0x53eb6e90,// 28 PAY   2 

    0x4060314c,// 29 PAY   3 

    0x6b48765a,// 30 PAY   4 

    0x2763cb98,// 31 PAY   5 

    0xb10511c7,// 32 PAY   6 

    0x7263c971,// 33 PAY   7 

    0x926184f4,// 34 PAY   8 

    0xe8842a54,// 35 PAY   9 

    0x98e7d032,// 36 PAY  10 

    0xc78d6ea3,// 37 PAY  11 

    0x728abd4c,// 38 PAY  12 

    0xda88b301,// 39 PAY  13 

    0x60171cff,// 40 PAY  14 

    0x148380df,// 41 PAY  15 

    0x93b94327,// 42 PAY  16 

    0xfa1310e9,// 43 PAY  17 

    0x97e09827,// 44 PAY  18 

    0x2f74e1dc,// 45 PAY  19 

    0x69a2dda2,// 46 PAY  20 

    0x2c88d30d,// 47 PAY  21 

    0xcb8cd136,// 48 PAY  22 

    0x797ea2d3,// 49 PAY  23 

    0xa0aeb494,// 50 PAY  24 

    0xa8ac577a,// 51 PAY  25 

    0xb5770263,// 52 PAY  26 

    0x578183e9,// 53 PAY  27 

    0xc3644788,// 54 PAY  28 

    0x62737710,// 55 PAY  29 

    0xea8b1c70,// 56 PAY  30 

    0x797e35e2,// 57 PAY  31 

    0x455db781,// 58 PAY  32 

    0x0b6ee943,// 59 PAY  33 

    0xde098d31,// 60 PAY  34 

    0xde6fdc04,// 61 PAY  35 

    0xd49627c3,// 62 PAY  36 

    0x43ae10fc,// 63 PAY  37 

    0x307a682d,// 64 PAY  38 

    0x9813630e,// 65 PAY  39 

    0x5797bea1,// 66 PAY  40 

    0xf3548f37,// 67 PAY  41 

    0x24bbc422,// 68 PAY  42 

    0x637bdace,// 69 PAY  43 

    0x7f171781,// 70 PAY  44 

    0xf5d08ab4,// 71 PAY  45 

    0xfa043239,// 72 PAY  46 

    0x38787c03,// 73 PAY  47 

    0x82a18667,// 74 PAY  48 

    0xfa62ebb5,// 75 PAY  49 

    0xa1561f79,// 76 PAY  50 

    0x23eed3a4,// 77 PAY  51 

    0xf11e3a61,// 78 PAY  52 

    0xc0a935ad,// 79 PAY  53 

    0xdb2e19ee,// 80 PAY  54 

    0xebc88bb3,// 81 PAY  55 

    0x9bbb4c24,// 82 PAY  56 

    0x76fe69e5,// 83 PAY  57 

    0x05f7331e,// 84 PAY  58 

    0x98d40f84,// 85 PAY  59 

    0x998d7ba5,// 86 PAY  60 

    0x95805105,// 87 PAY  61 

    0xe55de240,// 88 PAY  62 

    0x6154083d,// 89 PAY  63 

    0x20064b62,// 90 PAY  64 

    0x7f7f4c63,// 91 PAY  65 

    0xa693eeac,// 92 PAY  66 

    0x102d8e09,// 93 PAY  67 

    0x78b69c4b,// 94 PAY  68 

    0xafe1aa20,// 95 PAY  69 

    0xc66fff4c,// 96 PAY  70 

    0x8ce3f5df,// 97 PAY  71 

    0x04c08767,// 98 PAY  72 

    0x3677a8c7,// 99 PAY  73 

    0xf57f39b4,// 100 PAY  74 

    0xfc490016,// 101 PAY  75 

    0x14280703,// 102 PAY  76 

    0x9c71c744,// 103 PAY  77 

    0x839c2dd5,// 104 PAY  78 

    0x94214bc0,// 105 PAY  79 

    0x0bfdc141,// 106 PAY  80 

    0x34000000,// 107 PAY  81 

/// STA is 1 words. 

/// STA num_pkts       : 137 

/// STA pkt_idx        : 109 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xc0 

    0x01b5c089 // 108 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt18_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x809028a9,// 4 SCX   2 

    0x000041c2,// 5 SCX   3 

    0x5aa6df11,// 6 SCX   4 

    0xae8f0351,// 7 SCX   5 

    0xc925b30c,// 8 SCX   6 

    0x5d5cbec3,// 9 SCX   7 

    0x30b2a671,// 10 SCX   8 

    0xed2a7fe1,// 11 SCX   9 

    0xcdb31492,// 12 SCX  10 

    0x66d84def,// 13 SCX  11 

    0x90fd7e05,// 14 SCX  12 

    0x92e9e2e2,// 15 SCX  13 

    0x7c005beb,// 16 SCX  14 

    0x443ad036,// 17 SCX  15 

    0x78dde563,// 18 SCX  16 

    0x03c66a62,// 19 SCX  17 

    0x844ebf1f,// 20 SCX  18 

    0xb0024782,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1970 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 1385 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1385 

/// BFD lencrypto      : 380 

/// BFD ofstcrypto     : 984 

/// BFD (ofst+len)cry  : 1364 

/// BFD ofstiv         : 528 

/// BFD ofsticv        : 1432 

    0x00000569,// 22 BFD   1 

    0x03d8017c,// 23 BFD   2 

    0x05980210,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 8 

    0x080070d9,// 25 MFM   1 

    0x6a270000,// 26 MFM   2 

/// BDA is 494 words. 

/// BDA size     is 1970 (0x7b2) 

/// BDA id       is 0xdbea 

    0x07b2dbea,// 27 BDA   1 

/// PAY Generic Data size   : 1970 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x4a1f7048,// 28 PAY   1 

    0xe85a3c99,// 29 PAY   2 

    0xf2fc8d6d,// 30 PAY   3 

    0xea05f237,// 31 PAY   4 

    0x719e9572,// 32 PAY   5 

    0xb3c7db66,// 33 PAY   6 

    0x2fbfe980,// 34 PAY   7 

    0x42a44acd,// 35 PAY   8 

    0x94a89e98,// 36 PAY   9 

    0xf2b97b76,// 37 PAY  10 

    0x2bcdad43,// 38 PAY  11 

    0xe7426bc3,// 39 PAY  12 

    0x772e2bf2,// 40 PAY  13 

    0x0e12d841,// 41 PAY  14 

    0xa4690f12,// 42 PAY  15 

    0xc13d83b1,// 43 PAY  16 

    0xb096ef02,// 44 PAY  17 

    0xfb0484a4,// 45 PAY  18 

    0xe8782b14,// 46 PAY  19 

    0x118614a3,// 47 PAY  20 

    0xdd2f89ad,// 48 PAY  21 

    0x8eba930e,// 49 PAY  22 

    0x961a92c5,// 50 PAY  23 

    0x4f42578e,// 51 PAY  24 

    0xe017005f,// 52 PAY  25 

    0x3628699a,// 53 PAY  26 

    0xd368c698,// 54 PAY  27 

    0x3a788571,// 55 PAY  28 

    0xdca892d9,// 56 PAY  29 

    0x828c97ea,// 57 PAY  30 

    0xad75441f,// 58 PAY  31 

    0x454afe68,// 59 PAY  32 

    0xe8062bc3,// 60 PAY  33 

    0x7eb9044d,// 61 PAY  34 

    0x274ef03f,// 62 PAY  35 

    0x437ecaa8,// 63 PAY  36 

    0x05300ec0,// 64 PAY  37 

    0x08d5e2de,// 65 PAY  38 

    0x1f1af153,// 66 PAY  39 

    0x88df44da,// 67 PAY  40 

    0x4ceb72ff,// 68 PAY  41 

    0x0f844d6f,// 69 PAY  42 

    0xbb66b6e2,// 70 PAY  43 

    0xd5503bb1,// 71 PAY  44 

    0xf6c5319a,// 72 PAY  45 

    0x497ea22b,// 73 PAY  46 

    0x1e3b796e,// 74 PAY  47 

    0x6a2178f5,// 75 PAY  48 

    0xe7d8f259,// 76 PAY  49 

    0x0dde3f60,// 77 PAY  50 

    0x5c3012ba,// 78 PAY  51 

    0x37e8541d,// 79 PAY  52 

    0x8dea4678,// 80 PAY  53 

    0x12ebbb46,// 81 PAY  54 

    0xd039803c,// 82 PAY  55 

    0x48a51c46,// 83 PAY  56 

    0x752e4697,// 84 PAY  57 

    0x52ecde21,// 85 PAY  58 

    0x673ee5d3,// 86 PAY  59 

    0xd8208bca,// 87 PAY  60 

    0x935752a3,// 88 PAY  61 

    0xd9fbc3d9,// 89 PAY  62 

    0x6503f912,// 90 PAY  63 

    0x092a9d4b,// 91 PAY  64 

    0x676331c9,// 92 PAY  65 

    0x138e1c0a,// 93 PAY  66 

    0xbf680b03,// 94 PAY  67 

    0xcfb58f5c,// 95 PAY  68 

    0xaa489033,// 96 PAY  69 

    0x01d56012,// 97 PAY  70 

    0x5dd16939,// 98 PAY  71 

    0xa28495b6,// 99 PAY  72 

    0x4862083b,// 100 PAY  73 

    0x13fe2db5,// 101 PAY  74 

    0x907cb399,// 102 PAY  75 

    0xfddd277b,// 103 PAY  76 

    0x25d4fedf,// 104 PAY  77 

    0x624dac0c,// 105 PAY  78 

    0x915eb1be,// 106 PAY  79 

    0xc076c382,// 107 PAY  80 

    0x0550b03b,// 108 PAY  81 

    0x5a879d3a,// 109 PAY  82 

    0x22f55619,// 110 PAY  83 

    0xd22312b2,// 111 PAY  84 

    0xf48b773b,// 112 PAY  85 

    0xd2abc23b,// 113 PAY  86 

    0x377597fd,// 114 PAY  87 

    0x38303fca,// 115 PAY  88 

    0xafd3e39c,// 116 PAY  89 

    0x745a973d,// 117 PAY  90 

    0x9bb8333e,// 118 PAY  91 

    0xbe0e5045,// 119 PAY  92 

    0xdd9ce92b,// 120 PAY  93 

    0xce43b785,// 121 PAY  94 

    0x832073b3,// 122 PAY  95 

    0x6c1a9039,// 123 PAY  96 

    0x87178f52,// 124 PAY  97 

    0xba194ba1,// 125 PAY  98 

    0x72e49d41,// 126 PAY  99 

    0x9a5ec6da,// 127 PAY 100 

    0xe5ac24fc,// 128 PAY 101 

    0xf1d4084c,// 129 PAY 102 

    0x25e426b6,// 130 PAY 103 

    0x4de8bd03,// 131 PAY 104 

    0xc6926d1a,// 132 PAY 105 

    0x6d1e7055,// 133 PAY 106 

    0x04aebaf7,// 134 PAY 107 

    0x96033e66,// 135 PAY 108 

    0xaff93d5d,// 136 PAY 109 

    0x4175f0a1,// 137 PAY 110 

    0xca223e8d,// 138 PAY 111 

    0x313219ab,// 139 PAY 112 

    0xa04f3bc1,// 140 PAY 113 

    0xf73fb9dd,// 141 PAY 114 

    0xf76c7e49,// 142 PAY 115 

    0xcc01be39,// 143 PAY 116 

    0xe3e18d30,// 144 PAY 117 

    0x000cc02e,// 145 PAY 118 

    0x2d1e6ba6,// 146 PAY 119 

    0xfd52f8ee,// 147 PAY 120 

    0xdd3097c9,// 148 PAY 121 

    0x42503f38,// 149 PAY 122 

    0xe5043679,// 150 PAY 123 

    0xca16e35c,// 151 PAY 124 

    0x2464c037,// 152 PAY 125 

    0xfe7392fc,// 153 PAY 126 

    0x4402643e,// 154 PAY 127 

    0x722a2666,// 155 PAY 128 

    0x37245b18,// 156 PAY 129 

    0xf71d9ee2,// 157 PAY 130 

    0x8188d981,// 158 PAY 131 

    0x09520c73,// 159 PAY 132 

    0x3d247d60,// 160 PAY 133 

    0x2fa06c30,// 161 PAY 134 

    0x7882c538,// 162 PAY 135 

    0xe31e75d0,// 163 PAY 136 

    0x93fa30c1,// 164 PAY 137 

    0xe5119aa4,// 165 PAY 138 

    0x95446dff,// 166 PAY 139 

    0x3c33fa6d,// 167 PAY 140 

    0x3f02270e,// 168 PAY 141 

    0x351a381b,// 169 PAY 142 

    0xb5d3041e,// 170 PAY 143 

    0xeae98d7c,// 171 PAY 144 

    0x8f98c650,// 172 PAY 145 

    0x8a87ed0d,// 173 PAY 146 

    0x25de9c2b,// 174 PAY 147 

    0x615b9142,// 175 PAY 148 

    0x7d7454f5,// 176 PAY 149 

    0x8ee83150,// 177 PAY 150 

    0xcd73239e,// 178 PAY 151 

    0xbf7dc450,// 179 PAY 152 

    0x47d80201,// 180 PAY 153 

    0xf19f1f81,// 181 PAY 154 

    0xe56e63d9,// 182 PAY 155 

    0x6974fa61,// 183 PAY 156 

    0x6563485d,// 184 PAY 157 

    0x9cbfdbd3,// 185 PAY 158 

    0x7cac7634,// 186 PAY 159 

    0xe02fde3a,// 187 PAY 160 

    0x7da24c43,// 188 PAY 161 

    0x38c1d29b,// 189 PAY 162 

    0xfa92c803,// 190 PAY 163 

    0xc1a5dac2,// 191 PAY 164 

    0x8efcc84c,// 192 PAY 165 

    0xe28298b1,// 193 PAY 166 

    0x895530d0,// 194 PAY 167 

    0xbaa1eff4,// 195 PAY 168 

    0xae3012f6,// 196 PAY 169 

    0xb871d61f,// 197 PAY 170 

    0x7487cd10,// 198 PAY 171 

    0xbd8a4366,// 199 PAY 172 

    0x9ab54827,// 200 PAY 173 

    0x9f0a8bee,// 201 PAY 174 

    0x17fe389b,// 202 PAY 175 

    0xe77501a9,// 203 PAY 176 

    0x2ebc46b1,// 204 PAY 177 

    0x48892657,// 205 PAY 178 

    0xbc8f3183,// 206 PAY 179 

    0xc01c4c7f,// 207 PAY 180 

    0x2da2abfd,// 208 PAY 181 

    0x45be9507,// 209 PAY 182 

    0x15062cbb,// 210 PAY 183 

    0xf587f0fa,// 211 PAY 184 

    0x8d167ab3,// 212 PAY 185 

    0x94c14b48,// 213 PAY 186 

    0x1a6ef857,// 214 PAY 187 

    0xcf3ac294,// 215 PAY 188 

    0xec96d44e,// 216 PAY 189 

    0x59d9a749,// 217 PAY 190 

    0x9c7d3d48,// 218 PAY 191 

    0x2592ca0e,// 219 PAY 192 

    0xb6002341,// 220 PAY 193 

    0x11c2b7f2,// 221 PAY 194 

    0x4de7b67a,// 222 PAY 195 

    0x63f01663,// 223 PAY 196 

    0xc4b99156,// 224 PAY 197 

    0x4f3d1ba2,// 225 PAY 198 

    0x90e430d0,// 226 PAY 199 

    0xa7ea9e64,// 227 PAY 200 

    0x413b2729,// 228 PAY 201 

    0x1489cbd0,// 229 PAY 202 

    0xac6881a5,// 230 PAY 203 

    0x7ac44728,// 231 PAY 204 

    0x402dea35,// 232 PAY 205 

    0xca7cf804,// 233 PAY 206 

    0x98a020d0,// 234 PAY 207 

    0x818cdb55,// 235 PAY 208 

    0xdb7f2739,// 236 PAY 209 

    0x8c2c91a3,// 237 PAY 210 

    0xca28639a,// 238 PAY 211 

    0x9e9f804a,// 239 PAY 212 

    0xca14bd2a,// 240 PAY 213 

    0x01823f41,// 241 PAY 214 

    0xa0bfae01,// 242 PAY 215 

    0x4dff26fb,// 243 PAY 216 

    0x4863b2e2,// 244 PAY 217 

    0x21c924a4,// 245 PAY 218 

    0x21330288,// 246 PAY 219 

    0x8bb4a971,// 247 PAY 220 

    0xba6e1ff1,// 248 PAY 221 

    0x27290be7,// 249 PAY 222 

    0x38e98c15,// 250 PAY 223 

    0x12ca6860,// 251 PAY 224 

    0x9f2a1ffc,// 252 PAY 225 

    0x28af3462,// 253 PAY 226 

    0xda8c0ac6,// 254 PAY 227 

    0x0164cece,// 255 PAY 228 

    0x64611691,// 256 PAY 229 

    0xf178be3a,// 257 PAY 230 

    0x7d3c3244,// 258 PAY 231 

    0xb6b4cbb7,// 259 PAY 232 

    0x68c34838,// 260 PAY 233 

    0xac63e28c,// 261 PAY 234 

    0x9dcff1a7,// 262 PAY 235 

    0x962d163e,// 263 PAY 236 

    0x393059b9,// 264 PAY 237 

    0x9d6f3375,// 265 PAY 238 

    0xcfba57a6,// 266 PAY 239 

    0x08f27c1b,// 267 PAY 240 

    0xee829178,// 268 PAY 241 

    0xb07281af,// 269 PAY 242 

    0x6b6b5b3b,// 270 PAY 243 

    0xee230c65,// 271 PAY 244 

    0xa871224a,// 272 PAY 245 

    0x56e43fac,// 273 PAY 246 

    0xe7d31ba6,// 274 PAY 247 

    0x094e031d,// 275 PAY 248 

    0x8f17ae99,// 276 PAY 249 

    0x8c8b7476,// 277 PAY 250 

    0x9fc78d11,// 278 PAY 251 

    0x12f1b671,// 279 PAY 252 

    0x5967c3ac,// 280 PAY 253 

    0x5f34b5f3,// 281 PAY 254 

    0xaaf2758d,// 282 PAY 255 

    0x6e20664b,// 283 PAY 256 

    0x2379b2dc,// 284 PAY 257 

    0x771e16aa,// 285 PAY 258 

    0xbb27b10d,// 286 PAY 259 

    0x906fa5b8,// 287 PAY 260 

    0x1149bc6d,// 288 PAY 261 

    0x3f814609,// 289 PAY 262 

    0x2774261f,// 290 PAY 263 

    0x7943e5d5,// 291 PAY 264 

    0xf226535b,// 292 PAY 265 

    0xa865b74b,// 293 PAY 266 

    0x2d9ae0da,// 294 PAY 267 

    0x3cdcd577,// 295 PAY 268 

    0x60472f76,// 296 PAY 269 

    0x8756d670,// 297 PAY 270 

    0x6c1ab5ea,// 298 PAY 271 

    0x5e7bd836,// 299 PAY 272 

    0xf23f760f,// 300 PAY 273 

    0xb63dd72a,// 301 PAY 274 

    0x2623b61e,// 302 PAY 275 

    0x8ccd9a07,// 303 PAY 276 

    0x48968ac6,// 304 PAY 277 

    0xb592a929,// 305 PAY 278 

    0xd1eb91f9,// 306 PAY 279 

    0x7a62b974,// 307 PAY 280 

    0xe9e7cce3,// 308 PAY 281 

    0x544959e9,// 309 PAY 282 

    0x38d5ccd3,// 310 PAY 283 

    0xd072fd87,// 311 PAY 284 

    0x2a658cde,// 312 PAY 285 

    0x77198a8a,// 313 PAY 286 

    0x39e58d56,// 314 PAY 287 

    0x0b94108e,// 315 PAY 288 

    0x67f2c9e6,// 316 PAY 289 

    0x117f75c1,// 317 PAY 290 

    0x8b30b90a,// 318 PAY 291 

    0xaceee37b,// 319 PAY 292 

    0x0a5db027,// 320 PAY 293 

    0xeacc9ed0,// 321 PAY 294 

    0x0538931c,// 322 PAY 295 

    0x655ca4d1,// 323 PAY 296 

    0xa2398bbf,// 324 PAY 297 

    0x9ff07fec,// 325 PAY 298 

    0x3e29f58c,// 326 PAY 299 

    0x99220869,// 327 PAY 300 

    0x10fbaa51,// 328 PAY 301 

    0xb7b4c2e3,// 329 PAY 302 

    0x121872dc,// 330 PAY 303 

    0x9b57b15a,// 331 PAY 304 

    0x35169e23,// 332 PAY 305 

    0x47448c26,// 333 PAY 306 

    0x9346f6cb,// 334 PAY 307 

    0x782179c6,// 335 PAY 308 

    0x47c8e2b5,// 336 PAY 309 

    0xa8f81241,// 337 PAY 310 

    0xff94d6db,// 338 PAY 311 

    0xdcbe74df,// 339 PAY 312 

    0xd825866b,// 340 PAY 313 

    0xd1da6442,// 341 PAY 314 

    0x93fc1a57,// 342 PAY 315 

    0x2ec6ab7a,// 343 PAY 316 

    0x9efd7b0f,// 344 PAY 317 

    0x49d3d877,// 345 PAY 318 

    0xd8b54214,// 346 PAY 319 

    0xddd8774b,// 347 PAY 320 

    0xf6229234,// 348 PAY 321 

    0xcd5be156,// 349 PAY 322 

    0x015abc20,// 350 PAY 323 

    0x35d85d97,// 351 PAY 324 

    0xc97c39f2,// 352 PAY 325 

    0xd0b74de4,// 353 PAY 326 

    0xf2b1e280,// 354 PAY 327 

    0x8bbf6e50,// 355 PAY 328 

    0xaf370e86,// 356 PAY 329 

    0x121e7b4d,// 357 PAY 330 

    0xcf2bb3fe,// 358 PAY 331 

    0x10613567,// 359 PAY 332 

    0x2d5c7cd5,// 360 PAY 333 

    0xcbda6010,// 361 PAY 334 

    0x3fca0608,// 362 PAY 335 

    0x5a71c831,// 363 PAY 336 

    0x5126c381,// 364 PAY 337 

    0xc3a9e7c8,// 365 PAY 338 

    0x381763b7,// 366 PAY 339 

    0x166d72ae,// 367 PAY 340 

    0x75b45a94,// 368 PAY 341 

    0xf0d0a554,// 369 PAY 342 

    0x428bafa7,// 370 PAY 343 

    0x29c16f1c,// 371 PAY 344 

    0x5d937706,// 372 PAY 345 

    0xbc879775,// 373 PAY 346 

    0x266e14af,// 374 PAY 347 

    0xf09b4c40,// 375 PAY 348 

    0xf945853c,// 376 PAY 349 

    0xe2258519,// 377 PAY 350 

    0xbfca556c,// 378 PAY 351 

    0x95444964,// 379 PAY 352 

    0x9a944986,// 380 PAY 353 

    0xaac172ce,// 381 PAY 354 

    0xdfb271f6,// 382 PAY 355 

    0x6b995f51,// 383 PAY 356 

    0x181f441d,// 384 PAY 357 

    0x44eb9e91,// 385 PAY 358 

    0xb6a2c2b8,// 386 PAY 359 

    0xf217b53e,// 387 PAY 360 

    0xa8aa8661,// 388 PAY 361 

    0x1028f734,// 389 PAY 362 

    0xea5db38a,// 390 PAY 363 

    0x8cb526fe,// 391 PAY 364 

    0x7c683eea,// 392 PAY 365 

    0xc03d2950,// 393 PAY 366 

    0x65e877d4,// 394 PAY 367 

    0x1ca5a22e,// 395 PAY 368 

    0xe64caf61,// 396 PAY 369 

    0x71c3cada,// 397 PAY 370 

    0x88afd8b4,// 398 PAY 371 

    0xbc38ffa3,// 399 PAY 372 

    0x376b6c87,// 400 PAY 373 

    0xa5e5c1f9,// 401 PAY 374 

    0xfc2e25df,// 402 PAY 375 

    0x8659646d,// 403 PAY 376 

    0x30da1ace,// 404 PAY 377 

    0x77fde0f0,// 405 PAY 378 

    0xd6e6b012,// 406 PAY 379 

    0x92c050b0,// 407 PAY 380 

    0x428779d0,// 408 PAY 381 

    0xccfe1d48,// 409 PAY 382 

    0x07eb6190,// 410 PAY 383 

    0xe0821607,// 411 PAY 384 

    0xf844d3d1,// 412 PAY 385 

    0x06e54c6d,// 413 PAY 386 

    0xebe50335,// 414 PAY 387 

    0xc296c0a8,// 415 PAY 388 

    0xe5b5def8,// 416 PAY 389 

    0x3bed1c69,// 417 PAY 390 

    0xfe30934b,// 418 PAY 391 

    0xe7c8f679,// 419 PAY 392 

    0x651cda10,// 420 PAY 393 

    0x53207572,// 421 PAY 394 

    0x4f2802ba,// 422 PAY 395 

    0x313f13b0,// 423 PAY 396 

    0x3e595848,// 424 PAY 397 

    0x170beb7d,// 425 PAY 398 

    0xbf5ecadb,// 426 PAY 399 

    0xb465071c,// 427 PAY 400 

    0x522b83d6,// 428 PAY 401 

    0x69a21516,// 429 PAY 402 

    0x2e55e822,// 430 PAY 403 

    0xd944b1b6,// 431 PAY 404 

    0x20ecffa8,// 432 PAY 405 

    0x43eff6f4,// 433 PAY 406 

    0xef3b794e,// 434 PAY 407 

    0x8d497945,// 435 PAY 408 

    0xe10fab41,// 436 PAY 409 

    0x81c60cc5,// 437 PAY 410 

    0x6a9cb363,// 438 PAY 411 

    0x23cecc69,// 439 PAY 412 

    0xc423b6d8,// 440 PAY 413 

    0x30ed457b,// 441 PAY 414 

    0xa40c6b1d,// 442 PAY 415 

    0xb0f0976b,// 443 PAY 416 

    0x90f32369,// 444 PAY 417 

    0xc3dd19ec,// 445 PAY 418 

    0xf44a9e5f,// 446 PAY 419 

    0x82b94bc9,// 447 PAY 420 

    0xeefa711b,// 448 PAY 421 

    0xab12637d,// 449 PAY 422 

    0x67df6782,// 450 PAY 423 

    0xb24704f5,// 451 PAY 424 

    0x2387145f,// 452 PAY 425 

    0xf7bbad20,// 453 PAY 426 

    0x534e9006,// 454 PAY 427 

    0xba086eb0,// 455 PAY 428 

    0x0cb55569,// 456 PAY 429 

    0x76c4de60,// 457 PAY 430 

    0x1892f32f,// 458 PAY 431 

    0x7f4fa946,// 459 PAY 432 

    0xadee3f2c,// 460 PAY 433 

    0xe27de045,// 461 PAY 434 

    0xc7382927,// 462 PAY 435 

    0x58aca509,// 463 PAY 436 

    0xbf2f489d,// 464 PAY 437 

    0xec4e0d16,// 465 PAY 438 

    0x7e1c4e32,// 466 PAY 439 

    0xa9f6c0b5,// 467 PAY 440 

    0x54515cb2,// 468 PAY 441 

    0x4baa8d00,// 469 PAY 442 

    0xb8373000,// 470 PAY 443 

    0x51921f7e,// 471 PAY 444 

    0x301edaa9,// 472 PAY 445 

    0xa4e67ed0,// 473 PAY 446 

    0x9d512a2f,// 474 PAY 447 

    0x27d69d7e,// 475 PAY 448 

    0xca9ff590,// 476 PAY 449 

    0x06214e63,// 477 PAY 450 

    0x2dcbd5ee,// 478 PAY 451 

    0xc8cc6a2a,// 479 PAY 452 

    0xb7bfe802,// 480 PAY 453 

    0x4f36d580,// 481 PAY 454 

    0xa2bdaa35,// 482 PAY 455 

    0xa504eed0,// 483 PAY 456 

    0xf2920c72,// 484 PAY 457 

    0x6b97e3da,// 485 PAY 458 

    0x8cb67451,// 486 PAY 459 

    0xbd11eab9,// 487 PAY 460 

    0x09197788,// 488 PAY 461 

    0x5c449632,// 489 PAY 462 

    0xc86b91d5,// 490 PAY 463 

    0x73ae6ae9,// 491 PAY 464 

    0x4b19d117,// 492 PAY 465 

    0xac5a9480,// 493 PAY 466 

    0x75893b29,// 494 PAY 467 

    0x7137fca9,// 495 PAY 468 

    0xc9402de5,// 496 PAY 469 

    0x1014d603,// 497 PAY 470 

    0x37123c8c,// 498 PAY 471 

    0xd54c59f9,// 499 PAY 472 

    0xbecbce21,// 500 PAY 473 

    0xb2c5250e,// 501 PAY 474 

    0x3f2e4d99,// 502 PAY 475 

    0x7816e514,// 503 PAY 476 

    0xf44c7ea3,// 504 PAY 477 

    0x3cc9810f,// 505 PAY 478 

    0xe434a574,// 506 PAY 479 

    0xfb302d56,// 507 PAY 480 

    0x92ba7fb3,// 508 PAY 481 

    0xa1e47385,// 509 PAY 482 

    0x03a6d4a5,// 510 PAY 483 

    0x512c8bcc,// 511 PAY 484 

    0xb08a6b70,// 512 PAY 485 

    0x417804d6,// 513 PAY 486 

    0x8e1a1782,// 514 PAY 487 

    0x4d41f650,// 515 PAY 488 

    0xad211852,// 516 PAY 489 

    0xb9c0e050,// 517 PAY 490 

    0x826db892,// 518 PAY 491 

    0x69d2f13e,// 519 PAY 492 

    0x02790000,// 520 PAY 493 

/// STA is 1 words. 

/// STA num_pkts       : 212 

/// STA pkt_idx        : 86 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xe6 

    0x0158e6d4 // 521 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt19_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x808128c6,// 4 SCX   2 

    0x00006400,// 5 SCX   3 

    0x77e4262a,// 6 SCX   4 

    0xadd4a2a9,// 7 SCX   5 

    0xf384d6b2,// 8 SCX   6 

    0x4c3120ea,// 9 SCX   7 

    0x6ae61ec3,// 10 SCX   8 

    0x7248417e,// 11 SCX   9 

    0x79a78b39,// 12 SCX  10 

    0xfcc04107,// 13 SCX  11 

    0x648b28f8,// 14 SCX  12 

    0x37fd3ae8,// 15 SCX  13 

    0x33eeef8a,// 16 SCX  14 

    0xf50f2230,// 17 SCX  15 

    0xf4b28dec,// 18 SCX  16 

    0x7f6f293b,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 186 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 103 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 103 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 60 

/// BFD (ofst+len)cry  : 92 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 116 

    0x00000067,// 20 BFD   1 

    0x003c0020,// 21 BFD   2 

    0x00740010,// 22 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 8 

    0x0800a2e5,// 23 MFM   1 

    0x20f80000,// 24 MFM   2 

/// BDA is 48 words. 

/// BDA size     is 186 (0xba) 

/// BDA id       is 0x426c 

    0x00ba426c,// 25 BDA   1 

/// PAY Generic Data size   : 186 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xc3213061,// 26 PAY   1 

    0xcdfd4d09,// 27 PAY   2 

    0x6a158325,// 28 PAY   3 

    0x8d45e141,// 29 PAY   4 

    0xbf2b58f5,// 30 PAY   5 

    0x40273ba6,// 31 PAY   6 

    0xa0503724,// 32 PAY   7 

    0xd0be8a6d,// 33 PAY   8 

    0x9380a69d,// 34 PAY   9 

    0x79e06ff9,// 35 PAY  10 

    0xfdecf315,// 36 PAY  11 

    0x02e2d22c,// 37 PAY  12 

    0xda81168b,// 38 PAY  13 

    0xaf740cd8,// 39 PAY  14 

    0x47cdf4e8,// 40 PAY  15 

    0x18d38153,// 41 PAY  16 

    0x4ccea0c0,// 42 PAY  17 

    0x30c5c17e,// 43 PAY  18 

    0x95409a95,// 44 PAY  19 

    0xbcc20ee9,// 45 PAY  20 

    0x9622f5d1,// 46 PAY  21 

    0x1c8598df,// 47 PAY  22 

    0xafd748a2,// 48 PAY  23 

    0x9bafe017,// 49 PAY  24 

    0xf4899e2c,// 50 PAY  25 

    0xd1bf4e54,// 51 PAY  26 

    0xe292b454,// 52 PAY  27 

    0xf76479d3,// 53 PAY  28 

    0x467e69db,// 54 PAY  29 

    0xb28d5ce4,// 55 PAY  30 

    0x9c395ea7,// 56 PAY  31 

    0x4387288c,// 57 PAY  32 

    0x9f8ad9cc,// 58 PAY  33 

    0x0d7a0655,// 59 PAY  34 

    0xceb814fe,// 60 PAY  35 

    0x17499764,// 61 PAY  36 

    0x8580f57f,// 62 PAY  37 

    0x2cd47bc2,// 63 PAY  38 

    0xceb9e1cc,// 64 PAY  39 

    0xb177f4e9,// 65 PAY  40 

    0x99b969c1,// 66 PAY  41 

    0x592666ec,// 67 PAY  42 

    0xaf254e66,// 68 PAY  43 

    0x6fea3b19,// 69 PAY  44 

    0x348eaa15,// 70 PAY  45 

    0xe9f39a6c,// 71 PAY  46 

    0x45eb0000,// 72 PAY  47 

/// STA is 1 words. 

/// STA num_pkts       : 27 

/// STA pkt_idx        : 179 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x3c 

    0x02cc3c1b // 73 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt20_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x07 

/// ECH pdu_tag        : 0x00 

    0x00070000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x808028a8,// 4 SCX   2 

    0x00004300,// 5 SCX   3 

    0xb9fdd983,// 6 SCX   4 

    0x6e0a3159,// 7 SCX   5 

    0x34f1dfc5,// 8 SCX   6 

    0x3301f00c,// 9 SCX   7 

    0x8cb7fcb0,// 10 SCX   8 

    0xe46fd4fa,// 11 SCX   9 

    0x27cd181b,// 12 SCX  10 

    0xcb8f32aa,// 13 SCX  11 

    0x2e4ac5d9,// 14 SCX  12 

    0x2b77b774,// 15 SCX  13 

    0x402620a7,// 16 SCX  14 

    0x6846aadc,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1371 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1116 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1116 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 1032 

/// BFD (ofst+len)cry  : 1112 

/// BFD ofstiv         : 256 

/// BFD ofsticv        : 1320 

    0x0000045c,// 18 BFD   1 

    0x04080050,// 19 BFD   2 

    0x05280100,// 20 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c005bb1,// 21 MFM   1 

    0x274c1016,// 22 MFM   2 

    0x51677c73,// 23 MFM   3 

    0x8ef34966,// 24 MFM   4 

    0x8334ba2b,// 25 MFM   5 

    0xe690d8e2,// 26 MFM   6 

    0x2a52be97,// 27 MFM   7 

    0x455e0422,// 28 MFM   8 

    0x44a7cbc6,// 29 MFM   9 

    0x3e26f29d,// 30 MFM  10 

    0x3c717981,// 31 MFM  11 

    0xdbd60254,// 32 MFM  12 

    0xe0471496,// 33 MFM  13 

    0x4d068f54,// 34 MFM  14 

    0x5fd5d83f,// 35 MFM  15 

    0x78ae763b,// 36 MFM  16 

/// BDA is 344 words. 

/// BDA size     is 1371 (0x55b) 

/// BDA id       is 0x1692 

    0x055b1692,// 37 BDA   1 

/// PAY Generic Data size   : 1371 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0xeaa0086b,// 38 PAY   1 

    0x8f848f52,// 39 PAY   2 

    0x5ee4f389,// 40 PAY   3 

    0x76e934c3,// 41 PAY   4 

    0xb1c1f0a6,// 42 PAY   5 

    0x23d261df,// 43 PAY   6 

    0xaffdbe5c,// 44 PAY   7 

    0x566f38fb,// 45 PAY   8 

    0x2531814e,// 46 PAY   9 

    0xcc12d4cd,// 47 PAY  10 

    0xd4abc50d,// 48 PAY  11 

    0xc0dbd608,// 49 PAY  12 

    0x96647e86,// 50 PAY  13 

    0xf9caaf09,// 51 PAY  14 

    0xd3d721f6,// 52 PAY  15 

    0x0047f0db,// 53 PAY  16 

    0x8d5bf342,// 54 PAY  17 

    0x61605d3c,// 55 PAY  18 

    0x83d69abc,// 56 PAY  19 

    0xa4fe8fd0,// 57 PAY  20 

    0x06ce1c53,// 58 PAY  21 

    0xf02c0d65,// 59 PAY  22 

    0xd864f4f6,// 60 PAY  23 

    0xff76e4ab,// 61 PAY  24 

    0xd769aa85,// 62 PAY  25 

    0x92bba86b,// 63 PAY  26 

    0xca728b81,// 64 PAY  27 

    0x53856ffb,// 65 PAY  28 

    0xc075fdc0,// 66 PAY  29 

    0xd2eac4d9,// 67 PAY  30 

    0x8178e117,// 68 PAY  31 

    0xf71a62d1,// 69 PAY  32 

    0x34f851cc,// 70 PAY  33 

    0x6ea311d9,// 71 PAY  34 

    0xc1ca12b9,// 72 PAY  35 

    0xe9f8b1a1,// 73 PAY  36 

    0x822f3c6f,// 74 PAY  37 

    0x6165d521,// 75 PAY  38 

    0xc763df63,// 76 PAY  39 

    0x0573203d,// 77 PAY  40 

    0x8c66cfa3,// 78 PAY  41 

    0xcba1ffaf,// 79 PAY  42 

    0x0158d090,// 80 PAY  43 

    0x4a29d551,// 81 PAY  44 

    0x2c9d4a1d,// 82 PAY  45 

    0xa12df3e0,// 83 PAY  46 

    0x2fa5b4d2,// 84 PAY  47 

    0x78ae221d,// 85 PAY  48 

    0xeaa853b9,// 86 PAY  49 

    0x923bb4ef,// 87 PAY  50 

    0x1b1313aa,// 88 PAY  51 

    0x85c93893,// 89 PAY  52 

    0xc5dc275f,// 90 PAY  53 

    0xb3289328,// 91 PAY  54 

    0x101560e0,// 92 PAY  55 

    0x97063835,// 93 PAY  56 

    0xe553a50a,// 94 PAY  57 

    0xe66f2cbf,// 95 PAY  58 

    0x432d1b8b,// 96 PAY  59 

    0x6822bf05,// 97 PAY  60 

    0x21286d47,// 98 PAY  61 

    0x77e933d0,// 99 PAY  62 

    0x858db6e8,// 100 PAY  63 

    0xf37f63c8,// 101 PAY  64 

    0xe5661333,// 102 PAY  65 

    0xe4976bfc,// 103 PAY  66 

    0xcaf747db,// 104 PAY  67 

    0xa64db82f,// 105 PAY  68 

    0x1166b3e4,// 106 PAY  69 

    0x9ccdc58f,// 107 PAY  70 

    0xba5a12f1,// 108 PAY  71 

    0xc618bf1b,// 109 PAY  72 

    0xcc36cc3d,// 110 PAY  73 

    0xbf72bc77,// 111 PAY  74 

    0x52ed55c0,// 112 PAY  75 

    0x8e1ab105,// 113 PAY  76 

    0x3688dd13,// 114 PAY  77 

    0xb6179283,// 115 PAY  78 

    0x2607c980,// 116 PAY  79 

    0x55db37f6,// 117 PAY  80 

    0xc5995747,// 118 PAY  81 

    0x3c698a25,// 119 PAY  82 

    0xd20a0a5a,// 120 PAY  83 

    0x6fd67a34,// 121 PAY  84 

    0x824930a4,// 122 PAY  85 

    0x5557f5aa,// 123 PAY  86 

    0x190428ad,// 124 PAY  87 

    0x735a3ba3,// 125 PAY  88 

    0x671d47a2,// 126 PAY  89 

    0x25254f7b,// 127 PAY  90 

    0xe260a675,// 128 PAY  91 

    0xa7093243,// 129 PAY  92 

    0x14e9490b,// 130 PAY  93 

    0xddcd86f4,// 131 PAY  94 

    0xad681ec2,// 132 PAY  95 

    0xd0adfa14,// 133 PAY  96 

    0x2f2d20b9,// 134 PAY  97 

    0x28cfae69,// 135 PAY  98 

    0xb35a4a74,// 136 PAY  99 

    0x795b0c26,// 137 PAY 100 

    0x1115658f,// 138 PAY 101 

    0xb49b1aac,// 139 PAY 102 

    0x978841c0,// 140 PAY 103 

    0x391fb94c,// 141 PAY 104 

    0x72967f67,// 142 PAY 105 

    0x6f15c1e3,// 143 PAY 106 

    0xf04e556d,// 144 PAY 107 

    0xd3dd8314,// 145 PAY 108 

    0x8f3fe05f,// 146 PAY 109 

    0xb63df964,// 147 PAY 110 

    0x0ad9cf57,// 148 PAY 111 

    0x071785be,// 149 PAY 112 

    0x689f0803,// 150 PAY 113 

    0xe7a23c43,// 151 PAY 114 

    0xfbcde3af,// 152 PAY 115 

    0x2ffd489c,// 153 PAY 116 

    0x6e5ba174,// 154 PAY 117 

    0x8dbc916e,// 155 PAY 118 

    0x4acd687b,// 156 PAY 119 

    0xea989e2d,// 157 PAY 120 

    0x02650c62,// 158 PAY 121 

    0x02a46c61,// 159 PAY 122 

    0x5cd7b506,// 160 PAY 123 

    0xd6b3d156,// 161 PAY 124 

    0xc133b6b5,// 162 PAY 125 

    0x88a58306,// 163 PAY 126 

    0x0d7e8d5a,// 164 PAY 127 

    0x4df92ef1,// 165 PAY 128 

    0x695c3305,// 166 PAY 129 

    0xa263ae94,// 167 PAY 130 

    0x65cbdbfe,// 168 PAY 131 

    0x1cfcbaf5,// 169 PAY 132 

    0xac324cd3,// 170 PAY 133 

    0x02ab6017,// 171 PAY 134 

    0x123458c3,// 172 PAY 135 

    0xd240a84a,// 173 PAY 136 

    0x1a706150,// 174 PAY 137 

    0xffcb737c,// 175 PAY 138 

    0xe8aa824d,// 176 PAY 139 

    0x8c3bc5df,// 177 PAY 140 

    0x7ee74647,// 178 PAY 141 

    0xa120db3d,// 179 PAY 142 

    0x93c132c8,// 180 PAY 143 

    0x1bdad2db,// 181 PAY 144 

    0xdbb0530f,// 182 PAY 145 

    0xdc7f8239,// 183 PAY 146 

    0xd704ef46,// 184 PAY 147 

    0x383d0f21,// 185 PAY 148 

    0xf1530a66,// 186 PAY 149 

    0x459bc656,// 187 PAY 150 

    0x12ab6882,// 188 PAY 151 

    0x83e68c34,// 189 PAY 152 

    0xf36ead2c,// 190 PAY 153 

    0x1789e979,// 191 PAY 154 

    0xaad83033,// 192 PAY 155 

    0x591d8383,// 193 PAY 156 

    0x51b019b2,// 194 PAY 157 

    0x3530a378,// 195 PAY 158 

    0xd9bca042,// 196 PAY 159 

    0x43546c89,// 197 PAY 160 

    0x72883e5b,// 198 PAY 161 

    0x3df9bc6d,// 199 PAY 162 

    0x3e62106b,// 200 PAY 163 

    0x3bab668b,// 201 PAY 164 

    0x9f316da3,// 202 PAY 165 

    0xfdb9f9c1,// 203 PAY 166 

    0xd47029aa,// 204 PAY 167 

    0x7bc224b6,// 205 PAY 168 

    0x3403f204,// 206 PAY 169 

    0x9d913e19,// 207 PAY 170 

    0xd1f3cd33,// 208 PAY 171 

    0xbba50415,// 209 PAY 172 

    0x479661f2,// 210 PAY 173 

    0xa9788e12,// 211 PAY 174 

    0x1b63eaf4,// 212 PAY 175 

    0x2c496e0c,// 213 PAY 176 

    0x5d652ac1,// 214 PAY 177 

    0x6ae5b1cb,// 215 PAY 178 

    0x63166c1f,// 216 PAY 179 

    0x5479d3bd,// 217 PAY 180 

    0xd75f6a09,// 218 PAY 181 

    0xd672a6fb,// 219 PAY 182 

    0xf9725a36,// 220 PAY 183 

    0x2ac73d3c,// 221 PAY 184 

    0x8a132e09,// 222 PAY 185 

    0x5bcea841,// 223 PAY 186 

    0x01aa7054,// 224 PAY 187 

    0x6116d656,// 225 PAY 188 

    0x13ee6e97,// 226 PAY 189 

    0xb9cb38ee,// 227 PAY 190 

    0x75560fa4,// 228 PAY 191 

    0x533d43af,// 229 PAY 192 

    0xf3b7d6d8,// 230 PAY 193 

    0xa8fed6c8,// 231 PAY 194 

    0x4c56435b,// 232 PAY 195 

    0x8673a81b,// 233 PAY 196 

    0x21d478dd,// 234 PAY 197 

    0xb9d8f177,// 235 PAY 198 

    0xe7f6624f,// 236 PAY 199 

    0x66237fd2,// 237 PAY 200 

    0x0f007868,// 238 PAY 201 

    0x327005f7,// 239 PAY 202 

    0xb9629fed,// 240 PAY 203 

    0x3d8958bb,// 241 PAY 204 

    0xc8a929bf,// 242 PAY 205 

    0x9241cb21,// 243 PAY 206 

    0xb67b02e6,// 244 PAY 207 

    0x4205147d,// 245 PAY 208 

    0xc6b32bc0,// 246 PAY 209 

    0xd7bffb65,// 247 PAY 210 

    0x7218f993,// 248 PAY 211 

    0x871f4051,// 249 PAY 212 

    0x68e597e4,// 250 PAY 213 

    0x1617e05e,// 251 PAY 214 

    0x06d6503b,// 252 PAY 215 

    0x19ad1f0e,// 253 PAY 216 

    0xc9894505,// 254 PAY 217 

    0x8cd2f4e1,// 255 PAY 218 

    0x185fc4ae,// 256 PAY 219 

    0x5eff080d,// 257 PAY 220 

    0x5c116161,// 258 PAY 221 

    0xf6074817,// 259 PAY 222 

    0xe38c719d,// 260 PAY 223 

    0x566960eb,// 261 PAY 224 

    0x33b75923,// 262 PAY 225 

    0x0c9c2617,// 263 PAY 226 

    0x860fdff0,// 264 PAY 227 

    0x5d10afb5,// 265 PAY 228 

    0x4a32de29,// 266 PAY 229 

    0xb20064ba,// 267 PAY 230 

    0xf386bb4d,// 268 PAY 231 

    0xdecd822c,// 269 PAY 232 

    0x3a2a47c8,// 270 PAY 233 

    0xb2c2fde6,// 271 PAY 234 

    0xba0565ac,// 272 PAY 235 

    0x8446cf89,// 273 PAY 236 

    0xeb076d6b,// 274 PAY 237 

    0x3946d919,// 275 PAY 238 

    0x219609f4,// 276 PAY 239 

    0xc9d20cc0,// 277 PAY 240 

    0x88649a40,// 278 PAY 241 

    0x435fa74e,// 279 PAY 242 

    0xd7b40245,// 280 PAY 243 

    0xac1743ec,// 281 PAY 244 

    0x83ac49b8,// 282 PAY 245 

    0xd962b52e,// 283 PAY 246 

    0x938de42e,// 284 PAY 247 

    0x45d95a9e,// 285 PAY 248 

    0x5e4cb814,// 286 PAY 249 

    0x2ffc585f,// 287 PAY 250 

    0xb562fbca,// 288 PAY 251 

    0x88101bc2,// 289 PAY 252 

    0xd5269696,// 290 PAY 253 

    0xdbfd0caa,// 291 PAY 254 

    0x88a8acdf,// 292 PAY 255 

    0xd7b06c61,// 293 PAY 256 

    0x857ca23b,// 294 PAY 257 

    0x6f30750e,// 295 PAY 258 

    0x1aa8710a,// 296 PAY 259 

    0xd0f8fa27,// 297 PAY 260 

    0xad35d087,// 298 PAY 261 

    0x8a86c981,// 299 PAY 262 

    0xf96d5bd0,// 300 PAY 263 

    0xbabf590b,// 301 PAY 264 

    0x0e515798,// 302 PAY 265 

    0x26edf6f4,// 303 PAY 266 

    0x48a445b4,// 304 PAY 267 

    0xaf6b4304,// 305 PAY 268 

    0x147461c3,// 306 PAY 269 

    0x4d5ce15b,// 307 PAY 270 

    0x2c2fb6e4,// 308 PAY 271 

    0x1c1d8152,// 309 PAY 272 

    0x937b0695,// 310 PAY 273 

    0x7b84aec2,// 311 PAY 274 

    0xd0acaa50,// 312 PAY 275 

    0x3160b9b4,// 313 PAY 276 

    0xd1637ee1,// 314 PAY 277 

    0x649e91a7,// 315 PAY 278 

    0x4c4d3a53,// 316 PAY 279 

    0x29b09e40,// 317 PAY 280 

    0x879146f8,// 318 PAY 281 

    0x1498ce15,// 319 PAY 282 

    0x539ee5d0,// 320 PAY 283 

    0xa4ce7012,// 321 PAY 284 

    0xcdb17147,// 322 PAY 285 

    0x741f9aa3,// 323 PAY 286 

    0x9799f3de,// 324 PAY 287 

    0xe3fe30ee,// 325 PAY 288 

    0xbdf9268b,// 326 PAY 289 

    0x7c9366aa,// 327 PAY 290 

    0x2cff9627,// 328 PAY 291 

    0xcbb27243,// 329 PAY 292 

    0x5d4eb75d,// 330 PAY 293 

    0x6187d7ce,// 331 PAY 294 

    0xf32f2421,// 332 PAY 295 

    0xb92d6916,// 333 PAY 296 

    0x89c3aba1,// 334 PAY 297 

    0x88012814,// 335 PAY 298 

    0xa9cd40b3,// 336 PAY 299 

    0xc0dcf22d,// 337 PAY 300 

    0xf363f104,// 338 PAY 301 

    0x88adb20b,// 339 PAY 302 

    0xc1aab0d0,// 340 PAY 303 

    0x5aee5a83,// 341 PAY 304 

    0x4f2f2ca4,// 342 PAY 305 

    0x165cff6b,// 343 PAY 306 

    0x4354b363,// 344 PAY 307 

    0xdbbfb0dc,// 345 PAY 308 

    0xe2ceeb89,// 346 PAY 309 

    0x1d868847,// 347 PAY 310 

    0x964b55e6,// 348 PAY 311 

    0x99f6863a,// 349 PAY 312 

    0xa4e8d054,// 350 PAY 313 

    0xd6ac9b46,// 351 PAY 314 

    0xa27b8e8d,// 352 PAY 315 

    0x22bddb1e,// 353 PAY 316 

    0x684bfaea,// 354 PAY 317 

    0x1aa16efb,// 355 PAY 318 

    0x5b18c62f,// 356 PAY 319 

    0x8187b169,// 357 PAY 320 

    0x283edea1,// 358 PAY 321 

    0x8f387c54,// 359 PAY 322 

    0xee1d3deb,// 360 PAY 323 

    0x6f49913b,// 361 PAY 324 

    0xf9c7d719,// 362 PAY 325 

    0x43a05236,// 363 PAY 326 

    0x997cefb4,// 364 PAY 327 

    0xcbb78675,// 365 PAY 328 

    0xa6fe100e,// 366 PAY 329 

    0x721fe482,// 367 PAY 330 

    0x2dc238a1,// 368 PAY 331 

    0xd6fc5c88,// 369 PAY 332 

    0xe60548e3,// 370 PAY 333 

    0x576bbddd,// 371 PAY 334 

    0x229c631a,// 372 PAY 335 

    0xef47c616,// 373 PAY 336 

    0x4e524b9a,// 374 PAY 337 

    0xce60d34e,// 375 PAY 338 

    0x5ae37df6,// 376 PAY 339 

    0xb48babfe,// 377 PAY 340 

    0x1ec2901b,// 378 PAY 341 

    0x82418720,// 379 PAY 342 

    0xccdf3a00,// 380 PAY 343 

/// STA is 1 words. 

/// STA num_pkts       : 230 

/// STA pkt_idx        : 23 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x5b 

    0x005c5be6 // 381 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt21_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x80812811,// 4 SCX   2 

    0x00003200,// 5 SCX   3 

    0xbb1b0f32,// 6 SCX   4 

    0x81137322,// 7 SCX   5 

    0x30f13512,// 8 SCX   6 

    0x316fbac1,// 9 SCX   7 

    0xbb22197c,// 10 SCX   8 

    0x57dedb2b,// 11 SCX   9 

    0x8f54cafa,// 12 SCX  10 

    0xab1c2ea3,// 13 SCX  11 

    0xaf7328eb,// 14 SCX  12 

    0x42702c55,// 15 SCX  13 

    0x4405df01,// 16 SCX  14 

    0x5cbfc1a4,// 17 SCX  15 

    0xc75ca77c,// 18 SCX  16 

    0xa338485e,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 657 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 625 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 625 

/// BFD lencrypto      : 272 

/// BFD ofstcrypto     : 200 

/// BFD (ofst+len)cry  : 472 

/// BFD ofstiv         : 168 

/// BFD ofsticv        : 628 

    0x00000271,// 20 BFD   1 

    0x00c80110,// 21 BFD   2 

    0x027400a8,// 22 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 9 

    0x09000e92,// 23 MFM   1 

    0x85ff8000,// 24 MFM   2 

/// BDA is 166 words. 

/// BDA size     is 657 (0x291) 

/// BDA id       is 0xb7c2 

    0x0291b7c2,// 25 BDA   1 

/// PAY Generic Data size   : 657 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0xd39d58e4,// 26 PAY   1 

    0xec93b206,// 27 PAY   2 

    0xfe74367e,// 28 PAY   3 

    0x0c49e384,// 29 PAY   4 

    0x03f5dc31,// 30 PAY   5 

    0xe3c55f58,// 31 PAY   6 

    0xf2be7827,// 32 PAY   7 

    0x337a8bfe,// 33 PAY   8 

    0x249a0829,// 34 PAY   9 

    0x94daab8f,// 35 PAY  10 

    0x694bec04,// 36 PAY  11 

    0x55d7730a,// 37 PAY  12 

    0x0ccfa987,// 38 PAY  13 

    0xcfbe6740,// 39 PAY  14 

    0x9e6aacbb,// 40 PAY  15 

    0xb3a05e84,// 41 PAY  16 

    0x9e864f8c,// 42 PAY  17 

    0x997a1c28,// 43 PAY  18 

    0x8e4dc43f,// 44 PAY  19 

    0xb796f675,// 45 PAY  20 

    0x42fcfac9,// 46 PAY  21 

    0xdb841240,// 47 PAY  22 

    0x32158ceb,// 48 PAY  23 

    0x1388a7b0,// 49 PAY  24 

    0x1db4e89f,// 50 PAY  25 

    0xfae8b053,// 51 PAY  26 

    0x72d6a494,// 52 PAY  27 

    0x7a888211,// 53 PAY  28 

    0xd4f001ff,// 54 PAY  29 

    0xb03bb15b,// 55 PAY  30 

    0xfcdca00d,// 56 PAY  31 

    0xec100f07,// 57 PAY  32 

    0xa8d1ab2a,// 58 PAY  33 

    0xda92d6a3,// 59 PAY  34 

    0xdc94fa65,// 60 PAY  35 

    0xc2862308,// 61 PAY  36 

    0x6f05fe6f,// 62 PAY  37 

    0x30693c3c,// 63 PAY  38 

    0x693a0547,// 64 PAY  39 

    0x84a03107,// 65 PAY  40 

    0x4d06b568,// 66 PAY  41 

    0x4b753da1,// 67 PAY  42 

    0x22739ed9,// 68 PAY  43 

    0xe0ec030b,// 69 PAY  44 

    0xfa87d803,// 70 PAY  45 

    0x2d8d57fa,// 71 PAY  46 

    0x19181aad,// 72 PAY  47 

    0x5a56945b,// 73 PAY  48 

    0x13338dd4,// 74 PAY  49 

    0x820527e7,// 75 PAY  50 

    0x26b1ea3b,// 76 PAY  51 

    0x489b290e,// 77 PAY  52 

    0xa9062702,// 78 PAY  53 

    0x7bbeea67,// 79 PAY  54 

    0x44095435,// 80 PAY  55 

    0xd2b8062d,// 81 PAY  56 

    0x982faf2c,// 82 PAY  57 

    0xdf544bfa,// 83 PAY  58 

    0xfced19da,// 84 PAY  59 

    0x8bdb4102,// 85 PAY  60 

    0x749cfc8e,// 86 PAY  61 

    0x6cb32a72,// 87 PAY  62 

    0xeb23d66d,// 88 PAY  63 

    0x27777d3f,// 89 PAY  64 

    0x3fa254fe,// 90 PAY  65 

    0x0259bae3,// 91 PAY  66 

    0x08b0e095,// 92 PAY  67 

    0xfd8b300a,// 93 PAY  68 

    0xd3844ea7,// 94 PAY  69 

    0xada7fb50,// 95 PAY  70 

    0x3ce7e52c,// 96 PAY  71 

    0xb050d4f5,// 97 PAY  72 

    0x196aa88c,// 98 PAY  73 

    0xb6e0ac03,// 99 PAY  74 

    0x36f6490b,// 100 PAY  75 

    0x718ec3b4,// 101 PAY  76 

    0x573faa3d,// 102 PAY  77 

    0x43562ead,// 103 PAY  78 

    0x40cb8994,// 104 PAY  79 

    0xfecd0047,// 105 PAY  80 

    0x5ffc72c9,// 106 PAY  81 

    0x0f7f370b,// 107 PAY  82 

    0x6c456a79,// 108 PAY  83 

    0xea70832c,// 109 PAY  84 

    0x62af336b,// 110 PAY  85 

    0xe8dc5578,// 111 PAY  86 

    0xfa8ae655,// 112 PAY  87 

    0xc2019e95,// 113 PAY  88 

    0x5482823f,// 114 PAY  89 

    0xe338e933,// 115 PAY  90 

    0x2dc1f7cf,// 116 PAY  91 

    0x0cdd95af,// 117 PAY  92 

    0x73d05f44,// 118 PAY  93 

    0x71e4ef17,// 119 PAY  94 

    0x12de9886,// 120 PAY  95 

    0x0f54857e,// 121 PAY  96 

    0xa4145082,// 122 PAY  97 

    0x9f445714,// 123 PAY  98 

    0xcfec2cf1,// 124 PAY  99 

    0x1c287d7e,// 125 PAY 100 

    0x7b0ce08d,// 126 PAY 101 

    0x2146a40a,// 127 PAY 102 

    0x62d0a2e2,// 128 PAY 103 

    0xdf02522b,// 129 PAY 104 

    0x17455107,// 130 PAY 105 

    0xf2c229f4,// 131 PAY 106 

    0x7f2bbb4c,// 132 PAY 107 

    0xfea8ea8b,// 133 PAY 108 

    0xa2b7b4ae,// 134 PAY 109 

    0xb39ec183,// 135 PAY 110 

    0xbe0a1337,// 136 PAY 111 

    0xc5edac87,// 137 PAY 112 

    0x9fdd454d,// 138 PAY 113 

    0x29990a4e,// 139 PAY 114 

    0xbcb38d5e,// 140 PAY 115 

    0x15c3e539,// 141 PAY 116 

    0x8058def5,// 142 PAY 117 

    0xd3b89828,// 143 PAY 118 

    0x9f6be015,// 144 PAY 119 

    0xe97f22c1,// 145 PAY 120 

    0x2daaab9a,// 146 PAY 121 

    0xd9802642,// 147 PAY 122 

    0xdde8db0f,// 148 PAY 123 

    0x459c16d0,// 149 PAY 124 

    0x949fede1,// 150 PAY 125 

    0xa76db7ff,// 151 PAY 126 

    0x65322624,// 152 PAY 127 

    0xb5e876ef,// 153 PAY 128 

    0xd4fb1f35,// 154 PAY 129 

    0x9db28f1b,// 155 PAY 130 

    0x50e11dd4,// 156 PAY 131 

    0x46c5ef59,// 157 PAY 132 

    0xc5563eeb,// 158 PAY 133 

    0xbe29f1b7,// 159 PAY 134 

    0x83fd5235,// 160 PAY 135 

    0x75ae0dd0,// 161 PAY 136 

    0xea5cfdc9,// 162 PAY 137 

    0x9a370096,// 163 PAY 138 

    0x3b629971,// 164 PAY 139 

    0x3762a006,// 165 PAY 140 

    0x34078911,// 166 PAY 141 

    0x33640863,// 167 PAY 142 

    0x86b9fbed,// 168 PAY 143 

    0xf101ad42,// 169 PAY 144 

    0x3951b858,// 170 PAY 145 

    0xf2294e1f,// 171 PAY 146 

    0x44002da8,// 172 PAY 147 

    0xa95581f8,// 173 PAY 148 

    0x77a13cbc,// 174 PAY 149 

    0xcedc51f9,// 175 PAY 150 

    0xa3ff783d,// 176 PAY 151 

    0x7f746c4d,// 177 PAY 152 

    0x20114669,// 178 PAY 153 

    0x6f0ac427,// 179 PAY 154 

    0x13dc447f,// 180 PAY 155 

    0x65d29eb8,// 181 PAY 156 

    0x0b7bfa9f,// 182 PAY 157 

    0xd7830d63,// 183 PAY 158 

    0x8eb837b6,// 184 PAY 159 

    0xe9b3b39c,// 185 PAY 160 

    0x6805f38f,// 186 PAY 161 

    0xffbeee53,// 187 PAY 162 

    0xbaa216c3,// 188 PAY 163 

    0xe49e4c31,// 189 PAY 164 

    0xb1000000,// 190 PAY 165 

/// STA is 1 words. 

/// STA num_pkts       : 133 

/// STA pkt_idx        : 59 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x14 

    0x00ec1485 // 191 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt22_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x808028e0,// 4 SCX   2 

    0x00002100,// 5 SCX   3 

    0x603a58c9,// 6 SCX   4 

    0x761f9780,// 7 SCX   5 

    0xa3ce17ab,// 8 SCX   6 

    0x8ac270cd,// 9 SCX   7 

    0xadfd9c0c,// 10 SCX   8 

    0xf6c9867d,// 11 SCX   9 

    0x7f7bb2da,// 12 SCX  10 

    0x8f55a53f,// 13 SCX  11 

    0x7f777c9d,// 14 SCX  12 

    0x7b953b19,// 15 SCX  13 

    0x90cef32c,// 16 SCX  14 

    0x686bed40,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1837 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 291 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 291 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 220 

/// BFD (ofst+len)cry  : 252 

/// BFD ofstiv         : 140 

/// BFD ofsticv        : 380 

    0x00000123,// 18 BFD   1 

    0x00dc0020,// 19 BFD   2 

    0x017c008c,// 20 BFD   3 

/// MFM is 8 words. 

/// MFM vldnibs        : 3a 

    0x3a001c58,// 21 MFM   1 

    0x534b2435,// 22 MFM   2 

    0xb2d18329,// 23 MFM   3 

    0x37a06238,// 24 MFM   4 

    0x1f449a78,// 25 MFM   5 

    0x23580322,// 26 MFM   6 

    0x3630716a,// 27 MFM   7 

    0xbfbfc600,// 28 MFM   8 

/// BDA is 461 words. 

/// BDA size     is 1837 (0x72d) 

/// BDA id       is 0x393e 

    0x072d393e,// 29 BDA   1 

/// PAY Generic Data size   : 1837 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x1647e421,// 30 PAY   1 

    0x5ced6fe4,// 31 PAY   2 

    0xffc8ebe3,// 32 PAY   3 

    0x8200bbc0,// 33 PAY   4 

    0x577aa2bb,// 34 PAY   5 

    0x4a2808cd,// 35 PAY   6 

    0x06afcb35,// 36 PAY   7 

    0x14a0bb5b,// 37 PAY   8 

    0xb3ba0fc9,// 38 PAY   9 

    0xc5e90469,// 39 PAY  10 

    0x77a756e8,// 40 PAY  11 

    0xd48b61b4,// 41 PAY  12 

    0x0829650b,// 42 PAY  13 

    0x011084c1,// 43 PAY  14 

    0x8d73b55d,// 44 PAY  15 

    0xe86c1d0a,// 45 PAY  16 

    0x508f99d2,// 46 PAY  17 

    0xd81c644d,// 47 PAY  18 

    0xa964ab09,// 48 PAY  19 

    0xaf7f7cac,// 49 PAY  20 

    0x8b9c7225,// 50 PAY  21 

    0x3ce1c5b1,// 51 PAY  22 

    0xb33eeca8,// 52 PAY  23 

    0x32d9b605,// 53 PAY  24 

    0x2a686709,// 54 PAY  25 

    0xa7d3608b,// 55 PAY  26 

    0x6ffffbb6,// 56 PAY  27 

    0xf06571bc,// 57 PAY  28 

    0x8d5e357d,// 58 PAY  29 

    0xf0759a57,// 59 PAY  30 

    0xf41d18a2,// 60 PAY  31 

    0x97f3aea4,// 61 PAY  32 

    0x7fabaf00,// 62 PAY  33 

    0x6d0d4f1c,// 63 PAY  34 

    0x686e60d9,// 64 PAY  35 

    0x84df4139,// 65 PAY  36 

    0xb4215f0c,// 66 PAY  37 

    0x2a3f1288,// 67 PAY  38 

    0x37d7bf38,// 68 PAY  39 

    0x30918ac1,// 69 PAY  40 

    0x0623e415,// 70 PAY  41 

    0x95d65601,// 71 PAY  42 

    0xfb21c274,// 72 PAY  43 

    0x3c91372c,// 73 PAY  44 

    0xaf3d5857,// 74 PAY  45 

    0x4feb6f9d,// 75 PAY  46 

    0x15ae5c51,// 76 PAY  47 

    0x3f069ede,// 77 PAY  48 

    0xbe206015,// 78 PAY  49 

    0x38ea7a2f,// 79 PAY  50 

    0x70dd96bf,// 80 PAY  51 

    0x5ef67eb6,// 81 PAY  52 

    0x673c3a1d,// 82 PAY  53 

    0xaaaf859d,// 83 PAY  54 

    0x404f00dd,// 84 PAY  55 

    0xa8431557,// 85 PAY  56 

    0x282a90bf,// 86 PAY  57 

    0xe882e99f,// 87 PAY  58 

    0xb79dd906,// 88 PAY  59 

    0xe5bd6bfd,// 89 PAY  60 

    0xadafd182,// 90 PAY  61 

    0xc1c8c1fa,// 91 PAY  62 

    0x90959b6c,// 92 PAY  63 

    0xf03554f9,// 93 PAY  64 

    0x911c3372,// 94 PAY  65 

    0x75609b12,// 95 PAY  66 

    0xc45394da,// 96 PAY  67 

    0xbe5a77bb,// 97 PAY  68 

    0x68e1b125,// 98 PAY  69 

    0xe8ca2ff2,// 99 PAY  70 

    0x969c984c,// 100 PAY  71 

    0x617e896a,// 101 PAY  72 

    0x5453dd02,// 102 PAY  73 

    0xd07eadb5,// 103 PAY  74 

    0x628fbd92,// 104 PAY  75 

    0xe2334ce6,// 105 PAY  76 

    0x69b0f45e,// 106 PAY  77 

    0xb023ec22,// 107 PAY  78 

    0xbaaac8a4,// 108 PAY  79 

    0xb24bf1fa,// 109 PAY  80 

    0x9b07bbec,// 110 PAY  81 

    0xb4e71d5e,// 111 PAY  82 

    0x677f9ae1,// 112 PAY  83 

    0xa8aaf166,// 113 PAY  84 

    0x3d733474,// 114 PAY  85 

    0x2e896a27,// 115 PAY  86 

    0xc5961ff4,// 116 PAY  87 

    0x71eb172c,// 117 PAY  88 

    0xb5464e7a,// 118 PAY  89 

    0xb146254c,// 119 PAY  90 

    0x0be7167b,// 120 PAY  91 

    0xe1ca4925,// 121 PAY  92 

    0x31099856,// 122 PAY  93 

    0x037fc050,// 123 PAY  94 

    0x7b0c3de5,// 124 PAY  95 

    0x2d7cc408,// 125 PAY  96 

    0x2cec87d0,// 126 PAY  97 

    0xc0a81cff,// 127 PAY  98 

    0x77bff8fa,// 128 PAY  99 

    0x17c5a9c3,// 129 PAY 100 

    0xf08efc5f,// 130 PAY 101 

    0x5d630f2c,// 131 PAY 102 

    0x001bf8af,// 132 PAY 103 

    0xac37e72f,// 133 PAY 104 

    0x5e5c92f0,// 134 PAY 105 

    0x60c262ce,// 135 PAY 106 

    0x299c856a,// 136 PAY 107 

    0xde751b00,// 137 PAY 108 

    0xd781fa0c,// 138 PAY 109 

    0x2d225238,// 139 PAY 110 

    0x7d969539,// 140 PAY 111 

    0x311f0776,// 141 PAY 112 

    0x41cca1c5,// 142 PAY 113 

    0x66b1f3b2,// 143 PAY 114 

    0x00035f6c,// 144 PAY 115 

    0x3f40ae7d,// 145 PAY 116 

    0x8e5a2883,// 146 PAY 117 

    0x52a72a68,// 147 PAY 118 

    0x7e0448c2,// 148 PAY 119 

    0x1dbb6f54,// 149 PAY 120 

    0x87b8f252,// 150 PAY 121 

    0xdf74ccb5,// 151 PAY 122 

    0xf01aece0,// 152 PAY 123 

    0xce910edf,// 153 PAY 124 

    0xea7189e6,// 154 PAY 125 

    0x39fd8e71,// 155 PAY 126 

    0x8a68b291,// 156 PAY 127 

    0x051f4be6,// 157 PAY 128 

    0xb86e5100,// 158 PAY 129 

    0x58ee5a9d,// 159 PAY 130 

    0x7f5b3c13,// 160 PAY 131 

    0xe7ac4ae5,// 161 PAY 132 

    0xd30e998a,// 162 PAY 133 

    0xa28bc26b,// 163 PAY 134 

    0x4c89273a,// 164 PAY 135 

    0x697d7799,// 165 PAY 136 

    0x66ccb59f,// 166 PAY 137 

    0x312f8fee,// 167 PAY 138 

    0x43e14167,// 168 PAY 139 

    0x174c593f,// 169 PAY 140 

    0x9f6388fd,// 170 PAY 141 

    0x72518823,// 171 PAY 142 

    0x79b31a8e,// 172 PAY 143 

    0x39210a39,// 173 PAY 144 

    0xdd567df4,// 174 PAY 145 

    0xb3a723a0,// 175 PAY 146 

    0x60682bae,// 176 PAY 147 

    0x00104eac,// 177 PAY 148 

    0x15b7fe6b,// 178 PAY 149 

    0x27017cfb,// 179 PAY 150 

    0x344e1b63,// 180 PAY 151 

    0x287f0ccc,// 181 PAY 152 

    0x0488daa6,// 182 PAY 153 

    0xe36d59f5,// 183 PAY 154 

    0xe7f9e8d7,// 184 PAY 155 

    0x9d0431ff,// 185 PAY 156 

    0xf6eb883f,// 186 PAY 157 

    0x405d0907,// 187 PAY 158 

    0x35fa8d49,// 188 PAY 159 

    0xd8746729,// 189 PAY 160 

    0x30d8d99a,// 190 PAY 161 

    0x54ba66c8,// 191 PAY 162 

    0xfc5a4767,// 192 PAY 163 

    0xa06b2451,// 193 PAY 164 

    0xbf583abf,// 194 PAY 165 

    0x345b27f0,// 195 PAY 166 

    0x7e4a3484,// 196 PAY 167 

    0x998a76c6,// 197 PAY 168 

    0x4bc848e8,// 198 PAY 169 

    0x991442db,// 199 PAY 170 

    0xa6bf383f,// 200 PAY 171 

    0x4e1805d3,// 201 PAY 172 

    0x8035d3f0,// 202 PAY 173 

    0x12542c81,// 203 PAY 174 

    0x8ba1be5e,// 204 PAY 175 

    0xd38dd776,// 205 PAY 176 

    0x9b762f67,// 206 PAY 177 

    0x6e6c3a88,// 207 PAY 178 

    0x67c7cab5,// 208 PAY 179 

    0xb6fd3871,// 209 PAY 180 

    0x6578814f,// 210 PAY 181 

    0xb20a3ad9,// 211 PAY 182 

    0xa0538979,// 212 PAY 183 

    0x4bcae715,// 213 PAY 184 

    0xcf4206ff,// 214 PAY 185 

    0xa9650f4d,// 215 PAY 186 

    0x0be14807,// 216 PAY 187 

    0xb699add0,// 217 PAY 188 

    0x0c1370f0,// 218 PAY 189 

    0x0d657406,// 219 PAY 190 

    0xf66d4d56,// 220 PAY 191 

    0xd3811d15,// 221 PAY 192 

    0xb70bf9e5,// 222 PAY 193 

    0xc94f762f,// 223 PAY 194 

    0x39472537,// 224 PAY 195 

    0x5810b237,// 225 PAY 196 

    0x9d2dc83f,// 226 PAY 197 

    0xff723934,// 227 PAY 198 

    0x5ed0a9f8,// 228 PAY 199 

    0x77432a99,// 229 PAY 200 

    0x2a9cd6a7,// 230 PAY 201 

    0xddd5395f,// 231 PAY 202 

    0xf3491411,// 232 PAY 203 

    0x330bf069,// 233 PAY 204 

    0xa882fe58,// 234 PAY 205 

    0x6050c341,// 235 PAY 206 

    0x5b31081b,// 236 PAY 207 

    0x9dc60229,// 237 PAY 208 

    0xd0f74657,// 238 PAY 209 

    0xf6897922,// 239 PAY 210 

    0xef38af1e,// 240 PAY 211 

    0x606a2593,// 241 PAY 212 

    0xdac17db5,// 242 PAY 213 

    0x2a6d1b33,// 243 PAY 214 

    0x64246ac5,// 244 PAY 215 

    0x8509b214,// 245 PAY 216 

    0x654a4e17,// 246 PAY 217 

    0x7f8dae34,// 247 PAY 218 

    0x65958ff2,// 248 PAY 219 

    0x89547358,// 249 PAY 220 

    0xfe09d8aa,// 250 PAY 221 

    0xd528a256,// 251 PAY 222 

    0x9718ff95,// 252 PAY 223 

    0xe0f9c121,// 253 PAY 224 

    0x93a6513a,// 254 PAY 225 

    0x8c8c215b,// 255 PAY 226 

    0xfbdee910,// 256 PAY 227 

    0x6d5122db,// 257 PAY 228 

    0x8f41a388,// 258 PAY 229 

    0x8096c2c0,// 259 PAY 230 

    0x8c9a1303,// 260 PAY 231 

    0x6170da90,// 261 PAY 232 

    0x3f9f78cf,// 262 PAY 233 

    0x486865e7,// 263 PAY 234 

    0x5adb27dd,// 264 PAY 235 

    0xc79cf186,// 265 PAY 236 

    0x11cdfb8b,// 266 PAY 237 

    0xad661dd8,// 267 PAY 238 

    0x5936fc34,// 268 PAY 239 

    0x21caba46,// 269 PAY 240 

    0x984d4d32,// 270 PAY 241 

    0xf4e58cee,// 271 PAY 242 

    0x2ca1245d,// 272 PAY 243 

    0x2112a6db,// 273 PAY 244 

    0x22d35153,// 274 PAY 245 

    0x55c565a8,// 275 PAY 246 

    0xa683790d,// 276 PAY 247 

    0x20aa784f,// 277 PAY 248 

    0xbe4e042d,// 278 PAY 249 

    0x6e39826a,// 279 PAY 250 

    0xf59c3d85,// 280 PAY 251 

    0xf11e4f92,// 281 PAY 252 

    0x65987f81,// 282 PAY 253 

    0x581ed466,// 283 PAY 254 

    0x8422aff4,// 284 PAY 255 

    0x9ef77b90,// 285 PAY 256 

    0xd7031968,// 286 PAY 257 

    0xd9311edd,// 287 PAY 258 

    0x042e7a4a,// 288 PAY 259 

    0x40463ece,// 289 PAY 260 

    0xcef41032,// 290 PAY 261 

    0xda1635ec,// 291 PAY 262 

    0xf24b8892,// 292 PAY 263 

    0x969d2394,// 293 PAY 264 

    0x4f42805d,// 294 PAY 265 

    0xdd02cbce,// 295 PAY 266 

    0x323b4de8,// 296 PAY 267 

    0xc5bfe153,// 297 PAY 268 

    0x59677f53,// 298 PAY 269 

    0x1971272f,// 299 PAY 270 

    0xf888b2d1,// 300 PAY 271 

    0x549f0130,// 301 PAY 272 

    0xbc7bcc7d,// 302 PAY 273 

    0x06ee1434,// 303 PAY 274 

    0xb512cd0a,// 304 PAY 275 

    0xbd4975fc,// 305 PAY 276 

    0xc2b9ab15,// 306 PAY 277 

    0x821e9022,// 307 PAY 278 

    0x5b1f400f,// 308 PAY 279 

    0x70c6893a,// 309 PAY 280 

    0x073f3144,// 310 PAY 281 

    0x54ca4045,// 311 PAY 282 

    0xfcd56674,// 312 PAY 283 

    0xc9a789b3,// 313 PAY 284 

    0xa37f4f3d,// 314 PAY 285 

    0x1c9e10bb,// 315 PAY 286 

    0x0d70ac7c,// 316 PAY 287 

    0x148efef1,// 317 PAY 288 

    0x342ab194,// 318 PAY 289 

    0x80954eed,// 319 PAY 290 

    0x78ed8a02,// 320 PAY 291 

    0x44a30a2e,// 321 PAY 292 

    0x68f5c8b7,// 322 PAY 293 

    0x71f6f0ce,// 323 PAY 294 

    0xc2d3ef51,// 324 PAY 295 

    0x2ba69f54,// 325 PAY 296 

    0x7d0ffd8b,// 326 PAY 297 

    0x4e6d7823,// 327 PAY 298 

    0x2610d34c,// 328 PAY 299 

    0x02601f68,// 329 PAY 300 

    0x4ca8fdeb,// 330 PAY 301 

    0xa77d82fc,// 331 PAY 302 

    0x7a20d08f,// 332 PAY 303 

    0xb4292589,// 333 PAY 304 

    0x2c6e9e13,// 334 PAY 305 

    0xa4549ab8,// 335 PAY 306 

    0x2063c6fe,// 336 PAY 307 

    0xc9437072,// 337 PAY 308 

    0x79bf7a3c,// 338 PAY 309 

    0x55306965,// 339 PAY 310 

    0x45dc215c,// 340 PAY 311 

    0x8161ed64,// 341 PAY 312 

    0x944e062b,// 342 PAY 313 

    0x470b6d1f,// 343 PAY 314 

    0x5f657715,// 344 PAY 315 

    0xd3a2373b,// 345 PAY 316 

    0x06b183ef,// 346 PAY 317 

    0x533c4e55,// 347 PAY 318 

    0x45be2f2f,// 348 PAY 319 

    0xd7cd0f28,// 349 PAY 320 

    0xba0ede6b,// 350 PAY 321 

    0x6a10fbdd,// 351 PAY 322 

    0xb8c9391b,// 352 PAY 323 

    0x8697d6d3,// 353 PAY 324 

    0x58e25449,// 354 PAY 325 

    0xd81dff35,// 355 PAY 326 

    0xdbcef21b,// 356 PAY 327 

    0x91cb5027,// 357 PAY 328 

    0x99eb09a7,// 358 PAY 329 

    0x72d28bda,// 359 PAY 330 

    0xc01b35a9,// 360 PAY 331 

    0x466b5fb8,// 361 PAY 332 

    0x1340233f,// 362 PAY 333 

    0xd369f718,// 363 PAY 334 

    0x8654d8a8,// 364 PAY 335 

    0xbd8fab43,// 365 PAY 336 

    0x4e0bb355,// 366 PAY 337 

    0xbea09dd0,// 367 PAY 338 

    0xbb304586,// 368 PAY 339 

    0x66489f19,// 369 PAY 340 

    0xc424f656,// 370 PAY 341 

    0xf0cf3bc4,// 371 PAY 342 

    0x436067a8,// 372 PAY 343 

    0x239ba9a0,// 373 PAY 344 

    0x184fb7c7,// 374 PAY 345 

    0xcafa2806,// 375 PAY 346 

    0xf651463d,// 376 PAY 347 

    0xbd266a29,// 377 PAY 348 

    0x0adad4e6,// 378 PAY 349 

    0x0a708604,// 379 PAY 350 

    0xa388d84a,// 380 PAY 351 

    0x7f3e5ac9,// 381 PAY 352 

    0xa9235e3d,// 382 PAY 353 

    0x9f644766,// 383 PAY 354 

    0x3fc2f870,// 384 PAY 355 

    0x18b28e39,// 385 PAY 356 

    0xb24085fe,// 386 PAY 357 

    0x54ab9ec9,// 387 PAY 358 

    0xc1e42fcf,// 388 PAY 359 

    0xa7f5f78f,// 389 PAY 360 

    0xf4f68a20,// 390 PAY 361 

    0x4ff5258b,// 391 PAY 362 

    0x62f30785,// 392 PAY 363 

    0xfcbc59fd,// 393 PAY 364 

    0x9194732e,// 394 PAY 365 

    0x918d2312,// 395 PAY 366 

    0xd4071d25,// 396 PAY 367 

    0x4da1f516,// 397 PAY 368 

    0x5fda0fff,// 398 PAY 369 

    0x3d148ca7,// 399 PAY 370 

    0xb7af6243,// 400 PAY 371 

    0xea359f05,// 401 PAY 372 

    0xe6a71070,// 402 PAY 373 

    0x4423a654,// 403 PAY 374 

    0xb74fe1fa,// 404 PAY 375 

    0x5710f972,// 405 PAY 376 

    0x285060b8,// 406 PAY 377 

    0xc1f9cd9e,// 407 PAY 378 

    0x16fc114b,// 408 PAY 379 

    0x164f9424,// 409 PAY 380 

    0x7985c763,// 410 PAY 381 

    0x46be21d2,// 411 PAY 382 

    0x5050db73,// 412 PAY 383 

    0x06cf6147,// 413 PAY 384 

    0x09849986,// 414 PAY 385 

    0x27b9e083,// 415 PAY 386 

    0x4bc76509,// 416 PAY 387 

    0xbe5a9b0d,// 417 PAY 388 

    0x1c369eaa,// 418 PAY 389 

    0xa4daf679,// 419 PAY 390 

    0x0eac445c,// 420 PAY 391 

    0x77b6ba68,// 421 PAY 392 

    0x10d3926b,// 422 PAY 393 

    0x07302b3d,// 423 PAY 394 

    0x81298184,// 424 PAY 395 

    0xed67f93e,// 425 PAY 396 

    0x4701f122,// 426 PAY 397 

    0xb27b78c0,// 427 PAY 398 

    0x986950f1,// 428 PAY 399 

    0x9a1fdd3c,// 429 PAY 400 

    0x9ecc6b88,// 430 PAY 401 

    0xc0861cca,// 431 PAY 402 

    0xb41d00b8,// 432 PAY 403 

    0xce4d5378,// 433 PAY 404 

    0x28474d3d,// 434 PAY 405 

    0xba2055ed,// 435 PAY 406 

    0xe8d87572,// 436 PAY 407 

    0x78c9b237,// 437 PAY 408 

    0x658e870f,// 438 PAY 409 

    0xff4c38ec,// 439 PAY 410 

    0x139d72af,// 440 PAY 411 

    0x98788bfe,// 441 PAY 412 

    0x87e10df9,// 442 PAY 413 

    0xa8d1cbc6,// 443 PAY 414 

    0x66a220a2,// 444 PAY 415 

    0x5677a240,// 445 PAY 416 

    0xff3646d7,// 446 PAY 417 

    0xcf0d9166,// 447 PAY 418 

    0x707caea4,// 448 PAY 419 

    0x1e8c0253,// 449 PAY 420 

    0xc1bde8eb,// 450 PAY 421 

    0xa96ea542,// 451 PAY 422 

    0x8231719b,// 452 PAY 423 

    0xcd030d0f,// 453 PAY 424 

    0xe795b0c7,// 454 PAY 425 

    0xa6075789,// 455 PAY 426 

    0x66beb8ae,// 456 PAY 427 

    0x47bcb5ef,// 457 PAY 428 

    0xcaf348c5,// 458 PAY 429 

    0x186eab1f,// 459 PAY 430 

    0x9c912e80,// 460 PAY 431 

    0x66246597,// 461 PAY 432 

    0xcfef2446,// 462 PAY 433 

    0x054baf42,// 463 PAY 434 

    0x82ffcebe,// 464 PAY 435 

    0x5f89a266,// 465 PAY 436 

    0x2a70f066,// 466 PAY 437 

    0xd9bcd426,// 467 PAY 438 

    0x5695f76f,// 468 PAY 439 

    0x9d6b51a5,// 469 PAY 440 

    0x2f8436f1,// 470 PAY 441 

    0xf7c5c118,// 471 PAY 442 

    0x3a88f334,// 472 PAY 443 

    0xc06997b0,// 473 PAY 444 

    0xb844737b,// 474 PAY 445 

    0xba54da40,// 475 PAY 446 

    0x7209cdf7,// 476 PAY 447 

    0x522a1da1,// 477 PAY 448 

    0x6dcefe4e,// 478 PAY 449 

    0x103d0ef6,// 479 PAY 450 

    0xee836d98,// 480 PAY 451 

    0x3df71394,// 481 PAY 452 

    0xd6bb9731,// 482 PAY 453 

    0x9b3401ec,// 483 PAY 454 

    0x652c83f2,// 484 PAY 455 

    0xa3ae86af,// 485 PAY 456 

    0xc0494f58,// 486 PAY 457 

    0xcb4e46ae,// 487 PAY 458 

    0x3d2bcb5b,// 488 PAY 459 

    0x61000000,// 489 PAY 460 

/// STA is 1 words. 

/// STA num_pkts       : 76 

/// STA pkt_idx        : 88 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x80 

    0x0160804c // 490 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt23_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x80922813,// 4 SCX   2 

    0x000073c2,// 5 SCX   3 

    0x05526058,// 6 SCX   4 

    0xb9576bea,// 7 SCX   5 

    0x162c9591,// 8 SCX   6 

    0x444c1e97,// 9 SCX   7 

    0x14ac4baa,// 10 SCX   8 

    0xad240fe7,// 11 SCX   9 

    0x48f3dc2f,// 12 SCX  10 

    0x42ecac40,// 13 SCX  11 

    0x3dca1d66,// 14 SCX  12 

    0x79601bd3,// 15 SCX  13 

    0x85cb5a1a,// 16 SCX  14 

    0xe74129d9,// 17 SCX  15 

    0xa8992dff,// 18 SCX  16 

    0x0de7a039,// 19 SCX  17 

    0xd5cc2c6e,// 20 SCX  18 

    0x303ef685,// 21 SCX  19 

    0x4ac1f545,// 22 SCX  20 

    0x5951f79d,// 23 SCX  21 

    0x8ba2475b,// 24 SCX  22 

    0x52189528,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1774 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 1511 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1511 

/// BFD lencrypto      : 36 

/// BFD ofstcrypto     : 1440 

/// BFD (ofst+len)cry  : 1476 

/// BFD ofstiv         : 788 

/// BFD ofsticv        : 1732 

    0x000005e7,// 26 BFD   1 

    0x05a00024,// 27 BFD   2 

    0x06c40314,// 28 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c0053f6,// 29 MFM   1 

    0x0ad70a1c,// 30 MFM   2 

    0x5ded233f,// 31 MFM   3 

    0x89bef410,// 32 MFM   4 

    0x04213e4c,// 33 MFM   5 

    0xc7fe11fc,// 34 MFM   6 

    0x735efeab,// 35 MFM   7 

    0x109e4673,// 36 MFM   8 

    0x43edc513,// 37 MFM   9 

    0x8870c35f,// 38 MFM  10 

    0x00c538d9,// 39 MFM  11 

    0x5a879ed2,// 40 MFM  12 

    0xde3a96ad,// 41 MFM  13 

    0x72b80d64,// 42 MFM  14 

    0xbdb429c7,// 43 MFM  15 

    0x039ec31f,// 44 MFM  16 

/// BDA is 445 words. 

/// BDA size     is 1774 (0x6ee) 

/// BDA id       is 0x6a15 

    0x06ee6a15,// 45 BDA   1 

/// PAY Generic Data size   : 1774 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xfb7e914a,// 46 PAY   1 

    0x8750fc1b,// 47 PAY   2 

    0x0927ab41,// 48 PAY   3 

    0x3d05a569,// 49 PAY   4 

    0x2d7c1328,// 50 PAY   5 

    0x421a6103,// 51 PAY   6 

    0xf6081755,// 52 PAY   7 

    0xa094fac1,// 53 PAY   8 

    0x59a35d1f,// 54 PAY   9 

    0x468196ec,// 55 PAY  10 

    0x7a55d59b,// 56 PAY  11 

    0x4236b34c,// 57 PAY  12 

    0xb94f0222,// 58 PAY  13 

    0xaebf68dd,// 59 PAY  14 

    0xdbec7095,// 60 PAY  15 

    0x7eeb0bcd,// 61 PAY  16 

    0x980a456b,// 62 PAY  17 

    0x90d376cb,// 63 PAY  18 

    0x425232ab,// 64 PAY  19 

    0x523b0438,// 65 PAY  20 

    0xef2afba6,// 66 PAY  21 

    0xc897185f,// 67 PAY  22 

    0x8d49c640,// 68 PAY  23 

    0x91aeaf96,// 69 PAY  24 

    0x9a6c9309,// 70 PAY  25 

    0x4ae59c01,// 71 PAY  26 

    0xfa44b06e,// 72 PAY  27 

    0x065ef240,// 73 PAY  28 

    0xb4dd1903,// 74 PAY  29 

    0x398b7495,// 75 PAY  30 

    0xeee99fd9,// 76 PAY  31 

    0x3f915444,// 77 PAY  32 

    0xb281ac3b,// 78 PAY  33 

    0xf552a68e,// 79 PAY  34 

    0x82e2b917,// 80 PAY  35 

    0x99ef5984,// 81 PAY  36 

    0xd9b2b7b3,// 82 PAY  37 

    0x3dca7901,// 83 PAY  38 

    0x106e4d6b,// 84 PAY  39 

    0x1c91d8b6,// 85 PAY  40 

    0xd2cb0d05,// 86 PAY  41 

    0xf6a94c36,// 87 PAY  42 

    0x3010113f,// 88 PAY  43 

    0xa25cd4d1,// 89 PAY  44 

    0xd9995a38,// 90 PAY  45 

    0x3265cfb7,// 91 PAY  46 

    0x45cb6abc,// 92 PAY  47 

    0x4781e9c4,// 93 PAY  48 

    0xda061f76,// 94 PAY  49 

    0x9c714204,// 95 PAY  50 

    0x22d7627b,// 96 PAY  51 

    0xa5fa5cb9,// 97 PAY  52 

    0x024a7f0b,// 98 PAY  53 

    0x78f4c81f,// 99 PAY  54 

    0xe4af633b,// 100 PAY  55 

    0x81dbf0f6,// 101 PAY  56 

    0x043690c0,// 102 PAY  57 

    0xb9698d91,// 103 PAY  58 

    0xd3fe479d,// 104 PAY  59 

    0xbccc9934,// 105 PAY  60 

    0x5bc19aef,// 106 PAY  61 

    0xe255565a,// 107 PAY  62 

    0xac0377a4,// 108 PAY  63 

    0xdf94f199,// 109 PAY  64 

    0xa50150b9,// 110 PAY  65 

    0x3b7c4af8,// 111 PAY  66 

    0xd430c7be,// 112 PAY  67 

    0xd7b2ab51,// 113 PAY  68 

    0x3089caa5,// 114 PAY  69 

    0x42a31fda,// 115 PAY  70 

    0x2e6a8785,// 116 PAY  71 

    0x024d4066,// 117 PAY  72 

    0x44c0e371,// 118 PAY  73 

    0xa348b09b,// 119 PAY  74 

    0x329b0097,// 120 PAY  75 

    0x9b37d6b4,// 121 PAY  76 

    0xec20e9d4,// 122 PAY  77 

    0x6a738d1d,// 123 PAY  78 

    0xac504161,// 124 PAY  79 

    0xe7ed335f,// 125 PAY  80 

    0x53265b64,// 126 PAY  81 

    0xae5326d1,// 127 PAY  82 

    0x55611060,// 128 PAY  83 

    0xe74c100f,// 129 PAY  84 

    0xacacdfa7,// 130 PAY  85 

    0xb61a0214,// 131 PAY  86 

    0x0df53f55,// 132 PAY  87 

    0xba32ed1b,// 133 PAY  88 

    0x911dd9d2,// 134 PAY  89 

    0xc7bb7b12,// 135 PAY  90 

    0x793d3604,// 136 PAY  91 

    0x937993ee,// 137 PAY  92 

    0x940935d4,// 138 PAY  93 

    0x87b034f8,// 139 PAY  94 

    0x04c2a2a5,// 140 PAY  95 

    0xfbddc1a1,// 141 PAY  96 

    0x77e7eaae,// 142 PAY  97 

    0xeec320b8,// 143 PAY  98 

    0x04c3e27f,// 144 PAY  99 

    0xef10717a,// 145 PAY 100 

    0x2d41e4fc,// 146 PAY 101 

    0x0d21d30a,// 147 PAY 102 

    0xfed52f98,// 148 PAY 103 

    0xd8e13b9f,// 149 PAY 104 

    0xcbb0827a,// 150 PAY 105 

    0xe4168ace,// 151 PAY 106 

    0x249e5ff0,// 152 PAY 107 

    0xd8f58074,// 153 PAY 108 

    0x3518e977,// 154 PAY 109 

    0x1fff12b1,// 155 PAY 110 

    0xa36e708c,// 156 PAY 111 

    0xf39d8a9a,// 157 PAY 112 

    0x8478ede1,// 158 PAY 113 

    0x979b72fd,// 159 PAY 114 

    0x0a721dd7,// 160 PAY 115 

    0x33021c82,// 161 PAY 116 

    0x3cfbb329,// 162 PAY 117 

    0xcff339e4,// 163 PAY 118 

    0xb6817c25,// 164 PAY 119 

    0x8ec3b40c,// 165 PAY 120 

    0x3418de15,// 166 PAY 121 

    0xa4eb2d85,// 167 PAY 122 

    0xed4d87da,// 168 PAY 123 

    0x2824a7ed,// 169 PAY 124 

    0xb16750d4,// 170 PAY 125 

    0xc6bf977b,// 171 PAY 126 

    0xe8fc17e9,// 172 PAY 127 

    0xaf424a74,// 173 PAY 128 

    0x227c7dc7,// 174 PAY 129 

    0x94277dfa,// 175 PAY 130 

    0x3bb3f5c6,// 176 PAY 131 

    0x6b78b90c,// 177 PAY 132 

    0xb215cb5c,// 178 PAY 133 

    0xb59d70d7,// 179 PAY 134 

    0x3031a928,// 180 PAY 135 

    0xd40085ea,// 181 PAY 136 

    0x5c4fb50d,// 182 PAY 137 

    0xe934483c,// 183 PAY 138 

    0xfa714208,// 184 PAY 139 

    0x51234e6b,// 185 PAY 140 

    0xb0962144,// 186 PAY 141 

    0xfb28edc0,// 187 PAY 142 

    0x14056aba,// 188 PAY 143 

    0xd7e50077,// 189 PAY 144 

    0x31078a99,// 190 PAY 145 

    0x63e54ab1,// 191 PAY 146 

    0x3665dbf0,// 192 PAY 147 

    0xaa34a9ad,// 193 PAY 148 

    0x96da86ab,// 194 PAY 149 

    0x8055b34b,// 195 PAY 150 

    0x72c9c293,// 196 PAY 151 

    0x09201872,// 197 PAY 152 

    0x1a18c2ee,// 198 PAY 153 

    0x55d621c9,// 199 PAY 154 

    0xfc6bf46f,// 200 PAY 155 

    0x6fa126bf,// 201 PAY 156 

    0xeff0a7fe,// 202 PAY 157 

    0x9811a7b6,// 203 PAY 158 

    0x3fcb2238,// 204 PAY 159 

    0x9fbdaaf5,// 205 PAY 160 

    0xd6e886c3,// 206 PAY 161 

    0x0b05a34e,// 207 PAY 162 

    0x5ab0e99f,// 208 PAY 163 

    0x54d24d38,// 209 PAY 164 

    0xfae6c167,// 210 PAY 165 

    0xcb9d76c7,// 211 PAY 166 

    0x8e516988,// 212 PAY 167 

    0xf74f7ecb,// 213 PAY 168 

    0xcd211be0,// 214 PAY 169 

    0x2c5729d7,// 215 PAY 170 

    0x572720d7,// 216 PAY 171 

    0x85241e36,// 217 PAY 172 

    0x17f1207f,// 218 PAY 173 

    0x9319910f,// 219 PAY 174 

    0xacf5eb08,// 220 PAY 175 

    0xec273d39,// 221 PAY 176 

    0xf0574aae,// 222 PAY 177 

    0xd03c4a38,// 223 PAY 178 

    0x6218fd7d,// 224 PAY 179 

    0xa04401db,// 225 PAY 180 

    0x25b1f1ef,// 226 PAY 181 

    0xb689a9db,// 227 PAY 182 

    0x5e3fb7c1,// 228 PAY 183 

    0x5d08c78d,// 229 PAY 184 

    0xd20ce41b,// 230 PAY 185 

    0xa2132961,// 231 PAY 186 

    0x3b247a3f,// 232 PAY 187 

    0x45b009d7,// 233 PAY 188 

    0xf2056654,// 234 PAY 189 

    0xe4b6ff03,// 235 PAY 190 

    0x8ef826f0,// 236 PAY 191 

    0x73536917,// 237 PAY 192 

    0x6eb81a81,// 238 PAY 193 

    0xbcf51d09,// 239 PAY 194 

    0xdd71e23c,// 240 PAY 195 

    0xa347089e,// 241 PAY 196 

    0xd60315f9,// 242 PAY 197 

    0xddaa4ee8,// 243 PAY 198 

    0x548d3a1d,// 244 PAY 199 

    0x33acfee9,// 245 PAY 200 

    0xce01b5b8,// 246 PAY 201 

    0x4189e585,// 247 PAY 202 

    0x391d986c,// 248 PAY 203 

    0xece17d76,// 249 PAY 204 

    0x1939b040,// 250 PAY 205 

    0xad74dc29,// 251 PAY 206 

    0x33a88e77,// 252 PAY 207 

    0x4deb6d46,// 253 PAY 208 

    0x9e837034,// 254 PAY 209 

    0xef951db5,// 255 PAY 210 

    0x58b7483f,// 256 PAY 211 

    0x5f046abb,// 257 PAY 212 

    0xa2bb1a4c,// 258 PAY 213 

    0x2001d1db,// 259 PAY 214 

    0x328285c5,// 260 PAY 215 

    0xd73b1f4c,// 261 PAY 216 

    0xf240fe26,// 262 PAY 217 

    0xb90fa952,// 263 PAY 218 

    0x1133378c,// 264 PAY 219 

    0x03c59853,// 265 PAY 220 

    0x1101c1f2,// 266 PAY 221 

    0x031bc586,// 267 PAY 222 

    0x9a3902e8,// 268 PAY 223 

    0xe1de58e1,// 269 PAY 224 

    0x8f674bc1,// 270 PAY 225 

    0xad773927,// 271 PAY 226 

    0x9812a1ba,// 272 PAY 227 

    0x281bd6bf,// 273 PAY 228 

    0xa371c20d,// 274 PAY 229 

    0x5c1b53a5,// 275 PAY 230 

    0xf5c98f5e,// 276 PAY 231 

    0x47e5a357,// 277 PAY 232 

    0x61f8be6a,// 278 PAY 233 

    0x5e50bce4,// 279 PAY 234 

    0xef8b509a,// 280 PAY 235 

    0x01d15288,// 281 PAY 236 

    0xa615f1e2,// 282 PAY 237 

    0x68227f64,// 283 PAY 238 

    0x394bf499,// 284 PAY 239 

    0xd194d805,// 285 PAY 240 

    0x8533bc1c,// 286 PAY 241 

    0x4228b3cf,// 287 PAY 242 

    0x098f465e,// 288 PAY 243 

    0xa49c2433,// 289 PAY 244 

    0xb2283cff,// 290 PAY 245 

    0xbae27ad7,// 291 PAY 246 

    0x88484346,// 292 PAY 247 

    0x9a0c97e3,// 293 PAY 248 

    0x96a31e49,// 294 PAY 249 

    0x4df5a0f7,// 295 PAY 250 

    0x65983918,// 296 PAY 251 

    0x33c56882,// 297 PAY 252 

    0xf93d361e,// 298 PAY 253 

    0x500d7da1,// 299 PAY 254 

    0x7747948f,// 300 PAY 255 

    0x1d65df07,// 301 PAY 256 

    0xc590f69f,// 302 PAY 257 

    0xbc1004c1,// 303 PAY 258 

    0x21c18ef4,// 304 PAY 259 

    0x5e503c0c,// 305 PAY 260 

    0xd326cf12,// 306 PAY 261 

    0xa3f67890,// 307 PAY 262 

    0x6e729656,// 308 PAY 263 

    0x8588b150,// 309 PAY 264 

    0x6016bcab,// 310 PAY 265 

    0x794ef5cc,// 311 PAY 266 

    0x97b91aea,// 312 PAY 267 

    0x3a10b4f4,// 313 PAY 268 

    0xe2dae316,// 314 PAY 269 

    0xd39aab33,// 315 PAY 270 

    0x497a03f8,// 316 PAY 271 

    0x4cdfb4f7,// 317 PAY 272 

    0x59353f96,// 318 PAY 273 

    0x8d5c3ecf,// 319 PAY 274 

    0x3fae3a35,// 320 PAY 275 

    0xedc07107,// 321 PAY 276 

    0x65cf38c3,// 322 PAY 277 

    0x1e3ab5db,// 323 PAY 278 

    0xc23bf410,// 324 PAY 279 

    0x42352653,// 325 PAY 280 

    0xb461cddf,// 326 PAY 281 

    0xe41662a8,// 327 PAY 282 

    0xe2b450ef,// 328 PAY 283 

    0x1022641b,// 329 PAY 284 

    0x2247b894,// 330 PAY 285 

    0x706fe526,// 331 PAY 286 

    0x4f406cb7,// 332 PAY 287 

    0x3f9318f1,// 333 PAY 288 

    0x6acd048b,// 334 PAY 289 

    0xff960593,// 335 PAY 290 

    0xcdf18764,// 336 PAY 291 

    0x08039bfb,// 337 PAY 292 

    0xa460696f,// 338 PAY 293 

    0xfb8c23e2,// 339 PAY 294 

    0xcf1ff5d0,// 340 PAY 295 

    0xe8f5faef,// 341 PAY 296 

    0x3f52a501,// 342 PAY 297 

    0x0de071b4,// 343 PAY 298 

    0x26ac9d77,// 344 PAY 299 

    0x3f44ab53,// 345 PAY 300 

    0xeb5b6f10,// 346 PAY 301 

    0x03918799,// 347 PAY 302 

    0xafe9d783,// 348 PAY 303 

    0xcf8cd12f,// 349 PAY 304 

    0xf4c20b1b,// 350 PAY 305 

    0x46ce4b55,// 351 PAY 306 

    0xb193bac5,// 352 PAY 307 

    0xb62717f7,// 353 PAY 308 

    0x4749e563,// 354 PAY 309 

    0xd25e515c,// 355 PAY 310 

    0xb7916a01,// 356 PAY 311 

    0x4b36a6de,// 357 PAY 312 

    0x041fd864,// 358 PAY 313 

    0x45d73490,// 359 PAY 314 

    0x5de24be8,// 360 PAY 315 

    0x7f9af954,// 361 PAY 316 

    0xbdab44e5,// 362 PAY 317 

    0xee39e7cf,// 363 PAY 318 

    0x7098484b,// 364 PAY 319 

    0x01555bfa,// 365 PAY 320 

    0xc353e3f2,// 366 PAY 321 

    0xd089fa40,// 367 PAY 322 

    0xaeb3b46c,// 368 PAY 323 

    0x8016e8c0,// 369 PAY 324 

    0x4b74ec67,// 370 PAY 325 

    0x12bcac98,// 371 PAY 326 

    0x9278e393,// 372 PAY 327 

    0xda129394,// 373 PAY 328 

    0xb9573c13,// 374 PAY 329 

    0x8ebc7df6,// 375 PAY 330 

    0x1b4bce85,// 376 PAY 331 

    0x3c23cf6a,// 377 PAY 332 

    0xffcc29b8,// 378 PAY 333 

    0xcbdab408,// 379 PAY 334 

    0xab97c315,// 380 PAY 335 

    0xee197b55,// 381 PAY 336 

    0x4b335809,// 382 PAY 337 

    0x1164ef09,// 383 PAY 338 

    0x53d51e15,// 384 PAY 339 

    0x4732e6ba,// 385 PAY 340 

    0xb957a53b,// 386 PAY 341 

    0x02de3bb3,// 387 PAY 342 

    0x4a1b6a9f,// 388 PAY 343 

    0xd800b5ca,// 389 PAY 344 

    0x315db820,// 390 PAY 345 

    0x6085ab2c,// 391 PAY 346 

    0x0d659379,// 392 PAY 347 

    0xc92fcce7,// 393 PAY 348 

    0x36dcf713,// 394 PAY 349 

    0x033f5032,// 395 PAY 350 

    0xe5bad5cb,// 396 PAY 351 

    0x708fb6cc,// 397 PAY 352 

    0x3f97cd87,// 398 PAY 353 

    0x76916767,// 399 PAY 354 

    0x97b0a7b1,// 400 PAY 355 

    0x5b5efd49,// 401 PAY 356 

    0x0eabe7bd,// 402 PAY 357 

    0xf0e28f93,// 403 PAY 358 

    0x48235287,// 404 PAY 359 

    0xaed7bd47,// 405 PAY 360 

    0xe9ab75a1,// 406 PAY 361 

    0x3e06d88e,// 407 PAY 362 

    0x24395417,// 408 PAY 363 

    0x8436526b,// 409 PAY 364 

    0x719e3e5d,// 410 PAY 365 

    0x8f7ffec4,// 411 PAY 366 

    0x54a0b1ad,// 412 PAY 367 

    0x2fa013c5,// 413 PAY 368 

    0x8cab7fca,// 414 PAY 369 

    0x0f76de08,// 415 PAY 370 

    0x14d02477,// 416 PAY 371 

    0xce24404d,// 417 PAY 372 

    0xd80348b3,// 418 PAY 373 

    0x615fcea8,// 419 PAY 374 

    0x12ed6570,// 420 PAY 375 

    0x8cd149cd,// 421 PAY 376 

    0x2055679b,// 422 PAY 377 

    0xcf9443b0,// 423 PAY 378 

    0x42395be7,// 424 PAY 379 

    0xb72cff43,// 425 PAY 380 

    0x47b12f44,// 426 PAY 381 

    0x131d6239,// 427 PAY 382 

    0x1b023c88,// 428 PAY 383 

    0x4b452d0a,// 429 PAY 384 

    0x640e0998,// 430 PAY 385 

    0x5f0fbd6c,// 431 PAY 386 

    0x0343dc6a,// 432 PAY 387 

    0x9d170ea0,// 433 PAY 388 

    0xbb88d356,// 434 PAY 389 

    0x6a0bfb1e,// 435 PAY 390 

    0xb398eb75,// 436 PAY 391 

    0x8be03faa,// 437 PAY 392 

    0x3ecec434,// 438 PAY 393 

    0x88bc9e8d,// 439 PAY 394 

    0xe0e85bbf,// 440 PAY 395 

    0xb71c72b4,// 441 PAY 396 

    0x12133040,// 442 PAY 397 

    0xc47c66f6,// 443 PAY 398 

    0x4275928b,// 444 PAY 399 

    0x35b8fa3d,// 445 PAY 400 

    0x426d15c4,// 446 PAY 401 

    0xe465136d,// 447 PAY 402 

    0xa3342e03,// 448 PAY 403 

    0x80c97c56,// 449 PAY 404 

    0xec984124,// 450 PAY 405 

    0x357a77c4,// 451 PAY 406 

    0x7722ca98,// 452 PAY 407 

    0xf8731d08,// 453 PAY 408 

    0x0eb503fd,// 454 PAY 409 

    0x55f4563b,// 455 PAY 410 

    0x6c5a7659,// 456 PAY 411 

    0xc1a2fca8,// 457 PAY 412 

    0xf90ffde9,// 458 PAY 413 

    0x24390c75,// 459 PAY 414 

    0x5edd8d09,// 460 PAY 415 

    0x46f8fdf4,// 461 PAY 416 

    0x2586e127,// 462 PAY 417 

    0x6e9621c6,// 463 PAY 418 

    0xe37a62dc,// 464 PAY 419 

    0x66a4140d,// 465 PAY 420 

    0x0e1348e1,// 466 PAY 421 

    0x01b6fce2,// 467 PAY 422 

    0xd0b0fcfc,// 468 PAY 423 

    0x29ef1aa3,// 469 PAY 424 

    0x218286c3,// 470 PAY 425 

    0x4c76af81,// 471 PAY 426 

    0x674056f1,// 472 PAY 427 

    0xf83950e8,// 473 PAY 428 

    0x490a03ec,// 474 PAY 429 

    0x7f089cab,// 475 PAY 430 

    0xa41b2949,// 476 PAY 431 

    0x21e315a4,// 477 PAY 432 

    0x85179052,// 478 PAY 433 

    0x25b96bba,// 479 PAY 434 

    0x8e35cd31,// 480 PAY 435 

    0x289b1c23,// 481 PAY 436 

    0x0044e7af,// 482 PAY 437 

    0xc85df16b,// 483 PAY 438 

    0x6f1566e1,// 484 PAY 439 

    0x560309f7,// 485 PAY 440 

    0x9ef567ce,// 486 PAY 441 

    0xfddcee7c,// 487 PAY 442 

    0x8c3189fe,// 488 PAY 443 

    0xf4020000,// 489 PAY 444 

/// STA is 1 words. 

/// STA num_pkts       : 23 

/// STA pkt_idx        : 246 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xd8 

    0x03d9d817 // 490 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt24_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0f 

/// ECH pdu_tag        : 0x00 

    0x000f0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x8084287f,// 4 SCX   2 

    0x00003244,// 5 SCX   3 

    0x986b4f9c,// 6 SCX   4 

    0xb6831d6e,// 7 SCX   5 

    0x0fd95763,// 8 SCX   6 

    0xf87a7ade,// 9 SCX   7 

    0x25b1f1c3,// 10 SCX   8 

    0xc11b0040,// 11 SCX   9 

    0x5a2968a0,// 12 SCX  10 

    0xd348d9b5,// 13 SCX  11 

    0x86e72a84,// 14 SCX  12 

    0xb111dbfa,// 15 SCX  13 

    0x370f8f90,// 16 SCX  14 

    0xa224f9fc,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 2004 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 642 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 642 

/// BFD lencrypto      : 160 

/// BFD ofstcrypto     : 480 

/// BFD (ofst+len)cry  : 640 

/// BFD ofstiv         : 212 

/// BFD ofsticv        : 684 

    0x00000282,// 18 BFD   1 

    0x01e000a0,// 19 BFD   2 

    0x02ac00d4,// 20 BFD   3 

/// MFM is 11 words. 

/// MFM vldnibs        : 53 

    0x53001406,// 21 MFM   1 

    0x63b5d948,// 22 MFM   2 

    0xfe12c277,// 23 MFM   3 

    0x1f6a4164,// 24 MFM   4 

    0x97530d81,// 25 MFM   5 

    0xb34c3f7c,// 26 MFM   6 

    0x9f7036d2,// 27 MFM   7 

    0xc058332e,// 28 MFM   8 

    0xd8e1cc05,// 29 MFM   9 

    0x377e38a9,// 30 MFM  10 

    0xb90dfce0,// 31 MFM  11 

/// BDA is 502 words. 

/// BDA size     is 2004 (0x7d4) 

/// BDA id       is 0x2a9b 

    0x07d42a9b,// 32 BDA   1 

/// PAY Generic Data size   : 2004 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xf92b91a6,// 33 PAY   1 

    0xd60010df,// 34 PAY   2 

    0xed4e230c,// 35 PAY   3 

    0xdee30f98,// 36 PAY   4 

    0x86d49486,// 37 PAY   5 

    0xbdcae232,// 38 PAY   6 

    0xbc77608f,// 39 PAY   7 

    0x58d52ab9,// 40 PAY   8 

    0xd7370ec7,// 41 PAY   9 

    0xcbc5053e,// 42 PAY  10 

    0xe1802f07,// 43 PAY  11 

    0x496bc812,// 44 PAY  12 

    0x148de4dd,// 45 PAY  13 

    0xbf7e795b,// 46 PAY  14 

    0xa4d2753a,// 47 PAY  15 

    0x2ca5c862,// 48 PAY  16 

    0xb71c8fb0,// 49 PAY  17 

    0xf614558a,// 50 PAY  18 

    0xaf9a73c4,// 51 PAY  19 

    0x1ff36370,// 52 PAY  20 

    0xfe7de949,// 53 PAY  21 

    0xef967870,// 54 PAY  22 

    0x5d8293e5,// 55 PAY  23 

    0xdaa4d0ed,// 56 PAY  24 

    0xa3ede4ed,// 57 PAY  25 

    0x34d6ce94,// 58 PAY  26 

    0xc0445f55,// 59 PAY  27 

    0x67db0668,// 60 PAY  28 

    0xf1624832,// 61 PAY  29 

    0x501c5058,// 62 PAY  30 

    0x39c5f79c,// 63 PAY  31 

    0x1109e017,// 64 PAY  32 

    0x5a1ec6ee,// 65 PAY  33 

    0x369d95ad,// 66 PAY  34 

    0x2d49be40,// 67 PAY  35 

    0x5f9c74ed,// 68 PAY  36 

    0xb043c7f2,// 69 PAY  37 

    0x44d85e8f,// 70 PAY  38 

    0x04ff5791,// 71 PAY  39 

    0xdb54db4a,// 72 PAY  40 

    0x84683829,// 73 PAY  41 

    0xc2bf8539,// 74 PAY  42 

    0x76a056e7,// 75 PAY  43 

    0xa46686dc,// 76 PAY  44 

    0x4fdf6530,// 77 PAY  45 

    0x669d73ff,// 78 PAY  46 

    0x6d8611c2,// 79 PAY  47 

    0xe0202df8,// 80 PAY  48 

    0xedb83a2a,// 81 PAY  49 

    0xab2ed3ab,// 82 PAY  50 

    0x356bfc49,// 83 PAY  51 

    0xe3e71992,// 84 PAY  52 

    0xfa4b0aee,// 85 PAY  53 

    0x296b43a0,// 86 PAY  54 

    0x3ed82008,// 87 PAY  55 

    0xad64e42f,// 88 PAY  56 

    0xde826f67,// 89 PAY  57 

    0x89feeb58,// 90 PAY  58 

    0x82ec627a,// 91 PAY  59 

    0x03af211c,// 92 PAY  60 

    0x0d992ce1,// 93 PAY  61 

    0xe3a903f2,// 94 PAY  62 

    0xcd9ce720,// 95 PAY  63 

    0x5e642533,// 96 PAY  64 

    0x6ac930dc,// 97 PAY  65 

    0x372c5833,// 98 PAY  66 

    0xe5f7e2c4,// 99 PAY  67 

    0x78e662f3,// 100 PAY  68 

    0xb20ac4bb,// 101 PAY  69 

    0x28b671d0,// 102 PAY  70 

    0x9764febd,// 103 PAY  71 

    0xab4e3a7e,// 104 PAY  72 

    0xbe2309a4,// 105 PAY  73 

    0x9319950d,// 106 PAY  74 

    0x9067a976,// 107 PAY  75 

    0xe332ed3f,// 108 PAY  76 

    0x00925daa,// 109 PAY  77 

    0x3500e2d8,// 110 PAY  78 

    0x4d4b4bb4,// 111 PAY  79 

    0x7bca1e2e,// 112 PAY  80 

    0xf81317f1,// 113 PAY  81 

    0x228a9dc0,// 114 PAY  82 

    0x2f2e290f,// 115 PAY  83 

    0x0c3f0465,// 116 PAY  84 

    0x9c816185,// 117 PAY  85 

    0x76ef3291,// 118 PAY  86 

    0xcb524dcc,// 119 PAY  87 

    0x58a94e24,// 120 PAY  88 

    0xcbf6cf59,// 121 PAY  89 

    0x2e44ebf8,// 122 PAY  90 

    0x2ed209ea,// 123 PAY  91 

    0x49eb1917,// 124 PAY  92 

    0x7841a5a4,// 125 PAY  93 

    0x5bedfcb2,// 126 PAY  94 

    0x2db7683e,// 127 PAY  95 

    0xf59a2dd8,// 128 PAY  96 

    0xaf37d5a5,// 129 PAY  97 

    0x2d0ce308,// 130 PAY  98 

    0x527a9320,// 131 PAY  99 

    0x73b8c864,// 132 PAY 100 

    0x4f9464e0,// 133 PAY 101 

    0xf27c60ff,// 134 PAY 102 

    0xf7b85b63,// 135 PAY 103 

    0x352dd401,// 136 PAY 104 

    0x614a17b3,// 137 PAY 105 

    0xd4bfdfe5,// 138 PAY 106 

    0x6fc92e8e,// 139 PAY 107 

    0xda538c7d,// 140 PAY 108 

    0x1425cd9e,// 141 PAY 109 

    0x69e8f6cb,// 142 PAY 110 

    0x7bbc0d8e,// 143 PAY 111 

    0x8c378b8b,// 144 PAY 112 

    0x671aa0cb,// 145 PAY 113 

    0x33880aff,// 146 PAY 114 

    0x4327f49d,// 147 PAY 115 

    0x3df71093,// 148 PAY 116 

    0x54f1c138,// 149 PAY 117 

    0x2bf61121,// 150 PAY 118 

    0xdc8b2b6a,// 151 PAY 119 

    0x73bc093e,// 152 PAY 120 

    0xc75c875b,// 153 PAY 121 

    0x9f69dd85,// 154 PAY 122 

    0xbaf67af4,// 155 PAY 123 

    0x15f4cd4a,// 156 PAY 124 

    0xd676e82a,// 157 PAY 125 

    0x8d202058,// 158 PAY 126 

    0x0f83f401,// 159 PAY 127 

    0xf3af4cad,// 160 PAY 128 

    0x0d31fadf,// 161 PAY 129 

    0x7a29e721,// 162 PAY 130 

    0x95955c7e,// 163 PAY 131 

    0x28ed3c22,// 164 PAY 132 

    0x9ae1d07e,// 165 PAY 133 

    0x6f88a5a4,// 166 PAY 134 

    0x45754a89,// 167 PAY 135 

    0xc956a1b9,// 168 PAY 136 

    0x339b186f,// 169 PAY 137 

    0x60b16744,// 170 PAY 138 

    0x5435002a,// 171 PAY 139 

    0x4390d73c,// 172 PAY 140 

    0xe54be089,// 173 PAY 141 

    0xf10c0bd0,// 174 PAY 142 

    0x15f2a49e,// 175 PAY 143 

    0xfaf78b82,// 176 PAY 144 

    0x5a209147,// 177 PAY 145 

    0x501b4c76,// 178 PAY 146 

    0xd453e377,// 179 PAY 147 

    0x20886a6a,// 180 PAY 148 

    0x13691f7d,// 181 PAY 149 

    0x018fe126,// 182 PAY 150 

    0x24766374,// 183 PAY 151 

    0xd2bf31e3,// 184 PAY 152 

    0x8e7a46a3,// 185 PAY 153 

    0x703b8b91,// 186 PAY 154 

    0x90e66364,// 187 PAY 155 

    0xfa0066f6,// 188 PAY 156 

    0x15512469,// 189 PAY 157 

    0x71f8d8d5,// 190 PAY 158 

    0xd0c09881,// 191 PAY 159 

    0x1df72e4c,// 192 PAY 160 

    0x86f35c3d,// 193 PAY 161 

    0xfcb22a49,// 194 PAY 162 

    0x86d72692,// 195 PAY 163 

    0xeafc60db,// 196 PAY 164 

    0xafe7f4d6,// 197 PAY 165 

    0x9c806667,// 198 PAY 166 

    0x215cd579,// 199 PAY 167 

    0x8d6f58bc,// 200 PAY 168 

    0x4724512c,// 201 PAY 169 

    0x4a8bd6c8,// 202 PAY 170 

    0xd07247e1,// 203 PAY 171 

    0x64b616fe,// 204 PAY 172 

    0x2f10d4af,// 205 PAY 173 

    0x6ad629d3,// 206 PAY 174 

    0xbc3d305c,// 207 PAY 175 

    0x98829e69,// 208 PAY 176 

    0xd4762a42,// 209 PAY 177 

    0x2184da8f,// 210 PAY 178 

    0x1a3eb327,// 211 PAY 179 

    0x22c68361,// 212 PAY 180 

    0xf0170121,// 213 PAY 181 

    0x00ba7401,// 214 PAY 182 

    0xf7ebfd3e,// 215 PAY 183 

    0x2f12af7e,// 216 PAY 184 

    0x04882835,// 217 PAY 185 

    0xb7935d08,// 218 PAY 186 

    0xb82bacb4,// 219 PAY 187 

    0x9bb4d163,// 220 PAY 188 

    0x79dfb8fd,// 221 PAY 189 

    0x55d600c9,// 222 PAY 190 

    0xd995cf71,// 223 PAY 191 

    0xd317307c,// 224 PAY 192 

    0x848e1d3b,// 225 PAY 193 

    0x598bc1a5,// 226 PAY 194 

    0x7d737d01,// 227 PAY 195 

    0x302fe7cc,// 228 PAY 196 

    0x121e3b87,// 229 PAY 197 

    0x09184172,// 230 PAY 198 

    0x42d89f5a,// 231 PAY 199 

    0x288f0ca4,// 232 PAY 200 

    0x7fdff556,// 233 PAY 201 

    0x639dbe1b,// 234 PAY 202 

    0x3571583c,// 235 PAY 203 

    0xe07c3a96,// 236 PAY 204 

    0xe297f4b9,// 237 PAY 205 

    0x820cfd3e,// 238 PAY 206 

    0x01059d53,// 239 PAY 207 

    0x361fdc67,// 240 PAY 208 

    0xcb1a5fb0,// 241 PAY 209 

    0x5a5d6709,// 242 PAY 210 

    0x405e9c78,// 243 PAY 211 

    0x1929046b,// 244 PAY 212 

    0x24762d47,// 245 PAY 213 

    0x7ce8c9e9,// 246 PAY 214 

    0xdc6b6ffb,// 247 PAY 215 

    0xe18a6fba,// 248 PAY 216 

    0xad6b8018,// 249 PAY 217 

    0x5b715b71,// 250 PAY 218 

    0x807f3089,// 251 PAY 219 

    0xc42d3ee3,// 252 PAY 220 

    0xfb553a7a,// 253 PAY 221 

    0xca9c59bc,// 254 PAY 222 

    0x13885e0d,// 255 PAY 223 

    0xc7c51533,// 256 PAY 224 

    0x0f15015a,// 257 PAY 225 

    0x8f8dfc0b,// 258 PAY 226 

    0xfa3aed2f,// 259 PAY 227 

    0x3112277d,// 260 PAY 228 

    0x596f70c1,// 261 PAY 229 

    0x10326c58,// 262 PAY 230 

    0x9c933db4,// 263 PAY 231 

    0x1eb0a115,// 264 PAY 232 

    0xa508477a,// 265 PAY 233 

    0x6d776fb9,// 266 PAY 234 

    0x712836c4,// 267 PAY 235 

    0x03ab5d77,// 268 PAY 236 

    0x310bbe49,// 269 PAY 237 

    0x257e3bf8,// 270 PAY 238 

    0x0a5bc5f5,// 271 PAY 239 

    0xa8c9678a,// 272 PAY 240 

    0xfcfd89a4,// 273 PAY 241 

    0x728d0738,// 274 PAY 242 

    0x3d57f376,// 275 PAY 243 

    0x5946c3be,// 276 PAY 244 

    0xb51b4fc9,// 277 PAY 245 

    0x98ac4917,// 278 PAY 246 

    0x2903b967,// 279 PAY 247 

    0xdd3da8a7,// 280 PAY 248 

    0x54296891,// 281 PAY 249 

    0xaff94688,// 282 PAY 250 

    0xb0ae5696,// 283 PAY 251 

    0xddaef993,// 284 PAY 252 

    0x78d248b9,// 285 PAY 253 

    0x1992a810,// 286 PAY 254 

    0xb366b5b4,// 287 PAY 255 

    0x325802e5,// 288 PAY 256 

    0x348fa571,// 289 PAY 257 

    0x0ed7d0b0,// 290 PAY 258 

    0x7ee6244e,// 291 PAY 259 

    0x46caf135,// 292 PAY 260 

    0x452fdbae,// 293 PAY 261 

    0x2bc2dcff,// 294 PAY 262 

    0x4a493acb,// 295 PAY 263 

    0x4678bbf7,// 296 PAY 264 

    0x4e25fd57,// 297 PAY 265 

    0x7b66335d,// 298 PAY 266 

    0x405d3ff4,// 299 PAY 267 

    0x7d5bb931,// 300 PAY 268 

    0x52ef9a76,// 301 PAY 269 

    0x8181b40b,// 302 PAY 270 

    0xff287703,// 303 PAY 271 

    0x478903c7,// 304 PAY 272 

    0x5d15cf24,// 305 PAY 273 

    0xbad10cd5,// 306 PAY 274 

    0xd0ab45b8,// 307 PAY 275 

    0xab37ff49,// 308 PAY 276 

    0xbd7ed0b0,// 309 PAY 277 

    0xf8e68554,// 310 PAY 278 

    0x099f9165,// 311 PAY 279 

    0xada0d06b,// 312 PAY 280 

    0x15146088,// 313 PAY 281 

    0x05966173,// 314 PAY 282 

    0x3560d1ae,// 315 PAY 283 

    0x67dc6ff0,// 316 PAY 284 

    0x7c56a6c0,// 317 PAY 285 

    0x8fc5a114,// 318 PAY 286 

    0x17515eb7,// 319 PAY 287 

    0xfeec1beb,// 320 PAY 288 

    0xbf299699,// 321 PAY 289 

    0xc9ea6a31,// 322 PAY 290 

    0x88399cc3,// 323 PAY 291 

    0x8d12dcba,// 324 PAY 292 

    0x485b9102,// 325 PAY 293 

    0x59d4a077,// 326 PAY 294 

    0xeebae2cb,// 327 PAY 295 

    0x7b63162b,// 328 PAY 296 

    0xeac27ead,// 329 PAY 297 

    0x5d5ef659,// 330 PAY 298 

    0xdc9588d3,// 331 PAY 299 

    0x20658942,// 332 PAY 300 

    0xa5ee238b,// 333 PAY 301 

    0x2f54233d,// 334 PAY 302 

    0x00d0d763,// 335 PAY 303 

    0xbfcf39b9,// 336 PAY 304 

    0xd40d860b,// 337 PAY 305 

    0x97dbe337,// 338 PAY 306 

    0x75585dd4,// 339 PAY 307 

    0x65d2925f,// 340 PAY 308 

    0xe82a1205,// 341 PAY 309 

    0x7ece700f,// 342 PAY 310 

    0x8ef99c19,// 343 PAY 311 

    0x7ff91348,// 344 PAY 312 

    0xcdc15188,// 345 PAY 313 

    0xd01b9e8a,// 346 PAY 314 

    0x853f9ee2,// 347 PAY 315 

    0x78d1adc2,// 348 PAY 316 

    0xa7b8b4b8,// 349 PAY 317 

    0x2d2b829e,// 350 PAY 318 

    0x4b56e197,// 351 PAY 319 

    0x84101720,// 352 PAY 320 

    0x81fe67ea,// 353 PAY 321 

    0xc125a5d1,// 354 PAY 322 

    0x02170a79,// 355 PAY 323 

    0x5630957c,// 356 PAY 324 

    0xd41db11f,// 357 PAY 325 

    0x62e5e3d2,// 358 PAY 326 

    0x72644d32,// 359 PAY 327 

    0x32000dbd,// 360 PAY 328 

    0x30db2b89,// 361 PAY 329 

    0xdbb70e89,// 362 PAY 330 

    0x50aa89d5,// 363 PAY 331 

    0x64a8c93c,// 364 PAY 332 

    0x01cc3b5f,// 365 PAY 333 

    0x271e3a6a,// 366 PAY 334 

    0x11cca92c,// 367 PAY 335 

    0xd1fddc23,// 368 PAY 336 

    0x26774f94,// 369 PAY 337 

    0x0b6a2abd,// 370 PAY 338 

    0x848ee653,// 371 PAY 339 

    0xf38aca30,// 372 PAY 340 

    0xe849ef25,// 373 PAY 341 

    0x41a435d3,// 374 PAY 342 

    0xb16b02e6,// 375 PAY 343 

    0x6a512d11,// 376 PAY 344 

    0x50280ab2,// 377 PAY 345 

    0x4a8bd055,// 378 PAY 346 

    0x2c9cea0c,// 379 PAY 347 

    0x15b87974,// 380 PAY 348 

    0x4112bb70,// 381 PAY 349 

    0xdad1b981,// 382 PAY 350 

    0x69dd6297,// 383 PAY 351 

    0x34f44ac0,// 384 PAY 352 

    0xb885de89,// 385 PAY 353 

    0xf7e2b814,// 386 PAY 354 

    0xedc88d47,// 387 PAY 355 

    0x86ec3fd2,// 388 PAY 356 

    0xd8bb14da,// 389 PAY 357 

    0x1c82bc3d,// 390 PAY 358 

    0x16deb6d1,// 391 PAY 359 

    0x77ae7447,// 392 PAY 360 

    0xdb56c50e,// 393 PAY 361 

    0xe470bc4c,// 394 PAY 362 

    0xf9a364a8,// 395 PAY 363 

    0xe39c34ea,// 396 PAY 364 

    0x33485f7e,// 397 PAY 365 

    0xcd35b6a6,// 398 PAY 366 

    0xaaf19105,// 399 PAY 367 

    0xc6fba157,// 400 PAY 368 

    0xbb6ce09a,// 401 PAY 369 

    0x33be40dd,// 402 PAY 370 

    0x219c9723,// 403 PAY 371 

    0x6308d809,// 404 PAY 372 

    0xe5854b81,// 405 PAY 373 

    0xf895c446,// 406 PAY 374 

    0xcf58c231,// 407 PAY 375 

    0xa8440e46,// 408 PAY 376 

    0x7be644e0,// 409 PAY 377 

    0xc4e5f972,// 410 PAY 378 

    0x5de6cd57,// 411 PAY 379 

    0x0a680450,// 412 PAY 380 

    0xc727eddf,// 413 PAY 381 

    0x55edc35b,// 414 PAY 382 

    0xc22aa246,// 415 PAY 383 

    0xa7c7b89f,// 416 PAY 384 

    0xc750e0af,// 417 PAY 385 

    0xac88d53b,// 418 PAY 386 

    0xd6e73fa6,// 419 PAY 387 

    0xa171c969,// 420 PAY 388 

    0x8728118c,// 421 PAY 389 

    0xdd8892f8,// 422 PAY 390 

    0x78d85177,// 423 PAY 391 

    0x7b080847,// 424 PAY 392 

    0x19896e5b,// 425 PAY 393 

    0xda652b30,// 426 PAY 394 

    0xfd72cbfc,// 427 PAY 395 

    0x03431cde,// 428 PAY 396 

    0x6eafe33b,// 429 PAY 397 

    0x914c6ca3,// 430 PAY 398 

    0xffe7c3fa,// 431 PAY 399 

    0x74bf169a,// 432 PAY 400 

    0x28d113d8,// 433 PAY 401 

    0xf724094e,// 434 PAY 402 

    0x701c1b89,// 435 PAY 403 

    0x5a330fca,// 436 PAY 404 

    0x1359052e,// 437 PAY 405 

    0x391d179e,// 438 PAY 406 

    0xd43e1090,// 439 PAY 407 

    0xfe5a8e90,// 440 PAY 408 

    0x916b5b27,// 441 PAY 409 

    0x607a1342,// 442 PAY 410 

    0xb550c813,// 443 PAY 411 

    0x1276f691,// 444 PAY 412 

    0x5c7000de,// 445 PAY 413 

    0x71609395,// 446 PAY 414 

    0x6c64867b,// 447 PAY 415 

    0x5bb6228d,// 448 PAY 416 

    0xc8c86762,// 449 PAY 417 

    0x2ca14855,// 450 PAY 418 

    0x7a722ff4,// 451 PAY 419 

    0xad73e42f,// 452 PAY 420 

    0xbcc47455,// 453 PAY 421 

    0xcdf18a40,// 454 PAY 422 

    0xd3f62183,// 455 PAY 423 

    0x92775984,// 456 PAY 424 

    0xe34236bb,// 457 PAY 425 

    0xb44a5934,// 458 PAY 426 

    0x71173019,// 459 PAY 427 

    0x84e46f87,// 460 PAY 428 

    0x5000fe1f,// 461 PAY 429 

    0x794ba69d,// 462 PAY 430 

    0x9d8b4f8f,// 463 PAY 431 

    0x5b108b2e,// 464 PAY 432 

    0x186ae61f,// 465 PAY 433 

    0x12a9c891,// 466 PAY 434 

    0xa3304bf1,// 467 PAY 435 

    0xb890593b,// 468 PAY 436 

    0x4576f216,// 469 PAY 437 

    0xc60bb5d7,// 470 PAY 438 

    0xd9db3d56,// 471 PAY 439 

    0xcf73be06,// 472 PAY 440 

    0x0561875d,// 473 PAY 441 

    0x37b2baaa,// 474 PAY 442 

    0x2093dac6,// 475 PAY 443 

    0x1be8651f,// 476 PAY 444 

    0xfc1ffd3c,// 477 PAY 445 

    0x5b34902d,// 478 PAY 446 

    0xd27c4575,// 479 PAY 447 

    0xa5a69a35,// 480 PAY 448 

    0x48a09f4d,// 481 PAY 449 

    0x6e6f1b1b,// 482 PAY 450 

    0xb5bfacbe,// 483 PAY 451 

    0xafa63d08,// 484 PAY 452 

    0xbeddd132,// 485 PAY 453 

    0x9c5a6580,// 486 PAY 454 

    0x2473f568,// 487 PAY 455 

    0x490a6dcf,// 488 PAY 456 

    0xd04eac19,// 489 PAY 457 

    0xb859904f,// 490 PAY 458 

    0x6d808980,// 491 PAY 459 

    0xe288deda,// 492 PAY 460 

    0x0b3f9da0,// 493 PAY 461 

    0x8166e540,// 494 PAY 462 

    0xce50acb0,// 495 PAY 463 

    0xc98a92fc,// 496 PAY 464 

    0x86fe576c,// 497 PAY 465 

    0x5ae172ca,// 498 PAY 466 

    0x639282a2,// 499 PAY 467 

    0xbdd61997,// 500 PAY 468 

    0x87d9493d,// 501 PAY 469 

    0xedde6002,// 502 PAY 470 

    0xda19474c,// 503 PAY 471 

    0xf468656b,// 504 PAY 472 

    0xc8c807bb,// 505 PAY 473 

    0xf4dedd31,// 506 PAY 474 

    0x0463914b,// 507 PAY 475 

    0x48e8d065,// 508 PAY 476 

    0x88828adc,// 509 PAY 477 

    0x565a1592,// 510 PAY 478 

    0x990dc53c,// 511 PAY 479 

    0xb3f40b41,// 512 PAY 480 

    0xf66e05e7,// 513 PAY 481 

    0x171cc561,// 514 PAY 482 

    0x9a9d5778,// 515 PAY 483 

    0xfbe60dec,// 516 PAY 484 

    0xc5d524d4,// 517 PAY 485 

    0xf15497df,// 518 PAY 486 

    0x5f980a1c,// 519 PAY 487 

    0x3096b2ab,// 520 PAY 488 

    0x531fbcdf,// 521 PAY 489 

    0x44cf542f,// 522 PAY 490 

    0x388f4d04,// 523 PAY 491 

    0x1037a2a3,// 524 PAY 492 

    0x466ba3c2,// 525 PAY 493 

    0xef23b37e,// 526 PAY 494 

    0xf63f4fca,// 527 PAY 495 

    0x7635a31c,// 528 PAY 496 

    0x2a59b677,// 529 PAY 497 

    0x4f573ebe,// 530 PAY 498 

    0x6dd4a533,// 531 PAY 499 

    0x68d5ecd2,// 532 PAY 500 

    0x830ea1d3,// 533 PAY 501 

/// STA is 1 words. 

/// STA num_pkts       : 151 

/// STA pkt_idx        : 156 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x3c 

    0x02703c97 // 534 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt25_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x07 

/// ECH pdu_tag        : 0x00 

    0x00070000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80842846,// 4 SCX   2 

    0x000043c4,// 5 SCX   3 

    0xd2e3b44b,// 6 SCX   4 

    0x5f3cb2ee,// 7 SCX   5 

    0x353a8a01,// 8 SCX   6 

    0x724b61e5,// 9 SCX   7 

    0x6ec4ed59,// 10 SCX   8 

    0x1f1d2f16,// 11 SCX   9 

    0xea72c941,// 12 SCX  10 

    0xa3360e5e,// 13 SCX  11 

    0x228d46a0,// 14 SCX  12 

    0x004c4f7b,// 15 SCX  13 

    0x97ced582,// 16 SCX  14 

    0xf030b8a7,// 17 SCX  15 

    0x1d36eedd,// 18 SCX  16 

    0xbf715ef8,// 19 SCX  17 

    0xc397a0c3,// 20 SCX  18 

    0x18281ce8,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1147 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 712 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 712 

/// BFD lencrypto      : 432 

/// BFD ofstcrypto     : 80 

/// BFD (ofst+len)cry  : 512 

/// BFD ofstiv         : 48 

/// BFD ofsticv        : 860 

    0x000002c8,// 22 BFD   1 

    0x005001b0,// 23 BFD   2 

    0x035c0030,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c0057b3,// 25 MFM   1 

    0xfcddb7c5,// 26 MFM   2 

    0x21be724c,// 27 MFM   3 

    0xc6cb873e,// 28 MFM   4 

    0xe4394d6e,// 29 MFM   5 

    0x33515c43,// 30 MFM   6 

    0xff8fb4d5,// 31 MFM   7 

    0x9f5947e2,// 32 MFM   8 

    0x28e4c30e,// 33 MFM   9 

    0x0c3d5b36,// 34 MFM  10 

    0x870e20f0,// 35 MFM  11 

    0x3ed5c235,// 36 MFM  12 

    0xa1147c8a,// 37 MFM  13 

    0x4779b0e9,// 38 MFM  14 

    0x657cfed4,// 39 MFM  15 

    0xfd1fe0b1,// 40 MFM  16 

/// BDA is 288 words. 

/// BDA size     is 1147 (0x47b) 

/// BDA id       is 0xdca0 

    0x047bdca0,// 41 BDA   1 

/// PAY Generic Data size   : 1147 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x7df4b163,// 42 PAY   1 

    0xe1c45dcf,// 43 PAY   2 

    0xe70ac6e7,// 44 PAY   3 

    0x91839d07,// 45 PAY   4 

    0x5f81d2a1,// 46 PAY   5 

    0x783e7f31,// 47 PAY   6 

    0x6c658c0e,// 48 PAY   7 

    0xc406c6cd,// 49 PAY   8 

    0x1a91b47f,// 50 PAY   9 

    0x6b78b8eb,// 51 PAY  10 

    0xf3d7aa76,// 52 PAY  11 

    0x86f91cb5,// 53 PAY  12 

    0x18e78945,// 54 PAY  13 

    0x5af88aa7,// 55 PAY  14 

    0x46d6725d,// 56 PAY  15 

    0x680e9781,// 57 PAY  16 

    0x16d2277f,// 58 PAY  17 

    0x33ce8ab4,// 59 PAY  18 

    0x23682f7b,// 60 PAY  19 

    0x3014de08,// 61 PAY  20 

    0x23884209,// 62 PAY  21 

    0xb6c94fdc,// 63 PAY  22 

    0x720bca0d,// 64 PAY  23 

    0x8b3dde98,// 65 PAY  24 

    0x0f719a11,// 66 PAY  25 

    0x09ce5ea3,// 67 PAY  26 

    0x89c38696,// 68 PAY  27 

    0x4dcba1d9,// 69 PAY  28 

    0xe76a13c4,// 70 PAY  29 

    0xc52fccdc,// 71 PAY  30 

    0x98bc6f07,// 72 PAY  31 

    0x28f94c45,// 73 PAY  32 

    0xd6f7fc3e,// 74 PAY  33 

    0xdeb18ec6,// 75 PAY  34 

    0xa92b8a44,// 76 PAY  35 

    0xc87c5c69,// 77 PAY  36 

    0xb758b237,// 78 PAY  37 

    0x49a84a19,// 79 PAY  38 

    0x5f47a1e4,// 80 PAY  39 

    0xa3e337a0,// 81 PAY  40 

    0x4370a6e5,// 82 PAY  41 

    0x2dcd09e2,// 83 PAY  42 

    0x248ba79e,// 84 PAY  43 

    0x83d0e705,// 85 PAY  44 

    0x7ca8f54a,// 86 PAY  45 

    0x71243c05,// 87 PAY  46 

    0x80a096d9,// 88 PAY  47 

    0x01ffec0f,// 89 PAY  48 

    0xe2e8c52e,// 90 PAY  49 

    0x4aa0bfa5,// 91 PAY  50 

    0xa7722413,// 92 PAY  51 

    0x5b628989,// 93 PAY  52 

    0x9fb3b7c4,// 94 PAY  53 

    0x81fc5520,// 95 PAY  54 

    0xfd46471c,// 96 PAY  55 

    0x2aa938e2,// 97 PAY  56 

    0xb639a2c1,// 98 PAY  57 

    0xf06e2555,// 99 PAY  58 

    0x19d17786,// 100 PAY  59 

    0x392b05a6,// 101 PAY  60 

    0x7686cf80,// 102 PAY  61 

    0xb5bed0eb,// 103 PAY  62 

    0x4a6412dc,// 104 PAY  63 

    0x275a8535,// 105 PAY  64 

    0xabe8f7f0,// 106 PAY  65 

    0x05a6686b,// 107 PAY  66 

    0x9a4b2d0a,// 108 PAY  67 

    0xa4431688,// 109 PAY  68 

    0x0f31751f,// 110 PAY  69 

    0x0362cf47,// 111 PAY  70 

    0xcab64238,// 112 PAY  71 

    0x991f0f92,// 113 PAY  72 

    0x9ece3d81,// 114 PAY  73 

    0xe53525b8,// 115 PAY  74 

    0x1c4396a1,// 116 PAY  75 

    0x45203b3d,// 117 PAY  76 

    0xc36d1549,// 118 PAY  77 

    0x80a823da,// 119 PAY  78 

    0xb76e4269,// 120 PAY  79 

    0xbe2f19b6,// 121 PAY  80 

    0x5f147439,// 122 PAY  81 

    0x57844d21,// 123 PAY  82 

    0x98b047ff,// 124 PAY  83 

    0xfa2667ec,// 125 PAY  84 

    0xbdd947c9,// 126 PAY  85 

    0x010adc89,// 127 PAY  86 

    0xe80796a0,// 128 PAY  87 

    0xe35d9608,// 129 PAY  88 

    0x51a53bf6,// 130 PAY  89 

    0x2f7f0272,// 131 PAY  90 

    0x54faf9f9,// 132 PAY  91 

    0x4b6bc105,// 133 PAY  92 

    0x6bbb649e,// 134 PAY  93 

    0xe7ef6644,// 135 PAY  94 

    0x3a792e9d,// 136 PAY  95 

    0xecd23ae0,// 137 PAY  96 

    0x3b69a70d,// 138 PAY  97 

    0xc57b29ae,// 139 PAY  98 

    0x6cb67a23,// 140 PAY  99 

    0xa8a7d82c,// 141 PAY 100 

    0xa11fd298,// 142 PAY 101 

    0xb234f129,// 143 PAY 102 

    0x9b0738c3,// 144 PAY 103 

    0x544744fc,// 145 PAY 104 

    0x4c089b1d,// 146 PAY 105 

    0x38b1c08f,// 147 PAY 106 

    0x6bdf2b6b,// 148 PAY 107 

    0x42085b6b,// 149 PAY 108 

    0xcdd18e4f,// 150 PAY 109 

    0xce117ae1,// 151 PAY 110 

    0xd795e6f1,// 152 PAY 111 

    0x9082fc5c,// 153 PAY 112 

    0x6fdb5ab0,// 154 PAY 113 

    0xc0a9cddb,// 155 PAY 114 

    0xdfa7bf41,// 156 PAY 115 

    0x815830b9,// 157 PAY 116 

    0xc65d0e57,// 158 PAY 117 

    0x89524546,// 159 PAY 118 

    0x55678790,// 160 PAY 119 

    0x6a0852d0,// 161 PAY 120 

    0xb14d234b,// 162 PAY 121 

    0x65238874,// 163 PAY 122 

    0x1a8598ab,// 164 PAY 123 

    0x6c51f52f,// 165 PAY 124 

    0xad538190,// 166 PAY 125 

    0x9eaac000,// 167 PAY 126 

    0xb7feac4a,// 168 PAY 127 

    0x1002a794,// 169 PAY 128 

    0x35c0f746,// 170 PAY 129 

    0xdf027bc1,// 171 PAY 130 

    0x49cc82ef,// 172 PAY 131 

    0x7878b710,// 173 PAY 132 

    0x84c283fb,// 174 PAY 133 

    0x8d15b777,// 175 PAY 134 

    0xaaa02d9b,// 176 PAY 135 

    0x64d34fb1,// 177 PAY 136 

    0x55a21d4b,// 178 PAY 137 

    0x159ac998,// 179 PAY 138 

    0x3fa0b308,// 180 PAY 139 

    0xe5e5d1e8,// 181 PAY 140 

    0x04c210eb,// 182 PAY 141 

    0x770aeab3,// 183 PAY 142 

    0x516f8d9a,// 184 PAY 143 

    0x6c4ad30f,// 185 PAY 144 

    0xcf2805d0,// 186 PAY 145 

    0x7c0319e8,// 187 PAY 146 

    0xcb1e5a98,// 188 PAY 147 

    0x22687683,// 189 PAY 148 

    0x91858bc0,// 190 PAY 149 

    0x38037e8c,// 191 PAY 150 

    0xfe5e442c,// 192 PAY 151 

    0x288d0888,// 193 PAY 152 

    0x3389a719,// 194 PAY 153 

    0x93ca98aa,// 195 PAY 154 

    0x00f6d5ab,// 196 PAY 155 

    0x84e5b47e,// 197 PAY 156 

    0x12a84674,// 198 PAY 157 

    0xa7a5f5af,// 199 PAY 158 

    0xe8b34646,// 200 PAY 159 

    0xcbb7662c,// 201 PAY 160 

    0x7eaa3c5e,// 202 PAY 161 

    0x347f6b4b,// 203 PAY 162 

    0x40daec2f,// 204 PAY 163 

    0xd36456a1,// 205 PAY 164 

    0x98819885,// 206 PAY 165 

    0x2b443b5b,// 207 PAY 166 

    0x3f38b37d,// 208 PAY 167 

    0x67a0f6b8,// 209 PAY 168 

    0x46a376cf,// 210 PAY 169 

    0x1ac5dd71,// 211 PAY 170 

    0xfa9daee8,// 212 PAY 171 

    0xd28bb370,// 213 PAY 172 

    0x9bf0da03,// 214 PAY 173 

    0xd5ef138c,// 215 PAY 174 

    0x404311b4,// 216 PAY 175 

    0x2ecf813c,// 217 PAY 176 

    0x61832313,// 218 PAY 177 

    0xe963afab,// 219 PAY 178 

    0x6df4c7f6,// 220 PAY 179 

    0x29c4862d,// 221 PAY 180 

    0x82a7b3a0,// 222 PAY 181 

    0xb4048017,// 223 PAY 182 

    0xe09914fc,// 224 PAY 183 

    0x4c1999d7,// 225 PAY 184 

    0x267b3e94,// 226 PAY 185 

    0x3278ccf9,// 227 PAY 186 

    0x8f5281b6,// 228 PAY 187 

    0x83e5e018,// 229 PAY 188 

    0xf096ea5e,// 230 PAY 189 

    0xf9c65edb,// 231 PAY 190 

    0xf04b1732,// 232 PAY 191 

    0x1e456a68,// 233 PAY 192 

    0x0feb82e4,// 234 PAY 193 

    0x3ea18867,// 235 PAY 194 

    0x250d63da,// 236 PAY 195 

    0xf6876bce,// 237 PAY 196 

    0xe624bc23,// 238 PAY 197 

    0xd3f7b059,// 239 PAY 198 

    0xb434c241,// 240 PAY 199 

    0xc73cbdf3,// 241 PAY 200 

    0x9f1b4609,// 242 PAY 201 

    0x8b764726,// 243 PAY 202 

    0xbfbd129e,// 244 PAY 203 

    0x654f455f,// 245 PAY 204 

    0xb64833cf,// 246 PAY 205 

    0x59a242e5,// 247 PAY 206 

    0x43d4012e,// 248 PAY 207 

    0x9ae414be,// 249 PAY 208 

    0x0a1b32b6,// 250 PAY 209 

    0x74555bdb,// 251 PAY 210 

    0x7126c488,// 252 PAY 211 

    0x56435821,// 253 PAY 212 

    0xdaa2ff2e,// 254 PAY 213 

    0x67e4ba41,// 255 PAY 214 

    0x7c50eb72,// 256 PAY 215 

    0x25e96fe8,// 257 PAY 216 

    0x0ae90f32,// 258 PAY 217 

    0x27ed41bd,// 259 PAY 218 

    0x7936210f,// 260 PAY 219 

    0x83b236c7,// 261 PAY 220 

    0x9a444e46,// 262 PAY 221 

    0x067b361b,// 263 PAY 222 

    0x7866f16b,// 264 PAY 223 

    0x0b3fa0e1,// 265 PAY 224 

    0x09f06a4c,// 266 PAY 225 

    0x7523d652,// 267 PAY 226 

    0xb18cad38,// 268 PAY 227 

    0xc9aaa5ac,// 269 PAY 228 

    0x2a693c04,// 270 PAY 229 

    0x9f6bb099,// 271 PAY 230 

    0x8f2416a4,// 272 PAY 231 

    0x03cc45d5,// 273 PAY 232 

    0x948800da,// 274 PAY 233 

    0x2c5d292a,// 275 PAY 234 

    0x4eb4bbb3,// 276 PAY 235 

    0xe47bfbd9,// 277 PAY 236 

    0xd3491e13,// 278 PAY 237 

    0xf5f000fa,// 279 PAY 238 

    0xa6748db3,// 280 PAY 239 

    0x14b78aa8,// 281 PAY 240 

    0x745d5458,// 282 PAY 241 

    0x8b968027,// 283 PAY 242 

    0x9f477be0,// 284 PAY 243 

    0xebb850c1,// 285 PAY 244 

    0x6e9c7c9a,// 286 PAY 245 

    0xf5bda129,// 287 PAY 246 

    0xe450cd97,// 288 PAY 247 

    0x71001676,// 289 PAY 248 

    0x4dc24721,// 290 PAY 249 

    0x22896213,// 291 PAY 250 

    0x288e24ae,// 292 PAY 251 

    0xd4ca7c32,// 293 PAY 252 

    0x4c7f1897,// 294 PAY 253 

    0x955f58b8,// 295 PAY 254 

    0x22ca54a4,// 296 PAY 255 

    0x71f30c16,// 297 PAY 256 

    0xa72e2a26,// 298 PAY 257 

    0x4a7043b0,// 299 PAY 258 

    0x9f618f85,// 300 PAY 259 

    0x60c677f0,// 301 PAY 260 

    0x455c04a2,// 302 PAY 261 

    0x04254038,// 303 PAY 262 

    0x1f90b552,// 304 PAY 263 

    0xafd3e56b,// 305 PAY 264 

    0xc8682755,// 306 PAY 265 

    0x157ba22a,// 307 PAY 266 

    0xf032fa4c,// 308 PAY 267 

    0x9e77bcfd,// 309 PAY 268 

    0x12e3ac6f,// 310 PAY 269 

    0x6b2ca92b,// 311 PAY 270 

    0x8c4aba18,// 312 PAY 271 

    0x3b68f99b,// 313 PAY 272 

    0xc589b66a,// 314 PAY 273 

    0x18f4c6d2,// 315 PAY 274 

    0x7f7a6554,// 316 PAY 275 

    0xfbb50d9d,// 317 PAY 276 

    0x83ebec30,// 318 PAY 277 

    0x13af9cb8,// 319 PAY 278 

    0x324d23df,// 320 PAY 279 

    0xed195272,// 321 PAY 280 

    0xa43a2812,// 322 PAY 281 

    0x906d5d2b,// 323 PAY 282 

    0x957967be,// 324 PAY 283 

    0x103c454e,// 325 PAY 284 

    0x7692527c,// 326 PAY 285 

    0xcaec992a,// 327 PAY 286 

    0xf8430700,// 328 PAY 287 

/// STA is 1 words. 

/// STA num_pkts       : 145 

/// STA pkt_idx        : 230 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x4d 

    0x03994d91 // 329 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt26_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x8081280c,// 4 SCX   2 

    0x00001400,// 5 SCX   3 

    0x088e0f43,// 6 SCX   4 

    0xe3fd26f4,// 7 SCX   5 

    0x21c89581,// 8 SCX   6 

    0x91e8ee3f,// 9 SCX   7 

    0x2ddebcc4,// 10 SCX   8 

    0x2ead8d11,// 11 SCX   9 

    0x0325c5e8,// 12 SCX  10 

    0x486e0243,// 13 SCX  11 

    0x31eeaafa,// 14 SCX  12 

    0x97f7fc5d,// 15 SCX  13 

    0x1fa381f8,// 16 SCX  14 

    0xef3ae0c4,// 17 SCX  15 

    0x6eb3f88a,// 18 SCX  16 

    0xbd0e2b6c,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 782 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 491 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 491 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 112 

/// BFD (ofst+len)cry  : 192 

/// BFD ofstiv         : 72 

/// BFD ofsticv        : 632 

    0x000001eb,// 20 BFD   1 

    0x00700050,// 21 BFD   2 

    0x02780048,// 22 BFD   3 

/// MFM is 10 words. 

/// MFM vldnibs        : 45 

    0x4500b2df,// 23 MFM   1 

    0xbaf0c343,// 24 MFM   2 

    0xe15f96a9,// 25 MFM   3 

    0xb1b72888,// 26 MFM   4 

    0x44bdff44,// 27 MFM   5 

    0x67108224,// 28 MFM   6 

    0x9ae728ca,// 29 MFM   7 

    0x4d89c1af,// 30 MFM   8 

    0x03fa1245,// 31 MFM   9 

    0xf0000000,// 32 MFM  10 

/// BDA is 197 words. 

/// BDA size     is 782 (0x30e) 

/// BDA id       is 0x9ed4 

    0x030e9ed4,// 33 BDA   1 

/// PAY Generic Data size   : 782 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x327cc595,// 34 PAY   1 

    0x4818735e,// 35 PAY   2 

    0xad798bab,// 36 PAY   3 

    0x013bff89,// 37 PAY   4 

    0x0b2a766b,// 38 PAY   5 

    0x177126a8,// 39 PAY   6 

    0x5ca3f0cc,// 40 PAY   7 

    0x0524e82a,// 41 PAY   8 

    0x2ff3bffe,// 42 PAY   9 

    0x0e95af3d,// 43 PAY  10 

    0xe12dcf0c,// 44 PAY  11 

    0x58d0dff5,// 45 PAY  12 

    0x59697f29,// 46 PAY  13 

    0x7f0a5232,// 47 PAY  14 

    0xee6bc4aa,// 48 PAY  15 

    0x66478667,// 49 PAY  16 

    0xc34955eb,// 50 PAY  17 

    0xe4f06231,// 51 PAY  18 

    0xd94c5c85,// 52 PAY  19 

    0x898a5761,// 53 PAY  20 

    0xe28fee4e,// 54 PAY  21 

    0xfb0b5062,// 55 PAY  22 

    0x838b01ff,// 56 PAY  23 

    0x65819d83,// 57 PAY  24 

    0x8f73abe9,// 58 PAY  25 

    0xd9da52b2,// 59 PAY  26 

    0xa717ca0a,// 60 PAY  27 

    0xe74865d0,// 61 PAY  28 

    0x45ac304c,// 62 PAY  29 

    0x015561af,// 63 PAY  30 

    0x34f8c4a2,// 64 PAY  31 

    0x47cf9ef6,// 65 PAY  32 

    0xf8efc65c,// 66 PAY  33 

    0xca318413,// 67 PAY  34 

    0x4fd61980,// 68 PAY  35 

    0x30981d89,// 69 PAY  36 

    0xd6112164,// 70 PAY  37 

    0xa0b997c0,// 71 PAY  38 

    0x610ba19e,// 72 PAY  39 

    0x0573b79b,// 73 PAY  40 

    0x2d4b8da5,// 74 PAY  41 

    0x4e300de1,// 75 PAY  42 

    0xd3fdf4f8,// 76 PAY  43 

    0xed213bb6,// 77 PAY  44 

    0x7870bbe3,// 78 PAY  45 

    0x8e58bed5,// 79 PAY  46 

    0xcd727f95,// 80 PAY  47 

    0x7ebe792e,// 81 PAY  48 

    0x1b86f8a3,// 82 PAY  49 

    0xf659b54f,// 83 PAY  50 

    0x8b40e11d,// 84 PAY  51 

    0x65da9e53,// 85 PAY  52 

    0x06fa45d2,// 86 PAY  53 

    0x0c01d937,// 87 PAY  54 

    0xb70c49a6,// 88 PAY  55 

    0xbaf927b7,// 89 PAY  56 

    0x4b0b157e,// 90 PAY  57 

    0xd7f06a10,// 91 PAY  58 

    0x4b4a9bd0,// 92 PAY  59 

    0x2545aeb3,// 93 PAY  60 

    0x71498839,// 94 PAY  61 

    0xf0e5c9df,// 95 PAY  62 

    0xe92a5965,// 96 PAY  63 

    0x4af32a96,// 97 PAY  64 

    0x74f2f203,// 98 PAY  65 

    0x93647cb4,// 99 PAY  66 

    0x52374408,// 100 PAY  67 

    0x3183d534,// 101 PAY  68 

    0xe423a493,// 102 PAY  69 

    0x3a3f1fcc,// 103 PAY  70 

    0x402871b7,// 104 PAY  71 

    0xb9c88a3f,// 105 PAY  72 

    0x614c1484,// 106 PAY  73 

    0x08fcb9db,// 107 PAY  74 

    0x600bb3d3,// 108 PAY  75 

    0xc8bd16e4,// 109 PAY  76 

    0x6be464d6,// 110 PAY  77 

    0xea03d276,// 111 PAY  78 

    0xb0ef486d,// 112 PAY  79 

    0xdcc8e21d,// 113 PAY  80 

    0x2461fe30,// 114 PAY  81 

    0xa97d17fa,// 115 PAY  82 

    0xc16effa9,// 116 PAY  83 

    0x0527ff33,// 117 PAY  84 

    0xb7f05911,// 118 PAY  85 

    0xca82ad1e,// 119 PAY  86 

    0xecf4b30f,// 120 PAY  87 

    0x86f1557f,// 121 PAY  88 

    0x72a8619a,// 122 PAY  89 

    0x27e3f5da,// 123 PAY  90 

    0xe6e14e4d,// 124 PAY  91 

    0x8508dae4,// 125 PAY  92 

    0xed2a7a1c,// 126 PAY  93 

    0xf55ec87f,// 127 PAY  94 

    0xb2b25811,// 128 PAY  95 

    0xae51e9d0,// 129 PAY  96 

    0x00799602,// 130 PAY  97 

    0xa7a5b9c8,// 131 PAY  98 

    0x8e420739,// 132 PAY  99 

    0x08bbc7c4,// 133 PAY 100 

    0xca33d641,// 134 PAY 101 

    0x5d693347,// 135 PAY 102 

    0xf9f655b0,// 136 PAY 103 

    0x7bf9704b,// 137 PAY 104 

    0x1cc1188f,// 138 PAY 105 

    0x9d7488c6,// 139 PAY 106 

    0x885a5071,// 140 PAY 107 

    0xa0fc0d4f,// 141 PAY 108 

    0x15552445,// 142 PAY 109 

    0x6ceff593,// 143 PAY 110 

    0x9cf0c3af,// 144 PAY 111 

    0x30c985c9,// 145 PAY 112 

    0x5eb642de,// 146 PAY 113 

    0x25188492,// 147 PAY 114 

    0x845f61c3,// 148 PAY 115 

    0x5ca7207c,// 149 PAY 116 

    0x9ca7e81e,// 150 PAY 117 

    0x34917a4e,// 151 PAY 118 

    0x77a3b762,// 152 PAY 119 

    0xee227809,// 153 PAY 120 

    0x6b8a69ca,// 154 PAY 121 

    0xa4e8f9b2,// 155 PAY 122 

    0x418186d5,// 156 PAY 123 

    0x79b2f12c,// 157 PAY 124 

    0x31851f12,// 158 PAY 125 

    0xd00c6623,// 159 PAY 126 

    0x319a977e,// 160 PAY 127 

    0x432b03be,// 161 PAY 128 

    0x6043777a,// 162 PAY 129 

    0xb510d73f,// 163 PAY 130 

    0x74d11c00,// 164 PAY 131 

    0x97964cd5,// 165 PAY 132 

    0x9da03fe8,// 166 PAY 133 

    0xe4bfa627,// 167 PAY 134 

    0xb9257901,// 168 PAY 135 

    0x8b1ea506,// 169 PAY 136 

    0x916f8fda,// 170 PAY 137 

    0x537b4228,// 171 PAY 138 

    0x82941333,// 172 PAY 139 

    0x061b83b0,// 173 PAY 140 

    0xe6282a41,// 174 PAY 141 

    0xd0fc2855,// 175 PAY 142 

    0xea3aff46,// 176 PAY 143 

    0x9b070124,// 177 PAY 144 

    0x3b4370be,// 178 PAY 145 

    0x811ff64d,// 179 PAY 146 

    0x1d8a956a,// 180 PAY 147 

    0x662ad993,// 181 PAY 148 

    0xdd55eb56,// 182 PAY 149 

    0x0107d520,// 183 PAY 150 

    0x995800e4,// 184 PAY 151 

    0xb601fe98,// 185 PAY 152 

    0x175199a4,// 186 PAY 153 

    0xf209a461,// 187 PAY 154 

    0x4e847c22,// 188 PAY 155 

    0x94b9e2b2,// 189 PAY 156 

    0x50dfd18f,// 190 PAY 157 

    0xe2cd49c6,// 191 PAY 158 

    0x1f10064b,// 192 PAY 159 

    0x03475ad6,// 193 PAY 160 

    0x0e32e62b,// 194 PAY 161 

    0xa0dbe20a,// 195 PAY 162 

    0xde9334a9,// 196 PAY 163 

    0x04c0c320,// 197 PAY 164 

    0x03ba2472,// 198 PAY 165 

    0xe452b2c7,// 199 PAY 166 

    0xed71cd37,// 200 PAY 167 

    0x38017a48,// 201 PAY 168 

    0x8c39eb37,// 202 PAY 169 

    0xc75334ab,// 203 PAY 170 

    0x2f28d248,// 204 PAY 171 

    0xfb48fbe5,// 205 PAY 172 

    0xe5563282,// 206 PAY 173 

    0xd23804f6,// 207 PAY 174 

    0xd9f5584d,// 208 PAY 175 

    0x02e0c81d,// 209 PAY 176 

    0x469fd1c4,// 210 PAY 177 

    0x72208c13,// 211 PAY 178 

    0x2278cab0,// 212 PAY 179 

    0x5166ac2a,// 213 PAY 180 

    0xe0ecc17b,// 214 PAY 181 

    0xf7ae33a2,// 215 PAY 182 

    0xcf8326dc,// 216 PAY 183 

    0xd7e26124,// 217 PAY 184 

    0x2c2df0a3,// 218 PAY 185 

    0xc66e4657,// 219 PAY 186 

    0x7e2f0c2f,// 220 PAY 187 

    0xc9c54ef2,// 221 PAY 188 

    0xf4925a3d,// 222 PAY 189 

    0xc8a83016,// 223 PAY 190 

    0xf8c98512,// 224 PAY 191 

    0xfb4d902a,// 225 PAY 192 

    0xdea9fde5,// 226 PAY 193 

    0xc171d44c,// 227 PAY 194 

    0xa933e6bb,// 228 PAY 195 

    0x8a720000,// 229 PAY 196 

/// STA is 1 words. 

/// STA num_pkts       : 14 

/// STA pkt_idx        : 249 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xc8 

    0x03e4c80e // 230 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt27_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x809128b1,// 4 SCX   2 

    0x00003382,// 5 SCX   3 

    0x6d37041a,// 6 SCX   4 

    0x0fa72df2,// 7 SCX   5 

    0x5cf699eb,// 8 SCX   6 

    0x2d268707,// 9 SCX   7 

    0x06bd6d64,// 10 SCX   8 

    0xb319e891,// 11 SCX   9 

    0xe593196d,// 12 SCX  10 

    0x5a45ec5f,// 13 SCX  11 

    0x3bc823b4,// 14 SCX  12 

    0xb0298441,// 15 SCX  13 

    0xdc61a33f,// 16 SCX  14 

    0xc97cb18f,// 17 SCX  15 

    0xaf970922,// 18 SCX  16 

    0x1bc6e180,// 19 SCX  17 

    0xb4d70f48,// 20 SCX  18 

    0xfa3a572b,// 21 SCX  19 

    0x70791114,// 22 SCX  20 

    0xbfa91e77,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1273 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 1055 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1055 

/// BFD lencrypto      : 88 

/// BFD ofstcrypto     : 952 

/// BFD (ofst+len)cry  : 1040 

/// BFD ofstiv         : 288 

/// BFD ofsticv        : 1220 

    0x0000041f,// 24 BFD   1 

    0x03b80058,// 25 BFD   2 

    0x04c40120,// 26 BFD   3 

/// MFM is 4 words. 

/// MFM vldnibs        : 18 

    0x18008033,// 27 MFM   1 

    0x0ee1bd5c,// 28 MFM   2 

    0x4c8fc6ad,// 29 MFM   3 

    0x9aa00000,// 30 MFM   4 

/// BDA is 320 words. 

/// BDA size     is 1273 (0x4f9) 

/// BDA id       is 0x601b 

    0x04f9601b,// 31 BDA   1 

/// PAY Generic Data size   : 1273 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x13346c49,// 32 PAY   1 

    0x16733b6a,// 33 PAY   2 

    0xfd9439c4,// 34 PAY   3 

    0x778cb88a,// 35 PAY   4 

    0x14623871,// 36 PAY   5 

    0x14c0daba,// 37 PAY   6 

    0xb72ef37a,// 38 PAY   7 

    0x24ae7de6,// 39 PAY   8 

    0x00382e34,// 40 PAY   9 

    0x6c475dbe,// 41 PAY  10 

    0xad267448,// 42 PAY  11 

    0x864f6e64,// 43 PAY  12 

    0x4938f51d,// 44 PAY  13 

    0x8951f9d9,// 45 PAY  14 

    0x08c36268,// 46 PAY  15 

    0x4d96ec72,// 47 PAY  16 

    0xa7fd8e54,// 48 PAY  17 

    0x38e0c1c7,// 49 PAY  18 

    0xa00af3a7,// 50 PAY  19 

    0x2254febf,// 51 PAY  20 

    0x72267066,// 52 PAY  21 

    0x53d29d78,// 53 PAY  22 

    0x3b228e73,// 54 PAY  23 

    0xdcccc8c5,// 55 PAY  24 

    0x9c3b3cd3,// 56 PAY  25 

    0xd0214db1,// 57 PAY  26 

    0x11994723,// 58 PAY  27 

    0x5bd3b5d6,// 59 PAY  28 

    0x3ec8b269,// 60 PAY  29 

    0xcbe16cda,// 61 PAY  30 

    0x4aa07623,// 62 PAY  31 

    0xcd4682fc,// 63 PAY  32 

    0x14721f55,// 64 PAY  33 

    0x61bbfb88,// 65 PAY  34 

    0x298c97e7,// 66 PAY  35 

    0xc2bb8a0b,// 67 PAY  36 

    0xb0986a58,// 68 PAY  37 

    0x422145f2,// 69 PAY  38 

    0x4433c358,// 70 PAY  39 

    0x1bcce3d5,// 71 PAY  40 

    0xefa74849,// 72 PAY  41 

    0xb323ed99,// 73 PAY  42 

    0x8d4ed436,// 74 PAY  43 

    0xfab34cd7,// 75 PAY  44 

    0x4e9e2bbe,// 76 PAY  45 

    0xbbe2c00e,// 77 PAY  46 

    0xc59874aa,// 78 PAY  47 

    0xb40aeccb,// 79 PAY  48 

    0x06601553,// 80 PAY  49 

    0x40b008aa,// 81 PAY  50 

    0x840ff390,// 82 PAY  51 

    0x05647ea4,// 83 PAY  52 

    0x8e2ab29e,// 84 PAY  53 

    0x6d795f62,// 85 PAY  54 

    0x4b5e26df,// 86 PAY  55 

    0x82b516fe,// 87 PAY  56 

    0xd52b87d3,// 88 PAY  57 

    0xa8f92792,// 89 PAY  58 

    0x4ac43252,// 90 PAY  59 

    0xcac7604f,// 91 PAY  60 

    0x82a6dbdb,// 92 PAY  61 

    0x9f370de8,// 93 PAY  62 

    0xbf071cd0,// 94 PAY  63 

    0x33f76e2b,// 95 PAY  64 

    0x7f74421f,// 96 PAY  65 

    0x0e30aa13,// 97 PAY  66 

    0x542bb53f,// 98 PAY  67 

    0x1f874acc,// 99 PAY  68 

    0x98089caf,// 100 PAY  69 

    0x8ae6f424,// 101 PAY  70 

    0x2b3ad38f,// 102 PAY  71 

    0x8fd07439,// 103 PAY  72 

    0x91a4b6b5,// 104 PAY  73 

    0x46490b9b,// 105 PAY  74 

    0x6710e2d1,// 106 PAY  75 

    0x2b1203a7,// 107 PAY  76 

    0xeecf633a,// 108 PAY  77 

    0xfac1311a,// 109 PAY  78 

    0x03e452a4,// 110 PAY  79 

    0x6311561b,// 111 PAY  80 

    0x3f3aa77e,// 112 PAY  81 

    0xc09be41d,// 113 PAY  82 

    0x4e77992a,// 114 PAY  83 

    0x8ecde911,// 115 PAY  84 

    0x60be04b1,// 116 PAY  85 

    0xe2bd31a0,// 117 PAY  86 

    0x1c87e278,// 118 PAY  87 

    0xcfa6e3b9,// 119 PAY  88 

    0x7bc8bc72,// 120 PAY  89 

    0x0e038cc9,// 121 PAY  90 

    0x9294ca67,// 122 PAY  91 

    0x25419164,// 123 PAY  92 

    0x89babc96,// 124 PAY  93 

    0x20e662bf,// 125 PAY  94 

    0xfd79d9ab,// 126 PAY  95 

    0x8628c252,// 127 PAY  96 

    0x20916bf9,// 128 PAY  97 

    0xfe274369,// 129 PAY  98 

    0x2ad1dd1f,// 130 PAY  99 

    0x6178d11f,// 131 PAY 100 

    0x0b6d479f,// 132 PAY 101 

    0x312e92f3,// 133 PAY 102 

    0x90124922,// 134 PAY 103 

    0xbaf82b70,// 135 PAY 104 

    0xbfb14f64,// 136 PAY 105 

    0xc3eaf093,// 137 PAY 106 

    0x2e399875,// 138 PAY 107 

    0xd876feab,// 139 PAY 108 

    0xce4c79bd,// 140 PAY 109 

    0x6f503e4d,// 141 PAY 110 

    0x564b7b24,// 142 PAY 111 

    0x0baa53ce,// 143 PAY 112 

    0xadad0818,// 144 PAY 113 

    0x3b01feeb,// 145 PAY 114 

    0x1d0192b5,// 146 PAY 115 

    0xa10c6f49,// 147 PAY 116 

    0x3a67d05f,// 148 PAY 117 

    0x65b62b43,// 149 PAY 118 

    0xdebf5738,// 150 PAY 119 

    0x9e5285c5,// 151 PAY 120 

    0x73eb350d,// 152 PAY 121 

    0x33d5ae71,// 153 PAY 122 

    0x62d489eb,// 154 PAY 123 

    0xe873bb5b,// 155 PAY 124 

    0x8d84ba27,// 156 PAY 125 

    0xe72beab2,// 157 PAY 126 

    0xfd3fe1a6,// 158 PAY 127 

    0x63ffab63,// 159 PAY 128 

    0xc9fbca15,// 160 PAY 129 

    0x4d248eec,// 161 PAY 130 

    0xa9319df3,// 162 PAY 131 

    0x26b6b359,// 163 PAY 132 

    0xdefe6e9f,// 164 PAY 133 

    0x0fc344c4,// 165 PAY 134 

    0xefcb1f17,// 166 PAY 135 

    0x37d976ae,// 167 PAY 136 

    0xbf1bd335,// 168 PAY 137 

    0x24fb2e1c,// 169 PAY 138 

    0xc420993c,// 170 PAY 139 

    0x73421364,// 171 PAY 140 

    0xe5c4cbe2,// 172 PAY 141 

    0x5d448a3f,// 173 PAY 142 

    0xea48a347,// 174 PAY 143 

    0xee5f7557,// 175 PAY 144 

    0x859dc015,// 176 PAY 145 

    0x3c3701e0,// 177 PAY 146 

    0xa75ee144,// 178 PAY 147 

    0xfec1666f,// 179 PAY 148 

    0x8c97e0cb,// 180 PAY 149 

    0x41f179f3,// 181 PAY 150 

    0x31a3f847,// 182 PAY 151 

    0x81ac6f55,// 183 PAY 152 

    0xf66936b5,// 184 PAY 153 

    0xc9f11a37,// 185 PAY 154 

    0xe476ff76,// 186 PAY 155 

    0x5de2fd1d,// 187 PAY 156 

    0x9200cfd4,// 188 PAY 157 

    0x470cdc1a,// 189 PAY 158 

    0x96cd4e84,// 190 PAY 159 

    0x8b0dba15,// 191 PAY 160 

    0x9dab3a58,// 192 PAY 161 

    0x10fd2c0d,// 193 PAY 162 

    0xb1af086e,// 194 PAY 163 

    0xb5ac9d08,// 195 PAY 164 

    0x338e5229,// 196 PAY 165 

    0xc8a95715,// 197 PAY 166 

    0xc70bb72e,// 198 PAY 167 

    0x6137a0e5,// 199 PAY 168 

    0xf1d76e3f,// 200 PAY 169 

    0x3ff384d1,// 201 PAY 170 

    0xc4282a86,// 202 PAY 171 

    0xfa97a66e,// 203 PAY 172 

    0xc9e4d52f,// 204 PAY 173 

    0xcde2c7d6,// 205 PAY 174 

    0x3825aee1,// 206 PAY 175 

    0x44d8653c,// 207 PAY 176 

    0xcaaffb51,// 208 PAY 177 

    0x6d22e808,// 209 PAY 178 

    0x9937a653,// 210 PAY 179 

    0x8f259508,// 211 PAY 180 

    0xe4fb6351,// 212 PAY 181 

    0xbf9e05da,// 213 PAY 182 

    0x0f56a1ea,// 214 PAY 183 

    0x519ecc08,// 215 PAY 184 

    0x7906adea,// 216 PAY 185 

    0x3d12bc70,// 217 PAY 186 

    0xca58886d,// 218 PAY 187 

    0x36bd466c,// 219 PAY 188 

    0xea6842c8,// 220 PAY 189 

    0x23abb37c,// 221 PAY 190 

    0x83710f02,// 222 PAY 191 

    0xde8f91b8,// 223 PAY 192 

    0xae1f2391,// 224 PAY 193 

    0x8cb028b8,// 225 PAY 194 

    0xcbcfaca3,// 226 PAY 195 

    0x5902577d,// 227 PAY 196 

    0x1c200432,// 228 PAY 197 

    0x5a35d67c,// 229 PAY 198 

    0x2de067fe,// 230 PAY 199 

    0x963efeb6,// 231 PAY 200 

    0x5a491443,// 232 PAY 201 

    0x4ee22746,// 233 PAY 202 

    0xf12563be,// 234 PAY 203 

    0x5f21d50e,// 235 PAY 204 

    0x1a83697a,// 236 PAY 205 

    0x71772c43,// 237 PAY 206 

    0x222dac4e,// 238 PAY 207 

    0x29245153,// 239 PAY 208 

    0xdb27cec1,// 240 PAY 209 

    0x6e03d163,// 241 PAY 210 

    0xbc79c897,// 242 PAY 211 

    0x4470650e,// 243 PAY 212 

    0x031481f0,// 244 PAY 213 

    0x1952c600,// 245 PAY 214 

    0xa59181ba,// 246 PAY 215 

    0x7d280840,// 247 PAY 216 

    0x7396fef7,// 248 PAY 217 

    0xfaca1bc6,// 249 PAY 218 

    0x80ff6115,// 250 PAY 219 

    0xfb901840,// 251 PAY 220 

    0xd2ceba4a,// 252 PAY 221 

    0xdd45d0a8,// 253 PAY 222 

    0x3ab5efa3,// 254 PAY 223 

    0x00b79393,// 255 PAY 224 

    0x2978ea9a,// 256 PAY 225 

    0xdb5d39e2,// 257 PAY 226 

    0x602e43bc,// 258 PAY 227 

    0x36e14a0e,// 259 PAY 228 

    0x3af18044,// 260 PAY 229 

    0x028efb78,// 261 PAY 230 

    0x1603eb35,// 262 PAY 231 

    0x0ceb9214,// 263 PAY 232 

    0x50705bad,// 264 PAY 233 

    0xd38244a4,// 265 PAY 234 

    0x12a1e0ef,// 266 PAY 235 

    0x84fa8a69,// 267 PAY 236 

    0xbd5af0a6,// 268 PAY 237 

    0x64535df4,// 269 PAY 238 

    0x50313752,// 270 PAY 239 

    0xccb4f01f,// 271 PAY 240 

    0x54db06d7,// 272 PAY 241 

    0x88844be0,// 273 PAY 242 

    0x232595ff,// 274 PAY 243 

    0xb7afd10f,// 275 PAY 244 

    0x6c520e1d,// 276 PAY 245 

    0x5832747d,// 277 PAY 246 

    0x8334fce1,// 278 PAY 247 

    0xc43cb2a0,// 279 PAY 248 

    0x26b28e63,// 280 PAY 249 

    0x6daa9b49,// 281 PAY 250 

    0x1a6ef6bb,// 282 PAY 251 

    0x7951d13e,// 283 PAY 252 

    0xcb0b677f,// 284 PAY 253 

    0xc8808955,// 285 PAY 254 

    0x1dc2ce50,// 286 PAY 255 

    0xc53544ca,// 287 PAY 256 

    0xf057e363,// 288 PAY 257 

    0x9fead9c7,// 289 PAY 258 

    0x60502174,// 290 PAY 259 

    0xd648bedb,// 291 PAY 260 

    0x3069ad6c,// 292 PAY 261 

    0x32ac74fe,// 293 PAY 262 

    0x659c8d07,// 294 PAY 263 

    0x1fb86ff7,// 295 PAY 264 

    0x5bed8df3,// 296 PAY 265 

    0x9c869d15,// 297 PAY 266 

    0x3a2bcea4,// 298 PAY 267 

    0xb9bf262c,// 299 PAY 268 

    0x72d3626f,// 300 PAY 269 

    0x38acc4cc,// 301 PAY 270 

    0xe02ceb22,// 302 PAY 271 

    0xb4c356ca,// 303 PAY 272 

    0xe1bfa310,// 304 PAY 273 

    0x312665ac,// 305 PAY 274 

    0xcfd1cf40,// 306 PAY 275 

    0x8685231a,// 307 PAY 276 

    0x2dae3dd3,// 308 PAY 277 

    0x9dcda84f,// 309 PAY 278 

    0xbdc83a90,// 310 PAY 279 

    0x74a77dc2,// 311 PAY 280 

    0x69c51ae4,// 312 PAY 281 

    0xcbed9743,// 313 PAY 282 

    0x2ef1ad4d,// 314 PAY 283 

    0xbecd01c9,// 315 PAY 284 

    0x5b15d28c,// 316 PAY 285 

    0x437606aa,// 317 PAY 286 

    0xad52e28a,// 318 PAY 287 

    0x68fecd51,// 319 PAY 288 

    0xbebe1aee,// 320 PAY 289 

    0x75c0cef3,// 321 PAY 290 

    0xe264427c,// 322 PAY 291 

    0x46eed095,// 323 PAY 292 

    0x66db09f6,// 324 PAY 293 

    0x56385851,// 325 PAY 294 

    0xd22f9f61,// 326 PAY 295 

    0x8a4ac323,// 327 PAY 296 

    0x7665aded,// 328 PAY 297 

    0x9fbfd3aa,// 329 PAY 298 

    0x84a84f36,// 330 PAY 299 

    0x48fc195c,// 331 PAY 300 

    0x90411d14,// 332 PAY 301 

    0x06526bc2,// 333 PAY 302 

    0x6462a488,// 334 PAY 303 

    0x1b504883,// 335 PAY 304 

    0x613b2680,// 336 PAY 305 

    0xb54731dd,// 337 PAY 306 

    0x7f1916bd,// 338 PAY 307 

    0xe0fd9b30,// 339 PAY 308 

    0x61ecfcf2,// 340 PAY 309 

    0xa0b9ef5a,// 341 PAY 310 

    0xcbaee0b7,// 342 PAY 311 

    0x6345bf0b,// 343 PAY 312 

    0xc7d42e9b,// 344 PAY 313 

    0xfe687fba,// 345 PAY 314 

    0xc78eeae2,// 346 PAY 315 

    0x78a49853,// 347 PAY 316 

    0x7e152387,// 348 PAY 317 

    0x0e4947ed,// 349 PAY 318 

    0x26000000,// 350 PAY 319 

/// STA is 1 words. 

/// STA num_pkts       : 214 

/// STA pkt_idx        : 254 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xc1 

    0x03f8c1d6 // 351 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt28_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x8080287b,// 4 SCX   2 

    0x00003400,// 5 SCX   3 

    0xa5af314d,// 6 SCX   4 

    0x2249d787,// 7 SCX   5 

    0x63298fd8,// 8 SCX   6 

    0xd8dc7a5b,// 9 SCX   7 

    0x27f1780c,// 10 SCX   8 

    0x70bfbfd8,// 11 SCX   9 

    0x45de8e14,// 12 SCX  10 

    0x724fc48f,// 13 SCX  11 

    0x217a9d42,// 14 SCX  12 

    0x38f2a709,// 15 SCX  13 

    0xca9e9622,// 16 SCX  14 

    0xfde26edb,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1817 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1037 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1037 

/// BFD lencrypto      : 208 

/// BFD ofstcrypto     : 348 

/// BFD (ofst+len)cry  : 556 

/// BFD ofstiv         : 304 

/// BFD ofsticv        : 1520 

    0x0000040d,// 18 BFD   1 

    0x015c00d0,// 19 BFD   2 

    0x05f00130,// 20 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00e31f,// 21 MFM   1 

    0x1e95a623,// 22 MFM   2 

    0x6ad094d5,// 23 MFM   3 

    0x9ff40722,// 24 MFM   4 

    0xeb7b2af5,// 25 MFM   5 

    0x6e3c02dc,// 26 MFM   6 

    0x35697580,// 27 MFM   7 

    0xe3928efc,// 28 MFM   8 

    0x91c20bf8,// 29 MFM   9 

    0x3cae7dd4,// 30 MFM  10 

    0x633fd88c,// 31 MFM  11 

    0xa890d2f4,// 32 MFM  12 

    0x89118b1d,// 33 MFM  13 

    0xc959bbfc,// 34 MFM  14 

    0xb598e957,// 35 MFM  15 

    0x32070536,// 36 MFM  16 

/// BDA is 456 words. 

/// BDA size     is 1817 (0x719) 

/// BDA id       is 0x24a3 

    0x071924a3,// 37 BDA   1 

/// PAY Generic Data size   : 1817 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0xda49730c,// 38 PAY   1 

    0xfe45c0ff,// 39 PAY   2 

    0x756fda51,// 40 PAY   3 

    0x88b8ce1d,// 41 PAY   4 

    0x16cfbd4c,// 42 PAY   5 

    0x58579e23,// 43 PAY   6 

    0x71047811,// 44 PAY   7 

    0x3c41c08d,// 45 PAY   8 

    0xa435ca4c,// 46 PAY   9 

    0x81d46969,// 47 PAY  10 

    0xd43474b4,// 48 PAY  11 

    0xa26982c7,// 49 PAY  12 

    0x6e4da85e,// 50 PAY  13 

    0x776fef04,// 51 PAY  14 

    0xa4958a77,// 52 PAY  15 

    0x163f2e06,// 53 PAY  16 

    0x14efc315,// 54 PAY  17 

    0x58be96ba,// 55 PAY  18 

    0xbb575b00,// 56 PAY  19 

    0x7cdd82e5,// 57 PAY  20 

    0x48d3b6a2,// 58 PAY  21 

    0xd438e04b,// 59 PAY  22 

    0x5cc79687,// 60 PAY  23 

    0xcea4184e,// 61 PAY  24 

    0xff9eb5e5,// 62 PAY  25 

    0x8791ac5f,// 63 PAY  26 

    0x05b81d17,// 64 PAY  27 

    0x3a6c8254,// 65 PAY  28 

    0xf64565c2,// 66 PAY  29 

    0x93c25d7c,// 67 PAY  30 

    0x314b3f43,// 68 PAY  31 

    0x7bea6b0b,// 69 PAY  32 

    0xbcc46941,// 70 PAY  33 

    0x55a75b8d,// 71 PAY  34 

    0xc6537966,// 72 PAY  35 

    0xa7c0863f,// 73 PAY  36 

    0x1b43b86f,// 74 PAY  37 

    0x177c6e9e,// 75 PAY  38 

    0xcc0975d1,// 76 PAY  39 

    0x0e05f001,// 77 PAY  40 

    0x243dce1c,// 78 PAY  41 

    0xc1fc80c4,// 79 PAY  42 

    0x7f173b72,// 80 PAY  43 

    0xf46b1bfe,// 81 PAY  44 

    0x98a33d18,// 82 PAY  45 

    0xc757d2d0,// 83 PAY  46 

    0xa46c03b5,// 84 PAY  47 

    0xd74ab563,// 85 PAY  48 

    0xa52499ab,// 86 PAY  49 

    0xfabac680,// 87 PAY  50 

    0x07cd5628,// 88 PAY  51 

    0x8eb3d4ee,// 89 PAY  52 

    0x175dd802,// 90 PAY  53 

    0x58e374e4,// 91 PAY  54 

    0x62cf8c14,// 92 PAY  55 

    0xb747aa4c,// 93 PAY  56 

    0x822dad3a,// 94 PAY  57 

    0x642f8073,// 95 PAY  58 

    0xd6b8b21c,// 96 PAY  59 

    0x78800bd0,// 97 PAY  60 

    0x8c51e4f9,// 98 PAY  61 

    0x087765c2,// 99 PAY  62 

    0xda99b2b1,// 100 PAY  63 

    0x1ad5cbb4,// 101 PAY  64 

    0xb16c7e95,// 102 PAY  65 

    0xcc4e2c2c,// 103 PAY  66 

    0x60cf8022,// 104 PAY  67 

    0x445a817d,// 105 PAY  68 

    0xbfb0ee22,// 106 PAY  69 

    0x3fcf5385,// 107 PAY  70 

    0x1b00aaa4,// 108 PAY  71 

    0xe66d332e,// 109 PAY  72 

    0xb69f53cb,// 110 PAY  73 

    0x6f881758,// 111 PAY  74 

    0x1c133094,// 112 PAY  75 

    0x74c778e0,// 113 PAY  76 

    0x6b47d71c,// 114 PAY  77 

    0x26b797ce,// 115 PAY  78 

    0x4f32c755,// 116 PAY  79 

    0x69c16eac,// 117 PAY  80 

    0x66ccd825,// 118 PAY  81 

    0xe6cb435f,// 119 PAY  82 

    0x09f622e2,// 120 PAY  83 

    0x3356a0f6,// 121 PAY  84 

    0xcb9db251,// 122 PAY  85 

    0x23f9925e,// 123 PAY  86 

    0xfd03ceb4,// 124 PAY  87 

    0x656941da,// 125 PAY  88 

    0x0d49b6db,// 126 PAY  89 

    0x8e066c23,// 127 PAY  90 

    0x9d8dee90,// 128 PAY  91 

    0xada6389d,// 129 PAY  92 

    0x3ef18d87,// 130 PAY  93 

    0x6529d4d8,// 131 PAY  94 

    0x18b21899,// 132 PAY  95 

    0x39568696,// 133 PAY  96 

    0x229681d4,// 134 PAY  97 

    0xff9d524a,// 135 PAY  98 

    0xf73c2bce,// 136 PAY  99 

    0xe989bd32,// 137 PAY 100 

    0x910c941f,// 138 PAY 101 

    0x7ff0c36c,// 139 PAY 102 

    0xfc14c410,// 140 PAY 103 

    0xa58f5920,// 141 PAY 104 

    0xb599828a,// 142 PAY 105 

    0x4dbd22c7,// 143 PAY 106 

    0xbbb2819f,// 144 PAY 107 

    0x2c70022d,// 145 PAY 108 

    0x09d0b915,// 146 PAY 109 

    0x43071f6f,// 147 PAY 110 

    0xb4a2e1bf,// 148 PAY 111 

    0x06818925,// 149 PAY 112 

    0xfd4b10e4,// 150 PAY 113 

    0xa11c9d17,// 151 PAY 114 

    0xd7e30a21,// 152 PAY 115 

    0xd92c07db,// 153 PAY 116 

    0x627c7927,// 154 PAY 117 

    0x97e91fd6,// 155 PAY 118 

    0xe8487db4,// 156 PAY 119 

    0xa2998279,// 157 PAY 120 

    0x35367405,// 158 PAY 121 

    0x75143572,// 159 PAY 122 

    0xde459a05,// 160 PAY 123 

    0x03529950,// 161 PAY 124 

    0xa34670a5,// 162 PAY 125 

    0x7233724f,// 163 PAY 126 

    0x833c9c40,// 164 PAY 127 

    0x409b6936,// 165 PAY 128 

    0xa423bcd6,// 166 PAY 129 

    0x145fe7cf,// 167 PAY 130 

    0x916cc11d,// 168 PAY 131 

    0x58e2ffa5,// 169 PAY 132 

    0x226179e2,// 170 PAY 133 

    0x1595d6c7,// 171 PAY 134 

    0x250fea6a,// 172 PAY 135 

    0x7f9c4864,// 173 PAY 136 

    0x18fda451,// 174 PAY 137 

    0xdeafc14b,// 175 PAY 138 

    0x695204d9,// 176 PAY 139 

    0x543f8efe,// 177 PAY 140 

    0x3b06b727,// 178 PAY 141 

    0x53ccc91e,// 179 PAY 142 

    0xd6260bf3,// 180 PAY 143 

    0xa059ddbc,// 181 PAY 144 

    0x51a40531,// 182 PAY 145 

    0x6affc22d,// 183 PAY 146 

    0x777d4920,// 184 PAY 147 

    0x219c218e,// 185 PAY 148 

    0x48a16eb8,// 186 PAY 149 

    0xa1f73963,// 187 PAY 150 

    0xcfd4802a,// 188 PAY 151 

    0xfdb21b52,// 189 PAY 152 

    0x770be155,// 190 PAY 153 

    0xfe5403f7,// 191 PAY 154 

    0x90fda9c7,// 192 PAY 155 

    0x4d3b2d5c,// 193 PAY 156 

    0x6f829a64,// 194 PAY 157 

    0xeb4c611d,// 195 PAY 158 

    0x0f38b57a,// 196 PAY 159 

    0xb0523cd4,// 197 PAY 160 

    0x14353042,// 198 PAY 161 

    0xf8899a78,// 199 PAY 162 

    0xb56e89b1,// 200 PAY 163 

    0x39b0c170,// 201 PAY 164 

    0xf1eb9099,// 202 PAY 165 

    0x56d31b20,// 203 PAY 166 

    0xe48e35bb,// 204 PAY 167 

    0x65d4962f,// 205 PAY 168 

    0x855c4430,// 206 PAY 169 

    0xf9e95764,// 207 PAY 170 

    0xc703199d,// 208 PAY 171 

    0x30989479,// 209 PAY 172 

    0x3fcd1747,// 210 PAY 173 

    0x9b78579e,// 211 PAY 174 

    0x6454e44b,// 212 PAY 175 

    0xd08c98ee,// 213 PAY 176 

    0x3d5558c5,// 214 PAY 177 

    0xe7058a59,// 215 PAY 178 

    0xd8425e31,// 216 PAY 179 

    0x4ef0f5d8,// 217 PAY 180 

    0x655f737a,// 218 PAY 181 

    0x91b4e611,// 219 PAY 182 

    0x58b5f69f,// 220 PAY 183 

    0x4ad3f305,// 221 PAY 184 

    0x92ad4725,// 222 PAY 185 

    0x40efeebc,// 223 PAY 186 

    0xb17a7770,// 224 PAY 187 

    0xfcc65109,// 225 PAY 188 

    0x46df42b8,// 226 PAY 189 

    0x28a4d5a9,// 227 PAY 190 

    0x4cc6b6b5,// 228 PAY 191 

    0xf2eaaaee,// 229 PAY 192 

    0xa47f9818,// 230 PAY 193 

    0x64447c6c,// 231 PAY 194 

    0x52202afa,// 232 PAY 195 

    0x9774f130,// 233 PAY 196 

    0x6c6a6e1d,// 234 PAY 197 

    0x5c23c61b,// 235 PAY 198 

    0x979186f6,// 236 PAY 199 

    0xaf1ef0fd,// 237 PAY 200 

    0x839aa4af,// 238 PAY 201 

    0x8c03b0d6,// 239 PAY 202 

    0x6e3f7459,// 240 PAY 203 

    0xd96b208c,// 241 PAY 204 

    0x815daeb6,// 242 PAY 205 

    0x52bd56ac,// 243 PAY 206 

    0xe4fb2caf,// 244 PAY 207 

    0x92bdab92,// 245 PAY 208 

    0x949cd8ff,// 246 PAY 209 

    0xe5b3d6c8,// 247 PAY 210 

    0x1fdba3a7,// 248 PAY 211 

    0x2fef1630,// 249 PAY 212 

    0x1a2011df,// 250 PAY 213 

    0x15785472,// 251 PAY 214 

    0xf7c331c2,// 252 PAY 215 

    0x20ff8ac0,// 253 PAY 216 

    0xf9d67ed5,// 254 PAY 217 

    0x72ce5f8b,// 255 PAY 218 

    0x22933d8c,// 256 PAY 219 

    0x930082bc,// 257 PAY 220 

    0xaa9a5131,// 258 PAY 221 

    0x859a706e,// 259 PAY 222 

    0xaf6b8773,// 260 PAY 223 

    0xab0652ce,// 261 PAY 224 

    0x0eb0ba5b,// 262 PAY 225 

    0x3f81fb5b,// 263 PAY 226 

    0x3d3c77be,// 264 PAY 227 

    0x206c8a93,// 265 PAY 228 

    0x92fe18bd,// 266 PAY 229 

    0xd66538b3,// 267 PAY 230 

    0xa50421ad,// 268 PAY 231 

    0xb3421882,// 269 PAY 232 

    0x947629a2,// 270 PAY 233 

    0xa58b039f,// 271 PAY 234 

    0x86a174ff,// 272 PAY 235 

    0x7e249d5b,// 273 PAY 236 

    0xca50768a,// 274 PAY 237 

    0xcc21cee2,// 275 PAY 238 

    0x46c6923c,// 276 PAY 239 

    0xb04808b2,// 277 PAY 240 

    0x7b474ed1,// 278 PAY 241 

    0x0e2c712b,// 279 PAY 242 

    0x963a6fbe,// 280 PAY 243 

    0xb985e166,// 281 PAY 244 

    0x7b76ca95,// 282 PAY 245 

    0x2a090c88,// 283 PAY 246 

    0xb44bcc6a,// 284 PAY 247 

    0x7055710b,// 285 PAY 248 

    0x2b27dfca,// 286 PAY 249 

    0xcfad69da,// 287 PAY 250 

    0x9fb24514,// 288 PAY 251 

    0xfa8cd839,// 289 PAY 252 

    0x9273420f,// 290 PAY 253 

    0x05486779,// 291 PAY 254 

    0xb9e1194c,// 292 PAY 255 

    0xd66fd611,// 293 PAY 256 

    0x839461e4,// 294 PAY 257 

    0x80b3c42f,// 295 PAY 258 

    0x7927239f,// 296 PAY 259 

    0x478d4d24,// 297 PAY 260 

    0x770dffeb,// 298 PAY 261 

    0x37641bca,// 299 PAY 262 

    0x0326e909,// 300 PAY 263 

    0x6113ca04,// 301 PAY 264 

    0x6aa31716,// 302 PAY 265 

    0x7149869e,// 303 PAY 266 

    0xb79df335,// 304 PAY 267 

    0x1a163a4f,// 305 PAY 268 

    0xca6f1676,// 306 PAY 269 

    0x381202f5,// 307 PAY 270 

    0x9a171248,// 308 PAY 271 

    0x184c417c,// 309 PAY 272 

    0x8736a021,// 310 PAY 273 

    0x22c969e4,// 311 PAY 274 

    0x6132fda9,// 312 PAY 275 

    0xf7b8b4ff,// 313 PAY 276 

    0xfb62025b,// 314 PAY 277 

    0x81096d5e,// 315 PAY 278 

    0x9aae7590,// 316 PAY 279 

    0x4cfefb4a,// 317 PAY 280 

    0x85e84fd9,// 318 PAY 281 

    0x0c31af7d,// 319 PAY 282 

    0x59eca01a,// 320 PAY 283 

    0xf9bb89a4,// 321 PAY 284 

    0x901c7359,// 322 PAY 285 

    0x838242e9,// 323 PAY 286 

    0x84f97f79,// 324 PAY 287 

    0xc39adb5c,// 325 PAY 288 

    0xe6f84622,// 326 PAY 289 

    0x29b824a3,// 327 PAY 290 

    0x4dab448b,// 328 PAY 291 

    0xdd32e640,// 329 PAY 292 

    0x83171a8c,// 330 PAY 293 

    0xe5424639,// 331 PAY 294 

    0xfc407749,// 332 PAY 295 

    0x57fd9554,// 333 PAY 296 

    0x960afe9c,// 334 PAY 297 

    0x200f7a00,// 335 PAY 298 

    0xf048681c,// 336 PAY 299 

    0x0ee7c8a8,// 337 PAY 300 

    0x3efb9ded,// 338 PAY 301 

    0x8322d98b,// 339 PAY 302 

    0x60136528,// 340 PAY 303 

    0x2e85d995,// 341 PAY 304 

    0x89278a29,// 342 PAY 305 

    0x7701eccc,// 343 PAY 306 

    0x25c0e4bc,// 344 PAY 307 

    0x7ab40d82,// 345 PAY 308 

    0x73a98ea5,// 346 PAY 309 

    0x5f6ee49f,// 347 PAY 310 

    0x9d35636f,// 348 PAY 311 

    0xc4c70211,// 349 PAY 312 

    0xeb9d7bfe,// 350 PAY 313 

    0x7b8d90e5,// 351 PAY 314 

    0xba815f1e,// 352 PAY 315 

    0x49063319,// 353 PAY 316 

    0xb7b733d6,// 354 PAY 317 

    0xc433488d,// 355 PAY 318 

    0xa1a1a917,// 356 PAY 319 

    0xd55d711c,// 357 PAY 320 

    0xf9753c4a,// 358 PAY 321 

    0xb2bba2b9,// 359 PAY 322 

    0xaecef008,// 360 PAY 323 

    0x9c6abefe,// 361 PAY 324 

    0x07dfe13b,// 362 PAY 325 

    0x9eb742fb,// 363 PAY 326 

    0x9ef00b6b,// 364 PAY 327 

    0x31548a7e,// 365 PAY 328 

    0x576bf319,// 366 PAY 329 

    0x0728bb9a,// 367 PAY 330 

    0xb4f73c8a,// 368 PAY 331 

    0x3a4aae32,// 369 PAY 332 

    0x519a855e,// 370 PAY 333 

    0xc8d2d16e,// 371 PAY 334 

    0x3cc4f99f,// 372 PAY 335 

    0xc1c1b4bf,// 373 PAY 336 

    0x1e696446,// 374 PAY 337 

    0xe629f5e3,// 375 PAY 338 

    0x18d596aa,// 376 PAY 339 

    0xfc62b3b7,// 377 PAY 340 

    0xea6b4410,// 378 PAY 341 

    0x7d8ea53e,// 379 PAY 342 

    0xc3e8867a,// 380 PAY 343 

    0x81af1376,// 381 PAY 344 

    0xb195ea39,// 382 PAY 345 

    0xcdc935da,// 383 PAY 346 

    0x6b614404,// 384 PAY 347 

    0x65f66a49,// 385 PAY 348 

    0x54bbd24a,// 386 PAY 349 

    0x691c43c1,// 387 PAY 350 

    0xa65885e0,// 388 PAY 351 

    0xffa591fc,// 389 PAY 352 

    0x96f0e2ef,// 390 PAY 353 

    0x1a29f074,// 391 PAY 354 

    0x3ab6eefd,// 392 PAY 355 

    0x84f9a7b7,// 393 PAY 356 

    0xcd35e40b,// 394 PAY 357 

    0x0e91a600,// 395 PAY 358 

    0xac369f3b,// 396 PAY 359 

    0x28f1cf3b,// 397 PAY 360 

    0x47c8a888,// 398 PAY 361 

    0x9110e2cb,// 399 PAY 362 

    0xda37abf5,// 400 PAY 363 

    0xb1f0d06b,// 401 PAY 364 

    0xadef2028,// 402 PAY 365 

    0x86f89aa5,// 403 PAY 366 

    0x221eccae,// 404 PAY 367 

    0xd934998c,// 405 PAY 368 

    0x380e4b07,// 406 PAY 369 

    0x6e5b06f4,// 407 PAY 370 

    0xcba67db8,// 408 PAY 371 

    0x4cd1cca1,// 409 PAY 372 

    0x18ca567a,// 410 PAY 373 

    0x5ac66860,// 411 PAY 374 

    0x87176eb5,// 412 PAY 375 

    0xd52a7824,// 413 PAY 376 

    0xfb111683,// 414 PAY 377 

    0xedeb4af8,// 415 PAY 378 

    0x5eaa1644,// 416 PAY 379 

    0x0224e4ef,// 417 PAY 380 

    0xf0ac2d25,// 418 PAY 381 

    0xf9a0187d,// 419 PAY 382 

    0x090d48f0,// 420 PAY 383 

    0x3c0f61e5,// 421 PAY 384 

    0xe5da4f0a,// 422 PAY 385 

    0x3f8904d0,// 423 PAY 386 

    0x5b1459c9,// 424 PAY 387 

    0xe90c381d,// 425 PAY 388 

    0x21253887,// 426 PAY 389 

    0x83521b44,// 427 PAY 390 

    0x83ba30c3,// 428 PAY 391 

    0x96ae08b5,// 429 PAY 392 

    0xf2ce9e74,// 430 PAY 393 

    0xf602cf3c,// 431 PAY 394 

    0xbc87a4aa,// 432 PAY 395 

    0xa0e4f1f7,// 433 PAY 396 

    0xaa48762c,// 434 PAY 397 

    0xb7b3900a,// 435 PAY 398 

    0x839854d1,// 436 PAY 399 

    0xbf9a27d2,// 437 PAY 400 

    0x4009b783,// 438 PAY 401 

    0xc90f14b0,// 439 PAY 402 

    0x4d7408b7,// 440 PAY 403 

    0x420eead1,// 441 PAY 404 

    0x6900c8dd,// 442 PAY 405 

    0x7b3d59bd,// 443 PAY 406 

    0x9ee15267,// 444 PAY 407 

    0xdc172585,// 445 PAY 408 

    0xc7613b08,// 446 PAY 409 

    0x61c31ca0,// 447 PAY 410 

    0x0e0a8a9f,// 448 PAY 411 

    0xd7172dc6,// 449 PAY 412 

    0x3b93cddb,// 450 PAY 413 

    0x1ef6ed4f,// 451 PAY 414 

    0x6e7c3a61,// 452 PAY 415 

    0x15349a13,// 453 PAY 416 

    0x613006ed,// 454 PAY 417 

    0xce29c284,// 455 PAY 418 

    0xf2c8a447,// 456 PAY 419 

    0xf6f06e9b,// 457 PAY 420 

    0xa26b1531,// 458 PAY 421 

    0x50537162,// 459 PAY 422 

    0x9ea65629,// 460 PAY 423 

    0xa8844f83,// 461 PAY 424 

    0x2aebe292,// 462 PAY 425 

    0xd3ee7c39,// 463 PAY 426 

    0x6b94f80d,// 464 PAY 427 

    0xbedfe334,// 465 PAY 428 

    0x278c36c8,// 466 PAY 429 

    0x963041b3,// 467 PAY 430 

    0x5e929bf7,// 468 PAY 431 

    0x9561fd77,// 469 PAY 432 

    0xcb388331,// 470 PAY 433 

    0x80e66b5a,// 471 PAY 434 

    0x70957cc3,// 472 PAY 435 

    0xd59a704b,// 473 PAY 436 

    0xc52b25cc,// 474 PAY 437 

    0x98b85508,// 475 PAY 438 

    0xfd00c1ec,// 476 PAY 439 

    0xe2820b1e,// 477 PAY 440 

    0x58920b9a,// 478 PAY 441 

    0x555ec779,// 479 PAY 442 

    0xddbcf506,// 480 PAY 443 

    0x12f849e0,// 481 PAY 444 

    0xc528711d,// 482 PAY 445 

    0x2c13cf87,// 483 PAY 446 

    0xd165b0d0,// 484 PAY 447 

    0x7b88587b,// 485 PAY 448 

    0xd519e896,// 486 PAY 449 

    0xa4638ea7,// 487 PAY 450 

    0x3e523fd6,// 488 PAY 451 

    0xa25693c0,// 489 PAY 452 

    0x5e97527c,// 490 PAY 453 

    0x78e2aa1b,// 491 PAY 454 

    0xca000000,// 492 PAY 455 

/// STA is 1 words. 

/// STA num_pkts       : 128 

/// STA pkt_idx        : 122 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xe5 

    0x01e8e580 // 493 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt29_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x80922802,// 4 SCX   2 

    0x000062c2,// 5 SCX   3 

    0x6976fa41,// 6 SCX   4 

    0xade53cb2,// 7 SCX   5 

    0x68105704,// 8 SCX   6 

    0x0bf5d9d4,// 9 SCX   7 

    0x0c3c73f3,// 10 SCX   8 

    0x3a3f7a18,// 11 SCX   9 

    0x59945a01,// 12 SCX  10 

    0xe625d74f,// 13 SCX  11 

    0xa1d01263,// 14 SCX  12 

    0x4d5c304e,// 15 SCX  13 

    0x64af5667,// 16 SCX  14 

    0x5ecefdfa,// 17 SCX  15 

    0x57ae1efa,// 18 SCX  16 

    0x2a4675c9,// 19 SCX  17 

    0x06a33d02,// 20 SCX  18 

    0xd709eb2e,// 21 SCX  19 

    0x64c24c51,// 22 SCX  20 

    0xd21619dc,// 23 SCX  21 

    0x512ab359,// 24 SCX  22 

    0xfb5fde70,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1477 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 983 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 983 

/// BFD lencrypto      : 84 

/// BFD ofstcrypto     : 772 

/// BFD (ofst+len)cry  : 856 

/// BFD ofstiv         : 728 

/// BFD ofsticv        : 1436 

    0x000003d7,// 26 BFD   1 

    0x03040054,// 27 BFD   2 

    0x059c02d8,// 28 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c006afb,// 29 MFM   1 

    0xd0124f96,// 30 MFM   2 

    0x2e058fe6,// 31 MFM   3 

    0xfb000c47,// 32 MFM   4 

    0x66ac6057,// 33 MFM   5 

    0x7e112c83,// 34 MFM   6 

    0x2cd83efc,// 35 MFM   7 

    0xbe2bc243,// 36 MFM   8 

    0xa179da57,// 37 MFM   9 

    0xe70efd23,// 38 MFM  10 

    0xeb48e615,// 39 MFM  11 

    0x57dc52b9,// 40 MFM  12 

    0xc7871625,// 41 MFM  13 

    0xf7a56154,// 42 MFM  14 

    0xf2943864,// 43 MFM  15 

    0x708a438c,// 44 MFM  16 

/// BDA is 371 words. 

/// BDA size     is 1477 (0x5c5) 

/// BDA id       is 0x31c5 

    0x05c531c5,// 45 BDA   1 

/// PAY Generic Data size   : 1477 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x58217e07,// 46 PAY   1 

    0xa93dd2ee,// 47 PAY   2 

    0x6fbff81f,// 48 PAY   3 

    0x72e0a88e,// 49 PAY   4 

    0x752f25de,// 50 PAY   5 

    0x4a22b3a3,// 51 PAY   6 

    0x82247185,// 52 PAY   7 

    0x99a7770f,// 53 PAY   8 

    0xafd115d3,// 54 PAY   9 

    0xcba904be,// 55 PAY  10 

    0x359855ed,// 56 PAY  11 

    0x6c0661a6,// 57 PAY  12 

    0xa77bd4dc,// 58 PAY  13 

    0xe8a20169,// 59 PAY  14 

    0xd013309a,// 60 PAY  15 

    0x303913f6,// 61 PAY  16 

    0x2cf56b69,// 62 PAY  17 

    0x4ef12e94,// 63 PAY  18 

    0xb632b09a,// 64 PAY  19 

    0x2e78c6e5,// 65 PAY  20 

    0x243f581f,// 66 PAY  21 

    0x9cec72e2,// 67 PAY  22 

    0x8cf8bc35,// 68 PAY  23 

    0x31e3a384,// 69 PAY  24 

    0x1a06ce35,// 70 PAY  25 

    0x5f7a0458,// 71 PAY  26 

    0x50366943,// 72 PAY  27 

    0x39800f6f,// 73 PAY  28 

    0x2ff798ff,// 74 PAY  29 

    0x57cd1a43,// 75 PAY  30 

    0x51297eff,// 76 PAY  31 

    0xf22ef606,// 77 PAY  32 

    0x40c91860,// 78 PAY  33 

    0xc11565c8,// 79 PAY  34 

    0x94a7bd0f,// 80 PAY  35 

    0xeb8a7684,// 81 PAY  36 

    0xd49e0e12,// 82 PAY  37 

    0x7fe61a72,// 83 PAY  38 

    0x30b18fb6,// 84 PAY  39 

    0xdeda937d,// 85 PAY  40 

    0xf72b6f6b,// 86 PAY  41 

    0x90a3bad6,// 87 PAY  42 

    0x632d4751,// 88 PAY  43 

    0xb7360c1b,// 89 PAY  44 

    0x7b87fdce,// 90 PAY  45 

    0x8b080157,// 91 PAY  46 

    0xdafd24cc,// 92 PAY  47 

    0x714fc96d,// 93 PAY  48 

    0x64cd8ae9,// 94 PAY  49 

    0xeb607a17,// 95 PAY  50 

    0x8864ca24,// 96 PAY  51 

    0x11ac8ae7,// 97 PAY  52 

    0x6eb78c5f,// 98 PAY  53 

    0x4653decb,// 99 PAY  54 

    0xa7b8db40,// 100 PAY  55 

    0x0265961e,// 101 PAY  56 

    0xa054b1ab,// 102 PAY  57 

    0x37a807f2,// 103 PAY  58 

    0x565de49e,// 104 PAY  59 

    0x6b04f78c,// 105 PAY  60 

    0x51ba18ef,// 106 PAY  61 

    0x07ae3693,// 107 PAY  62 

    0x1b1b4778,// 108 PAY  63 

    0x0ad61f3c,// 109 PAY  64 

    0xa8e81ed8,// 110 PAY  65 

    0x96b10931,// 111 PAY  66 

    0xf2e7d3f1,// 112 PAY  67 

    0xd907b381,// 113 PAY  68 

    0xa2ae4277,// 114 PAY  69 

    0x16c74bce,// 115 PAY  70 

    0xddc49bfd,// 116 PAY  71 

    0xb80a1068,// 117 PAY  72 

    0x9d23144e,// 118 PAY  73 

    0x3b026610,// 119 PAY  74 

    0x8c8f85e5,// 120 PAY  75 

    0x897583d7,// 121 PAY  76 

    0xead58a2f,// 122 PAY  77 

    0x73cf1ba7,// 123 PAY  78 

    0xef5d496f,// 124 PAY  79 

    0x72662c55,// 125 PAY  80 

    0x8ad1ec00,// 126 PAY  81 

    0xd6382e5b,// 127 PAY  82 

    0x410d829d,// 128 PAY  83 

    0xdd1a4d4a,// 129 PAY  84 

    0x8f62dcf9,// 130 PAY  85 

    0x87801c29,// 131 PAY  86 

    0x789fcd0e,// 132 PAY  87 

    0x9f6a7a4c,// 133 PAY  88 

    0x7717cb6f,// 134 PAY  89 

    0x7e7ff388,// 135 PAY  90 

    0x8f4f554f,// 136 PAY  91 

    0xaecb1287,// 137 PAY  92 

    0x05d013ba,// 138 PAY  93 

    0x3adeda23,// 139 PAY  94 

    0x2b3ed1d6,// 140 PAY  95 

    0xf63614b4,// 141 PAY  96 

    0x33cb1d9a,// 142 PAY  97 

    0x9841331e,// 143 PAY  98 

    0xf7204b38,// 144 PAY  99 

    0x19bb953d,// 145 PAY 100 

    0xfb189d1a,// 146 PAY 101 

    0xa90ea733,// 147 PAY 102 

    0x8743c6a7,// 148 PAY 103 

    0xfa6f1f7e,// 149 PAY 104 

    0x0aeb651f,// 150 PAY 105 

    0x4ac56b0d,// 151 PAY 106 

    0x3f93f790,// 152 PAY 107 

    0xf4111a45,// 153 PAY 108 

    0xc3d4ed74,// 154 PAY 109 

    0x5e3e694e,// 155 PAY 110 

    0xd9beae92,// 156 PAY 111 

    0x141ba4d4,// 157 PAY 112 

    0xc32577b5,// 158 PAY 113 

    0x61e3c371,// 159 PAY 114 

    0xb1e6316a,// 160 PAY 115 

    0xf3086c08,// 161 PAY 116 

    0xa8a073bb,// 162 PAY 117 

    0xd37a0c47,// 163 PAY 118 

    0x7a45dd78,// 164 PAY 119 

    0x4d0dba7e,// 165 PAY 120 

    0x5a5585de,// 166 PAY 121 

    0xa1888a1f,// 167 PAY 122 

    0x5ef799c2,// 168 PAY 123 

    0x5d80324c,// 169 PAY 124 

    0x4890b643,// 170 PAY 125 

    0x3015cfa0,// 171 PAY 126 

    0x0e1514eb,// 172 PAY 127 

    0x1953a42c,// 173 PAY 128 

    0x4d764ce2,// 174 PAY 129 

    0xa4d49b4c,// 175 PAY 130 

    0xd1aead2c,// 176 PAY 131 

    0x6dc08161,// 177 PAY 132 

    0x4f17558e,// 178 PAY 133 

    0xe608f229,// 179 PAY 134 

    0xa0653c93,// 180 PAY 135 

    0xa8f463ca,// 181 PAY 136 

    0xea84e6a6,// 182 PAY 137 

    0x09397244,// 183 PAY 138 

    0x39f146d9,// 184 PAY 139 

    0x4ba73e12,// 185 PAY 140 

    0x5262171b,// 186 PAY 141 

    0xad545660,// 187 PAY 142 

    0x17124f7f,// 188 PAY 143 

    0x1327e08f,// 189 PAY 144 

    0x9896d9de,// 190 PAY 145 

    0xaa619333,// 191 PAY 146 

    0xb2254f6b,// 192 PAY 147 

    0xacd1b34a,// 193 PAY 148 

    0x2bbdf5bf,// 194 PAY 149 

    0x880d8181,// 195 PAY 150 

    0xd765ecb3,// 196 PAY 151 

    0xb7deb849,// 197 PAY 152 

    0x9907c96e,// 198 PAY 153 

    0x28b6219b,// 199 PAY 154 

    0x31b02d59,// 200 PAY 155 

    0x6cb5e825,// 201 PAY 156 

    0xca388bba,// 202 PAY 157 

    0x47902bea,// 203 PAY 158 

    0xcfe727cc,// 204 PAY 159 

    0x33ea7b8f,// 205 PAY 160 

    0x71d4ac42,// 206 PAY 161 

    0xe97985dc,// 207 PAY 162 

    0x5db8eac9,// 208 PAY 163 

    0x1e7d0d54,// 209 PAY 164 

    0x159c120c,// 210 PAY 165 

    0xb784b85d,// 211 PAY 166 

    0x2122f3fa,// 212 PAY 167 

    0x4659b4e3,// 213 PAY 168 

    0x473d6f4f,// 214 PAY 169 

    0xfb20f06b,// 215 PAY 170 

    0x0e4d991c,// 216 PAY 171 

    0xa390a79a,// 217 PAY 172 

    0x97f3ea2a,// 218 PAY 173 

    0x36db1c60,// 219 PAY 174 

    0x908c8b25,// 220 PAY 175 

    0xf87166e1,// 221 PAY 176 

    0x3c7c7e06,// 222 PAY 177 

    0xc6f672f1,// 223 PAY 178 

    0x0e165bc8,// 224 PAY 179 

    0xeef47629,// 225 PAY 180 

    0xa7f77865,// 226 PAY 181 

    0xc8394029,// 227 PAY 182 

    0xf20f29a4,// 228 PAY 183 

    0x666d2f60,// 229 PAY 184 

    0xc4e426fd,// 230 PAY 185 

    0x0bca750a,// 231 PAY 186 

    0x5e3cc959,// 232 PAY 187 

    0xbd49dec6,// 233 PAY 188 

    0x8cba1384,// 234 PAY 189 

    0x8c41b726,// 235 PAY 190 

    0xfa040929,// 236 PAY 191 

    0xaea08deb,// 237 PAY 192 

    0x2bc07e93,// 238 PAY 193 

    0x837a5703,// 239 PAY 194 

    0xaa81b75a,// 240 PAY 195 

    0xb6b0f4c2,// 241 PAY 196 

    0x83a13232,// 242 PAY 197 

    0xf05c6fe8,// 243 PAY 198 

    0x8348a81f,// 244 PAY 199 

    0x413da64a,// 245 PAY 200 

    0xe96290a4,// 246 PAY 201 

    0x28d96dad,// 247 PAY 202 

    0x9ec30454,// 248 PAY 203 

    0x5258f115,// 249 PAY 204 

    0x7a1ea96f,// 250 PAY 205 

    0xfe588b3a,// 251 PAY 206 

    0x784afabe,// 252 PAY 207 

    0x84f56bb1,// 253 PAY 208 

    0x0357aefc,// 254 PAY 209 

    0x5a8311d8,// 255 PAY 210 

    0x554c7891,// 256 PAY 211 

    0x2ef381fd,// 257 PAY 212 

    0x59fce7fe,// 258 PAY 213 

    0x450dbfbe,// 259 PAY 214 

    0x4226963f,// 260 PAY 215 

    0xf68dfe92,// 261 PAY 216 

    0x4176347f,// 262 PAY 217 

    0x45db0232,// 263 PAY 218 

    0xb214f9d9,// 264 PAY 219 

    0xb90ca3f8,// 265 PAY 220 

    0x2095d0eb,// 266 PAY 221 

    0x2cb33ccc,// 267 PAY 222 

    0xfa16206c,// 268 PAY 223 

    0x1497b171,// 269 PAY 224 

    0xc3481ccb,// 270 PAY 225 

    0x9e8253ad,// 271 PAY 226 

    0x6d2484bc,// 272 PAY 227 

    0x47bbc99b,// 273 PAY 228 

    0x2f9e5c5e,// 274 PAY 229 

    0x5c4d9df5,// 275 PAY 230 

    0x151a2e3e,// 276 PAY 231 

    0xaa040a00,// 277 PAY 232 

    0xc27500ed,// 278 PAY 233 

    0x4b48d454,// 279 PAY 234 

    0x801839fb,// 280 PAY 235 

    0x96c6c923,// 281 PAY 236 

    0x242fc1bc,// 282 PAY 237 

    0xd72c3874,// 283 PAY 238 

    0x5d9e80fd,// 284 PAY 239 

    0xc6488417,// 285 PAY 240 

    0xdf21fc07,// 286 PAY 241 

    0x279ed917,// 287 PAY 242 

    0x13e878e6,// 288 PAY 243 

    0xcacdc0fa,// 289 PAY 244 

    0xebbefbc5,// 290 PAY 245 

    0xb8e08913,// 291 PAY 246 

    0x6ae3434d,// 292 PAY 247 

    0xd055ea99,// 293 PAY 248 

    0xb5d3230a,// 294 PAY 249 

    0xd611ea53,// 295 PAY 250 

    0x093ed743,// 296 PAY 251 

    0xd41734c8,// 297 PAY 252 

    0xa5f6fec5,// 298 PAY 253 

    0x31d12bd1,// 299 PAY 254 

    0xc66cef9a,// 300 PAY 255 

    0x1bd474c3,// 301 PAY 256 

    0xe167ce65,// 302 PAY 257 

    0x65d131f7,// 303 PAY 258 

    0xbc01a531,// 304 PAY 259 

    0x187c6667,// 305 PAY 260 

    0xff70ae48,// 306 PAY 261 

    0x0537629d,// 307 PAY 262 

    0x1f1b4b11,// 308 PAY 263 

    0x648bd3da,// 309 PAY 264 

    0xec3509ef,// 310 PAY 265 

    0xfa229ae0,// 311 PAY 266 

    0xf85e029a,// 312 PAY 267 

    0x873a80be,// 313 PAY 268 

    0x1ad08ba2,// 314 PAY 269 

    0x48e14c62,// 315 PAY 270 

    0x929a2510,// 316 PAY 271 

    0xa4ad31b7,// 317 PAY 272 

    0xb1e57d65,// 318 PAY 273 

    0xe72f4bcd,// 319 PAY 274 

    0x178e6f48,// 320 PAY 275 

    0x66ed535c,// 321 PAY 276 

    0x4dc581db,// 322 PAY 277 

    0xbcd7138d,// 323 PAY 278 

    0xb0ca34e8,// 324 PAY 279 

    0x183f1c1b,// 325 PAY 280 

    0x9a4c3d5f,// 326 PAY 281 

    0x9f617a3e,// 327 PAY 282 

    0x58f76a9b,// 328 PAY 283 

    0x41120e7d,// 329 PAY 284 

    0xd90482bd,// 330 PAY 285 

    0x861bf6eb,// 331 PAY 286 

    0xa995a7eb,// 332 PAY 287 

    0x7828708c,// 333 PAY 288 

    0xc61ff245,// 334 PAY 289 

    0x1b823e4f,// 335 PAY 290 

    0xca352e5e,// 336 PAY 291 

    0x70d48bb3,// 337 PAY 292 

    0x655ddb35,// 338 PAY 293 

    0x28bf4ef9,// 339 PAY 294 

    0xca4e980e,// 340 PAY 295 

    0x9360472d,// 341 PAY 296 

    0x7135f45f,// 342 PAY 297 

    0x67073b7a,// 343 PAY 298 

    0xd946de30,// 344 PAY 299 

    0x75fc3963,// 345 PAY 300 

    0x6fd6f8c2,// 346 PAY 301 

    0x95581e69,// 347 PAY 302 

    0x0ba5cc48,// 348 PAY 303 

    0x4d993608,// 349 PAY 304 

    0xb1bad365,// 350 PAY 305 

    0x3680c4fb,// 351 PAY 306 

    0x00d800ed,// 352 PAY 307 

    0x547b9d9a,// 353 PAY 308 

    0x6e6ffe96,// 354 PAY 309 

    0xde8fc168,// 355 PAY 310 

    0xcb307847,// 356 PAY 311 

    0xd2d94a95,// 357 PAY 312 

    0xfa56f5d6,// 358 PAY 313 

    0x36a19fa6,// 359 PAY 314 

    0xb8b32e72,// 360 PAY 315 

    0xb2e884c4,// 361 PAY 316 

    0x2893fc98,// 362 PAY 317 

    0x90dfa9bd,// 363 PAY 318 

    0xc6d2111f,// 364 PAY 319 

    0x32ac05de,// 365 PAY 320 

    0xa20b1dab,// 366 PAY 321 

    0x9347234e,// 367 PAY 322 

    0xadda82f5,// 368 PAY 323 

    0x9337ded1,// 369 PAY 324 

    0xc1927c13,// 370 PAY 325 

    0x38d7a3f0,// 371 PAY 326 

    0xc605437b,// 372 PAY 327 

    0x78b6c58b,// 373 PAY 328 

    0x7f860ded,// 374 PAY 329 

    0x6940d2b1,// 375 PAY 330 

    0x31508b08,// 376 PAY 331 

    0xe36f18ea,// 377 PAY 332 

    0x478520bc,// 378 PAY 333 

    0x6b1b68f4,// 379 PAY 334 

    0xb9c6a331,// 380 PAY 335 

    0xd34cae72,// 381 PAY 336 

    0xb2f31dee,// 382 PAY 337 

    0xde18beda,// 383 PAY 338 

    0xbf5d63f4,// 384 PAY 339 

    0xd8a26cea,// 385 PAY 340 

    0x224630bd,// 386 PAY 341 

    0xb9bc71c1,// 387 PAY 342 

    0x8b284107,// 388 PAY 343 

    0x90713570,// 389 PAY 344 

    0x969afc99,// 390 PAY 345 

    0x1dca7df7,// 391 PAY 346 

    0xc5204b46,// 392 PAY 347 

    0x285632af,// 393 PAY 348 

    0x1c8fbcf6,// 394 PAY 349 

    0xe36aea93,// 395 PAY 350 

    0x3b6b8eb6,// 396 PAY 351 

    0x27958877,// 397 PAY 352 

    0xb7ca9c97,// 398 PAY 353 

    0x630cc3e8,// 399 PAY 354 

    0xd467bb4a,// 400 PAY 355 

    0xd639a5f0,// 401 PAY 356 

    0xa5f2f909,// 402 PAY 357 

    0xf7d15f70,// 403 PAY 358 

    0x727d44f0,// 404 PAY 359 

    0xcd67dbcc,// 405 PAY 360 

    0xa75f06fa,// 406 PAY 361 

    0x5ae8008b,// 407 PAY 362 

    0x0785d2b3,// 408 PAY 363 

    0x16452d8f,// 409 PAY 364 

    0xd8e67bb9,// 410 PAY 365 

    0x37314b27,// 411 PAY 366 

    0x96e1334a,// 412 PAY 367 

    0x45699698,// 413 PAY 368 

    0x9b8cbdf8,// 414 PAY 369 

    0xc6000000,// 415 PAY 370 

/// STA is 1 words. 

/// STA num_pkts       : 28 

/// STA pkt_idx        : 43 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x6e 

    0x00ac6e1c // 416 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt30_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x03 

/// ECH pdu_tag        : 0x00 

    0x00030000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8082283e,// 4 SCX   2 

    0x00005100,// 5 SCX   3 

    0xf1164af3,// 6 SCX   4 

    0xeac5db3c,// 7 SCX   5 

    0xbe39f96e,// 8 SCX   6 

    0xe65017a5,// 9 SCX   7 

    0xbc0c8951,// 10 SCX   8 

    0xa09b5ba0,// 11 SCX   9 

    0x7c7d20df,// 12 SCX  10 

    0xab729544,// 13 SCX  11 

    0x7d44917a,// 14 SCX  12 

    0x0036e07b,// 15 SCX  13 

    0x1d2471bb,// 16 SCX  14 

    0x30e99c54,// 17 SCX  15 

    0x4203d84e,// 18 SCX  16 

    0xd9f5115c,// 19 SCX  17 

    0xcf33bc24,// 20 SCX  18 

    0x72157152,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 457 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 185 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 185 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 80 

/// BFD (ofst+len)cry  : 96 

/// BFD ofstiv         : 24 

/// BFD ofsticv        : 388 

    0x000000b9,// 22 BFD   1 

    0x00500010,// 23 BFD   2 

    0x01840018,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : a 

    0x0a00db42,// 25 MFM   1 

    0x469e7400,// 26 MFM   2 

/// BDA is 116 words. 

/// BDA size     is 457 (0x1c9) 

/// BDA id       is 0x15c 

    0x01c9015c,// 27 BDA   1 

/// PAY Generic Data size   : 457 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x18c4d92b,// 28 PAY   1 

    0x13313ccc,// 29 PAY   2 

    0xb3627668,// 30 PAY   3 

    0x8afaa7ec,// 31 PAY   4 

    0xa16c73b1,// 32 PAY   5 

    0x27af3804,// 33 PAY   6 

    0x7244e4c8,// 34 PAY   7 

    0x0ed93398,// 35 PAY   8 

    0x6ab53636,// 36 PAY   9 

    0x92d5af74,// 37 PAY  10 

    0xa5729c7a,// 38 PAY  11 

    0x20f898ea,// 39 PAY  12 

    0xa1500262,// 40 PAY  13 

    0xcb53e409,// 41 PAY  14 

    0xb3690363,// 42 PAY  15 

    0x23739eea,// 43 PAY  16 

    0xef2c1200,// 44 PAY  17 

    0x6d534937,// 45 PAY  18 

    0x42f80788,// 46 PAY  19 

    0x2d125845,// 47 PAY  20 

    0x44dc996c,// 48 PAY  21 

    0x8b9eb482,// 49 PAY  22 

    0xe6eba7db,// 50 PAY  23 

    0x1650595d,// 51 PAY  24 

    0x7288fe5d,// 52 PAY  25 

    0xa59ebf81,// 53 PAY  26 

    0xc5b92cdd,// 54 PAY  27 

    0x14d92e0d,// 55 PAY  28 

    0x50d84338,// 56 PAY  29 

    0xe6e05b77,// 57 PAY  30 

    0x1614611f,// 58 PAY  31 

    0xbf377e87,// 59 PAY  32 

    0x142a0547,// 60 PAY  33 

    0xa45b8643,// 61 PAY  34 

    0x137340e5,// 62 PAY  35 

    0x1aefec5f,// 63 PAY  36 

    0x839a5cdd,// 64 PAY  37 

    0xd36955d4,// 65 PAY  38 

    0x4b14886a,// 66 PAY  39 

    0xbd973b4d,// 67 PAY  40 

    0x1904f127,// 68 PAY  41 

    0xd2064627,// 69 PAY  42 

    0x31e1c504,// 70 PAY  43 

    0x5ae9cf11,// 71 PAY  44 

    0x98ef6240,// 72 PAY  45 

    0x3f0d2500,// 73 PAY  46 

    0x739233f1,// 74 PAY  47 

    0xe7ea2786,// 75 PAY  48 

    0x9f278b9d,// 76 PAY  49 

    0x6c2b0885,// 77 PAY  50 

    0xce8e30fd,// 78 PAY  51 

    0x8788640d,// 79 PAY  52 

    0x05e3db2d,// 80 PAY  53 

    0x701fec94,// 81 PAY  54 

    0xe48ce3cf,// 82 PAY  55 

    0xa226e36c,// 83 PAY  56 

    0x3633bbbb,// 84 PAY  57 

    0x9e698e80,// 85 PAY  58 

    0x91b7bc24,// 86 PAY  59 

    0x91cbc456,// 87 PAY  60 

    0x6458a2c6,// 88 PAY  61 

    0x11760f4d,// 89 PAY  62 

    0x4b79db61,// 90 PAY  63 

    0xfe45fe26,// 91 PAY  64 

    0xee0c0738,// 92 PAY  65 

    0xdec7e831,// 93 PAY  66 

    0x7396d1ba,// 94 PAY  67 

    0x58e15245,// 95 PAY  68 

    0xec15daa0,// 96 PAY  69 

    0xbed3a262,// 97 PAY  70 

    0x9e2b3227,// 98 PAY  71 

    0xd8aa92f7,// 99 PAY  72 

    0x0ff28964,// 100 PAY  73 

    0xc4183f8e,// 101 PAY  74 

    0x89324211,// 102 PAY  75 

    0xf516c6fd,// 103 PAY  76 

    0xe3a63e79,// 104 PAY  77 

    0x1c6ad627,// 105 PAY  78 

    0x24ae076d,// 106 PAY  79 

    0x3787dc18,// 107 PAY  80 

    0xdce3c0f1,// 108 PAY  81 

    0xfec22848,// 109 PAY  82 

    0x0a31070a,// 110 PAY  83 

    0x74499f2e,// 111 PAY  84 

    0xfb13018b,// 112 PAY  85 

    0x7a9bbf2f,// 113 PAY  86 

    0x2d4240e4,// 114 PAY  87 

    0xa6d2ee05,// 115 PAY  88 

    0xfd1ee60d,// 116 PAY  89 

    0x538644b8,// 117 PAY  90 

    0x7038174a,// 118 PAY  91 

    0xc1e2646b,// 119 PAY  92 

    0xb304a839,// 120 PAY  93 

    0x0ea0b66f,// 121 PAY  94 

    0x97e5ea44,// 122 PAY  95 

    0xa70c637a,// 123 PAY  96 

    0x84ba43a6,// 124 PAY  97 

    0x356802b4,// 125 PAY  98 

    0x589bdaee,// 126 PAY  99 

    0x930bbb70,// 127 PAY 100 

    0x8072a95b,// 128 PAY 101 

    0xa3afc9de,// 129 PAY 102 

    0xd6514271,// 130 PAY 103 

    0xf221a7de,// 131 PAY 104 

    0x81687160,// 132 PAY 105 

    0x72cb4114,// 133 PAY 106 

    0x987f684e,// 134 PAY 107 

    0xc04cb931,// 135 PAY 108 

    0x84ac85ea,// 136 PAY 109 

    0xfe1e5d75,// 137 PAY 110 

    0xe41779e2,// 138 PAY 111 

    0xd91cadfd,// 139 PAY 112 

    0xea8aedaf,// 140 PAY 113 

    0x95848443,// 141 PAY 114 

    0xe0000000,// 142 PAY 115 

/// STA is 1 words. 

/// STA num_pkts       : 6 

/// STA pkt_idx        : 105 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x53 

    0x01a55306 // 143 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt31_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000015,// 3 SCX   1 

    0x80852870,// 4 SCX   2 

    0x00006184,// 5 SCX   3 

    0xa2c93d46,// 6 SCX   4 

    0x461a0a91,// 7 SCX   5 

    0x965bc7b0,// 8 SCX   6 

    0xf936a766,// 9 SCX   7 

    0x414ab14f,// 10 SCX   8 

    0x48ac1645,// 11 SCX   9 

    0x300104e8,// 12 SCX  10 

    0x3d2d60a4,// 13 SCX  11 

    0xf87293f4,// 14 SCX  12 

    0x0e18b0b0,// 15 SCX  13 

    0x2a04c639,// 16 SCX  14 

    0x0fd4653d,// 17 SCX  15 

    0xcfebf34c,// 18 SCX  16 

    0x808f1dab,// 19 SCX  17 

    0x2539eb70,// 20 SCX  18 

    0x0dfa8d43,// 21 SCX  19 

    0x82634fe1,// 22 SCX  20 

    0x7b55d5e2,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 452 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 276 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 276 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 80 

/// BFD (ofst+len)cry  : 160 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 436 

    0x00000114,// 24 BFD   1 

    0x00500050,// 25 BFD   2 

    0x01b4000c,// 26 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 9 

    0x0900a8f4,// 27 MFM   1 

    0x8d0ad000,// 28 MFM   2 

/// BDA is 114 words. 

/// BDA size     is 452 (0x1c4) 

/// BDA id       is 0x2b67 

    0x01c42b67,// 29 BDA   1 

/// PAY Generic Data size   : 452 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xf000245d,// 30 PAY   1 

    0xdc5ec11a,// 31 PAY   2 

    0xd69318ae,// 32 PAY   3 

    0x9e74b65b,// 33 PAY   4 

    0x6630a630,// 34 PAY   5 

    0x3c334fb3,// 35 PAY   6 

    0x0223716c,// 36 PAY   7 

    0xb9db00f9,// 37 PAY   8 

    0xc60d2447,// 38 PAY   9 

    0x78847979,// 39 PAY  10 

    0x59854365,// 40 PAY  11 

    0x1d402266,// 41 PAY  12 

    0x36b057ba,// 42 PAY  13 

    0x228b9efc,// 43 PAY  14 

    0xfa7a7af2,// 44 PAY  15 

    0x4d391700,// 45 PAY  16 

    0x5205dc9e,// 46 PAY  17 

    0x199792e1,// 47 PAY  18 

    0x777e2a6d,// 48 PAY  19 

    0x0b8a6b71,// 49 PAY  20 

    0x1f99669c,// 50 PAY  21 

    0x5a9f895f,// 51 PAY  22 

    0x3757450d,// 52 PAY  23 

    0xe7365ef0,// 53 PAY  24 

    0xc8392a86,// 54 PAY  25 

    0xd066f60f,// 55 PAY  26 

    0xd3397cda,// 56 PAY  27 

    0x11fbe978,// 57 PAY  28 

    0x8696245c,// 58 PAY  29 

    0x7ef60cda,// 59 PAY  30 

    0xddd7a3bf,// 60 PAY  31 

    0x34a62b31,// 61 PAY  32 

    0x427ab562,// 62 PAY  33 

    0x0f18bcdb,// 63 PAY  34 

    0x0b2ad22c,// 64 PAY  35 

    0x6d5526e7,// 65 PAY  36 

    0x99a6f54a,// 66 PAY  37 

    0xaa239aed,// 67 PAY  38 

    0xb0b8a2c9,// 68 PAY  39 

    0xbe367f4f,// 69 PAY  40 

    0x35c90093,// 70 PAY  41 

    0xca3e3442,// 71 PAY  42 

    0x704d8928,// 72 PAY  43 

    0xe5062988,// 73 PAY  44 

    0xc85695a7,// 74 PAY  45 

    0x268f9cf4,// 75 PAY  46 

    0x6516aa45,// 76 PAY  47 

    0x4b092b04,// 77 PAY  48 

    0x713ae8f8,// 78 PAY  49 

    0xd8b15ff0,// 79 PAY  50 

    0x64511f90,// 80 PAY  51 

    0xe37a23e2,// 81 PAY  52 

    0x4c8c0526,// 82 PAY  53 

    0xb25b1b36,// 83 PAY  54 

    0x2e368e35,// 84 PAY  55 

    0x4cbd1c30,// 85 PAY  56 

    0x4966814a,// 86 PAY  57 

    0xb5c3984f,// 87 PAY  58 

    0x5c05895a,// 88 PAY  59 

    0xf5816f30,// 89 PAY  60 

    0x5c233c97,// 90 PAY  61 

    0x328aba75,// 91 PAY  62 

    0x2bbbb667,// 92 PAY  63 

    0x04a33793,// 93 PAY  64 

    0x91a9b728,// 94 PAY  65 

    0xa7afb07a,// 95 PAY  66 

    0x50ca47c0,// 96 PAY  67 

    0xd8b2434f,// 97 PAY  68 

    0x409ee1e2,// 98 PAY  69 

    0x498d0d13,// 99 PAY  70 

    0x824cf0ca,// 100 PAY  71 

    0xea73bf80,// 101 PAY  72 

    0x155fced0,// 102 PAY  73 

    0x16a0cfe6,// 103 PAY  74 

    0x8243fc51,// 104 PAY  75 

    0x4022fd2b,// 105 PAY  76 

    0x573cedfd,// 106 PAY  77 

    0xcb5ddbd1,// 107 PAY  78 

    0x785b0ed5,// 108 PAY  79 

    0x9dd0ac68,// 109 PAY  80 

    0xe836fbd4,// 110 PAY  81 

    0x4d1a0bdb,// 111 PAY  82 

    0x9f2dcff8,// 112 PAY  83 

    0x8b933536,// 113 PAY  84 

    0x7470cc67,// 114 PAY  85 

    0x62e77802,// 115 PAY  86 

    0xdc5e5832,// 116 PAY  87 

    0x476367aa,// 117 PAY  88 

    0xd802cbc4,// 118 PAY  89 

    0x08bf93f4,// 119 PAY  90 

    0xab9f5bd6,// 120 PAY  91 

    0x2108c7af,// 121 PAY  92 

    0x81a95649,// 122 PAY  93 

    0xff7bdcb1,// 123 PAY  94 

    0xc79c64eb,// 124 PAY  95 

    0xd7c393e6,// 125 PAY  96 

    0x28db3a6a,// 126 PAY  97 

    0x777fad5a,// 127 PAY  98 

    0x995bcf49,// 128 PAY  99 

    0x10021218,// 129 PAY 100 

    0x8a419795,// 130 PAY 101 

    0x04cf6c62,// 131 PAY 102 

    0x150bf2f1,// 132 PAY 103 

    0x4ea52386,// 133 PAY 104 

    0xf876e793,// 134 PAY 105 

    0xe1d5d29a,// 135 PAY 106 

    0xc9d67894,// 136 PAY 107 

    0x07427658,// 137 PAY 108 

    0xa9ea0d90,// 138 PAY 109 

    0x9365490b,// 139 PAY 110 

    0x12b15e2a,// 140 PAY 111 

    0x201f5fec,// 141 PAY 112 

    0xe3134bae,// 142 PAY 113 

/// STA is 1 words. 

/// STA num_pkts       : 179 

/// STA pkt_idx        : 154 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xb8 

    0x0269b8b3 // 143 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt32_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x809128f5,// 4 SCX   2 

    0x00004282,// 5 SCX   3 

    0x45755211,// 6 SCX   4 

    0xc8d42ec6,// 7 SCX   5 

    0xcbbed1b9,// 8 SCX   6 

    0xd1668e25,// 9 SCX   7 

    0x824765a2,// 10 SCX   8 

    0x42ca4286,// 11 SCX   9 

    0xf0e607c4,// 12 SCX  10 

    0x248eabac,// 13 SCX  11 

    0xb1dbf5b9,// 14 SCX  12 

    0x999dcd00,// 15 SCX  13 

    0xafccb82c,// 16 SCX  14 

    0x89ce3293,// 17 SCX  15 

    0xe2223104,// 18 SCX  16 

    0x365fdb80,// 19 SCX  17 

    0xb74a9dca,// 20 SCX  18 

    0xee4fe91a,// 21 SCX  19 

    0xe4536ade,// 22 SCX  20 

    0x25d16d84,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 937 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 233 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 233 

/// BFD lencrypto      : 8 

/// BFD ofstcrypto     : 224 

/// BFD (ofst+len)cry  : 232 

/// BFD ofstiv         : 100 

/// BFD ofsticv        : 288 

    0x000000e9,// 24 BFD   1 

    0x00e00008,// 25 BFD   2 

    0x01200064,// 26 BFD   3 

/// MFM is 5 words. 

/// MFM vldnibs        : 20 

    0x2000fe93,// 27 MFM   1 

    0x282f8285,// 28 MFM   2 

    0x024b35ef,// 29 MFM   3 

    0xa8f90b09,// 30 MFM   4 

    0x70550000,// 31 MFM   5 

/// BDA is 236 words. 

/// BDA size     is 937 (0x3a9) 

/// BDA id       is 0x1659 

    0x03a91659,// 32 BDA   1 

/// PAY Generic Data size   : 937 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x130bf83c,// 33 PAY   1 

    0xc924b476,// 34 PAY   2 

    0x2651010c,// 35 PAY   3 

    0xfe5d0365,// 36 PAY   4 

    0x1a625506,// 37 PAY   5 

    0x29de606b,// 38 PAY   6 

    0x053c2093,// 39 PAY   7 

    0xc2c84631,// 40 PAY   8 

    0x57ee8952,// 41 PAY   9 

    0x2d2598b3,// 42 PAY  10 

    0x799ec398,// 43 PAY  11 

    0x0be56c96,// 44 PAY  12 

    0xf9f44a80,// 45 PAY  13 

    0xa92b7157,// 46 PAY  14 

    0x75e5e0ce,// 47 PAY  15 

    0xf61f3c4d,// 48 PAY  16 

    0xdf05dfd0,// 49 PAY  17 

    0x4a4101ea,// 50 PAY  18 

    0x59f074cb,// 51 PAY  19 

    0xdddeb6e2,// 52 PAY  20 

    0x714d198e,// 53 PAY  21 

    0x3efa4072,// 54 PAY  22 

    0x36529d6d,// 55 PAY  23 

    0x74db2520,// 56 PAY  24 

    0x87dcb5cb,// 57 PAY  25 

    0xd87c1530,// 58 PAY  26 

    0x31147349,// 59 PAY  27 

    0xd723cedd,// 60 PAY  28 

    0xcc172339,// 61 PAY  29 

    0x1b5636b2,// 62 PAY  30 

    0xbdee3f2d,// 63 PAY  31 

    0x7fbc9dae,// 64 PAY  32 

    0x8c8fa18b,// 65 PAY  33 

    0x3538836e,// 66 PAY  34 

    0xe0dc024b,// 67 PAY  35 

    0x7f16e52d,// 68 PAY  36 

    0x8f014c60,// 69 PAY  37 

    0x9e3e79f1,// 70 PAY  38 

    0xa7405c19,// 71 PAY  39 

    0x3b8f5f64,// 72 PAY  40 

    0xbd5ca0e5,// 73 PAY  41 

    0x0938e2cf,// 74 PAY  42 

    0xc5b8e5d8,// 75 PAY  43 

    0x9593172e,// 76 PAY  44 

    0xd36dc37c,// 77 PAY  45 

    0xfa32f360,// 78 PAY  46 

    0xadc77759,// 79 PAY  47 

    0x8eb1a3af,// 80 PAY  48 

    0x49a61e04,// 81 PAY  49 

    0x1193e711,// 82 PAY  50 

    0x385dd04d,// 83 PAY  51 

    0x6921b3a0,// 84 PAY  52 

    0xe68ddc79,// 85 PAY  53 

    0x9e7c8f2f,// 86 PAY  54 

    0xd75c9734,// 87 PAY  55 

    0x4253c645,// 88 PAY  56 

    0x7a8d87fd,// 89 PAY  57 

    0x86eab45c,// 90 PAY  58 

    0x032eac44,// 91 PAY  59 

    0x82366b6d,// 92 PAY  60 

    0xfd82c6be,// 93 PAY  61 

    0x39fdd88c,// 94 PAY  62 

    0x5beff27c,// 95 PAY  63 

    0xe14dc57b,// 96 PAY  64 

    0x3b8f5928,// 97 PAY  65 

    0x9e9d7e6a,// 98 PAY  66 

    0x5bf21e5f,// 99 PAY  67 

    0xcff832a7,// 100 PAY  68 

    0xaf6f3af6,// 101 PAY  69 

    0xbe058445,// 102 PAY  70 

    0x6616a208,// 103 PAY  71 

    0x6744cb7e,// 104 PAY  72 

    0x7dd91422,// 105 PAY  73 

    0x645af8f7,// 106 PAY  74 

    0x46cbcda7,// 107 PAY  75 

    0xfed31748,// 108 PAY  76 

    0xf8101e10,// 109 PAY  77 

    0xbc5bb3d3,// 110 PAY  78 

    0x453575ae,// 111 PAY  79 

    0x9e03c156,// 112 PAY  80 

    0x2d155b85,// 113 PAY  81 

    0xce75039f,// 114 PAY  82 

    0x2e65a9f4,// 115 PAY  83 

    0x2d5c158b,// 116 PAY  84 

    0x602445a7,// 117 PAY  85 

    0xcd698322,// 118 PAY  86 

    0xc9988b12,// 119 PAY  87 

    0x76587638,// 120 PAY  88 

    0x784a3689,// 121 PAY  89 

    0xde0dfa88,// 122 PAY  90 

    0x9fafe282,// 123 PAY  91 

    0x7188fb36,// 124 PAY  92 

    0x75cb2f57,// 125 PAY  93 

    0xf2af323c,// 126 PAY  94 

    0xc0d9a1a0,// 127 PAY  95 

    0xd39adf3b,// 128 PAY  96 

    0x5fbbf3d3,// 129 PAY  97 

    0x1c45440b,// 130 PAY  98 

    0x236ed4dd,// 131 PAY  99 

    0xeaea3362,// 132 PAY 100 

    0xf0fbff52,// 133 PAY 101 

    0x96a89b9c,// 134 PAY 102 

    0xb418f0c4,// 135 PAY 103 

    0x1481632f,// 136 PAY 104 

    0x105c2766,// 137 PAY 105 

    0x0b7c0701,// 138 PAY 106 

    0x6435659c,// 139 PAY 107 

    0x9413d5dc,// 140 PAY 108 

    0x99ac87b5,// 141 PAY 109 

    0x82ef6eac,// 142 PAY 110 

    0x083e08ed,// 143 PAY 111 

    0x721e13aa,// 144 PAY 112 

    0xd280a9a9,// 145 PAY 113 

    0x0c1b9636,// 146 PAY 114 

    0xe107b3ac,// 147 PAY 115 

    0x74e8cc3c,// 148 PAY 116 

    0x971f6273,// 149 PAY 117 

    0xbb0ff2c3,// 150 PAY 118 

    0x68fe1a89,// 151 PAY 119 

    0xaacac681,// 152 PAY 120 

    0x8263ecc7,// 153 PAY 121 

    0x70234f8d,// 154 PAY 122 

    0x15136c37,// 155 PAY 123 

    0xb995ffd3,// 156 PAY 124 

    0xf8f76426,// 157 PAY 125 

    0x1ade06f8,// 158 PAY 126 

    0x86849671,// 159 PAY 127 

    0xe650466c,// 160 PAY 128 

    0x1bd15cd7,// 161 PAY 129 

    0x4da15c3d,// 162 PAY 130 

    0x4812ba27,// 163 PAY 131 

    0x6a01594f,// 164 PAY 132 

    0x67675106,// 165 PAY 133 

    0x5e26dad8,// 166 PAY 134 

    0x260b8789,// 167 PAY 135 

    0xbd941f50,// 168 PAY 136 

    0xf97e4d8d,// 169 PAY 137 

    0x428774bc,// 170 PAY 138 

    0x55ea8a94,// 171 PAY 139 

    0xccb5b21e,// 172 PAY 140 

    0x82ad1a26,// 173 PAY 141 

    0xf42cad16,// 174 PAY 142 

    0xbb4f6771,// 175 PAY 143 

    0xbcb18675,// 176 PAY 144 

    0xe59f9ad1,// 177 PAY 145 

    0x65d46656,// 178 PAY 146 

    0xb7e8f246,// 179 PAY 147 

    0x838d6dc1,// 180 PAY 148 

    0x7766d1de,// 181 PAY 149 

    0x366c3274,// 182 PAY 150 

    0xd6a10111,// 183 PAY 151 

    0xfc4b16ae,// 184 PAY 152 

    0xc896872a,// 185 PAY 153 

    0xe94e4111,// 186 PAY 154 

    0x44fb49d9,// 187 PAY 155 

    0x0fb5a840,// 188 PAY 156 

    0x374c8402,// 189 PAY 157 

    0x3912bce0,// 190 PAY 158 

    0x7566b35e,// 191 PAY 159 

    0xd3097b5a,// 192 PAY 160 

    0x44252411,// 193 PAY 161 

    0x6836aed2,// 194 PAY 162 

    0xdbedbd42,// 195 PAY 163 

    0x85933c7c,// 196 PAY 164 

    0x1662f03c,// 197 PAY 165 

    0x8b1b4095,// 198 PAY 166 

    0x545f2284,// 199 PAY 167 

    0x80aa38fd,// 200 PAY 168 

    0x219bbd05,// 201 PAY 169 

    0xbc3d82c5,// 202 PAY 170 

    0xe0401621,// 203 PAY 171 

    0x260e1f72,// 204 PAY 172 

    0x8828e657,// 205 PAY 173 

    0x3a5d9405,// 206 PAY 174 

    0xfab92df5,// 207 PAY 175 

    0x416dcb96,// 208 PAY 176 

    0x84dcfb4b,// 209 PAY 177 

    0x452f3747,// 210 PAY 178 

    0xadec8c12,// 211 PAY 179 

    0xd3e1804e,// 212 PAY 180 

    0x27fea89c,// 213 PAY 181 

    0x2a3f8221,// 214 PAY 182 

    0x665265ec,// 215 PAY 183 

    0x1b3d8440,// 216 PAY 184 

    0x9e2e81c4,// 217 PAY 185 

    0x924d396d,// 218 PAY 186 

    0x10b6bec3,// 219 PAY 187 

    0x7060337d,// 220 PAY 188 

    0x6106e77e,// 221 PAY 189 

    0x13c48f6a,// 222 PAY 190 

    0x86327c67,// 223 PAY 191 

    0x2ac703a2,// 224 PAY 192 

    0xfe3488f4,// 225 PAY 193 

    0x07aa95c1,// 226 PAY 194 

    0xdbfa38ad,// 227 PAY 195 

    0xc0c315a8,// 228 PAY 196 

    0x62de1d82,// 229 PAY 197 

    0x2b27db92,// 230 PAY 198 

    0xd09a8fb7,// 231 PAY 199 

    0xcdc9c6b9,// 232 PAY 200 

    0x5886a45e,// 233 PAY 201 

    0x226bc834,// 234 PAY 202 

    0x4dc815fd,// 235 PAY 203 

    0x3d44a25c,// 236 PAY 204 

    0xd7294c91,// 237 PAY 205 

    0xa5d4162b,// 238 PAY 206 

    0xfc53b719,// 239 PAY 207 

    0x5fb51e61,// 240 PAY 208 

    0x5fd2df75,// 241 PAY 209 

    0xe63acf60,// 242 PAY 210 

    0x03114939,// 243 PAY 211 

    0x952cd21b,// 244 PAY 212 

    0x65623fe0,// 245 PAY 213 

    0x49387c8b,// 246 PAY 214 

    0x2e10f560,// 247 PAY 215 

    0x49e61868,// 248 PAY 216 

    0x14296a24,// 249 PAY 217 

    0xffc44940,// 250 PAY 218 

    0x2b73c553,// 251 PAY 219 

    0x40ed6f0e,// 252 PAY 220 

    0xe34b4d29,// 253 PAY 221 

    0x891d4a05,// 254 PAY 222 

    0xe8d25b03,// 255 PAY 223 

    0xe1693faf,// 256 PAY 224 

    0x82688edf,// 257 PAY 225 

    0x7b720add,// 258 PAY 226 

    0x7ce800ee,// 259 PAY 227 

    0x213ab194,// 260 PAY 228 

    0x35a69f28,// 261 PAY 229 

    0x59006e24,// 262 PAY 230 

    0x7e3b917c,// 263 PAY 231 

    0xea022215,// 264 PAY 232 

    0x8e89f82a,// 265 PAY 233 

    0x52e8a053,// 266 PAY 234 

    0xfd000000,// 267 PAY 235 

/// STA is 1 words. 

/// STA num_pkts       : 75 

/// STA pkt_idx        : 68 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x28 

    0x0111284b // 268 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt33_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x8081285f,// 4 SCX   2 

    0x00001400,// 5 SCX   3 

    0x35f37f50,// 6 SCX   4 

    0xc0b3d5e5,// 7 SCX   5 

    0x38bd79e6,// 8 SCX   6 

    0xa25f8216,// 9 SCX   7 

    0xec9804c1,// 10 SCX   8 

    0xdceeb8b8,// 11 SCX   9 

    0xfc389fa8,// 12 SCX  10 

    0x94cac2e3,// 13 SCX  11 

    0x90b416a5,// 14 SCX  12 

    0x57c80d87,// 15 SCX  13 

    0xf37b4b30,// 16 SCX  14 

    0xecd0cdad,// 17 SCX  15 

    0x9666f250,// 18 SCX  16 

    0x113dc5c8,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 106 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 87 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 87 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 48 

/// BFD (ofst+len)cry  : 64 

/// BFD ofstiv         : 24 

/// BFD ofsticv        : 88 

    0x00000057,// 20 BFD   1 

    0x00300010,// 21 BFD   2 

    0x00580018,// 22 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : d 

    0x0d006f65,// 23 MFM   1 

    0x24b0b1c9,// 24 MFM   2 

    0x20000000,// 25 MFM   3 

/// BDA is 28 words. 

/// BDA size     is 106 (0x6a) 

/// BDA id       is 0x8db2 

    0x006a8db2,// 26 BDA   1 

/// PAY Generic Data size   : 106 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x2c16a15d,// 27 PAY   1 

    0x56af1582,// 28 PAY   2 

    0x1e5e319e,// 29 PAY   3 

    0xf7a70bf5,// 30 PAY   4 

    0x09ac55bc,// 31 PAY   5 

    0xdc2e4719,// 32 PAY   6 

    0xe839f09d,// 33 PAY   7 

    0x1ef204d2,// 34 PAY   8 

    0x19283c36,// 35 PAY   9 

    0x59456232,// 36 PAY  10 

    0xe17291d6,// 37 PAY  11 

    0x2f78c5d1,// 38 PAY  12 

    0x6e107182,// 39 PAY  13 

    0x20c39229,// 40 PAY  14 

    0x14ceae2d,// 41 PAY  15 

    0xf5da7bcc,// 42 PAY  16 

    0x8fb27665,// 43 PAY  17 

    0xe16c691e,// 44 PAY  18 

    0x42b923d1,// 45 PAY  19 

    0x1334d8ee,// 46 PAY  20 

    0xff41d971,// 47 PAY  21 

    0xf186da92,// 48 PAY  22 

    0xf7f9a24d,// 49 PAY  23 

    0x7a860f85,// 50 PAY  24 

    0xc9c75d11,// 51 PAY  25 

    0x4653d6f1,// 52 PAY  26 

    0x302d0000,// 53 PAY  27 

/// STA is 1 words. 

/// STA num_pkts       : 55 

/// STA pkt_idx        : 141 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xb2 

    0x0234b237 // 54 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt34_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv !sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x8086284a,// 4 SCX   2 

    0x00006344,// 5 SCX   3 

    0xa4864581,// 6 SCX   4 

    0xf74f0404,// 7 SCX   5 

    0x3ec0667e,// 8 SCX   6 

    0xd468d66d,// 9 SCX   7 

    0xea048b29,// 10 SCX   8 

    0xd5a588b8,// 11 SCX   9 

    0xa2d318be,// 12 SCX  10 

    0x3ba8139d,// 13 SCX  11 

    0x2c3c1c4d,// 14 SCX  12 

    0x04c9667f,// 15 SCX  13 

    0xa4efcb21,// 16 SCX  14 

    0xc2a853d3,// 17 SCX  15 

    0x41a566b6,// 18 SCX  16 

    0xf4411b1d,// 19 SCX  17 

    0xbffbd64a,// 20 SCX  18 

    0x0791dccf,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1160 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1076 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1076 

/// BFD lencrypto      : 608 

/// BFD ofstcrypto     : 136 

/// BFD (ofst+len)cry  : 744 

/// BFD ofstiv         : 112 

/// BFD ofsticv        : 1144 

    0x00000434,// 22 BFD   1 

    0x00880260,// 23 BFD   2 

    0x04780070,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c000f1b,// 25 MFM   1 

    0x39411240,// 26 MFM   2 

    0x6f0fbcde,// 27 MFM   3 

    0x2e350532,// 28 MFM   4 

    0x645bc16a,// 29 MFM   5 

    0xe2d7a1c6,// 30 MFM   6 

    0x2fae0172,// 31 MFM   7 

    0x4aece30f,// 32 MFM   8 

    0x367dbf35,// 33 MFM   9 

    0x934eb421,// 34 MFM  10 

    0x0cd14b00,// 35 MFM  11 

    0xd45b82bb,// 36 MFM  12 

    0xa5629213,// 37 MFM  13 

    0x1ef5b0f1,// 38 MFM  14 

    0x58254ee8,// 39 MFM  15 

    0x6010b019,// 40 MFM  16 

/// BDA is 291 words. 

/// BDA size     is 1160 (0x488) 

/// BDA id       is 0xaed0 

    0x0488aed0,// 41 BDA   1 

/// PAY Generic Data size   : 1160 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x3c4fab63,// 42 PAY   1 

    0x4c7417d9,// 43 PAY   2 

    0x265850fa,// 44 PAY   3 

    0x97a84cd9,// 45 PAY   4 

    0x4115d20d,// 46 PAY   5 

    0x4a8fd5c4,// 47 PAY   6 

    0x03f1d461,// 48 PAY   7 

    0x3fe00874,// 49 PAY   8 

    0x23f810ee,// 50 PAY   9 

    0x02772939,// 51 PAY  10 

    0xf28163a0,// 52 PAY  11 

    0xd281652d,// 53 PAY  12 

    0x26caee56,// 54 PAY  13 

    0x4647be7c,// 55 PAY  14 

    0x7e48d899,// 56 PAY  15 

    0x9ffe818e,// 57 PAY  16 

    0xf1ad5475,// 58 PAY  17 

    0x85792f28,// 59 PAY  18 

    0x2e6578aa,// 60 PAY  19 

    0x780dc5ae,// 61 PAY  20 

    0xb73e9be6,// 62 PAY  21 

    0x3c2c7ea2,// 63 PAY  22 

    0x85292175,// 64 PAY  23 

    0x4c0de51d,// 65 PAY  24 

    0xa996d186,// 66 PAY  25 

    0xab372122,// 67 PAY  26 

    0xefd8a713,// 68 PAY  27 

    0x8d5adb3c,// 69 PAY  28 

    0xed60631d,// 70 PAY  29 

    0xe8ab2eb5,// 71 PAY  30 

    0x53f279bd,// 72 PAY  31 

    0x7633504d,// 73 PAY  32 

    0x6db0be43,// 74 PAY  33 

    0x468ce3a1,// 75 PAY  34 

    0x1e89f850,// 76 PAY  35 

    0x2fe43f88,// 77 PAY  36 

    0xb0908303,// 78 PAY  37 

    0xa9e5c819,// 79 PAY  38 

    0xf9a03abb,// 80 PAY  39 

    0x8e2d768c,// 81 PAY  40 

    0xbfaed154,// 82 PAY  41 

    0xb5f0c0bc,// 83 PAY  42 

    0x856a5b83,// 84 PAY  43 

    0xae16d93d,// 85 PAY  44 

    0x2612b691,// 86 PAY  45 

    0xebc70ec2,// 87 PAY  46 

    0xea2e7c41,// 88 PAY  47 

    0xe6bb30b9,// 89 PAY  48 

    0xfa89d7dd,// 90 PAY  49 

    0x10edf7f4,// 91 PAY  50 

    0xc96aa211,// 92 PAY  51 

    0x5755f53c,// 93 PAY  52 

    0xd475c0f4,// 94 PAY  53 

    0x709b5751,// 95 PAY  54 

    0xe6097fcc,// 96 PAY  55 

    0x23730de8,// 97 PAY  56 

    0x89c69fd5,// 98 PAY  57 

    0x64cfb202,// 99 PAY  58 

    0xfd50cb1d,// 100 PAY  59 

    0x6ae14475,// 101 PAY  60 

    0x6cf2d3b2,// 102 PAY  61 

    0xbb273513,// 103 PAY  62 

    0x9a908def,// 104 PAY  63 

    0xcca4f6b5,// 105 PAY  64 

    0x47132a34,// 106 PAY  65 

    0x79a2d15c,// 107 PAY  66 

    0xc882233d,// 108 PAY  67 

    0xbf490450,// 109 PAY  68 

    0xbb12f49e,// 110 PAY  69 

    0x913dff7d,// 111 PAY  70 

    0x209ff651,// 112 PAY  71 

    0x46d5ee6a,// 113 PAY  72 

    0xaa21747a,// 114 PAY  73 

    0x4a221778,// 115 PAY  74 

    0xd8ade165,// 116 PAY  75 

    0x4f2c19fc,// 117 PAY  76 

    0x11757c15,// 118 PAY  77 

    0x585052a1,// 119 PAY  78 

    0x285d25f1,// 120 PAY  79 

    0x3f1cd80d,// 121 PAY  80 

    0xac0790ff,// 122 PAY  81 

    0x35b9ba86,// 123 PAY  82 

    0xc1f18335,// 124 PAY  83 

    0x368694fc,// 125 PAY  84 

    0x91de3706,// 126 PAY  85 

    0x955dfc9d,// 127 PAY  86 

    0x44cec6f8,// 128 PAY  87 

    0x36ca80a3,// 129 PAY  88 

    0x607616a3,// 130 PAY  89 

    0xdd9e58a4,// 131 PAY  90 

    0x4205d47c,// 132 PAY  91 

    0x31d613fd,// 133 PAY  92 

    0x7446f932,// 134 PAY  93 

    0x6a7e808a,// 135 PAY  94 

    0xe38a1f32,// 136 PAY  95 

    0xf5b937f9,// 137 PAY  96 

    0x510d550a,// 138 PAY  97 

    0x7bc43ce3,// 139 PAY  98 

    0x685d18de,// 140 PAY  99 

    0x2bbca675,// 141 PAY 100 

    0x80889715,// 142 PAY 101 

    0x263a0823,// 143 PAY 102 

    0x748bc2ee,// 144 PAY 103 

    0xff009bed,// 145 PAY 104 

    0xfeaf6326,// 146 PAY 105 

    0x2b9f7552,// 147 PAY 106 

    0x726bbaf2,// 148 PAY 107 

    0x37d84e55,// 149 PAY 108 

    0x28a16903,// 150 PAY 109 

    0x83d22925,// 151 PAY 110 

    0x3e961a74,// 152 PAY 111 

    0xa0458312,// 153 PAY 112 

    0x7bbcc943,// 154 PAY 113 

    0x80ec4978,// 155 PAY 114 

    0x928b4587,// 156 PAY 115 

    0x68cd1e9b,// 157 PAY 116 

    0x93ea034a,// 158 PAY 117 

    0xe37dd3be,// 159 PAY 118 

    0x1cd5c286,// 160 PAY 119 

    0xc59ecd52,// 161 PAY 120 

    0x614850fa,// 162 PAY 121 

    0xdd38973a,// 163 PAY 122 

    0x61273286,// 164 PAY 123 

    0x91d6f96e,// 165 PAY 124 

    0x657a0170,// 166 PAY 125 

    0x12a54ade,// 167 PAY 126 

    0xa148eea5,// 168 PAY 127 

    0xdf188b54,// 169 PAY 128 

    0x1dc1c240,// 170 PAY 129 

    0xcef59c39,// 171 PAY 130 

    0xd7adf97c,// 172 PAY 131 

    0x2aef622d,// 173 PAY 132 

    0x9e2633e9,// 174 PAY 133 

    0x3ed2ca34,// 175 PAY 134 

    0x6126bc07,// 176 PAY 135 

    0xe2b4dc55,// 177 PAY 136 

    0x58442cd9,// 178 PAY 137 

    0xe8b528a6,// 179 PAY 138 

    0x11260508,// 180 PAY 139 

    0xa445155b,// 181 PAY 140 

    0x1d59524e,// 182 PAY 141 

    0xb07be8c1,// 183 PAY 142 

    0x70d70be4,// 184 PAY 143 

    0x960b1056,// 185 PAY 144 

    0x3546327a,// 186 PAY 145 

    0x896f9a63,// 187 PAY 146 

    0xa73f6ad9,// 188 PAY 147 

    0xd92a53da,// 189 PAY 148 

    0x5af66a8d,// 190 PAY 149 

    0x2ff38efc,// 191 PAY 150 

    0x9694ed25,// 192 PAY 151 

    0xcd7857b6,// 193 PAY 152 

    0xca83a22c,// 194 PAY 153 

    0xc589101f,// 195 PAY 154 

    0xeacd5da2,// 196 PAY 155 

    0x3c6025b0,// 197 PAY 156 

    0xfae22b59,// 198 PAY 157 

    0x81ac9b91,// 199 PAY 158 

    0x5052e368,// 200 PAY 159 

    0xb7a58eb6,// 201 PAY 160 

    0x6b98c04e,// 202 PAY 161 

    0x083f2537,// 203 PAY 162 

    0x4f53da1b,// 204 PAY 163 

    0xd738ef82,// 205 PAY 164 

    0x77b57a85,// 206 PAY 165 

    0xb0f42f8a,// 207 PAY 166 

    0xa7735fe5,// 208 PAY 167 

    0xe3e1a525,// 209 PAY 168 

    0xc23b47b6,// 210 PAY 169 

    0xb975e681,// 211 PAY 170 

    0xb5a3eaf2,// 212 PAY 171 

    0xef2dc94f,// 213 PAY 172 

    0x4355dcdc,// 214 PAY 173 

    0xaebfff35,// 215 PAY 174 

    0x64f4a641,// 216 PAY 175 

    0x7c58511c,// 217 PAY 176 

    0xc6a493ab,// 218 PAY 177 

    0x100cb849,// 219 PAY 178 

    0xb7877f9a,// 220 PAY 179 

    0xa09849ab,// 221 PAY 180 

    0x964f7b11,// 222 PAY 181 

    0x2914d9b6,// 223 PAY 182 

    0xbbde5d38,// 224 PAY 183 

    0x0803ab27,// 225 PAY 184 

    0x0349e9b0,// 226 PAY 185 

    0x94047a19,// 227 PAY 186 

    0x10d1fc0e,// 228 PAY 187 

    0x46b0f5e0,// 229 PAY 188 

    0xc1042e76,// 230 PAY 189 

    0x97a9d63a,// 231 PAY 190 

    0x495ba8fd,// 232 PAY 191 

    0x770f3f78,// 233 PAY 192 

    0x02014a83,// 234 PAY 193 

    0x87f9b7d2,// 235 PAY 194 

    0x646bf453,// 236 PAY 195 

    0xfae483d6,// 237 PAY 196 

    0xde1d00c1,// 238 PAY 197 

    0xea8fd1f6,// 239 PAY 198 

    0xfc070852,// 240 PAY 199 

    0xb756e10e,// 241 PAY 200 

    0x5a04268f,// 242 PAY 201 

    0x819964c5,// 243 PAY 202 

    0x374a08cf,// 244 PAY 203 

    0xfca99a9f,// 245 PAY 204 

    0xc32d793b,// 246 PAY 205 

    0x24cc4e08,// 247 PAY 206 

    0x38acfc82,// 248 PAY 207 

    0x3cf85c8b,// 249 PAY 208 

    0x99c5c357,// 250 PAY 209 

    0x69fd49b5,// 251 PAY 210 

    0xc9a15161,// 252 PAY 211 

    0xed60056d,// 253 PAY 212 

    0x3d2378f7,// 254 PAY 213 

    0x334b542e,// 255 PAY 214 

    0xe226f81d,// 256 PAY 215 

    0x2a95778f,// 257 PAY 216 

    0x691ace4d,// 258 PAY 217 

    0x7d780527,// 259 PAY 218 

    0xbe79f979,// 260 PAY 219 

    0xc4c2c52e,// 261 PAY 220 

    0xc6e8b61c,// 262 PAY 221 

    0xde37f5da,// 263 PAY 222 

    0xafc9efd3,// 264 PAY 223 

    0xc5df0b4a,// 265 PAY 224 

    0x6a888dcd,// 266 PAY 225 

    0x57314a70,// 267 PAY 226 

    0xb959f31e,// 268 PAY 227 

    0x4bad0cd8,// 269 PAY 228 

    0x29b02a8a,// 270 PAY 229 

    0x7ac08633,// 271 PAY 230 

    0xb1d71bb3,// 272 PAY 231 

    0x1847b7ab,// 273 PAY 232 

    0xf7aee9cf,// 274 PAY 233 

    0xe70581f7,// 275 PAY 234 

    0x51d818bf,// 276 PAY 235 

    0x56f80f10,// 277 PAY 236 

    0x26eece91,// 278 PAY 237 

    0x20b82882,// 279 PAY 238 

    0xdbf58f62,// 280 PAY 239 

    0xc99140e1,// 281 PAY 240 

    0xaf8612cd,// 282 PAY 241 

    0x5288e3db,// 283 PAY 242 

    0x432e756e,// 284 PAY 243 

    0x3069ccc2,// 285 PAY 244 

    0x5f65bc1f,// 286 PAY 245 

    0x8ec92b04,// 287 PAY 246 

    0x626274fb,// 288 PAY 247 

    0xba5516ed,// 289 PAY 248 

    0x4c942479,// 290 PAY 249 

    0xc1802428,// 291 PAY 250 

    0x471987d9,// 292 PAY 251 

    0xa591a105,// 293 PAY 252 

    0x1e60b280,// 294 PAY 253 

    0x2cc44562,// 295 PAY 254 

    0x5d9df1a8,// 296 PAY 255 

    0x9ccfae6e,// 297 PAY 256 

    0x2e209636,// 298 PAY 257 

    0x96ccb8f6,// 299 PAY 258 

    0xe281d869,// 300 PAY 259 

    0x6c6ed117,// 301 PAY 260 

    0x0e6edc16,// 302 PAY 261 

    0x8c2ebd92,// 303 PAY 262 

    0xd51f5818,// 304 PAY 263 

    0xc4452bc9,// 305 PAY 264 

    0x49c671e0,// 306 PAY 265 

    0x6aba6f1b,// 307 PAY 266 

    0x12efe8d9,// 308 PAY 267 

    0x6f5ce336,// 309 PAY 268 

    0xf527c7a5,// 310 PAY 269 

    0x6512b0f5,// 311 PAY 270 

    0x58faf01d,// 312 PAY 271 

    0x212ce813,// 313 PAY 272 

    0x6a18f855,// 314 PAY 273 

    0x412ab56d,// 315 PAY 274 

    0xba33e98c,// 316 PAY 275 

    0x0e582869,// 317 PAY 276 

    0x6cda8c7a,// 318 PAY 277 

    0x308565ad,// 319 PAY 278 

    0xd229816c,// 320 PAY 279 

    0x1cdecb92,// 321 PAY 280 

    0x5e3f81c2,// 322 PAY 281 

    0x1d340b65,// 323 PAY 282 

    0x6dee13c9,// 324 PAY 283 

    0xd8015b72,// 325 PAY 284 

    0xa4753683,// 326 PAY 285 

    0x7006bd14,// 327 PAY 286 

    0x5a6eda60,// 328 PAY 287 

    0x17e7b1ea,// 329 PAY 288 

    0x1020f116,// 330 PAY 289 

    0x2837ed3e,// 331 PAY 290 

/// STA is 1 words. 

/// STA num_pkts       : 84 

/// STA pkt_idx        : 173 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x3d 

    0x02b53d54 // 332 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt35_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000011,// 3 SCX   1 

    0x80812840,// 4 SCX   2 

    0x00002200,// 5 SCX   3 

    0x39f4431d,// 6 SCX   4 

    0x3663c1bd,// 7 SCX   5 

    0x891d902c,// 8 SCX   6 

    0x6f9cdec4,// 9 SCX   7 

    0x3fca4df5,// 10 SCX   8 

    0x73d12d8c,// 11 SCX   9 

    0x0da1626e,// 12 SCX  10 

    0x8228806b,// 13 SCX  11 

    0xe26d5473,// 14 SCX  12 

    0x14644a39,// 15 SCX  13 

    0x0891fc39,// 16 SCX  14 

    0x6f5c688a,// 17 SCX  15 

    0x57c0e47f,// 18 SCX  16 

    0x1070f80b,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 279 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 249 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 249 

/// BFD lencrypto      : 48 

/// BFD ofstcrypto     : 152 

/// BFD (ofst+len)cry  : 200 

/// BFD ofstiv         : 48 

/// BFD ofsticv        : 256 

    0x000000f9,// 20 BFD   1 

    0x00980030,// 21 BFD   2 

    0x01000030,// 22 BFD   3 

/// MFM is 8 words. 

/// MFM vldnibs        : 36 

    0x3600ab5c,// 23 MFM   1 

    0xe5b997c4,// 24 MFM   2 

    0x76aecd15,// 25 MFM   3 

    0x1a721608,// 26 MFM   4 

    0x11f75f3e,// 27 MFM   5 

    0xf535cd42,// 28 MFM   6 

    0x9317cc1f,// 29 MFM   7 

    0x50000000,// 30 MFM   8 

/// BDA is 71 words. 

/// BDA size     is 279 (0x117) 

/// BDA id       is 0x41dc 

    0x011741dc,// 31 BDA   1 

/// PAY Generic Data size   : 279 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x4b5cf2b9,// 32 PAY   1 

    0x870b2af2,// 33 PAY   2 

    0x4a3c9a55,// 34 PAY   3 

    0x9acd9659,// 35 PAY   4 

    0xdf7c9829,// 36 PAY   5 

    0xc20c84fa,// 37 PAY   6 

    0x34a94eb8,// 38 PAY   7 

    0x8b19d8b2,// 39 PAY   8 

    0x59b454c8,// 40 PAY   9 

    0x9cc82386,// 41 PAY  10 

    0xf637c6b2,// 42 PAY  11 

    0xa4fb8512,// 43 PAY  12 

    0x12e9e44c,// 44 PAY  13 

    0xcaf02f19,// 45 PAY  14 

    0x8a8754b0,// 46 PAY  15 

    0x302c32c5,// 47 PAY  16 

    0x2d7e9efe,// 48 PAY  17 

    0x868d5c01,// 49 PAY  18 

    0xc6031c90,// 50 PAY  19 

    0x2749fed5,// 51 PAY  20 

    0xa404911c,// 52 PAY  21 

    0x2596d519,// 53 PAY  22 

    0xf9c37ba7,// 54 PAY  23 

    0x492430f1,// 55 PAY  24 

    0xe85075aa,// 56 PAY  25 

    0x4df9d25a,// 57 PAY  26 

    0xe7dbb4d2,// 58 PAY  27 

    0x2dc33677,// 59 PAY  28 

    0xd0778dc7,// 60 PAY  29 

    0x7e7ba748,// 61 PAY  30 

    0x66888604,// 62 PAY  31 

    0x44beba7c,// 63 PAY  32 

    0x1566b695,// 64 PAY  33 

    0x72c369c8,// 65 PAY  34 

    0x10c267d7,// 66 PAY  35 

    0x18adea9c,// 67 PAY  36 

    0x88420930,// 68 PAY  37 

    0x5bdc912c,// 69 PAY  38 

    0x0d1c95e5,// 70 PAY  39 

    0x1c95b657,// 71 PAY  40 

    0x63446726,// 72 PAY  41 

    0x8bf15beb,// 73 PAY  42 

    0xb4714b20,// 74 PAY  43 

    0xd2c304d6,// 75 PAY  44 

    0x671e5eec,// 76 PAY  45 

    0x4a293f3b,// 77 PAY  46 

    0xd48d1d96,// 78 PAY  47 

    0xbc1ea3d5,// 79 PAY  48 

    0xe3886ada,// 80 PAY  49 

    0xc57bfc91,// 81 PAY  50 

    0xc08b19f3,// 82 PAY  51 

    0xe4ea32c3,// 83 PAY  52 

    0xdf0597ac,// 84 PAY  53 

    0x9332fa23,// 85 PAY  54 

    0x9f682c16,// 86 PAY  55 

    0x12e6bd2a,// 87 PAY  56 

    0x83eeeb7f,// 88 PAY  57 

    0x013d6cee,// 89 PAY  58 

    0xed077720,// 90 PAY  59 

    0x286fd9d1,// 91 PAY  60 

    0x373d3e18,// 92 PAY  61 

    0x05507c46,// 93 PAY  62 

    0xdee1eb01,// 94 PAY  63 

    0xe524699e,// 95 PAY  64 

    0x479a6ba5,// 96 PAY  65 

    0x3ed4344e,// 97 PAY  66 

    0xba382615,// 98 PAY  67 

    0x674a20b8,// 99 PAY  68 

    0x34b7e0ba,// 100 PAY  69 

    0x4a423800,// 101 PAY  70 

/// STA is 1 words. 

/// STA num_pkts       : 214 

/// STA pkt_idx        : 7 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xfa 

    0x001cfad6 // 102 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt36_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x03 

/// ECH pdu_tag        : 0x00 

    0x00030000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x80912879,// 4 SCX   2 

    0x00005382,// 5 SCX   3 

    0xe6009d69,// 6 SCX   4 

    0x2efd22ce,// 7 SCX   5 

    0x46ed1c19,// 8 SCX   6 

    0x38150954,// 9 SCX   7 

    0xc9e2ae96,// 10 SCX   8 

    0xfe07e242,// 11 SCX   9 

    0x125f9b8e,// 12 SCX  10 

    0x2e335692,// 13 SCX  11 

    0xa3bb6f0a,// 14 SCX  12 

    0x559a6a49,// 15 SCX  13 

    0xce86cd63,// 16 SCX  14 

    0xf0e89783,// 17 SCX  15 

    0xb8fecd21,// 18 SCX  16 

    0x6cb97ecd,// 19 SCX  17 

    0x1595eb0c,// 20 SCX  18 

    0x2c1b75d7,// 21 SCX  19 

    0xe27d4027,// 22 SCX  20 

    0x6944f6e0,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1392 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 693 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 693 

/// BFD lencrypto      : 156 

/// BFD ofstcrypto     : 72 

/// BFD (ofst+len)cry  : 228 

/// BFD ofstiv         : 56 

/// BFD ofsticv        : 1316 

    0x000002b5,// 24 BFD   1 

    0x0048009c,// 25 BFD   2 

    0x05240038,// 26 BFD   3 

/// MFM is 15 words. 

/// MFM vldnibs        : 74 

    0x74003106,// 27 MFM   1 

    0xf8af2bc9,// 28 MFM   2 

    0x53f3bf41,// 29 MFM   3 

    0x13d66b62,// 30 MFM   4 

    0xbf3edf82,// 31 MFM   5 

    0x2dbfad76,// 32 MFM   6 

    0x7031bdf3,// 33 MFM   7 

    0x6e7c21d4,// 34 MFM   8 

    0xf487f0de,// 35 MFM   9 

    0xcc953f18,// 36 MFM  10 

    0xe5287a7f,// 37 MFM  11 

    0xd2a9bc24,// 38 MFM  12 

    0xe2f94bd9,// 39 MFM  13 

    0x5447b545,// 40 MFM  14 

    0x61b2b9bb,// 41 MFM  15 

/// BDA is 349 words. 

/// BDA size     is 1392 (0x570) 

/// BDA id       is 0xda48 

    0x0570da48,// 42 BDA   1 

/// PAY Generic Data size   : 1392 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x80f7aad4,// 43 PAY   1 

    0x33ec42f2,// 44 PAY   2 

    0x246953fa,// 45 PAY   3 

    0x42dc9453,// 46 PAY   4 

    0xbd4593ba,// 47 PAY   5 

    0x2eafb682,// 48 PAY   6 

    0x994f83b0,// 49 PAY   7 

    0x68fca5b4,// 50 PAY   8 

    0x1e51dd88,// 51 PAY   9 

    0x7d158fff,// 52 PAY  10 

    0x3e3c66b4,// 53 PAY  11 

    0xb4e89601,// 54 PAY  12 

    0xe50a873a,// 55 PAY  13 

    0x56b51668,// 56 PAY  14 

    0x82a949b9,// 57 PAY  15 

    0xcf85cf6e,// 58 PAY  16 

    0x8483a78c,// 59 PAY  17 

    0xf77005ce,// 60 PAY  18 

    0xec7bb70f,// 61 PAY  19 

    0x4621f9de,// 62 PAY  20 

    0x7513c8ae,// 63 PAY  21 

    0x7862e5f3,// 64 PAY  22 

    0x506dfae1,// 65 PAY  23 

    0x4fe3e0a8,// 66 PAY  24 

    0x3424c563,// 67 PAY  25 

    0x2b30ec30,// 68 PAY  26 

    0x2a0e8783,// 69 PAY  27 

    0xbb1fba33,// 70 PAY  28 

    0x2af84080,// 71 PAY  29 

    0x5e81a4e8,// 72 PAY  30 

    0x4eb5afda,// 73 PAY  31 

    0xffb03645,// 74 PAY  32 

    0x5eb6c691,// 75 PAY  33 

    0x76c5298a,// 76 PAY  34 

    0xd26eae23,// 77 PAY  35 

    0x21d793b7,// 78 PAY  36 

    0x6c32a08a,// 79 PAY  37 

    0xa19be4cb,// 80 PAY  38 

    0x57577110,// 81 PAY  39 

    0xb565818e,// 82 PAY  40 

    0xf7e3ef93,// 83 PAY  41 

    0x0389be8f,// 84 PAY  42 

    0xbfc0247b,// 85 PAY  43 

    0x3d22f987,// 86 PAY  44 

    0x914a8750,// 87 PAY  45 

    0x8bc73b35,// 88 PAY  46 

    0x18199cd2,// 89 PAY  47 

    0x6ec575a2,// 90 PAY  48 

    0x68ded9a8,// 91 PAY  49 

    0x508ee7f5,// 92 PAY  50 

    0x9919240e,// 93 PAY  51 

    0xc138e1ae,// 94 PAY  52 

    0x1e60b28b,// 95 PAY  53 

    0xc8288857,// 96 PAY  54 

    0x10233734,// 97 PAY  55 

    0x0006cb1b,// 98 PAY  56 

    0xb8833a3d,// 99 PAY  57 

    0x4bbbab34,// 100 PAY  58 

    0x42c145c1,// 101 PAY  59 

    0xeb529e17,// 102 PAY  60 

    0x73ad364b,// 103 PAY  61 

    0xa4287dd9,// 104 PAY  62 

    0xff0b1a86,// 105 PAY  63 

    0xd6edc392,// 106 PAY  64 

    0xc523fa07,// 107 PAY  65 

    0x02c7d024,// 108 PAY  66 

    0xa2e98ab6,// 109 PAY  67 

    0x3404c55e,// 110 PAY  68 

    0xed8c3379,// 111 PAY  69 

    0x043bf689,// 112 PAY  70 

    0x8a2d9ed2,// 113 PAY  71 

    0xab52c933,// 114 PAY  72 

    0x3576fef7,// 115 PAY  73 

    0x3de63b26,// 116 PAY  74 

    0xc8907638,// 117 PAY  75 

    0x4d47370a,// 118 PAY  76 

    0xea8c6ef3,// 119 PAY  77 

    0xdd237b07,// 120 PAY  78 

    0xcc9e318d,// 121 PAY  79 

    0xd2e00c73,// 122 PAY  80 

    0x6d7d18ba,// 123 PAY  81 

    0x78ef0c89,// 124 PAY  82 

    0xe6a93253,// 125 PAY  83 

    0x742dc0d7,// 126 PAY  84 

    0x163e9cd9,// 127 PAY  85 

    0x85138daa,// 128 PAY  86 

    0x11c5a6c9,// 129 PAY  87 

    0x1ff947ba,// 130 PAY  88 

    0xe2cb008f,// 131 PAY  89 

    0x9ac3cbd3,// 132 PAY  90 

    0xcf96ff4e,// 133 PAY  91 

    0x5cde7d9e,// 134 PAY  92 

    0xa041242f,// 135 PAY  93 

    0xce91deb6,// 136 PAY  94 

    0xf7a075df,// 137 PAY  95 

    0x8bfc4dc5,// 138 PAY  96 

    0x09743f8b,// 139 PAY  97 

    0x9ca1f7af,// 140 PAY  98 

    0x07c95f32,// 141 PAY  99 

    0x941a742c,// 142 PAY 100 

    0x52f2c505,// 143 PAY 101 

    0x8c717513,// 144 PAY 102 

    0x7d114fd5,// 145 PAY 103 

    0x04193995,// 146 PAY 104 

    0x1bb58c9c,// 147 PAY 105 

    0xcfbeb79e,// 148 PAY 106 

    0xa3a777c7,// 149 PAY 107 

    0x37d1d3c5,// 150 PAY 108 

    0xf5ac4b3a,// 151 PAY 109 

    0x7fc9549e,// 152 PAY 110 

    0xc0028a41,// 153 PAY 111 

    0x318caebd,// 154 PAY 112 

    0xf33194de,// 155 PAY 113 

    0xf8070721,// 156 PAY 114 

    0xba9e9fb9,// 157 PAY 115 

    0x340e1c88,// 158 PAY 116 

    0xeefb0350,// 159 PAY 117 

    0x6de9555d,// 160 PAY 118 

    0x99dff289,// 161 PAY 119 

    0x5a65e188,// 162 PAY 120 

    0x81624a9d,// 163 PAY 121 

    0xd23d4dd0,// 164 PAY 122 

    0x7f27a065,// 165 PAY 123 

    0x3eb63a8f,// 166 PAY 124 

    0x5e47e6ff,// 167 PAY 125 

    0x8b6575ae,// 168 PAY 126 

    0x439428a8,// 169 PAY 127 

    0xdc3f413c,// 170 PAY 128 

    0xb02aa103,// 171 PAY 129 

    0xa87d40ea,// 172 PAY 130 

    0x7f665465,// 173 PAY 131 

    0xe4922c2c,// 174 PAY 132 

    0x009cdd3a,// 175 PAY 133 

    0x3c6d14bd,// 176 PAY 134 

    0x49bf5e78,// 177 PAY 135 

    0xcc53e25f,// 178 PAY 136 

    0xe4d9c1cf,// 179 PAY 137 

    0xef256d9f,// 180 PAY 138 

    0x981af0b0,// 181 PAY 139 

    0xc39104be,// 182 PAY 140 

    0xa3c705db,// 183 PAY 141 

    0x4639a7d1,// 184 PAY 142 

    0x8ea8355f,// 185 PAY 143 

    0x642f54bc,// 186 PAY 144 

    0x070c33ab,// 187 PAY 145 

    0xeac31928,// 188 PAY 146 

    0x742c1f25,// 189 PAY 147 

    0x0075466a,// 190 PAY 148 

    0xef8421cc,// 191 PAY 149 

    0x5837074b,// 192 PAY 150 

    0x8fd347a6,// 193 PAY 151 

    0xf847658e,// 194 PAY 152 

    0x24ff00b7,// 195 PAY 153 

    0x3a024f73,// 196 PAY 154 

    0x39dac282,// 197 PAY 155 

    0x454fb5b1,// 198 PAY 156 

    0xd5a7a97b,// 199 PAY 157 

    0xdb488102,// 200 PAY 158 

    0x2b257695,// 201 PAY 159 

    0x094dbb3f,// 202 PAY 160 

    0x111111de,// 203 PAY 161 

    0xb69bb39f,// 204 PAY 162 

    0x2c200f0b,// 205 PAY 163 

    0xc34b42e1,// 206 PAY 164 

    0xdb707342,// 207 PAY 165 

    0x202fe9e2,// 208 PAY 166 

    0xe6239ba8,// 209 PAY 167 

    0x48980e12,// 210 PAY 168 

    0xdff5b057,// 211 PAY 169 

    0xac345ced,// 212 PAY 170 

    0xd0c5d626,// 213 PAY 171 

    0xa9abb0ec,// 214 PAY 172 

    0x7aaffd01,// 215 PAY 173 

    0x78ff7fed,// 216 PAY 174 

    0x9abe8881,// 217 PAY 175 

    0xf4e2125d,// 218 PAY 176 

    0xd891f4de,// 219 PAY 177 

    0xd56a8174,// 220 PAY 178 

    0x0df4bb4d,// 221 PAY 179 

    0xb4d6a385,// 222 PAY 180 

    0xfed43e67,// 223 PAY 181 

    0x58587096,// 224 PAY 182 

    0x4f82db3f,// 225 PAY 183 

    0xb801c09c,// 226 PAY 184 

    0xc0b9b0aa,// 227 PAY 185 

    0xfa822306,// 228 PAY 186 

    0xa08906e2,// 229 PAY 187 

    0x8c8325df,// 230 PAY 188 

    0x08eeb756,// 231 PAY 189 

    0x7483e803,// 232 PAY 190 

    0x0736acef,// 233 PAY 191 

    0xcc2135bb,// 234 PAY 192 

    0x7d3f31ff,// 235 PAY 193 

    0xb37f9211,// 236 PAY 194 

    0xf1c88eeb,// 237 PAY 195 

    0xe800f012,// 238 PAY 196 

    0xb291de34,// 239 PAY 197 

    0x686734d7,// 240 PAY 198 

    0x83b8cc25,// 241 PAY 199 

    0x98f95149,// 242 PAY 200 

    0x2d775dee,// 243 PAY 201 

    0x3cde4ba5,// 244 PAY 202 

    0x9959d9fe,// 245 PAY 203 

    0xc1b711e6,// 246 PAY 204 

    0x2e02d654,// 247 PAY 205 

    0x01be395d,// 248 PAY 206 

    0xebbbf3c2,// 249 PAY 207 

    0x8506a3f5,// 250 PAY 208 

    0x3cfdd87e,// 251 PAY 209 

    0x510891a1,// 252 PAY 210 

    0x04d29623,// 253 PAY 211 

    0x97ec115f,// 254 PAY 212 

    0xd3649ae5,// 255 PAY 213 

    0x4fb7a429,// 256 PAY 214 

    0x28f4d97a,// 257 PAY 215 

    0x09a43eb5,// 258 PAY 216 

    0xac609d6c,// 259 PAY 217 

    0x31e37f16,// 260 PAY 218 

    0x1f86829d,// 261 PAY 219 

    0x0cc21463,// 262 PAY 220 

    0xe50d48a5,// 263 PAY 221 

    0x2503d36e,// 264 PAY 222 

    0x313d7d5b,// 265 PAY 223 

    0x485e1ae1,// 266 PAY 224 

    0xf560ab64,// 267 PAY 225 

    0xcedd1ca2,// 268 PAY 226 

    0x2df9702a,// 269 PAY 227 

    0x90c8f06d,// 270 PAY 228 

    0xc312828d,// 271 PAY 229 

    0x1597ec15,// 272 PAY 230 

    0x212013ba,// 273 PAY 231 

    0x4eb2dea2,// 274 PAY 232 

    0x707674e0,// 275 PAY 233 

    0xce3b5cf1,// 276 PAY 234 

    0x09400d9c,// 277 PAY 235 

    0xf96d329d,// 278 PAY 236 

    0xbd1dc68b,// 279 PAY 237 

    0x692d9f99,// 280 PAY 238 

    0x6da97b0e,// 281 PAY 239 

    0xfda48aca,// 282 PAY 240 

    0xe8a059a2,// 283 PAY 241 

    0x7f3d9221,// 284 PAY 242 

    0x92016f3d,// 285 PAY 243 

    0x20ef65a9,// 286 PAY 244 

    0xe7faf5fc,// 287 PAY 245 

    0x617cb335,// 288 PAY 246 

    0x0b9baa6b,// 289 PAY 247 

    0x78107619,// 290 PAY 248 

    0x27911ee8,// 291 PAY 249 

    0x51f8f823,// 292 PAY 250 

    0xa98e5aee,// 293 PAY 251 

    0x06121f9d,// 294 PAY 252 

    0x45e01e5c,// 295 PAY 253 

    0x3a7cac98,// 296 PAY 254 

    0x24cc67c8,// 297 PAY 255 

    0x7c53579d,// 298 PAY 256 

    0xb729f9a7,// 299 PAY 257 

    0xc7650f23,// 300 PAY 258 

    0x64d5a972,// 301 PAY 259 

    0xad3e53c6,// 302 PAY 260 

    0x6184caea,// 303 PAY 261 

    0x6ae7912b,// 304 PAY 262 

    0x88423ceb,// 305 PAY 263 

    0x969def02,// 306 PAY 264 

    0x810c71bd,// 307 PAY 265 

    0xfd7e6d8b,// 308 PAY 266 

    0x6e33e05e,// 309 PAY 267 

    0xd2a5827a,// 310 PAY 268 

    0xb8943cb7,// 311 PAY 269 

    0xd623c823,// 312 PAY 270 

    0x81f7aeaa,// 313 PAY 271 

    0x006fcb2a,// 314 PAY 272 

    0xca73b8d1,// 315 PAY 273 

    0x45258ad8,// 316 PAY 274 

    0x5d0242c4,// 317 PAY 275 

    0xd9180b63,// 318 PAY 276 

    0xe2ac5c9f,// 319 PAY 277 

    0x74f83b9a,// 320 PAY 278 

    0xcbd52057,// 321 PAY 279 

    0x77cb2dfc,// 322 PAY 280 

    0x0a1dabde,// 323 PAY 281 

    0x0330328a,// 324 PAY 282 

    0xb928330d,// 325 PAY 283 

    0x048f83f9,// 326 PAY 284 

    0xa90fc135,// 327 PAY 285 

    0x01139ee0,// 328 PAY 286 

    0x0463bede,// 329 PAY 287 

    0x3308d0a2,// 330 PAY 288 

    0x00cb7bb7,// 331 PAY 289 

    0xc2c1d325,// 332 PAY 290 

    0x70a56cdf,// 333 PAY 291 

    0x35a26485,// 334 PAY 292 

    0x3ed70dd2,// 335 PAY 293 

    0xa8830d11,// 336 PAY 294 

    0x60fc214c,// 337 PAY 295 

    0xe74a7ac2,// 338 PAY 296 

    0xba26baff,// 339 PAY 297 

    0x9629dcb9,// 340 PAY 298 

    0xeb943f2b,// 341 PAY 299 

    0x719f3e71,// 342 PAY 300 

    0x063df3fe,// 343 PAY 301 

    0xdc6920ad,// 344 PAY 302 

    0xbd096e5d,// 345 PAY 303 

    0x1837bda2,// 346 PAY 304 

    0x4d5c0771,// 347 PAY 305 

    0x450c0c15,// 348 PAY 306 

    0xad50db61,// 349 PAY 307 

    0xe30b1739,// 350 PAY 308 

    0x2aae2ab0,// 351 PAY 309 

    0x080cd3c0,// 352 PAY 310 

    0x50ccd98c,// 353 PAY 311 

    0xf59bcfc9,// 354 PAY 312 

    0xa6a29821,// 355 PAY 313 

    0xf72e28e3,// 356 PAY 314 

    0x12411e9b,// 357 PAY 315 

    0x67f63079,// 358 PAY 316 

    0x6ff2ee0c,// 359 PAY 317 

    0x338a9c54,// 360 PAY 318 

    0x2b9675c2,// 361 PAY 319 

    0xf449cf15,// 362 PAY 320 

    0x0b61d374,// 363 PAY 321 

    0x4b9cd0df,// 364 PAY 322 

    0x64042c24,// 365 PAY 323 

    0xd5be6c18,// 366 PAY 324 

    0x67069072,// 367 PAY 325 

    0xcdb8902a,// 368 PAY 326 

    0x7a9a32de,// 369 PAY 327 

    0x6dc0204d,// 370 PAY 328 

    0x2cb331a6,// 371 PAY 329 

    0xbeeb437e,// 372 PAY 330 

    0x39742dc0,// 373 PAY 331 

    0xaf51e654,// 374 PAY 332 

    0xdbffe4e1,// 375 PAY 333 

    0x85d49d20,// 376 PAY 334 

    0x3b7be657,// 377 PAY 335 

    0xc800a305,// 378 PAY 336 

    0x5343717f,// 379 PAY 337 

    0xbdebf321,// 380 PAY 338 

    0x761c3464,// 381 PAY 339 

    0x0b2b9626,// 382 PAY 340 

    0x3ffa9ddd,// 383 PAY 341 

    0x91ca9822,// 384 PAY 342 

    0x762e0cb6,// 385 PAY 343 

    0x965bfdc3,// 386 PAY 344 

    0x4d63d4a5,// 387 PAY 345 

    0x0227d28d,// 388 PAY 346 

    0x91f0ce97,// 389 PAY 347 

    0x58edf9a9,// 390 PAY 348 

/// STA is 1 words. 

/// STA num_pkts       : 178 

/// STA pkt_idx        : 254 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x32 

    0x03f932b2 // 391 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc !incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt37_tmpl[] = {
    0xa8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x0b 

/// ECH pdu_tag        : 0x00 

    0x000b0000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x808128cd,// 4 SCX   2 

    0x00004100,// 5 SCX   3 

    0xe66fc8c8,// 6 SCX   4 

    0xcaf8e88b,// 7 SCX   5 

    0x7fa6cc30,// 8 SCX   6 

    0xa951ec99,// 9 SCX   7 

    0x55f2d818,// 10 SCX   8 

    0xd4826d8d,// 11 SCX   9 

    0x28e554c1,// 12 SCX  10 

    0x922e3602,// 13 SCX  11 

    0x1703b2d3,// 14 SCX  12 

    0x573534c0,// 15 SCX  13 

    0x8b65f9d8,// 16 SCX  14 

    0xc452f034,// 17 SCX  15 

    0x73fe2ee3,// 18 SCX  16 

    0xf8714a24,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 86 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 60 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 60 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 20 

/// BFD (ofst+len)cry  : 52 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 64 

    0x0000003c,// 20 BFD   1 

    0x00140020,// 21 BFD   2 

    0x00400000,// 22 BFD   3 

/// BDA is 23 words. 

/// BDA size     is 86 (0x56) 

/// BDA id       is 0x1608 

    0x00561608,// 23 BDA   1 

/// PAY Generic Data size   : 86 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x9b54f10e,// 24 PAY   1 

    0xb311258a,// 25 PAY   2 

    0x24f401ac,// 26 PAY   3 

    0xa27a9186,// 27 PAY   4 

    0x4d1aba83,// 28 PAY   5 

    0x5e789250,// 29 PAY   6 

    0x82fd737f,// 30 PAY   7 

    0x37326e23,// 31 PAY   8 

    0x61e0d43f,// 32 PAY   9 

    0x97261c48,// 33 PAY  10 

    0xe57718dd,// 34 PAY  11 

    0xfacb3de6,// 35 PAY  12 

    0x004eaffc,// 36 PAY  13 

    0x17f748be,// 37 PAY  14 

    0xb3cd5eea,// 38 PAY  15 

    0x60333655,// 39 PAY  16 

    0xdf522200,// 40 PAY  17 

    0xd40a0eea,// 41 PAY  18 

    0x7dc67fa3,// 42 PAY  19 

    0x949dde55,// 43 PAY  20 

    0x1d52739c,// 44 PAY  21 

    0x5ca40000,// 45 PAY  22 

/// STA is 1 words. 

/// STA num_pkts       : 164 

/// STA pkt_idx        : 88 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xbe 

    0x0161bea4 // 46 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt38_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x8084280c,// 4 SCX   2 

    0x000024c4,// 5 SCX   3 

    0xbbc07892,// 6 SCX   4 

    0x9dbd9995,// 7 SCX   5 

    0x2ed286ca,// 8 SCX   6 

    0xa68a93ea,// 9 SCX   7 

    0x350037b3,// 10 SCX   8 

    0xc000b8ed,// 11 SCX   9 

    0x434c09d6,// 12 SCX  10 

    0x1b3818ec,// 13 SCX  11 

    0x53adde40,// 14 SCX  12 

    0xae60f251,// 15 SCX  13 

    0x787b16c6,// 16 SCX  14 

    0xb1219c6b,// 17 SCX  15 

    0x7947b9d9,// 18 SCX  16 

    0x15f42467,// 19 SCX  17 

    0x00df5e97,// 20 SCX  18 

    0x31a46e1b,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1031 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 693 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 693 

/// BFD lencrypto      : 112 

/// BFD ofstcrypto     : 336 

/// BFD (ofst+len)cry  : 448 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 860 

    0x000002b5,// 22 BFD   1 

    0x01500070,// 23 BFD   2 

    0x035c0010,// 24 BFD   3 

/// MFM is 4 words. 

/// MFM vldnibs        : 18 

    0x1800f2fc,// 25 MFM   1 

    0x8c7ec39e,// 26 MFM   2 

    0x76797e77,// 27 MFM   3 

    0xc09f0000,// 28 MFM   4 

/// BDA is 259 words. 

/// BDA size     is 1031 (0x407) 

/// BDA id       is 0x1528 

    0x04071528,// 29 BDA   1 

/// PAY Generic Data size   : 1031 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0xf26ef274,// 30 PAY   1 

    0xffa89643,// 31 PAY   2 

    0x31d89a7d,// 32 PAY   3 

    0xbc09a0c2,// 33 PAY   4 

    0x8fa98142,// 34 PAY   5 

    0xe8f73d43,// 35 PAY   6 

    0xcb69b4c0,// 36 PAY   7 

    0xb7421b2e,// 37 PAY   8 

    0xb5fe5956,// 38 PAY   9 

    0x5907170a,// 39 PAY  10 

    0x7ef424e0,// 40 PAY  11 

    0x1dfc8d13,// 41 PAY  12 

    0xd4e9f7c7,// 42 PAY  13 

    0x394764ed,// 43 PAY  14 

    0x7c8f6a09,// 44 PAY  15 

    0x96a4cd11,// 45 PAY  16 

    0xf3b0f02a,// 46 PAY  17 

    0x6720ed6f,// 47 PAY  18 

    0x3ce026be,// 48 PAY  19 

    0xaca972aa,// 49 PAY  20 

    0x3bce0200,// 50 PAY  21 

    0xc54c9cd7,// 51 PAY  22 

    0xb39983fe,// 52 PAY  23 

    0xafb6f4b7,// 53 PAY  24 

    0x224df8b2,// 54 PAY  25 

    0xa016041a,// 55 PAY  26 

    0xbae8eb8e,// 56 PAY  27 

    0x6f4512c5,// 57 PAY  28 

    0x76693b02,// 58 PAY  29 

    0x8468a200,// 59 PAY  30 

    0x733a41e6,// 60 PAY  31 

    0x12a0b459,// 61 PAY  32 

    0x2bfa143f,// 62 PAY  33 

    0x312c6ab0,// 63 PAY  34 

    0x81942601,// 64 PAY  35 

    0x551127d8,// 65 PAY  36 

    0x8252b2a8,// 66 PAY  37 

    0x9c2afdf3,// 67 PAY  38 

    0x27ae9e7e,// 68 PAY  39 

    0x65454d4c,// 69 PAY  40 

    0x46849e18,// 70 PAY  41 

    0xa4619881,// 71 PAY  42 

    0xb771b759,// 72 PAY  43 

    0x16668b94,// 73 PAY  44 

    0x79421149,// 74 PAY  45 

    0x4af2f6dd,// 75 PAY  46 

    0xed6dc68d,// 76 PAY  47 

    0xdaad4a8e,// 77 PAY  48 

    0xa7155030,// 78 PAY  49 

    0x1331bd54,// 79 PAY  50 

    0x31392f80,// 80 PAY  51 

    0xb2e19aac,// 81 PAY  52 

    0xe18deef5,// 82 PAY  53 

    0x5d9475d1,// 83 PAY  54 

    0xe7b5c7d0,// 84 PAY  55 

    0xd7a0f0c5,// 85 PAY  56 

    0x67278727,// 86 PAY  57 

    0xaebde2f2,// 87 PAY  58 

    0x24ee943e,// 88 PAY  59 

    0xe8b04842,// 89 PAY  60 

    0x6518525e,// 90 PAY  61 

    0xdd75bb16,// 91 PAY  62 

    0x22b050fb,// 92 PAY  63 

    0x4563c637,// 93 PAY  64 

    0x0eaa38db,// 94 PAY  65 

    0x7c2fc9a5,// 95 PAY  66 

    0x479248b2,// 96 PAY  67 

    0x44ebd4fb,// 97 PAY  68 

    0x9f183e45,// 98 PAY  69 

    0xbb07d7bb,// 99 PAY  70 

    0x457979b7,// 100 PAY  71 

    0x5839fd17,// 101 PAY  72 

    0x9a732749,// 102 PAY  73 

    0x8d22a911,// 103 PAY  74 

    0xafc31664,// 104 PAY  75 

    0xf5fe3f73,// 105 PAY  76 

    0x57e44ec2,// 106 PAY  77 

    0x27d28d87,// 107 PAY  78 

    0x9d98f73d,// 108 PAY  79 

    0x029a425c,// 109 PAY  80 

    0x04eaff92,// 110 PAY  81 

    0x80271b41,// 111 PAY  82 

    0xcfa26788,// 112 PAY  83 

    0x380466c2,// 113 PAY  84 

    0xdb3aa1b4,// 114 PAY  85 

    0xa83f113f,// 115 PAY  86 

    0xd7005442,// 116 PAY  87 

    0xd483013d,// 117 PAY  88 

    0xaf028e66,// 118 PAY  89 

    0xd213921c,// 119 PAY  90 

    0x6168963a,// 120 PAY  91 

    0xae198be5,// 121 PAY  92 

    0x07de44eb,// 122 PAY  93 

    0x8288bd4e,// 123 PAY  94 

    0xf0dc3cee,// 124 PAY  95 

    0xd24fd0fa,// 125 PAY  96 

    0x830b8bf2,// 126 PAY  97 

    0xd8edf74c,// 127 PAY  98 

    0x2f0bb358,// 128 PAY  99 

    0x78339f6c,// 129 PAY 100 

    0x33d02c2d,// 130 PAY 101 

    0x5cf5ea6b,// 131 PAY 102 

    0xc1620eba,// 132 PAY 103 

    0xe6e2dd8f,// 133 PAY 104 

    0xafde5611,// 134 PAY 105 

    0xdf0575ea,// 135 PAY 106 

    0xcb77a586,// 136 PAY 107 

    0x0e01f4d7,// 137 PAY 108 

    0xc609ca0c,// 138 PAY 109 

    0x29ba1b0c,// 139 PAY 110 

    0x7ce03ac7,// 140 PAY 111 

    0x9a42f0b9,// 141 PAY 112 

    0x780c7f51,// 142 PAY 113 

    0xe1f4729b,// 143 PAY 114 

    0x2633d187,// 144 PAY 115 

    0xb5d4f57a,// 145 PAY 116 

    0x189d745d,// 146 PAY 117 

    0x27403ded,// 147 PAY 118 

    0x46234feb,// 148 PAY 119 

    0x9fcb4ad9,// 149 PAY 120 

    0x3ae09a15,// 150 PAY 121 

    0x9b02c89c,// 151 PAY 122 

    0xf3f7b9c6,// 152 PAY 123 

    0xfef43b61,// 153 PAY 124 

    0x3f3f5b77,// 154 PAY 125 

    0x2a549129,// 155 PAY 126 

    0x78751911,// 156 PAY 127 

    0xdf8459c4,// 157 PAY 128 

    0x42d45e47,// 158 PAY 129 

    0xd6490753,// 159 PAY 130 

    0x84a81923,// 160 PAY 131 

    0x4baaf836,// 161 PAY 132 

    0x13f292f3,// 162 PAY 133 

    0x451e7f79,// 163 PAY 134 

    0xd2099929,// 164 PAY 135 

    0x350e9266,// 165 PAY 136 

    0x537e1bc3,// 166 PAY 137 

    0x32378e1d,// 167 PAY 138 

    0x01dac972,// 168 PAY 139 

    0xce7e449d,// 169 PAY 140 

    0x4d3dee7d,// 170 PAY 141 

    0x3023673e,// 171 PAY 142 

    0x5e6674b0,// 172 PAY 143 

    0x1187d712,// 173 PAY 144 

    0x8cf07e65,// 174 PAY 145 

    0x2ee64a83,// 175 PAY 146 

    0xa48ed5fa,// 176 PAY 147 

    0x584cf17c,// 177 PAY 148 

    0x3e5a436f,// 178 PAY 149 

    0x03beadd2,// 179 PAY 150 

    0x4fb74703,// 180 PAY 151 

    0xcc089168,// 181 PAY 152 

    0x4bedf1bb,// 182 PAY 153 

    0x333a7eac,// 183 PAY 154 

    0x0f63ff0e,// 184 PAY 155 

    0x0abe9eec,// 185 PAY 156 

    0x80af7b8d,// 186 PAY 157 

    0x9555257e,// 187 PAY 158 

    0x24cc89af,// 188 PAY 159 

    0xb42c102d,// 189 PAY 160 

    0xde2a4114,// 190 PAY 161 

    0xe3324b57,// 191 PAY 162 

    0x66242fb7,// 192 PAY 163 

    0xc0506af2,// 193 PAY 164 

    0x8db95b4f,// 194 PAY 165 

    0x0c3b0b81,// 195 PAY 166 

    0x718838d0,// 196 PAY 167 

    0xd8df5735,// 197 PAY 168 

    0x60b6cb42,// 198 PAY 169 

    0x2060a0e8,// 199 PAY 170 

    0xbcc28a99,// 200 PAY 171 

    0xf6ad33d9,// 201 PAY 172 

    0x97d9c481,// 202 PAY 173 

    0x042c6698,// 203 PAY 174 

    0xe8509602,// 204 PAY 175 

    0x06079396,// 205 PAY 176 

    0xa620e790,// 206 PAY 177 

    0xde9b5637,// 207 PAY 178 

    0xb6325983,// 208 PAY 179 

    0x082c1eb6,// 209 PAY 180 

    0x2e30e5f1,// 210 PAY 181 

    0xc179f7af,// 211 PAY 182 

    0x0a39ae18,// 212 PAY 183 

    0x1fb87e59,// 213 PAY 184 

    0xd28387f1,// 214 PAY 185 

    0xce621a74,// 215 PAY 186 

    0xcd16355f,// 216 PAY 187 

    0x9cf5d1be,// 217 PAY 188 

    0x7b8f3320,// 218 PAY 189 

    0xfe8ec272,// 219 PAY 190 

    0x45d9d8aa,// 220 PAY 191 

    0x0ebaa0d0,// 221 PAY 192 

    0xd195ee1f,// 222 PAY 193 

    0xa3bc7a8a,// 223 PAY 194 

    0xa1db15df,// 224 PAY 195 

    0x5880fac9,// 225 PAY 196 

    0x94dc6ea9,// 226 PAY 197 

    0x038f8cee,// 227 PAY 198 

    0xab39071a,// 228 PAY 199 

    0xa154c690,// 229 PAY 200 

    0x75f366f2,// 230 PAY 201 

    0xe3c84ef5,// 231 PAY 202 

    0x1fa50d71,// 232 PAY 203 

    0x8378cfbe,// 233 PAY 204 

    0xc60bf5a3,// 234 PAY 205 

    0x5b0c17fa,// 235 PAY 206 

    0x8187541b,// 236 PAY 207 

    0x5b9345e8,// 237 PAY 208 

    0x8be981c7,// 238 PAY 209 

    0x7d1a7134,// 239 PAY 210 

    0x4bb69cd4,// 240 PAY 211 

    0x5da43805,// 241 PAY 212 

    0x038b052e,// 242 PAY 213 

    0x8f84cf4e,// 243 PAY 214 

    0x0f5307f4,// 244 PAY 215 

    0x14e0059d,// 245 PAY 216 

    0x279b8cb0,// 246 PAY 217 

    0xcaa062b2,// 247 PAY 218 

    0x0079e80d,// 248 PAY 219 

    0x90a676c1,// 249 PAY 220 

    0x29c2bcee,// 250 PAY 221 

    0xe3bb94b7,// 251 PAY 222 

    0x028755d0,// 252 PAY 223 

    0x970faebc,// 253 PAY 224 

    0xd8ce8418,// 254 PAY 225 

    0xd6dd8625,// 255 PAY 226 

    0xef5a31c5,// 256 PAY 227 

    0xcf17ed95,// 257 PAY 228 

    0x1a08704d,// 258 PAY 229 

    0xa5819576,// 259 PAY 230 

    0xc1a65565,// 260 PAY 231 

    0xd2e5d32d,// 261 PAY 232 

    0x9f6b808e,// 262 PAY 233 

    0x8dfaeb8e,// 263 PAY 234 

    0x28b5a601,// 264 PAY 235 

    0x1388cbef,// 265 PAY 236 

    0x1ed77fbf,// 266 PAY 237 

    0xbcdf0dae,// 267 PAY 238 

    0x2ba105d2,// 268 PAY 239 

    0xbb13183d,// 269 PAY 240 

    0x90400422,// 270 PAY 241 

    0x9b59667c,// 271 PAY 242 

    0x01789759,// 272 PAY 243 

    0x0318bd1d,// 273 PAY 244 

    0x1ce7fcec,// 274 PAY 245 

    0x4db19c9a,// 275 PAY 246 

    0xc63c42dd,// 276 PAY 247 

    0xca507922,// 277 PAY 248 

    0x2d1244a9,// 278 PAY 249 

    0xb47056be,// 279 PAY 250 

    0x7ccad4ad,// 280 PAY 251 

    0xa77f1edb,// 281 PAY 252 

    0xb7ece2ab,// 282 PAY 253 

    0x521dd754,// 283 PAY 254 

    0x61f40b6f,// 284 PAY 255 

    0x8d96cf0c,// 285 PAY 256 

    0x52d6b1b4,// 286 PAY 257 

    0x2baaac00,// 287 PAY 258 

/// STA is 1 words. 

/// STA num_pkts       : 229 

/// STA pkt_idx        : 76 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x4f 

    0x01314fe5 // 288 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt39_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x808228fb,// 4 SCX   2 

    0x00000200,// 5 SCX   3 

    0x22980b94,// 6 SCX   4 

    0x1e72eadb,// 7 SCX   5 

    0xec6c6536,// 8 SCX   6 

    0x749ab9b9,// 9 SCX   7 

    0xfbeeefff,// 10 SCX   8 

    0x71b8f0c6,// 11 SCX   9 

    0x5d61c124,// 12 SCX  10 

    0xfbf23f22,// 13 SCX  11 

    0xd1d61987,// 14 SCX  12 

    0x25128ef4,// 15 SCX  13 

    0x05dfc472,// 16 SCX  14 

    0xf5de98e2,// 17 SCX  15 

    0xb79bf513,// 18 SCX  16 

    0x00c7ea2c,// 19 SCX  17 

    0x436f657e,// 20 SCX  18 

    0xdd4946de,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1422 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 274 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 274 

/// BFD lencrypto      : 64 

/// BFD ofstcrypto     : 40 

/// BFD (ofst+len)cry  : 104 

/// BFD ofstiv         : 4 

/// BFD ofsticv        : 564 

    0x00000112,// 22 BFD   1 

    0x00280040,// 23 BFD   2 

    0x02340004,// 24 BFD   3 

/// MFM is 4 words. 

/// MFM vldnibs        : 15 

    0x15008b71,// 25 MFM   1 

    0x12e03763,// 26 MFM   2 

    0x40d10753,// 27 MFM   3 

    0xc0000000,// 28 MFM   4 

/// BDA is 357 words. 

/// BDA size     is 1422 (0x58e) 

/// BDA id       is 0xc25c 

    0x058ec25c,// 29 BDA   1 

/// PAY Generic Data size   : 1422 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xbe952cd6,// 30 PAY   1 

    0x36578f99,// 31 PAY   2 

    0x5aa004e4,// 32 PAY   3 

    0x2d9e616e,// 33 PAY   4 

    0x8c451afe,// 34 PAY   5 

    0xba4a2b44,// 35 PAY   6 

    0xbf29008e,// 36 PAY   7 

    0x31345e39,// 37 PAY   8 

    0x63413b54,// 38 PAY   9 

    0xf0907aab,// 39 PAY  10 

    0x3246647c,// 40 PAY  11 

    0xf8dc26d8,// 41 PAY  12 

    0x4d0f96d4,// 42 PAY  13 

    0x35dd72dc,// 43 PAY  14 

    0xf5f786cf,// 44 PAY  15 

    0xa36c439a,// 45 PAY  16 

    0x190e6613,// 46 PAY  17 

    0xdbe7d16f,// 47 PAY  18 

    0x348e02aa,// 48 PAY  19 

    0xf4ce2610,// 49 PAY  20 

    0x535cf38d,// 50 PAY  21 

    0x3461d224,// 51 PAY  22 

    0x4318635f,// 52 PAY  23 

    0x610249b3,// 53 PAY  24 

    0x0512423b,// 54 PAY  25 

    0xae569dd3,// 55 PAY  26 

    0x49a5cd72,// 56 PAY  27 

    0x3b2094ef,// 57 PAY  28 

    0xf2abdf65,// 58 PAY  29 

    0xc04c8c59,// 59 PAY  30 

    0x5e6b90f9,// 60 PAY  31 

    0xedab8c0b,// 61 PAY  32 

    0xf304413c,// 62 PAY  33 

    0xb3ea35cf,// 63 PAY  34 

    0x4f59ed5a,// 64 PAY  35 

    0x9a0b754e,// 65 PAY  36 

    0x3a5fe650,// 66 PAY  37 

    0xa8309d17,// 67 PAY  38 

    0x7b23abc2,// 68 PAY  39 

    0x5c3456fe,// 69 PAY  40 

    0x445a1dec,// 70 PAY  41 

    0xf49b3946,// 71 PAY  42 

    0xf7db3bf3,// 72 PAY  43 

    0x216f6dfc,// 73 PAY  44 

    0xa6a22837,// 74 PAY  45 

    0xeb7a0c87,// 75 PAY  46 

    0xbbba57b7,// 76 PAY  47 

    0xef432e9d,// 77 PAY  48 

    0x2fbd2842,// 78 PAY  49 

    0x571dee0e,// 79 PAY  50 

    0x3fa8a6d0,// 80 PAY  51 

    0x56e47f2b,// 81 PAY  52 

    0x4d6f53f4,// 82 PAY  53 

    0xf9a6007c,// 83 PAY  54 

    0x9a71b0f0,// 84 PAY  55 

    0x5f5c9d98,// 85 PAY  56 

    0x6df09d96,// 86 PAY  57 

    0x12070a84,// 87 PAY  58 

    0x6d9e033d,// 88 PAY  59 

    0x3189d2d6,// 89 PAY  60 

    0x9113c646,// 90 PAY  61 

    0xe96321cd,// 91 PAY  62 

    0x77c506ea,// 92 PAY  63 

    0xce73bbc2,// 93 PAY  64 

    0x3db1a82d,// 94 PAY  65 

    0x19c117d2,// 95 PAY  66 

    0xfbd9cf7d,// 96 PAY  67 

    0x002c605e,// 97 PAY  68 

    0xf12e928f,// 98 PAY  69 

    0x724ecbd9,// 99 PAY  70 

    0xcc35c398,// 100 PAY  71 

    0xf028ed41,// 101 PAY  72 

    0x6b4b007b,// 102 PAY  73 

    0x657cd24e,// 103 PAY  74 

    0xb42f5542,// 104 PAY  75 

    0xfd467ff3,// 105 PAY  76 

    0x54fb0b6f,// 106 PAY  77 

    0x67871b50,// 107 PAY  78 

    0xfd03caf4,// 108 PAY  79 

    0xc545fb21,// 109 PAY  80 

    0xf5ba41b8,// 110 PAY  81 

    0x9126625c,// 111 PAY  82 

    0x43b5987d,// 112 PAY  83 

    0xb326d9bd,// 113 PAY  84 

    0x5d831dbe,// 114 PAY  85 

    0x47e47596,// 115 PAY  86 

    0x51b6a113,// 116 PAY  87 

    0xd56bcbb8,// 117 PAY  88 

    0x3c5db9c4,// 118 PAY  89 

    0xba4013bd,// 119 PAY  90 

    0xf91fc504,// 120 PAY  91 

    0xe975aea7,// 121 PAY  92 

    0x15f34258,// 122 PAY  93 

    0xfb5c59b4,// 123 PAY  94 

    0xa94ef4b5,// 124 PAY  95 

    0x7808dbb9,// 125 PAY  96 

    0xf0954f7f,// 126 PAY  97 

    0x0b1982a5,// 127 PAY  98 

    0x1e715b86,// 128 PAY  99 

    0x3b5a912a,// 129 PAY 100 

    0x36e648b8,// 130 PAY 101 

    0xf3b5aed7,// 131 PAY 102 

    0x12b21388,// 132 PAY 103 

    0x97dbada6,// 133 PAY 104 

    0x704e48c1,// 134 PAY 105 

    0x80bca4e4,// 135 PAY 106 

    0x2515e63b,// 136 PAY 107 

    0x35331d02,// 137 PAY 108 

    0xddc18d72,// 138 PAY 109 

    0x421405ae,// 139 PAY 110 

    0xeae95f10,// 140 PAY 111 

    0x6a572a1d,// 141 PAY 112 

    0xb52d4299,// 142 PAY 113 

    0x85c3e0a1,// 143 PAY 114 

    0xd7289f9f,// 144 PAY 115 

    0xf2ba5f2e,// 145 PAY 116 

    0x6b884540,// 146 PAY 117 

    0x2fa06065,// 147 PAY 118 

    0x39fdf16d,// 148 PAY 119 

    0x371090f6,// 149 PAY 120 

    0x2ca997ef,// 150 PAY 121 

    0xbb6f811a,// 151 PAY 122 

    0xc35c89cb,// 152 PAY 123 

    0xcff5c7f8,// 153 PAY 124 

    0x551b6e01,// 154 PAY 125 

    0xa54f62a4,// 155 PAY 126 

    0xdf2dc3a4,// 156 PAY 127 

    0xec7f8912,// 157 PAY 128 

    0x8321e42f,// 158 PAY 129 

    0x54cd4dfb,// 159 PAY 130 

    0xa3329e31,// 160 PAY 131 

    0xba9861d2,// 161 PAY 132 

    0xc08dd39a,// 162 PAY 133 

    0x8633ffc1,// 163 PAY 134 

    0x5ce40775,// 164 PAY 135 

    0x1763c9ce,// 165 PAY 136 

    0xefcd67c1,// 166 PAY 137 

    0xb030f967,// 167 PAY 138 

    0x1bb72190,// 168 PAY 139 

    0x461d18d4,// 169 PAY 140 

    0x8b59e0c9,// 170 PAY 141 

    0x69a117c7,// 171 PAY 142 

    0x3a925b1a,// 172 PAY 143 

    0x69cf47bf,// 173 PAY 144 

    0xfd78a632,// 174 PAY 145 

    0x0646a990,// 175 PAY 146 

    0x227be8b9,// 176 PAY 147 

    0x85c8f7e8,// 177 PAY 148 

    0x83fd4b63,// 178 PAY 149 

    0x946c943e,// 179 PAY 150 

    0x375400f4,// 180 PAY 151 

    0x7218ca51,// 181 PAY 152 

    0x0daf7f68,// 182 PAY 153 

    0x42311bb8,// 183 PAY 154 

    0xe0fb23a3,// 184 PAY 155 

    0x3f8bb952,// 185 PAY 156 

    0x522ac678,// 186 PAY 157 

    0x286c9c0c,// 187 PAY 158 

    0x30da94c3,// 188 PAY 159 

    0x71708bbe,// 189 PAY 160 

    0xe2106c4b,// 190 PAY 161 

    0x54932165,// 191 PAY 162 

    0xcc800727,// 192 PAY 163 

    0x23917994,// 193 PAY 164 

    0x1fe5bfc5,// 194 PAY 165 

    0x4d0cfe7c,// 195 PAY 166 

    0x3b82ccba,// 196 PAY 167 

    0x01751d84,// 197 PAY 168 

    0x5f98608a,// 198 PAY 169 

    0xae209e55,// 199 PAY 170 

    0x2c50f25f,// 200 PAY 171 

    0x9fa00589,// 201 PAY 172 

    0xcb7401a9,// 202 PAY 173 

    0x259a3941,// 203 PAY 174 

    0x84ab5c28,// 204 PAY 175 

    0x0cfe8364,// 205 PAY 176 

    0x7c26fd82,// 206 PAY 177 

    0xb51a9762,// 207 PAY 178 

    0x6e9fafa2,// 208 PAY 179 

    0x05824db3,// 209 PAY 180 

    0x6377ae4d,// 210 PAY 181 

    0xc38c2684,// 211 PAY 182 

    0x1db16de1,// 212 PAY 183 

    0xf3d655e6,// 213 PAY 184 

    0x9224a0a5,// 214 PAY 185 

    0x6a69c819,// 215 PAY 186 

    0xb6616399,// 216 PAY 187 

    0xb430d010,// 217 PAY 188 

    0xeedaa74a,// 218 PAY 189 

    0x8378dbe2,// 219 PAY 190 

    0xa5077bd2,// 220 PAY 191 

    0x1d4b2ad8,// 221 PAY 192 

    0x1e38d0bc,// 222 PAY 193 

    0x12a989b9,// 223 PAY 194 

    0xa868c363,// 224 PAY 195 

    0x5bb6105b,// 225 PAY 196 

    0x7dd45913,// 226 PAY 197 

    0x4beba6fb,// 227 PAY 198 

    0xef10be67,// 228 PAY 199 

    0x92b7ce45,// 229 PAY 200 

    0x7b9c67b4,// 230 PAY 201 

    0xeb98ead9,// 231 PAY 202 

    0x3ad4980e,// 232 PAY 203 

    0xd7aa6337,// 233 PAY 204 

    0x8af3e324,// 234 PAY 205 

    0x6da7e860,// 235 PAY 206 

    0xc3bf9ced,// 236 PAY 207 

    0x8fc0411c,// 237 PAY 208 

    0xb6eea28f,// 238 PAY 209 

    0xf67d24a7,// 239 PAY 210 

    0x49f9757e,// 240 PAY 211 

    0x1ab47245,// 241 PAY 212 

    0x2f26a585,// 242 PAY 213 

    0x80144fa2,// 243 PAY 214 

    0xf8fdd6b4,// 244 PAY 215 

    0xb9e9fae9,// 245 PAY 216 

    0xf02e9240,// 246 PAY 217 

    0xebe00565,// 247 PAY 218 

    0x7fb19788,// 248 PAY 219 

    0xad682e1d,// 249 PAY 220 

    0x5e261305,// 250 PAY 221 

    0xb1292492,// 251 PAY 222 

    0x00e2b0c9,// 252 PAY 223 

    0x0a63c857,// 253 PAY 224 

    0x3ea73bea,// 254 PAY 225 

    0x80b8f39e,// 255 PAY 226 

    0x3f0770b8,// 256 PAY 227 

    0x639ebced,// 257 PAY 228 

    0x92b50758,// 258 PAY 229 

    0x6b7b984a,// 259 PAY 230 

    0x84c136dc,// 260 PAY 231 

    0x5b0d4920,// 261 PAY 232 

    0x93998b49,// 262 PAY 233 

    0x6b136c6a,// 263 PAY 234 

    0x36477074,// 264 PAY 235 

    0x14ec1498,// 265 PAY 236 

    0xf614ea09,// 266 PAY 237 

    0xdc3daebd,// 267 PAY 238 

    0xd35e2434,// 268 PAY 239 

    0xf17e3b06,// 269 PAY 240 

    0xfc1dba83,// 270 PAY 241 

    0xea8f8072,// 271 PAY 242 

    0x547452c8,// 272 PAY 243 

    0xeb1eec44,// 273 PAY 244 

    0x336a51de,// 274 PAY 245 

    0x0b6ad669,// 275 PAY 246 

    0xd18f8746,// 276 PAY 247 

    0xc3fcd0fb,// 277 PAY 248 

    0x43da8fe2,// 278 PAY 249 

    0xcb8ceb74,// 279 PAY 250 

    0xc195e234,// 280 PAY 251 

    0x0d854ac7,// 281 PAY 252 

    0x2f3ea1a8,// 282 PAY 253 

    0xd21eb773,// 283 PAY 254 

    0x03ac0a23,// 284 PAY 255 

    0x93c37668,// 285 PAY 256 

    0x44046d46,// 286 PAY 257 

    0x5ff82f37,// 287 PAY 258 

    0xab40b27d,// 288 PAY 259 

    0x6656eda8,// 289 PAY 260 

    0xb298d940,// 290 PAY 261 

    0x8b6a12c6,// 291 PAY 262 

    0xf246282f,// 292 PAY 263 

    0xc62e33a1,// 293 PAY 264 

    0x92778b13,// 294 PAY 265 

    0xebace500,// 295 PAY 266 

    0x85284a88,// 296 PAY 267 

    0xef0ac22b,// 297 PAY 268 

    0xbbafce83,// 298 PAY 269 

    0xb8cc0eb2,// 299 PAY 270 

    0xa9c31a2b,// 300 PAY 271 

    0x1427c469,// 301 PAY 272 

    0x824443f9,// 302 PAY 273 

    0x51344995,// 303 PAY 274 

    0xdb6ee713,// 304 PAY 275 

    0xf84ec248,// 305 PAY 276 

    0x0380948e,// 306 PAY 277 

    0x5775f9de,// 307 PAY 278 

    0x4f3a2dea,// 308 PAY 279 

    0xbb3574b2,// 309 PAY 280 

    0x53c34fdd,// 310 PAY 281 

    0x1fab13e2,// 311 PAY 282 

    0x10b23e32,// 312 PAY 283 

    0x55a8a1a0,// 313 PAY 284 

    0xb5889843,// 314 PAY 285 

    0x94f052ea,// 315 PAY 286 

    0xc0213afd,// 316 PAY 287 

    0x3e2632fa,// 317 PAY 288 

    0xd57328cc,// 318 PAY 289 

    0xc01b7604,// 319 PAY 290 

    0xb53b4c75,// 320 PAY 291 

    0xf5b7b4b5,// 321 PAY 292 

    0xa56f5c1c,// 322 PAY 293 

    0xa95ea995,// 323 PAY 294 

    0x44d2f9d7,// 324 PAY 295 

    0xf2d3b841,// 325 PAY 296 

    0x9a592798,// 326 PAY 297 

    0xa1c40f9c,// 327 PAY 298 

    0x03a58281,// 328 PAY 299 

    0x92841394,// 329 PAY 300 

    0xd3c29ea4,// 330 PAY 301 

    0x15a90c2f,// 331 PAY 302 

    0xbbf62694,// 332 PAY 303 

    0xec9d4a73,// 333 PAY 304 

    0x140ef036,// 334 PAY 305 

    0x3881862f,// 335 PAY 306 

    0x760b03db,// 336 PAY 307 

    0xcd6d3887,// 337 PAY 308 

    0x4249f29d,// 338 PAY 309 

    0x0e950065,// 339 PAY 310 

    0xee4efb8b,// 340 PAY 311 

    0x35957840,// 341 PAY 312 

    0xc152a633,// 342 PAY 313 

    0x92567f45,// 343 PAY 314 

    0x68d00e25,// 344 PAY 315 

    0xb3fd256b,// 345 PAY 316 

    0xf599fb70,// 346 PAY 317 

    0xfa504fe1,// 347 PAY 318 

    0x893820cd,// 348 PAY 319 

    0x9e0e9ef3,// 349 PAY 320 

    0x0fab56af,// 350 PAY 321 

    0x4ede842b,// 351 PAY 322 

    0x200f1fd5,// 352 PAY 323 

    0xc6736654,// 353 PAY 324 

    0x6dcd449d,// 354 PAY 325 

    0xc8fcfa1e,// 355 PAY 326 

    0xceaf9304,// 356 PAY 327 

    0xb60a968a,// 357 PAY 328 

    0xbe46be5c,// 358 PAY 329 

    0x587aaef7,// 359 PAY 330 

    0x3359cf41,// 360 PAY 331 

    0xb2a41ba2,// 361 PAY 332 

    0xb45ea643,// 362 PAY 333 

    0x21a8f5c1,// 363 PAY 334 

    0x5b1a06f0,// 364 PAY 335 

    0x528d15b5,// 365 PAY 336 

    0xb54bcab8,// 366 PAY 337 

    0xcb2cbf9d,// 367 PAY 338 

    0x5cacbed7,// 368 PAY 339 

    0x2e91759c,// 369 PAY 340 

    0x1b997ef5,// 370 PAY 341 

    0xf7213d8f,// 371 PAY 342 

    0x8094de13,// 372 PAY 343 

    0xb0db4a4a,// 373 PAY 344 

    0x8a6c616f,// 374 PAY 345 

    0xd00ed7d3,// 375 PAY 346 

    0x050f12ad,// 376 PAY 347 

    0x7171f225,// 377 PAY 348 

    0x4b3c660f,// 378 PAY 349 

    0x2e026450,// 379 PAY 350 

    0x8b5d9654,// 380 PAY 351 

    0x68db18d9,// 381 PAY 352 

    0x4efff9d7,// 382 PAY 353 

    0x04fe68f7,// 383 PAY 354 

    0x75b442b3,// 384 PAY 355 

    0x08660000,// 385 PAY 356 

/// STA is 1 words. 

/// STA num_pkts       : 208 

/// STA pkt_idx        : 48 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x5f 

    0x00c05fd0 // 386 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt40_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x80922891,// 4 SCX   2 

    0x00006482,// 5 SCX   3 

    0xe87b637d,// 6 SCX   4 

    0x3ce26d9f,// 7 SCX   5 

    0x07bd12f1,// 8 SCX   6 

    0x641af403,// 9 SCX   7 

    0xe9c10c4e,// 10 SCX   8 

    0x786fc2e2,// 11 SCX   9 

    0xccf6c305,// 12 SCX  10 

    0x4c510960,// 13 SCX  11 

    0x21c7dcc1,// 14 SCX  12 

    0x4e5ed2c9,// 15 SCX  13 

    0x712ca605,// 16 SCX  14 

    0xc621e1f9,// 17 SCX  15 

    0x5d79217b,// 18 SCX  16 

    0xad902ccf,// 19 SCX  17 

    0x70db4cbe,// 20 SCX  18 

    0xd8180831,// 21 SCX  19 

    0x5ae87264,// 22 SCX  20 

    0xe5e696a6,// 23 SCX  21 

    0xf9452129,// 24 SCX  22 

    0xe053d26a,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 796 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 110 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 110 

/// BFD lencrypto      : 20 

/// BFD ofstcrypto     : 84 

/// BFD (ofst+len)cry  : 104 

/// BFD ofstiv         : 56 

/// BFD ofsticv        : 456 

    0x0000006e,// 26 BFD   1 

    0x00540014,// 27 BFD   2 

    0x01c80038,// 28 BFD   3 

/// MFM is 4 words. 

/// MFM vldnibs        : 1b 

    0x1b00f706,// 29 MFM   1 

    0xe8c95303,// 30 MFM   2 

    0xaf8573eb,// 31 MFM   3 

    0x9639b520,// 32 MFM   4 

/// BDA is 200 words. 

/// BDA size     is 796 (0x31c) 

/// BDA id       is 0xd94d 

    0x031cd94d,// 33 BDA   1 

/// PAY Generic Data size   : 796 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x4f300e70,// 34 PAY   1 

    0x0b641801,// 35 PAY   2 

    0x185e4aee,// 36 PAY   3 

    0xe6d89cc8,// 37 PAY   4 

    0xa74d67cc,// 38 PAY   5 

    0x9fe2f1c9,// 39 PAY   6 

    0xe2f18e16,// 40 PAY   7 

    0x14a6c935,// 41 PAY   8 

    0xff60f44d,// 42 PAY   9 

    0x32dc9e3c,// 43 PAY  10 

    0xccea2558,// 44 PAY  11 

    0x3f80abc1,// 45 PAY  12 

    0xb887dbe5,// 46 PAY  13 

    0xac689cce,// 47 PAY  14 

    0xea63be28,// 48 PAY  15 

    0xc944481e,// 49 PAY  16 

    0x5b708629,// 50 PAY  17 

    0x0fdced9a,// 51 PAY  18 

    0xa7b24777,// 52 PAY  19 

    0xf35b72d7,// 53 PAY  20 

    0xf9fab108,// 54 PAY  21 

    0xe58ab630,// 55 PAY  22 

    0x575fbe9c,// 56 PAY  23 

    0x7b173bb5,// 57 PAY  24 

    0xc89e67e5,// 58 PAY  25 

    0xbbd10a83,// 59 PAY  26 

    0x18cd6bf0,// 60 PAY  27 

    0x837d3dcf,// 61 PAY  28 

    0x269b53df,// 62 PAY  29 

    0x519cbcc8,// 63 PAY  30 

    0x1d75ae91,// 64 PAY  31 

    0x1d59113a,// 65 PAY  32 

    0x9d10a68a,// 66 PAY  33 

    0xc6f8090b,// 67 PAY  34 

    0x77ba9787,// 68 PAY  35 

    0x249662e1,// 69 PAY  36 

    0xd056d907,// 70 PAY  37 

    0x33ebcc02,// 71 PAY  38 

    0x1f125093,// 72 PAY  39 

    0x9a3c2555,// 73 PAY  40 

    0x3010cf8d,// 74 PAY  41 

    0x880bee83,// 75 PAY  42 

    0x64d7fe8c,// 76 PAY  43 

    0xda57bd29,// 77 PAY  44 

    0x03399c68,// 78 PAY  45 

    0x616a361e,// 79 PAY  46 

    0x5274d41c,// 80 PAY  47 

    0xd8c648ff,// 81 PAY  48 

    0x970ecf15,// 82 PAY  49 

    0x03c3e089,// 83 PAY  50 

    0x09974a18,// 84 PAY  51 

    0xe57b6738,// 85 PAY  52 

    0xb6e9329e,// 86 PAY  53 

    0xb5ae25a8,// 87 PAY  54 

    0x57920b58,// 88 PAY  55 

    0x77eca008,// 89 PAY  56 

    0x034fd45e,// 90 PAY  57 

    0xe0dae201,// 91 PAY  58 

    0xf09b598a,// 92 PAY  59 

    0x208e2431,// 93 PAY  60 

    0x012f8dcc,// 94 PAY  61 

    0x419c18be,// 95 PAY  62 

    0x0ad11b4f,// 96 PAY  63 

    0xbcf60d2b,// 97 PAY  64 

    0x2ad5d77d,// 98 PAY  65 

    0x8636600d,// 99 PAY  66 

    0xdf820c1c,// 100 PAY  67 

    0x2a4a5a2e,// 101 PAY  68 

    0x2e0c7eb4,// 102 PAY  69 

    0x5d9a7ab5,// 103 PAY  70 

    0x3075e168,// 104 PAY  71 

    0xa877d249,// 105 PAY  72 

    0x819a62c4,// 106 PAY  73 

    0xa3ae7264,// 107 PAY  74 

    0x73d0e487,// 108 PAY  75 

    0xc41ce11a,// 109 PAY  76 

    0x600b7efd,// 110 PAY  77 

    0xf83f693d,// 111 PAY  78 

    0x6cd45fee,// 112 PAY  79 

    0x4596ed1f,// 113 PAY  80 

    0xf2550c1e,// 114 PAY  81 

    0xf9108178,// 115 PAY  82 

    0x6193b7c4,// 116 PAY  83 

    0x739a5681,// 117 PAY  84 

    0xea406fca,// 118 PAY  85 

    0x3bda6064,// 119 PAY  86 

    0x42f4bd82,// 120 PAY  87 

    0xc5c169d3,// 121 PAY  88 

    0x99a42435,// 122 PAY  89 

    0xd2fe2ae6,// 123 PAY  90 

    0x584487fe,// 124 PAY  91 

    0xc28b8e8f,// 125 PAY  92 

    0x84ec58c1,// 126 PAY  93 

    0xae6aad5b,// 127 PAY  94 

    0x75701470,// 128 PAY  95 

    0xf8f8fc62,// 129 PAY  96 

    0xaefdf8f8,// 130 PAY  97 

    0x8932ed17,// 131 PAY  98 

    0xfbb66217,// 132 PAY  99 

    0x0f202eeb,// 133 PAY 100 

    0x63a80f7c,// 134 PAY 101 

    0xcb85e53d,// 135 PAY 102 

    0x7678bb0d,// 136 PAY 103 

    0x7fe475fb,// 137 PAY 104 

    0x2de9baa8,// 138 PAY 105 

    0x4cf98e2a,// 139 PAY 106 

    0x0e482aeb,// 140 PAY 107 

    0xd23e3d47,// 141 PAY 108 

    0x6af6ddd0,// 142 PAY 109 

    0xc8c36e56,// 143 PAY 110 

    0x891f9557,// 144 PAY 111 

    0x5c721a39,// 145 PAY 112 

    0x4e4823a4,// 146 PAY 113 

    0xdb1fd5b3,// 147 PAY 114 

    0x956c5378,// 148 PAY 115 

    0x161413f1,// 149 PAY 116 

    0x64863172,// 150 PAY 117 

    0x35a0a58a,// 151 PAY 118 

    0xaa399a9f,// 152 PAY 119 

    0xd5eb88d3,// 153 PAY 120 

    0xeacebe47,// 154 PAY 121 

    0x5f0227b3,// 155 PAY 122 

    0xc6de821e,// 156 PAY 123 

    0x51a928e7,// 157 PAY 124 

    0xb2011a30,// 158 PAY 125 

    0x43357ebf,// 159 PAY 126 

    0x4c1fd349,// 160 PAY 127 

    0x9f86a36e,// 161 PAY 128 

    0x08c696f3,// 162 PAY 129 

    0x0dfca078,// 163 PAY 130 

    0x1fe9d97c,// 164 PAY 131 

    0xafb9b852,// 165 PAY 132 

    0xea5654b5,// 166 PAY 133 

    0x2cd75c52,// 167 PAY 134 

    0x26478098,// 168 PAY 135 

    0x9cef0be5,// 169 PAY 136 

    0xc9fb8332,// 170 PAY 137 

    0x218a6575,// 171 PAY 138 

    0x1170052e,// 172 PAY 139 

    0xc9b5d832,// 173 PAY 140 

    0x21f0cab1,// 174 PAY 141 

    0x3d4974b4,// 175 PAY 142 

    0xc2462fea,// 176 PAY 143 

    0x38adbfaa,// 177 PAY 144 

    0xb0a14852,// 178 PAY 145 

    0x517f79e9,// 179 PAY 146 

    0xc17560a5,// 180 PAY 147 

    0x276903c7,// 181 PAY 148 

    0x015fe8f9,// 182 PAY 149 

    0x72c97a76,// 183 PAY 150 

    0x9451ab85,// 184 PAY 151 

    0xc362828c,// 185 PAY 152 

    0x548149e9,// 186 PAY 153 

    0x08e25c6b,// 187 PAY 154 

    0xe75308f9,// 188 PAY 155 

    0xdb1a776d,// 189 PAY 156 

    0xf91d9b82,// 190 PAY 157 

    0xf6442a51,// 191 PAY 158 

    0x273ac2eb,// 192 PAY 159 

    0x522d4d13,// 193 PAY 160 

    0xb3741da0,// 194 PAY 161 

    0x2d85a7eb,// 195 PAY 162 

    0x9fc31816,// 196 PAY 163 

    0x4c29d09a,// 197 PAY 164 

    0xb380d867,// 198 PAY 165 

    0x0dc729b2,// 199 PAY 166 

    0x142cc571,// 200 PAY 167 

    0x04e452f6,// 201 PAY 168 

    0xfafdc458,// 202 PAY 169 

    0x7b883444,// 203 PAY 170 

    0xda409e8a,// 204 PAY 171 

    0x18896d17,// 205 PAY 172 

    0x2349c893,// 206 PAY 173 

    0x71c64af7,// 207 PAY 174 

    0x40d9a09d,// 208 PAY 175 

    0x7067f55b,// 209 PAY 176 

    0x827ea673,// 210 PAY 177 

    0x96d303b8,// 211 PAY 178 

    0xf68958ac,// 212 PAY 179 

    0x7447411e,// 213 PAY 180 

    0x8840c891,// 214 PAY 181 

    0xa6386835,// 215 PAY 182 

    0x2ffcb3fd,// 216 PAY 183 

    0x54120f4b,// 217 PAY 184 

    0xe509fc2d,// 218 PAY 185 

    0x704d5ff8,// 219 PAY 186 

    0x4f1d7353,// 220 PAY 187 

    0x5d3c9d92,// 221 PAY 188 

    0xca4375cf,// 222 PAY 189 

    0x9c9b6c67,// 223 PAY 190 

    0x27275e1d,// 224 PAY 191 

    0x5a061552,// 225 PAY 192 

    0x3cd9b318,// 226 PAY 193 

    0x916f1a2e,// 227 PAY 194 

    0xff32b143,// 228 PAY 195 

    0x005e3389,// 229 PAY 196 

    0x140258f8,// 230 PAY 197 

    0x561bd04a,// 231 PAY 198 

    0x5c5e5b4e,// 232 PAY 199 

/// STA is 1 words. 

/// STA num_pkts       : 120 

/// STA pkt_idx        : 243 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xdb 

    0x03ccdb78 // 233 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt41_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x8085282a,// 4 SCX   2 

    0x000013c4,// 5 SCX   3 

    0x2b8e01eb,// 6 SCX   4 

    0x57f924df,// 7 SCX   5 

    0x531721f3,// 8 SCX   6 

    0x1f4f65b8,// 9 SCX   7 

    0x4db8129a,// 10 SCX   8 

    0x61c4bca0,// 11 SCX   9 

    0x956c95b8,// 12 SCX  10 

    0xc27a4c66,// 13 SCX  11 

    0x4ef1d214,// 14 SCX  12 

    0xb517242a,// 15 SCX  13 

    0xd5096e3e,// 16 SCX  14 

    0x68bba52b,// 17 SCX  15 

    0x4b5ccc74,// 18 SCX  16 

    0x5dcbdae3,// 19 SCX  17 

    0x0b18898d,// 20 SCX  18 

    0x09298a41,// 21 SCX  19 

    0xaf9d2b49,// 22 SCX  20 

    0x7551eb50,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1710 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1184 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1184 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 968 

/// BFD (ofst+len)cry  : 984 

/// BFD ofstiv         : 152 

/// BFD ofsticv        : 1240 

    0x000004a0,// 24 BFD   1 

    0x03c80010,// 25 BFD   2 

    0x04d80098,// 26 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00e927,// 27 MFM   1 

    0xcc7e5035,// 28 MFM   2 

    0xe9a88cc2,// 29 MFM   3 

    0xfa51c31e,// 30 MFM   4 

    0x524d44bf,// 31 MFM   5 

    0xab0a0f0e,// 32 MFM   6 

    0x14f12ae6,// 33 MFM   7 

    0xe1439e52,// 34 MFM   8 

    0x552b0492,// 35 MFM   9 

    0x20ecfdf4,// 36 MFM  10 

    0xd7900c14,// 37 MFM  11 

    0x54c99d12,// 38 MFM  12 

    0x57f1d6dd,// 39 MFM  13 

    0xc08e49e8,// 40 MFM  14 

    0x272da5d4,// 41 MFM  15 

    0xa84e22ea,// 42 MFM  16 

/// BDA is 429 words. 

/// BDA size     is 1710 (0x6ae) 

/// BDA id       is 0x4f88 

    0x06ae4f88,// 43 BDA   1 

/// PAY Generic Data size   : 1710 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x144cb381,// 44 PAY   1 

    0xa3dadb4f,// 45 PAY   2 

    0xc1e9392d,// 46 PAY   3 

    0x33672dd5,// 47 PAY   4 

    0x2ee5f748,// 48 PAY   5 

    0xaf2dd90b,// 49 PAY   6 

    0x2ec838bf,// 50 PAY   7 

    0xf69317ac,// 51 PAY   8 

    0xcc2ef95b,// 52 PAY   9 

    0xf5093b24,// 53 PAY  10 

    0x7a251628,// 54 PAY  11 

    0xf6a36d3d,// 55 PAY  12 

    0xd74b5231,// 56 PAY  13 

    0x95735e52,// 57 PAY  14 

    0xe979ff89,// 58 PAY  15 

    0xade6b5e7,// 59 PAY  16 

    0x322f0bea,// 60 PAY  17 

    0xbe336594,// 61 PAY  18 

    0x2361bed9,// 62 PAY  19 

    0xd74a0990,// 63 PAY  20 

    0xe0770ac1,// 64 PAY  21 

    0x70738f34,// 65 PAY  22 

    0x425192ea,// 66 PAY  23 

    0x17db5706,// 67 PAY  24 

    0x26e7e18f,// 68 PAY  25 

    0x134997e9,// 69 PAY  26 

    0xbdb54ed8,// 70 PAY  27 

    0x3ebe9877,// 71 PAY  28 

    0xb53bc039,// 72 PAY  29 

    0x8069dac4,// 73 PAY  30 

    0xffda7005,// 74 PAY  31 

    0x2735ed88,// 75 PAY  32 

    0x514cdb5f,// 76 PAY  33 

    0x0dd22003,// 77 PAY  34 

    0x0dea525b,// 78 PAY  35 

    0x2ab3b61f,// 79 PAY  36 

    0x25875392,// 80 PAY  37 

    0x9c56482f,// 81 PAY  38 

    0x9898195e,// 82 PAY  39 

    0xf3b2efd6,// 83 PAY  40 

    0xb432cf02,// 84 PAY  41 

    0x72e31205,// 85 PAY  42 

    0x0d337eb2,// 86 PAY  43 

    0xf17f8fa5,// 87 PAY  44 

    0x807d5662,// 88 PAY  45 

    0xfe9cd260,// 89 PAY  46 

    0xed242ff5,// 90 PAY  47 

    0xc54c34bc,// 91 PAY  48 

    0xb9b37fbf,// 92 PAY  49 

    0x654a86c3,// 93 PAY  50 

    0x9f2b50e0,// 94 PAY  51 

    0xd09f59b9,// 95 PAY  52 

    0x1cf0bb98,// 96 PAY  53 

    0xdbca10c7,// 97 PAY  54 

    0x8bfb4f5f,// 98 PAY  55 

    0x5ad71a63,// 99 PAY  56 

    0x0a419b43,// 100 PAY  57 

    0x65840b11,// 101 PAY  58 

    0xbaf089c0,// 102 PAY  59 

    0x567bc67f,// 103 PAY  60 

    0xf12d4dea,// 104 PAY  61 

    0xc5323125,// 105 PAY  62 

    0xf449ca80,// 106 PAY  63 

    0x2ed28993,// 107 PAY  64 

    0x70ad7da6,// 108 PAY  65 

    0x2f5ad2c3,// 109 PAY  66 

    0x2578ca9f,// 110 PAY  67 

    0x298d620b,// 111 PAY  68 

    0x34820ac6,// 112 PAY  69 

    0xfffd8f49,// 113 PAY  70 

    0xac0fe758,// 114 PAY  71 

    0xd6351014,// 115 PAY  72 

    0x3b954ca9,// 116 PAY  73 

    0xbac14800,// 117 PAY  74 

    0x0f5fffd5,// 118 PAY  75 

    0xdaae8709,// 119 PAY  76 

    0xc6ce6eb2,// 120 PAY  77 

    0x17262e1b,// 121 PAY  78 

    0x1cd02556,// 122 PAY  79 

    0x22b3d533,// 123 PAY  80 

    0x7d63bc6b,// 124 PAY  81 

    0x50c2afd4,// 125 PAY  82 

    0x19e62962,// 126 PAY  83 

    0x63d0b983,// 127 PAY  84 

    0xa236098d,// 128 PAY  85 

    0x6ffb117e,// 129 PAY  86 

    0x7290255a,// 130 PAY  87 

    0xa2ee12c9,// 131 PAY  88 

    0x33c61736,// 132 PAY  89 

    0x9bb1907c,// 133 PAY  90 

    0x2703af2c,// 134 PAY  91 

    0x303c7a05,// 135 PAY  92 

    0x46342665,// 136 PAY  93 

    0x27ce2e9d,// 137 PAY  94 

    0xf8c032be,// 138 PAY  95 

    0x48e16ab8,// 139 PAY  96 

    0x1d72e57b,// 140 PAY  97 

    0xc43e6c9d,// 141 PAY  98 

    0xc2303d51,// 142 PAY  99 

    0x76662b86,// 143 PAY 100 

    0xf9c9d700,// 144 PAY 101 

    0x3c82aec7,// 145 PAY 102 

    0xeb5a7d10,// 146 PAY 103 

    0xc7fcd8a4,// 147 PAY 104 

    0x1b8fb02e,// 148 PAY 105 

    0x4a128729,// 149 PAY 106 

    0xe90ad1bb,// 150 PAY 107 

    0xcc038d12,// 151 PAY 108 

    0xcb2d44c8,// 152 PAY 109 

    0x64481ceb,// 153 PAY 110 

    0x5188b46a,// 154 PAY 111 

    0xf00bdac4,// 155 PAY 112 

    0xd154fe88,// 156 PAY 113 

    0x07b15652,// 157 PAY 114 

    0xd5cb5465,// 158 PAY 115 

    0x37475502,// 159 PAY 116 

    0x86d5c3f6,// 160 PAY 117 

    0x584bdfc7,// 161 PAY 118 

    0x356b7bf4,// 162 PAY 119 

    0x9db22ce2,// 163 PAY 120 

    0x7eb533d9,// 164 PAY 121 

    0x8ce09d93,// 165 PAY 122 

    0x7e9435c7,// 166 PAY 123 

    0xe93a5ee9,// 167 PAY 124 

    0xc649a9fd,// 168 PAY 125 

    0xe6c9f631,// 169 PAY 126 

    0xa9f7159b,// 170 PAY 127 

    0xfc6e1f87,// 171 PAY 128 

    0x6e22a8c2,// 172 PAY 129 

    0x85cc55c5,// 173 PAY 130 

    0x18850e96,// 174 PAY 131 

    0x96c5ee26,// 175 PAY 132 

    0x1ee8a3ab,// 176 PAY 133 

    0x7e0ea81a,// 177 PAY 134 

    0x6f5b234c,// 178 PAY 135 

    0x36dc078f,// 179 PAY 136 

    0x8b8d4c43,// 180 PAY 137 

    0xf3d06aa8,// 181 PAY 138 

    0x51517ba9,// 182 PAY 139 

    0x5c68a111,// 183 PAY 140 

    0x589e92cf,// 184 PAY 141 

    0x21dcf095,// 185 PAY 142 

    0xb5e00de6,// 186 PAY 143 

    0x2d31bfb9,// 187 PAY 144 

    0x5a6e3bc8,// 188 PAY 145 

    0x0bc0ef1d,// 189 PAY 146 

    0xe1c212fe,// 190 PAY 147 

    0xf8aad984,// 191 PAY 148 

    0x6b106c0a,// 192 PAY 149 

    0xc73d3c74,// 193 PAY 150 

    0x1fe1cd59,// 194 PAY 151 

    0xa56665fd,// 195 PAY 152 

    0x391d698f,// 196 PAY 153 

    0x737cfafe,// 197 PAY 154 

    0x0d9984a7,// 198 PAY 155 

    0xec14bdda,// 199 PAY 156 

    0x690c897d,// 200 PAY 157 

    0xe9c5f97e,// 201 PAY 158 

    0xf816d6a0,// 202 PAY 159 

    0x5aa5251d,// 203 PAY 160 

    0x90b6f60b,// 204 PAY 161 

    0x187bf876,// 205 PAY 162 

    0xc50ff409,// 206 PAY 163 

    0xf440686c,// 207 PAY 164 

    0xf0816f28,// 208 PAY 165 

    0xfa860648,// 209 PAY 166 

    0x04956f81,// 210 PAY 167 

    0x601974a4,// 211 PAY 168 

    0x012d1072,// 212 PAY 169 

    0x9cf39322,// 213 PAY 170 

    0xbeac4a8e,// 214 PAY 171 

    0x57bf3d28,// 215 PAY 172 

    0xe42e694f,// 216 PAY 173 

    0xce94e040,// 217 PAY 174 

    0xdcdfa0d2,// 218 PAY 175 

    0xea775b70,// 219 PAY 176 

    0x1f92caa4,// 220 PAY 177 

    0xe8458786,// 221 PAY 178 

    0x877ca4d3,// 222 PAY 179 

    0x6a2c966c,// 223 PAY 180 

    0x6ec40b66,// 224 PAY 181 

    0x78950268,// 225 PAY 182 

    0x12dac8ba,// 226 PAY 183 

    0x5d5c95b4,// 227 PAY 184 

    0x8993d540,// 228 PAY 185 

    0x7aef410f,// 229 PAY 186 

    0x120ef40c,// 230 PAY 187 

    0xb684021f,// 231 PAY 188 

    0xbe275046,// 232 PAY 189 

    0xaa477081,// 233 PAY 190 

    0x93b1218d,// 234 PAY 191 

    0x466eeb42,// 235 PAY 192 

    0x9e1007f5,// 236 PAY 193 

    0x4f070c84,// 237 PAY 194 

    0x063ab327,// 238 PAY 195 

    0xb89feb80,// 239 PAY 196 

    0xe09e02b7,// 240 PAY 197 

    0xbae2c895,// 241 PAY 198 

    0x38fe0340,// 242 PAY 199 

    0x3985b39f,// 243 PAY 200 

    0x18c9d6be,// 244 PAY 201 

    0x776b92f3,// 245 PAY 202 

    0x85b36fc9,// 246 PAY 203 

    0xd463e6e5,// 247 PAY 204 

    0x1a0d6ec5,// 248 PAY 205 

    0x3185b1d9,// 249 PAY 206 

    0x293a8517,// 250 PAY 207 

    0x2c4934a8,// 251 PAY 208 

    0xc5263179,// 252 PAY 209 

    0x5f2d449c,// 253 PAY 210 

    0x70e353e6,// 254 PAY 211 

    0x2ee3cc21,// 255 PAY 212 

    0x5c084def,// 256 PAY 213 

    0x5a529c26,// 257 PAY 214 

    0x341f69a7,// 258 PAY 215 

    0x064ac55a,// 259 PAY 216 

    0xdd1c5162,// 260 PAY 217 

    0xf901b5c3,// 261 PAY 218 

    0xcf6f431c,// 262 PAY 219 

    0x5dc19100,// 263 PAY 220 

    0xc190d7be,// 264 PAY 221 

    0x14373ef6,// 265 PAY 222 

    0xbcdbae8d,// 266 PAY 223 

    0x61b5beb0,// 267 PAY 224 

    0xf366bf9b,// 268 PAY 225 

    0x13d069ff,// 269 PAY 226 

    0xdd24f7f4,// 270 PAY 227 

    0x93278519,// 271 PAY 228 

    0xa10b7de2,// 272 PAY 229 

    0x9e3008ea,// 273 PAY 230 

    0xf02947b2,// 274 PAY 231 

    0x513659ad,// 275 PAY 232 

    0xe212f32c,// 276 PAY 233 

    0xf4c41880,// 277 PAY 234 

    0x45dd9c77,// 278 PAY 235 

    0x5ab106ea,// 279 PAY 236 

    0x68f2be1c,// 280 PAY 237 

    0x3e7350e1,// 281 PAY 238 

    0x72351bd3,// 282 PAY 239 

    0x2b445239,// 283 PAY 240 

    0x1438976f,// 284 PAY 241 

    0xe308c296,// 285 PAY 242 

    0xc9b577db,// 286 PAY 243 

    0x8435f12f,// 287 PAY 244 

    0x03cebf08,// 288 PAY 245 

    0x61f0d3b2,// 289 PAY 246 

    0xa96979f1,// 290 PAY 247 

    0x0f0ac51b,// 291 PAY 248 

    0x5ea4fcab,// 292 PAY 249 

    0xb8baf5ff,// 293 PAY 250 

    0x6fa04589,// 294 PAY 251 

    0xebb2df75,// 295 PAY 252 

    0xfb10e9a1,// 296 PAY 253 

    0x3d87b174,// 297 PAY 254 

    0xebadcf5d,// 298 PAY 255 

    0x544525fe,// 299 PAY 256 

    0xc0cfc622,// 300 PAY 257 

    0xd8eaf135,// 301 PAY 258 

    0xc042e2d2,// 302 PAY 259 

    0xbd4ad897,// 303 PAY 260 

    0x3053f90e,// 304 PAY 261 

    0x8fa49dac,// 305 PAY 262 

    0xeddabe62,// 306 PAY 263 

    0xa880a85c,// 307 PAY 264 

    0x9f276f5b,// 308 PAY 265 

    0x84878e20,// 309 PAY 266 

    0xfcf550e6,// 310 PAY 267 

    0xa4f5257d,// 311 PAY 268 

    0x67ee3cb4,// 312 PAY 269 

    0x5c45556d,// 313 PAY 270 

    0xfeeaab62,// 314 PAY 271 

    0x6fe71d69,// 315 PAY 272 

    0x5264cd80,// 316 PAY 273 

    0x0f6f073d,// 317 PAY 274 

    0xd926bea2,// 318 PAY 275 

    0x1c1d4f85,// 319 PAY 276 

    0xf55cc9c3,// 320 PAY 277 

    0x78361e63,// 321 PAY 278 

    0x037b06e1,// 322 PAY 279 

    0xb668b7a6,// 323 PAY 280 

    0x22e8dd98,// 324 PAY 281 

    0x740d4861,// 325 PAY 282 

    0x3f9e66f6,// 326 PAY 283 

    0x0985b97f,// 327 PAY 284 

    0xbb248057,// 328 PAY 285 

    0x8cf6400d,// 329 PAY 286 

    0x342c907c,// 330 PAY 287 

    0x465ae590,// 331 PAY 288 

    0xa056f9d3,// 332 PAY 289 

    0x7c44eab2,// 333 PAY 290 

    0x2896146c,// 334 PAY 291 

    0x02d2d9bb,// 335 PAY 292 

    0x7fe4b7ff,// 336 PAY 293 

    0x4830a1fa,// 337 PAY 294 

    0x4368be9e,// 338 PAY 295 

    0x23f22c5f,// 339 PAY 296 

    0x31cbc236,// 340 PAY 297 

    0x61b0e71d,// 341 PAY 298 

    0x8b47badd,// 342 PAY 299 

    0x971a1435,// 343 PAY 300 

    0x2b1e3f70,// 344 PAY 301 

    0x6f13cc83,// 345 PAY 302 

    0x194bb124,// 346 PAY 303 

    0xc461d86d,// 347 PAY 304 

    0x242c4b46,// 348 PAY 305 

    0x09606cef,// 349 PAY 306 

    0x7bb7555e,// 350 PAY 307 

    0x5549d496,// 351 PAY 308 

    0x0fbc96e1,// 352 PAY 309 

    0xe80e04a4,// 353 PAY 310 

    0x819245be,// 354 PAY 311 

    0xba7484dd,// 355 PAY 312 

    0x9a099a64,// 356 PAY 313 

    0xab5f61e9,// 357 PAY 314 

    0x58971232,// 358 PAY 315 

    0x20bc289a,// 359 PAY 316 

    0xd29a7f31,// 360 PAY 317 

    0x9cc1334e,// 361 PAY 318 

    0x87d9ac9d,// 362 PAY 319 

    0xb1c92ff2,// 363 PAY 320 

    0xfda83c68,// 364 PAY 321 

    0x859ac3bf,// 365 PAY 322 

    0xff8e5943,// 366 PAY 323 

    0x0ebf6408,// 367 PAY 324 

    0xc06d72f9,// 368 PAY 325 

    0x2c0258c8,// 369 PAY 326 

    0x773c86d0,// 370 PAY 327 

    0x1b08a37e,// 371 PAY 328 

    0xa7139a9a,// 372 PAY 329 

    0x8e2cc8d5,// 373 PAY 330 

    0x3fda5a89,// 374 PAY 331 

    0x77cc8d85,// 375 PAY 332 

    0x413ce4f1,// 376 PAY 333 

    0x347bd614,// 377 PAY 334 

    0x29e8b196,// 378 PAY 335 

    0xa305686c,// 379 PAY 336 

    0x4b2c0016,// 380 PAY 337 

    0x87d0127a,// 381 PAY 338 

    0xedffc91b,// 382 PAY 339 

    0x7ddcbebf,// 383 PAY 340 

    0x86778bf4,// 384 PAY 341 

    0x7477e203,// 385 PAY 342 

    0x1457a068,// 386 PAY 343 

    0x2d2c2a63,// 387 PAY 344 

    0x3b0d724f,// 388 PAY 345 

    0x8a954138,// 389 PAY 346 

    0xf993f391,// 390 PAY 347 

    0x9e176649,// 391 PAY 348 

    0x0850ade8,// 392 PAY 349 

    0xfcbeb585,// 393 PAY 350 

    0x016bb2dd,// 394 PAY 351 

    0x6b95f0bf,// 395 PAY 352 

    0x9844a3fb,// 396 PAY 353 

    0x4e84743f,// 397 PAY 354 

    0xc333ac43,// 398 PAY 355 

    0x18a412d8,// 399 PAY 356 

    0x0e1eeb14,// 400 PAY 357 

    0x9f23d08d,// 401 PAY 358 

    0x65f999a8,// 402 PAY 359 

    0xda2219b6,// 403 PAY 360 

    0xf95bdf5f,// 404 PAY 361 

    0x04b142fc,// 405 PAY 362 

    0x9e2c2ab9,// 406 PAY 363 

    0x81bb2494,// 407 PAY 364 

    0x049ce7e5,// 408 PAY 365 

    0x2ee97d0d,// 409 PAY 366 

    0x520d2898,// 410 PAY 367 

    0xb6ecb8f9,// 411 PAY 368 

    0xcd0b663c,// 412 PAY 369 

    0x3d96914e,// 413 PAY 370 

    0x2dd99eb8,// 414 PAY 371 

    0x646130f5,// 415 PAY 372 

    0xb9a8acd5,// 416 PAY 373 

    0xbae24947,// 417 PAY 374 

    0x25ebdd79,// 418 PAY 375 

    0x8821e7c2,// 419 PAY 376 

    0x4f9d33c5,// 420 PAY 377 

    0xb57af374,// 421 PAY 378 

    0x8733fdf9,// 422 PAY 379 

    0xb47bd71a,// 423 PAY 380 

    0x48a175e1,// 424 PAY 381 

    0xf92f3361,// 425 PAY 382 

    0xb0938054,// 426 PAY 383 

    0x58cef1ae,// 427 PAY 384 

    0xfa3fe6c7,// 428 PAY 385 

    0xa5d1bc3b,// 429 PAY 386 

    0x43b4f5f1,// 430 PAY 387 

    0x7bac1212,// 431 PAY 388 

    0x15455525,// 432 PAY 389 

    0xd260e866,// 433 PAY 390 

    0x3985eb36,// 434 PAY 391 

    0xfd0d18e7,// 435 PAY 392 

    0x06e5a275,// 436 PAY 393 

    0xdfa17cb3,// 437 PAY 394 

    0xe4dfa506,// 438 PAY 395 

    0x186874b3,// 439 PAY 396 

    0x5550b7d0,// 440 PAY 397 

    0xe6b4eaab,// 441 PAY 398 

    0xd0c323d3,// 442 PAY 399 

    0x845fc83b,// 443 PAY 400 

    0xced4601b,// 444 PAY 401 

    0x120aeb64,// 445 PAY 402 

    0xceb88eb5,// 446 PAY 403 

    0xb7a17839,// 447 PAY 404 

    0x727d0d5e,// 448 PAY 405 

    0x3113aec0,// 449 PAY 406 

    0xd5c0c45f,// 450 PAY 407 

    0x3742fc91,// 451 PAY 408 

    0xc19089f6,// 452 PAY 409 

    0x0e9fc4c9,// 453 PAY 410 

    0x8e15ad4b,// 454 PAY 411 

    0xf68e3878,// 455 PAY 412 

    0x33634524,// 456 PAY 413 

    0xe377b63b,// 457 PAY 414 

    0xc8c96894,// 458 PAY 415 

    0x100819ae,// 459 PAY 416 

    0x9961b3f7,// 460 PAY 417 

    0x055ead1d,// 461 PAY 418 

    0xeea81d65,// 462 PAY 419 

    0x5b5ab074,// 463 PAY 420 

    0x383bca28,// 464 PAY 421 

    0xecefe627,// 465 PAY 422 

    0x51786ac5,// 466 PAY 423 

    0xf135a413,// 467 PAY 424 

    0x4cc6d688,// 468 PAY 425 

    0x5a417b00,// 469 PAY 426 

    0xeb711d8e,// 470 PAY 427 

    0x3bda0000,// 471 PAY 428 

/// STA is 1 words. 

/// STA num_pkts       : 154 

/// STA pkt_idx        : 101 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x4a 

    0x01954a9a // 472 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt42_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80842883,// 4 SCX   2 

    0x00004384,// 5 SCX   3 

    0x0b429396,// 6 SCX   4 

    0x1eb6f1c6,// 7 SCX   5 

    0xf8995703,// 8 SCX   6 

    0x105da53f,// 9 SCX   7 

    0xdbc817a6,// 10 SCX   8 

    0x7abd2758,// 11 SCX   9 

    0xfa634ba9,// 12 SCX  10 

    0xdb5fd7e6,// 13 SCX  11 

    0x235c0545,// 14 SCX  12 

    0x931e6c4e,// 15 SCX  13 

    0xa87c5ba8,// 16 SCX  14 

    0xe571bc2a,// 17 SCX  15 

    0x646a2b65,// 18 SCX  16 

    0x3896bf7c,// 19 SCX  17 

    0xff52caaf,// 20 SCX  18 

    0xd1054286,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1053 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 838 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 838 

/// BFD lencrypto      : 96 

/// BFD ofstcrypto     : 432 

/// BFD (ofst+len)cry  : 528 

/// BFD ofstiv         : 208 

/// BFD ofsticv        : 968 

    0x00000346,// 22 BFD   1 

    0x01b00060,// 23 BFD   2 

    0x03c800d0,// 24 BFD   3 

/// MFM is 10 words. 

/// MFM vldnibs        : 45 

    0x45006555,// 25 MFM   1 

    0x0b975e75,// 26 MFM   2 

    0x3cb36f4e,// 27 MFM   3 

    0x3731124e,// 28 MFM   4 

    0x1026ae4c,// 29 MFM   5 

    0x7cd30387,// 30 MFM   6 

    0x46c01480,// 31 MFM   7 

    0xe7e4dbfe,// 32 MFM   8 

    0xdc27204b,// 33 MFM   9 

    0x20000000,// 34 MFM  10 

/// BDA is 265 words. 

/// BDA size     is 1053 (0x41d) 

/// BDA id       is 0x80ec 

    0x041d80ec,// 35 BDA   1 

/// PAY Generic Data size   : 1053 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x3046d8d7,// 36 PAY   1 

    0x0f148944,// 37 PAY   2 

    0x503eedeb,// 38 PAY   3 

    0x06d8752f,// 39 PAY   4 

    0xb065f160,// 40 PAY   5 

    0x4427e07e,// 41 PAY   6 

    0x9773f6f4,// 42 PAY   7 

    0xa6a342da,// 43 PAY   8 

    0x0b66e3ee,// 44 PAY   9 

    0xcccd1d65,// 45 PAY  10 

    0xb8fee531,// 46 PAY  11 

    0xbe64894a,// 47 PAY  12 

    0xdbdc4bf5,// 48 PAY  13 

    0x87d0b47b,// 49 PAY  14 

    0x96ce3f15,// 50 PAY  15 

    0xdc762a91,// 51 PAY  16 

    0xd8669718,// 52 PAY  17 

    0xc26edd9e,// 53 PAY  18 

    0x1597794d,// 54 PAY  19 

    0x43f4bc25,// 55 PAY  20 

    0x56144b20,// 56 PAY  21 

    0xfc5f6e8b,// 57 PAY  22 

    0xb1b02a54,// 58 PAY  23 

    0xee6e8c85,// 59 PAY  24 

    0x6024739d,// 60 PAY  25 

    0xcfd4b883,// 61 PAY  26 

    0xfe635414,// 62 PAY  27 

    0xd02c28b6,// 63 PAY  28 

    0xc3b5ccf4,// 64 PAY  29 

    0xa1458a80,// 65 PAY  30 

    0x7be1b713,// 66 PAY  31 

    0x78a08153,// 67 PAY  32 

    0x32648c39,// 68 PAY  33 

    0x99b4ffdd,// 69 PAY  34 

    0x2cf784c5,// 70 PAY  35 

    0x7073c016,// 71 PAY  36 

    0x92339b1e,// 72 PAY  37 

    0x6a1587e8,// 73 PAY  38 

    0x3ed3c510,// 74 PAY  39 

    0xb5aa258c,// 75 PAY  40 

    0xfa2be0ac,// 76 PAY  41 

    0x7429e582,// 77 PAY  42 

    0x231f21a8,// 78 PAY  43 

    0xf96ef710,// 79 PAY  44 

    0xf9e02451,// 80 PAY  45 

    0xfcda6bab,// 81 PAY  46 

    0xaae43e17,// 82 PAY  47 

    0xc61bc7e6,// 83 PAY  48 

    0xe73b2580,// 84 PAY  49 

    0x50c53eba,// 85 PAY  50 

    0x078b442d,// 86 PAY  51 

    0x29ac40fd,// 87 PAY  52 

    0x5aaac4ff,// 88 PAY  53 

    0xd7d58eeb,// 89 PAY  54 

    0x42836e63,// 90 PAY  55 

    0x97f110a7,// 91 PAY  56 

    0xeead643b,// 92 PAY  57 

    0x100fbb0c,// 93 PAY  58 

    0xa9de26bf,// 94 PAY  59 

    0x9408c230,// 95 PAY  60 

    0xa81faccb,// 96 PAY  61 

    0x0c79657c,// 97 PAY  62 

    0x9da72206,// 98 PAY  63 

    0x3d5b520e,// 99 PAY  64 

    0x5883ad68,// 100 PAY  65 

    0xe98440ad,// 101 PAY  66 

    0xdc26b77e,// 102 PAY  67 

    0x5eeb5653,// 103 PAY  68 

    0xb8353236,// 104 PAY  69 

    0xd9d1f67c,// 105 PAY  70 

    0x250fc03e,// 106 PAY  71 

    0x31747fe5,// 107 PAY  72 

    0x682b24aa,// 108 PAY  73 

    0x60cf1610,// 109 PAY  74 

    0x6015f3d3,// 110 PAY  75 

    0xaeb68296,// 111 PAY  76 

    0x357ca54a,// 112 PAY  77 

    0x07cbb48a,// 113 PAY  78 

    0x67b1592e,// 114 PAY  79 

    0x8bf18de5,// 115 PAY  80 

    0x591bb89c,// 116 PAY  81 

    0x45e9fa2a,// 117 PAY  82 

    0x37c1046b,// 118 PAY  83 

    0x441dc91d,// 119 PAY  84 

    0x51ba4c6a,// 120 PAY  85 

    0x3a328bf6,// 121 PAY  86 

    0x432de29b,// 122 PAY  87 

    0xdc699b56,// 123 PAY  88 

    0x23699d7d,// 124 PAY  89 

    0x96c53a94,// 125 PAY  90 

    0x451eec0e,// 126 PAY  91 

    0x535b87d4,// 127 PAY  92 

    0xb167d4aa,// 128 PAY  93 

    0xe65e9460,// 129 PAY  94 

    0x596704ca,// 130 PAY  95 

    0xf13b778f,// 131 PAY  96 

    0xef62e387,// 132 PAY  97 

    0x5647601c,// 133 PAY  98 

    0xb81a0e00,// 134 PAY  99 

    0x84425321,// 135 PAY 100 

    0x74ef25f6,// 136 PAY 101 

    0x8b4215a5,// 137 PAY 102 

    0xbb1dde38,// 138 PAY 103 

    0x06c2006b,// 139 PAY 104 

    0x702c4b95,// 140 PAY 105 

    0x939e7730,// 141 PAY 106 

    0x6e7d6048,// 142 PAY 107 

    0x872a7b3d,// 143 PAY 108 

    0x16dcee3a,// 144 PAY 109 

    0xae60ba0a,// 145 PAY 110 

    0x5dc2dc5a,// 146 PAY 111 

    0xd19a0b6a,// 147 PAY 112 

    0x0a5321f3,// 148 PAY 113 

    0xf2680682,// 149 PAY 114 

    0x7c826956,// 150 PAY 115 

    0xe5a17abd,// 151 PAY 116 

    0x30cc1833,// 152 PAY 117 

    0x0f48ee58,// 153 PAY 118 

    0xb4073c92,// 154 PAY 119 

    0xf059d71e,// 155 PAY 120 

    0x5a8fb17e,// 156 PAY 121 

    0xd2751f7a,// 157 PAY 122 

    0x0fe17ed4,// 158 PAY 123 

    0x44cdbe11,// 159 PAY 124 

    0x4668d332,// 160 PAY 125 

    0xa38238bd,// 161 PAY 126 

    0xa77cfe2f,// 162 PAY 127 

    0x411094df,// 163 PAY 128 

    0xc1d2567e,// 164 PAY 129 

    0xc8b99736,// 165 PAY 130 

    0x07d664fc,// 166 PAY 131 

    0xe45c14dd,// 167 PAY 132 

    0x4def24b8,// 168 PAY 133 

    0x7d70a534,// 169 PAY 134 

    0x2618a4dd,// 170 PAY 135 

    0xd5ddb035,// 171 PAY 136 

    0x00ebd56d,// 172 PAY 137 

    0x8ace5a6f,// 173 PAY 138 

    0x5f31f803,// 174 PAY 139 

    0x98dcf9be,// 175 PAY 140 

    0xdcdb9913,// 176 PAY 141 

    0xea38b643,// 177 PAY 142 

    0xaa99e142,// 178 PAY 143 

    0xff5a5e13,// 179 PAY 144 

    0x27b1c63d,// 180 PAY 145 

    0x879319d5,// 181 PAY 146 

    0xb5ece30e,// 182 PAY 147 

    0xcdd233bf,// 183 PAY 148 

    0xf272d8ad,// 184 PAY 149 

    0xc24c9cc1,// 185 PAY 150 

    0x2443bc6c,// 186 PAY 151 

    0xd6750736,// 187 PAY 152 

    0x7a133301,// 188 PAY 153 

    0x9e290e77,// 189 PAY 154 

    0x280bd5aa,// 190 PAY 155 

    0xe9496f3f,// 191 PAY 156 

    0x4dae7e30,// 192 PAY 157 

    0x31002a21,// 193 PAY 158 

    0x00809e82,// 194 PAY 159 

    0xdac06543,// 195 PAY 160 

    0xa507726e,// 196 PAY 161 

    0x6ebef936,// 197 PAY 162 

    0x74373e84,// 198 PAY 163 

    0x0883059e,// 199 PAY 164 

    0x5d36e54f,// 200 PAY 165 

    0x0633e8eb,// 201 PAY 166 

    0xc9229687,// 202 PAY 167 

    0xbbdd6890,// 203 PAY 168 

    0x6bd05a00,// 204 PAY 169 

    0x8c76642f,// 205 PAY 170 

    0x0c3a63e2,// 206 PAY 171 

    0x837cbf4c,// 207 PAY 172 

    0xbc9064a0,// 208 PAY 173 

    0xb67cebb7,// 209 PAY 174 

    0xc844604c,// 210 PAY 175 

    0x9718dd97,// 211 PAY 176 

    0x47bbb555,// 212 PAY 177 

    0x91a87709,// 213 PAY 178 

    0x5bd99efd,// 214 PAY 179 

    0x4bb723de,// 215 PAY 180 

    0x796bbe2c,// 216 PAY 181 

    0x38a2795b,// 217 PAY 182 

    0x6e542684,// 218 PAY 183 

    0x563bbeee,// 219 PAY 184 

    0xc4576dc1,// 220 PAY 185 

    0x87bec1b3,// 221 PAY 186 

    0x3bfc60de,// 222 PAY 187 

    0xb510db9c,// 223 PAY 188 

    0xeab051ff,// 224 PAY 189 

    0xb4f92ad2,// 225 PAY 190 

    0xba0ba322,// 226 PAY 191 

    0xbcc09c8e,// 227 PAY 192 

    0xfa26dfdb,// 228 PAY 193 

    0x4f511ca6,// 229 PAY 194 

    0x4602682a,// 230 PAY 195 

    0x50df3842,// 231 PAY 196 

    0x25e023ad,// 232 PAY 197 

    0x83c074e0,// 233 PAY 198 

    0x5ae44ce6,// 234 PAY 199 

    0x29ec93c8,// 235 PAY 200 

    0xc6365207,// 236 PAY 201 

    0x1dc71678,// 237 PAY 202 

    0x7df23dc5,// 238 PAY 203 

    0x0c689e60,// 239 PAY 204 

    0x19d72f5c,// 240 PAY 205 

    0xb2a50a6d,// 241 PAY 206 

    0x26ee061c,// 242 PAY 207 

    0x663c8ca9,// 243 PAY 208 

    0x2b4d3dd4,// 244 PAY 209 

    0x3e002986,// 245 PAY 210 

    0xf7a6b1ae,// 246 PAY 211 

    0xdee5f6d7,// 247 PAY 212 

    0xc2ea4f54,// 248 PAY 213 

    0x62cf7239,// 249 PAY 214 

    0x6b37f936,// 250 PAY 215 

    0x0141b240,// 251 PAY 216 

    0x3fe0c46c,// 252 PAY 217 

    0xa7152dca,// 253 PAY 218 

    0x13923f56,// 254 PAY 219 

    0x07d0788c,// 255 PAY 220 

    0x64b7c1ab,// 256 PAY 221 

    0xd5260a01,// 257 PAY 222 

    0x20456ea3,// 258 PAY 223 

    0xbc4a75e7,// 259 PAY 224 

    0x6c0160d1,// 260 PAY 225 

    0xefe1760f,// 261 PAY 226 

    0xd6438f2e,// 262 PAY 227 

    0x777c4f0b,// 263 PAY 228 

    0x9e07f9b0,// 264 PAY 229 

    0x00a9e900,// 265 PAY 230 

    0xd9ff0ada,// 266 PAY 231 

    0xa0ee2462,// 267 PAY 232 

    0xbd01670b,// 268 PAY 233 

    0xa3d808dd,// 269 PAY 234 

    0xf08cc747,// 270 PAY 235 

    0xb1d62a5a,// 271 PAY 236 

    0xd965f48e,// 272 PAY 237 

    0x108cda0f,// 273 PAY 238 

    0x69839443,// 274 PAY 239 

    0x8d167e87,// 275 PAY 240 

    0x489e143d,// 276 PAY 241 

    0x38443208,// 277 PAY 242 

    0x92423f1b,// 278 PAY 243 

    0xd586d36a,// 279 PAY 244 

    0x49d3da6e,// 280 PAY 245 

    0x211d34ad,// 281 PAY 246 

    0xb45e3c1f,// 282 PAY 247 

    0x5a09a78a,// 283 PAY 248 

    0xa28b2b94,// 284 PAY 249 

    0xe6782cf7,// 285 PAY 250 

    0x88e19dc1,// 286 PAY 251 

    0xffeed6ae,// 287 PAY 252 

    0x231d9ee1,// 288 PAY 253 

    0xc0b43afe,// 289 PAY 254 

    0x3f113c37,// 290 PAY 255 

    0x16afc947,// 291 PAY 256 

    0xa5710d88,// 292 PAY 257 

    0x38646275,// 293 PAY 258 

    0x09182bc9,// 294 PAY 259 

    0x04bcf778,// 295 PAY 260 

    0x9a1fcaa3,// 296 PAY 261 

    0x53c7e99f,// 297 PAY 262 

    0xa14682ae,// 298 PAY 263 

    0x95000000,// 299 PAY 264 

/// STA is 1 words. 

/// STA num_pkts       : 45 

/// STA pkt_idx        : 54 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x8b 

    0x00d98b2d // 300 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt43_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8082280d,// 4 SCX   2 

    0x00003200,// 5 SCX   3 

    0x24d51bdd,// 6 SCX   4 

    0x23dbed44,// 7 SCX   5 

    0x913200e3,// 8 SCX   6 

    0x2f194679,// 9 SCX   7 

    0xa82a581d,// 10 SCX   8 

    0x0957b925,// 11 SCX   9 

    0x0df77eda,// 12 SCX  10 

    0xfc1e2cfb,// 13 SCX  11 

    0x284c7275,// 14 SCX  12 

    0x8e532434,// 15 SCX  13 

    0x930f4c2a,// 16 SCX  14 

    0x8ddf9028,// 17 SCX  15 

    0x9574eef3,// 18 SCX  16 

    0x6a8a6185,// 19 SCX  17 

    0x77e88453,// 20 SCX  18 

    0x2813036b,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1528 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1268 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1268 

/// BFD lencrypto      : 64 

/// BFD ofstcrypto     : 1008 

/// BFD (ofst+len)cry  : 1072 

/// BFD ofstiv         : 92 

/// BFD ofsticv        : 1420 

    0x000004f4,// 22 BFD   1 

    0x03f00040,// 23 BFD   2 

    0x058c005c,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00c5d7,// 25 MFM   1 

    0x7e21a448,// 26 MFM   2 

    0xd65140cc,// 27 MFM   3 

    0xc434be41,// 28 MFM   4 

    0x2eff5866,// 29 MFM   5 

    0x2e6880ec,// 30 MFM   6 

    0x3d8b7ef5,// 31 MFM   7 

    0xd0a4c8f0,// 32 MFM   8 

    0xa59dbe9b,// 33 MFM   9 

    0xf80c41ef,// 34 MFM  10 

    0xd42e1d34,// 35 MFM  11 

    0x9988f0aa,// 36 MFM  12 

    0x5878749c,// 37 MFM  13 

    0x96ccbc67,// 38 MFM  14 

    0xded48e7f,// 39 MFM  15 

    0x1d3c594d,// 40 MFM  16 

/// BDA is 383 words. 

/// BDA size     is 1528 (0x5f8) 

/// BDA id       is 0x6967 

    0x05f86967,// 41 BDA   1 

/// PAY Generic Data size   : 1528 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xdc1d8359,// 42 PAY   1 

    0xbe55f8bf,// 43 PAY   2 

    0x660c8886,// 44 PAY   3 

    0x52171b52,// 45 PAY   4 

    0x7864862a,// 46 PAY   5 

    0x9560faa1,// 47 PAY   6 

    0x434cdc05,// 48 PAY   7 

    0xbfae01b3,// 49 PAY   8 

    0x2149068e,// 50 PAY   9 

    0x693628e8,// 51 PAY  10 

    0x1a03a2c9,// 52 PAY  11 

    0x2664b067,// 53 PAY  12 

    0x6c52d28d,// 54 PAY  13 

    0x49e11566,// 55 PAY  14 

    0xd34b2785,// 56 PAY  15 

    0x0bfc9322,// 57 PAY  16 

    0x456a6fbf,// 58 PAY  17 

    0x08056ccb,// 59 PAY  18 

    0x5ce283b5,// 60 PAY  19 

    0x58911d54,// 61 PAY  20 

    0x4d3bc937,// 62 PAY  21 

    0x98aebd71,// 63 PAY  22 

    0x6ea3e06e,// 64 PAY  23 

    0xb71ce636,// 65 PAY  24 

    0xe2fab29c,// 66 PAY  25 

    0x3df7c26b,// 67 PAY  26 

    0x0f0c73db,// 68 PAY  27 

    0x8482c192,// 69 PAY  28 

    0xf0e42b61,// 70 PAY  29 

    0x2b414053,// 71 PAY  30 

    0x9195124e,// 72 PAY  31 

    0x9c7af29a,// 73 PAY  32 

    0x2f0cd025,// 74 PAY  33 

    0x26884f9d,// 75 PAY  34 

    0x81a66247,// 76 PAY  35 

    0xc27c753f,// 77 PAY  36 

    0xc5d88aa2,// 78 PAY  37 

    0x50a548a7,// 79 PAY  38 

    0x87ed2011,// 80 PAY  39 

    0x65426f4f,// 81 PAY  40 

    0x5ba9a4b3,// 82 PAY  41 

    0xee680b2e,// 83 PAY  42 

    0x0e75ac5d,// 84 PAY  43 

    0x25aa18ca,// 85 PAY  44 

    0xc41a9bff,// 86 PAY  45 

    0x17bd8319,// 87 PAY  46 

    0x2ab16c8a,// 88 PAY  47 

    0x8a2ab4e6,// 89 PAY  48 

    0x40378330,// 90 PAY  49 

    0x7ed9dab7,// 91 PAY  50 

    0x64bdff1e,// 92 PAY  51 

    0xc88503c7,// 93 PAY  52 

    0x38c47548,// 94 PAY  53 

    0x44556e26,// 95 PAY  54 

    0x7ec033c7,// 96 PAY  55 

    0x1bde4307,// 97 PAY  56 

    0x92e9be8d,// 98 PAY  57 

    0x79096ca1,// 99 PAY  58 

    0x17713751,// 100 PAY  59 

    0xeb80462e,// 101 PAY  60 

    0x7996018a,// 102 PAY  61 

    0x3644601a,// 103 PAY  62 

    0x0c46a786,// 104 PAY  63 

    0x5d48aeca,// 105 PAY  64 

    0x0c963f33,// 106 PAY  65 

    0xdd778a56,// 107 PAY  66 

    0x814bb0e5,// 108 PAY  67 

    0xd7d9fb9e,// 109 PAY  68 

    0x76a00d29,// 110 PAY  69 

    0x6dbe70d6,// 111 PAY  70 

    0x66750b33,// 112 PAY  71 

    0x9d7dda0c,// 113 PAY  72 

    0x6d038823,// 114 PAY  73 

    0x42bda584,// 115 PAY  74 

    0xfdf05e5a,// 116 PAY  75 

    0xf58c5e52,// 117 PAY  76 

    0x7623c6fa,// 118 PAY  77 

    0x3ba4b31c,// 119 PAY  78 

    0xb3ee1a94,// 120 PAY  79 

    0x27d11c03,// 121 PAY  80 

    0x69f18fc1,// 122 PAY  81 

    0x1b13f111,// 123 PAY  82 

    0x4633837a,// 124 PAY  83 

    0x8c1ec001,// 125 PAY  84 

    0x845b4841,// 126 PAY  85 

    0x432a8cca,// 127 PAY  86 

    0x8ee35a2b,// 128 PAY  87 

    0x403e3dc0,// 129 PAY  88 

    0x4cbad2dd,// 130 PAY  89 

    0xf2f23ac8,// 131 PAY  90 

    0xc6b50958,// 132 PAY  91 

    0x4cf5a962,// 133 PAY  92 

    0xd5ff3190,// 134 PAY  93 

    0x2b710772,// 135 PAY  94 

    0x5c00a82c,// 136 PAY  95 

    0xaebb34ba,// 137 PAY  96 

    0x885d71c5,// 138 PAY  97 

    0x18ab1e5b,// 139 PAY  98 

    0xfda206ac,// 140 PAY  99 

    0x37a2f39e,// 141 PAY 100 

    0x6bfdacee,// 142 PAY 101 

    0xde11e19f,// 143 PAY 102 

    0xfbe0967e,// 144 PAY 103 

    0x34151043,// 145 PAY 104 

    0x2d5683b1,// 146 PAY 105 

    0x412b20ea,// 147 PAY 106 

    0xe470778d,// 148 PAY 107 

    0x758ae662,// 149 PAY 108 

    0x1fe27201,// 150 PAY 109 

    0x30a2c696,// 151 PAY 110 

    0x0519f00d,// 152 PAY 111 

    0x2ec61d54,// 153 PAY 112 

    0x1f3c4548,// 154 PAY 113 

    0x1bea883c,// 155 PAY 114 

    0xe1d5e86e,// 156 PAY 115 

    0xb1dac20f,// 157 PAY 116 

    0xc8acdd01,// 158 PAY 117 

    0x73dfb4be,// 159 PAY 118 

    0xb2626e13,// 160 PAY 119 

    0x7d3321ae,// 161 PAY 120 

    0xc03736c3,// 162 PAY 121 

    0x6f94d938,// 163 PAY 122 

    0xd6fa8325,// 164 PAY 123 

    0xedc17d0c,// 165 PAY 124 

    0x71472c2c,// 166 PAY 125 

    0x5b5995d3,// 167 PAY 126 

    0xa466a94f,// 168 PAY 127 

    0x6f4f35f4,// 169 PAY 128 

    0x07e4ff74,// 170 PAY 129 

    0x885182f0,// 171 PAY 130 

    0xf1551f72,// 172 PAY 131 

    0x623b4ca7,// 173 PAY 132 

    0x8316bcbd,// 174 PAY 133 

    0x6178c0d3,// 175 PAY 134 

    0xd571805e,// 176 PAY 135 

    0x76c63853,// 177 PAY 136 

    0xc1f32d55,// 178 PAY 137 

    0x45eec641,// 179 PAY 138 

    0x3356ddc3,// 180 PAY 139 

    0x4df7d237,// 181 PAY 140 

    0x549441f2,// 182 PAY 141 

    0xca6dd4ce,// 183 PAY 142 

    0xcf9a2eb9,// 184 PAY 143 

    0xea6a9f7b,// 185 PAY 144 

    0xaa87d01f,// 186 PAY 145 

    0x4500caac,// 187 PAY 146 

    0x825ab6e3,// 188 PAY 147 

    0xce1d670d,// 189 PAY 148 

    0x2de97bec,// 190 PAY 149 

    0xc03175e8,// 191 PAY 150 

    0xf2381677,// 192 PAY 151 

    0xdf86e029,// 193 PAY 152 

    0xa07199cf,// 194 PAY 153 

    0x901a4d64,// 195 PAY 154 

    0xc9ea1734,// 196 PAY 155 

    0x63a0832c,// 197 PAY 156 

    0xc2187975,// 198 PAY 157 

    0xe392c07b,// 199 PAY 158 

    0xd3f0418d,// 200 PAY 159 

    0xae496652,// 201 PAY 160 

    0x5cfa05dd,// 202 PAY 161 

    0xe32ba245,// 203 PAY 162 

    0xddfb8243,// 204 PAY 163 

    0x887a02b7,// 205 PAY 164 

    0xc1c72406,// 206 PAY 165 

    0xc00c5ec6,// 207 PAY 166 

    0x4b1476cd,// 208 PAY 167 

    0x67882ce8,// 209 PAY 168 

    0x6154599d,// 210 PAY 169 

    0x02dfa674,// 211 PAY 170 

    0x312cd35b,// 212 PAY 171 

    0xf9beca88,// 213 PAY 172 

    0xf3eb1b5f,// 214 PAY 173 

    0x3715e1d8,// 215 PAY 174 

    0xab66c5ed,// 216 PAY 175 

    0x2a6673e9,// 217 PAY 176 

    0x675c7345,// 218 PAY 177 

    0x56907fa7,// 219 PAY 178 

    0xa3e3c5a9,// 220 PAY 179 

    0x972339c2,// 221 PAY 180 

    0x7018cf58,// 222 PAY 181 

    0x33f31020,// 223 PAY 182 

    0xb38052ab,// 224 PAY 183 

    0x6e0a0369,// 225 PAY 184 

    0x3e52bb5f,// 226 PAY 185 

    0xc633dffc,// 227 PAY 186 

    0xb9866174,// 228 PAY 187 

    0x01c29afb,// 229 PAY 188 

    0xd51c1727,// 230 PAY 189 

    0xafdda941,// 231 PAY 190 

    0x4f1e14c6,// 232 PAY 191 

    0x04ab4c20,// 233 PAY 192 

    0x27d2800d,// 234 PAY 193 

    0x3a5ed2f7,// 235 PAY 194 

    0xb3448724,// 236 PAY 195 

    0x5942f24b,// 237 PAY 196 

    0xd1eb867a,// 238 PAY 197 

    0xc9d62c12,// 239 PAY 198 

    0x6907170e,// 240 PAY 199 

    0x36cc46da,// 241 PAY 200 

    0xeb51d04c,// 242 PAY 201 

    0x7c4191b5,// 243 PAY 202 

    0xbd856415,// 244 PAY 203 

    0x235b5b60,// 245 PAY 204 

    0x9cea6ff0,// 246 PAY 205 

    0xd5142f3c,// 247 PAY 206 

    0x4b79fb41,// 248 PAY 207 

    0x54c94f8d,// 249 PAY 208 

    0x05795462,// 250 PAY 209 

    0x0d3c162c,// 251 PAY 210 

    0xd13d3386,// 252 PAY 211 

    0xc5452200,// 253 PAY 212 

    0xd1df9d68,// 254 PAY 213 

    0xfd9ca032,// 255 PAY 214 

    0xc8461fdd,// 256 PAY 215 

    0xe4e27c42,// 257 PAY 216 

    0x303e6e4e,// 258 PAY 217 

    0x16ab7717,// 259 PAY 218 

    0xe87c65ca,// 260 PAY 219 

    0x51282b33,// 261 PAY 220 

    0x61ddd2b6,// 262 PAY 221 

    0xd9d6a15a,// 263 PAY 222 

    0xf49c0ce2,// 264 PAY 223 

    0x085d19b7,// 265 PAY 224 

    0x44a765bb,// 266 PAY 225 

    0x24320917,// 267 PAY 226 

    0xcd970788,// 268 PAY 227 

    0x1b10903d,// 269 PAY 228 

    0x3f5fbf6d,// 270 PAY 229 

    0xfe0fcde1,// 271 PAY 230 

    0x86b723d2,// 272 PAY 231 

    0x629e1d2c,// 273 PAY 232 

    0x5b74031b,// 274 PAY 233 

    0x36ab324b,// 275 PAY 234 

    0x1ad98761,// 276 PAY 235 

    0xd56fdff1,// 277 PAY 236 

    0x655abb46,// 278 PAY 237 

    0x9f91c76c,// 279 PAY 238 

    0x97f9f765,// 280 PAY 239 

    0xa06773a6,// 281 PAY 240 

    0x5bea295d,// 282 PAY 241 

    0x0db64571,// 283 PAY 242 

    0x0d01c134,// 284 PAY 243 

    0xe0f72654,// 285 PAY 244 

    0x13c8a363,// 286 PAY 245 

    0x73edf896,// 287 PAY 246 

    0x52512bb7,// 288 PAY 247 

    0xa13f8cd0,// 289 PAY 248 

    0xba224f08,// 290 PAY 249 

    0x3f1b04df,// 291 PAY 250 

    0xf404bf4a,// 292 PAY 251 

    0x9e939f5f,// 293 PAY 252 

    0x1bea6ffb,// 294 PAY 253 

    0x4cfc883e,// 295 PAY 254 

    0xf033371f,// 296 PAY 255 

    0xe35520de,// 297 PAY 256 

    0x8427263e,// 298 PAY 257 

    0xb4d5d302,// 299 PAY 258 

    0x598e7294,// 300 PAY 259 

    0x08efcc1e,// 301 PAY 260 

    0xa6bbc0bd,// 302 PAY 261 

    0x26afbc19,// 303 PAY 262 

    0xc01cd583,// 304 PAY 263 

    0x99ad6395,// 305 PAY 264 

    0xe5c719fc,// 306 PAY 265 

    0x2ff10ba4,// 307 PAY 266 

    0x5dde6406,// 308 PAY 267 

    0xd8a03295,// 309 PAY 268 

    0xb2f528ce,// 310 PAY 269 

    0xeb74914a,// 311 PAY 270 

    0x3b7b65b6,// 312 PAY 271 

    0xd6d46c7e,// 313 PAY 272 

    0x1dc3df25,// 314 PAY 273 

    0x533576af,// 315 PAY 274 

    0xb062ddbb,// 316 PAY 275 

    0x3c19d72c,// 317 PAY 276 

    0xff5cc120,// 318 PAY 277 

    0x2bde3e40,// 319 PAY 278 

    0xd73925ff,// 320 PAY 279 

    0x283d53db,// 321 PAY 280 

    0x243e679f,// 322 PAY 281 

    0x06267c4c,// 323 PAY 282 

    0xcc3fc832,// 324 PAY 283 

    0x6ab19b20,// 325 PAY 284 

    0x9bea7b7b,// 326 PAY 285 

    0xec463d32,// 327 PAY 286 

    0x27de10ef,// 328 PAY 287 

    0x216294d0,// 329 PAY 288 

    0x2d44c85d,// 330 PAY 289 

    0x4cc0be0e,// 331 PAY 290 

    0x11e5e0cc,// 332 PAY 291 

    0xedc806a4,// 333 PAY 292 

    0xd0fa3872,// 334 PAY 293 

    0x461ac1ed,// 335 PAY 294 

    0xe0952e7c,// 336 PAY 295 

    0x275b7abb,// 337 PAY 296 

    0x90f2594f,// 338 PAY 297 

    0xd48fb6d2,// 339 PAY 298 

    0x9c27669e,// 340 PAY 299 

    0x96c62c88,// 341 PAY 300 

    0x3f79fca1,// 342 PAY 301 

    0xd23c3d81,// 343 PAY 302 

    0x7cbfde1c,// 344 PAY 303 

    0x845d54be,// 345 PAY 304 

    0xcce8d0db,// 346 PAY 305 

    0x5fbf8e5f,// 347 PAY 306 

    0x63e806e4,// 348 PAY 307 

    0x9eb55e2c,// 349 PAY 308 

    0xc5741310,// 350 PAY 309 

    0x581d3e38,// 351 PAY 310 

    0x49b4023a,// 352 PAY 311 

    0xf647c13c,// 353 PAY 312 

    0x09665316,// 354 PAY 313 

    0x037a93e1,// 355 PAY 314 

    0x49ad74ba,// 356 PAY 315 

    0xd2f08996,// 357 PAY 316 

    0x2fe0ad91,// 358 PAY 317 

    0x4cf73c07,// 359 PAY 318 

    0x3bf0fa97,// 360 PAY 319 

    0x80d6760b,// 361 PAY 320 

    0xf921e9fa,// 362 PAY 321 

    0xc2a4e26a,// 363 PAY 322 

    0x04471acb,// 364 PAY 323 

    0xd9d2f0cd,// 365 PAY 324 

    0x80aea640,// 366 PAY 325 

    0xa73a80e3,// 367 PAY 326 

    0xc7c2e3c7,// 368 PAY 327 

    0x5437e010,// 369 PAY 328 

    0xeb87a192,// 370 PAY 329 

    0xe6c8f8c5,// 371 PAY 330 

    0x641d2f7e,// 372 PAY 331 

    0xc1e619cd,// 373 PAY 332 

    0x58dd436c,// 374 PAY 333 

    0x4ecac045,// 375 PAY 334 

    0x443ab87e,// 376 PAY 335 

    0x442e698b,// 377 PAY 336 

    0x7c0d295b,// 378 PAY 337 

    0xe789c0b3,// 379 PAY 338 

    0x0594ee20,// 380 PAY 339 

    0xaf2fe2de,// 381 PAY 340 

    0x8d91dfea,// 382 PAY 341 

    0x6f91d3be,// 383 PAY 342 

    0xd7c7df43,// 384 PAY 343 

    0x866352f1,// 385 PAY 344 

    0x67b441a4,// 386 PAY 345 

    0x0beed0fa,// 387 PAY 346 

    0x18806012,// 388 PAY 347 

    0xa8836d72,// 389 PAY 348 

    0xb18ea763,// 390 PAY 349 

    0xa1cc8c44,// 391 PAY 350 

    0x956b7b7f,// 392 PAY 351 

    0x61cfa26e,// 393 PAY 352 

    0x55d117a6,// 394 PAY 353 

    0x70e24eb8,// 395 PAY 354 

    0x8f52e7c6,// 396 PAY 355 

    0xef1bec13,// 397 PAY 356 

    0x7b210ca9,// 398 PAY 357 

    0xe2ab2c4a,// 399 PAY 358 

    0x1e7c7bbb,// 400 PAY 359 

    0x975636e6,// 401 PAY 360 

    0x157ef952,// 402 PAY 361 

    0x601b8b3d,// 403 PAY 362 

    0x3d2152db,// 404 PAY 363 

    0xb36e799a,// 405 PAY 364 

    0x15e2cfa1,// 406 PAY 365 

    0x924d24bc,// 407 PAY 366 

    0x38f421e1,// 408 PAY 367 

    0xbda53637,// 409 PAY 368 

    0xa4635b9a,// 410 PAY 369 

    0xc262090a,// 411 PAY 370 

    0xcfcd1772,// 412 PAY 371 

    0xb0e24424,// 413 PAY 372 

    0x7bd9f802,// 414 PAY 373 

    0x046fb13e,// 415 PAY 374 

    0x7f4e3a04,// 416 PAY 375 

    0xb4ff1aae,// 417 PAY 376 

    0xc2ad5801,// 418 PAY 377 

    0x9a650247,// 419 PAY 378 

    0xda2f72be,// 420 PAY 379 

    0x2f094ae8,// 421 PAY 380 

    0x884679b1,// 422 PAY 381 

    0xadd602e3,// 423 PAY 382 

/// STA is 1 words. 

/// STA num_pkts       : 133 

/// STA pkt_idx        : 232 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x79 

    0x03a07985 // 424 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt44_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x808628dc,// 4 SCX   2 

    0x000011c4,// 5 SCX   3 

    0xcc81fa91,// 6 SCX   4 

    0xa45d9808,// 7 SCX   5 

    0x2e871ba5,// 8 SCX   6 

    0x5d3466e3,// 9 SCX   7 

    0x8ac5eb98,// 10 SCX   8 

    0x231ae11a,// 11 SCX   9 

    0xd532d90f,// 12 SCX  10 

    0xff690d8a,// 13 SCX  11 

    0x56719ae1,// 14 SCX  12 

    0x79197cdf,// 15 SCX  13 

    0x7ac966cc,// 16 SCX  14 

    0xf5a721ce,// 17 SCX  15 

    0xab838e57,// 18 SCX  16 

    0x5375ab82,// 19 SCX  17 

    0xf9795535,// 20 SCX  18 

    0x0a823628,// 21 SCX  19 

    0xe9c6425f,// 22 SCX  20 

    0x95582069,// 23 SCX  21 

    0x16cec2d1,// 24 SCX  22 

    0x46c6019a,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1710 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 200 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 200 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 92 

/// BFD (ofst+len)cry  : 124 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 652 

    0x000000c8,// 26 BFD   1 

    0x005c0020,// 27 BFD   2 

    0x028c0010,// 28 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : b 

    0x0b00c504,// 29 MFM   1 

    0x8ff53cc0,// 30 MFM   2 

/// BDA is 429 words. 

/// BDA size     is 1710 (0x6ae) 

/// BDA id       is 0x4bfd 

    0x06ae4bfd,// 31 BDA   1 

/// PAY Generic Data size   : 1710 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xe7f2fad9,// 32 PAY   1 

    0xc254e694,// 33 PAY   2 

    0xfa0a9718,// 34 PAY   3 

    0xf5f1fa08,// 35 PAY   4 

    0x8205e728,// 36 PAY   5 

    0xb4a5c2fa,// 37 PAY   6 

    0x6277e23a,// 38 PAY   7 

    0x78015fd9,// 39 PAY   8 

    0xc1d3fec0,// 40 PAY   9 

    0x1d6561ac,// 41 PAY  10 

    0x968bbd3b,// 42 PAY  11 

    0x7124bc3c,// 43 PAY  12 

    0xa63b1cde,// 44 PAY  13 

    0x94a21e6c,// 45 PAY  14 

    0xc1afaa9f,// 46 PAY  15 

    0x83ef8487,// 47 PAY  16 

    0x0518dad7,// 48 PAY  17 

    0x22eabdcb,// 49 PAY  18 

    0x82ea3e4e,// 50 PAY  19 

    0x85200a74,// 51 PAY  20 

    0x5ccff99c,// 52 PAY  21 

    0x8dc2674f,// 53 PAY  22 

    0xf198d599,// 54 PAY  23 

    0x9976b608,// 55 PAY  24 

    0x1cdb5ca8,// 56 PAY  25 

    0x8165ea03,// 57 PAY  26 

    0xa8692f23,// 58 PAY  27 

    0xe1dde82e,// 59 PAY  28 

    0xab1d6339,// 60 PAY  29 

    0x5e095bbd,// 61 PAY  30 

    0x27cd8748,// 62 PAY  31 

    0xa02af2cb,// 63 PAY  32 

    0xdd45dc04,// 64 PAY  33 

    0x563388cb,// 65 PAY  34 

    0x53923819,// 66 PAY  35 

    0x66d8c574,// 67 PAY  36 

    0xbbfe8316,// 68 PAY  37 

    0xd412faa3,// 69 PAY  38 

    0x78006e13,// 70 PAY  39 

    0xd47642f1,// 71 PAY  40 

    0xfaba300d,// 72 PAY  41 

    0xd771d6ed,// 73 PAY  42 

    0x5a4aa526,// 74 PAY  43 

    0x42759087,// 75 PAY  44 

    0x72db9f8a,// 76 PAY  45 

    0x2c494c8f,// 77 PAY  46 

    0xfbe304fc,// 78 PAY  47 

    0x85317f98,// 79 PAY  48 

    0xfa2c4e67,// 80 PAY  49 

    0x21ca5177,// 81 PAY  50 

    0xaa726d43,// 82 PAY  51 

    0x639e6d65,// 83 PAY  52 

    0xd5b760f9,// 84 PAY  53 

    0xd37d5dff,// 85 PAY  54 

    0xbb158f3e,// 86 PAY  55 

    0xd0382aec,// 87 PAY  56 

    0xb1b8c849,// 88 PAY  57 

    0x1a079cd2,// 89 PAY  58 

    0x41cd4c3f,// 90 PAY  59 

    0xd1b9b46b,// 91 PAY  60 

    0x119dd9cc,// 92 PAY  61 

    0x987f7da7,// 93 PAY  62 

    0x0dcb1ba2,// 94 PAY  63 

    0xec9d09a0,// 95 PAY  64 

    0x13f9542a,// 96 PAY  65 

    0xbb8a2142,// 97 PAY  66 

    0x41fd4869,// 98 PAY  67 

    0x3cd80b50,// 99 PAY  68 

    0x4da2d21b,// 100 PAY  69 

    0x4ec0d0d5,// 101 PAY  70 

    0x0ae0ac18,// 102 PAY  71 

    0x3eba54c0,// 103 PAY  72 

    0x14fc3c6b,// 104 PAY  73 

    0x374a13fd,// 105 PAY  74 

    0x6b329a38,// 106 PAY  75 

    0x635c095a,// 107 PAY  76 

    0x7532017b,// 108 PAY  77 

    0x595d3b46,// 109 PAY  78 

    0x91ea619a,// 110 PAY  79 

    0x283b2d84,// 111 PAY  80 

    0x9fd4c7e0,// 112 PAY  81 

    0x1521d102,// 113 PAY  82 

    0x39d93160,// 114 PAY  83 

    0x419a0297,// 115 PAY  84 

    0xddecb87b,// 116 PAY  85 

    0xa18340a1,// 117 PAY  86 

    0x465c27ad,// 118 PAY  87 

    0x28df2ab2,// 119 PAY  88 

    0x7ecca408,// 120 PAY  89 

    0x956f428c,// 121 PAY  90 

    0xd883479e,// 122 PAY  91 

    0x71753589,// 123 PAY  92 

    0x9e3d3776,// 124 PAY  93 

    0x8a0e7cb0,// 125 PAY  94 

    0xe53b12cc,// 126 PAY  95 

    0x6ff5e1bb,// 127 PAY  96 

    0xd635bd88,// 128 PAY  97 

    0xde364f54,// 129 PAY  98 

    0xd585270d,// 130 PAY  99 

    0x4dc70fb2,// 131 PAY 100 

    0x95dd266e,// 132 PAY 101 

    0xf1abb4ee,// 133 PAY 102 

    0xd800caad,// 134 PAY 103 

    0xb61a45be,// 135 PAY 104 

    0x522599a7,// 136 PAY 105 

    0x3398196e,// 137 PAY 106 

    0xd03afd7f,// 138 PAY 107 

    0x23b6589a,// 139 PAY 108 

    0x9b376c43,// 140 PAY 109 

    0x0a784306,// 141 PAY 110 

    0x1ea97b73,// 142 PAY 111 

    0x9cb29699,// 143 PAY 112 

    0x2abb6500,// 144 PAY 113 

    0x2627ef20,// 145 PAY 114 

    0x39f97703,// 146 PAY 115 

    0xfbee7fcf,// 147 PAY 116 

    0xa321978d,// 148 PAY 117 

    0x82224399,// 149 PAY 118 

    0xd6776453,// 150 PAY 119 

    0x9cf96546,// 151 PAY 120 

    0x34cb3f38,// 152 PAY 121 

    0xce2595c8,// 153 PAY 122 

    0x77a55970,// 154 PAY 123 

    0x3ce9f722,// 155 PAY 124 

    0x668fbab2,// 156 PAY 125 

    0x3149e77a,// 157 PAY 126 

    0x46d4c4c1,// 158 PAY 127 

    0x34415e85,// 159 PAY 128 

    0x064805df,// 160 PAY 129 

    0x9b12b109,// 161 PAY 130 

    0x823c33de,// 162 PAY 131 

    0xf5864af8,// 163 PAY 132 

    0xf8e4a4fa,// 164 PAY 133 

    0xbcc1a968,// 165 PAY 134 

    0x949c8b8f,// 166 PAY 135 

    0x84438a6b,// 167 PAY 136 

    0x4933a95d,// 168 PAY 137 

    0x84f735ab,// 169 PAY 138 

    0xfb52e4ed,// 170 PAY 139 

    0x1f03ecb9,// 171 PAY 140 

    0xdad4ce1d,// 172 PAY 141 

    0xb557f6ff,// 173 PAY 142 

    0xf7d3dbf8,// 174 PAY 143 

    0xdc80c6c7,// 175 PAY 144 

    0x883fe9e5,// 176 PAY 145 

    0xea181420,// 177 PAY 146 

    0x5f280d6e,// 178 PAY 147 

    0x806c29f4,// 179 PAY 148 

    0xd6716c97,// 180 PAY 149 

    0xd8b9c904,// 181 PAY 150 

    0x3cfdb2c6,// 182 PAY 151 

    0x3235d882,// 183 PAY 152 

    0xf1fb4399,// 184 PAY 153 

    0x54377589,// 185 PAY 154 

    0xfb0a0c29,// 186 PAY 155 

    0x9c47a9a9,// 187 PAY 156 

    0x88015daa,// 188 PAY 157 

    0xa5653269,// 189 PAY 158 

    0x121fc04b,// 190 PAY 159 

    0x6afc289e,// 191 PAY 160 

    0x327390fd,// 192 PAY 161 

    0x715ecb16,// 193 PAY 162 

    0x247d789c,// 194 PAY 163 

    0x96078be9,// 195 PAY 164 

    0x3b0939d9,// 196 PAY 165 

    0x4c6c0302,// 197 PAY 166 

    0xfc82295f,// 198 PAY 167 

    0xc49fef2d,// 199 PAY 168 

    0x6b358a94,// 200 PAY 169 

    0xf163f3c4,// 201 PAY 170 

    0xf1b71cfa,// 202 PAY 171 

    0x812f1c7c,// 203 PAY 172 

    0xaafbd9c6,// 204 PAY 173 

    0x0e22c53d,// 205 PAY 174 

    0x552635a1,// 206 PAY 175 

    0x2ebd98d6,// 207 PAY 176 

    0xa0dc7c26,// 208 PAY 177 

    0xad3af7a3,// 209 PAY 178 

    0x1d398ab0,// 210 PAY 179 

    0x7f0aa8d3,// 211 PAY 180 

    0x8cb2d444,// 212 PAY 181 

    0x56e61478,// 213 PAY 182 

    0xcb9ff1b4,// 214 PAY 183 

    0xe491a170,// 215 PAY 184 

    0xa484d6a1,// 216 PAY 185 

    0xbfb8e9f1,// 217 PAY 186 

    0xefe45ed7,// 218 PAY 187 

    0xe96606e5,// 219 PAY 188 

    0x1c2bcb80,// 220 PAY 189 

    0x77299da6,// 221 PAY 190 

    0x8b955f28,// 222 PAY 191 

    0x659bca21,// 223 PAY 192 

    0x740af9fc,// 224 PAY 193 

    0x624df3cb,// 225 PAY 194 

    0xb9f4e3cd,// 226 PAY 195 

    0xbbdbb2c8,// 227 PAY 196 

    0x0166c7a9,// 228 PAY 197 

    0x05fc3819,// 229 PAY 198 

    0x6ee26c60,// 230 PAY 199 

    0x6c0fe291,// 231 PAY 200 

    0x36d618ce,// 232 PAY 201 

    0xd30cb319,// 233 PAY 202 

    0xbeabe9b4,// 234 PAY 203 

    0x85972563,// 235 PAY 204 

    0x8b8176ba,// 236 PAY 205 

    0x21bb0df0,// 237 PAY 206 

    0xea141529,// 238 PAY 207 

    0x42f7284a,// 239 PAY 208 

    0x3ebcf7fd,// 240 PAY 209 

    0xe00bcbe2,// 241 PAY 210 

    0x302aea4b,// 242 PAY 211 

    0x4668000b,// 243 PAY 212 

    0xc1bbdad3,// 244 PAY 213 

    0xa01763a4,// 245 PAY 214 

    0x17cb745f,// 246 PAY 215 

    0x4599fefe,// 247 PAY 216 

    0xca472bc0,// 248 PAY 217 

    0x0df09fd4,// 249 PAY 218 

    0x9a20e16c,// 250 PAY 219 

    0xba5b95e1,// 251 PAY 220 

    0x38bb8733,// 252 PAY 221 

    0x5311f613,// 253 PAY 222 

    0x0723b45e,// 254 PAY 223 

    0x1814788d,// 255 PAY 224 

    0xb2ec8525,// 256 PAY 225 

    0xb0759549,// 257 PAY 226 

    0xc2f6a0d8,// 258 PAY 227 

    0x4e083d3e,// 259 PAY 228 

    0x26919160,// 260 PAY 229 

    0x750811d2,// 261 PAY 230 

    0x53b9c83f,// 262 PAY 231 

    0x742b1718,// 263 PAY 232 

    0xe38bef83,// 264 PAY 233 

    0x3287fe1f,// 265 PAY 234 

    0x681270bf,// 266 PAY 235 

    0x994d5a1a,// 267 PAY 236 

    0xfc258e25,// 268 PAY 237 

    0x48ba298a,// 269 PAY 238 

    0x63374049,// 270 PAY 239 

    0xa529e83c,// 271 PAY 240 

    0x381b1d05,// 272 PAY 241 

    0x5fe36c0d,// 273 PAY 242 

    0x8f8691fb,// 274 PAY 243 

    0x0b392e2a,// 275 PAY 244 

    0x136b45a1,// 276 PAY 245 

    0xec65e1a6,// 277 PAY 246 

    0xf587bce4,// 278 PAY 247 

    0x57215e56,// 279 PAY 248 

    0x90e577a6,// 280 PAY 249 

    0x7d53e58b,// 281 PAY 250 

    0x9e44ea38,// 282 PAY 251 

    0x4163ab41,// 283 PAY 252 

    0xd39507fe,// 284 PAY 253 

    0xb167b545,// 285 PAY 254 

    0x1eb7822f,// 286 PAY 255 

    0x08613286,// 287 PAY 256 

    0x62dbb3e2,// 288 PAY 257 

    0x9895f31b,// 289 PAY 258 

    0x5bff0f6a,// 290 PAY 259 

    0x3237822e,// 291 PAY 260 

    0xf6ad8234,// 292 PAY 261 

    0xf9390c0e,// 293 PAY 262 

    0x2e5929c7,// 294 PAY 263 

    0x0b132c26,// 295 PAY 264 

    0x15fa5976,// 296 PAY 265 

    0x5752610a,// 297 PAY 266 

    0xd2cd57fe,// 298 PAY 267 

    0xb738e330,// 299 PAY 268 

    0xe3f1c510,// 300 PAY 269 

    0xb09b8c53,// 301 PAY 270 

    0x6989f0c2,// 302 PAY 271 

    0x42ed2841,// 303 PAY 272 

    0x9513d725,// 304 PAY 273 

    0x8f079ebb,// 305 PAY 274 

    0x70c18484,// 306 PAY 275 

    0xe3a4f221,// 307 PAY 276 

    0xcc7b35fd,// 308 PAY 277 

    0xdfa4be44,// 309 PAY 278 

    0xf2e2ef8b,// 310 PAY 279 

    0xd01a7da5,// 311 PAY 280 

    0x9f863055,// 312 PAY 281 

    0x27974d79,// 313 PAY 282 

    0xe39d03ba,// 314 PAY 283 

    0xadd08424,// 315 PAY 284 

    0x3eb74235,// 316 PAY 285 

    0x94931db9,// 317 PAY 286 

    0xebe1fb9c,// 318 PAY 287 

    0x51564a33,// 319 PAY 288 

    0x4f1e8f10,// 320 PAY 289 

    0x9adb6729,// 321 PAY 290 

    0x2c1855a0,// 322 PAY 291 

    0x4dd16a2f,// 323 PAY 292 

    0xc0cf4c01,// 324 PAY 293 

    0x6402f952,// 325 PAY 294 

    0x2d340626,// 326 PAY 295 

    0x2be55ce9,// 327 PAY 296 

    0x1d5fc871,// 328 PAY 297 

    0x6726291a,// 329 PAY 298 

    0x35d575db,// 330 PAY 299 

    0xf21c329e,// 331 PAY 300 

    0x9eef0a64,// 332 PAY 301 

    0x97ad4b69,// 333 PAY 302 

    0xa1b98fad,// 334 PAY 303 

    0xf5df7cbf,// 335 PAY 304 

    0x5db329b8,// 336 PAY 305 

    0x8a747a86,// 337 PAY 306 

    0xb89bec9c,// 338 PAY 307 

    0x8a8bb98c,// 339 PAY 308 

    0xc125cfff,// 340 PAY 309 

    0x294a8136,// 341 PAY 310 

    0x7acdc088,// 342 PAY 311 

    0x8b9661e9,// 343 PAY 312 

    0x156417a2,// 344 PAY 313 

    0x40d0cd7c,// 345 PAY 314 

    0x8189e0fb,// 346 PAY 315 

    0xb1899ef9,// 347 PAY 316 

    0xa5932e72,// 348 PAY 317 

    0xe7752aff,// 349 PAY 318 

    0x25c40b05,// 350 PAY 319 

    0xa63ea391,// 351 PAY 320 

    0x1b3c79a0,// 352 PAY 321 

    0x932e3725,// 353 PAY 322 

    0x8685bf70,// 354 PAY 323 

    0x3731ebad,// 355 PAY 324 

    0x2936c00d,// 356 PAY 325 

    0x84b0093c,// 357 PAY 326 

    0xc8b1bc37,// 358 PAY 327 

    0x110f6eab,// 359 PAY 328 

    0x4d412888,// 360 PAY 329 

    0x5975b42f,// 361 PAY 330 

    0x1cdee017,// 362 PAY 331 

    0x1a5dcb44,// 363 PAY 332 

    0x2bd76c9c,// 364 PAY 333 

    0x495bdf76,// 365 PAY 334 

    0x0b149227,// 366 PAY 335 

    0xae77aa36,// 367 PAY 336 

    0x882c0131,// 368 PAY 337 

    0x126a121c,// 369 PAY 338 

    0xa70b694e,// 370 PAY 339 

    0x6301bca2,// 371 PAY 340 

    0xf6f9a14f,// 372 PAY 341 

    0x2e0ab08b,// 373 PAY 342 

    0x1b641bb8,// 374 PAY 343 

    0x01fbc37a,// 375 PAY 344 

    0xb33d3c71,// 376 PAY 345 

    0x766d7078,// 377 PAY 346 

    0xce209f72,// 378 PAY 347 

    0x147a4422,// 379 PAY 348 

    0xd1b39622,// 380 PAY 349 

    0xc2997742,// 381 PAY 350 

    0x7deaeaea,// 382 PAY 351 

    0x4fbdcad0,// 383 PAY 352 

    0xf24f8dd2,// 384 PAY 353 

    0x5f573eda,// 385 PAY 354 

    0x24c41e45,// 386 PAY 355 

    0x3343fdd1,// 387 PAY 356 

    0x43216072,// 388 PAY 357 

    0x7473ffa2,// 389 PAY 358 

    0x02f778f5,// 390 PAY 359 

    0x39668b08,// 391 PAY 360 

    0x129c82de,// 392 PAY 361 

    0x429d2373,// 393 PAY 362 

    0xd9b2a84d,// 394 PAY 363 

    0x30d3147d,// 395 PAY 364 

    0x3b4fbba4,// 396 PAY 365 

    0x08df8703,// 397 PAY 366 

    0xd41f69ff,// 398 PAY 367 

    0xe851f8f9,// 399 PAY 368 

    0x6324a3a6,// 400 PAY 369 

    0x10f4a04b,// 401 PAY 370 

    0xd362e932,// 402 PAY 371 

    0x3e701a4c,// 403 PAY 372 

    0x2e054279,// 404 PAY 373 

    0xbde66965,// 405 PAY 374 

    0xfe189f92,// 406 PAY 375 

    0x10374f3e,// 407 PAY 376 

    0xd37c0295,// 408 PAY 377 

    0xe8cde467,// 409 PAY 378 

    0xb2f16f0b,// 410 PAY 379 

    0x5c472bbd,// 411 PAY 380 

    0x75dab419,// 412 PAY 381 

    0x1f6be4db,// 413 PAY 382 

    0x4c4d435e,// 414 PAY 383 

    0xce797b2a,// 415 PAY 384 

    0xcf0835b6,// 416 PAY 385 

    0x408b4db0,// 417 PAY 386 

    0x65476bc0,// 418 PAY 387 

    0xca9617d4,// 419 PAY 388 

    0xb2fdf489,// 420 PAY 389 

    0x974b4e70,// 421 PAY 390 

    0x9f9871f6,// 422 PAY 391 

    0xe530fcf2,// 423 PAY 392 

    0x2b6d3af8,// 424 PAY 393 

    0x71615d53,// 425 PAY 394 

    0x3ebddce5,// 426 PAY 395 

    0x3db1272f,// 427 PAY 396 

    0x980e882a,// 428 PAY 397 

    0xce3e0a55,// 429 PAY 398 

    0xbbb8c9ab,// 430 PAY 399 

    0xe753984a,// 431 PAY 400 

    0x44caae51,// 432 PAY 401 

    0x1ce02ffd,// 433 PAY 402 

    0x276402d3,// 434 PAY 403 

    0x5c7602f6,// 435 PAY 404 

    0x4cac57a9,// 436 PAY 405 

    0x76e956d8,// 437 PAY 406 

    0xcebe5135,// 438 PAY 407 

    0xe6bc8ad9,// 439 PAY 408 

    0xddecfb90,// 440 PAY 409 

    0x4e277179,// 441 PAY 410 

    0x4eeb03e6,// 442 PAY 411 

    0xbebc5caa,// 443 PAY 412 

    0x2de4b81c,// 444 PAY 413 

    0xc04315c5,// 445 PAY 414 

    0x05354e84,// 446 PAY 415 

    0x4aaca03b,// 447 PAY 416 

    0xdda241af,// 448 PAY 417 

    0x51a8705c,// 449 PAY 418 

    0x2ffecc7b,// 450 PAY 419 

    0xf6fdcda1,// 451 PAY 420 

    0x7fe34360,// 452 PAY 421 

    0x056dda1b,// 453 PAY 422 

    0x716e3c4a,// 454 PAY 423 

    0x9bf03720,// 455 PAY 424 

    0xea017123,// 456 PAY 425 

    0x03f2040e,// 457 PAY 426 

    0x3783f20e,// 458 PAY 427 

    0x93660000,// 459 PAY 428 

/// STA is 1 words. 

/// STA num_pkts       : 13 

/// STA pkt_idx        : 80 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x9a 

    0x01419a0d // 460 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt45_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x01 

/// ECH pdu_tag        : 0x00 

    0x00010000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000015,// 3 SCX   1 

    0x809128fc,// 4 SCX   2 

    0x000033c2,// 5 SCX   3 

    0x47181913,// 6 SCX   4 

    0x554e1187,// 7 SCX   5 

    0x4052547a,// 8 SCX   6 

    0x867b9492,// 9 SCX   7 

    0x3d8a6fee,// 10 SCX   8 

    0x387601e1,// 11 SCX   9 

    0xed32d5a9,// 12 SCX  10 

    0xace4b536,// 13 SCX  11 

    0x0be1a228,// 14 SCX  12 

    0x56a87430,// 15 SCX  13 

    0x9fa765ce,// 16 SCX  14 

    0x65eb2fa1,// 17 SCX  15 

    0xecfc5c15,// 18 SCX  16 

    0x30159e0f,// 19 SCX  17 

    0x431bf231,// 20 SCX  18 

    0x0853598b,// 21 SCX  19 

    0x814f0ec3,// 22 SCX  20 

    0x9121e575,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 210 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 44 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 44 

/// BFD lencrypto      : 4 

/// BFD ofstcrypto     : 36 

/// BFD (ofst+len)cry  : 40 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 172 

    0x0000002c,// 24 BFD   1 

    0x00240004,// 25 BFD   2 

    0x00ac000c,// 26 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 1 

    0x01000000,// 27 MFM   1 

/// BDA is 54 words. 

/// BDA size     is 210 (0xd2) 

/// BDA id       is 0xae4b 

    0x00d2ae4b,// 28 BDA   1 

/// PAY Generic Data size   : 210 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x3d04f01d,// 29 PAY   1 

    0x41fe8e08,// 30 PAY   2 

    0xf0c4119f,// 31 PAY   3 

    0x239e2323,// 32 PAY   4 

    0xe75e58fb,// 33 PAY   5 

    0x557d4b75,// 34 PAY   6 

    0xe9a1251a,// 35 PAY   7 

    0x3c9dfee9,// 36 PAY   8 

    0x5342a492,// 37 PAY   9 

    0x3bfbef0f,// 38 PAY  10 

    0x44ac4a07,// 39 PAY  11 

    0xe0aa4f21,// 40 PAY  12 

    0xaff1f509,// 41 PAY  13 

    0x7ef1f196,// 42 PAY  14 

    0x28c82972,// 43 PAY  15 

    0xa6254e3d,// 44 PAY  16 

    0x8a4ae460,// 45 PAY  17 

    0x280f207f,// 46 PAY  18 

    0x4ca83b89,// 47 PAY  19 

    0xcc29b95e,// 48 PAY  20 

    0x5d301794,// 49 PAY  21 

    0xcb84d549,// 50 PAY  22 

    0x9857c528,// 51 PAY  23 

    0x53d131dd,// 52 PAY  24 

    0x7d83ec2f,// 53 PAY  25 

    0xb2385766,// 54 PAY  26 

    0xf302e666,// 55 PAY  27 

    0xda49731d,// 56 PAY  28 

    0xc72e9786,// 57 PAY  29 

    0x4f920ad6,// 58 PAY  30 

    0x6e656425,// 59 PAY  31 

    0x91a8527b,// 60 PAY  32 

    0x1a47a25d,// 61 PAY  33 

    0x76079076,// 62 PAY  34 

    0x55855a23,// 63 PAY  35 

    0xb650730f,// 64 PAY  36 

    0xb71e8d1e,// 65 PAY  37 

    0x96f0dec4,// 66 PAY  38 

    0x6be294fd,// 67 PAY  39 

    0x7b39a2bf,// 68 PAY  40 

    0x5794de0d,// 69 PAY  41 

    0x45adb115,// 70 PAY  42 

    0x2b01481d,// 71 PAY  43 

    0x3b9aca3c,// 72 PAY  44 

    0x10147afd,// 73 PAY  45 

    0x9a1f7dad,// 74 PAY  46 

    0x84cc36ea,// 75 PAY  47 

    0xa08481b9,// 76 PAY  48 

    0x9d731b74,// 77 PAY  49 

    0xc21f2675,// 78 PAY  50 

    0xe5460c2e,// 79 PAY  51 

    0x61e9c16e,// 80 PAY  52 

    0x517c0000,// 81 PAY  53 

/// STA is 1 words. 

/// STA num_pkts       : 173 

/// STA pkt_idx        : 179 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x3f 

    0x02cd3fad // 82 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt46_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x809228c9,// 4 SCX   2 

    0x00007482,// 5 SCX   3 

    0x7de5e8d4,// 6 SCX   4 

    0x41b77082,// 7 SCX   5 

    0xcb31e795,// 8 SCX   6 

    0x6b93df1c,// 9 SCX   7 

    0xa850d0e7,// 10 SCX   8 

    0x4abff44a,// 11 SCX   9 

    0xc3b173ad,// 12 SCX  10 

    0xd0b9281d,// 13 SCX  11 

    0xb963115f,// 14 SCX  12 

    0x5c4a2aa6,// 15 SCX  13 

    0xbc1d97cd,// 16 SCX  14 

    0xb9c96f89,// 17 SCX  15 

    0xc641d8f0,// 18 SCX  16 

    0x21a4f0c5,// 19 SCX  17 

    0x6df460d0,// 20 SCX  18 

    0xddf46c1b,// 21 SCX  19 

    0xc1970402,// 22 SCX  20 

    0xf3b2cfb7,// 23 SCX  21 

    0x733c676e,// 24 SCX  22 

    0xa37dfd2c,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 941 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 870 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 870 

/// BFD lencrypto      : 440 

/// BFD ofstcrypto     : 16 

/// BFD (ofst+len)cry  : 456 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 896 

    0x00000366,// 26 BFD   1 

    0x001001b8,// 27 BFD   2 

    0x03800000,// 28 BFD   3 

/// MFM is 12 words. 

/// MFM vldnibs        : 55 

    0x5500ade2,// 29 MFM   1 

    0xc39a90fb,// 30 MFM   2 

    0x7b3cd81b,// 31 MFM   3 

    0xc22c4009,// 32 MFM   4 

    0x39118b9a,// 33 MFM   5 

    0xe64480e2,// 34 MFM   6 

    0xcdb8a42d,// 35 MFM   7 

    0x89e63f8f,// 36 MFM   8 

    0x67315ba0,// 37 MFM   9 

    0xc918084a,// 38 MFM  10 

    0x5924bcca,// 39 MFM  11 

    0x30000000,// 40 MFM  12 

/// BDA is 237 words. 

/// BDA size     is 941 (0x3ad) 

/// BDA id       is 0x3c4b 

    0x03ad3c4b,// 41 BDA   1 

/// PAY Generic Data size   : 941 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x0b32d726,// 42 PAY   1 

    0x21cf0bc4,// 43 PAY   2 

    0x74146097,// 44 PAY   3 

    0x8440b6e5,// 45 PAY   4 

    0x2303601e,// 46 PAY   5 

    0x2a1907b8,// 47 PAY   6 

    0x9d5f899a,// 48 PAY   7 

    0xa584c753,// 49 PAY   8 

    0xb918ada7,// 50 PAY   9 

    0xb87507ed,// 51 PAY  10 

    0x3f02626d,// 52 PAY  11 

    0x5d6a9afd,// 53 PAY  12 

    0x3e4cb0ec,// 54 PAY  13 

    0x7a591ef4,// 55 PAY  14 

    0x7d321ac4,// 56 PAY  15 

    0x7f530615,// 57 PAY  16 

    0x1ba96f5b,// 58 PAY  17 

    0x403e74c2,// 59 PAY  18 

    0xe4bc4c49,// 60 PAY  19 

    0xbe5905fd,// 61 PAY  20 

    0x46b22729,// 62 PAY  21 

    0x6c5c15a6,// 63 PAY  22 

    0xe60740df,// 64 PAY  23 

    0x5890056d,// 65 PAY  24 

    0x73982a7c,// 66 PAY  25 

    0xe8fb1a9d,// 67 PAY  26 

    0xd3c92ae4,// 68 PAY  27 

    0x32ccb03a,// 69 PAY  28 

    0xa52ec185,// 70 PAY  29 

    0x535ace98,// 71 PAY  30 

    0x3a7106d5,// 72 PAY  31 

    0x12ba0fd8,// 73 PAY  32 

    0x9cb69d06,// 74 PAY  33 

    0x7a93598d,// 75 PAY  34 

    0xfe4fb1c0,// 76 PAY  35 

    0x5471768a,// 77 PAY  36 

    0xf23aae2e,// 78 PAY  37 

    0xfd9aae14,// 79 PAY  38 

    0x7a6c1924,// 80 PAY  39 

    0xa7a92f71,// 81 PAY  40 

    0x96aa44a7,// 82 PAY  41 

    0x3394fa65,// 83 PAY  42 

    0xee9914d5,// 84 PAY  43 

    0x1ec38070,// 85 PAY  44 

    0xd6dd1691,// 86 PAY  45 

    0x65b26e66,// 87 PAY  46 

    0x25835135,// 88 PAY  47 

    0xbf69c6fa,// 89 PAY  48 

    0x1323578a,// 90 PAY  49 

    0xcf2c9e2f,// 91 PAY  50 

    0x508e880a,// 92 PAY  51 

    0x94cf7a9d,// 93 PAY  52 

    0x46c5cbbc,// 94 PAY  53 

    0x464243d5,// 95 PAY  54 

    0x9efa64a0,// 96 PAY  55 

    0x3f0d2f00,// 97 PAY  56 

    0xf3d49e0f,// 98 PAY  57 

    0x4334d244,// 99 PAY  58 

    0x191f88f4,// 100 PAY  59 

    0xf3223506,// 101 PAY  60 

    0xfbc30a14,// 102 PAY  61 

    0x3aeed63a,// 103 PAY  62 

    0x4ef5fe2f,// 104 PAY  63 

    0x4d4479d6,// 105 PAY  64 

    0x8caeeaa7,// 106 PAY  65 

    0xb104df48,// 107 PAY  66 

    0xdddb5585,// 108 PAY  67 

    0x3f5277ac,// 109 PAY  68 

    0xdc72c6fd,// 110 PAY  69 

    0x7e909e6b,// 111 PAY  70 

    0x1cbcbcc4,// 112 PAY  71 

    0x7c4a5df1,// 113 PAY  72 

    0x271c4479,// 114 PAY  73 

    0xe9f28a74,// 115 PAY  74 

    0x216ad085,// 116 PAY  75 

    0x85f0c407,// 117 PAY  76 

    0x20995dcb,// 118 PAY  77 

    0xb6634fb1,// 119 PAY  78 

    0xe2addee5,// 120 PAY  79 

    0xee243762,// 121 PAY  80 

    0x311c6d11,// 122 PAY  81 

    0xb3b0644a,// 123 PAY  82 

    0xf11c7613,// 124 PAY  83 

    0x3dbd2ce1,// 125 PAY  84 

    0x2eb41083,// 126 PAY  85 

    0xcecd9eeb,// 127 PAY  86 

    0xc2a997e7,// 128 PAY  87 

    0x7e0915fd,// 129 PAY  88 

    0xf02935c7,// 130 PAY  89 

    0xeb454d43,// 131 PAY  90 

    0x95df70e7,// 132 PAY  91 

    0x10afca9f,// 133 PAY  92 

    0xd7f4368c,// 134 PAY  93 

    0xe2bcc650,// 135 PAY  94 

    0x44955352,// 136 PAY  95 

    0x942add98,// 137 PAY  96 

    0x80c0c8cb,// 138 PAY  97 

    0xe3ec7396,// 139 PAY  98 

    0x63739f44,// 140 PAY  99 

    0xbee2a18d,// 141 PAY 100 

    0x76420321,// 142 PAY 101 

    0xc8fd88e8,// 143 PAY 102 

    0x9aa8cb42,// 144 PAY 103 

    0xe62f0a36,// 145 PAY 104 

    0x2677604c,// 146 PAY 105 

    0x79957128,// 147 PAY 106 

    0x59daae5b,// 148 PAY 107 

    0x48043bd5,// 149 PAY 108 

    0x9754e467,// 150 PAY 109 

    0xd2351284,// 151 PAY 110 

    0xa71cfb5d,// 152 PAY 111 

    0x37f6bcf5,// 153 PAY 112 

    0x7d4ca523,// 154 PAY 113 

    0xc18bb3c2,// 155 PAY 114 

    0x5a65fd63,// 156 PAY 115 

    0x01dfc0b3,// 157 PAY 116 

    0x2da36096,// 158 PAY 117 

    0x45451948,// 159 PAY 118 

    0xdbda7b71,// 160 PAY 119 

    0x6c4732a3,// 161 PAY 120 

    0xeb977f0f,// 162 PAY 121 

    0x46f6fb6e,// 163 PAY 122 

    0x53e7eb42,// 164 PAY 123 

    0x6bc1de8a,// 165 PAY 124 

    0xe5970553,// 166 PAY 125 

    0x145341f6,// 167 PAY 126 

    0x09b804ce,// 168 PAY 127 

    0xa21c1906,// 169 PAY 128 

    0x8d00c917,// 170 PAY 129 

    0xccc73d29,// 171 PAY 130 

    0x189491bd,// 172 PAY 131 

    0x823df58b,// 173 PAY 132 

    0x968bce97,// 174 PAY 133 

    0x8ab3a8d7,// 175 PAY 134 

    0x7d05b9c0,// 176 PAY 135 

    0xa016a6a5,// 177 PAY 136 

    0xfd6393f0,// 178 PAY 137 

    0x057dd846,// 179 PAY 138 

    0x882ec926,// 180 PAY 139 

    0xadb510ca,// 181 PAY 140 

    0x82ca4906,// 182 PAY 141 

    0x1f2868c7,// 183 PAY 142 

    0x5ae25441,// 184 PAY 143 

    0xc9691c64,// 185 PAY 144 

    0x9dc87d99,// 186 PAY 145 

    0xa73b30b3,// 187 PAY 146 

    0x79ccdbf7,// 188 PAY 147 

    0x7a7c6c6f,// 189 PAY 148 

    0x3bf14809,// 190 PAY 149 

    0xdcbc4bca,// 191 PAY 150 

    0x84ffbf5d,// 192 PAY 151 

    0x1685c3ba,// 193 PAY 152 

    0xa7849ce4,// 194 PAY 153 

    0xda13a42b,// 195 PAY 154 

    0x7eacf7ae,// 196 PAY 155 

    0xa91fbb7f,// 197 PAY 156 

    0x6d1cfa1c,// 198 PAY 157 

    0xb82e7479,// 199 PAY 158 

    0x88b52e2c,// 200 PAY 159 

    0x688dcba3,// 201 PAY 160 

    0x3a85a44a,// 202 PAY 161 

    0x2f73cd21,// 203 PAY 162 

    0x78968634,// 204 PAY 163 

    0x9007c4c3,// 205 PAY 164 

    0xe7b20fd8,// 206 PAY 165 

    0x5f98615a,// 207 PAY 166 

    0x65c1dc7e,// 208 PAY 167 

    0x12f6a6e3,// 209 PAY 168 

    0xc61864a2,// 210 PAY 169 

    0xf546fe77,// 211 PAY 170 

    0x9dca8641,// 212 PAY 171 

    0xe2e2bbb6,// 213 PAY 172 

    0x5b9c1b57,// 214 PAY 173 

    0x3d7dd4c2,// 215 PAY 174 

    0x4ac89747,// 216 PAY 175 

    0xb2eff5a7,// 217 PAY 176 

    0x371c3ef7,// 218 PAY 177 

    0x74258f9f,// 219 PAY 178 

    0x3dd47687,// 220 PAY 179 

    0xaee41bdb,// 221 PAY 180 

    0x27fe0601,// 222 PAY 181 

    0x4166adec,// 223 PAY 182 

    0x45b46a39,// 224 PAY 183 

    0x73c641df,// 225 PAY 184 

    0x9d10f226,// 226 PAY 185 

    0x8e6e7848,// 227 PAY 186 

    0x93b18242,// 228 PAY 187 

    0xc4b3b171,// 229 PAY 188 

    0xfd2238ee,// 230 PAY 189 

    0x964f8384,// 231 PAY 190 

    0x79e7d65f,// 232 PAY 191 

    0x0cf147c8,// 233 PAY 192 

    0x96ef5e41,// 234 PAY 193 

    0xfd91ea4c,// 235 PAY 194 

    0xb478f392,// 236 PAY 195 

    0x4d2fb63f,// 237 PAY 196 

    0xe9cefdca,// 238 PAY 197 

    0x432e0f32,// 239 PAY 198 

    0x64391143,// 240 PAY 199 

    0xc356aae9,// 241 PAY 200 

    0x94a61d34,// 242 PAY 201 

    0x47e00b1a,// 243 PAY 202 

    0x9a9c5378,// 244 PAY 203 

    0x1d9ef59f,// 245 PAY 204 

    0x7fe09042,// 246 PAY 205 

    0xa27bf0e0,// 247 PAY 206 

    0x737f62d6,// 248 PAY 207 

    0xd57f24c6,// 249 PAY 208 

    0x930f726c,// 250 PAY 209 

    0x6bf4c858,// 251 PAY 210 

    0x6970e199,// 252 PAY 211 

    0x2a2c6f31,// 253 PAY 212 

    0xa3cfa9f2,// 254 PAY 213 

    0x831b1c1b,// 255 PAY 214 

    0x8a89d059,// 256 PAY 215 

    0xbf358b26,// 257 PAY 216 

    0x9a02d987,// 258 PAY 217 

    0xe778af4a,// 259 PAY 218 

    0xe6941db1,// 260 PAY 219 

    0x7da6f1c4,// 261 PAY 220 

    0xdc01e581,// 262 PAY 221 

    0xf3917d5a,// 263 PAY 222 

    0x4e265af0,// 264 PAY 223 

    0x36f5ede7,// 265 PAY 224 

    0xd4d8f79e,// 266 PAY 225 

    0x34e2a606,// 267 PAY 226 

    0x624a3b9e,// 268 PAY 227 

    0xcd3d0eae,// 269 PAY 228 

    0x4c07fd01,// 270 PAY 229 

    0x914e6c0e,// 271 PAY 230 

    0x65c26de7,// 272 PAY 231 

    0xe50016af,// 273 PAY 232 

    0xdface428,// 274 PAY 233 

    0xd3277651,// 275 PAY 234 

    0x483415dc,// 276 PAY 235 

    0x13000000,// 277 PAY 236 

/// STA is 1 words. 

/// STA num_pkts       : 100 

/// STA pkt_idx        : 152 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x6f 

    0x02616f64 // 278 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt47_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x07 

/// ECH pdu_tag        : 0x00 

    0x00070000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x8080286b,// 4 SCX   2 

    0x00000200,// 5 SCX   3 

    0x9380015e,// 6 SCX   4 

    0x08e675f8,// 7 SCX   5 

    0x749cccc6,// 8 SCX   6 

    0x0f1109d5,// 9 SCX   7 

    0x9da7ca85,// 10 SCX   8 

    0xe5b3826f,// 11 SCX   9 

    0x4a946acb,// 12 SCX  10 

    0x60c4961b,// 13 SCX  11 

    0xd7ec1e4a,// 14 SCX  12 

    0xf4af6bdb,// 15 SCX  13 

    0x7f08d63b,// 16 SCX  14 

    0x9818ec16,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1432 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 857 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 857 

/// BFD lencrypto      : 160 

/// BFD ofstcrypto     : 676 

/// BFD (ofst+len)cry  : 836 

/// BFD ofstiv         : 596 

/// BFD ofsticv        : 1324 

    0x00000359,// 18 BFD   1 

    0x02a400a0,// 19 BFD   2 

    0x052c0254,// 20 BFD   3 

/// MFM is 9 words. 

/// MFM vldnibs        : 44 

    0x4400023f,// 21 MFM   1 

    0x8bbcc152,// 22 MFM   2 

    0xde66eb20,// 23 MFM   3 

    0x228f9069,// 24 MFM   4 

    0x83b93745,// 25 MFM   5 

    0x80ca6be0,// 26 MFM   6 

    0xfb800316,// 27 MFM   7 

    0x9ebf8a5c,// 28 MFM   8 

    0x206c13f2,// 29 MFM   9 

/// BDA is 359 words. 

/// BDA size     is 1432 (0x598) 

/// BDA id       is 0x4ac8 

    0x05984ac8,// 30 BDA   1 

/// PAY Generic Data size   : 1432 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xba0a1b1f,// 31 PAY   1 

    0xa2b5b1e8,// 32 PAY   2 

    0x452e3a3a,// 33 PAY   3 

    0x20fa34b5,// 34 PAY   4 

    0x67be082e,// 35 PAY   5 

    0x87c530e4,// 36 PAY   6 

    0x7302ec7c,// 37 PAY   7 

    0xbc79ad67,// 38 PAY   8 

    0x7c097852,// 39 PAY   9 

    0xa608a0ca,// 40 PAY  10 

    0xf2543939,// 41 PAY  11 

    0x71e42b03,// 42 PAY  12 

    0xf6b82f2a,// 43 PAY  13 

    0x75651669,// 44 PAY  14 

    0x6dff3192,// 45 PAY  15 

    0xba146e65,// 46 PAY  16 

    0xa7bc81fa,// 47 PAY  17 

    0x999169fe,// 48 PAY  18 

    0xf86d28c9,// 49 PAY  19 

    0xb4de706a,// 50 PAY  20 

    0xbc6fe474,// 51 PAY  21 

    0xf2186d3f,// 52 PAY  22 

    0x184751af,// 53 PAY  23 

    0x87a50325,// 54 PAY  24 

    0x9396527d,// 55 PAY  25 

    0x20384bb7,// 56 PAY  26 

    0x758a955f,// 57 PAY  27 

    0x6f3a0678,// 58 PAY  28 

    0x843c0543,// 59 PAY  29 

    0xb4b4976f,// 60 PAY  30 

    0x1300db5f,// 61 PAY  31 

    0x8adea50e,// 62 PAY  32 

    0x35330ec4,// 63 PAY  33 

    0x252c05f0,// 64 PAY  34 

    0x5e7a3ae7,// 65 PAY  35 

    0x8ed78b73,// 66 PAY  36 

    0x35783b62,// 67 PAY  37 

    0x1532d9a1,// 68 PAY  38 

    0xd621620b,// 69 PAY  39 

    0x3512e33c,// 70 PAY  40 

    0xc31ec95f,// 71 PAY  41 

    0xc58e79a5,// 72 PAY  42 

    0x07d314cc,// 73 PAY  43 

    0xf0a4b6e9,// 74 PAY  44 

    0xd348ef19,// 75 PAY  45 

    0x154c4f45,// 76 PAY  46 

    0x241a08da,// 77 PAY  47 

    0x657c4707,// 78 PAY  48 

    0x7ff48c28,// 79 PAY  49 

    0xb8c1d978,// 80 PAY  50 

    0x1e313802,// 81 PAY  51 

    0x19792c7a,// 82 PAY  52 

    0xc4bf66e0,// 83 PAY  53 

    0x9a63390f,// 84 PAY  54 

    0xfc83d88d,// 85 PAY  55 

    0x7c8a6b21,// 86 PAY  56 

    0x8d0b929e,// 87 PAY  57 

    0xebcaa76c,// 88 PAY  58 

    0x1b9002f4,// 89 PAY  59 

    0xc0c2716b,// 90 PAY  60 

    0x93ed1e7d,// 91 PAY  61 

    0xfb5cece0,// 92 PAY  62 

    0xb855c227,// 93 PAY  63 

    0x1bfade2f,// 94 PAY  64 

    0x588dd5c7,// 95 PAY  65 

    0x14f43e88,// 96 PAY  66 

    0x26a87efc,// 97 PAY  67 

    0x47a768a8,// 98 PAY  68 

    0xb16b2e0b,// 99 PAY  69 

    0x85fd3bf2,// 100 PAY  70 

    0xad86df72,// 101 PAY  71 

    0xb9754d6b,// 102 PAY  72 

    0x2d39465e,// 103 PAY  73 

    0x69031601,// 104 PAY  74 

    0xe780a6fa,// 105 PAY  75 

    0xffb14adb,// 106 PAY  76 

    0x37b73ed4,// 107 PAY  77 

    0x88cdb3a5,// 108 PAY  78 

    0x1105974c,// 109 PAY  79 

    0x71b80376,// 110 PAY  80 

    0x3c2a7f0d,// 111 PAY  81 

    0x0741ff82,// 112 PAY  82 

    0x57bf746e,// 113 PAY  83 

    0x1ae91abf,// 114 PAY  84 

    0xf6d9962b,// 115 PAY  85 

    0xf4530633,// 116 PAY  86 

    0x250aae6b,// 117 PAY  87 

    0x30a43816,// 118 PAY  88 

    0x1e08d9ff,// 119 PAY  89 

    0xb4389376,// 120 PAY  90 

    0xa900c725,// 121 PAY  91 

    0xe902a5d6,// 122 PAY  92 

    0xba044446,// 123 PAY  93 

    0xad8c0ff7,// 124 PAY  94 

    0x2db40df7,// 125 PAY  95 

    0x2171e431,// 126 PAY  96 

    0x7b5fb96a,// 127 PAY  97 

    0x0a94724d,// 128 PAY  98 

    0x7d2c2aac,// 129 PAY  99 

    0xf4b999e1,// 130 PAY 100 

    0x8415e425,// 131 PAY 101 

    0x7347b2c8,// 132 PAY 102 

    0x6440c2f5,// 133 PAY 103 

    0x7ce57946,// 134 PAY 104 

    0xfbe70850,// 135 PAY 105 

    0x9ffb2cee,// 136 PAY 106 

    0xdb660e07,// 137 PAY 107 

    0x7245bd37,// 138 PAY 108 

    0x7da5a31d,// 139 PAY 109 

    0x31d9421d,// 140 PAY 110 

    0xd2adf2fd,// 141 PAY 111 

    0x2ca583e9,// 142 PAY 112 

    0xf21f34fe,// 143 PAY 113 

    0xed6db358,// 144 PAY 114 

    0xc266cfc1,// 145 PAY 115 

    0xa8c9a3ce,// 146 PAY 116 

    0xc9338271,// 147 PAY 117 

    0xf5ac9fec,// 148 PAY 118 

    0x050809b2,// 149 PAY 119 

    0x4ec47e52,// 150 PAY 120 

    0x7a1dcc48,// 151 PAY 121 

    0x23c028e6,// 152 PAY 122 

    0x04fc51d2,// 153 PAY 123 

    0xfaa03c58,// 154 PAY 124 

    0x4b068983,// 155 PAY 125 

    0xfe3b136e,// 156 PAY 126 

    0xd12556fc,// 157 PAY 127 

    0xd3e03137,// 158 PAY 128 

    0x3b658115,// 159 PAY 129 

    0x8e9d16b8,// 160 PAY 130 

    0x04e81e69,// 161 PAY 131 

    0xb0820219,// 162 PAY 132 

    0x396b4fbd,// 163 PAY 133 

    0x6baa3e73,// 164 PAY 134 

    0xafcbfac5,// 165 PAY 135 

    0x232c77f7,// 166 PAY 136 

    0x475cbc19,// 167 PAY 137 

    0xe89df8ee,// 168 PAY 138 

    0x272a6820,// 169 PAY 139 

    0x55c7e681,// 170 PAY 140 

    0x76a2f4d0,// 171 PAY 141 

    0x1bc14e5b,// 172 PAY 142 

    0xfabee65d,// 173 PAY 143 

    0x1d4fd39e,// 174 PAY 144 

    0x1228331a,// 175 PAY 145 

    0xb2cdc026,// 176 PAY 146 

    0xe07e5142,// 177 PAY 147 

    0x1361519c,// 178 PAY 148 

    0x3f572156,// 179 PAY 149 

    0x279afc36,// 180 PAY 150 

    0xc453117a,// 181 PAY 151 

    0x9f7bbdba,// 182 PAY 152 

    0xdc8ad25c,// 183 PAY 153 

    0x7d688183,// 184 PAY 154 

    0xe7660349,// 185 PAY 155 

    0x85434596,// 186 PAY 156 

    0x25c42d3c,// 187 PAY 157 

    0xa0f75c1c,// 188 PAY 158 

    0xb74e8619,// 189 PAY 159 

    0xd470183f,// 190 PAY 160 

    0x44b12bb7,// 191 PAY 161 

    0x1447508d,// 192 PAY 162 

    0x796b05eb,// 193 PAY 163 

    0x898cda80,// 194 PAY 164 

    0x18bc4030,// 195 PAY 165 

    0x69e51d20,// 196 PAY 166 

    0x4d597aea,// 197 PAY 167 

    0x32dfdff0,// 198 PAY 168 

    0x4c9c357f,// 199 PAY 169 

    0x11fbb3c7,// 200 PAY 170 

    0x750a9df5,// 201 PAY 171 

    0x3ec25dfe,// 202 PAY 172 

    0xd0fef421,// 203 PAY 173 

    0x207ecae2,// 204 PAY 174 

    0x2a3319f3,// 205 PAY 175 

    0x2cb463a2,// 206 PAY 176 

    0xbb9603b3,// 207 PAY 177 

    0x14740c29,// 208 PAY 178 

    0xa9a0d829,// 209 PAY 179 

    0xe02f15e9,// 210 PAY 180 

    0xbba6b416,// 211 PAY 181 

    0xe48c422e,// 212 PAY 182 

    0x103e7621,// 213 PAY 183 

    0xfe65f27f,// 214 PAY 184 

    0x3d005c67,// 215 PAY 185 

    0x7661eefc,// 216 PAY 186 

    0x3542259e,// 217 PAY 187 

    0x4b5dea08,// 218 PAY 188 

    0x4cb4a803,// 219 PAY 189 

    0xd33e9d61,// 220 PAY 190 

    0xe644f3d7,// 221 PAY 191 

    0xbeb13ea8,// 222 PAY 192 

    0x8bd1b325,// 223 PAY 193 

    0xbe7d85e0,// 224 PAY 194 

    0xc631288c,// 225 PAY 195 

    0x787b3b50,// 226 PAY 196 

    0x2991a071,// 227 PAY 197 

    0xb9e6f236,// 228 PAY 198 

    0xaff534bc,// 229 PAY 199 

    0x76e28e96,// 230 PAY 200 

    0x4340940f,// 231 PAY 201 

    0xcca5ba78,// 232 PAY 202 

    0x115745aa,// 233 PAY 203 

    0xe450a016,// 234 PAY 204 

    0x375f3762,// 235 PAY 205 

    0x0c673be5,// 236 PAY 206 

    0x9a302038,// 237 PAY 207 

    0x4df85978,// 238 PAY 208 

    0xd2117a00,// 239 PAY 209 

    0x5db6ab48,// 240 PAY 210 

    0x28aad91a,// 241 PAY 211 

    0x2ed6df1f,// 242 PAY 212 

    0xb2e65132,// 243 PAY 213 

    0x436b96e4,// 244 PAY 214 

    0xa02a84bd,// 245 PAY 215 

    0x1c79f0f3,// 246 PAY 216 

    0xdae9aa38,// 247 PAY 217 

    0xbe251297,// 248 PAY 218 

    0x75b5f232,// 249 PAY 219 

    0xc85fc5e6,// 250 PAY 220 

    0x708e4bf5,// 251 PAY 221 

    0xb50997a0,// 252 PAY 222 

    0x54fac336,// 253 PAY 223 

    0xc95c423c,// 254 PAY 224 

    0xb91ef05b,// 255 PAY 225 

    0x44f99310,// 256 PAY 226 

    0x654b9a9a,// 257 PAY 227 

    0x6c527012,// 258 PAY 228 

    0x968416ee,// 259 PAY 229 

    0x126c236e,// 260 PAY 230 

    0x2d3b0a7b,// 261 PAY 231 

    0x90da20fc,// 262 PAY 232 

    0xb7c10c27,// 263 PAY 233 

    0x51e3462c,// 264 PAY 234 

    0x63dacada,// 265 PAY 235 

    0x1409883a,// 266 PAY 236 

    0x55353b89,// 267 PAY 237 

    0x588170e7,// 268 PAY 238 

    0xa42efb5c,// 269 PAY 239 

    0x698d4823,// 270 PAY 240 

    0xa02e5de6,// 271 PAY 241 

    0x8fb2e797,// 272 PAY 242 

    0x05973df7,// 273 PAY 243 

    0x86651f38,// 274 PAY 244 

    0x33c73096,// 275 PAY 245 

    0x515fbf78,// 276 PAY 246 

    0xca5c5cd8,// 277 PAY 247 

    0x9299a857,// 278 PAY 248 

    0x4a6a61d9,// 279 PAY 249 

    0x78977eae,// 280 PAY 250 

    0x8f485763,// 281 PAY 251 

    0x2b4d7a16,// 282 PAY 252 

    0x7d721c29,// 283 PAY 253 

    0xa7505e36,// 284 PAY 254 

    0xdba92987,// 285 PAY 255 

    0xe8a29aad,// 286 PAY 256 

    0xed9bc1ff,// 287 PAY 257 

    0xb9c6d742,// 288 PAY 258 

    0x1206646a,// 289 PAY 259 

    0x105d33cb,// 290 PAY 260 

    0xaf4725f3,// 291 PAY 261 

    0x4d1b748c,// 292 PAY 262 

    0xae55ebd8,// 293 PAY 263 

    0x9f5e646a,// 294 PAY 264 

    0x1974445a,// 295 PAY 265 

    0x66c906ab,// 296 PAY 266 

    0x7029a6cd,// 297 PAY 267 

    0xf6fb6cf8,// 298 PAY 268 

    0x39d28743,// 299 PAY 269 

    0xc1f3b39c,// 300 PAY 270 

    0x88fe148a,// 301 PAY 271 

    0xddc7fd8a,// 302 PAY 272 

    0x6d05b7f7,// 303 PAY 273 

    0x937f9044,// 304 PAY 274 

    0x353cbd00,// 305 PAY 275 

    0x63ee9b77,// 306 PAY 276 

    0xf7c90269,// 307 PAY 277 

    0x1ac26220,// 308 PAY 278 

    0x59946c96,// 309 PAY 279 

    0x15c41063,// 310 PAY 280 

    0x2f23eba6,// 311 PAY 281 

    0x508cdd0f,// 312 PAY 282 

    0x2b772136,// 313 PAY 283 

    0xd884cf54,// 314 PAY 284 

    0x74259c51,// 315 PAY 285 

    0x664c7652,// 316 PAY 286 

    0xfb6b0646,// 317 PAY 287 

    0x3ea43177,// 318 PAY 288 

    0x4c40e3bd,// 319 PAY 289 

    0x3206731f,// 320 PAY 290 

    0x357a9e26,// 321 PAY 291 

    0xb5d3efbd,// 322 PAY 292 

    0xfec7a89d,// 323 PAY 293 

    0x4c5a977a,// 324 PAY 294 

    0x205d43f4,// 325 PAY 295 

    0x288d7e32,// 326 PAY 296 

    0x83aa2e9d,// 327 PAY 297 

    0xbf839b25,// 328 PAY 298 

    0x4f1b3838,// 329 PAY 299 

    0x66425f08,// 330 PAY 300 

    0xfe9ebfc1,// 331 PAY 301 

    0xf3a6d118,// 332 PAY 302 

    0x50248bfa,// 333 PAY 303 

    0xa05b3da3,// 334 PAY 304 

    0x3c954ede,// 335 PAY 305 

    0xbd12a530,// 336 PAY 306 

    0xda248986,// 337 PAY 307 

    0x2e6bf613,// 338 PAY 308 

    0xf69b24de,// 339 PAY 309 

    0xab06361e,// 340 PAY 310 

    0xd05ebd59,// 341 PAY 311 

    0x102003a4,// 342 PAY 312 

    0xfe2e4507,// 343 PAY 313 

    0xe9857570,// 344 PAY 314 

    0x2a5d311d,// 345 PAY 315 

    0x8d49d09d,// 346 PAY 316 

    0x1a423a7d,// 347 PAY 317 

    0x83496c64,// 348 PAY 318 

    0x12f2f38c,// 349 PAY 319 

    0x5ec5b088,// 350 PAY 320 

    0xfdef2b8d,// 351 PAY 321 

    0x67e2420e,// 352 PAY 322 

    0x98b4d560,// 353 PAY 323 

    0xd1834e77,// 354 PAY 324 

    0x39e47e0a,// 355 PAY 325 

    0x989367ba,// 356 PAY 326 

    0x2a950cf9,// 357 PAY 327 

    0x89d2542f,// 358 PAY 328 

    0x8ed635c5,// 359 PAY 329 

    0xe8b28db2,// 360 PAY 330 

    0xbbf2057f,// 361 PAY 331 

    0x82570569,// 362 PAY 332 

    0xee1e3d1c,// 363 PAY 333 

    0x4a679990,// 364 PAY 334 

    0xa72c5e3d,// 365 PAY 335 

    0x6bade334,// 366 PAY 336 

    0xebb6e6e8,// 367 PAY 337 

    0xdb5e6875,// 368 PAY 338 

    0x240e8655,// 369 PAY 339 

    0xb2851039,// 370 PAY 340 

    0x09da18a6,// 371 PAY 341 

    0x6106bfa9,// 372 PAY 342 

    0xf389a22a,// 373 PAY 343 

    0xa0b9007f,// 374 PAY 344 

    0xdeb78de7,// 375 PAY 345 

    0x2f785c4c,// 376 PAY 346 

    0x4619fbe3,// 377 PAY 347 

    0xe0fa0126,// 378 PAY 348 

    0xc2b8b3e3,// 379 PAY 349 

    0x9b740904,// 380 PAY 350 

    0x992b44c5,// 381 PAY 351 

    0x4f580e08,// 382 PAY 352 

    0x70a3c504,// 383 PAY 353 

    0x3605489f,// 384 PAY 354 

    0xc72a4fe1,// 385 PAY 355 

    0x245961b2,// 386 PAY 356 

    0xa10b69dd,// 387 PAY 357 

    0x00cd1173,// 388 PAY 358 

/// STA is 1 words. 

/// STA num_pkts       : 35 

/// STA pkt_idx        : 128 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xac 

    0x0200ac23 // 389 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt48_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x07 

/// ECH pdu_tag        : 0x00 

    0x00070000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x80902814,// 4 SCX   2 

    0x000053c2,// 5 SCX   3 

    0x5ed902d6,// 6 SCX   4 

    0xbf712b1c,// 7 SCX   5 

    0x463d3859,// 8 SCX   6 

    0x8d95d9df,// 9 SCX   7 

    0x876de853,// 10 SCX   8 

    0x7f3e195d,// 11 SCX   9 

    0x0fb5681f,// 12 SCX  10 

    0xf0add512,// 13 SCX  11 

    0x48994281,// 14 SCX  12 

    0xca53f57b,// 15 SCX  13 

    0x677884ef,// 16 SCX  14 

    0xe15809e9,// 17 SCX  15 

    0xd0669ac3,// 18 SCX  16 

    0x15c23c0d,// 19 SCX  17 

    0x543964c6,// 20 SCX  18 

    0x109c15de,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1666 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 1614 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1614 

/// BFD lencrypto      : 120 

/// BFD ofstcrypto     : 748 

/// BFD (ofst+len)cry  : 868 

/// BFD ofstiv         : 524 

/// BFD ofsticv        : 1648 

    0x0000064e,// 22 BFD   1 

    0x02ec0078,// 23 BFD   2 

    0x0670020c,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00c7b0,// 25 MFM   1 

    0x4d4850ab,// 26 MFM   2 

    0xb6568d60,// 27 MFM   3 

    0x39feae7a,// 28 MFM   4 

    0x6d27873d,// 29 MFM   5 

    0xc074a4ad,// 30 MFM   6 

    0xc9cbe58f,// 31 MFM   7 

    0x65501314,// 32 MFM   8 

    0x64a173da,// 33 MFM   9 

    0x3b0562fd,// 34 MFM  10 

    0xf1f8cf44,// 35 MFM  11 

    0x43169601,// 36 MFM  12 

    0x8fc23913,// 37 MFM  13 

    0x735f4962,// 38 MFM  14 

    0x347cb894,// 39 MFM  15 

    0x64570d56,// 40 MFM  16 

/// BDA is 418 words. 

/// BDA size     is 1666 (0x682) 

/// BDA id       is 0x267c 

    0x0682267c,// 41 BDA   1 

/// PAY Generic Data size   : 1666 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x58eac9da,// 42 PAY   1 

    0x33f37558,// 43 PAY   2 

    0xd72ca5f6,// 44 PAY   3 

    0xe51376a8,// 45 PAY   4 

    0xf8cdf913,// 46 PAY   5 

    0x3e134360,// 47 PAY   6 

    0xc566105a,// 48 PAY   7 

    0x3406d6fa,// 49 PAY   8 

    0xfa4207d9,// 50 PAY   9 

    0xed92db5f,// 51 PAY  10 

    0x1dc87d3b,// 52 PAY  11 

    0x483e2650,// 53 PAY  12 

    0x1db5be4a,// 54 PAY  13 

    0x1ebbd980,// 55 PAY  14 

    0x4ff92b46,// 56 PAY  15 

    0x1d909ba3,// 57 PAY  16 

    0x253c3c17,// 58 PAY  17 

    0x59f825f4,// 59 PAY  18 

    0x828d4619,// 60 PAY  19 

    0x36c9959e,// 61 PAY  20 

    0xfe8d1594,// 62 PAY  21 

    0x9aef6a90,// 63 PAY  22 

    0xa4ab0822,// 64 PAY  23 

    0xf8c9696f,// 65 PAY  24 

    0xdef40e1d,// 66 PAY  25 

    0x40aa7293,// 67 PAY  26 

    0x5012140b,// 68 PAY  27 

    0x88664051,// 69 PAY  28 

    0xf4248802,// 70 PAY  29 

    0x81d9023e,// 71 PAY  30 

    0x990c3013,// 72 PAY  31 

    0x9d7eb2d9,// 73 PAY  32 

    0xc1257b7c,// 74 PAY  33 

    0x05928f63,// 75 PAY  34 

    0xce5c9d05,// 76 PAY  35 

    0x33b4830a,// 77 PAY  36 

    0x206650b9,// 78 PAY  37 

    0x93fc6bb8,// 79 PAY  38 

    0x93f302b9,// 80 PAY  39 

    0x658dc0a0,// 81 PAY  40 

    0xdddcba2c,// 82 PAY  41 

    0x3b40e697,// 83 PAY  42 

    0xf0b1b2c0,// 84 PAY  43 

    0x28098939,// 85 PAY  44 

    0xcb4d5685,// 86 PAY  45 

    0xf3e4f3cf,// 87 PAY  46 

    0xb174071f,// 88 PAY  47 

    0xd2cd664d,// 89 PAY  48 

    0x61c919ea,// 90 PAY  49 

    0x4afc5d94,// 91 PAY  50 

    0x46868b99,// 92 PAY  51 

    0xb4cc07bc,// 93 PAY  52 

    0xd8d76d2a,// 94 PAY  53 

    0xbd59a045,// 95 PAY  54 

    0x412c1380,// 96 PAY  55 

    0x5e11c0a8,// 97 PAY  56 

    0xd771f3cd,// 98 PAY  57 

    0x3ab56fd7,// 99 PAY  58 

    0x2cb29269,// 100 PAY  59 

    0x90cd4c5a,// 101 PAY  60 

    0xcbcbf620,// 102 PAY  61 

    0xfb3b4cbd,// 103 PAY  62 

    0x7f48d728,// 104 PAY  63 

    0xc5c76a5c,// 105 PAY  64 

    0xd9ad4f15,// 106 PAY  65 

    0x226fb674,// 107 PAY  66 

    0x22d0b719,// 108 PAY  67 

    0xb89a15fb,// 109 PAY  68 

    0xa93d6ca2,// 110 PAY  69 

    0x74218fc1,// 111 PAY  70 

    0x1230a7d8,// 112 PAY  71 

    0x3a7e1db1,// 113 PAY  72 

    0x7aa453d9,// 114 PAY  73 

    0x2236dace,// 115 PAY  74 

    0x76df1345,// 116 PAY  75 

    0xb20dbf5b,// 117 PAY  76 

    0x3dee02ba,// 118 PAY  77 

    0xb89e65a2,// 119 PAY  78 

    0xf7093071,// 120 PAY  79 

    0x73fb15e4,// 121 PAY  80 

    0xe068062d,// 122 PAY  81 

    0x5f19aa97,// 123 PAY  82 

    0x2d0dcf41,// 124 PAY  83 

    0xdcadfc9f,// 125 PAY  84 

    0xc33d6857,// 126 PAY  85 

    0xcfb6680e,// 127 PAY  86 

    0x9f0d29a7,// 128 PAY  87 

    0xfeb6b0af,// 129 PAY  88 

    0xfdbaf1e3,// 130 PAY  89 

    0x494e5c53,// 131 PAY  90 

    0x13b99f0b,// 132 PAY  91 

    0x674eb6b6,// 133 PAY  92 

    0x2b22ebbb,// 134 PAY  93 

    0x32f975a1,// 135 PAY  94 

    0xb611079e,// 136 PAY  95 

    0x3c9ccee6,// 137 PAY  96 

    0xcfb1a989,// 138 PAY  97 

    0x6e89eeca,// 139 PAY  98 

    0xa66de85a,// 140 PAY  99 

    0xe1ff852d,// 141 PAY 100 

    0xa70649b2,// 142 PAY 101 

    0x6d8462f1,// 143 PAY 102 

    0x2c0b3bd1,// 144 PAY 103 

    0xdeac023e,// 145 PAY 104 

    0xf399a259,// 146 PAY 105 

    0x1db88aea,// 147 PAY 106 

    0x289adeab,// 148 PAY 107 

    0xb01c138f,// 149 PAY 108 

    0x8db3d718,// 150 PAY 109 

    0xaf4d5331,// 151 PAY 110 

    0xe828c5fa,// 152 PAY 111 

    0x65a372c3,// 153 PAY 112 

    0x255a6263,// 154 PAY 113 

    0xad0f9916,// 155 PAY 114 

    0x3e6dc10d,// 156 PAY 115 

    0xef763987,// 157 PAY 116 

    0x949b270b,// 158 PAY 117 

    0x7d3f42d6,// 159 PAY 118 

    0x8ed3744e,// 160 PAY 119 

    0xc7895371,// 161 PAY 120 

    0x0a0e7bfd,// 162 PAY 121 

    0xaf65f201,// 163 PAY 122 

    0xafb583de,// 164 PAY 123 

    0xc7be8aa1,// 165 PAY 124 

    0x33785c9c,// 166 PAY 125 

    0xff372b68,// 167 PAY 126 

    0x713539a6,// 168 PAY 127 

    0x1e4ce329,// 169 PAY 128 

    0xee9a5db3,// 170 PAY 129 

    0x980e48ab,// 171 PAY 130 

    0xe2245687,// 172 PAY 131 

    0xbece1ff1,// 173 PAY 132 

    0x5dd08954,// 174 PAY 133 

    0x6cb9730f,// 175 PAY 134 

    0x9e1b343d,// 176 PAY 135 

    0x36c800c1,// 177 PAY 136 

    0x5bd3ea9d,// 178 PAY 137 

    0xe0fbd7a4,// 179 PAY 138 

    0x2f8b75fb,// 180 PAY 139 

    0x41fb7c8d,// 181 PAY 140 

    0x90b78c13,// 182 PAY 141 

    0x1de8b58e,// 183 PAY 142 

    0xfb31561b,// 184 PAY 143 

    0x4cf41faf,// 185 PAY 144 

    0xf9971af7,// 186 PAY 145 

    0x4934bdf6,// 187 PAY 146 

    0xf8b23eda,// 188 PAY 147 

    0x512d556b,// 189 PAY 148 

    0xc832c7e3,// 190 PAY 149 

    0xff4dddb3,// 191 PAY 150 

    0xa4993b86,// 192 PAY 151 

    0x80b63c47,// 193 PAY 152 

    0x0931ce79,// 194 PAY 153 

    0x31b88da4,// 195 PAY 154 

    0xcd98f4ef,// 196 PAY 155 

    0x9b5ddecf,// 197 PAY 156 

    0x63e6142c,// 198 PAY 157 

    0x5386c632,// 199 PAY 158 

    0x22827132,// 200 PAY 159 

    0xb57d4c53,// 201 PAY 160 

    0xcb6ba27c,// 202 PAY 161 

    0x80c3b74c,// 203 PAY 162 

    0xc8c93082,// 204 PAY 163 

    0xcbad9461,// 205 PAY 164 

    0xa10d43e9,// 206 PAY 165 

    0x4dd69933,// 207 PAY 166 

    0x2a80193b,// 208 PAY 167 

    0xd32e2fe3,// 209 PAY 168 

    0xd8c8d233,// 210 PAY 169 

    0xe9aeeb88,// 211 PAY 170 

    0xec039a0f,// 212 PAY 171 

    0x4e1ec15c,// 213 PAY 172 

    0xab9dd9e4,// 214 PAY 173 

    0x32c94f86,// 215 PAY 174 

    0x74038086,// 216 PAY 175 

    0x18490a20,// 217 PAY 176 

    0xbaffcee2,// 218 PAY 177 

    0x43a9d815,// 219 PAY 178 

    0xe0fe57d8,// 220 PAY 179 

    0x71e1826c,// 221 PAY 180 

    0x82cbdf6c,// 222 PAY 181 

    0x4195faf0,// 223 PAY 182 

    0x5922f06a,// 224 PAY 183 

    0xd5796dba,// 225 PAY 184 

    0x96cfffbe,// 226 PAY 185 

    0xb76c206e,// 227 PAY 186 

    0x639bb7fe,// 228 PAY 187 

    0xb538a195,// 229 PAY 188 

    0x14403232,// 230 PAY 189 

    0xe4450957,// 231 PAY 190 

    0x1506b784,// 232 PAY 191 

    0xfc9bb336,// 233 PAY 192 

    0x24aa29fc,// 234 PAY 193 

    0x2b8d666a,// 235 PAY 194 

    0xe2d03fb4,// 236 PAY 195 

    0x69d363bd,// 237 PAY 196 

    0x54d79131,// 238 PAY 197 

    0x19498e5d,// 239 PAY 198 

    0xca9118cf,// 240 PAY 199 

    0x2ddb02f3,// 241 PAY 200 

    0xba08bfbb,// 242 PAY 201 

    0x49ba54f2,// 243 PAY 202 

    0xe6b566ce,// 244 PAY 203 

    0x2daf0cda,// 245 PAY 204 

    0x5a008a1b,// 246 PAY 205 

    0x881c1d34,// 247 PAY 206 

    0x80dbc3a0,// 248 PAY 207 

    0x0d2161af,// 249 PAY 208 

    0xad4336a4,// 250 PAY 209 

    0x8d5c4edf,// 251 PAY 210 

    0x01c9cc8b,// 252 PAY 211 

    0xa7f70f3f,// 253 PAY 212 

    0xecc32654,// 254 PAY 213 

    0x38ca7bd1,// 255 PAY 214 

    0x8c719e65,// 256 PAY 215 

    0xa098a83b,// 257 PAY 216 

    0x24e9aaa3,// 258 PAY 217 

    0x1cb0a5aa,// 259 PAY 218 

    0x2fcec358,// 260 PAY 219 

    0x211c9c9f,// 261 PAY 220 

    0xe9c2542d,// 262 PAY 221 

    0x7bbff41a,// 263 PAY 222 

    0x63dbb464,// 264 PAY 223 

    0xe1c2e2f8,// 265 PAY 224 

    0x6159c0e5,// 266 PAY 225 

    0xd9b9c1af,// 267 PAY 226 

    0x51992ea0,// 268 PAY 227 

    0x03cfc99d,// 269 PAY 228 

    0xbf2aef18,// 270 PAY 229 

    0x6029f8f5,// 271 PAY 230 

    0x801d3a4f,// 272 PAY 231 

    0x0fd15adc,// 273 PAY 232 

    0x6e26a0e7,// 274 PAY 233 

    0x4e424a2c,// 275 PAY 234 

    0xfad08890,// 276 PAY 235 

    0x1c712698,// 277 PAY 236 

    0x59ff737a,// 278 PAY 237 

    0x8d397d04,// 279 PAY 238 

    0xf8a52ae0,// 280 PAY 239 

    0xaab883ac,// 281 PAY 240 

    0xe41f25e6,// 282 PAY 241 

    0x7e11b295,// 283 PAY 242 

    0x27f0a276,// 284 PAY 243 

    0x481bdae6,// 285 PAY 244 

    0x254cc5e1,// 286 PAY 245 

    0x731fc027,// 287 PAY 246 

    0x9fbb0993,// 288 PAY 247 

    0x4bbe50f8,// 289 PAY 248 

    0x3c2163fa,// 290 PAY 249 

    0xa55cb87f,// 291 PAY 250 

    0x18eab902,// 292 PAY 251 

    0xdde9f511,// 293 PAY 252 

    0x9110d2e7,// 294 PAY 253 

    0xae1502fd,// 295 PAY 254 

    0x189d969f,// 296 PAY 255 

    0x8e412c06,// 297 PAY 256 

    0xb4c04d97,// 298 PAY 257 

    0x8814af3a,// 299 PAY 258 

    0x4ad40054,// 300 PAY 259 

    0x2f91f919,// 301 PAY 260 

    0xd10358fd,// 302 PAY 261 

    0x8c70f07c,// 303 PAY 262 

    0x4debc6bf,// 304 PAY 263 

    0x7a82287c,// 305 PAY 264 

    0xfa1091f9,// 306 PAY 265 

    0x23d0d34b,// 307 PAY 266 

    0x95d472c1,// 308 PAY 267 

    0x84d4be53,// 309 PAY 268 

    0x68d6ca95,// 310 PAY 269 

    0x70f545f4,// 311 PAY 270 

    0xfad9b6ef,// 312 PAY 271 

    0x452d0301,// 313 PAY 272 

    0xd27786cb,// 314 PAY 273 

    0xb39e3bed,// 315 PAY 274 

    0xcf967632,// 316 PAY 275 

    0xeb0d7d44,// 317 PAY 276 

    0x4bd52cf4,// 318 PAY 277 

    0x26eb5467,// 319 PAY 278 

    0x122cd02d,// 320 PAY 279 

    0xe535ec7c,// 321 PAY 280 

    0x70142e66,// 322 PAY 281 

    0xaf99b6ac,// 323 PAY 282 

    0xa6c3fb6f,// 324 PAY 283 

    0xbbd65777,// 325 PAY 284 

    0x0e6ba266,// 326 PAY 285 

    0x8b4e0b3e,// 327 PAY 286 

    0x13cc2c50,// 328 PAY 287 

    0x9034c7f1,// 329 PAY 288 

    0x0dc7d909,// 330 PAY 289 

    0xb7db8918,// 331 PAY 290 

    0xc5cf2b37,// 332 PAY 291 

    0x89364d1b,// 333 PAY 292 

    0xb8ee1293,// 334 PAY 293 

    0x171f374f,// 335 PAY 294 

    0x71653361,// 336 PAY 295 

    0x6fee3b29,// 337 PAY 296 

    0xac1a97a2,// 338 PAY 297 

    0xa7e41946,// 339 PAY 298 

    0x74725900,// 340 PAY 299 

    0x5e47541f,// 341 PAY 300 

    0x9ae36ee2,// 342 PAY 301 

    0x95576c18,// 343 PAY 302 

    0xe2df1927,// 344 PAY 303 

    0x615a0737,// 345 PAY 304 

    0x78998034,// 346 PAY 305 

    0x1f4e3808,// 347 PAY 306 

    0x210da937,// 348 PAY 307 

    0xc559d79a,// 349 PAY 308 

    0xc869bf8c,// 350 PAY 309 

    0x5ad68b14,// 351 PAY 310 

    0x700a2e61,// 352 PAY 311 

    0xe80d31e2,// 353 PAY 312 

    0x1aa0f2f4,// 354 PAY 313 

    0x39ef925f,// 355 PAY 314 

    0xb0d43c54,// 356 PAY 315 

    0x1feb8f51,// 357 PAY 316 

    0x24c42a2d,// 358 PAY 317 

    0x3453fdcc,// 359 PAY 318 

    0xf6eb4c21,// 360 PAY 319 

    0xbedbf6a2,// 361 PAY 320 

    0xbdebc1e7,// 362 PAY 321 

    0xf551bfda,// 363 PAY 322 

    0x5af62660,// 364 PAY 323 

    0x3a69fdb2,// 365 PAY 324 

    0x53c889ec,// 366 PAY 325 

    0x7ec1fa2b,// 367 PAY 326 

    0x608290c6,// 368 PAY 327 

    0x9d2d34f2,// 369 PAY 328 

    0xacb57b9e,// 370 PAY 329 

    0xa6fa7f46,// 371 PAY 330 

    0x88e65cc3,// 372 PAY 331 

    0x450fcef4,// 373 PAY 332 

    0x3554cf58,// 374 PAY 333 

    0xfee9164c,// 375 PAY 334 

    0x5d7008bf,// 376 PAY 335 

    0x824a221c,// 377 PAY 336 

    0xb9c2ed0d,// 378 PAY 337 

    0xd58a8169,// 379 PAY 338 

    0x2ff01251,// 380 PAY 339 

    0x3baaebf7,// 381 PAY 340 

    0x78b76766,// 382 PAY 341 

    0xa487fbfb,// 383 PAY 342 

    0x3c5564b8,// 384 PAY 343 

    0xfac05f84,// 385 PAY 344 

    0xa2260d22,// 386 PAY 345 

    0x9dad8805,// 387 PAY 346 

    0x078d990a,// 388 PAY 347 

    0x56ab8555,// 389 PAY 348 

    0xbaf04cec,// 390 PAY 349 

    0x255d5e55,// 391 PAY 350 

    0xd1190148,// 392 PAY 351 

    0x06ff0726,// 393 PAY 352 

    0x4cbec0bc,// 394 PAY 353 

    0x74251a55,// 395 PAY 354 

    0xb4801b76,// 396 PAY 355 

    0xcf99ac9c,// 397 PAY 356 

    0x0ec0bf61,// 398 PAY 357 

    0x7c74b194,// 399 PAY 358 

    0xf0712be4,// 400 PAY 359 

    0x7460dc58,// 401 PAY 360 

    0xf2a2f282,// 402 PAY 361 

    0x0b7ebc74,// 403 PAY 362 

    0xd906e2de,// 404 PAY 363 

    0x1210a8c0,// 405 PAY 364 

    0x251594a3,// 406 PAY 365 

    0x47b5712d,// 407 PAY 366 

    0x84c9a4d9,// 408 PAY 367 

    0xa392cd11,// 409 PAY 368 

    0x1155c9c0,// 410 PAY 369 

    0x63832f94,// 411 PAY 370 

    0x3e77aa3f,// 412 PAY 371 

    0x0525945e,// 413 PAY 372 

    0x057a5bac,// 414 PAY 373 

    0x42bc5f32,// 415 PAY 374 

    0x4d708444,// 416 PAY 375 

    0x9ca7d376,// 417 PAY 376 

    0xfc9c5e4c,// 418 PAY 377 

    0x54e11609,// 419 PAY 378 

    0xea6b90d3,// 420 PAY 379 

    0x8cc66850,// 421 PAY 380 

    0x87a3257a,// 422 PAY 381 

    0x640920d2,// 423 PAY 382 

    0x64d91006,// 424 PAY 383 

    0x4329d608,// 425 PAY 384 

    0x30c88cae,// 426 PAY 385 

    0x566630df,// 427 PAY 386 

    0x2e5d8d49,// 428 PAY 387 

    0xf87ad6eb,// 429 PAY 388 

    0x068f2d23,// 430 PAY 389 

    0x039853c1,// 431 PAY 390 

    0x80916362,// 432 PAY 391 

    0x02cf6eaa,// 433 PAY 392 

    0x6d3fbc5e,// 434 PAY 393 

    0x6c39b440,// 435 PAY 394 

    0x15479886,// 436 PAY 395 

    0x20b54356,// 437 PAY 396 

    0x66b9b411,// 438 PAY 397 

    0xe15e40a4,// 439 PAY 398 

    0xa830c45e,// 440 PAY 399 

    0x9a47ac55,// 441 PAY 400 

    0x5e2c89cd,// 442 PAY 401 

    0x3343f148,// 443 PAY 402 

    0x6e3e84c9,// 444 PAY 403 

    0x8980a243,// 445 PAY 404 

    0x16e5fdc6,// 446 PAY 405 

    0xcb944e9e,// 447 PAY 406 

    0x9935510c,// 448 PAY 407 

    0xe39f1def,// 449 PAY 408 

    0x686a2ba5,// 450 PAY 409 

    0xee6b88f7,// 451 PAY 410 

    0xfb816c36,// 452 PAY 411 

    0xa2a7e901,// 453 PAY 412 

    0xf79f961a,// 454 PAY 413 

    0x409b6674,// 455 PAY 414 

    0x4058c941,// 456 PAY 415 

    0xfec72dfc,// 457 PAY 416 

    0xae090000,// 458 PAY 417 

/// STA is 1 words. 

/// STA num_pkts       : 144 

/// STA pkt_idx        : 108 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x1c 

    0x01b11c90 // 459 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt49_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x808428d6,// 4 SCX   2 

    0x000023c4,// 5 SCX   3 

    0x18ad2666,// 6 SCX   4 

    0x2ec4efcf,// 7 SCX   5 

    0x565fbd67,// 8 SCX   6 

    0x15fcc80a,// 9 SCX   7 

    0xd480f6b7,// 10 SCX   8 

    0x913bcc84,// 11 SCX   9 

    0xe0400970,// 12 SCX  10 

    0x8e39f613,// 13 SCX  11 

    0xa01a5cef,// 14 SCX  12 

    0xb340ed9d,// 15 SCX  13 

    0xf1157440,// 16 SCX  14 

    0x4afc1e6f,// 17 SCX  15 

    0x238b579d,// 18 SCX  16 

    0x16dfe21d,// 19 SCX  17 

    0xeb421aa0,// 20 SCX  18 

    0xb770f650,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 989 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 565 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 565 

/// BFD lencrypto      : 64 

/// BFD ofstcrypto     : 100 

/// BFD (ofst+len)cry  : 164 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 740 

    0x00000235,// 22 BFD   1 

    0x00640040,// 23 BFD   2 

    0x02e4000c,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : a 

    0x0a0015c3,// 25 MFM   1 

    0x638efb00,// 26 MFM   2 

/// BDA is 249 words. 

/// BDA size     is 989 (0x3dd) 

/// BDA id       is 0x5630 

    0x03dd5630,// 27 BDA   1 

/// PAY Generic Data size   : 989 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x7d76516d,// 28 PAY   1 

    0x8d95422d,// 29 PAY   2 

    0x17f71de5,// 30 PAY   3 

    0x75224a54,// 31 PAY   4 

    0xd39bfb6a,// 32 PAY   5 

    0xee31a0b8,// 33 PAY   6 

    0x39746012,// 34 PAY   7 

    0x5f3ec2c6,// 35 PAY   8 

    0x8a7624be,// 36 PAY   9 

    0x10950b22,// 37 PAY  10 

    0xf3683204,// 38 PAY  11 

    0x9acc281c,// 39 PAY  12 

    0x4cffa542,// 40 PAY  13 

    0x10d5185a,// 41 PAY  14 

    0x63a15a44,// 42 PAY  15 

    0x6acfa303,// 43 PAY  16 

    0x447aaf36,// 44 PAY  17 

    0x77e00163,// 45 PAY  18 

    0xc21fae96,// 46 PAY  19 

    0x48064ca1,// 47 PAY  20 

    0x3552b5f7,// 48 PAY  21 

    0x0cf50f6d,// 49 PAY  22 

    0x49bdbe1b,// 50 PAY  23 

    0xeca2dd89,// 51 PAY  24 

    0x792083c6,// 52 PAY  25 

    0xeb4f3bbd,// 53 PAY  26 

    0x7520e11d,// 54 PAY  27 

    0x808ab0e9,// 55 PAY  28 

    0xcec80166,// 56 PAY  29 

    0x522066db,// 57 PAY  30 

    0x5ce2fa1f,// 58 PAY  31 

    0xe25cde31,// 59 PAY  32 

    0xbd44f5c6,// 60 PAY  33 

    0x55e240ce,// 61 PAY  34 

    0x30578508,// 62 PAY  35 

    0xe989f584,// 63 PAY  36 

    0x8919ad75,// 64 PAY  37 

    0xeb903d04,// 65 PAY  38 

    0x4107d54f,// 66 PAY  39 

    0xb2112eda,// 67 PAY  40 

    0x4071f22d,// 68 PAY  41 

    0x442adf51,// 69 PAY  42 

    0x25bb0485,// 70 PAY  43 

    0x63a06e20,// 71 PAY  44 

    0x65c63ff9,// 72 PAY  45 

    0x6cf52b34,// 73 PAY  46 

    0x34cf64d4,// 74 PAY  47 

    0x6f28985c,// 75 PAY  48 

    0x0501e96b,// 76 PAY  49 

    0xe8edfded,// 77 PAY  50 

    0x9546e2f0,// 78 PAY  51 

    0x6790097b,// 79 PAY  52 

    0xf0eb10c6,// 80 PAY  53 

    0xbd6bd919,// 81 PAY  54 

    0x2ebd1ab2,// 82 PAY  55 

    0x9a7f3aef,// 83 PAY  56 

    0xc13222f3,// 84 PAY  57 

    0xdc6969d0,// 85 PAY  58 

    0x42a963dd,// 86 PAY  59 

    0x46e1b130,// 87 PAY  60 

    0x021120f6,// 88 PAY  61 

    0x159bd2c7,// 89 PAY  62 

    0x39590e15,// 90 PAY  63 

    0x169c3c01,// 91 PAY  64 

    0x3816ec22,// 92 PAY  65 

    0xada43646,// 93 PAY  66 

    0xb0a2a1ac,// 94 PAY  67 

    0x5f19ee25,// 95 PAY  68 

    0xd734526c,// 96 PAY  69 

    0x82281f88,// 97 PAY  70 

    0xbb542a79,// 98 PAY  71 

    0x626efaa9,// 99 PAY  72 

    0x3e0f9209,// 100 PAY  73 

    0x642e30ab,// 101 PAY  74 

    0x237e2a46,// 102 PAY  75 

    0xbd66dd46,// 103 PAY  76 

    0x641c5ffb,// 104 PAY  77 

    0x6457cb6d,// 105 PAY  78 

    0xac559ec4,// 106 PAY  79 

    0x898bc5da,// 107 PAY  80 

    0x157dcc21,// 108 PAY  81 

    0x66fc0f19,// 109 PAY  82 

    0x9e68534e,// 110 PAY  83 

    0x1b18980a,// 111 PAY  84 

    0xadf119c1,// 112 PAY  85 

    0xaae2caa5,// 113 PAY  86 

    0xe3662e0e,// 114 PAY  87 

    0xfffb242e,// 115 PAY  88 

    0xdac8647e,// 116 PAY  89 

    0xe171afa7,// 117 PAY  90 

    0x5e36e304,// 118 PAY  91 

    0xab7bfe25,// 119 PAY  92 

    0xb9545de5,// 120 PAY  93 

    0x17065a9e,// 121 PAY  94 

    0x2d09c42e,// 122 PAY  95 

    0x3b8017c5,// 123 PAY  96 

    0x3859d2ad,// 124 PAY  97 

    0x16d7837b,// 125 PAY  98 

    0x6ff46e2d,// 126 PAY  99 

    0x8012b1c3,// 127 PAY 100 

    0x59096c9d,// 128 PAY 101 

    0x4c246aec,// 129 PAY 102 

    0x00d4dcd2,// 130 PAY 103 

    0xb55b4d52,// 131 PAY 104 

    0x562793b3,// 132 PAY 105 

    0x026eaaee,// 133 PAY 106 

    0x6deb43a7,// 134 PAY 107 

    0x1c32d04d,// 135 PAY 108 

    0x3b943567,// 136 PAY 109 

    0xb004ccaf,// 137 PAY 110 

    0x81abe610,// 138 PAY 111 

    0x85a78a49,// 139 PAY 112 

    0x097f6de5,// 140 PAY 113 

    0x574a653e,// 141 PAY 114 

    0xfe2cb8b3,// 142 PAY 115 

    0x1869fc77,// 143 PAY 116 

    0x48bab9fd,// 144 PAY 117 

    0xd1f192e2,// 145 PAY 118 

    0x655b3516,// 146 PAY 119 

    0x50668e0c,// 147 PAY 120 

    0x84a23bff,// 148 PAY 121 

    0x525c4fe8,// 149 PAY 122 

    0x453b78c3,// 150 PAY 123 

    0x167e4fe2,// 151 PAY 124 

    0x79a11386,// 152 PAY 125 

    0x5be1108f,// 153 PAY 126 

    0xae0670f6,// 154 PAY 127 

    0x68c551ea,// 155 PAY 128 

    0xd9c55738,// 156 PAY 129 

    0x9b80c2e3,// 157 PAY 130 

    0x862e41d5,// 158 PAY 131 

    0x5169cdb0,// 159 PAY 132 

    0x6b107fc4,// 160 PAY 133 

    0x1f925220,// 161 PAY 134 

    0xd11cd97c,// 162 PAY 135 

    0xe8ca495f,// 163 PAY 136 

    0x303df882,// 164 PAY 137 

    0x2b610de5,// 165 PAY 138 

    0x7df17b7a,// 166 PAY 139 

    0xb041a573,// 167 PAY 140 

    0x779eb9dc,// 168 PAY 141 

    0x42a22fbb,// 169 PAY 142 

    0x96039a79,// 170 PAY 143 

    0x91a5faa8,// 171 PAY 144 

    0xcb32a219,// 172 PAY 145 

    0x01263dc4,// 173 PAY 146 

    0xa6d65128,// 174 PAY 147 

    0xf8cbb6e5,// 175 PAY 148 

    0xad28ad41,// 176 PAY 149 

    0x8f52eace,// 177 PAY 150 

    0x4e5237e6,// 178 PAY 151 

    0xfdc1c40a,// 179 PAY 152 

    0x461655a5,// 180 PAY 153 

    0xe48fecfa,// 181 PAY 154 

    0x8187bbc5,// 182 PAY 155 

    0x02f93a08,// 183 PAY 156 

    0x82a61ee7,// 184 PAY 157 

    0x35523b3e,// 185 PAY 158 

    0x2dace7b8,// 186 PAY 159 

    0x4ad0c18e,// 187 PAY 160 

    0x1a66be71,// 188 PAY 161 

    0x88d72be6,// 189 PAY 162 

    0xe34ce137,// 190 PAY 163 

    0xb628f549,// 191 PAY 164 

    0x80440f01,// 192 PAY 165 

    0xc7b92ae6,// 193 PAY 166 

    0x64f3a7ae,// 194 PAY 167 

    0xcb6eb0ae,// 195 PAY 168 

    0x2a9dffc2,// 196 PAY 169 

    0x6cc93002,// 197 PAY 170 

    0xa9a0b015,// 198 PAY 171 

    0x8d5fb9be,// 199 PAY 172 

    0x1411e8a7,// 200 PAY 173 

    0xb9d3a7ac,// 201 PAY 174 

    0x7f5a8b4a,// 202 PAY 175 

    0x610f490f,// 203 PAY 176 

    0xde88697b,// 204 PAY 177 

    0xe01434d9,// 205 PAY 178 

    0x426f708d,// 206 PAY 179 

    0x730ed8dd,// 207 PAY 180 

    0x7d9c71e9,// 208 PAY 181 

    0x8634e829,// 209 PAY 182 

    0x533676a9,// 210 PAY 183 

    0x0e75bd81,// 211 PAY 184 

    0xa7f98f0f,// 212 PAY 185 

    0xb332a486,// 213 PAY 186 

    0xbe41f7e0,// 214 PAY 187 

    0xb56a1163,// 215 PAY 188 

    0x4de5d80a,// 216 PAY 189 

    0x98ddde5f,// 217 PAY 190 

    0xc984896d,// 218 PAY 191 

    0x15f65ba0,// 219 PAY 192 

    0x40ffcf57,// 220 PAY 193 

    0x23b1053b,// 221 PAY 194 

    0x1722ad3f,// 222 PAY 195 

    0x1c32ac62,// 223 PAY 196 

    0x7e63dacc,// 224 PAY 197 

    0x808fbb06,// 225 PAY 198 

    0x0679c151,// 226 PAY 199 

    0x1e28daca,// 227 PAY 200 

    0x2b2cf46c,// 228 PAY 201 

    0xd8237d7b,// 229 PAY 202 

    0x1a6e89b1,// 230 PAY 203 

    0xeacd7b94,// 231 PAY 204 

    0x07ed36a4,// 232 PAY 205 

    0xa001c041,// 233 PAY 206 

    0xb05bf173,// 234 PAY 207 

    0x081d6cd1,// 235 PAY 208 

    0xaec8dafb,// 236 PAY 209 

    0x25a58eac,// 237 PAY 210 

    0x9e9c3f6d,// 238 PAY 211 

    0x6875f8c4,// 239 PAY 212 

    0x761dc557,// 240 PAY 213 

    0x3e0a3e24,// 241 PAY 214 

    0xf40a4a3b,// 242 PAY 215 

    0x1da45178,// 243 PAY 216 

    0xb30c7dc9,// 244 PAY 217 

    0x74cfb848,// 245 PAY 218 

    0x850a226b,// 246 PAY 219 

    0x613a6cb1,// 247 PAY 220 

    0x496cb550,// 248 PAY 221 

    0xce8b9bb2,// 249 PAY 222 

    0x04f2b2fe,// 250 PAY 223 

    0x1b95bce9,// 251 PAY 224 

    0x21d00526,// 252 PAY 225 

    0xe159e064,// 253 PAY 226 

    0x94d338d1,// 254 PAY 227 

    0x487f80d7,// 255 PAY 228 

    0x5f6ab3c1,// 256 PAY 229 

    0xbce71629,// 257 PAY 230 

    0xbeb91018,// 258 PAY 231 

    0x29893e11,// 259 PAY 232 

    0xd6499a03,// 260 PAY 233 

    0xbd939568,// 261 PAY 234 

    0x68d878e2,// 262 PAY 235 

    0x3e0697b1,// 263 PAY 236 

    0x4ad48c95,// 264 PAY 237 

    0x61ed2166,// 265 PAY 238 

    0x88c3a732,// 266 PAY 239 

    0x2057be90,// 267 PAY 240 

    0x8ab2c2c9,// 268 PAY 241 

    0x84d9c269,// 269 PAY 242 

    0xe0769b9e,// 270 PAY 243 

    0x61fce538,// 271 PAY 244 

    0x41d80120,// 272 PAY 245 

    0x24046ac8,// 273 PAY 246 

    0x1979e7d2,// 274 PAY 247 

    0x9f000000,// 275 PAY 248 

/// STA is 1 words. 

/// STA num_pkts       : 101 

/// STA pkt_idx        : 196 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xce 

    0x0311ce65 // 276 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt50_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x0c 

/// ECH pdu_tag        : 0x00 

    0x000c0000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x808628d8,// 4 SCX   2 

    0x000052c4,// 5 SCX   3 

    0xbf4120d6,// 6 SCX   4 

    0x9efa6c19,// 7 SCX   5 

    0x42fe3d5a,// 8 SCX   6 

    0xfafd0de0,// 9 SCX   7 

    0x6fd617e5,// 10 SCX   8 

    0x7864a22e,// 11 SCX   9 

    0x065351bc,// 12 SCX  10 

    0xc426850c,// 13 SCX  11 

    0xd5d265a4,// 14 SCX  12 

    0xa324d3dd,// 15 SCX  13 

    0x7d71a9f5,// 16 SCX  14 

    0xfc128d09,// 17 SCX  15 

    0x1ccb367b,// 18 SCX  16 

    0xe055472f,// 19 SCX  17 

    0x771631ca,// 20 SCX  18 

    0xad2abec0,// 21 SCX  19 

    0x397cae8b,// 22 SCX  20 

    0x61acf4d7,// 23 SCX  21 

    0x7ce8abed,// 24 SCX  22 

    0xf510246c,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 206 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 71 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 71 

/// BFD lencrypto      : 48 

/// BFD ofstcrypto     : 16 

/// BFD (ofst+len)cry  : 64 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 176 

    0x00000047,// 26 BFD   1 

    0x00100030,// 27 BFD   2 

    0x00b00000,// 28 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 2 

    0x02005f00,// 29 MFM   1 

/// BDA is 53 words. 

/// BDA size     is 206 (0xce) 

/// BDA id       is 0x3ee5 

    0x00ce3ee5,// 30 BDA   1 

/// PAY Generic Data size   : 206 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x795e67d0,// 31 PAY   1 

    0x5eb7a000,// 32 PAY   2 

    0xcec54cec,// 33 PAY   3 

    0x2db59833,// 34 PAY   4 

    0x7c580ac1,// 35 PAY   5 

    0xb86f5035,// 36 PAY   6 

    0x5b7b322b,// 37 PAY   7 

    0x8396d5ee,// 38 PAY   8 

    0x9383b79c,// 39 PAY   9 

    0x838cbbd2,// 40 PAY  10 

    0x03b77e11,// 41 PAY  11 

    0xb058547e,// 42 PAY  12 

    0x0041ae1f,// 43 PAY  13 

    0x790a2c7f,// 44 PAY  14 

    0xd3bc7d16,// 45 PAY  15 

    0xf2fb7007,// 46 PAY  16 

    0x1f5dce27,// 47 PAY  17 

    0x0785e138,// 48 PAY  18 

    0x6fb8f83d,// 49 PAY  19 

    0xb524c4ee,// 50 PAY  20 

    0xddc24e04,// 51 PAY  21 

    0x3b890b80,// 52 PAY  22 

    0xc2c24c5a,// 53 PAY  23 

    0x7fd338ff,// 54 PAY  24 

    0xb19b708b,// 55 PAY  25 

    0xe6657d63,// 56 PAY  26 

    0x1158a008,// 57 PAY  27 

    0xbacfc931,// 58 PAY  28 

    0xad6f2283,// 59 PAY  29 

    0xe803f986,// 60 PAY  30 

    0x15383164,// 61 PAY  31 

    0xf62568bd,// 62 PAY  32 

    0x3f34516f,// 63 PAY  33 

    0x6ef91f05,// 64 PAY  34 

    0xa1b75ebb,// 65 PAY  35 

    0xd93db0ec,// 66 PAY  36 

    0xcdd0cf95,// 67 PAY  37 

    0x81cb96bb,// 68 PAY  38 

    0x3f6ac714,// 69 PAY  39 

    0x69bd1f19,// 70 PAY  40 

    0x50ac9a0b,// 71 PAY  41 

    0xf0465b77,// 72 PAY  42 

    0x3d81ce01,// 73 PAY  43 

    0xc1e3317a,// 74 PAY  44 

    0x6b4ce937,// 75 PAY  45 

    0xaa16abb3,// 76 PAY  46 

    0x304ea833,// 77 PAY  47 

    0xe68f2ca7,// 78 PAY  48 

    0x5080f08f,// 79 PAY  49 

    0xf1856405,// 80 PAY  50 

    0x9044e685,// 81 PAY  51 

    0xa3eb0000,// 82 PAY  52 

/// STA is 1 words. 

/// STA num_pkts       : 196 

/// STA pkt_idx        : 51 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x52 

    0x00cc52c4 // 83 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt51_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x0d 

/// ECH pdu_tag        : 0x00 

    0x000d0000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000011,// 3 SCX   1 

    0x808128a8,// 4 SCX   2 

    0x00006100,// 5 SCX   3 

    0x602060f8,// 6 SCX   4 

    0x674db3c8,// 7 SCX   5 

    0x4df6eff3,// 8 SCX   6 

    0x657362f7,// 9 SCX   7 

    0xe0f316bd,// 10 SCX   8 

    0x42ff0c1b,// 11 SCX   9 

    0x8de0b75f,// 12 SCX  10 

    0x6d988904,// 13 SCX  11 

    0xfd7fd772,// 14 SCX  12 

    0x862aee39,// 15 SCX  13 

    0xfd6acd70,// 16 SCX  14 

    0x9a5b3e85,// 17 SCX  15 

    0x0bb754cc,// 18 SCX  16 

    0x5e16a968,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 986 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 894 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 894 

/// BFD lencrypto      : 176 

/// BFD ofstcrypto     : 676 

/// BFD (ofst+len)cry  : 852 

/// BFD ofstiv         : 548 

/// BFD ofsticv        : 924 

    0x0000037e,// 20 BFD   1 

    0x02a400b0,// 21 BFD   2 

    0x039c0224,// 22 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c008350,// 23 MFM   1 

    0xfac2602e,// 24 MFM   2 

    0x5c47c28f,// 25 MFM   3 

    0x2b98c092,// 26 MFM   4 

    0x3abcc6a6,// 27 MFM   5 

    0xc0844eeb,// 28 MFM   6 

    0x11c48dc4,// 29 MFM   7 

    0xedf3887a,// 30 MFM   8 

    0x06a434a8,// 31 MFM   9 

    0x9d21c729,// 32 MFM  10 

    0xcb3b6dd6,// 33 MFM  11 

    0xd0e13dee,// 34 MFM  12 

    0xbe3a167e,// 35 MFM  13 

    0xc2085bdd,// 36 MFM  14 

    0x37703aab,// 37 MFM  15 

    0x52fe7c1d,// 38 MFM  16 

/// BDA is 248 words. 

/// BDA size     is 986 (0x3da) 

/// BDA id       is 0x30ad 

    0x03da30ad,// 39 BDA   1 

/// PAY Generic Data size   : 986 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xe8c91812,// 40 PAY   1 

    0xa0638ad7,// 41 PAY   2 

    0x62467a32,// 42 PAY   3 

    0x18e55351,// 43 PAY   4 

    0xc88913d8,// 44 PAY   5 

    0x1ca7f59a,// 45 PAY   6 

    0xf251679b,// 46 PAY   7 

    0x6030bae1,// 47 PAY   8 

    0x11ad6e2a,// 48 PAY   9 

    0xdadee9ea,// 49 PAY  10 

    0xa4ec220c,// 50 PAY  11 

    0x532d62d2,// 51 PAY  12 

    0x014e5dfc,// 52 PAY  13 

    0x0b57a506,// 53 PAY  14 

    0x1759d0df,// 54 PAY  15 

    0x953b18e8,// 55 PAY  16 

    0x2372424e,// 56 PAY  17 

    0x02505869,// 57 PAY  18 

    0xace428ed,// 58 PAY  19 

    0xe6749af7,// 59 PAY  20 

    0x803ad023,// 60 PAY  21 

    0x30782348,// 61 PAY  22 

    0xc187396b,// 62 PAY  23 

    0x09336739,// 63 PAY  24 

    0x79742fe2,// 64 PAY  25 

    0x4452bd9e,// 65 PAY  26 

    0x87562553,// 66 PAY  27 

    0x169fa331,// 67 PAY  28 

    0x73a6ee3b,// 68 PAY  29 

    0x540622a4,// 69 PAY  30 

    0xb2251401,// 70 PAY  31 

    0xca2e3f1d,// 71 PAY  32 

    0x032f24c6,// 72 PAY  33 

    0x393708cc,// 73 PAY  34 

    0x1de6d1f8,// 74 PAY  35 

    0x2d18b8f6,// 75 PAY  36 

    0x9cc327b4,// 76 PAY  37 

    0x03bf3048,// 77 PAY  38 

    0x863c6837,// 78 PAY  39 

    0x9107d52d,// 79 PAY  40 

    0xdbe12a0c,// 80 PAY  41 

    0xcc25a7a0,// 81 PAY  42 

    0xbeb03e32,// 82 PAY  43 

    0x36d00207,// 83 PAY  44 

    0x1265dc10,// 84 PAY  45 

    0x09f2b5de,// 85 PAY  46 

    0x87c46750,// 86 PAY  47 

    0x6a36910b,// 87 PAY  48 

    0xf827d430,// 88 PAY  49 

    0x52a5d740,// 89 PAY  50 

    0xc1b5af78,// 90 PAY  51 

    0x96b2dd38,// 91 PAY  52 

    0x08cf8b57,// 92 PAY  53 

    0x2f145be0,// 93 PAY  54 

    0x7474495f,// 94 PAY  55 

    0xff89846a,// 95 PAY  56 

    0xccb74e8f,// 96 PAY  57 

    0x91bd36e9,// 97 PAY  58 

    0x723df8d1,// 98 PAY  59 

    0x6821e29e,// 99 PAY  60 

    0xdefd66aa,// 100 PAY  61 

    0x6c38e332,// 101 PAY  62 

    0x16285b2e,// 102 PAY  63 

    0xc91ac647,// 103 PAY  64 

    0x6a68f23c,// 104 PAY  65 

    0x0842200f,// 105 PAY  66 

    0x8ebd3bca,// 106 PAY  67 

    0x15bfa6c8,// 107 PAY  68 

    0x326a7c7d,// 108 PAY  69 

    0x67ccc261,// 109 PAY  70 

    0xa20a578c,// 110 PAY  71 

    0x1222dc20,// 111 PAY  72 

    0xcb5ad47c,// 112 PAY  73 

    0x533373f8,// 113 PAY  74 

    0x23da587d,// 114 PAY  75 

    0x68b4428b,// 115 PAY  76 

    0x95932047,// 116 PAY  77 

    0x02f6ca10,// 117 PAY  78 

    0xf1d532ca,// 118 PAY  79 

    0xcaba03ac,// 119 PAY  80 

    0xcceb16f7,// 120 PAY  81 

    0xeabfb0a8,// 121 PAY  82 

    0x2a5ebbe9,// 122 PAY  83 

    0x6a011d49,// 123 PAY  84 

    0x1cfe031c,// 124 PAY  85 

    0xcde76817,// 125 PAY  86 

    0xea599a64,// 126 PAY  87 

    0x1f73c872,// 127 PAY  88 

    0xd7ad108d,// 128 PAY  89 

    0x489b229f,// 129 PAY  90 

    0x44bffe93,// 130 PAY  91 

    0x3a16432c,// 131 PAY  92 

    0x60fdf234,// 132 PAY  93 

    0x6c72190c,// 133 PAY  94 

    0x637fa6f6,// 134 PAY  95 

    0xfb8cd506,// 135 PAY  96 

    0x32eddabe,// 136 PAY  97 

    0x692ea1a2,// 137 PAY  98 

    0x70d53310,// 138 PAY  99 

    0x5f2e7f19,// 139 PAY 100 

    0xf84323d8,// 140 PAY 101 

    0xce04131c,// 141 PAY 102 

    0xe03311f9,// 142 PAY 103 

    0xb6685f52,// 143 PAY 104 

    0xd663d425,// 144 PAY 105 

    0x0daa0ada,// 145 PAY 106 

    0x0740b51f,// 146 PAY 107 

    0x695d2fc3,// 147 PAY 108 

    0x71569914,// 148 PAY 109 

    0xa81fc066,// 149 PAY 110 

    0xb56dda9b,// 150 PAY 111 

    0xe7b69c22,// 151 PAY 112 

    0x0504ab1a,// 152 PAY 113 

    0xe5132282,// 153 PAY 114 

    0x19484ab4,// 154 PAY 115 

    0x7baafe7d,// 155 PAY 116 

    0x94aa781d,// 156 PAY 117 

    0x163a5ad5,// 157 PAY 118 

    0x32c8950f,// 158 PAY 119 

    0x4f0d7520,// 159 PAY 120 

    0x75a43a31,// 160 PAY 121 

    0x9640a5a6,// 161 PAY 122 

    0x301a2676,// 162 PAY 123 

    0x11ae0955,// 163 PAY 124 

    0x0b6e7d5f,// 164 PAY 125 

    0xdbeccf49,// 165 PAY 126 

    0x2ce34440,// 166 PAY 127 

    0xd03a753c,// 167 PAY 128 

    0xe970a9a8,// 168 PAY 129 

    0xb14edfd7,// 169 PAY 130 

    0x0dc94918,// 170 PAY 131 

    0x7fee7170,// 171 PAY 132 

    0x560a62e1,// 172 PAY 133 

    0xeb9a3866,// 173 PAY 134 

    0x419d37f9,// 174 PAY 135 

    0x9a799479,// 175 PAY 136 

    0x0d9a8c3b,// 176 PAY 137 

    0x3132f29d,// 177 PAY 138 

    0xd4d4284f,// 178 PAY 139 

    0x3e9f8ff5,// 179 PAY 140 

    0xdba66d70,// 180 PAY 141 

    0x7fc6615b,// 181 PAY 142 

    0xbf2b8e06,// 182 PAY 143 

    0x60c5d2a5,// 183 PAY 144 

    0xbcc2b5b1,// 184 PAY 145 

    0x6ebcfa97,// 185 PAY 146 

    0xab51c478,// 186 PAY 147 

    0xac542351,// 187 PAY 148 

    0xb7dca2e4,// 188 PAY 149 

    0x1d08ab1e,// 189 PAY 150 

    0x831eda19,// 190 PAY 151 

    0xfb87d30f,// 191 PAY 152 

    0xecb00cd0,// 192 PAY 153 

    0x7fc0f5ec,// 193 PAY 154 

    0x17627623,// 194 PAY 155 

    0x125f0b8f,// 195 PAY 156 

    0x91b42fe5,// 196 PAY 157 

    0x8ae3f484,// 197 PAY 158 

    0x71ccd923,// 198 PAY 159 

    0xd9050008,// 199 PAY 160 

    0x91fe32b1,// 200 PAY 161 

    0x7152dcb3,// 201 PAY 162 

    0x808d6c6b,// 202 PAY 163 

    0xa1bb19e6,// 203 PAY 164 

    0x7cd7da9c,// 204 PAY 165 

    0xc6e583ab,// 205 PAY 166 

    0x5bafcdeb,// 206 PAY 167 

    0x047b13f0,// 207 PAY 168 

    0xd4c70a2c,// 208 PAY 169 

    0xb0ab1f38,// 209 PAY 170 

    0x0c233931,// 210 PAY 171 

    0xe83c25cd,// 211 PAY 172 

    0x8b24a1c5,// 212 PAY 173 

    0x5c88c23c,// 213 PAY 174 

    0xa6cce20d,// 214 PAY 175 

    0xbd56a0c2,// 215 PAY 176 

    0x679cd755,// 216 PAY 177 

    0x6e0de435,// 217 PAY 178 

    0xdd55a67e,// 218 PAY 179 

    0x0c1d8ac8,// 219 PAY 180 

    0x60e4dcbd,// 220 PAY 181 

    0xf62b111e,// 221 PAY 182 

    0x84146f7e,// 222 PAY 183 

    0x67120b0e,// 223 PAY 184 

    0xef440c25,// 224 PAY 185 

    0xc4798bb6,// 225 PAY 186 

    0x1b5d8750,// 226 PAY 187 

    0x581b0c17,// 227 PAY 188 

    0x90ec162c,// 228 PAY 189 

    0xda2e9a0a,// 229 PAY 190 

    0xb230b007,// 230 PAY 191 

    0x8feaea08,// 231 PAY 192 

    0xf8e2e068,// 232 PAY 193 

    0x3fb3601b,// 233 PAY 194 

    0xc4b0e8a7,// 234 PAY 195 

    0x89347f9b,// 235 PAY 196 

    0xfd1d64b7,// 236 PAY 197 

    0x205196bf,// 237 PAY 198 

    0x33bdb9f6,// 238 PAY 199 

    0x1b3e1b6e,// 239 PAY 200 

    0x946f5021,// 240 PAY 201 

    0x079e0e03,// 241 PAY 202 

    0xa529fb62,// 242 PAY 203 

    0x960fed2b,// 243 PAY 204 

    0x407812d7,// 244 PAY 205 

    0x4497f3fa,// 245 PAY 206 

    0x2c092589,// 246 PAY 207 

    0x9c4b2111,// 247 PAY 208 

    0x2ed537d3,// 248 PAY 209 

    0x54bbdacc,// 249 PAY 210 

    0x2be45f36,// 250 PAY 211 

    0x5f282ce1,// 251 PAY 212 

    0x1106a33a,// 252 PAY 213 

    0xde860296,// 253 PAY 214 

    0x95cc7d47,// 254 PAY 215 

    0xf5266bf0,// 255 PAY 216 

    0x5d4354ad,// 256 PAY 217 

    0xcf17bab3,// 257 PAY 218 

    0x9651b996,// 258 PAY 219 

    0xa1e0d2ae,// 259 PAY 220 

    0x14828fd1,// 260 PAY 221 

    0x8df01e34,// 261 PAY 222 

    0x1068586b,// 262 PAY 223 

    0xe25418cd,// 263 PAY 224 

    0x70a870fe,// 264 PAY 225 

    0x324e895e,// 265 PAY 226 

    0xed47463a,// 266 PAY 227 

    0x2bb2029c,// 267 PAY 228 

    0x246873b0,// 268 PAY 229 

    0xc49d6e33,// 269 PAY 230 

    0xed7c682e,// 270 PAY 231 

    0x69ea0c4e,// 271 PAY 232 

    0xfd8d79b1,// 272 PAY 233 

    0x8e377392,// 273 PAY 234 

    0x83111738,// 274 PAY 235 

    0x8abe8215,// 275 PAY 236 

    0x62c09df7,// 276 PAY 237 

    0xabc442d9,// 277 PAY 238 

    0xa935778a,// 278 PAY 239 

    0x8d6cafa8,// 279 PAY 240 

    0x925dd073,// 280 PAY 241 

    0x8f1fcea9,// 281 PAY 242 

    0x9eac871c,// 282 PAY 243 

    0x32617f09,// 283 PAY 244 

    0x2595fdfd,// 284 PAY 245 

    0x658d83d4,// 285 PAY 246 

    0x2b410000,// 286 PAY 247 

/// STA is 1 words. 

/// STA num_pkts       : 59 

/// STA pkt_idx        : 20 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xb6 

    0x0050b63b // 287 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt52_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0d 

/// ECH pdu_tag        : 0x00 

    0x000d0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x809028db,// 4 SCX   2 

    0x000073c2,// 5 SCX   3 

    0x946dabb8,// 6 SCX   4 

    0x7bb91c7e,// 7 SCX   5 

    0x689eefb0,// 8 SCX   6 

    0x148c86e8,// 9 SCX   7 

    0x2eb2d5b0,// 10 SCX   8 

    0x1b16f719,// 11 SCX   9 

    0xb0a03199,// 12 SCX  10 

    0x020592bd,// 13 SCX  11 

    0x1bdcff85,// 14 SCX  12 

    0x712c9479,// 15 SCX  13 

    0x5ee4dbf8,// 16 SCX  14 

    0x05800b46,// 17 SCX  15 

    0x08161d13,// 18 SCX  16 

    0x486c1be3,// 19 SCX  17 

    0xe82cea3f,// 20 SCX  18 

    0xf66d1add,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 55 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 29 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 29 

/// BFD lencrypto      : 8 

/// BFD ofstcrypto     : 16 

/// BFD (ofst+len)cry  : 24 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 32 

    0x0000001d,// 22 BFD   1 

    0x00100008,// 23 BFD   2 

    0x00200000,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 6 

    0x0600e382,// 25 MFM   1 

    0xdc000000,// 26 MFM   2 

/// BDA is 15 words. 

/// BDA size     is 55 (0x37) 

/// BDA id       is 0xa607 

    0x0037a607,// 27 BDA   1 

/// PAY Generic Data size   : 55 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x3cc2368f,// 28 PAY   1 

    0x88f7f10e,// 29 PAY   2 

    0x148636ad,// 30 PAY   3 

    0x4e133cac,// 31 PAY   4 

    0x1a0dc325,// 32 PAY   5 

    0x122000d0,// 33 PAY   6 

    0xb990f0ee,// 34 PAY   7 

    0x8a2e3dc6,// 35 PAY   8 

    0x47f897f8,// 36 PAY   9 

    0x35bd8853,// 37 PAY  10 

    0x5cd0c8fb,// 38 PAY  11 

    0x2182984e,// 39 PAY  12 

    0x311b307a,// 40 PAY  13 

    0x2b40ef00,// 41 PAY  14 

/// STA is 1 words. 

/// STA num_pkts       : 163 

/// STA pkt_idx        : 246 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x58 

    0x03d958a3 // 42 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt53_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8082283a,// 4 SCX   2 

    0x00000300,// 5 SCX   3 

    0xa93670d3,// 6 SCX   4 

    0x62f5f788,// 7 SCX   5 

    0xed045635,// 8 SCX   6 

    0xf514726a,// 9 SCX   7 

    0x2194a07a,// 10 SCX   8 

    0x919779a1,// 11 SCX   9 

    0xe53e5f64,// 12 SCX  10 

    0xcb17a796,// 13 SCX  11 

    0xbf094d4e,// 14 SCX  12 

    0x674f05b4,// 15 SCX  13 

    0x3ece31ae,// 16 SCX  14 

    0xcf29ce5a,// 17 SCX  15 

    0xff05f7b5,// 18 SCX  16 

    0xd5f48651,// 19 SCX  17 

    0x28810fb0,// 20 SCX  18 

    0xd28cb6e6,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 83 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 49 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 49 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 20 

/// BFD (ofst+len)cry  : 36 

/// BFD ofstiv         : 4 

/// BFD ofsticv        : 60 

    0x00000031,// 22 BFD   1 

    0x00140010,// 23 BFD   2 

    0x003c0004,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : b 

    0x0b009b0a,// 25 MFM   1 

    0xeadd2890,// 26 MFM   2 

/// BDA is 22 words. 

/// BDA size     is 83 (0x53) 

/// BDA id       is 0x7e9d 

    0x00537e9d,// 27 BDA   1 

/// PAY Generic Data size   : 83 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x463aaec9,// 28 PAY   1 

    0xe8c269a4,// 29 PAY   2 

    0x6a312146,// 30 PAY   3 

    0x944f5e19,// 31 PAY   4 

    0xfe819aec,// 32 PAY   5 

    0xf19b0c6d,// 33 PAY   6 

    0x903f64da,// 34 PAY   7 

    0xe7c64213,// 35 PAY   8 

    0xc45ebf4e,// 36 PAY   9 

    0xa0d3479c,// 37 PAY  10 

    0x0166b1e6,// 38 PAY  11 

    0x1040b6ab,// 39 PAY  12 

    0x88c6dad6,// 40 PAY  13 

    0xa0d29a23,// 41 PAY  14 

    0x142aa939,// 42 PAY  15 

    0x3aff10e6,// 43 PAY  16 

    0x2c158463,// 44 PAY  17 

    0xa51efc35,// 45 PAY  18 

    0x7c540825,// 46 PAY  19 

    0x32bb54a0,// 47 PAY  20 

    0x1846e700,// 48 PAY  21 

/// STA is 1 words. 

/// STA num_pkts       : 6 

/// STA pkt_idx        : 44 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xf8 

    0x00b1f806 // 49 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt54_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x8085284b,// 4 SCX   2 

    0x000063c4,// 5 SCX   3 

    0x35a5aa24,// 6 SCX   4 

    0x4d66de79,// 7 SCX   5 

    0x38c3c633,// 8 SCX   6 

    0x334538bc,// 9 SCX   7 

    0x8a78ab13,// 10 SCX   8 

    0x25b3a235,// 11 SCX   9 

    0x83a8c1d0,// 12 SCX  10 

    0x9683e40d,// 13 SCX  11 

    0x78d6a516,// 14 SCX  12 

    0xa7deca4c,// 15 SCX  13 

    0x35634db4,// 16 SCX  14 

    0xfc5cf70c,// 17 SCX  15 

    0xa6022630,// 18 SCX  16 

    0x843a67da,// 19 SCX  17 

    0xa3ae8422,// 20 SCX  18 

    0xc5ebaccf,// 21 SCX  19 

    0xe2f7dd5b,// 22 SCX  20 

    0x8da10717,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1852 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 213 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 213 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 108 

/// BFD (ofst+len)cry  : 188 

/// BFD ofstiv         : 8 

/// BFD ofsticv        : 1116 

    0x000000d5,// 24 BFD   1 

    0x006c0050,// 25 BFD   2 

    0x045c0008,// 26 BFD   3 

/// MFM is 4 words. 

/// MFM vldnibs        : 1b 

    0x1b009858,// 27 MFM   1 

    0xdb99e7eb,// 28 MFM   2 

    0x72611b53,// 29 MFM   3 

    0x2b516000,// 30 MFM   4 

/// BDA is 464 words. 

/// BDA size     is 1852 (0x73c) 

/// BDA id       is 0x5aee 

    0x073c5aee,// 31 BDA   1 

/// PAY Generic Data size   : 1852 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xab66ef16,// 32 PAY   1 

    0xc332dca5,// 33 PAY   2 

    0xc8736184,// 34 PAY   3 

    0x8fce97b8,// 35 PAY   4 

    0xaa35a01c,// 36 PAY   5 

    0xfd7febf6,// 37 PAY   6 

    0x524c769b,// 38 PAY   7 

    0xeb58543f,// 39 PAY   8 

    0x613d59f7,// 40 PAY   9 

    0xb811f535,// 41 PAY  10 

    0x99d32fa9,// 42 PAY  11 

    0x3f2e8bc2,// 43 PAY  12 

    0xce43b0b5,// 44 PAY  13 

    0x96b1e478,// 45 PAY  14 

    0x4018041d,// 46 PAY  15 

    0xc586d5d8,// 47 PAY  16 

    0x46dd7ce1,// 48 PAY  17 

    0x3be88ba5,// 49 PAY  18 

    0xfcabeb34,// 50 PAY  19 

    0x5232c3d1,// 51 PAY  20 

    0x9b0e49c7,// 52 PAY  21 

    0x628c7e58,// 53 PAY  22 

    0x74e764c7,// 54 PAY  23 

    0xe01ca325,// 55 PAY  24 

    0xbffc8be5,// 56 PAY  25 

    0x456acc37,// 57 PAY  26 

    0x921523eb,// 58 PAY  27 

    0x208ef8b4,// 59 PAY  28 

    0xde67b305,// 60 PAY  29 

    0x7dfda55a,// 61 PAY  30 

    0xe44b3cf2,// 62 PAY  31 

    0x8e42426c,// 63 PAY  32 

    0x9b35594a,// 64 PAY  33 

    0x17269032,// 65 PAY  34 

    0x2522d71d,// 66 PAY  35 

    0x160403f3,// 67 PAY  36 

    0x6df8b2db,// 68 PAY  37 

    0x0d341412,// 69 PAY  38 

    0xe1d07f85,// 70 PAY  39 

    0xe8c1befd,// 71 PAY  40 

    0xc3201763,// 72 PAY  41 

    0x7f221f7b,// 73 PAY  42 

    0x9e22248e,// 74 PAY  43 

    0x9efc040c,// 75 PAY  44 

    0x82f569e7,// 76 PAY  45 

    0x5ab8071d,// 77 PAY  46 

    0x3adb284a,// 78 PAY  47 

    0xcb05a472,// 79 PAY  48 

    0xe3d4755b,// 80 PAY  49 

    0x0f0bf1be,// 81 PAY  50 

    0x880ea952,// 82 PAY  51 

    0x0bbe7764,// 83 PAY  52 

    0x36cdcc2d,// 84 PAY  53 

    0x98941fb0,// 85 PAY  54 

    0x9284cebb,// 86 PAY  55 

    0x78c75c13,// 87 PAY  56 

    0xe8210d7d,// 88 PAY  57 

    0x3662fa6c,// 89 PAY  58 

    0x2331cf20,// 90 PAY  59 

    0xd58f1e91,// 91 PAY  60 

    0x1418d288,// 92 PAY  61 

    0xb9991659,// 93 PAY  62 

    0x562e4926,// 94 PAY  63 

    0x1d00aa99,// 95 PAY  64 

    0xfc4b579c,// 96 PAY  65 

    0xfb263012,// 97 PAY  66 

    0xb63d5c1a,// 98 PAY  67 

    0xa200ecbb,// 99 PAY  68 

    0x4ba48b16,// 100 PAY  69 

    0xaf669c76,// 101 PAY  70 

    0x82086938,// 102 PAY  71 

    0x5a05f6f9,// 103 PAY  72 

    0xb4259c9b,// 104 PAY  73 

    0xad31094d,// 105 PAY  74 

    0xcf799539,// 106 PAY  75 

    0x9bebd5e5,// 107 PAY  76 

    0x2d04d41b,// 108 PAY  77 

    0x51363a0f,// 109 PAY  78 

    0xf92493ed,// 110 PAY  79 

    0x93c62bae,// 111 PAY  80 

    0xf2c1c589,// 112 PAY  81 

    0x609835ad,// 113 PAY  82 

    0xe004eca6,// 114 PAY  83 

    0xd67bed45,// 115 PAY  84 

    0xd0caa9ce,// 116 PAY  85 

    0xcfc22428,// 117 PAY  86 

    0x54c413d8,// 118 PAY  87 

    0x07678020,// 119 PAY  88 

    0x36b37279,// 120 PAY  89 

    0x3541c84e,// 121 PAY  90 

    0x23283abb,// 122 PAY  91 

    0x81e950bb,// 123 PAY  92 

    0xb1545b81,// 124 PAY  93 

    0xa5b24a35,// 125 PAY  94 

    0xedfbaa33,// 126 PAY  95 

    0xfe1a7f41,// 127 PAY  96 

    0x888c1ef4,// 128 PAY  97 

    0x79fafc92,// 129 PAY  98 

    0x84791732,// 130 PAY  99 

    0x4f3b604c,// 131 PAY 100 

    0xca32f0aa,// 132 PAY 101 

    0xb3b9cf25,// 133 PAY 102 

    0xf75d23d7,// 134 PAY 103 

    0xe3f09c0b,// 135 PAY 104 

    0x13752c22,// 136 PAY 105 

    0x4a120f9d,// 137 PAY 106 

    0x4eb3252b,// 138 PAY 107 

    0xf17d190c,// 139 PAY 108 

    0x6759478b,// 140 PAY 109 

    0xd83f6554,// 141 PAY 110 

    0xa8c2c6ba,// 142 PAY 111 

    0x4acb9143,// 143 PAY 112 

    0xb021590f,// 144 PAY 113 

    0xa7ac0c61,// 145 PAY 114 

    0xa36afd51,// 146 PAY 115 

    0x30fce586,// 147 PAY 116 

    0xf87b61ca,// 148 PAY 117 

    0x7f67dbb8,// 149 PAY 118 

    0x4825f0d6,// 150 PAY 119 

    0xf9c15b92,// 151 PAY 120 

    0x4b955d8d,// 152 PAY 121 

    0x83ed81f2,// 153 PAY 122 

    0x92a53a85,// 154 PAY 123 

    0xcb532586,// 155 PAY 124 

    0x507b7041,// 156 PAY 125 

    0xfe111aef,// 157 PAY 126 

    0x7d4028b9,// 158 PAY 127 

    0x7160de24,// 159 PAY 128 

    0x0dc9d3f5,// 160 PAY 129 

    0x8fdd8f8a,// 161 PAY 130 

    0x138fae1b,// 162 PAY 131 

    0x05579e81,// 163 PAY 132 

    0xb031ed10,// 164 PAY 133 

    0xae054342,// 165 PAY 134 

    0xd8087c26,// 166 PAY 135 

    0x3dd09951,// 167 PAY 136 

    0x6eb1d89d,// 168 PAY 137 

    0xeb237666,// 169 PAY 138 

    0x5243a90b,// 170 PAY 139 

    0x24b82e85,// 171 PAY 140 

    0xaac5c0a7,// 172 PAY 141 

    0x617c4f2d,// 173 PAY 142 

    0x299fa37f,// 174 PAY 143 

    0x77453255,// 175 PAY 144 

    0xf7b3f828,// 176 PAY 145 

    0x7f729f94,// 177 PAY 146 

    0x086adaf2,// 178 PAY 147 

    0xe4127c72,// 179 PAY 148 

    0x2e7b8ad5,// 180 PAY 149 

    0x900bcfb1,// 181 PAY 150 

    0x952417d7,// 182 PAY 151 

    0x95da305c,// 183 PAY 152 

    0x6a82e2ac,// 184 PAY 153 

    0x268884c7,// 185 PAY 154 

    0xa4f669df,// 186 PAY 155 

    0x3ba2f808,// 187 PAY 156 

    0x68c5e41a,// 188 PAY 157 

    0x516d0a7f,// 189 PAY 158 

    0xa5bb8720,// 190 PAY 159 

    0x2ed8e7ab,// 191 PAY 160 

    0x6855b92b,// 192 PAY 161 

    0x98f0eea8,// 193 PAY 162 

    0x49ec9df6,// 194 PAY 163 

    0x85442b73,// 195 PAY 164 

    0x2727d963,// 196 PAY 165 

    0xd294083a,// 197 PAY 166 

    0x88a024f0,// 198 PAY 167 

    0x8ef5144d,// 199 PAY 168 

    0xd8f103e2,// 200 PAY 169 

    0x6442f7b6,// 201 PAY 170 

    0x5a384eb0,// 202 PAY 171 

    0xe80ec9b7,// 203 PAY 172 

    0x06da3be2,// 204 PAY 173 

    0xd5f53da5,// 205 PAY 174 

    0xdccd3519,// 206 PAY 175 

    0x524162da,// 207 PAY 176 

    0x1d1f3724,// 208 PAY 177 

    0xdd481c0f,// 209 PAY 178 

    0xd3a45c46,// 210 PAY 179 

    0xcab54669,// 211 PAY 180 

    0x7159f035,// 212 PAY 181 

    0x99126524,// 213 PAY 182 

    0xc60b3eb6,// 214 PAY 183 

    0x07119e51,// 215 PAY 184 

    0x6826dac5,// 216 PAY 185 

    0x8f94be1e,// 217 PAY 186 

    0x38b218b7,// 218 PAY 187 

    0x6de88dbb,// 219 PAY 188 

    0x9c94547a,// 220 PAY 189 

    0x089d1988,// 221 PAY 190 

    0xa21c8b0a,// 222 PAY 191 

    0x46b51503,// 223 PAY 192 

    0x831bd5da,// 224 PAY 193 

    0x4dcd7299,// 225 PAY 194 

    0xe8335c1f,// 226 PAY 195 

    0x155f47f1,// 227 PAY 196 

    0xd81b16c3,// 228 PAY 197 

    0xe049ea6f,// 229 PAY 198 

    0x0fc1f4d2,// 230 PAY 199 

    0x10ad1209,// 231 PAY 200 

    0x3e0c1ea6,// 232 PAY 201 

    0x80339bca,// 233 PAY 202 

    0xbe63d237,// 234 PAY 203 

    0x291036a0,// 235 PAY 204 

    0x02607235,// 236 PAY 205 

    0xc834b844,// 237 PAY 206 

    0x27e94cc0,// 238 PAY 207 

    0xa966b28d,// 239 PAY 208 

    0x99cc57f3,// 240 PAY 209 

    0xce67aa5f,// 241 PAY 210 

    0xb4a97d6e,// 242 PAY 211 

    0x10e0756b,// 243 PAY 212 

    0x7b762e47,// 244 PAY 213 

    0xb70c132e,// 245 PAY 214 

    0x938d56c4,// 246 PAY 215 

    0x54707b4b,// 247 PAY 216 

    0x3b8e71ed,// 248 PAY 217 

    0x63721776,// 249 PAY 218 

    0xdc5bc249,// 250 PAY 219 

    0xa57d50e0,// 251 PAY 220 

    0x9cdce3e0,// 252 PAY 221 

    0x26d10e72,// 253 PAY 222 

    0x3a81973e,// 254 PAY 223 

    0x14f69174,// 255 PAY 224 

    0xb9fc0c4a,// 256 PAY 225 

    0xa28a7e99,// 257 PAY 226 

    0xb2ecfda2,// 258 PAY 227 

    0x18e7656a,// 259 PAY 228 

    0x94aeb1c5,// 260 PAY 229 

    0xf724dd62,// 261 PAY 230 

    0x9250b7cb,// 262 PAY 231 

    0xfd0a9d4e,// 263 PAY 232 

    0x76b4ffe6,// 264 PAY 233 

    0x81f87e59,// 265 PAY 234 

    0x31b0dd90,// 266 PAY 235 

    0xc62ae5c9,// 267 PAY 236 

    0x4bbeb28a,// 268 PAY 237 

    0x88b534bf,// 269 PAY 238 

    0xec765fec,// 270 PAY 239 

    0x18c9a205,// 271 PAY 240 

    0xd8e707b9,// 272 PAY 241 

    0x63cb4476,// 273 PAY 242 

    0xd5cea86a,// 274 PAY 243 

    0x0b906469,// 275 PAY 244 

    0x4549d445,// 276 PAY 245 

    0xe962031b,// 277 PAY 246 

    0x1dab833d,// 278 PAY 247 

    0xc7a18535,// 279 PAY 248 

    0x2d534c4c,// 280 PAY 249 

    0x9dc04ab0,// 281 PAY 250 

    0x789cb33e,// 282 PAY 251 

    0xe6694bc3,// 283 PAY 252 

    0x3486ca4b,// 284 PAY 253 

    0xd54a43b1,// 285 PAY 254 

    0x9d95f4cc,// 286 PAY 255 

    0xf62c2e1a,// 287 PAY 256 

    0x0b761e96,// 288 PAY 257 

    0x4558c712,// 289 PAY 258 

    0x49f9d23e,// 290 PAY 259 

    0xc78482a9,// 291 PAY 260 

    0x30ede6ba,// 292 PAY 261 

    0x09a01f4b,// 293 PAY 262 

    0x475b0f71,// 294 PAY 263 

    0x042ebbaa,// 295 PAY 264 

    0x06caedc4,// 296 PAY 265 

    0x8898438c,// 297 PAY 266 

    0xbc309fe8,// 298 PAY 267 

    0x13160585,// 299 PAY 268 

    0x08689656,// 300 PAY 269 

    0xb8f045cd,// 301 PAY 270 

    0x27ed3198,// 302 PAY 271 

    0x29d85e52,// 303 PAY 272 

    0xf2446ade,// 304 PAY 273 

    0x11e3eda5,// 305 PAY 274 

    0xeeabd191,// 306 PAY 275 

    0x63d6dad5,// 307 PAY 276 

    0x82ec1960,// 308 PAY 277 

    0x71e5381c,// 309 PAY 278 

    0x2509fed7,// 310 PAY 279 

    0xf1a2aaa5,// 311 PAY 280 

    0xb927ea9c,// 312 PAY 281 

    0x228de553,// 313 PAY 282 

    0x856c8e9d,// 314 PAY 283 

    0xc914a76f,// 315 PAY 284 

    0x70133578,// 316 PAY 285 

    0x0ff65093,// 317 PAY 286 

    0x929a03b3,// 318 PAY 287 

    0xeb14063e,// 319 PAY 288 

    0x31fcd461,// 320 PAY 289 

    0x51851d12,// 321 PAY 290 

    0xdd49d5e4,// 322 PAY 291 

    0xe8d52e5f,// 323 PAY 292 

    0x2aa9d45a,// 324 PAY 293 

    0x46f924ec,// 325 PAY 294 

    0xb69bb809,// 326 PAY 295 

    0xbe756ad4,// 327 PAY 296 

    0x16f33fa5,// 328 PAY 297 

    0xfc647f43,// 329 PAY 298 

    0x7d6db0e3,// 330 PAY 299 

    0xeb0f0130,// 331 PAY 300 

    0x4da1852c,// 332 PAY 301 

    0xbfc9d6cf,// 333 PAY 302 

    0x607f496a,// 334 PAY 303 

    0x85b4395c,// 335 PAY 304 

    0xe0936c50,// 336 PAY 305 

    0x57f3473f,// 337 PAY 306 

    0xe019ceb2,// 338 PAY 307 

    0xfd89c236,// 339 PAY 308 

    0x00ff0f10,// 340 PAY 309 

    0x5cbc9958,// 341 PAY 310 

    0x89f67140,// 342 PAY 311 

    0x433c61c8,// 343 PAY 312 

    0xc9571530,// 344 PAY 313 

    0xe6a92fd0,// 345 PAY 314 

    0xa33a3290,// 346 PAY 315 

    0xfcf97e9f,// 347 PAY 316 

    0xc35bec09,// 348 PAY 317 

    0x6d11997e,// 349 PAY 318 

    0xa2aaf1a6,// 350 PAY 319 

    0x5fc7e900,// 351 PAY 320 

    0x57a39e1f,// 352 PAY 321 

    0xe629870d,// 353 PAY 322 

    0x63f33559,// 354 PAY 323 

    0x3eff6dc3,// 355 PAY 324 

    0x1984b4a7,// 356 PAY 325 

    0xa1ae0ac7,// 357 PAY 326 

    0xf9c77b9e,// 358 PAY 327 

    0xaf1e7819,// 359 PAY 328 

    0xe6f5b17f,// 360 PAY 329 

    0x2a01a165,// 361 PAY 330 

    0xbffc4823,// 362 PAY 331 

    0xe423c42f,// 363 PAY 332 

    0x637951d9,// 364 PAY 333 

    0x64edfa52,// 365 PAY 334 

    0xd5342673,// 366 PAY 335 

    0xc795f10c,// 367 PAY 336 

    0x051a4197,// 368 PAY 337 

    0xdfea2f35,// 369 PAY 338 

    0x12c3a629,// 370 PAY 339 

    0x886a29ac,// 371 PAY 340 

    0x4124472c,// 372 PAY 341 

    0xb57582ab,// 373 PAY 342 

    0x8f6c6700,// 374 PAY 343 

    0x8d77351e,// 375 PAY 344 

    0xd91d2401,// 376 PAY 345 

    0x8caa96ad,// 377 PAY 346 

    0xa729da22,// 378 PAY 347 

    0x121223a3,// 379 PAY 348 

    0xf21f1a29,// 380 PAY 349 

    0x08943e93,// 381 PAY 350 

    0xffef8323,// 382 PAY 351 

    0x54d5c59a,// 383 PAY 352 

    0xab9863e8,// 384 PAY 353 

    0xf5346aaa,// 385 PAY 354 

    0xc5d7f2f9,// 386 PAY 355 

    0x14588d96,// 387 PAY 356 

    0xe7cd651c,// 388 PAY 357 

    0x62ab6d51,// 389 PAY 358 

    0x2444cce5,// 390 PAY 359 

    0x979c849d,// 391 PAY 360 

    0xa775b95d,// 392 PAY 361 

    0x55ebec01,// 393 PAY 362 

    0x79c964b7,// 394 PAY 363 

    0xc8748589,// 395 PAY 364 

    0x70a01c25,// 396 PAY 365 

    0xbee2341d,// 397 PAY 366 

    0x37819548,// 398 PAY 367 

    0xc4d8c738,// 399 PAY 368 

    0xc4f0270a,// 400 PAY 369 

    0x4077a65c,// 401 PAY 370 

    0x81c49666,// 402 PAY 371 

    0x6b177c6e,// 403 PAY 372 

    0x0b3639f8,// 404 PAY 373 

    0x37a4b143,// 405 PAY 374 

    0x9c5ad977,// 406 PAY 375 

    0x57c4318b,// 407 PAY 376 

    0x920b5aba,// 408 PAY 377 

    0xd8886258,// 409 PAY 378 

    0xdd9d7753,// 410 PAY 379 

    0xa323a810,// 411 PAY 380 

    0x00131494,// 412 PAY 381 

    0x3b07fcf9,// 413 PAY 382 

    0x4c16a3ba,// 414 PAY 383 

    0x9af9414b,// 415 PAY 384 

    0x01e8b89c,// 416 PAY 385 

    0x33809159,// 417 PAY 386 

    0x27c0765c,// 418 PAY 387 

    0xbb9235bb,// 419 PAY 388 

    0x8027230c,// 420 PAY 389 

    0xed202f82,// 421 PAY 390 

    0x9af49745,// 422 PAY 391 

    0x0a547460,// 423 PAY 392 

    0xef1607b4,// 424 PAY 393 

    0x08b3c281,// 425 PAY 394 

    0x2255244e,// 426 PAY 395 

    0x192c327d,// 427 PAY 396 

    0x3910f8a1,// 428 PAY 397 

    0x46d7fcc0,// 429 PAY 398 

    0xe5c4fb88,// 430 PAY 399 

    0x670b3600,// 431 PAY 400 

    0x5265df9f,// 432 PAY 401 

    0x9e915a4a,// 433 PAY 402 

    0xb589a55d,// 434 PAY 403 

    0x340d15a4,// 435 PAY 404 

    0x7640e7ca,// 436 PAY 405 

    0x6b1e282e,// 437 PAY 406 

    0xeb226398,// 438 PAY 407 

    0x4a88ea3d,// 439 PAY 408 

    0xee0b78f3,// 440 PAY 409 

    0x0a102052,// 441 PAY 410 

    0xfe35d828,// 442 PAY 411 

    0xfa142d8c,// 443 PAY 412 

    0x76293948,// 444 PAY 413 

    0x0446e56b,// 445 PAY 414 

    0x3cfbca72,// 446 PAY 415 

    0xf7d1d709,// 447 PAY 416 

    0x6e1013c1,// 448 PAY 417 

    0x055aec7a,// 449 PAY 418 

    0x285a836d,// 450 PAY 419 

    0xea3a772d,// 451 PAY 420 

    0x65eb5deb,// 452 PAY 421 

    0x013f08b8,// 453 PAY 422 

    0x59b1a2f4,// 454 PAY 423 

    0x84ee08eb,// 455 PAY 424 

    0xa95bf4cd,// 456 PAY 425 

    0x8fd2a538,// 457 PAY 426 

    0x2fa49aef,// 458 PAY 427 

    0x4aa7bb77,// 459 PAY 428 

    0x80584b41,// 460 PAY 429 

    0xc88c4446,// 461 PAY 430 

    0xf1808ac1,// 462 PAY 431 

    0x40227348,// 463 PAY 432 

    0x68418129,// 464 PAY 433 

    0x3da18e54,// 465 PAY 434 

    0xe2fdcbfd,// 466 PAY 435 

    0xfd77fb0c,// 467 PAY 436 

    0x97f16fce,// 468 PAY 437 

    0x704792fe,// 469 PAY 438 

    0xf02a9f52,// 470 PAY 439 

    0x7108cdf6,// 471 PAY 440 

    0xca38bd16,// 472 PAY 441 

    0xe3bd9b07,// 473 PAY 442 

    0xe0738a5d,// 474 PAY 443 

    0x7a0608f4,// 475 PAY 444 

    0x86e3cae6,// 476 PAY 445 

    0x9a198333,// 477 PAY 446 

    0x749ad119,// 478 PAY 447 

    0x567ddabe,// 479 PAY 448 

    0xd7b6b8e6,// 480 PAY 449 

    0x132c3b49,// 481 PAY 450 

    0xca34b149,// 482 PAY 451 

    0xf40893b4,// 483 PAY 452 

    0x53de108f,// 484 PAY 453 

    0x3bc77048,// 485 PAY 454 

    0xaecda5d8,// 486 PAY 455 

    0x4215625d,// 487 PAY 456 

    0x343c7991,// 488 PAY 457 

    0xfb8bc66e,// 489 PAY 458 

    0xf06cc44c,// 490 PAY 459 

    0x504caddf,// 491 PAY 460 

    0x4a3bb9c4,// 492 PAY 461 

    0x1734103e,// 493 PAY 462 

    0xc80718b6,// 494 PAY 463 

/// STA is 1 words. 

/// STA num_pkts       : 33 

/// STA pkt_idx        : 109 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x19 

    0x01b41921 // 495 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt55_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x03 

/// ECH pdu_tag        : 0x00 

    0x00030000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x808428b2,// 4 SCX   2 

    0x00003484,// 5 SCX   3 

    0x55ee068b,// 6 SCX   4 

    0xd0d83ec8,// 7 SCX   5 

    0xf8b0a5ff,// 8 SCX   6 

    0x2122ffb6,// 9 SCX   7 

    0xaf72df1b,// 10 SCX   8 

    0xbe87cb90,// 11 SCX   9 

    0x76ec40f5,// 12 SCX  10 

    0xfc76bee8,// 13 SCX  11 

    0x87110f75,// 14 SCX  12 

    0xf57b477c,// 15 SCX  13 

    0xffa4d232,// 16 SCX  14 

    0x68e37ac6,// 17 SCX  15 

    0x579fd941,// 18 SCX  16 

    0x3a3cd34e,// 19 SCX  17 

    0x1bda53a5,// 20 SCX  18 

    0xe0a3270b,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 662 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 572 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 572 

/// BFD lencrypto      : 448 

/// BFD ofstcrypto     : 108 

/// BFD (ofst+len)cry  : 556 

/// BFD ofstiv         : 48 

/// BFD ofsticv        : 604 

    0x0000023c,// 22 BFD   1 

    0x006c01c0,// 23 BFD   2 

    0x025c0030,// 24 BFD   3 

/// MFM is 15 words. 

/// MFM vldnibs        : 70 

    0x70000e68,// 25 MFM   1 

    0xb184e90d,// 26 MFM   2 

    0x1a28da11,// 27 MFM   3 

    0x18db224d,// 28 MFM   4 

    0xba143f35,// 29 MFM   5 

    0x46827c29,// 30 MFM   6 

    0x16462325,// 31 MFM   7 

    0x35cef9fe,// 32 MFM   8 

    0x1d05016b,// 33 MFM   9 

    0xa3b8681a,// 34 MFM  10 

    0x1e23c79e,// 35 MFM  11 

    0xc3e4a2eb,// 36 MFM  12 

    0x79bfc286,// 37 MFM  13 

    0xcdc9302f,// 38 MFM  14 

    0xc9950000,// 39 MFM  15 

/// BDA is 167 words. 

/// BDA size     is 662 (0x296) 

/// BDA id       is 0x49d1 

    0x029649d1,// 40 BDA   1 

/// PAY Generic Data size   : 662 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xb521271b,// 41 PAY   1 

    0x37785e81,// 42 PAY   2 

    0x2dd2e6b6,// 43 PAY   3 

    0x54edfa29,// 44 PAY   4 

    0x601a49a2,// 45 PAY   5 

    0x503b972f,// 46 PAY   6 

    0x4bf2f32d,// 47 PAY   7 

    0x83e8b926,// 48 PAY   8 

    0xf518f492,// 49 PAY   9 

    0x7c259850,// 50 PAY  10 

    0xba1a0c66,// 51 PAY  11 

    0xa2936ee5,// 52 PAY  12 

    0x52e357a6,// 53 PAY  13 

    0x7a1a9bc1,// 54 PAY  14 

    0x72434800,// 55 PAY  15 

    0xe9771ceb,// 56 PAY  16 

    0xf04681b2,// 57 PAY  17 

    0x36c1b3f9,// 58 PAY  18 

    0x76d7d013,// 59 PAY  19 

    0xf2251f7a,// 60 PAY  20 

    0x10df8a5d,// 61 PAY  21 

    0xac7f5792,// 62 PAY  22 

    0xdf39500e,// 63 PAY  23 

    0xd95ce01e,// 64 PAY  24 

    0x961db0f9,// 65 PAY  25 

    0x2b7c13cf,// 66 PAY  26 

    0xe951e51b,// 67 PAY  27 

    0x3225abf7,// 68 PAY  28 

    0xc7ba644f,// 69 PAY  29 

    0xb03a99cb,// 70 PAY  30 

    0xc9d4ee52,// 71 PAY  31 

    0x9e275ee0,// 72 PAY  32 

    0x749b771e,// 73 PAY  33 

    0xe158c795,// 74 PAY  34 

    0x6a4d3a27,// 75 PAY  35 

    0x5b796f91,// 76 PAY  36 

    0x9f95bab1,// 77 PAY  37 

    0x6da75ecf,// 78 PAY  38 

    0x1636a234,// 79 PAY  39 

    0x1425a5b5,// 80 PAY  40 

    0xbff7ced7,// 81 PAY  41 

    0x40c3724a,// 82 PAY  42 

    0x8a2cedab,// 83 PAY  43 

    0x583e82ad,// 84 PAY  44 

    0x048c07af,// 85 PAY  45 

    0x3871c82e,// 86 PAY  46 

    0x3644de7d,// 87 PAY  47 

    0xbd2e99be,// 88 PAY  48 

    0x25460cc4,// 89 PAY  49 

    0xc9845f48,// 90 PAY  50 

    0x2b7df0cc,// 91 PAY  51 

    0xd91fd41b,// 92 PAY  52 

    0x41b97cf1,// 93 PAY  53 

    0x3de33d88,// 94 PAY  54 

    0x62e925f6,// 95 PAY  55 

    0x08cdb064,// 96 PAY  56 

    0x542f938c,// 97 PAY  57 

    0xc085cc76,// 98 PAY  58 

    0x057e8ed8,// 99 PAY  59 

    0xcec666aa,// 100 PAY  60 

    0x754ebd5c,// 101 PAY  61 

    0xc539baa2,// 102 PAY  62 

    0x4eb6b93e,// 103 PAY  63 

    0x9ab08c2e,// 104 PAY  64 

    0x39e1eaf4,// 105 PAY  65 

    0xa6252e60,// 106 PAY  66 

    0x2e787337,// 107 PAY  67 

    0xd672a319,// 108 PAY  68 

    0x2b28dc01,// 109 PAY  69 

    0x65e5cb98,// 110 PAY  70 

    0xf5813075,// 111 PAY  71 

    0x30be0ecc,// 112 PAY  72 

    0xfa8481f0,// 113 PAY  73 

    0xa5a405e2,// 114 PAY  74 

    0x25301cca,// 115 PAY  75 

    0xe02a31e7,// 116 PAY  76 

    0x05d64630,// 117 PAY  77 

    0x518fb37b,// 118 PAY  78 

    0xb6e62b56,// 119 PAY  79 

    0x4fc4a346,// 120 PAY  80 

    0x07252730,// 121 PAY  81 

    0x5ddaf191,// 122 PAY  82 

    0x8a1c538b,// 123 PAY  83 

    0xd5cd4319,// 124 PAY  84 

    0x7ea017cc,// 125 PAY  85 

    0x864eabb3,// 126 PAY  86 

    0x915bcc32,// 127 PAY  87 

    0xaff539e9,// 128 PAY  88 

    0x6b95d134,// 129 PAY  89 

    0x74437d74,// 130 PAY  90 

    0x8326503d,// 131 PAY  91 

    0x50c7ce42,// 132 PAY  92 

    0x3804764d,// 133 PAY  93 

    0x5b843275,// 134 PAY  94 

    0xb5d6934d,// 135 PAY  95 

    0x376838d0,// 136 PAY  96 

    0x08e079d6,// 137 PAY  97 

    0xf2c32600,// 138 PAY  98 

    0x726a55cb,// 139 PAY  99 

    0x7c243ce3,// 140 PAY 100 

    0xebea0acf,// 141 PAY 101 

    0xac3012a9,// 142 PAY 102 

    0x7a6154f2,// 143 PAY 103 

    0x25b218ce,// 144 PAY 104 

    0x2b01e97b,// 145 PAY 105 

    0x59de02b4,// 146 PAY 106 

    0x78c952d7,// 147 PAY 107 

    0x82502915,// 148 PAY 108 

    0x5ffce2dd,// 149 PAY 109 

    0x326a1a88,// 150 PAY 110 

    0x2e4640b2,// 151 PAY 111 

    0x6a99333c,// 152 PAY 112 

    0x67dcd821,// 153 PAY 113 

    0xa671a5d2,// 154 PAY 114 

    0x9b707153,// 155 PAY 115 

    0xffca3e6b,// 156 PAY 116 

    0x7c60c5f9,// 157 PAY 117 

    0x69371b16,// 158 PAY 118 

    0x8002ff65,// 159 PAY 119 

    0x9d9a004c,// 160 PAY 120 

    0x2baf7162,// 161 PAY 121 

    0x6241e99f,// 162 PAY 122 

    0x5d7439fa,// 163 PAY 123 

    0x69305668,// 164 PAY 124 

    0x17a1b451,// 165 PAY 125 

    0x228c01b4,// 166 PAY 126 

    0xf7540b27,// 167 PAY 127 

    0xb84f5319,// 168 PAY 128 

    0x8797517e,// 169 PAY 129 

    0x8c87ad5d,// 170 PAY 130 

    0x60baf524,// 171 PAY 131 

    0x0881d56e,// 172 PAY 132 

    0x0717997a,// 173 PAY 133 

    0xf4d048ff,// 174 PAY 134 

    0x4c809763,// 175 PAY 135 

    0xed2376e9,// 176 PAY 136 

    0x388248b4,// 177 PAY 137 

    0x1d86f12e,// 178 PAY 138 

    0x044ec111,// 179 PAY 139 

    0x372a07d3,// 180 PAY 140 

    0x3d1bd843,// 181 PAY 141 

    0x0e36ca37,// 182 PAY 142 

    0xd27b6518,// 183 PAY 143 

    0x762f6b2b,// 184 PAY 144 

    0xa5d22678,// 185 PAY 145 

    0x2a269adf,// 186 PAY 146 

    0xe8fe853a,// 187 PAY 147 

    0xdfaf1f9a,// 188 PAY 148 

    0xcc47ddd3,// 189 PAY 149 

    0x94c562e4,// 190 PAY 150 

    0xb258dad4,// 191 PAY 151 

    0x386ad73b,// 192 PAY 152 

    0xb42df9e2,// 193 PAY 153 

    0x933f904f,// 194 PAY 154 

    0xea18b336,// 195 PAY 155 

    0x4028a955,// 196 PAY 156 

    0xa211b234,// 197 PAY 157 

    0x2b4cfbbd,// 198 PAY 158 

    0x90b7a519,// 199 PAY 159 

    0x89a80d12,// 200 PAY 160 

    0x765e2b49,// 201 PAY 161 

    0x300d713c,// 202 PAY 162 

    0x663439d1,// 203 PAY 163 

    0xa0f4e67d,// 204 PAY 164 

    0xad86c10f,// 205 PAY 165 

    0x57bd0000,// 206 PAY 166 

/// STA is 1 words. 

/// STA num_pkts       : 215 

/// STA pkt_idx        : 91 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xc4 

    0x016cc4d7 // 207 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt56_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x0b 

/// ECH pdu_tag        : 0x00 

    0x000b0000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x80812840,// 4 SCX   2 

    0x00005400,// 5 SCX   3 

    0x5f95b0cd,// 6 SCX   4 

    0x468a7d8e,// 7 SCX   5 

    0x3ee071c8,// 8 SCX   6 

    0x349f7858,// 9 SCX   7 

    0x2e62a432,// 10 SCX   8 

    0xb27bc68d,// 11 SCX   9 

    0x8e580fde,// 12 SCX  10 

    0xd07d6fd6,// 13 SCX  11 

    0xe60bc5cf,// 14 SCX  12 

    0xfe9b046a,// 15 SCX  13 

    0xf157bd37,// 16 SCX  14 

    0x184890c8,// 17 SCX  15 

    0xbed8b4ce,// 18 SCX  16 

    0x30e5c101,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 1775 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1548 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1548 

/// BFD lencrypto      : 736 

/// BFD ofstcrypto     : 640 

/// BFD (ofst+len)cry  : 1376 

/// BFD ofstiv         : 604 

/// BFD ofsticv        : 1600 

    0x0000060c,// 20 BFD   1 

    0x028002e0,// 21 BFD   2 

    0x0640025c,// 22 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c0092c0,// 23 MFM   1 

    0x7cd8ac9e,// 24 MFM   2 

    0xa070e8a3,// 25 MFM   3 

    0x62a82007,// 26 MFM   4 

    0xbdfccfb4,// 27 MFM   5 

    0xe8312750,// 28 MFM   6 

    0x3e379021,// 29 MFM   7 

    0x29109e81,// 30 MFM   8 

    0x53318e2a,// 31 MFM   9 

    0x08634ee3,// 32 MFM  10 

    0xd3dfeac5,// 33 MFM  11 

    0xa758d333,// 34 MFM  12 

    0xbc3ec410,// 35 MFM  13 

    0x063717ab,// 36 MFM  14 

    0x31aeef1f,// 37 MFM  15 

    0x9c0dd9d3,// 38 MFM  16 

/// BDA is 445 words. 

/// BDA size     is 1775 (0x6ef) 

/// BDA id       is 0x1b7b 

    0x06ef1b7b,// 39 BDA   1 

/// PAY Generic Data size   : 1775 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x4526946c,// 40 PAY   1 

    0xf6eb2320,// 41 PAY   2 

    0x1ed0040e,// 42 PAY   3 

    0xe2cc0e81,// 43 PAY   4 

    0xef047d57,// 44 PAY   5 

    0xa5336663,// 45 PAY   6 

    0xa88cdcc7,// 46 PAY   7 

    0xfeefeefb,// 47 PAY   8 

    0x18d79f37,// 48 PAY   9 

    0x413e0467,// 49 PAY  10 

    0xd3dcceb0,// 50 PAY  11 

    0x0cf0bb58,// 51 PAY  12 

    0x8efe28b5,// 52 PAY  13 

    0xa76829ef,// 53 PAY  14 

    0xb81e5aeb,// 54 PAY  15 

    0x80f739dd,// 55 PAY  16 

    0xdf6cabdb,// 56 PAY  17 

    0x76f13eea,// 57 PAY  18 

    0x9972f55e,// 58 PAY  19 

    0x78059dc7,// 59 PAY  20 

    0xa6ef432c,// 60 PAY  21 

    0x35b175c6,// 61 PAY  22 

    0x7209e436,// 62 PAY  23 

    0x0a5f47cc,// 63 PAY  24 

    0x1b611666,// 64 PAY  25 

    0xfac60556,// 65 PAY  26 

    0x9415ba1d,// 66 PAY  27 

    0x21edeefc,// 67 PAY  28 

    0xc37d389f,// 68 PAY  29 

    0x7d3919e2,// 69 PAY  30 

    0x34f4a962,// 70 PAY  31 

    0xf36a445e,// 71 PAY  32 

    0xe7a039a1,// 72 PAY  33 

    0x0da98e23,// 73 PAY  34 

    0xf4e7cfe7,// 74 PAY  35 

    0xe82455c6,// 75 PAY  36 

    0xe2f2423e,// 76 PAY  37 

    0x8ec17bbf,// 77 PAY  38 

    0x6e74b7ed,// 78 PAY  39 

    0x6b8ce1cb,// 79 PAY  40 

    0xe51d276b,// 80 PAY  41 

    0x95830597,// 81 PAY  42 

    0x543bea12,// 82 PAY  43 

    0xb5fdd8c9,// 83 PAY  44 

    0x24537e2a,// 84 PAY  45 

    0x26c34361,// 85 PAY  46 

    0x2f0d632e,// 86 PAY  47 

    0x7c424e9a,// 87 PAY  48 

    0x2aad6c55,// 88 PAY  49 

    0x2f48797e,// 89 PAY  50 

    0x5193cf7f,// 90 PAY  51 

    0x2ba05977,// 91 PAY  52 

    0xe86f376e,// 92 PAY  53 

    0x8876e09e,// 93 PAY  54 

    0x46af98c4,// 94 PAY  55 

    0xfb5e0354,// 95 PAY  56 

    0xd110e1c6,// 96 PAY  57 

    0x5b26e713,// 97 PAY  58 

    0xa1c81203,// 98 PAY  59 

    0xf52ee4b1,// 99 PAY  60 

    0xae2c4e71,// 100 PAY  61 

    0x1008c50c,// 101 PAY  62 

    0x828fb30a,// 102 PAY  63 

    0xa4cddb96,// 103 PAY  64 

    0x5325caa1,// 104 PAY  65 

    0x5d82ab29,// 105 PAY  66 

    0x3cf36f3e,// 106 PAY  67 

    0xa023211f,// 107 PAY  68 

    0xa23042d4,// 108 PAY  69 

    0x017b7914,// 109 PAY  70 

    0x947accd9,// 110 PAY  71 

    0xa853ea24,// 111 PAY  72 

    0xbd2c63ba,// 112 PAY  73 

    0xc64c5b0e,// 113 PAY  74 

    0x62a0df6f,// 114 PAY  75 

    0x4015c7e5,// 115 PAY  76 

    0xfc659c5c,// 116 PAY  77 

    0x6b2bafa0,// 117 PAY  78 

    0x6f06d844,// 118 PAY  79 

    0x2a8ac77a,// 119 PAY  80 

    0x331caf78,// 120 PAY  81 

    0x8f29bfd3,// 121 PAY  82 

    0xb02ef0a1,// 122 PAY  83 

    0x90eccd1a,// 123 PAY  84 

    0x8a1c8af9,// 124 PAY  85 

    0xc1dd7bcd,// 125 PAY  86 

    0x5728917e,// 126 PAY  87 

    0xdd2ad38c,// 127 PAY  88 

    0x90d607c0,// 128 PAY  89 

    0x4399326c,// 129 PAY  90 

    0x50ddc7ef,// 130 PAY  91 

    0xe64af232,// 131 PAY  92 

    0x2d677a82,// 132 PAY  93 

    0xba589eed,// 133 PAY  94 

    0xefb73abb,// 134 PAY  95 

    0x3b7bb95f,// 135 PAY  96 

    0xfa8ab1bd,// 136 PAY  97 

    0x4b5bd25e,// 137 PAY  98 

    0xefaf384d,// 138 PAY  99 

    0x149d9443,// 139 PAY 100 

    0xdfb6a7b1,// 140 PAY 101 

    0x1124dcf8,// 141 PAY 102 

    0xc9994ad3,// 142 PAY 103 

    0xfe4fdcef,// 143 PAY 104 

    0x7e39e7b3,// 144 PAY 105 

    0x92f9a509,// 145 PAY 106 

    0xcfd647f1,// 146 PAY 107 

    0xff6796bd,// 147 PAY 108 

    0x2c0853cd,// 148 PAY 109 

    0xd406acf5,// 149 PAY 110 

    0xe3396505,// 150 PAY 111 

    0x0bc0ccb0,// 151 PAY 112 

    0x65fc5a67,// 152 PAY 113 

    0x15dcb9bd,// 153 PAY 114 

    0x853a3a35,// 154 PAY 115 

    0x5a6b73aa,// 155 PAY 116 

    0xc9d4a20c,// 156 PAY 117 

    0x86e351c6,// 157 PAY 118 

    0x3c7689ac,// 158 PAY 119 

    0xffcc2ab1,// 159 PAY 120 

    0xc20146bf,// 160 PAY 121 

    0x3dc3b343,// 161 PAY 122 

    0x8797a425,// 162 PAY 123 

    0x4edeed97,// 163 PAY 124 

    0xf4c20c9f,// 164 PAY 125 

    0x43a17154,// 165 PAY 126 

    0xd2912fe1,// 166 PAY 127 

    0x02ac97d1,// 167 PAY 128 

    0xa2270511,// 168 PAY 129 

    0xcb6f63a0,// 169 PAY 130 

    0xd0ebc8ac,// 170 PAY 131 

    0x04dd2ee3,// 171 PAY 132 

    0x51c069ed,// 172 PAY 133 

    0x2da9b980,// 173 PAY 134 

    0x3e068fb9,// 174 PAY 135 

    0x3d7ff58a,// 175 PAY 136 

    0x9f4d5ca9,// 176 PAY 137 

    0x110ca208,// 177 PAY 138 

    0xcb634bea,// 178 PAY 139 

    0x88cf0dfd,// 179 PAY 140 

    0xc6d712c8,// 180 PAY 141 

    0x2576d0dd,// 181 PAY 142 

    0xaa9ab55f,// 182 PAY 143 

    0x02dffebf,// 183 PAY 144 

    0x99c28d73,// 184 PAY 145 

    0x0ee43697,// 185 PAY 146 

    0x9c65e1c1,// 186 PAY 147 

    0x12657727,// 187 PAY 148 

    0x85122c6d,// 188 PAY 149 

    0x8c5d7935,// 189 PAY 150 

    0x23733a1b,// 190 PAY 151 

    0x4dd6176b,// 191 PAY 152 

    0x84e86b03,// 192 PAY 153 

    0x35fad14d,// 193 PAY 154 

    0xde36777a,// 194 PAY 155 

    0x3f627749,// 195 PAY 156 

    0x762f6d3b,// 196 PAY 157 

    0x34acbd23,// 197 PAY 158 

    0x7d01d6b7,// 198 PAY 159 

    0x6675e1ba,// 199 PAY 160 

    0x9480fc71,// 200 PAY 161 

    0x4c6efe2c,// 201 PAY 162 

    0x5a850616,// 202 PAY 163 

    0x54149525,// 203 PAY 164 

    0x04f6b0df,// 204 PAY 165 

    0x8991476f,// 205 PAY 166 

    0x5a7ead1b,// 206 PAY 167 

    0x0064901b,// 207 PAY 168 

    0xc717f2a4,// 208 PAY 169 

    0x8c7c6d12,// 209 PAY 170 

    0xec9d4e10,// 210 PAY 171 

    0xed553524,// 211 PAY 172 

    0x3ac22bc9,// 212 PAY 173 

    0xae6dfe76,// 213 PAY 174 

    0x208cbc6b,// 214 PAY 175 

    0xec63d15a,// 215 PAY 176 

    0xbbb20ea5,// 216 PAY 177 

    0x37e33dbf,// 217 PAY 178 

    0xc5ce2f63,// 218 PAY 179 

    0x1c402cdf,// 219 PAY 180 

    0x76ffc446,// 220 PAY 181 

    0x3a3021fc,// 221 PAY 182 

    0x8c52a4ba,// 222 PAY 183 

    0x1a86ecb0,// 223 PAY 184 

    0x705fbe74,// 224 PAY 185 

    0xfe1c662b,// 225 PAY 186 

    0x70b37ffd,// 226 PAY 187 

    0x368858cb,// 227 PAY 188 

    0x39238fda,// 228 PAY 189 

    0x5352443b,// 229 PAY 190 

    0x672231ce,// 230 PAY 191 

    0xd2b62a83,// 231 PAY 192 

    0x200c47f1,// 232 PAY 193 

    0x48e9eacd,// 233 PAY 194 

    0x9ad8f56f,// 234 PAY 195 

    0x1d344845,// 235 PAY 196 

    0x55a1a748,// 236 PAY 197 

    0x6bd314b9,// 237 PAY 198 

    0x91cf58cb,// 238 PAY 199 

    0x1211cdff,// 239 PAY 200 

    0x4715ac86,// 240 PAY 201 

    0x4931c774,// 241 PAY 202 

    0xd45b057b,// 242 PAY 203 

    0x7714f4f4,// 243 PAY 204 

    0x283d011f,// 244 PAY 205 

    0x53980864,// 245 PAY 206 

    0x5d9c7a9f,// 246 PAY 207 

    0x9d70cb24,// 247 PAY 208 

    0x04e90dce,// 248 PAY 209 

    0xd403b425,// 249 PAY 210 

    0x9c554ef9,// 250 PAY 211 

    0x5a22b911,// 251 PAY 212 

    0xcab2b8cd,// 252 PAY 213 

    0xf12128fc,// 253 PAY 214 

    0x473a64fd,// 254 PAY 215 

    0xe8120ba8,// 255 PAY 216 

    0x5c835725,// 256 PAY 217 

    0x9c1b4557,// 257 PAY 218 

    0x3d1303b7,// 258 PAY 219 

    0xe9ea08c5,// 259 PAY 220 

    0x298e5b73,// 260 PAY 221 

    0x6aca1a8e,// 261 PAY 222 

    0x5a5199d8,// 262 PAY 223 

    0xad45708a,// 263 PAY 224 

    0xdd5d6fb6,// 264 PAY 225 

    0xa572d208,// 265 PAY 226 

    0xfa5535ea,// 266 PAY 227 

    0x7f71d32e,// 267 PAY 228 

    0xd8d924d1,// 268 PAY 229 

    0x312420e9,// 269 PAY 230 

    0x37e6e792,// 270 PAY 231 

    0x54c2df65,// 271 PAY 232 

    0x30574f09,// 272 PAY 233 

    0xfbb2b1d3,// 273 PAY 234 

    0x5d40df0c,// 274 PAY 235 

    0x077b445b,// 275 PAY 236 

    0xfd4c88ff,// 276 PAY 237 

    0x99e51624,// 277 PAY 238 

    0x68b009ef,// 278 PAY 239 

    0xc453c060,// 279 PAY 240 

    0xc3fef0cb,// 280 PAY 241 

    0x06ea9696,// 281 PAY 242 

    0xe5358bd1,// 282 PAY 243 

    0xa2e19654,// 283 PAY 244 

    0x6829978c,// 284 PAY 245 

    0xde71ef7b,// 285 PAY 246 

    0xa0fd2733,// 286 PAY 247 

    0x2a561fbb,// 287 PAY 248 

    0xd00ec09b,// 288 PAY 249 

    0x8feb7962,// 289 PAY 250 

    0xefe2e3f7,// 290 PAY 251 

    0x7b932a8f,// 291 PAY 252 

    0x27bb740d,// 292 PAY 253 

    0xa2926bab,// 293 PAY 254 

    0x28788db5,// 294 PAY 255 

    0x0be84964,// 295 PAY 256 

    0xb75a71cc,// 296 PAY 257 

    0xe802061a,// 297 PAY 258 

    0xe4cd7e44,// 298 PAY 259 

    0xcf1e1647,// 299 PAY 260 

    0xd51bdcea,// 300 PAY 261 

    0x5c6978f7,// 301 PAY 262 

    0x355e9e10,// 302 PAY 263 

    0xca042f59,// 303 PAY 264 

    0x0c4cca19,// 304 PAY 265 

    0xf5ab3753,// 305 PAY 266 

    0x45f44c27,// 306 PAY 267 

    0x6faabf99,// 307 PAY 268 

    0x3f859773,// 308 PAY 269 

    0x1e3a5fe5,// 309 PAY 270 

    0x5880d66d,// 310 PAY 271 

    0xffebbb01,// 311 PAY 272 

    0xda2c687b,// 312 PAY 273 

    0xceeff4c8,// 313 PAY 274 

    0x1aec159b,// 314 PAY 275 

    0x9e5eac76,// 315 PAY 276 

    0x0d163841,// 316 PAY 277 

    0x2f477398,// 317 PAY 278 

    0xf836287d,// 318 PAY 279 

    0xb6c858c2,// 319 PAY 280 

    0xa17db95a,// 320 PAY 281 

    0x27dbe153,// 321 PAY 282 

    0x62edeff2,// 322 PAY 283 

    0xed0010b2,// 323 PAY 284 

    0x09a4c321,// 324 PAY 285 

    0x83a0ea65,// 325 PAY 286 

    0x44d22a59,// 326 PAY 287 

    0xa0f4762e,// 327 PAY 288 

    0x15c17a9c,// 328 PAY 289 

    0x1f3a0d66,// 329 PAY 290 

    0x09fe8195,// 330 PAY 291 

    0xa13175cf,// 331 PAY 292 

    0x11c81775,// 332 PAY 293 

    0xd8986609,// 333 PAY 294 

    0xcc9385ef,// 334 PAY 295 

    0x76554d7f,// 335 PAY 296 

    0xc95112a3,// 336 PAY 297 

    0xf8e3bf7b,// 337 PAY 298 

    0x6d4c5883,// 338 PAY 299 

    0xaab0507f,// 339 PAY 300 

    0xc78402bd,// 340 PAY 301 

    0x1983d570,// 341 PAY 302 

    0xb1876207,// 342 PAY 303 

    0xb5e41b17,// 343 PAY 304 

    0xf10a434e,// 344 PAY 305 

    0x54ec0194,// 345 PAY 306 

    0x34157da4,// 346 PAY 307 

    0xad98143e,// 347 PAY 308 

    0x638f121f,// 348 PAY 309 

    0x354b80eb,// 349 PAY 310 

    0x39cf9b15,// 350 PAY 311 

    0x74db6c1a,// 351 PAY 312 

    0x030108cf,// 352 PAY 313 

    0x20f0748c,// 353 PAY 314 

    0xd96b3203,// 354 PAY 315 

    0xa339d647,// 355 PAY 316 

    0xef331700,// 356 PAY 317 

    0xb033fea0,// 357 PAY 318 

    0xf91a1675,// 358 PAY 319 

    0x953f5f96,// 359 PAY 320 

    0x612a4067,// 360 PAY 321 

    0x0a1909d2,// 361 PAY 322 

    0xef3b88e8,// 362 PAY 323 

    0x3e1e2eee,// 363 PAY 324 

    0x47be36a7,// 364 PAY 325 

    0xd61c75fd,// 365 PAY 326 

    0x07b29466,// 366 PAY 327 

    0x39a39969,// 367 PAY 328 

    0x4cf7da93,// 368 PAY 329 

    0x11e796fb,// 369 PAY 330 

    0x9613bd69,// 370 PAY 331 

    0xbfb66c63,// 371 PAY 332 

    0x66f7fd6d,// 372 PAY 333 

    0xf9d9586d,// 373 PAY 334 

    0x36d23040,// 374 PAY 335 

    0x4058e179,// 375 PAY 336 

    0x828d79ef,// 376 PAY 337 

    0xcc55bf3e,// 377 PAY 338 

    0xd2cb427f,// 378 PAY 339 

    0xcbba5590,// 379 PAY 340 

    0xfefeee85,// 380 PAY 341 

    0xc722ef69,// 381 PAY 342 

    0xb5d6ab37,// 382 PAY 343 

    0xdc4c9b6e,// 383 PAY 344 

    0x9c223490,// 384 PAY 345 

    0xc0f6b057,// 385 PAY 346 

    0x684e9fa9,// 386 PAY 347 

    0x73df0956,// 387 PAY 348 

    0x62c40a03,// 388 PAY 349 

    0x320d453e,// 389 PAY 350 

    0x0f5ce665,// 390 PAY 351 

    0x9cf53070,// 391 PAY 352 

    0x0ab6a0d2,// 392 PAY 353 

    0x6e86d0eb,// 393 PAY 354 

    0x64399bc9,// 394 PAY 355 

    0x98f8215d,// 395 PAY 356 

    0x57134e80,// 396 PAY 357 

    0x992bbe33,// 397 PAY 358 

    0xc467122f,// 398 PAY 359 

    0x173a2382,// 399 PAY 360 

    0xd77a0c23,// 400 PAY 361 

    0x3c19f5a8,// 401 PAY 362 

    0x7d0fe6fc,// 402 PAY 363 

    0xc54aced9,// 403 PAY 364 

    0x4d6ec3c4,// 404 PAY 365 

    0x1e1d1fbd,// 405 PAY 366 

    0xf136f7b1,// 406 PAY 367 

    0x2969499e,// 407 PAY 368 

    0x3dfcea2b,// 408 PAY 369 

    0xa04f94f4,// 409 PAY 370 

    0x78da3853,// 410 PAY 371 

    0xe6610c2c,// 411 PAY 372 

    0x074e98c9,// 412 PAY 373 

    0xca6a3842,// 413 PAY 374 

    0x42dc99fa,// 414 PAY 375 

    0x057b86cd,// 415 PAY 376 

    0xae9c84ef,// 416 PAY 377 

    0x761ed5f5,// 417 PAY 378 

    0xec6cbd36,// 418 PAY 379 

    0x1d057f03,// 419 PAY 380 

    0x08ac5aee,// 420 PAY 381 

    0x4be08c25,// 421 PAY 382 

    0x28d5f877,// 422 PAY 383 

    0xd3327d47,// 423 PAY 384 

    0x768bddaa,// 424 PAY 385 

    0x1507ea36,// 425 PAY 386 

    0x8309cef9,// 426 PAY 387 

    0xd38cc3ff,// 427 PAY 388 

    0x7efb12f0,// 428 PAY 389 

    0x9ab18b37,// 429 PAY 390 

    0x46ccd746,// 430 PAY 391 

    0x98fbbec9,// 431 PAY 392 

    0x03621ece,// 432 PAY 393 

    0xb30c4b88,// 433 PAY 394 

    0x03c6d6b3,// 434 PAY 395 

    0x8df4cc49,// 435 PAY 396 

    0x051138fc,// 436 PAY 397 

    0x88131e7e,// 437 PAY 398 

    0x046ee948,// 438 PAY 399 

    0xb6dc9413,// 439 PAY 400 

    0x76455851,// 440 PAY 401 

    0xf77424bb,// 441 PAY 402 

    0xf6d907de,// 442 PAY 403 

    0x17efbbad,// 443 PAY 404 

    0xb2a1979a,// 444 PAY 405 

    0x1b58304d,// 445 PAY 406 

    0x47f7c17f,// 446 PAY 407 

    0xf4d4e62b,// 447 PAY 408 

    0x40439002,// 448 PAY 409 

    0x4511ea62,// 449 PAY 410 

    0x332a55fb,// 450 PAY 411 

    0x6b0210de,// 451 PAY 412 

    0x29090de7,// 452 PAY 413 

    0xab747626,// 453 PAY 414 

    0xa6e1f1e8,// 454 PAY 415 

    0x2a0ea840,// 455 PAY 416 

    0xe22c4c13,// 456 PAY 417 

    0x51ed1f1a,// 457 PAY 418 

    0x04009b36,// 458 PAY 419 

    0x35d1f277,// 459 PAY 420 

    0x509a00d5,// 460 PAY 421 

    0xd902e242,// 461 PAY 422 

    0x2e3fe150,// 462 PAY 423 

    0xd163f2ed,// 463 PAY 424 

    0xd7fe54af,// 464 PAY 425 

    0xe86b9010,// 465 PAY 426 

    0x27fe637c,// 466 PAY 427 

    0x228a2847,// 467 PAY 428 

    0xd78a19a7,// 468 PAY 429 

    0x59c9980b,// 469 PAY 430 

    0x03b7964d,// 470 PAY 431 

    0xe64d766f,// 471 PAY 432 

    0xb150b99e,// 472 PAY 433 

    0x61453874,// 473 PAY 434 

    0xa607656f,// 474 PAY 435 

    0xb132898b,// 475 PAY 436 

    0x42e84806,// 476 PAY 437 

    0x0dbbfaec,// 477 PAY 438 

    0xc7f1fa5d,// 478 PAY 439 

    0x86399c99,// 479 PAY 440 

    0xe3d86aaa,// 480 PAY 441 

    0x81cf7229,// 481 PAY 442 

    0xc99dec40,// 482 PAY 443 

    0xb14ec800,// 483 PAY 444 

/// STA is 1 words. 

/// STA num_pkts       : 160 

/// STA pkt_idx        : 180 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xf7 

    0x02d1f7a0 // 484 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt57_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x80802821,// 4 SCX   2 

    0x00002300,// 5 SCX   3 

    0x77167012,// 6 SCX   4 

    0xa16fbf75,// 7 SCX   5 

    0xbdd5bdb5,// 8 SCX   6 

    0x1a297495,// 9 SCX   7 

    0x5ab5cd7b,// 10 SCX   8 

    0x66164a6c,// 11 SCX   9 

    0xc4a57e33,// 12 SCX  10 

    0x8e2bea1d,// 13 SCX  11 

    0x52806a86,// 14 SCX  12 

    0x76fb135f,// 15 SCX  13 

    0xad4d777a,// 16 SCX  14 

    0x1c33ef9e,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 348 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 178 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 178 

/// BFD lencrypto      : 96 

/// BFD ofstcrypto     : 28 

/// BFD (ofst+len)cry  : 124 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 220 

    0x000000b2,// 18 BFD   1 

    0x001c0060,// 19 BFD   2 

    0x00dc0000,// 20 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : 10 

    0x1000f81b,// 21 MFM   1 

    0x049f2c0e,// 22 MFM   2 

    0x19f00000,// 23 MFM   3 

/// BDA is 88 words. 

/// BDA size     is 348 (0x15c) 

/// BDA id       is 0xf427 

    0x015cf427,// 24 BDA   1 

/// PAY Generic Data size   : 348 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x7c125e4b,// 25 PAY   1 

    0x90645a88,// 26 PAY   2 

    0x69d14eb7,// 27 PAY   3 

    0x9d306a99,// 28 PAY   4 

    0xb91f7aee,// 29 PAY   5 

    0x2055bb6b,// 30 PAY   6 

    0xd12721bd,// 31 PAY   7 

    0x7c9b3abe,// 32 PAY   8 

    0x67275745,// 33 PAY   9 

    0x781b3588,// 34 PAY  10 

    0x2f6d50e6,// 35 PAY  11 

    0x75cda846,// 36 PAY  12 

    0x4db2ed5e,// 37 PAY  13 

    0x30fff695,// 38 PAY  14 

    0xef9f8395,// 39 PAY  15 

    0x5746567e,// 40 PAY  16 

    0x6bec6308,// 41 PAY  17 

    0x4d4540a6,// 42 PAY  18 

    0x5b08cee6,// 43 PAY  19 

    0xe5c03d19,// 44 PAY  20 

    0xb9b134a1,// 45 PAY  21 

    0xa9e054c5,// 46 PAY  22 

    0xa6b334a6,// 47 PAY  23 

    0xd178daf1,// 48 PAY  24 

    0x16c93912,// 49 PAY  25 

    0x1ea3ea69,// 50 PAY  26 

    0xf66383b3,// 51 PAY  27 

    0xf063dbfe,// 52 PAY  28 

    0xd26d52e7,// 53 PAY  29 

    0x5778114e,// 54 PAY  30 

    0x565d1b64,// 55 PAY  31 

    0x7ff2ca71,// 56 PAY  32 

    0x61ed566f,// 57 PAY  33 

    0x61ea316f,// 58 PAY  34 

    0x3dc94124,// 59 PAY  35 

    0x77a9fb7f,// 60 PAY  36 

    0xa91e251d,// 61 PAY  37 

    0x490e0854,// 62 PAY  38 

    0x00aac94b,// 63 PAY  39 

    0xd1934c76,// 64 PAY  40 

    0x70dc64ac,// 65 PAY  41 

    0x6ec49e3d,// 66 PAY  42 

    0x0cbf2b7b,// 67 PAY  43 

    0x7a6506af,// 68 PAY  44 

    0x8874bc24,// 69 PAY  45 

    0x1c9babf2,// 70 PAY  46 

    0x017f34dc,// 71 PAY  47 

    0xc70ac28d,// 72 PAY  48 

    0x5eae6864,// 73 PAY  49 

    0x05ee5a65,// 74 PAY  50 

    0x7ff53cf2,// 75 PAY  51 

    0x8b308183,// 76 PAY  52 

    0x45122251,// 77 PAY  53 

    0xca996956,// 78 PAY  54 

    0x87bbb6c5,// 79 PAY  55 

    0x295ef63e,// 80 PAY  56 

    0xd99b7912,// 81 PAY  57 

    0xf85f245f,// 82 PAY  58 

    0xef67b013,// 83 PAY  59 

    0x1d74fd5b,// 84 PAY  60 

    0x7f769afc,// 85 PAY  61 

    0xee9b6be9,// 86 PAY  62 

    0x06ed95a0,// 87 PAY  63 

    0x079c8aec,// 88 PAY  64 

    0x831db9c0,// 89 PAY  65 

    0x45b2ac0f,// 90 PAY  66 

    0x8808b070,// 91 PAY  67 

    0x60ba8921,// 92 PAY  68 

    0xedbaa98d,// 93 PAY  69 

    0x4045852b,// 94 PAY  70 

    0x3cb45833,// 95 PAY  71 

    0x9e7402a8,// 96 PAY  72 

    0x9b0fc8b7,// 97 PAY  73 

    0xb99563cf,// 98 PAY  74 

    0x226f9515,// 99 PAY  75 

    0xaa6347ab,// 100 PAY  76 

    0x2248597a,// 101 PAY  77 

    0x811afe32,// 102 PAY  78 

    0xfac936d8,// 103 PAY  79 

    0x96eff0e7,// 104 PAY  80 

    0xeb72f011,// 105 PAY  81 

    0x299871c1,// 106 PAY  82 

    0x2e2ba509,// 107 PAY  83 

    0xb1802a2e,// 108 PAY  84 

    0x8cf52429,// 109 PAY  85 

    0x30e90fe0,// 110 PAY  86 

    0xfb1859c0,// 111 PAY  87 

/// STA is 1 words. 

/// STA num_pkts       : 231 

/// STA pkt_idx        : 247 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x9 

    0x03dc09e7 // 112 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt58_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x8082282e,// 4 SCX   2 

    0x00003200,// 5 SCX   3 

    0xa0c6170f,// 6 SCX   4 

    0x50a52017,// 7 SCX   5 

    0x25280611,// 8 SCX   6 

    0x302645f8,// 9 SCX   7 

    0x91ec6519,// 10 SCX   8 

    0x113ecd18,// 11 SCX   9 

    0xce9ee378,// 12 SCX  10 

    0x46b34906,// 13 SCX  11 

    0x71384438,// 14 SCX  12 

    0x5137f938,// 15 SCX  13 

    0xbfb7e273,// 16 SCX  14 

    0x22134e6b,// 17 SCX  15 

    0xc2f97996,// 18 SCX  16 

    0xf29ecad2,// 19 SCX  17 

    0x92107c04,// 20 SCX  18 

    0x29ed27b7,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 445 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 373 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 373 

/// BFD lencrypto      : 128 

/// BFD ofstcrypto     : 220 

/// BFD (ofst+len)cry  : 348 

/// BFD ofstiv         : 124 

/// BFD ofsticv        : 408 

    0x00000175,// 22 BFD   1 

    0x00dc0080,// 23 BFD   2 

    0x0198007c,// 24 BFD   3 

/// MFM is 6 words. 

/// MFM vldnibs        : 27 

    0x2700a281,// 25 MFM   1 

    0x07b22718,// 26 MFM   2 

    0x1c1a0028,// 27 MFM   3 

    0x818a7dd5,// 28 MFM   4 

    0x37d704f6,// 29 MFM   5 

    0x7b500000,// 30 MFM   6 

/// BDA is 113 words. 

/// BDA size     is 445 (0x1bd) 

/// BDA id       is 0x5042 

    0x01bd5042,// 31 BDA   1 

/// PAY Generic Data size   : 445 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0xd43689a8,// 32 PAY   1 

    0xdfa8e53b,// 33 PAY   2 

    0x800c125b,// 34 PAY   3 

    0xe5667342,// 35 PAY   4 

    0xb799418a,// 36 PAY   5 

    0xb9957a6b,// 37 PAY   6 

    0x9a72b624,// 38 PAY   7 

    0x6f666bea,// 39 PAY   8 

    0xba65e8e2,// 40 PAY   9 

    0xc18acdba,// 41 PAY  10 

    0xf782a9ec,// 42 PAY  11 

    0x375954c8,// 43 PAY  12 

    0x84bfd531,// 44 PAY  13 

    0xf18ef6e9,// 45 PAY  14 

    0xda409491,// 46 PAY  15 

    0x7ae37729,// 47 PAY  16 

    0x66bc938c,// 48 PAY  17 

    0x5b6093ed,// 49 PAY  18 

    0xc33e7bf8,// 50 PAY  19 

    0x96ade1ba,// 51 PAY  20 

    0xa0f80b54,// 52 PAY  21 

    0x432d722f,// 53 PAY  22 

    0x856150af,// 54 PAY  23 

    0x691bae3d,// 55 PAY  24 

    0x5c8a3027,// 56 PAY  25 

    0x1a2160c7,// 57 PAY  26 

    0x79629c4a,// 58 PAY  27 

    0x2630b4ee,// 59 PAY  28 

    0x59ea5802,// 60 PAY  29 

    0x2777741f,// 61 PAY  30 

    0x6d40c1eb,// 62 PAY  31 

    0xe74e2e8d,// 63 PAY  32 

    0xa26d3c52,// 64 PAY  33 

    0x134ffca1,// 65 PAY  34 

    0x53f28cfe,// 66 PAY  35 

    0x2da4883f,// 67 PAY  36 

    0x3b04f30d,// 68 PAY  37 

    0xe9795da3,// 69 PAY  38 

    0xe74ece40,// 70 PAY  39 

    0xf2f84320,// 71 PAY  40 

    0xb094f228,// 72 PAY  41 

    0xea0d2f17,// 73 PAY  42 

    0x7a022012,// 74 PAY  43 

    0x1bbb5a5e,// 75 PAY  44 

    0x6d4220ab,// 76 PAY  45 

    0x77def4f1,// 77 PAY  46 

    0x1cb07d47,// 78 PAY  47 

    0xc696b580,// 79 PAY  48 

    0xfc430b08,// 80 PAY  49 

    0x62e3ca6f,// 81 PAY  50 

    0xa2097045,// 82 PAY  51 

    0xfeb2a760,// 83 PAY  52 

    0xfbb756be,// 84 PAY  53 

    0xfae33897,// 85 PAY  54 

    0x0faab7c9,// 86 PAY  55 

    0x0fc34ea0,// 87 PAY  56 

    0x03212db2,// 88 PAY  57 

    0x506a8998,// 89 PAY  58 

    0x3ed61e2d,// 90 PAY  59 

    0xf31abb38,// 91 PAY  60 

    0xe95c7cab,// 92 PAY  61 

    0x70a99aae,// 93 PAY  62 

    0x0f34ae4d,// 94 PAY  63 

    0xee0a8633,// 95 PAY  64 

    0x83e11f83,// 96 PAY  65 

    0x863f653b,// 97 PAY  66 

    0x48f2d2d0,// 98 PAY  67 

    0x977f3250,// 99 PAY  68 

    0x2b623950,// 100 PAY  69 

    0xcfd2f705,// 101 PAY  70 

    0xd668ddce,// 102 PAY  71 

    0xe6d5cf78,// 103 PAY  72 

    0xae80aec7,// 104 PAY  73 

    0xf8b1bd9a,// 105 PAY  74 

    0x2db38a3e,// 106 PAY  75 

    0xc893ddb7,// 107 PAY  76 

    0xc0f72697,// 108 PAY  77 

    0xb724b396,// 109 PAY  78 

    0x992970d6,// 110 PAY  79 

    0x613110a3,// 111 PAY  80 

    0x9202170b,// 112 PAY  81 

    0x0635d9b8,// 113 PAY  82 

    0xf31e126e,// 114 PAY  83 

    0xd68bd8f8,// 115 PAY  84 

    0x4d315e23,// 116 PAY  85 

    0xb75cdd0e,// 117 PAY  86 

    0x05be2b3b,// 118 PAY  87 

    0xfd8be6f6,// 119 PAY  88 

    0x2de789d6,// 120 PAY  89 

    0x4f36b83d,// 121 PAY  90 

    0xf089fa2e,// 122 PAY  91 

    0x65d8de8d,// 123 PAY  92 

    0xbc9b7456,// 124 PAY  93 

    0xff30a335,// 125 PAY  94 

    0xe4298cbe,// 126 PAY  95 

    0x2b20e12d,// 127 PAY  96 

    0xf77c5f87,// 128 PAY  97 

    0xf3710784,// 129 PAY  98 

    0x500ff1e7,// 130 PAY  99 

    0x9cb00780,// 131 PAY 100 

    0xe8d90349,// 132 PAY 101 

    0x38233271,// 133 PAY 102 

    0x06b60277,// 134 PAY 103 

    0x82e5384c,// 135 PAY 104 

    0xc9a761a2,// 136 PAY 105 

    0xb80a4b43,// 137 PAY 106 

    0x9d4e32f9,// 138 PAY 107 

    0xe4f2e60c,// 139 PAY 108 

    0x3e278796,// 140 PAY 109 

    0xe7fae5d0,// 141 PAY 110 

    0xed97913e,// 142 PAY 111 

    0xe7000000,// 143 PAY 112 

/// STA is 1 words. 

/// STA num_pkts       : 207 

/// STA pkt_idx        : 160 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x1e 

    0x02811ecf // 144 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt59_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x80922815,// 4 SCX   2 

    0x000043c2,// 5 SCX   3 

    0xd96ff58e,// 6 SCX   4 

    0x6bae1076,// 7 SCX   5 

    0xe0cd9012,// 8 SCX   6 

    0x627069f5,// 9 SCX   7 

    0x6344b4ea,// 10 SCX   8 

    0x36e60ed3,// 11 SCX   9 

    0xd16b9a80,// 12 SCX  10 

    0x4a2ed480,// 13 SCX  11 

    0x6edfbe95,// 14 SCX  12 

    0x3436291b,// 15 SCX  13 

    0x7201d009,// 16 SCX  14 

    0xc5c5cac9,// 17 SCX  15 

    0xb352f3f9,// 18 SCX  16 

    0x349f5b4a,// 19 SCX  17 

    0xdb349c1d,// 20 SCX  18 

    0xa351c28e,// 21 SCX  19 

    0x17eb9531,// 22 SCX  20 

    0xf0567d64,// 23 SCX  21 

    0x28c97a94,// 24 SCX  22 

    0x8583a598,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 426 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 86 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 86 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 48 

/// BFD (ofst+len)cry  : 80 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 232 

    0x00000056,// 26 BFD   1 

    0x00300020,// 27 BFD   2 

    0x00e80010,// 28 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : 13 

    0x13009c81,// 29 MFM   1 

    0xa32ac037,// 30 MFM   2 

    0xce8a0200,// 31 MFM   3 

/// BDA is 108 words. 

/// BDA size     is 426 (0x1aa) 

/// BDA id       is 0x1f49 

    0x01aa1f49,// 32 BDA   1 

/// PAY Generic Data size   : 426 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xd9ccd401,// 33 PAY   1 

    0x8388c9f2,// 34 PAY   2 

    0xbfd74f57,// 35 PAY   3 

    0xb51efb1b,// 36 PAY   4 

    0x9118f822,// 37 PAY   5 

    0xec66220d,// 38 PAY   6 

    0xb7689a5b,// 39 PAY   7 

    0xb51a21f3,// 40 PAY   8 

    0x8cdfcfb7,// 41 PAY   9 

    0x92921f0f,// 42 PAY  10 

    0x59ab18f4,// 43 PAY  11 

    0xaf23a8dc,// 44 PAY  12 

    0xab5d780c,// 45 PAY  13 

    0x6103cd03,// 46 PAY  14 

    0x900eacb2,// 47 PAY  15 

    0xb27a7d94,// 48 PAY  16 

    0xb7b9058f,// 49 PAY  17 

    0x3ef5847f,// 50 PAY  18 

    0xc80299b3,// 51 PAY  19 

    0x6b448c35,// 52 PAY  20 

    0x698dfe55,// 53 PAY  21 

    0xd9679241,// 54 PAY  22 

    0xec95771c,// 55 PAY  23 

    0x2557f629,// 56 PAY  24 

    0xd1643b47,// 57 PAY  25 

    0x52652769,// 58 PAY  26 

    0xf0dff5c9,// 59 PAY  27 

    0x855173c9,// 60 PAY  28 

    0xf55343de,// 61 PAY  29 

    0xe9e4f042,// 62 PAY  30 

    0xe1e7e95f,// 63 PAY  31 

    0xc30d7ddc,// 64 PAY  32 

    0x6470d325,// 65 PAY  33 

    0x5d75348f,// 66 PAY  34 

    0x669c96ac,// 67 PAY  35 

    0x7849e450,// 68 PAY  36 

    0x26a5f65b,// 69 PAY  37 

    0xd72f2e67,// 70 PAY  38 

    0xa442a8e4,// 71 PAY  39 

    0x5bcb45c3,// 72 PAY  40 

    0x58803fbe,// 73 PAY  41 

    0xcd29184e,// 74 PAY  42 

    0xc008a7c3,// 75 PAY  43 

    0xa61394c0,// 76 PAY  44 

    0x7027d65f,// 77 PAY  45 

    0xf9baec54,// 78 PAY  46 

    0x44b7b8c4,// 79 PAY  47 

    0x4b144dee,// 80 PAY  48 

    0xeec9abad,// 81 PAY  49 

    0x1addc80c,// 82 PAY  50 

    0x08558e48,// 83 PAY  51 

    0x2a4c95b9,// 84 PAY  52 

    0xd49955fe,// 85 PAY  53 

    0xe2211b96,// 86 PAY  54 

    0xf7e716a3,// 87 PAY  55 

    0x0c406dd4,// 88 PAY  56 

    0x5c71feca,// 89 PAY  57 

    0xdb8f096a,// 90 PAY  58 

    0x5ec9e386,// 91 PAY  59 

    0xd5a54e97,// 92 PAY  60 

    0xa208ea1e,// 93 PAY  61 

    0x2bea1ce1,// 94 PAY  62 

    0x55336d50,// 95 PAY  63 

    0xf188feeb,// 96 PAY  64 

    0x5089d1c1,// 97 PAY  65 

    0xf63d6c35,// 98 PAY  66 

    0x1a98a999,// 99 PAY  67 

    0xd31461c6,// 100 PAY  68 

    0xbb7582ce,// 101 PAY  69 

    0xdaea63cd,// 102 PAY  70 

    0xb7ad95f3,// 103 PAY  71 

    0x6341aaf4,// 104 PAY  72 

    0x1ec9bfd8,// 105 PAY  73 

    0xdfc88bc6,// 106 PAY  74 

    0xe8cee7df,// 107 PAY  75 

    0xba769d6c,// 108 PAY  76 

    0xbdea5c5b,// 109 PAY  77 

    0x5b72fec4,// 110 PAY  78 

    0x3f518a88,// 111 PAY  79 

    0x58da4331,// 112 PAY  80 

    0xcafc03ae,// 113 PAY  81 

    0x64daa7a5,// 114 PAY  82 

    0xe9d1d9ba,// 115 PAY  83 

    0x699f4f30,// 116 PAY  84 

    0x5df8f692,// 117 PAY  85 

    0x7f1e99f2,// 118 PAY  86 

    0xa38eca57,// 119 PAY  87 

    0x6bfaaa1d,// 120 PAY  88 

    0x81ca5503,// 121 PAY  89 

    0x23fdfb31,// 122 PAY  90 

    0xf0eb5441,// 123 PAY  91 

    0xf760ae6f,// 124 PAY  92 

    0xa731b285,// 125 PAY  93 

    0x29bb1e47,// 126 PAY  94 

    0x16002382,// 127 PAY  95 

    0x8f48de30,// 128 PAY  96 

    0x58d39c0a,// 129 PAY  97 

    0x19c99e15,// 130 PAY  98 

    0x45bfccc9,// 131 PAY  99 

    0xcbb73df5,// 132 PAY 100 

    0x3eeaae28,// 133 PAY 101 

    0xdde8ccf4,// 134 PAY 102 

    0x30e1f2c6,// 135 PAY 103 

    0xdb1d8602,// 136 PAY 104 

    0x4426b905,// 137 PAY 105 

    0x0fb29755,// 138 PAY 106 

    0x59420000,// 139 PAY 107 

/// STA is 1 words. 

/// STA num_pkts       : 244 

/// STA pkt_idx        : 68 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x7a 

    0x01107af4 // 140 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt60_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0d 

/// ECH pdu_tag        : 0x00 

    0x000d0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x80842869,// 4 SCX   2 

    0x00006384,// 5 SCX   3 

    0xb5a8e6b3,// 6 SCX   4 

    0xb15743af,// 7 SCX   5 

    0x4a858ebc,// 8 SCX   6 

    0x51def40a,// 9 SCX   7 

    0x5c4b1def,// 10 SCX   8 

    0xa6d5108e,// 11 SCX   9 

    0xf4b68ac4,// 12 SCX  10 

    0x2ea60d10,// 13 SCX  11 

    0xb0f40997,// 14 SCX  12 

    0x2cbda3d3,// 15 SCX  13 

    0x52a883a6,// 16 SCX  14 

    0x6f232668,// 17 SCX  15 

    0x2a554549,// 18 SCX  16 

    0x5edac6dd,// 19 SCX  17 

    0x1155da83,// 20 SCX  18 

    0x2970c641,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1792 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1741 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1741 

/// BFD lencrypto      : 144 

/// BFD ofstcrypto     : 812 

/// BFD (ofst+len)cry  : 956 

/// BFD ofstiv         : 564 

/// BFD ofsticv        : 1752 

    0x000006cd,// 22 BFD   1 

    0x032c0090,// 23 BFD   2 

    0x06d80234,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c004776,// 25 MFM   1 

    0xd0d5377a,// 26 MFM   2 

    0x3f06b8d6,// 27 MFM   3 

    0x8afc5399,// 28 MFM   4 

    0xe7d84fcd,// 29 MFM   5 

    0x002f5dfb,// 30 MFM   6 

    0x99be1602,// 31 MFM   7 

    0xc3d09c13,// 32 MFM   8 

    0xb8fae9d2,// 33 MFM   9 

    0x83d05308,// 34 MFM  10 

    0xdb37af6f,// 35 MFM  11 

    0xc3941d98,// 36 MFM  12 

    0x28be73a7,// 37 MFM  13 

    0x3e7f2f52,// 38 MFM  14 

    0x8657b960,// 39 MFM  15 

    0x553199d7,// 40 MFM  16 

/// BDA is 449 words. 

/// BDA size     is 1792 (0x700) 

/// BDA id       is 0x6d6b 

    0x07006d6b,// 41 BDA   1 

/// PAY Generic Data size   : 1792 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x5e3840ec,// 42 PAY   1 

    0x9183336e,// 43 PAY   2 

    0x14ef95b0,// 44 PAY   3 

    0x8b1b50da,// 45 PAY   4 

    0x2ca7f920,// 46 PAY   5 

    0x5e13fbab,// 47 PAY   6 

    0x703ddc6e,// 48 PAY   7 

    0x861fb14e,// 49 PAY   8 

    0x4bd0626c,// 50 PAY   9 

    0x7b9e2dda,// 51 PAY  10 

    0xe152bbce,// 52 PAY  11 

    0xc0d26413,// 53 PAY  12 

    0xc8877f47,// 54 PAY  13 

    0x11a1c308,// 55 PAY  14 

    0x35f6b4bc,// 56 PAY  15 

    0x3c1dd95e,// 57 PAY  16 

    0x00a281eb,// 58 PAY  17 

    0xf86d069e,// 59 PAY  18 

    0x15c0217c,// 60 PAY  19 

    0x42f34c5b,// 61 PAY  20 

    0xfe480bef,// 62 PAY  21 

    0xba4b3af3,// 63 PAY  22 

    0xe4735943,// 64 PAY  23 

    0x08e29004,// 65 PAY  24 

    0x73b3e91b,// 66 PAY  25 

    0x5bea4234,// 67 PAY  26 

    0x7c52b4c4,// 68 PAY  27 

    0x5835966a,// 69 PAY  28 

    0xbc2c5c08,// 70 PAY  29 

    0xf1054306,// 71 PAY  30 

    0xf154e9df,// 72 PAY  31 

    0x75c36da1,// 73 PAY  32 

    0xd4d98458,// 74 PAY  33 

    0xb25f32f9,// 75 PAY  34 

    0xcd300a82,// 76 PAY  35 

    0xe58222e7,// 77 PAY  36 

    0xc8f8fd38,// 78 PAY  37 

    0x8eef51f3,// 79 PAY  38 

    0x9408dec8,// 80 PAY  39 

    0x021c9a29,// 81 PAY  40 

    0x9e96115b,// 82 PAY  41 

    0x430e1fe2,// 83 PAY  42 

    0x0ad1dfbd,// 84 PAY  43 

    0xb0bd6eb4,// 85 PAY  44 

    0x4224dc8c,// 86 PAY  45 

    0xcfbd9185,// 87 PAY  46 

    0xca277e7c,// 88 PAY  47 

    0x5ba8c125,// 89 PAY  48 

    0xf71be716,// 90 PAY  49 

    0xd0c6df63,// 91 PAY  50 

    0x88e25534,// 92 PAY  51 

    0x2274d5b9,// 93 PAY  52 

    0x2cd5300e,// 94 PAY  53 

    0xc9b1a256,// 95 PAY  54 

    0x117150bc,// 96 PAY  55 

    0x0f6043b6,// 97 PAY  56 

    0x1af6e51b,// 98 PAY  57 

    0x312e7798,// 99 PAY  58 

    0xc0fae3c4,// 100 PAY  59 

    0x72f07f65,// 101 PAY  60 

    0x7277c874,// 102 PAY  61 

    0x7411d034,// 103 PAY  62 

    0xa01d056c,// 104 PAY  63 

    0xfa7b03f1,// 105 PAY  64 

    0x976b4f79,// 106 PAY  65 

    0x74c3bef1,// 107 PAY  66 

    0x476f65b8,// 108 PAY  67 

    0x22672bba,// 109 PAY  68 

    0x30d41b6c,// 110 PAY  69 

    0x0f5e67df,// 111 PAY  70 

    0x59a85e4c,// 112 PAY  71 

    0x3bcf1e8c,// 113 PAY  72 

    0x8cd5963f,// 114 PAY  73 

    0x22c84250,// 115 PAY  74 

    0x665def0a,// 116 PAY  75 

    0x1f3255c4,// 117 PAY  76 

    0x8ca46ce3,// 118 PAY  77 

    0x178f7830,// 119 PAY  78 

    0xbd9d28f1,// 120 PAY  79 

    0xe6eb7f7f,// 121 PAY  80 

    0x6c1d30df,// 122 PAY  81 

    0xcd766f75,// 123 PAY  82 

    0xbdb6aed1,// 124 PAY  83 

    0x56f4e868,// 125 PAY  84 

    0x71e837ee,// 126 PAY  85 

    0xa4d7a01b,// 127 PAY  86 

    0xb9aea520,// 128 PAY  87 

    0x0f7cbf1d,// 129 PAY  88 

    0xf823ed02,// 130 PAY  89 

    0xfb316ec9,// 131 PAY  90 

    0xe657dbe1,// 132 PAY  91 

    0x14ef46b0,// 133 PAY  92 

    0x726ebb79,// 134 PAY  93 

    0x6481234c,// 135 PAY  94 

    0x81fb295e,// 136 PAY  95 

    0xb60d212f,// 137 PAY  96 

    0x70f5066e,// 138 PAY  97 

    0x35dd8a09,// 139 PAY  98 

    0x355a1659,// 140 PAY  99 

    0x203ce37a,// 141 PAY 100 

    0x15836020,// 142 PAY 101 

    0xdbc81fd3,// 143 PAY 102 

    0x70c6b5fc,// 144 PAY 103 

    0xa16e15a8,// 145 PAY 104 

    0x53e39f71,// 146 PAY 105 

    0x001e4a41,// 147 PAY 106 

    0x55fa11d5,// 148 PAY 107 

    0x3c6e401c,// 149 PAY 108 

    0xae5a1121,// 150 PAY 109 

    0xc16a3dbb,// 151 PAY 110 

    0x8386fc9a,// 152 PAY 111 

    0x91f4b736,// 153 PAY 112 

    0x0a7fd7d9,// 154 PAY 113 

    0x5013da5d,// 155 PAY 114 

    0x5261fc78,// 156 PAY 115 

    0x16d9bb0f,// 157 PAY 116 

    0xe9474ee3,// 158 PAY 117 

    0x1ec9dea4,// 159 PAY 118 

    0x7af6357b,// 160 PAY 119 

    0x068515ce,// 161 PAY 120 

    0x4088d759,// 162 PAY 121 

    0x4ac40012,// 163 PAY 122 

    0xa78f4858,// 164 PAY 123 

    0xca8384ed,// 165 PAY 124 

    0x79984fb4,// 166 PAY 125 

    0x6d54f989,// 167 PAY 126 

    0xc0fe3683,// 168 PAY 127 

    0x29f5e04f,// 169 PAY 128 

    0x6cf447fb,// 170 PAY 129 

    0x6975d786,// 171 PAY 130 

    0x1c290b94,// 172 PAY 131 

    0x297dd8da,// 173 PAY 132 

    0xfac5990a,// 174 PAY 133 

    0x3f756ff8,// 175 PAY 134 

    0xc3873c79,// 176 PAY 135 

    0xc0fbd5f0,// 177 PAY 136 

    0xb1844ebe,// 178 PAY 137 

    0xc9141946,// 179 PAY 138 

    0x2c9102be,// 180 PAY 139 

    0x58f4c32f,// 181 PAY 140 

    0x94a1e025,// 182 PAY 141 

    0xfe45ab01,// 183 PAY 142 

    0x7b49d3c0,// 184 PAY 143 

    0xffca9fa5,// 185 PAY 144 

    0xf7bb90d1,// 186 PAY 145 

    0x161887a1,// 187 PAY 146 

    0xf367606d,// 188 PAY 147 

    0x1effb875,// 189 PAY 148 

    0x05ccd0db,// 190 PAY 149 

    0x7bf0ba83,// 191 PAY 150 

    0x3ec09275,// 192 PAY 151 

    0xe7e03c9a,// 193 PAY 152 

    0x9b8e7064,// 194 PAY 153 

    0xfe6819e8,// 195 PAY 154 

    0xd1075e50,// 196 PAY 155 

    0xb92495bf,// 197 PAY 156 

    0x52944350,// 198 PAY 157 

    0x866e2028,// 199 PAY 158 

    0x4c0f43af,// 200 PAY 159 

    0x885403b6,// 201 PAY 160 

    0x5ff466ec,// 202 PAY 161 

    0x5019c958,// 203 PAY 162 

    0x7398c009,// 204 PAY 163 

    0x360b1941,// 205 PAY 164 

    0xf74fc073,// 206 PAY 165 

    0x7d0c854e,// 207 PAY 166 

    0x9b3fc06b,// 208 PAY 167 

    0x69eaaa9a,// 209 PAY 168 

    0x00b68050,// 210 PAY 169 

    0x3ea56df4,// 211 PAY 170 

    0x674635b9,// 212 PAY 171 

    0x6e5b30ff,// 213 PAY 172 

    0x34c60f3b,// 214 PAY 173 

    0x50456d6b,// 215 PAY 174 

    0x50bd23dc,// 216 PAY 175 

    0x3783ce5e,// 217 PAY 176 

    0x451b9cc8,// 218 PAY 177 

    0xb8bfa651,// 219 PAY 178 

    0xbad82c3c,// 220 PAY 179 

    0xa206fbed,// 221 PAY 180 

    0x7fac0d71,// 222 PAY 181 

    0x03de7e99,// 223 PAY 182 

    0x38934621,// 224 PAY 183 

    0x942612a0,// 225 PAY 184 

    0x90eac12f,// 226 PAY 185 

    0xc51bc559,// 227 PAY 186 

    0xb0831df3,// 228 PAY 187 

    0xd40c029d,// 229 PAY 188 

    0xbc5dbb85,// 230 PAY 189 

    0x6fe37eb0,// 231 PAY 190 

    0x170ed068,// 232 PAY 191 

    0xa1201802,// 233 PAY 192 

    0x1e624565,// 234 PAY 193 

    0xfd801f4a,// 235 PAY 194 

    0x07d31050,// 236 PAY 195 

    0xca8dcf06,// 237 PAY 196 

    0x7e63eca9,// 238 PAY 197 

    0x2c0c8ec5,// 239 PAY 198 

    0xc6955c9d,// 240 PAY 199 

    0x1d50df45,// 241 PAY 200 

    0x10311865,// 242 PAY 201 

    0x5e54fc53,// 243 PAY 202 

    0x628a60a7,// 244 PAY 203 

    0xbcfb799e,// 245 PAY 204 

    0xf8fd8b7a,// 246 PAY 205 

    0x62f9a715,// 247 PAY 206 

    0x03eed673,// 248 PAY 207 

    0xab6cdde3,// 249 PAY 208 

    0xd2ac23ff,// 250 PAY 209 

    0xc0d36fbb,// 251 PAY 210 

    0x43b7562b,// 252 PAY 211 

    0xc42a0e9f,// 253 PAY 212 

    0x7c6f2d77,// 254 PAY 213 

    0x84bd42be,// 255 PAY 214 

    0x92a2539f,// 256 PAY 215 

    0xd7aeb739,// 257 PAY 216 

    0xb0ea0d84,// 258 PAY 217 

    0x7e30744e,// 259 PAY 218 

    0x8318ea4c,// 260 PAY 219 

    0x08e9da61,// 261 PAY 220 

    0x48806885,// 262 PAY 221 

    0x2955c744,// 263 PAY 222 

    0x76d472f9,// 264 PAY 223 

    0x5bd80ef4,// 265 PAY 224 

    0xa8693566,// 266 PAY 225 

    0x59bda4ac,// 267 PAY 226 

    0x2b031ff1,// 268 PAY 227 

    0x02090bf2,// 269 PAY 228 

    0xe7cac955,// 270 PAY 229 

    0x36a8700d,// 271 PAY 230 

    0xcf826760,// 272 PAY 231 

    0xc1664706,// 273 PAY 232 

    0xe6fa05b6,// 274 PAY 233 

    0xa34dc59c,// 275 PAY 234 

    0xd0e72b2c,// 276 PAY 235 

    0x2f731098,// 277 PAY 236 

    0x6cf5b804,// 278 PAY 237 

    0xffade967,// 279 PAY 238 

    0xc5c1180f,// 280 PAY 239 

    0x5489b6c5,// 281 PAY 240 

    0x78b48b48,// 282 PAY 241 

    0x96b585fe,// 283 PAY 242 

    0xc6c8c6c7,// 284 PAY 243 

    0x11f8f455,// 285 PAY 244 

    0x7de1fa17,// 286 PAY 245 

    0x544e2fc8,// 287 PAY 246 

    0x37193d94,// 288 PAY 247 

    0x80de6d7f,// 289 PAY 248 

    0xfec8586a,// 290 PAY 249 

    0x57bbcc20,// 291 PAY 250 

    0x8ca887bc,// 292 PAY 251 

    0xdcda88c9,// 293 PAY 252 

    0x4c2fefbc,// 294 PAY 253 

    0x7302814a,// 295 PAY 254 

    0x4e8b0b40,// 296 PAY 255 

    0x7c8398b4,// 297 PAY 256 

    0xefb02862,// 298 PAY 257 

    0xf755eff8,// 299 PAY 258 

    0x3a4f6bf8,// 300 PAY 259 

    0xf164c0c8,// 301 PAY 260 

    0xd1a1b097,// 302 PAY 261 

    0x9e19820a,// 303 PAY 262 

    0x61058c53,// 304 PAY 263 

    0x88e41bdb,// 305 PAY 264 

    0xdb47b4cc,// 306 PAY 265 

    0x7483f316,// 307 PAY 266 

    0xaad7eea3,// 308 PAY 267 

    0x18695c8c,// 309 PAY 268 

    0x441a09af,// 310 PAY 269 

    0x368242e2,// 311 PAY 270 

    0x423b4013,// 312 PAY 271 

    0x4e83323c,// 313 PAY 272 

    0x8b40b603,// 314 PAY 273 

    0x36a32f03,// 315 PAY 274 

    0x9b76a8d3,// 316 PAY 275 

    0x84aa6390,// 317 PAY 276 

    0x277e445a,// 318 PAY 277 

    0x3f73d15b,// 319 PAY 278 

    0xf9338181,// 320 PAY 279 

    0x3597c3b8,// 321 PAY 280 

    0x7869be53,// 322 PAY 281 

    0x34e6d4cd,// 323 PAY 282 

    0xb0657544,// 324 PAY 283 

    0x7d9643d7,// 325 PAY 284 

    0x370bea3d,// 326 PAY 285 

    0x28f08cc8,// 327 PAY 286 

    0x94ae5008,// 328 PAY 287 

    0xdf6d3562,// 329 PAY 288 

    0x8e2db270,// 330 PAY 289 

    0x23777097,// 331 PAY 290 

    0x1b2e68f9,// 332 PAY 291 

    0xc4adb49a,// 333 PAY 292 

    0xacafa10a,// 334 PAY 293 

    0x093d28c0,// 335 PAY 294 

    0xa02dfe4b,// 336 PAY 295 

    0xe788c94d,// 337 PAY 296 

    0xd163b390,// 338 PAY 297 

    0xd28614f6,// 339 PAY 298 

    0xd3830c55,// 340 PAY 299 

    0xda472386,// 341 PAY 300 

    0x04059e6a,// 342 PAY 301 

    0xbf243fcf,// 343 PAY 302 

    0x07756414,// 344 PAY 303 

    0x0ba6e45b,// 345 PAY 304 

    0xc3930834,// 346 PAY 305 

    0xb8f36edf,// 347 PAY 306 

    0xf6c32dbe,// 348 PAY 307 

    0x56923e94,// 349 PAY 308 

    0x94d8d752,// 350 PAY 309 

    0x2070d46e,// 351 PAY 310 

    0xb5973427,// 352 PAY 311 

    0x2e0b770f,// 353 PAY 312 

    0xb12ff02f,// 354 PAY 313 

    0x93f14274,// 355 PAY 314 

    0x84f758a5,// 356 PAY 315 

    0xcefecb00,// 357 PAY 316 

    0x87b4e82d,// 358 PAY 317 

    0x1b005428,// 359 PAY 318 

    0x1ce73297,// 360 PAY 319 

    0x8efa7380,// 361 PAY 320 

    0x49748b50,// 362 PAY 321 

    0xfe78c01a,// 363 PAY 322 

    0xde222d0d,// 364 PAY 323 

    0x4dc44357,// 365 PAY 324 

    0xd7b80684,// 366 PAY 325 

    0x0cb1820f,// 367 PAY 326 

    0xd654cfdc,// 368 PAY 327 

    0x3d6fe4e1,// 369 PAY 328 

    0x3e313311,// 370 PAY 329 

    0xba56a4f8,// 371 PAY 330 

    0x972cd991,// 372 PAY 331 

    0x032d46dc,// 373 PAY 332 

    0x2611ac83,// 374 PAY 333 

    0x6d6d8dbf,// 375 PAY 334 

    0x3a9bfbc6,// 376 PAY 335 

    0x4862dc81,// 377 PAY 336 

    0x8f0bc642,// 378 PAY 337 

    0x998c94e5,// 379 PAY 338 

    0xe0c9e9b5,// 380 PAY 339 

    0x48eaf55c,// 381 PAY 340 

    0xc878b645,// 382 PAY 341 

    0x621bac64,// 383 PAY 342 

    0x70d85b30,// 384 PAY 343 

    0xf1e19aa5,// 385 PAY 344 

    0x8aacf431,// 386 PAY 345 

    0xc3f236f9,// 387 PAY 346 

    0xa1cee21e,// 388 PAY 347 

    0x9aeb0b4a,// 389 PAY 348 

    0x77e8109a,// 390 PAY 349 

    0x21e8bd52,// 391 PAY 350 

    0x6d4269cb,// 392 PAY 351 

    0xc5b4d05c,// 393 PAY 352 

    0x11989aa3,// 394 PAY 353 

    0x231aa71a,// 395 PAY 354 

    0xaa991ddc,// 396 PAY 355 

    0x5d858126,// 397 PAY 356 

    0x0f5e3184,// 398 PAY 357 

    0x0794e9aa,// 399 PAY 358 

    0xb2b13309,// 400 PAY 359 

    0xa363017d,// 401 PAY 360 

    0x130ccf41,// 402 PAY 361 

    0x632e0a70,// 403 PAY 362 

    0xbcbc45f2,// 404 PAY 363 

    0xb58fd149,// 405 PAY 364 

    0x5e01a9bc,// 406 PAY 365 

    0x940206de,// 407 PAY 366 

    0xdedd9f6d,// 408 PAY 367 

    0x9ec50555,// 409 PAY 368 

    0x06d3c20a,// 410 PAY 369 

    0x8469d27c,// 411 PAY 370 

    0xc7226afa,// 412 PAY 371 

    0x1149057b,// 413 PAY 372 

    0xd8d209f6,// 414 PAY 373 

    0xb4b46a2d,// 415 PAY 374 

    0xd9276abe,// 416 PAY 375 

    0xb25a812d,// 417 PAY 376 

    0x4a26e088,// 418 PAY 377 

    0x97f2b06f,// 419 PAY 378 

    0x1d0580f6,// 420 PAY 379 

    0x9a874e4d,// 421 PAY 380 

    0xc4f23457,// 422 PAY 381 

    0x199cdc6b,// 423 PAY 382 

    0xfebbab39,// 424 PAY 383 

    0x186042be,// 425 PAY 384 

    0x2166dc88,// 426 PAY 385 

    0xcec33723,// 427 PAY 386 

    0xa952dc42,// 428 PAY 387 

    0x9070acf3,// 429 PAY 388 

    0x6abc3d27,// 430 PAY 389 

    0xaa1ed7df,// 431 PAY 390 

    0x429d2869,// 432 PAY 391 

    0xff64792b,// 433 PAY 392 

    0xfe2dd280,// 434 PAY 393 

    0x808942ae,// 435 PAY 394 

    0xcc3b6660,// 436 PAY 395 

    0xb86ad204,// 437 PAY 396 

    0x261904ed,// 438 PAY 397 

    0x9ab102b9,// 439 PAY 398 

    0xdb1955c2,// 440 PAY 399 

    0xda281ccf,// 441 PAY 400 

    0xa485234c,// 442 PAY 401 

    0xa3ea2c8d,// 443 PAY 402 

    0xddba337c,// 444 PAY 403 

    0x40cc3b25,// 445 PAY 404 

    0xe59d8367,// 446 PAY 405 

    0x710dfe74,// 447 PAY 406 

    0x8e3a46f1,// 448 PAY 407 

    0xc798ed65,// 449 PAY 408 

    0x79e48fe0,// 450 PAY 409 

    0xe8010eef,// 451 PAY 410 

    0x1c2b3fc1,// 452 PAY 411 

    0x2a3945f9,// 453 PAY 412 

    0xee356bb6,// 454 PAY 413 

    0x4051512f,// 455 PAY 414 

    0x12265ef7,// 456 PAY 415 

    0xae595a9c,// 457 PAY 416 

    0xe11b9264,// 458 PAY 417 

    0x094dd352,// 459 PAY 418 

    0x301c1886,// 460 PAY 419 

    0x71144eee,// 461 PAY 420 

    0x764333de,// 462 PAY 421 

    0xc8f7bb7d,// 463 PAY 422 

    0xe289ec2a,// 464 PAY 423 

    0xcd490889,// 465 PAY 424 

    0x34aa3bd1,// 466 PAY 425 

    0xd61ebfaf,// 467 PAY 426 

    0x8cbe8096,// 468 PAY 427 

    0xab63e846,// 469 PAY 428 

    0x007e5d3e,// 470 PAY 429 

    0x3de77c40,// 471 PAY 430 

    0x03fb421f,// 472 PAY 431 

    0xd87df6c6,// 473 PAY 432 

    0x8217de5f,// 474 PAY 433 

    0xba3bfe31,// 475 PAY 434 

    0x5a3ed53b,// 476 PAY 435 

    0xbfa37224,// 477 PAY 436 

    0xbc6799e7,// 478 PAY 437 

    0x62317a4c,// 479 PAY 438 

    0xdc02626c,// 480 PAY 439 

    0x44da1c91,// 481 PAY 440 

    0x37061b8e,// 482 PAY 441 

    0xb3ddf455,// 483 PAY 442 

    0x9bc3615f,// 484 PAY 443 

    0x6e99f7ed,// 485 PAY 444 

    0xe8813b9d,// 486 PAY 445 

    0x6c24d85a,// 487 PAY 446 

    0xd290b0f2,// 488 PAY 447 

    0x2989bdd0,// 489 PAY 448 

/// STA is 1 words. 

/// STA num_pkts       : 18 

/// STA pkt_idx        : 20 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xda 

    0x0051da12 // 490 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt61_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x809228b0,// 4 SCX   2 

    0x000053c2,// 5 SCX   3 

    0xfed544cc,// 6 SCX   4 

    0x5f565f2f,// 7 SCX   5 

    0x26e66c0d,// 8 SCX   6 

    0x6ff5201a,// 9 SCX   7 

    0x582f24e3,// 10 SCX   8 

    0x07de19df,// 11 SCX   9 

    0xe58ddec5,// 12 SCX  10 

    0x8101776b,// 13 SCX  11 

    0x7111cb4b,// 14 SCX  12 

    0x1008de2b,// 15 SCX  13 

    0x5bdc6c58,// 16 SCX  14 

    0xc3e3e7d8,// 17 SCX  15 

    0xaf0d0251,// 18 SCX  16 

    0x31b7f596,// 19 SCX  17 

    0x55671e3c,// 20 SCX  18 

    0xf3df3426,// 21 SCX  19 

    0x13d99a2c,// 22 SCX  20 

    0x34ae9a9d,// 23 SCX  21 

    0x22584a7f,// 24 SCX  22 

    0x74a1c828,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1920 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 1749 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1749 

/// BFD lencrypto      : 148 

/// BFD ofstcrypto     : 1136 

/// BFD (ofst+len)cry  : 1284 

/// BFD ofstiv         : 856 

/// BFD ofsticv        : 1780 

    0x000006d5,// 26 BFD   1 

    0x04700094,// 27 BFD   2 

    0x06f40358,// 28 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c000a3a,// 29 MFM   1 

    0xf2f77a1d,// 30 MFM   2 

    0xebbd2896,// 31 MFM   3 

    0xa382d5ae,// 32 MFM   4 

    0x896385bc,// 33 MFM   5 

    0x1295126f,// 34 MFM   6 

    0x257b0b57,// 35 MFM   7 

    0x75d9da98,// 36 MFM   8 

    0x26d366a2,// 37 MFM   9 

    0xccec35ed,// 38 MFM  10 

    0x23acfec4,// 39 MFM  11 

    0x9e7934ab,// 40 MFM  12 

    0x146bd4e7,// 41 MFM  13 

    0x3bc9399c,// 42 MFM  14 

    0x7d53bbb8,// 43 MFM  15 

    0x3072076f,// 44 MFM  16 

/// BDA is 481 words. 

/// BDA size     is 1920 (0x780) 

/// BDA id       is 0xb58b 

    0x0780b58b,// 45 BDA   1 

/// PAY Generic Data size   : 1920 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xa55c077c,// 46 PAY   1 

    0xac752890,// 47 PAY   2 

    0xf8266fd8,// 48 PAY   3 

    0x88cfb298,// 49 PAY   4 

    0x16356390,// 50 PAY   5 

    0x2e16bc41,// 51 PAY   6 

    0xfbe99a09,// 52 PAY   7 

    0x2e91c8ad,// 53 PAY   8 

    0xcfd079d7,// 54 PAY   9 

    0x77e29276,// 55 PAY  10 

    0x7d336873,// 56 PAY  11 

    0x34602e75,// 57 PAY  12 

    0x8770d505,// 58 PAY  13 

    0x9bb96f8d,// 59 PAY  14 

    0x37bf307f,// 60 PAY  15 

    0xe42d1f41,// 61 PAY  16 

    0xba821e17,// 62 PAY  17 

    0xbd245575,// 63 PAY  18 

    0xa6c10db5,// 64 PAY  19 

    0x2de6e446,// 65 PAY  20 

    0xb5a02b80,// 66 PAY  21 

    0x70018e44,// 67 PAY  22 

    0x93a8194c,// 68 PAY  23 

    0x60fc5ed5,// 69 PAY  24 

    0xcea40a16,// 70 PAY  25 

    0x0f1e1d3c,// 71 PAY  26 

    0xae1ef164,// 72 PAY  27 

    0x63c7d7d1,// 73 PAY  28 

    0x3edd9313,// 74 PAY  29 

    0xe379355c,// 75 PAY  30 

    0xe742d5a4,// 76 PAY  31 

    0x645a792f,// 77 PAY  32 

    0xedc972df,// 78 PAY  33 

    0xcbe27842,// 79 PAY  34 

    0x2193a206,// 80 PAY  35 

    0xb1a270f7,// 81 PAY  36 

    0xc5413a7d,// 82 PAY  37 

    0x0784fd6c,// 83 PAY  38 

    0x39d336fb,// 84 PAY  39 

    0xc74a0f41,// 85 PAY  40 

    0x8b6594fe,// 86 PAY  41 

    0x66dcd55b,// 87 PAY  42 

    0xb989f1fc,// 88 PAY  43 

    0xe988e86c,// 89 PAY  44 

    0xe2ae6108,// 90 PAY  45 

    0xba85c8b1,// 91 PAY  46 

    0x3518d7db,// 92 PAY  47 

    0xe979a42e,// 93 PAY  48 

    0xc3ff24b5,// 94 PAY  49 

    0x35fdd523,// 95 PAY  50 

    0x6eab508c,// 96 PAY  51 

    0x1e9f3e99,// 97 PAY  52 

    0x3f8eab1e,// 98 PAY  53 

    0x32c3e8f3,// 99 PAY  54 

    0x7b5cd77e,// 100 PAY  55 

    0xd1878c7f,// 101 PAY  56 

    0x582d03e0,// 102 PAY  57 

    0x8389f62f,// 103 PAY  58 

    0xdbc07442,// 104 PAY  59 

    0x82079a64,// 105 PAY  60 

    0x9954c8e3,// 106 PAY  61 

    0x84a758c4,// 107 PAY  62 

    0x23564c9b,// 108 PAY  63 

    0x4715233a,// 109 PAY  64 

    0xbd30c208,// 110 PAY  65 

    0x0bd5a271,// 111 PAY  66 

    0xa2d6c257,// 112 PAY  67 

    0x9e07f740,// 113 PAY  68 

    0xcfaacf09,// 114 PAY  69 

    0x13b537dc,// 115 PAY  70 

    0x6cb86579,// 116 PAY  71 

    0x912af7dc,// 117 PAY  72 

    0xee671e50,// 118 PAY  73 

    0x516a8009,// 119 PAY  74 

    0x06c6cc23,// 120 PAY  75 

    0x819d4e59,// 121 PAY  76 

    0xf56ee244,// 122 PAY  77 

    0xad85a3d0,// 123 PAY  78 

    0xf89d49a2,// 124 PAY  79 

    0xc7b79690,// 125 PAY  80 

    0xf4d0c7e9,// 126 PAY  81 

    0xa513a7cb,// 127 PAY  82 

    0x0fef36e7,// 128 PAY  83 

    0xbbe7f192,// 129 PAY  84 

    0x5dd0142b,// 130 PAY  85 

    0xea7d8736,// 131 PAY  86 

    0x164c449f,// 132 PAY  87 

    0xef64360e,// 133 PAY  88 

    0x146ea541,// 134 PAY  89 

    0x3d5f8add,// 135 PAY  90 

    0xf925f206,// 136 PAY  91 

    0x74b9d0b0,// 137 PAY  92 

    0x36f26f72,// 138 PAY  93 

    0xceaebff5,// 139 PAY  94 

    0xf3dc85e3,// 140 PAY  95 

    0xeb941a7d,// 141 PAY  96 

    0x78d93de5,// 142 PAY  97 

    0xe4e6bcab,// 143 PAY  98 

    0x1160e408,// 144 PAY  99 

    0xb624948f,// 145 PAY 100 

    0xde6f2fe4,// 146 PAY 101 

    0xf09bccac,// 147 PAY 102 

    0x859d3277,// 148 PAY 103 

    0x11251992,// 149 PAY 104 

    0xb7278bf4,// 150 PAY 105 

    0x5e795bd0,// 151 PAY 106 

    0x8100ef6e,// 152 PAY 107 

    0xa3ceaccb,// 153 PAY 108 

    0xe0b8451a,// 154 PAY 109 

    0x88acedde,// 155 PAY 110 

    0xfe37c612,// 156 PAY 111 

    0x928b53a9,// 157 PAY 112 

    0x339f22ec,// 158 PAY 113 

    0x0ee37281,// 159 PAY 114 

    0xa1dd43e2,// 160 PAY 115 

    0xf2e43e7b,// 161 PAY 116 

    0xda2e75cc,// 162 PAY 117 

    0x6ae9371e,// 163 PAY 118 

    0x1dfa0f88,// 164 PAY 119 

    0xc747b41b,// 165 PAY 120 

    0x50cb46cb,// 166 PAY 121 

    0x93c1d803,// 167 PAY 122 

    0x4eaeab18,// 168 PAY 123 

    0x6cb0e54a,// 169 PAY 124 

    0xf2449d7b,// 170 PAY 125 

    0x32a37488,// 171 PAY 126 

    0xe1be2eed,// 172 PAY 127 

    0x55be92bf,// 173 PAY 128 

    0x6d26b208,// 174 PAY 129 

    0x2c73ad8d,// 175 PAY 130 

    0x914cc624,// 176 PAY 131 

    0x9964f42d,// 177 PAY 132 

    0x7cd441e5,// 178 PAY 133 

    0x78a82683,// 179 PAY 134 

    0xb170765e,// 180 PAY 135 

    0xa4cc694c,// 181 PAY 136 

    0x40322134,// 182 PAY 137 

    0xbc52fbce,// 183 PAY 138 

    0x2097bbcd,// 184 PAY 139 

    0x05829cd1,// 185 PAY 140 

    0xef8d3d69,// 186 PAY 141 

    0x38d6175b,// 187 PAY 142 

    0x9ef86122,// 188 PAY 143 

    0x4449e484,// 189 PAY 144 

    0x0563b74f,// 190 PAY 145 

    0xa847150c,// 191 PAY 146 

    0xf0cc4df0,// 192 PAY 147 

    0x62d9a1ae,// 193 PAY 148 

    0xd6c9577e,// 194 PAY 149 

    0x220c924f,// 195 PAY 150 

    0x6e4d1e2b,// 196 PAY 151 

    0x5234528f,// 197 PAY 152 

    0x5d4d4525,// 198 PAY 153 

    0x952377ae,// 199 PAY 154 

    0x0b877731,// 200 PAY 155 

    0xf165d633,// 201 PAY 156 

    0x7afceb4f,// 202 PAY 157 

    0x2e881570,// 203 PAY 158 

    0x861d2630,// 204 PAY 159 

    0xfcac507f,// 205 PAY 160 

    0x3bf6577c,// 206 PAY 161 

    0x1bfa71cf,// 207 PAY 162 

    0xd2b6862e,// 208 PAY 163 

    0x5e11c2ab,// 209 PAY 164 

    0xe5ed1b88,// 210 PAY 165 

    0x494bd55c,// 211 PAY 166 

    0x9cd9b181,// 212 PAY 167 

    0x24f97611,// 213 PAY 168 

    0x1cdcaed7,// 214 PAY 169 

    0xda405a16,// 215 PAY 170 

    0x90abdecc,// 216 PAY 171 

    0xa368c666,// 217 PAY 172 

    0x92caddb4,// 218 PAY 173 

    0xc588fef7,// 219 PAY 174 

    0xaef0508b,// 220 PAY 175 

    0xd0c1c6b0,// 221 PAY 176 

    0xdaeb7337,// 222 PAY 177 

    0xf3ae41ff,// 223 PAY 178 

    0x39c8c638,// 224 PAY 179 

    0x52fbfb74,// 225 PAY 180 

    0x5a5c8e1b,// 226 PAY 181 

    0x5f42bbf0,// 227 PAY 182 

    0x1b1560b6,// 228 PAY 183 

    0xa450f3d1,// 229 PAY 184 

    0xe1731cda,// 230 PAY 185 

    0xc02f6c35,// 231 PAY 186 

    0xbd4e6c33,// 232 PAY 187 

    0x23868ca1,// 233 PAY 188 

    0xef2622bc,// 234 PAY 189 

    0x05f73fe4,// 235 PAY 190 

    0x53dfbd6e,// 236 PAY 191 

    0x4dae091b,// 237 PAY 192 

    0x133bbf22,// 238 PAY 193 

    0x7928748c,// 239 PAY 194 

    0x64d09b75,// 240 PAY 195 

    0xf0372281,// 241 PAY 196 

    0x5c00a13c,// 242 PAY 197 

    0xafd76a3b,// 243 PAY 198 

    0x4cb152b1,// 244 PAY 199 

    0x1aee81bc,// 245 PAY 200 

    0xae464700,// 246 PAY 201 

    0xce169f7f,// 247 PAY 202 

    0xca15fa4e,// 248 PAY 203 

    0x08094514,// 249 PAY 204 

    0xbefdfcb9,// 250 PAY 205 

    0xd3a0a132,// 251 PAY 206 

    0x0f5ff80d,// 252 PAY 207 

    0x7eba0a9f,// 253 PAY 208 

    0x4debb848,// 254 PAY 209 

    0x38c180dd,// 255 PAY 210 

    0xcbe5f48a,// 256 PAY 211 

    0x788b70c3,// 257 PAY 212 

    0x518b2b4b,// 258 PAY 213 

    0xb345232f,// 259 PAY 214 

    0x74fb1a17,// 260 PAY 215 

    0xd7078667,// 261 PAY 216 

    0x8cb4a22b,// 262 PAY 217 

    0xac5b0937,// 263 PAY 218 

    0xdb8e9d08,// 264 PAY 219 

    0x854545fa,// 265 PAY 220 

    0x0e3c100f,// 266 PAY 221 

    0x4c0a2689,// 267 PAY 222 

    0xf9e750e9,// 268 PAY 223 

    0x123edbad,// 269 PAY 224 

    0x68f6888b,// 270 PAY 225 

    0xb3eb7256,// 271 PAY 226 

    0xd5f9302f,// 272 PAY 227 

    0x100f8732,// 273 PAY 228 

    0x70caa38c,// 274 PAY 229 

    0x9a908355,// 275 PAY 230 

    0x9bbb1817,// 276 PAY 231 

    0x3e1c3377,// 277 PAY 232 

    0x8e49d671,// 278 PAY 233 

    0xe35a1fec,// 279 PAY 234 

    0x233f4c8e,// 280 PAY 235 

    0x63bee6fd,// 281 PAY 236 

    0x99ead7aa,// 282 PAY 237 

    0xb987615b,// 283 PAY 238 

    0x83e06833,// 284 PAY 239 

    0x25b4aefa,// 285 PAY 240 

    0x852d22ae,// 286 PAY 241 

    0x8a6eaf80,// 287 PAY 242 

    0xac7e6528,// 288 PAY 243 

    0x5db51095,// 289 PAY 244 

    0x82794e23,// 290 PAY 245 

    0x7344f0a7,// 291 PAY 246 

    0x0c88db72,// 292 PAY 247 

    0x73c2b790,// 293 PAY 248 

    0x64ffd0c8,// 294 PAY 249 

    0x620d591d,// 295 PAY 250 

    0x3e8c7cdf,// 296 PAY 251 

    0x12369bac,// 297 PAY 252 

    0xb4762d4e,// 298 PAY 253 

    0x47010767,// 299 PAY 254 

    0xfe6d5f1c,// 300 PAY 255 

    0xc21c05c7,// 301 PAY 256 

    0x3501223b,// 302 PAY 257 

    0xa027f453,// 303 PAY 258 

    0x8a79e95b,// 304 PAY 259 

    0xa09bbb46,// 305 PAY 260 

    0x732d382e,// 306 PAY 261 

    0x7b952202,// 307 PAY 262 

    0x976230c3,// 308 PAY 263 

    0xdb189bb6,// 309 PAY 264 

    0xdd211d83,// 310 PAY 265 

    0x8132b286,// 311 PAY 266 

    0x08c25a85,// 312 PAY 267 

    0x1cfa6397,// 313 PAY 268 

    0x83c76731,// 314 PAY 269 

    0x0742c10e,// 315 PAY 270 

    0xad892a86,// 316 PAY 271 

    0x46711935,// 317 PAY 272 

    0x1466c62e,// 318 PAY 273 

    0x9a775c02,// 319 PAY 274 

    0x7effe4e5,// 320 PAY 275 

    0xc698a934,// 321 PAY 276 

    0xcbe3e455,// 322 PAY 277 

    0x85d2b436,// 323 PAY 278 

    0x8962c1c9,// 324 PAY 279 

    0x84e19b02,// 325 PAY 280 

    0x5b88ddca,// 326 PAY 281 

    0xe5ce1e61,// 327 PAY 282 

    0x98e51ebe,// 328 PAY 283 

    0xa06b6235,// 329 PAY 284 

    0xa150925d,// 330 PAY 285 

    0xa4bc1e9f,// 331 PAY 286 

    0xcb95803f,// 332 PAY 287 

    0xaf7d9a76,// 333 PAY 288 

    0x7f16d99c,// 334 PAY 289 

    0x2cfc1326,// 335 PAY 290 

    0xb66973b1,// 336 PAY 291 

    0x18f5de66,// 337 PAY 292 

    0x4979fcdb,// 338 PAY 293 

    0x643b4ec3,// 339 PAY 294 

    0x926afa9f,// 340 PAY 295 

    0x5c588029,// 341 PAY 296 

    0xe26b2782,// 342 PAY 297 

    0xb1d37ca0,// 343 PAY 298 

    0x716cb6e1,// 344 PAY 299 

    0x039b974e,// 345 PAY 300 

    0x39d852bb,// 346 PAY 301 

    0x542a7028,// 347 PAY 302 

    0x03a268b2,// 348 PAY 303 

    0x9ab51a62,// 349 PAY 304 

    0x5a01a3ed,// 350 PAY 305 

    0x7aac13d1,// 351 PAY 306 

    0xd9ed1283,// 352 PAY 307 

    0x3fbc43b4,// 353 PAY 308 

    0x39baebff,// 354 PAY 309 

    0xcf34d71e,// 355 PAY 310 

    0xaa1b802d,// 356 PAY 311 

    0x8621933e,// 357 PAY 312 

    0x4406f459,// 358 PAY 313 

    0x05bda55b,// 359 PAY 314 

    0xe58822c6,// 360 PAY 315 

    0xd6803e51,// 361 PAY 316 

    0x97c1221f,// 362 PAY 317 

    0x611ddf40,// 363 PAY 318 

    0xd2dd4f44,// 364 PAY 319 

    0x025dfdf2,// 365 PAY 320 

    0x889051a9,// 366 PAY 321 

    0x762bef74,// 367 PAY 322 

    0x17c57615,// 368 PAY 323 

    0xc41310cf,// 369 PAY 324 

    0x823351d8,// 370 PAY 325 

    0x6d99fdcc,// 371 PAY 326 

    0x41936330,// 372 PAY 327 

    0x3486dd17,// 373 PAY 328 

    0xf28c563a,// 374 PAY 329 

    0x8f0858bb,// 375 PAY 330 

    0x03a7ef78,// 376 PAY 331 

    0x795bc02c,// 377 PAY 332 

    0x9ac87d81,// 378 PAY 333 

    0x0f3b729a,// 379 PAY 334 

    0xbc4067c1,// 380 PAY 335 

    0x47d5c5fd,// 381 PAY 336 

    0x6a805656,// 382 PAY 337 

    0xa7da2cad,// 383 PAY 338 

    0x10557b6d,// 384 PAY 339 

    0x7d1f6837,// 385 PAY 340 

    0x80324980,// 386 PAY 341 

    0x17faa5b8,// 387 PAY 342 

    0x6aa12720,// 388 PAY 343 

    0x458b0e78,// 389 PAY 344 

    0xbda0409f,// 390 PAY 345 

    0x5af3cd12,// 391 PAY 346 

    0x25397088,// 392 PAY 347 

    0x5cca54e0,// 393 PAY 348 

    0x1892c8f4,// 394 PAY 349 

    0xbfd0b2fe,// 395 PAY 350 

    0xd29a4b38,// 396 PAY 351 

    0x951c043c,// 397 PAY 352 

    0xf062be56,// 398 PAY 353 

    0xe6a4997d,// 399 PAY 354 

    0xa73df7fc,// 400 PAY 355 

    0x1bb7d39e,// 401 PAY 356 

    0x6fabe8aa,// 402 PAY 357 

    0x4a1bbecb,// 403 PAY 358 

    0x6c9c1c28,// 404 PAY 359 

    0x5e2bb4da,// 405 PAY 360 

    0xeaa0b09b,// 406 PAY 361 

    0x798fc14a,// 407 PAY 362 

    0x6d14ecf7,// 408 PAY 363 

    0xe3d5cfc8,// 409 PAY 364 

    0x868022d5,// 410 PAY 365 

    0x4ef5832f,// 411 PAY 366 

    0xe632d969,// 412 PAY 367 

    0x89da5e94,// 413 PAY 368 

    0xae4a68fc,// 414 PAY 369 

    0xc894e55f,// 415 PAY 370 

    0xc605c8a0,// 416 PAY 371 

    0x20e88a44,// 417 PAY 372 

    0x8140cc41,// 418 PAY 373 

    0xa20ff1ce,// 419 PAY 374 

    0x5f35a165,// 420 PAY 375 

    0x24cb9fde,// 421 PAY 376 

    0x2605e6b6,// 422 PAY 377 

    0x6622a2a2,// 423 PAY 378 

    0xa1884d71,// 424 PAY 379 

    0x78fd88c3,// 425 PAY 380 

    0x6aa1fd1c,// 426 PAY 381 

    0xb6f99946,// 427 PAY 382 

    0x07a07f92,// 428 PAY 383 

    0x00b3d27d,// 429 PAY 384 

    0x8cc41be3,// 430 PAY 385 

    0x0f34e924,// 431 PAY 386 

    0xf5388c93,// 432 PAY 387 

    0xf8ec9370,// 433 PAY 388 

    0x8576012a,// 434 PAY 389 

    0x568216d6,// 435 PAY 390 

    0x3f3c6432,// 436 PAY 391 

    0x706171b5,// 437 PAY 392 

    0x2a9ffa3e,// 438 PAY 393 

    0xd8592cd2,// 439 PAY 394 

    0x7168dbfa,// 440 PAY 395 

    0x5b6a9470,// 441 PAY 396 

    0x2666dbcb,// 442 PAY 397 

    0x6b851531,// 443 PAY 398 

    0xd38beeba,// 444 PAY 399 

    0x2f5f1582,// 445 PAY 400 

    0xe4cf79ff,// 446 PAY 401 

    0x966fb515,// 447 PAY 402 

    0xd863dec9,// 448 PAY 403 

    0xfe7ffd8f,// 449 PAY 404 

    0xf91c89a3,// 450 PAY 405 

    0x90a41af4,// 451 PAY 406 

    0x95150e94,// 452 PAY 407 

    0xdc042bc0,// 453 PAY 408 

    0x51a7148c,// 454 PAY 409 

    0xff64fcd5,// 455 PAY 410 

    0x68f99d48,// 456 PAY 411 

    0xceffb823,// 457 PAY 412 

    0x4081abb6,// 458 PAY 413 

    0xac379345,// 459 PAY 414 

    0x23e83215,// 460 PAY 415 

    0x014e5897,// 461 PAY 416 

    0x2a2cf6d8,// 462 PAY 417 

    0xedc52e96,// 463 PAY 418 

    0x2b82485c,// 464 PAY 419 

    0x99d8d8ae,// 465 PAY 420 

    0x936d18ae,// 466 PAY 421 

    0x98ad13a2,// 467 PAY 422 

    0xfd26a123,// 468 PAY 423 

    0x84cc4da3,// 469 PAY 424 

    0x9508ebc2,// 470 PAY 425 

    0xfb5f3edd,// 471 PAY 426 

    0xf7c1180e,// 472 PAY 427 

    0x4002ba26,// 473 PAY 428 

    0xb276b007,// 474 PAY 429 

    0xaf1cd894,// 475 PAY 430 

    0x9def65ab,// 476 PAY 431 

    0x970b08f9,// 477 PAY 432 

    0x21a47e8b,// 478 PAY 433 

    0x6c13590a,// 479 PAY 434 

    0x999fa93a,// 480 PAY 435 

    0x409e70f1,// 481 PAY 436 

    0x11f0dd46,// 482 PAY 437 

    0xc6620811,// 483 PAY 438 

    0x55ae3bb1,// 484 PAY 439 

    0xcf676e12,// 485 PAY 440 

    0x60e40d5c,// 486 PAY 441 

    0x75a906ab,// 487 PAY 442 

    0x90e79371,// 488 PAY 443 

    0x1c5a38bd,// 489 PAY 444 

    0xa3f0fb7b,// 490 PAY 445 

    0x50112c7e,// 491 PAY 446 

    0x0cbe515c,// 492 PAY 447 

    0xf7b165bf,// 493 PAY 448 

    0x43d08178,// 494 PAY 449 

    0x2db8d64e,// 495 PAY 450 

    0xc731dca0,// 496 PAY 451 

    0xf562c1bb,// 497 PAY 452 

    0x70df8093,// 498 PAY 453 

    0xf14e5421,// 499 PAY 454 

    0xa8219a3a,// 500 PAY 455 

    0xd9fbe4c3,// 501 PAY 456 

    0x8e2daa19,// 502 PAY 457 

    0x51b51599,// 503 PAY 458 

    0x3a0265ff,// 504 PAY 459 

    0xc0c0f71f,// 505 PAY 460 

    0xccc25de3,// 506 PAY 461 

    0x3066b7de,// 507 PAY 462 

    0x89af4e51,// 508 PAY 463 

    0x4fba5be1,// 509 PAY 464 

    0xa258663a,// 510 PAY 465 

    0xdd1f4b11,// 511 PAY 466 

    0x34715530,// 512 PAY 467 

    0xdc2c8254,// 513 PAY 468 

    0x7ac06024,// 514 PAY 469 

    0xd3ca04ae,// 515 PAY 470 

    0x6de5c975,// 516 PAY 471 

    0x062151e9,// 517 PAY 472 

    0xffadc9af,// 518 PAY 473 

    0x76f4b27a,// 519 PAY 474 

    0xdb116972,// 520 PAY 475 

    0xf1295964,// 521 PAY 476 

    0xab03c2a2,// 522 PAY 477 

    0x70b89272,// 523 PAY 478 

    0x3007113c,// 524 PAY 479 

    0x7a5bd2b0,// 525 PAY 480 

/// STA is 1 words. 

/// STA num_pkts       : 178 

/// STA pkt_idx        : 214 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x6e 

    0x03586eb2 // 526 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt62_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000011,// 3 SCX   1 

    0x80812870,// 4 SCX   2 

    0x00001400,// 5 SCX   3 

    0x0c8986d9,// 6 SCX   4 

    0x91c238e3,// 7 SCX   5 

    0x406364e4,// 8 SCX   6 

    0x50215c2d,// 9 SCX   7 

    0xe52ffe91,// 10 SCX   8 

    0xe49e4c23,// 11 SCX   9 

    0x80ce95d7,// 12 SCX  10 

    0x678eb8fb,// 13 SCX  11 

    0x3e3f0d6a,// 14 SCX  12 

    0x8e2c3233,// 15 SCX  13 

    0xa2556ff7,// 16 SCX  14 

    0xa98fe084,// 17 SCX  15 

    0x880bde4d,// 18 SCX  16 

    0xcb3bd9c0,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 2028 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 755 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 755 

/// BFD lencrypto      : 192 

/// BFD ofstcrypto     : 40 

/// BFD (ofst+len)cry  : 232 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 1612 

    0x000002f3,// 20 BFD   1 

    0x002800c0,// 21 BFD   2 

    0x064c000c,// 22 BFD   3 

/// MFM is 10 words. 

/// MFM vldnibs        : 46 

    0x460088af,// 23 MFM   1 

    0x300f5d40,// 24 MFM   2 

    0x544413b8,// 25 MFM   3 

    0x3e5ed8c0,// 26 MFM   4 

    0xc41a368b,// 27 MFM   5 

    0x421f32fb,// 28 MFM   6 

    0x5f86ddb7,// 29 MFM   7 

    0xc116ae20,// 30 MFM   8 

    0xe0261481,// 31 MFM   9 

    0x5a000000,// 32 MFM  10 

/// BDA is 508 words. 

/// BDA size     is 2028 (0x7ec) 

/// BDA id       is 0x8eca 

    0x07ec8eca,// 33 BDA   1 

/// PAY Generic Data size   : 2028 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x61430c0f,// 34 PAY   1 

    0xacc96660,// 35 PAY   2 

    0xe394124a,// 36 PAY   3 

    0x186fa4ca,// 37 PAY   4 

    0x6b52834e,// 38 PAY   5 

    0xa6cf57d3,// 39 PAY   6 

    0xf897c981,// 40 PAY   7 

    0xc15644f1,// 41 PAY   8 

    0x5e989011,// 42 PAY   9 

    0x30e66ab1,// 43 PAY  10 

    0x34a7cd1f,// 44 PAY  11 

    0xe801286f,// 45 PAY  12 

    0x2b0d6c4f,// 46 PAY  13 

    0x2252ea8f,// 47 PAY  14 

    0xa59a14bf,// 48 PAY  15 

    0x992b4bb2,// 49 PAY  16 

    0x40e4b71e,// 50 PAY  17 

    0x1d07747c,// 51 PAY  18 

    0xea1cffc8,// 52 PAY  19 

    0xcf22297b,// 53 PAY  20 

    0x10de7d1c,// 54 PAY  21 

    0x838bdc6c,// 55 PAY  22 

    0xd5b01ac8,// 56 PAY  23 

    0x9cc02c9e,// 57 PAY  24 

    0x180d1224,// 58 PAY  25 

    0x8748c132,// 59 PAY  26 

    0x37bef541,// 60 PAY  27 

    0xc69d8655,// 61 PAY  28 

    0x8f5fc6ed,// 62 PAY  29 

    0x11a86ced,// 63 PAY  30 

    0x2f3b47f9,// 64 PAY  31 

    0x23e0b890,// 65 PAY  32 

    0x9e04f1a6,// 66 PAY  33 

    0x242fed21,// 67 PAY  34 

    0x2dd91716,// 68 PAY  35 

    0x15dca92a,// 69 PAY  36 

    0xe8eaa5ef,// 70 PAY  37 

    0x6ca50233,// 71 PAY  38 

    0x3ee744bd,// 72 PAY  39 

    0x7b72eef5,// 73 PAY  40 

    0x34cb12f4,// 74 PAY  41 

    0x7d1641b9,// 75 PAY  42 

    0x1fe6da03,// 76 PAY  43 

    0xd2ad1cab,// 77 PAY  44 

    0xbbe0b4aa,// 78 PAY  45 

    0x2e104b57,// 79 PAY  46 

    0x8459a268,// 80 PAY  47 

    0x8652b514,// 81 PAY  48 

    0x1c86a561,// 82 PAY  49 

    0xfe45b08e,// 83 PAY  50 

    0xb1beb135,// 84 PAY  51 

    0x000bf365,// 85 PAY  52 

    0x251c638f,// 86 PAY  53 

    0xecb92125,// 87 PAY  54 

    0x2caa1970,// 88 PAY  55 

    0xa8431485,// 89 PAY  56 

    0xe0b5fd81,// 90 PAY  57 

    0x4a3273a0,// 91 PAY  58 

    0xe8c5bba2,// 92 PAY  59 

    0x7ba7d5cb,// 93 PAY  60 

    0xa6384b4b,// 94 PAY  61 

    0xa7153fa4,// 95 PAY  62 

    0x41249814,// 96 PAY  63 

    0x5efdbec1,// 97 PAY  64 

    0xf39d3f6f,// 98 PAY  65 

    0xf5b67aac,// 99 PAY  66 

    0x694a2d66,// 100 PAY  67 

    0x09a13ed3,// 101 PAY  68 

    0x4b0fb840,// 102 PAY  69 

    0x2f085386,// 103 PAY  70 

    0xd30eb394,// 104 PAY  71 

    0x00e4d588,// 105 PAY  72 

    0x349a3ebb,// 106 PAY  73 

    0xf499a15a,// 107 PAY  74 

    0x8222c4ca,// 108 PAY  75 

    0x03dfa017,// 109 PAY  76 

    0x64fdbcae,// 110 PAY  77 

    0xa2ff9b8c,// 111 PAY  78 

    0xf789d678,// 112 PAY  79 

    0x66df99b9,// 113 PAY  80 

    0x9639c665,// 114 PAY  81 

    0x4882ad58,// 115 PAY  82 

    0x897f3c2d,// 116 PAY  83 

    0xacadd463,// 117 PAY  84 

    0x73352d22,// 118 PAY  85 

    0x69ccf38c,// 119 PAY  86 

    0xa73f643e,// 120 PAY  87 

    0x4b9986a2,// 121 PAY  88 

    0xdebe5b1f,// 122 PAY  89 

    0xac72eaf2,// 123 PAY  90 

    0x1a54273d,// 124 PAY  91 

    0xe134542c,// 125 PAY  92 

    0x00023291,// 126 PAY  93 

    0x04135270,// 127 PAY  94 

    0xb1457ba5,// 128 PAY  95 

    0xe6d12e56,// 129 PAY  96 

    0xaba71494,// 130 PAY  97 

    0x93528a88,// 131 PAY  98 

    0xd87c0002,// 132 PAY  99 

    0x67701025,// 133 PAY 100 

    0xb31ba106,// 134 PAY 101 

    0xc0c5be54,// 135 PAY 102 

    0xbffb0f62,// 136 PAY 103 

    0xdaeec51d,// 137 PAY 104 

    0x9295f220,// 138 PAY 105 

    0xc7f86a67,// 139 PAY 106 

    0x8bd82826,// 140 PAY 107 

    0x7098677e,// 141 PAY 108 

    0x7d8ebd5b,// 142 PAY 109 

    0xa17a7e0e,// 143 PAY 110 

    0xdf6aef09,// 144 PAY 111 

    0x5704af3c,// 145 PAY 112 

    0x5baa5da8,// 146 PAY 113 

    0x6dff65ec,// 147 PAY 114 

    0x70f1cfb2,// 148 PAY 115 

    0x2228cf6b,// 149 PAY 116 

    0x16748f26,// 150 PAY 117 

    0xd538e60a,// 151 PAY 118 

    0xb5eb054c,// 152 PAY 119 

    0x7791456c,// 153 PAY 120 

    0xfb112853,// 154 PAY 121 

    0x616ada3b,// 155 PAY 122 

    0x69f7fa18,// 156 PAY 123 

    0x722e71a5,// 157 PAY 124 

    0xbd16ecc4,// 158 PAY 125 

    0x67261e86,// 159 PAY 126 

    0x27c949d6,// 160 PAY 127 

    0x88be476e,// 161 PAY 128 

    0xd12a5cf1,// 162 PAY 129 

    0x0fdd9409,// 163 PAY 130 

    0x7a4c16bb,// 164 PAY 131 

    0xd4d07af3,// 165 PAY 132 

    0x3542fef4,// 166 PAY 133 

    0x324f6133,// 167 PAY 134 

    0x3efb2e5b,// 168 PAY 135 

    0xf9172629,// 169 PAY 136 

    0xacacb150,// 170 PAY 137 

    0xac9fdbbf,// 171 PAY 138 

    0xb8651089,// 172 PAY 139 

    0x46045128,// 173 PAY 140 

    0x1d5c5c7c,// 174 PAY 141 

    0x9f070bbd,// 175 PAY 142 

    0x929316e1,// 176 PAY 143 

    0xcf6232d2,// 177 PAY 144 

    0x24ff0127,// 178 PAY 145 

    0x973b9f9b,// 179 PAY 146 

    0x7a09f7c5,// 180 PAY 147 

    0xff4be658,// 181 PAY 148 

    0x38bc5461,// 182 PAY 149 

    0x0e3a8994,// 183 PAY 150 

    0xfcd91126,// 184 PAY 151 

    0x314d66f8,// 185 PAY 152 

    0x1f90fcc9,// 186 PAY 153 

    0x6deab148,// 187 PAY 154 

    0x37eddc96,// 188 PAY 155 

    0x8ad12548,// 189 PAY 156 

    0x9ff91ae8,// 190 PAY 157 

    0x35a642cb,// 191 PAY 158 

    0x8dea087b,// 192 PAY 159 

    0x991d53e6,// 193 PAY 160 

    0x5ea6b76c,// 194 PAY 161 

    0xf7e9dcb0,// 195 PAY 162 

    0xe8fa30a5,// 196 PAY 163 

    0xf7dc2575,// 197 PAY 164 

    0x93065785,// 198 PAY 165 

    0xec73159e,// 199 PAY 166 

    0x23708272,// 200 PAY 167 

    0x5d69b9cc,// 201 PAY 168 

    0x510b9348,// 202 PAY 169 

    0x23a89ee5,// 203 PAY 170 

    0x04af1edc,// 204 PAY 171 

    0x8255db7e,// 205 PAY 172 

    0x20f22e8f,// 206 PAY 173 

    0x9f0916de,// 207 PAY 174 

    0x8b092682,// 208 PAY 175 

    0x363779ed,// 209 PAY 176 

    0x5d04acd3,// 210 PAY 177 

    0x3d429828,// 211 PAY 178 

    0x074314f3,// 212 PAY 179 

    0x4e231da3,// 213 PAY 180 

    0xc9124a84,// 214 PAY 181 

    0x1e088bcd,// 215 PAY 182 

    0x5f68edd0,// 216 PAY 183 

    0x412a763e,// 217 PAY 184 

    0x96a5882a,// 218 PAY 185 

    0x7889f9db,// 219 PAY 186 

    0xbb64678e,// 220 PAY 187 

    0x972452ef,// 221 PAY 188 

    0x9bcee0f8,// 222 PAY 189 

    0x3f45a985,// 223 PAY 190 

    0xc146faa7,// 224 PAY 191 

    0x5a16c595,// 225 PAY 192 

    0xc2ef82f0,// 226 PAY 193 

    0x87f5f5e1,// 227 PAY 194 

    0x57408bda,// 228 PAY 195 

    0x2bc7c301,// 229 PAY 196 

    0x20140f6d,// 230 PAY 197 

    0xd83ccbe9,// 231 PAY 198 

    0xab0b6e66,// 232 PAY 199 

    0x390bb392,// 233 PAY 200 

    0xd028a3d9,// 234 PAY 201 

    0x678d020a,// 235 PAY 202 

    0x4e21bd98,// 236 PAY 203 

    0x0e50b9c8,// 237 PAY 204 

    0xaac6b86d,// 238 PAY 205 

    0x530bab81,// 239 PAY 206 

    0xc6442129,// 240 PAY 207 

    0x7432a5ca,// 241 PAY 208 

    0x8ef9ad7d,// 242 PAY 209 

    0xf6d760a3,// 243 PAY 210 

    0x1bd6ed9c,// 244 PAY 211 

    0x61eb1c36,// 245 PAY 212 

    0x6484cff8,// 246 PAY 213 

    0x0914ef86,// 247 PAY 214 

    0x9c06c1af,// 248 PAY 215 

    0x5142670c,// 249 PAY 216 

    0x9a5b4257,// 250 PAY 217 

    0x59570bd4,// 251 PAY 218 

    0xeaecb11d,// 252 PAY 219 

    0xcae8adde,// 253 PAY 220 

    0x7d2a3c6b,// 254 PAY 221 

    0x13f06434,// 255 PAY 222 

    0x17819d7b,// 256 PAY 223 

    0x72c98e59,// 257 PAY 224 

    0xb58a3340,// 258 PAY 225 

    0x3142aaab,// 259 PAY 226 

    0x97bfe136,// 260 PAY 227 

    0x9b8db2a6,// 261 PAY 228 

    0x55198f68,// 262 PAY 229 

    0x5c8c58eb,// 263 PAY 230 

    0x490189a8,// 264 PAY 231 

    0x2ac5fe74,// 265 PAY 232 

    0xd8728765,// 266 PAY 233 

    0x46db81fe,// 267 PAY 234 

    0x036fecf0,// 268 PAY 235 

    0xa24d3bb9,// 269 PAY 236 

    0x0850e44f,// 270 PAY 237 

    0xe81d9e7a,// 271 PAY 238 

    0x5b536b36,// 272 PAY 239 

    0x3a8381d6,// 273 PAY 240 

    0x5839a802,// 274 PAY 241 

    0x6694d4e5,// 275 PAY 242 

    0x8a1b14a7,// 276 PAY 243 

    0x52181a4e,// 277 PAY 244 

    0xab428b63,// 278 PAY 245 

    0xe9c48c22,// 279 PAY 246 

    0xee4c8513,// 280 PAY 247 

    0x75b2eabf,// 281 PAY 248 

    0x0f73bf62,// 282 PAY 249 

    0x58308cb5,// 283 PAY 250 

    0x2d2f4d56,// 284 PAY 251 

    0xff49f4dc,// 285 PAY 252 

    0xbe7f8a5b,// 286 PAY 253 

    0xcb4091e1,// 287 PAY 254 

    0xb7b957a5,// 288 PAY 255 

    0x7a778093,// 289 PAY 256 

    0x06eb7d7e,// 290 PAY 257 

    0xb05bf02d,// 291 PAY 258 

    0x3e9e1b64,// 292 PAY 259 

    0x4cfd6c3f,// 293 PAY 260 

    0xbdd0838d,// 294 PAY 261 

    0xf0449fff,// 295 PAY 262 

    0xd2b5d0ef,// 296 PAY 263 

    0x82289263,// 297 PAY 264 

    0x5d5ddeb9,// 298 PAY 265 

    0x03fba7aa,// 299 PAY 266 

    0x4c1afd23,// 300 PAY 267 

    0x36e9eb2b,// 301 PAY 268 

    0xb83baead,// 302 PAY 269 

    0x477af4ce,// 303 PAY 270 

    0xc5410c56,// 304 PAY 271 

    0x1435a346,// 305 PAY 272 

    0xe9d742f3,// 306 PAY 273 

    0x730c8115,// 307 PAY 274 

    0x6901bd9e,// 308 PAY 275 

    0x0c5bbc0b,// 309 PAY 276 

    0x7c9d19e8,// 310 PAY 277 

    0x78753c8b,// 311 PAY 278 

    0x9dcd946a,// 312 PAY 279 

    0xd01ec817,// 313 PAY 280 

    0x4c248d52,// 314 PAY 281 

    0xca88d7bf,// 315 PAY 282 

    0x79f1ebae,// 316 PAY 283 

    0xb6ebfc69,// 317 PAY 284 

    0x193d50d4,// 318 PAY 285 

    0x255ef8c1,// 319 PAY 286 

    0x1df00cdd,// 320 PAY 287 

    0xb64f1512,// 321 PAY 288 

    0xb3a6ef5a,// 322 PAY 289 

    0x54966c46,// 323 PAY 290 

    0xcb4275ab,// 324 PAY 291 

    0xdc37615f,// 325 PAY 292 

    0xbf01b453,// 326 PAY 293 

    0xce466ef5,// 327 PAY 294 

    0xc9c57469,// 328 PAY 295 

    0xbae7b303,// 329 PAY 296 

    0x9008ef35,// 330 PAY 297 

    0xba432dfd,// 331 PAY 298 

    0x819bb014,// 332 PAY 299 

    0xff2da7a6,// 333 PAY 300 

    0x895b1240,// 334 PAY 301 

    0xca2dc243,// 335 PAY 302 

    0x8c030d0f,// 336 PAY 303 

    0x308b2e84,// 337 PAY 304 

    0x90bbeaf0,// 338 PAY 305 

    0xdc336347,// 339 PAY 306 

    0xf7bccd92,// 340 PAY 307 

    0x4fce1134,// 341 PAY 308 

    0x238755e1,// 342 PAY 309 

    0x5928b86e,// 343 PAY 310 

    0xf8308d0b,// 344 PAY 311 

    0xf526bdc3,// 345 PAY 312 

    0xe285a7ac,// 346 PAY 313 

    0x41188a62,// 347 PAY 314 

    0xe01b2e72,// 348 PAY 315 

    0x9289c2e5,// 349 PAY 316 

    0xdbc08111,// 350 PAY 317 

    0x7162cdbe,// 351 PAY 318 

    0xde803a40,// 352 PAY 319 

    0x70d5a252,// 353 PAY 320 

    0x15326474,// 354 PAY 321 

    0x91777d57,// 355 PAY 322 

    0xad4ebffe,// 356 PAY 323 

    0xfa86127a,// 357 PAY 324 

    0x7db524dc,// 358 PAY 325 

    0x8d947f68,// 359 PAY 326 

    0x4b34182c,// 360 PAY 327 

    0x34d20cfe,// 361 PAY 328 

    0xa711bbe9,// 362 PAY 329 

    0xe334a017,// 363 PAY 330 

    0x3da67d40,// 364 PAY 331 

    0x2f592131,// 365 PAY 332 

    0x437496fb,// 366 PAY 333 

    0x7c71333c,// 367 PAY 334 

    0x57f3db6e,// 368 PAY 335 

    0xf879946e,// 369 PAY 336 

    0x3d46b148,// 370 PAY 337 

    0x6c4d0ec1,// 371 PAY 338 

    0x567d2a5e,// 372 PAY 339 

    0x37409e7b,// 373 PAY 340 

    0xc7b45827,// 374 PAY 341 

    0x303adf5f,// 375 PAY 342 

    0x7b6bea60,// 376 PAY 343 

    0xe4b11bdd,// 377 PAY 344 

    0x61a2f8d7,// 378 PAY 345 

    0xb82cd926,// 379 PAY 346 

    0x8b16161d,// 380 PAY 347 

    0x628ae89c,// 381 PAY 348 

    0x910c1930,// 382 PAY 349 

    0xf47cd00b,// 383 PAY 350 

    0x646e7d42,// 384 PAY 351 

    0x69608c22,// 385 PAY 352 

    0x5bcb249f,// 386 PAY 353 

    0x5f56bc05,// 387 PAY 354 

    0x0cef1621,// 388 PAY 355 

    0xcb9c5f69,// 389 PAY 356 

    0x74cf7510,// 390 PAY 357 

    0x3e060eec,// 391 PAY 358 

    0xbf7bafec,// 392 PAY 359 

    0xce963035,// 393 PAY 360 

    0x1dc89815,// 394 PAY 361 

    0xa223db69,// 395 PAY 362 

    0xfdb14fa3,// 396 PAY 363 

    0xd17d03bf,// 397 PAY 364 

    0x9ad1868c,// 398 PAY 365 

    0xd9d7f6e8,// 399 PAY 366 

    0x3e7f4f53,// 400 PAY 367 

    0x080ab9c4,// 401 PAY 368 

    0x9c1ec65f,// 402 PAY 369 

    0x1df81dd0,// 403 PAY 370 

    0x21488b25,// 404 PAY 371 

    0x7aa401f3,// 405 PAY 372 

    0x4199edf7,// 406 PAY 373 

    0xc76eda83,// 407 PAY 374 

    0xcaac2021,// 408 PAY 375 

    0x18491ec6,// 409 PAY 376 

    0xf82e8860,// 410 PAY 377 

    0x5c61e361,// 411 PAY 378 

    0xece80a3e,// 412 PAY 379 

    0x80f86757,// 413 PAY 380 

    0x94e5e3ae,// 414 PAY 381 

    0x603a18de,// 415 PAY 382 

    0xeba8fa86,// 416 PAY 383 

    0x2d7b7f94,// 417 PAY 384 

    0x72ec5a51,// 418 PAY 385 

    0xafe5180a,// 419 PAY 386 

    0x1b5b201f,// 420 PAY 387 

    0x85f5eeb5,// 421 PAY 388 

    0x484fe397,// 422 PAY 389 

    0xb86ace7d,// 423 PAY 390 

    0xbce2efd1,// 424 PAY 391 

    0xc76b7400,// 425 PAY 392 

    0x4e855a93,// 426 PAY 393 

    0x397d4a8d,// 427 PAY 394 

    0x184bbaf0,// 428 PAY 395 

    0x859cea3f,// 429 PAY 396 

    0x3e51150e,// 430 PAY 397 

    0xf2d373a0,// 431 PAY 398 

    0x0d7bff49,// 432 PAY 399 

    0x544ae360,// 433 PAY 400 

    0x86ca0300,// 434 PAY 401 

    0x176c6216,// 435 PAY 402 

    0x7ebf5f97,// 436 PAY 403 

    0xe1b7fee8,// 437 PAY 404 

    0x649624c4,// 438 PAY 405 

    0xb94a7dcb,// 439 PAY 406 

    0x2f4cb0d8,// 440 PAY 407 

    0xdf7b1a1c,// 441 PAY 408 

    0xac43fe60,// 442 PAY 409 

    0x5f7670b1,// 443 PAY 410 

    0xa8a86bf6,// 444 PAY 411 

    0xb68d1a38,// 445 PAY 412 

    0x6d6e49d2,// 446 PAY 413 

    0xbcb1354a,// 447 PAY 414 

    0x7f9b6594,// 448 PAY 415 

    0xa061177e,// 449 PAY 416 

    0x37b40f24,// 450 PAY 417 

    0xdf63d955,// 451 PAY 418 

    0xd051c988,// 452 PAY 419 

    0x3dad6adc,// 453 PAY 420 

    0x18c520b9,// 454 PAY 421 

    0xfef314e3,// 455 PAY 422 

    0x86f89006,// 456 PAY 423 

    0x91e75157,// 457 PAY 424 

    0xd6caa422,// 458 PAY 425 

    0xdb623041,// 459 PAY 426 

    0xba110d2a,// 460 PAY 427 

    0x22597185,// 461 PAY 428 

    0x159a172f,// 462 PAY 429 

    0x502822d0,// 463 PAY 430 

    0x49f0e042,// 464 PAY 431 

    0xd4c1dca1,// 465 PAY 432 

    0xec3e47dd,// 466 PAY 433 

    0xb0f50e98,// 467 PAY 434 

    0xb5f57ba0,// 468 PAY 435 

    0x19f23c27,// 469 PAY 436 

    0x0035396c,// 470 PAY 437 

    0x696b6f4d,// 471 PAY 438 

    0xc86018e5,// 472 PAY 439 

    0x7c6bfb2c,// 473 PAY 440 

    0x7163d5b9,// 474 PAY 441 

    0x47080bb8,// 475 PAY 442 

    0x3ade1b6c,// 476 PAY 443 

    0xd5dee176,// 477 PAY 444 

    0x877a49b5,// 478 PAY 445 

    0x4f041eaf,// 479 PAY 446 

    0x6a0f73a7,// 480 PAY 447 

    0x2007f95b,// 481 PAY 448 

    0x74b53fe5,// 482 PAY 449 

    0x808b4f14,// 483 PAY 450 

    0x694f4a61,// 484 PAY 451 

    0x61663c30,// 485 PAY 452 

    0x2cbdc235,// 486 PAY 453 

    0x01105233,// 487 PAY 454 

    0x893bb1ee,// 488 PAY 455 

    0x28a3388b,// 489 PAY 456 

    0xe92d86df,// 490 PAY 457 

    0x4643e977,// 491 PAY 458 

    0x65f51b92,// 492 PAY 459 

    0x927671b0,// 493 PAY 460 

    0x76beea44,// 494 PAY 461 

    0x479e9ad9,// 495 PAY 462 

    0x99737a33,// 496 PAY 463 

    0x159bf9ef,// 497 PAY 464 

    0xaf529134,// 498 PAY 465 

    0xde94b1b3,// 499 PAY 466 

    0x383efad2,// 500 PAY 467 

    0x91f228f2,// 501 PAY 468 

    0x56a1435b,// 502 PAY 469 

    0xe9232e50,// 503 PAY 470 

    0xdeac8eca,// 504 PAY 471 

    0xf827687d,// 505 PAY 472 

    0x1f21bb8d,// 506 PAY 473 

    0xcd983e6a,// 507 PAY 474 

    0xfef4ac17,// 508 PAY 475 

    0x41b9d8d6,// 509 PAY 476 

    0x4cef6e76,// 510 PAY 477 

    0xcd06adff,// 511 PAY 478 

    0x46bab037,// 512 PAY 479 

    0x14074f20,// 513 PAY 480 

    0xb4347626,// 514 PAY 481 

    0x3706aad0,// 515 PAY 482 

    0x4c6985bc,// 516 PAY 483 

    0x5806c0bd,// 517 PAY 484 

    0xda8ca5d2,// 518 PAY 485 

    0x52161835,// 519 PAY 486 

    0xcd74ff17,// 520 PAY 487 

    0x55ea5168,// 521 PAY 488 

    0xc6f35969,// 522 PAY 489 

    0x541561f6,// 523 PAY 490 

    0x10b06d74,// 524 PAY 491 

    0x9f10825e,// 525 PAY 492 

    0xc621daf2,// 526 PAY 493 

    0xf2b463d3,// 527 PAY 494 

    0xddd3cf75,// 528 PAY 495 

    0x8e13ae7e,// 529 PAY 496 

    0xf4a8f2c7,// 530 PAY 497 

    0xce3bbeb2,// 531 PAY 498 

    0x67ea9f7d,// 532 PAY 499 

    0x3fa33ea1,// 533 PAY 500 

    0x39107259,// 534 PAY 501 

    0xaaebfe4b,// 535 PAY 502 

    0x2fd91ee6,// 536 PAY 503 

    0x732c44de,// 537 PAY 504 

    0x99e00bf3,// 538 PAY 505 

    0xfa32329f,// 539 PAY 506 

    0xa948f66b,// 540 PAY 507 

/// STA is 1 words. 

/// STA num_pkts       : 128 

/// STA pkt_idx        : 187 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xdd 

    0x02ecdd80 // 541 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt63_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0c 

/// ECH pdu_tag        : 0x00 

    0x000c0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x808228d8,// 4 SCX   2 

    0x00002200,// 5 SCX   3 

    0x6ec40d6f,// 6 SCX   4 

    0xd75bb23c,// 7 SCX   5 

    0xf4e7c7d8,// 8 SCX   6 

    0x7f753dd1,// 9 SCX   7 

    0xf2cd6729,// 10 SCX   8 

    0xbd030f25,// 11 SCX   9 

    0xb1063a22,// 12 SCX  10 

    0x38799bfb,// 13 SCX  11 

    0xfd7ce633,// 14 SCX  12 

    0x400fe7a9,// 15 SCX  13 

    0x48f2afe2,// 16 SCX  14 

    0xc0d4bd87,// 17 SCX  15 

    0xa426f223,// 18 SCX  16 

    0xbc689ebd,// 19 SCX  17 

    0x6a1d731e,// 20 SCX  18 

    0x1a4e5cab,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1581 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 794 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 794 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 764 

/// BFD (ofst+len)cry  : 780 

/// BFD ofstiv         : 136 

/// BFD ofsticv        : 1452 

    0x0000031a,// 22 BFD   1 

    0x02fc0010,// 23 BFD   2 

    0x05ac0088,// 24 BFD   3 

/// MFM is 13 words. 

/// MFM vldnibs        : 61 

    0x610038cf,// 25 MFM   1 

    0x176dac6f,// 26 MFM   2 

    0x2f16dfbd,// 27 MFM   3 

    0xca27f01e,// 28 MFM   4 

    0x54c3f64f,// 29 MFM   5 

    0x1e99c7bd,// 30 MFM   6 

    0xdca2e7de,// 31 MFM   7 

    0xcd948b0f,// 32 MFM   8 

    0x137f9af2,// 33 MFM   9 

    0x9cc6d840,// 34 MFM  10 

    0xac3b55f6,// 35 MFM  11 

    0x66a752f1,// 36 MFM  12 

    0x11b6e000,// 37 MFM  13 

/// BDA is 397 words. 

/// BDA size     is 1581 (0x62d) 

/// BDA id       is 0xad27 

    0x062dad27,// 38 BDA   1 

/// PAY Generic Data size   : 1581 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x65e80bad,// 39 PAY   1 

    0x9e3eb366,// 40 PAY   2 

    0xcc25b4af,// 41 PAY   3 

    0x185a2496,// 42 PAY   4 

    0xeae6da10,// 43 PAY   5 

    0x3a0b987f,// 44 PAY   6 

    0x8dc2ac1a,// 45 PAY   7 

    0xd43c1790,// 46 PAY   8 

    0x817c0aa8,// 47 PAY   9 

    0x6681747d,// 48 PAY  10 

    0x0108a8d8,// 49 PAY  11 

    0xa3d2b37d,// 50 PAY  12 

    0x47892837,// 51 PAY  13 

    0x473be2a0,// 52 PAY  14 

    0x852a01a7,// 53 PAY  15 

    0x38896ba8,// 54 PAY  16 

    0x67afbeca,// 55 PAY  17 

    0xcfae2c30,// 56 PAY  18 

    0xa9c2d74d,// 57 PAY  19 

    0x325b98cb,// 58 PAY  20 

    0xe0f8d709,// 59 PAY  21 

    0x43a88a55,// 60 PAY  22 

    0xfb9a1f59,// 61 PAY  23 

    0xfaa7c3c5,// 62 PAY  24 

    0x3fd219a6,// 63 PAY  25 

    0x791e2aef,// 64 PAY  26 

    0x067189c4,// 65 PAY  27 

    0xd29d1f08,// 66 PAY  28 

    0xfeeff204,// 67 PAY  29 

    0x26db8099,// 68 PAY  30 

    0x44aa384c,// 69 PAY  31 

    0x6c418548,// 70 PAY  32 

    0x23617ea6,// 71 PAY  33 

    0x40398f42,// 72 PAY  34 

    0x14bfa32f,// 73 PAY  35 

    0x71b2b16a,// 74 PAY  36 

    0x74b71ac2,// 75 PAY  37 

    0xd955e4c4,// 76 PAY  38 

    0x1b15bf20,// 77 PAY  39 

    0x631567b7,// 78 PAY  40 

    0x5a303711,// 79 PAY  41 

    0x4d0b09e6,// 80 PAY  42 

    0x08616f4d,// 81 PAY  43 

    0x2ada9cfb,// 82 PAY  44 

    0x360bde22,// 83 PAY  45 

    0x76d732f2,// 84 PAY  46 

    0x5ec72a8f,// 85 PAY  47 

    0xab0a19e7,// 86 PAY  48 

    0x9e5031cb,// 87 PAY  49 

    0x0b16b697,// 88 PAY  50 

    0x11e04af3,// 89 PAY  51 

    0xa057b6b1,// 90 PAY  52 

    0x7cf3d21c,// 91 PAY  53 

    0x04e71e51,// 92 PAY  54 

    0x6faf2219,// 93 PAY  55 

    0xeab06001,// 94 PAY  56 

    0xcec16d10,// 95 PAY  57 

    0x50feb8a2,// 96 PAY  58 

    0xa69d5fe5,// 97 PAY  59 

    0x5713003d,// 98 PAY  60 

    0x56a7da96,// 99 PAY  61 

    0x6167ff0e,// 100 PAY  62 

    0x4989c040,// 101 PAY  63 

    0x7baf1648,// 102 PAY  64 

    0x25915840,// 103 PAY  65 

    0xbc30f032,// 104 PAY  66 

    0xb01d15da,// 105 PAY  67 

    0xbe655c61,// 106 PAY  68 

    0x6ea150c3,// 107 PAY  69 

    0xe4b39025,// 108 PAY  70 

    0x2e807941,// 109 PAY  71 

    0x60d96bf2,// 110 PAY  72 

    0xc91a1872,// 111 PAY  73 

    0x9ba21227,// 112 PAY  74 

    0xb364007c,// 113 PAY  75 

    0x099a43db,// 114 PAY  76 

    0xc3ea619b,// 115 PAY  77 

    0xe68d7bc6,// 116 PAY  78 

    0xef945b97,// 117 PAY  79 

    0x2f4d8c65,// 118 PAY  80 

    0x23eaa281,// 119 PAY  81 

    0xfa72321f,// 120 PAY  82 

    0x6dae2b28,// 121 PAY  83 

    0xccb3c0c5,// 122 PAY  84 

    0x92fb3c1a,// 123 PAY  85 

    0xd0f552d1,// 124 PAY  86 

    0x33434983,// 125 PAY  87 

    0x09210cab,// 126 PAY  88 

    0xc9fa4c76,// 127 PAY  89 

    0x56b04235,// 128 PAY  90 

    0x0f10132c,// 129 PAY  91 

    0xaf906089,// 130 PAY  92 

    0xab1cdb67,// 131 PAY  93 

    0xb5dfbd2d,// 132 PAY  94 

    0x1b166a11,// 133 PAY  95 

    0xedbfa3f5,// 134 PAY  96 

    0x2d40a38b,// 135 PAY  97 

    0x81bbcf2b,// 136 PAY  98 

    0x0e1b0396,// 137 PAY  99 

    0x2011416c,// 138 PAY 100 

    0x7e81d4c3,// 139 PAY 101 

    0x066940c2,// 140 PAY 102 

    0x5965ff1a,// 141 PAY 103 

    0x25278b70,// 142 PAY 104 

    0x40208c33,// 143 PAY 105 

    0x6cf3c61f,// 144 PAY 106 

    0x25b05c15,// 145 PAY 107 

    0xc68a0996,// 146 PAY 108 

    0x822a57ea,// 147 PAY 109 

    0x29482860,// 148 PAY 110 

    0xa232b6e0,// 149 PAY 111 

    0xf3f549e2,// 150 PAY 112 

    0xbaea951c,// 151 PAY 113 

    0x23a6e1c0,// 152 PAY 114 

    0xe492a5cf,// 153 PAY 115 

    0x89a224c4,// 154 PAY 116 

    0x98f04fe3,// 155 PAY 117 

    0x1d1a5069,// 156 PAY 118 

    0xba5297a8,// 157 PAY 119 

    0x292dcdd0,// 158 PAY 120 

    0xdaf192ba,// 159 PAY 121 

    0x8a362e8b,// 160 PAY 122 

    0xc40f0b6c,// 161 PAY 123 

    0xa3006216,// 162 PAY 124 

    0xec6a01b6,// 163 PAY 125 

    0x6905e27b,// 164 PAY 126 

    0x489d4415,// 165 PAY 127 

    0xf40ef0f7,// 166 PAY 128 

    0xf5dc2aab,// 167 PAY 129 

    0xabdfc28d,// 168 PAY 130 

    0xb44aaa78,// 169 PAY 131 

    0xf4cfc990,// 170 PAY 132 

    0x3f5363de,// 171 PAY 133 

    0x60ded868,// 172 PAY 134 

    0x30b8673a,// 173 PAY 135 

    0xc1f065fe,// 174 PAY 136 

    0x1466ef50,// 175 PAY 137 

    0x7cde037e,// 176 PAY 138 

    0x83dff4ac,// 177 PAY 139 

    0xb6d28305,// 178 PAY 140 

    0x99d75018,// 179 PAY 141 

    0xe1a997a1,// 180 PAY 142 

    0xdd5384c4,// 181 PAY 143 

    0xdb0a5dd3,// 182 PAY 144 

    0xdf98275b,// 183 PAY 145 

    0x0ed1cfac,// 184 PAY 146 

    0x36b815a3,// 185 PAY 147 

    0x95ac8aa5,// 186 PAY 148 

    0xb0fc60c3,// 187 PAY 149 

    0x0b0cc68f,// 188 PAY 150 

    0x2fd843e0,// 189 PAY 151 

    0x3dc47883,// 190 PAY 152 

    0x230139a4,// 191 PAY 153 

    0xd719d812,// 192 PAY 154 

    0xd95a9d20,// 193 PAY 155 

    0x74bfba43,// 194 PAY 156 

    0xae9ee675,// 195 PAY 157 

    0x0ef066af,// 196 PAY 158 

    0x2ae39fa7,// 197 PAY 159 

    0x06d85db2,// 198 PAY 160 

    0x70227f74,// 199 PAY 161 

    0x48eb4a0e,// 200 PAY 162 

    0xbf2ff54b,// 201 PAY 163 

    0x7c809465,// 202 PAY 164 

    0xa21a6b15,// 203 PAY 165 

    0xd3654e99,// 204 PAY 166 

    0x0211802e,// 205 PAY 167 

    0xe4f095df,// 206 PAY 168 

    0x2fef4e9f,// 207 PAY 169 

    0xcf0407f8,// 208 PAY 170 

    0x1c60f613,// 209 PAY 171 

    0x618706eb,// 210 PAY 172 

    0xd99b8f1c,// 211 PAY 173 

    0xca8ba323,// 212 PAY 174 

    0xa4add889,// 213 PAY 175 

    0x7cca7c72,// 214 PAY 176 

    0x98199cb3,// 215 PAY 177 

    0x2377a12f,// 216 PAY 178 

    0x48806707,// 217 PAY 179 

    0x9341aa0f,// 218 PAY 180 

    0xf4218e43,// 219 PAY 181 

    0x4d57f442,// 220 PAY 182 

    0xfefe8483,// 221 PAY 183 

    0x9bacc134,// 222 PAY 184 

    0xab628f94,// 223 PAY 185 

    0x11986c82,// 224 PAY 186 

    0x3e8e4d15,// 225 PAY 187 

    0x56d949d1,// 226 PAY 188 

    0x5bc2e8dc,// 227 PAY 189 

    0x4957f75e,// 228 PAY 190 

    0xc52f45b4,// 229 PAY 191 

    0x91cab4c8,// 230 PAY 192 

    0x81990b90,// 231 PAY 193 

    0x6504f07a,// 232 PAY 194 

    0x14b0652f,// 233 PAY 195 

    0x33aeaa98,// 234 PAY 196 

    0xad3ee78b,// 235 PAY 197 

    0xfbb958f7,// 236 PAY 198 

    0xb871d5b0,// 237 PAY 199 

    0x57002305,// 238 PAY 200 

    0x506f329a,// 239 PAY 201 

    0x0ea1aace,// 240 PAY 202 

    0x071eafad,// 241 PAY 203 

    0xf710bb8c,// 242 PAY 204 

    0xd3c69fae,// 243 PAY 205 

    0xf8ba7d3a,// 244 PAY 206 

    0xf1d56cf7,// 245 PAY 207 

    0x8598bf37,// 246 PAY 208 

    0xd65432cb,// 247 PAY 209 

    0xf0bcd0d2,// 248 PAY 210 

    0x8e5fe562,// 249 PAY 211 

    0x8c0e7a23,// 250 PAY 212 

    0x92ccab53,// 251 PAY 213 

    0xfba7e22f,// 252 PAY 214 

    0x853e42b3,// 253 PAY 215 

    0x337629c8,// 254 PAY 216 

    0xa32c7b9c,// 255 PAY 217 

    0x35fe3f2d,// 256 PAY 218 

    0x75de84f7,// 257 PAY 219 

    0xb1a72434,// 258 PAY 220 

    0xb92d386f,// 259 PAY 221 

    0xfc1464e2,// 260 PAY 222 

    0xc9b65cd2,// 261 PAY 223 

    0x63f67ffe,// 262 PAY 224 

    0xd5d062f1,// 263 PAY 225 

    0xe1407637,// 264 PAY 226 

    0xd40c425d,// 265 PAY 227 

    0x1c4b4eb5,// 266 PAY 228 

    0xead67b1a,// 267 PAY 229 

    0xef894876,// 268 PAY 230 

    0xb21cd9b7,// 269 PAY 231 

    0xa866cf4f,// 270 PAY 232 

    0x865e492a,// 271 PAY 233 

    0x76f43217,// 272 PAY 234 

    0x95a166c7,// 273 PAY 235 

    0xbf2d0857,// 274 PAY 236 

    0x322dbde8,// 275 PAY 237 

    0xa6ed40fc,// 276 PAY 238 

    0x8d80ceba,// 277 PAY 239 

    0xe854054c,// 278 PAY 240 

    0x065006ef,// 279 PAY 241 

    0x41e2c8da,// 280 PAY 242 

    0x322e29a1,// 281 PAY 243 

    0x5e6d4023,// 282 PAY 244 

    0x0ec30138,// 283 PAY 245 

    0xc0ecc060,// 284 PAY 246 

    0x397b81d6,// 285 PAY 247 

    0x5dbb8d86,// 286 PAY 248 

    0xa8307f8d,// 287 PAY 249 

    0x2e43d5f2,// 288 PAY 250 

    0xe948ff56,// 289 PAY 251 

    0x3d25cfbc,// 290 PAY 252 

    0x2866ce4e,// 291 PAY 253 

    0x2c6c548a,// 292 PAY 254 

    0x5ed2f1f7,// 293 PAY 255 

    0x385b5ca4,// 294 PAY 256 

    0x87390876,// 295 PAY 257 

    0x3fe3a84e,// 296 PAY 258 

    0x428e9a0a,// 297 PAY 259 

    0x0d4a5a70,// 298 PAY 260 

    0x19a37de9,// 299 PAY 261 

    0x454a42ef,// 300 PAY 262 

    0x0fb731bc,// 301 PAY 263 

    0x1e62f615,// 302 PAY 264 

    0x93cb1566,// 303 PAY 265 

    0x244d479f,// 304 PAY 266 

    0x71de816a,// 305 PAY 267 

    0x81b06390,// 306 PAY 268 

    0xf71a120f,// 307 PAY 269 

    0x9b6b639e,// 308 PAY 270 

    0xff99173c,// 309 PAY 271 

    0x8327dee4,// 310 PAY 272 

    0xdc128d5f,// 311 PAY 273 

    0xbe09214f,// 312 PAY 274 

    0x510848ed,// 313 PAY 275 

    0x18ee20bf,// 314 PAY 276 

    0x1ec2bab0,// 315 PAY 277 

    0x95d27e9c,// 316 PAY 278 

    0x5d4df88d,// 317 PAY 279 

    0xc541c6b6,// 318 PAY 280 

    0x9c60811a,// 319 PAY 281 

    0x36fa9437,// 320 PAY 282 

    0xf7fce42f,// 321 PAY 283 

    0xe0cfeef2,// 322 PAY 284 

    0x352f3776,// 323 PAY 285 

    0x363170a0,// 324 PAY 286 

    0x661cad59,// 325 PAY 287 

    0x335573e4,// 326 PAY 288 

    0x07081d0d,// 327 PAY 289 

    0x77aa9b17,// 328 PAY 290 

    0xeade5aac,// 329 PAY 291 

    0x998893b0,// 330 PAY 292 

    0x73bdc1bf,// 331 PAY 293 

    0x0b7915d3,// 332 PAY 294 

    0xa9fbd295,// 333 PAY 295 

    0x8b266b4e,// 334 PAY 296 

    0xa19f8a5b,// 335 PAY 297 

    0x12fb3b38,// 336 PAY 298 

    0x2ea45ce2,// 337 PAY 299 

    0xefd7b3ae,// 338 PAY 300 

    0x393e88f0,// 339 PAY 301 

    0xd611d55c,// 340 PAY 302 

    0x58117c49,// 341 PAY 303 

    0x76c2e291,// 342 PAY 304 

    0x7ebf4a04,// 343 PAY 305 

    0x81f5e824,// 344 PAY 306 

    0xfa4c03d3,// 345 PAY 307 

    0x6d5b5c1a,// 346 PAY 308 

    0xbe0bb936,// 347 PAY 309 

    0x617332de,// 348 PAY 310 

    0x1a5bf546,// 349 PAY 311 

    0xc540c3af,// 350 PAY 312 

    0xa352547c,// 351 PAY 313 

    0x7b7e599f,// 352 PAY 314 

    0xd0e49f9e,// 353 PAY 315 

    0x6691aa75,// 354 PAY 316 

    0xff3c0f08,// 355 PAY 317 

    0x8ef11cce,// 356 PAY 318 

    0xc89de928,// 357 PAY 319 

    0x5556f9f5,// 358 PAY 320 

    0x2a6697aa,// 359 PAY 321 

    0xa92d91a4,// 360 PAY 322 

    0xf0bd919f,// 361 PAY 323 

    0xb46dda6a,// 362 PAY 324 

    0x3613ca0e,// 363 PAY 325 

    0x84d81a01,// 364 PAY 326 

    0xee3ad55e,// 365 PAY 327 

    0x59337953,// 366 PAY 328 

    0x382346e2,// 367 PAY 329 

    0x19112783,// 368 PAY 330 

    0xe9c57b04,// 369 PAY 331 

    0xfe0c603f,// 370 PAY 332 

    0x849b0bcf,// 371 PAY 333 

    0xc5fbde3c,// 372 PAY 334 

    0x550eb7b4,// 373 PAY 335 

    0x5e0e8faf,// 374 PAY 336 

    0x7b02df0e,// 375 PAY 337 

    0x491496a7,// 376 PAY 338 

    0xf0da445d,// 377 PAY 339 

    0xf7ba2066,// 378 PAY 340 

    0xe145a31d,// 379 PAY 341 

    0x02db19e0,// 380 PAY 342 

    0x7c316baa,// 381 PAY 343 

    0xbe14d815,// 382 PAY 344 

    0x61e5f84a,// 383 PAY 345 

    0x0deabcf7,// 384 PAY 346 

    0x2c5545df,// 385 PAY 347 

    0xf6fd771c,// 386 PAY 348 

    0x5ec99562,// 387 PAY 349 

    0x73b178f8,// 388 PAY 350 

    0xaf448ec5,// 389 PAY 351 

    0x6bf01503,// 390 PAY 352 

    0xf02c5462,// 391 PAY 353 

    0x19733cca,// 392 PAY 354 

    0xc2e84d71,// 393 PAY 355 

    0x4e015165,// 394 PAY 356 

    0xae608a64,// 395 PAY 357 

    0x046b6bdc,// 396 PAY 358 

    0x03eca4a0,// 397 PAY 359 

    0xbc01920e,// 398 PAY 360 

    0x51e696e8,// 399 PAY 361 

    0x07bcac02,// 400 PAY 362 

    0x313e4714,// 401 PAY 363 

    0xfbd824aa,// 402 PAY 364 

    0x32b14adf,// 403 PAY 365 

    0x52be061e,// 404 PAY 366 

    0x2d41272b,// 405 PAY 367 

    0xcd57b6a4,// 406 PAY 368 

    0x97094558,// 407 PAY 369 

    0xb9d6a156,// 408 PAY 370 

    0x60909b34,// 409 PAY 371 

    0xfac89954,// 410 PAY 372 

    0x9a807624,// 411 PAY 373 

    0x53041191,// 412 PAY 374 

    0xdf004a14,// 413 PAY 375 

    0x5f4b5fd6,// 414 PAY 376 

    0xfa3868dd,// 415 PAY 377 

    0xf707879c,// 416 PAY 378 

    0xdbce37f5,// 417 PAY 379 

    0x75c67f28,// 418 PAY 380 

    0x1adb3ceb,// 419 PAY 381 

    0xa399d93c,// 420 PAY 382 

    0xee16131e,// 421 PAY 383 

    0x159b5d66,// 422 PAY 384 

    0x963dd9ad,// 423 PAY 385 

    0x5c4c73af,// 424 PAY 386 

    0x8864f8ab,// 425 PAY 387 

    0xb1b3b2c7,// 426 PAY 388 

    0xc6c887f8,// 427 PAY 389 

    0x30a2c6ce,// 428 PAY 390 

    0x3c3c7bf6,// 429 PAY 391 

    0x22b60f10,// 430 PAY 392 

    0xe603f780,// 431 PAY 393 

    0x51863e3b,// 432 PAY 394 

    0xe8d19e1f,// 433 PAY 395 

    0x4a000000,// 434 PAY 396 

/// STA is 1 words. 

/// STA num_pkts       : 83 

/// STA pkt_idx        : 218 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x25 

    0x03682553 // 435 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt64_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000015,// 3 SCX   1 

    0x8085288e,// 4 SCX   2 

    0x000013c4,// 5 SCX   3 

    0x53cf3309,// 6 SCX   4 

    0xd0dcac2e,// 7 SCX   5 

    0xfc2db1ef,// 8 SCX   6 

    0x0adf8e5a,// 9 SCX   7 

    0x00ed556a,// 10 SCX   8 

    0xcd71d5f2,// 11 SCX   9 

    0x969c7faf,// 12 SCX  10 

    0xadf116df,// 13 SCX  11 

    0x3becb9c0,// 14 SCX  12 

    0x891ea087,// 15 SCX  13 

    0x499d27d2,// 16 SCX  14 

    0x87394112,// 17 SCX  15 

    0x32b24415,// 18 SCX  16 

    0x10038b4d,// 19 SCX  17 

    0xf51bb58e,// 20 SCX  18 

    0x34bb40c3,// 21 SCX  19 

    0xa941b843,// 22 SCX  20 

    0x1de08f02,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1192 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 853 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 853 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 660 

/// BFD (ofst+len)cry  : 676 

/// BFD ofstiv         : 268 

/// BFD ofsticv        : 1092 

    0x00000355,// 24 BFD   1 

    0x02940010,// 25 BFD   2 

    0x0444010c,// 26 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c009d82,// 27 MFM   1 

    0xfc984c1e,// 28 MFM   2 

    0x9b6b3efe,// 29 MFM   3 

    0x5e77f6a7,// 30 MFM   4 

    0x16f8a9d9,// 31 MFM   5 

    0x22cd6445,// 32 MFM   6 

    0x8b9cc068,// 33 MFM   7 

    0xef4bd6b4,// 34 MFM   8 

    0x0d1ce0f4,// 35 MFM   9 

    0xfbfc376e,// 36 MFM  10 

    0xac2f85ac,// 37 MFM  11 

    0xf5c1bc32,// 38 MFM  12 

    0xb39499a0,// 39 MFM  13 

    0xdfd7cfbd,// 40 MFM  14 

    0x51ff8f01,// 41 MFM  15 

    0x98b9addf,// 42 MFM  16 

/// BDA is 299 words. 

/// BDA size     is 1192 (0x4a8) 

/// BDA id       is 0x770a 

    0x04a8770a,// 43 BDA   1 

/// PAY Generic Data size   : 1192 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x33998e14,// 44 PAY   1 

    0x1f0897e1,// 45 PAY   2 

    0x078821e5,// 46 PAY   3 

    0xaebdc1bc,// 47 PAY   4 

    0x9ae378f2,// 48 PAY   5 

    0xc5b292aa,// 49 PAY   6 

    0xd5641f41,// 50 PAY   7 

    0xc1b4a822,// 51 PAY   8 

    0x231f3f02,// 52 PAY   9 

    0x1c0d6abc,// 53 PAY  10 

    0x56fdd043,// 54 PAY  11 

    0x1fac8bb7,// 55 PAY  12 

    0x14410302,// 56 PAY  13 

    0xc2a94fbe,// 57 PAY  14 

    0xd9b37e64,// 58 PAY  15 

    0xb87fa2ac,// 59 PAY  16 

    0xe2909a9c,// 60 PAY  17 

    0x51005c42,// 61 PAY  18 

    0x2b685b88,// 62 PAY  19 

    0x1e1fc261,// 63 PAY  20 

    0x9e8f0a77,// 64 PAY  21 

    0x02396858,// 65 PAY  22 

    0xfcfbafd1,// 66 PAY  23 

    0x62d68ec3,// 67 PAY  24 

    0x4452bcce,// 68 PAY  25 

    0x85d877c1,// 69 PAY  26 

    0xb7cd0e9a,// 70 PAY  27 

    0x4f2128c3,// 71 PAY  28 

    0xd7f0df3b,// 72 PAY  29 

    0x9cfe5c37,// 73 PAY  30 

    0x00296290,// 74 PAY  31 

    0x1b66a05f,// 75 PAY  32 

    0x358a7b5b,// 76 PAY  33 

    0xc37bb1d1,// 77 PAY  34 

    0x92a7f2ae,// 78 PAY  35 

    0x481a2345,// 79 PAY  36 

    0x5cce4970,// 80 PAY  37 

    0x728087c0,// 81 PAY  38 

    0x496f37bb,// 82 PAY  39 

    0xebf6a79c,// 83 PAY  40 

    0x743b0189,// 84 PAY  41 

    0x3203638d,// 85 PAY  42 

    0xb109173f,// 86 PAY  43 

    0xb2de2529,// 87 PAY  44 

    0x6538589d,// 88 PAY  45 

    0x32792dd8,// 89 PAY  46 

    0x261becdd,// 90 PAY  47 

    0x88b63b91,// 91 PAY  48 

    0xee07d1f3,// 92 PAY  49 

    0xbd82769a,// 93 PAY  50 

    0xc3c36afd,// 94 PAY  51 

    0xef3c2efc,// 95 PAY  52 

    0x44da342a,// 96 PAY  53 

    0x8f39640b,// 97 PAY  54 

    0x054a6833,// 98 PAY  55 

    0xda955570,// 99 PAY  56 

    0x4c161473,// 100 PAY  57 

    0xe804cc46,// 101 PAY  58 

    0x34f7b9dc,// 102 PAY  59 

    0x316b7868,// 103 PAY  60 

    0xe59f8e19,// 104 PAY  61 

    0x43b94440,// 105 PAY  62 

    0x8c5ace37,// 106 PAY  63 

    0x2a2c4270,// 107 PAY  64 

    0xa9e34013,// 108 PAY  65 

    0x6ff22d9a,// 109 PAY  66 

    0xccc8b33e,// 110 PAY  67 

    0x6af312d7,// 111 PAY  68 

    0x69f5c223,// 112 PAY  69 

    0xe9673f96,// 113 PAY  70 

    0xc765a5dc,// 114 PAY  71 

    0xfdbddf25,// 115 PAY  72 

    0x3a4a66e2,// 116 PAY  73 

    0xbfd9397f,// 117 PAY  74 

    0x6d04d6ed,// 118 PAY  75 

    0xee156db3,// 119 PAY  76 

    0xc6b3d068,// 120 PAY  77 

    0xf0586530,// 121 PAY  78 

    0x107d5ca5,// 122 PAY  79 

    0x350bed4c,// 123 PAY  80 

    0x9712c11d,// 124 PAY  81 

    0xf1933926,// 125 PAY  82 

    0x43d3391c,// 126 PAY  83 

    0x2874cdae,// 127 PAY  84 

    0x06fb1d5e,// 128 PAY  85 

    0x658dd663,// 129 PAY  86 

    0x12f18691,// 130 PAY  87 

    0xe1e83b96,// 131 PAY  88 

    0xac41b903,// 132 PAY  89 

    0xa634229f,// 133 PAY  90 

    0x9fc9ff1b,// 134 PAY  91 

    0x6ee412c3,// 135 PAY  92 

    0xd8ac86fd,// 136 PAY  93 

    0x13692168,// 137 PAY  94 

    0x7f7865e0,// 138 PAY  95 

    0xd6bd6e2a,// 139 PAY  96 

    0x500ccb23,// 140 PAY  97 

    0xa2f5eb38,// 141 PAY  98 

    0x9ce96c9f,// 142 PAY  99 

    0x36db1e76,// 143 PAY 100 

    0x301189a2,// 144 PAY 101 

    0x3c6bcc78,// 145 PAY 102 

    0x8da09311,// 146 PAY 103 

    0xd320dfdc,// 147 PAY 104 

    0x1948ee69,// 148 PAY 105 

    0xd4e8c936,// 149 PAY 106 

    0xba918cf6,// 150 PAY 107 

    0xd83f236f,// 151 PAY 108 

    0x720bbb66,// 152 PAY 109 

    0xc8f08686,// 153 PAY 110 

    0x40254c85,// 154 PAY 111 

    0xf60ed8e5,// 155 PAY 112 

    0x8dafbaea,// 156 PAY 113 

    0x056a0b9d,// 157 PAY 114 

    0xdb03feac,// 158 PAY 115 

    0x8fc113d4,// 159 PAY 116 

    0xb5966d3a,// 160 PAY 117 

    0xbdfdc0ff,// 161 PAY 118 

    0xace19ea0,// 162 PAY 119 

    0x5069d9bb,// 163 PAY 120 

    0xd05995db,// 164 PAY 121 

    0x126eff2d,// 165 PAY 122 

    0x2f97c239,// 166 PAY 123 

    0x752a1ee3,// 167 PAY 124 

    0xb1896c54,// 168 PAY 125 

    0x95fbd1d3,// 169 PAY 126 

    0x89f6d493,// 170 PAY 127 

    0x5ab83eec,// 171 PAY 128 

    0x86f48574,// 172 PAY 129 

    0xf0fe39ad,// 173 PAY 130 

    0x9c6c514b,// 174 PAY 131 

    0x5960b42e,// 175 PAY 132 

    0xc15ddc68,// 176 PAY 133 

    0x93d097cc,// 177 PAY 134 

    0x8c0a02f8,// 178 PAY 135 

    0x99a20910,// 179 PAY 136 

    0x95f6f49a,// 180 PAY 137 

    0x613c7fcf,// 181 PAY 138 

    0xd24368f1,// 182 PAY 139 

    0xd1b6112f,// 183 PAY 140 

    0x9dfcb027,// 184 PAY 141 

    0xbc8519bc,// 185 PAY 142 

    0xf2f3ab07,// 186 PAY 143 

    0xfc908edf,// 187 PAY 144 

    0xa472cf5c,// 188 PAY 145 

    0xeee49859,// 189 PAY 146 

    0xbfb8f865,// 190 PAY 147 

    0xc0362c5e,// 191 PAY 148 

    0xc08c0e90,// 192 PAY 149 

    0x8f738b53,// 193 PAY 150 

    0xfcdd7ee8,// 194 PAY 151 

    0x8a36879b,// 195 PAY 152 

    0x28de31da,// 196 PAY 153 

    0x1dbc9ef8,// 197 PAY 154 

    0x6a88ba7d,// 198 PAY 155 

    0xff3929a3,// 199 PAY 156 

    0xf2b4a4a4,// 200 PAY 157 

    0x39968a66,// 201 PAY 158 

    0x667c774e,// 202 PAY 159 

    0xbce425cf,// 203 PAY 160 

    0x19ee2e71,// 204 PAY 161 

    0x9d40b322,// 205 PAY 162 

    0x285f68a7,// 206 PAY 163 

    0xa368a411,// 207 PAY 164 

    0x71a4e664,// 208 PAY 165 

    0xc16330b1,// 209 PAY 166 

    0xf8f78e57,// 210 PAY 167 

    0xfc642299,// 211 PAY 168 

    0x4e9526dd,// 212 PAY 169 

    0x0562fbbc,// 213 PAY 170 

    0xb851cd93,// 214 PAY 171 

    0x94989f55,// 215 PAY 172 

    0xc1d0c72a,// 216 PAY 173 

    0x84114788,// 217 PAY 174 

    0xa1faa567,// 218 PAY 175 

    0x5d812d80,// 219 PAY 176 

    0xba78fbb0,// 220 PAY 177 

    0x3e938c2c,// 221 PAY 178 

    0x62aa1334,// 222 PAY 179 

    0xda850d93,// 223 PAY 180 

    0xab488022,// 224 PAY 181 

    0x73e3e90e,// 225 PAY 182 

    0x19d898ca,// 226 PAY 183 

    0xcf94c55c,// 227 PAY 184 

    0x9c7d7d7b,// 228 PAY 185 

    0x9998307f,// 229 PAY 186 

    0xfca893cd,// 230 PAY 187 

    0x575dc9d6,// 231 PAY 188 

    0xcd72645d,// 232 PAY 189 

    0x0d191124,// 233 PAY 190 

    0xf5ca1ce3,// 234 PAY 191 

    0xf996f2d0,// 235 PAY 192 

    0x3370df6d,// 236 PAY 193 

    0xf113b63e,// 237 PAY 194 

    0xee4ad4b8,// 238 PAY 195 

    0x8ac7ad07,// 239 PAY 196 

    0x50fff347,// 240 PAY 197 

    0x3cde91ec,// 241 PAY 198 

    0xac10a702,// 242 PAY 199 

    0xd73f3f54,// 243 PAY 200 

    0x9b66fc60,// 244 PAY 201 

    0xa5da83b9,// 245 PAY 202 

    0x58cdaab5,// 246 PAY 203 

    0x1b17cfba,// 247 PAY 204 

    0x6d6067ab,// 248 PAY 205 

    0xbb282136,// 249 PAY 206 

    0xf0187f3f,// 250 PAY 207 

    0x4b8db4cb,// 251 PAY 208 

    0x5e88c1ec,// 252 PAY 209 

    0xfe6c3ecc,// 253 PAY 210 

    0xaf3efef8,// 254 PAY 211 

    0x19d1a1e1,// 255 PAY 212 

    0x8c85173e,// 256 PAY 213 

    0xe4cd2c8c,// 257 PAY 214 

    0xebb746e9,// 258 PAY 215 

    0xbc2e7ca9,// 259 PAY 216 

    0xf4c7c123,// 260 PAY 217 

    0x5310d75c,// 261 PAY 218 

    0xc299c910,// 262 PAY 219 

    0x9c760877,// 263 PAY 220 

    0x862d8817,// 264 PAY 221 

    0xf3c50a50,// 265 PAY 222 

    0xac2845b4,// 266 PAY 223 

    0x5bb8c238,// 267 PAY 224 

    0x3bdfee3f,// 268 PAY 225 

    0x677a75ab,// 269 PAY 226 

    0x78a8c9b5,// 270 PAY 227 

    0x8de39588,// 271 PAY 228 

    0xa6a45847,// 272 PAY 229 

    0xce31358a,// 273 PAY 230 

    0x5662bf6a,// 274 PAY 231 

    0x5dff60bf,// 275 PAY 232 

    0x5e6c1d73,// 276 PAY 233 

    0x0976b9cb,// 277 PAY 234 

    0x725b7da1,// 278 PAY 235 

    0x9edf4407,// 279 PAY 236 

    0x3a183ece,// 280 PAY 237 

    0xcb4098a9,// 281 PAY 238 

    0xcdcd3137,// 282 PAY 239 

    0x11eb6029,// 283 PAY 240 

    0xf154bd00,// 284 PAY 241 

    0xf23392ee,// 285 PAY 242 

    0x22c08c3c,// 286 PAY 243 

    0xcdc6320f,// 287 PAY 244 

    0x04bd868a,// 288 PAY 245 

    0xb750ecdb,// 289 PAY 246 

    0x4b6086be,// 290 PAY 247 

    0xcc5e4f73,// 291 PAY 248 

    0xb2e9e0ab,// 292 PAY 249 

    0x1755aa9d,// 293 PAY 250 

    0x0ac6eaeb,// 294 PAY 251 

    0x94c3770b,// 295 PAY 252 

    0x86cb6e81,// 296 PAY 253 

    0xb8cd8e4f,// 297 PAY 254 

    0x719efe6c,// 298 PAY 255 

    0xa58cfe9b,// 299 PAY 256 

    0x04fd16fe,// 300 PAY 257 

    0xae28e062,// 301 PAY 258 

    0x80d1b8dc,// 302 PAY 259 

    0x7f2e3748,// 303 PAY 260 

    0xe2850d58,// 304 PAY 261 

    0x14dd0e3b,// 305 PAY 262 

    0xedd78376,// 306 PAY 263 

    0x13200c6c,// 307 PAY 264 

    0x8fae6e7e,// 308 PAY 265 

    0x8cf7c6d2,// 309 PAY 266 

    0xc2b7917b,// 310 PAY 267 

    0x3def94f5,// 311 PAY 268 

    0x64292426,// 312 PAY 269 

    0x69308a20,// 313 PAY 270 

    0xdbf5468a,// 314 PAY 271 

    0x11060698,// 315 PAY 272 

    0xbd98a504,// 316 PAY 273 

    0x1c5fd32a,// 317 PAY 274 

    0xf44d2bf7,// 318 PAY 275 

    0x5846b559,// 319 PAY 276 

    0xa3829d5f,// 320 PAY 277 

    0x7210f4ea,// 321 PAY 278 

    0xbbcd4b7f,// 322 PAY 279 

    0x921ec853,// 323 PAY 280 

    0xef599a2e,// 324 PAY 281 

    0xd8d32fc7,// 325 PAY 282 

    0x5c317332,// 326 PAY 283 

    0xdc0de57f,// 327 PAY 284 

    0x25589b45,// 328 PAY 285 

    0xe9408766,// 329 PAY 286 

    0xc538b8f5,// 330 PAY 287 

    0x643968e3,// 331 PAY 288 

    0x074dd7fe,// 332 PAY 289 

    0xbda0d605,// 333 PAY 290 

    0x951653e1,// 334 PAY 291 

    0xacfe4281,// 335 PAY 292 

    0x504095f8,// 336 PAY 293 

    0xcc2bf28e,// 337 PAY 294 

    0x807ad5d0,// 338 PAY 295 

    0x1f9ac667,// 339 PAY 296 

    0xc86dce25,// 340 PAY 297 

    0x546ce476,// 341 PAY 298 

/// STA is 1 words. 

/// STA num_pkts       : 51 

/// STA pkt_idx        : 131 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xbb 

    0x020cbb33 // 342 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt65_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x80842849,// 4 SCX   2 

    0x00006484,// 5 SCX   3 

    0x731418e4,// 6 SCX   4 

    0xbe789c27,// 7 SCX   5 

    0x5687e379,// 8 SCX   6 

    0x84b9ac39,// 9 SCX   7 

    0x04a025de,// 10 SCX   8 

    0xa4e1bc03,// 11 SCX   9 

    0x3cc09b36,// 12 SCX  10 

    0x0d16d831,// 13 SCX  11 

    0xa9ca4468,// 14 SCX  12 

    0x5ed019e3,// 15 SCX  13 

    0xa0108428,// 16 SCX  14 

    0x85948c7d,// 17 SCX  15 

    0x7d5c1585,// 18 SCX  16 

    0x38478736,// 19 SCX  17 

    0x89296c82,// 20 SCX  18 

    0xdaa41816,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1334 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1177 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1177 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 1112 

/// BFD (ofst+len)cry  : 1128 

/// BFD ofstiv         : 900 

/// BFD ofsticv        : 1296 

    0x00000499,// 22 BFD   1 

    0x04580010,// 23 BFD   2 

    0x05100384,// 24 BFD   3 

/// MFM is 6 words. 

/// MFM vldnibs        : 2c 

    0x2c00e2f9,// 25 MFM   1 

    0x908433d9,// 26 MFM   2 

    0x0b61f306,// 27 MFM   3 

    0x77c6b3fc,// 28 MFM   4 

    0x1d08bf12,// 29 MFM   5 

    0x222a34b4,// 30 MFM   6 

/// BDA is 335 words. 

/// BDA size     is 1334 (0x536) 

/// BDA id       is 0x5fa4 

    0x05365fa4,// 31 BDA   1 

/// PAY Generic Data size   : 1334 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xa0e82fab,// 32 PAY   1 

    0x0ee756b1,// 33 PAY   2 

    0x835b2fce,// 34 PAY   3 

    0x58dc28f5,// 35 PAY   4 

    0x1a04855f,// 36 PAY   5 

    0x2cfa9fe5,// 37 PAY   6 

    0x2acb638b,// 38 PAY   7 

    0xbab1dba4,// 39 PAY   8 

    0x7f62e4d8,// 40 PAY   9 

    0xe451be7a,// 41 PAY  10 

    0x5dc3cc21,// 42 PAY  11 

    0xd010032b,// 43 PAY  12 

    0xcc46a2cd,// 44 PAY  13 

    0xd1e62e69,// 45 PAY  14 

    0x8ce63fe1,// 46 PAY  15 

    0x2c691697,// 47 PAY  16 

    0x81566733,// 48 PAY  17 

    0x8d115d5e,// 49 PAY  18 

    0x39e127f0,// 50 PAY  19 

    0x1371654c,// 51 PAY  20 

    0x927e3a62,// 52 PAY  21 

    0x29763b23,// 53 PAY  22 

    0xe6729bfc,// 54 PAY  23 

    0x1baf540e,// 55 PAY  24 

    0xc882e604,// 56 PAY  25 

    0xdd45e98a,// 57 PAY  26 

    0x00b89cb4,// 58 PAY  27 

    0x67c55f97,// 59 PAY  28 

    0xcc827b6c,// 60 PAY  29 

    0xb49af594,// 61 PAY  30 

    0x20ddff48,// 62 PAY  31 

    0x3673d702,// 63 PAY  32 

    0x92ca917f,// 64 PAY  33 

    0xfe22320d,// 65 PAY  34 

    0xa3e6af44,// 66 PAY  35 

    0xfdd90ffe,// 67 PAY  36 

    0x80eda8f8,// 68 PAY  37 

    0x774d669b,// 69 PAY  38 

    0x58d42fe8,// 70 PAY  39 

    0x13eaf992,// 71 PAY  40 

    0x925096aa,// 72 PAY  41 

    0x453f900d,// 73 PAY  42 

    0x26fa0728,// 74 PAY  43 

    0x31ace57f,// 75 PAY  44 

    0xeae92119,// 76 PAY  45 

    0x56d12f8b,// 77 PAY  46 

    0x4e5dc674,// 78 PAY  47 

    0xa7bb57ba,// 79 PAY  48 

    0x36471244,// 80 PAY  49 

    0x1bfbdbec,// 81 PAY  50 

    0xb157d828,// 82 PAY  51 

    0xf3ca5a60,// 83 PAY  52 

    0x3057fd33,// 84 PAY  53 

    0x50180e66,// 85 PAY  54 

    0xbb53d57c,// 86 PAY  55 

    0x24ae5e80,// 87 PAY  56 

    0x9e3794e1,// 88 PAY  57 

    0x19fa65d0,// 89 PAY  58 

    0x3fef41fd,// 90 PAY  59 

    0xe217afb2,// 91 PAY  60 

    0x27efb570,// 92 PAY  61 

    0x2de9fe25,// 93 PAY  62 

    0x33aa55dc,// 94 PAY  63 

    0x6e2666b9,// 95 PAY  64 

    0xa5911ab3,// 96 PAY  65 

    0x6e2685d5,// 97 PAY  66 

    0x781efaed,// 98 PAY  67 

    0x9264db0d,// 99 PAY  68 

    0xd615e4de,// 100 PAY  69 

    0x487623bb,// 101 PAY  70 

    0x2a1fd7a2,// 102 PAY  71 

    0x9f902ab6,// 103 PAY  72 

    0x1666ac40,// 104 PAY  73 

    0x958204a5,// 105 PAY  74 

    0xf15d0151,// 106 PAY  75 

    0xc7a2cf44,// 107 PAY  76 

    0x51a5e481,// 108 PAY  77 

    0xc2c4a620,// 109 PAY  78 

    0xb66d68b6,// 110 PAY  79 

    0xfd4ab9c5,// 111 PAY  80 

    0xb1df317f,// 112 PAY  81 

    0x597e6f95,// 113 PAY  82 

    0x8ed55b82,// 114 PAY  83 

    0x83bf0530,// 115 PAY  84 

    0x5b07d7ac,// 116 PAY  85 

    0xc4ac7b5a,// 117 PAY  86 

    0x102c1a2f,// 118 PAY  87 

    0x317eca47,// 119 PAY  88 

    0x6ebec1c4,// 120 PAY  89 

    0xcdeae49c,// 121 PAY  90 

    0xe9379e5b,// 122 PAY  91 

    0xa5744c2f,// 123 PAY  92 

    0x9e866062,// 124 PAY  93 

    0x5abb80f7,// 125 PAY  94 

    0xc95a1666,// 126 PAY  95 

    0x8984a06a,// 127 PAY  96 

    0x0df22017,// 128 PAY  97 

    0x4f2da423,// 129 PAY  98 

    0x0b3b7be8,// 130 PAY  99 

    0x75f6d42e,// 131 PAY 100 

    0x6f0cb94d,// 132 PAY 101 

    0xf9b04fff,// 133 PAY 102 

    0x09c357e5,// 134 PAY 103 

    0x42a357c6,// 135 PAY 104 

    0xd69e9cd1,// 136 PAY 105 

    0x10b58799,// 137 PAY 106 

    0x39fa8472,// 138 PAY 107 

    0xd8be9594,// 139 PAY 108 

    0x09c2311e,// 140 PAY 109 

    0xb5932950,// 141 PAY 110 

    0xebc1b23f,// 142 PAY 111 

    0x67c72715,// 143 PAY 112 

    0xebf30681,// 144 PAY 113 

    0x1a19440d,// 145 PAY 114 

    0xdffac3d0,// 146 PAY 115 

    0xb8c3fad9,// 147 PAY 116 

    0x203f3341,// 148 PAY 117 

    0x26c8abac,// 149 PAY 118 

    0xbc17b327,// 150 PAY 119 

    0x5bacc12b,// 151 PAY 120 

    0xb5138e72,// 152 PAY 121 

    0x0b2ebbb3,// 153 PAY 122 

    0x9d2a08e3,// 154 PAY 123 

    0x7889a8ac,// 155 PAY 124 

    0x178152cb,// 156 PAY 125 

    0xa8a454aa,// 157 PAY 126 

    0x6e06ea3b,// 158 PAY 127 

    0x9957bb6e,// 159 PAY 128 

    0x54741b19,// 160 PAY 129 

    0x668985d6,// 161 PAY 130 

    0xc8001791,// 162 PAY 131 

    0x794403c4,// 163 PAY 132 

    0x725b1e39,// 164 PAY 133 

    0x4c3b0322,// 165 PAY 134 

    0xdaa953b8,// 166 PAY 135 

    0x981fad1e,// 167 PAY 136 

    0xecb36528,// 168 PAY 137 

    0xf0f3e034,// 169 PAY 138 

    0x13652866,// 170 PAY 139 

    0xc1b33731,// 171 PAY 140 

    0xd6adb163,// 172 PAY 141 

    0x75eca1ba,// 173 PAY 142 

    0xc0a31fe9,// 174 PAY 143 

    0x5a25d85a,// 175 PAY 144 

    0xe149c162,// 176 PAY 145 

    0x6ebe48bf,// 177 PAY 146 

    0xc2a4c04d,// 178 PAY 147 

    0xe886f340,// 179 PAY 148 

    0x3fc7641d,// 180 PAY 149 

    0xf0dc0282,// 181 PAY 150 

    0x0d411be4,// 182 PAY 151 

    0xa43fa97b,// 183 PAY 152 

    0xe0d1eec0,// 184 PAY 153 

    0xf296717a,// 185 PAY 154 

    0x65f2f24c,// 186 PAY 155 

    0xf8c26950,// 187 PAY 156 

    0x04ae87db,// 188 PAY 157 

    0x047f75e3,// 189 PAY 158 

    0x9416cb0c,// 190 PAY 159 

    0xe1de851b,// 191 PAY 160 

    0xc2733fa8,// 192 PAY 161 

    0xb33c7819,// 193 PAY 162 

    0x186a7b16,// 194 PAY 163 

    0x0ad993cd,// 195 PAY 164 

    0x7e5a5310,// 196 PAY 165 

    0x860e25eb,// 197 PAY 166 

    0x784f108b,// 198 PAY 167 

    0x9ce717d8,// 199 PAY 168 

    0x2fb8bf22,// 200 PAY 169 

    0x7f3794d9,// 201 PAY 170 

    0xb0a02aec,// 202 PAY 171 

    0x98b5a107,// 203 PAY 172 

    0x17eede20,// 204 PAY 173 

    0x39556c13,// 205 PAY 174 

    0x6cf73a9c,// 206 PAY 175 

    0x1cb33009,// 207 PAY 176 

    0xb36b2337,// 208 PAY 177 

    0x633550f1,// 209 PAY 178 

    0xd2cdbf6b,// 210 PAY 179 

    0xb62cd6f1,// 211 PAY 180 

    0xb52bca94,// 212 PAY 181 

    0xc2fa7277,// 213 PAY 182 

    0x7d685118,// 214 PAY 183 

    0xfdc77db7,// 215 PAY 184 

    0x0d697842,// 216 PAY 185 

    0x666066f0,// 217 PAY 186 

    0x2b166ff9,// 218 PAY 187 

    0x792596ba,// 219 PAY 188 

    0xc941b66b,// 220 PAY 189 

    0x59586393,// 221 PAY 190 

    0x52c8b417,// 222 PAY 191 

    0x8ae6d2c1,// 223 PAY 192 

    0x44aa6d88,// 224 PAY 193 

    0x2a3745e0,// 225 PAY 194 

    0x0ab5f4e1,// 226 PAY 195 

    0x300040f1,// 227 PAY 196 

    0xe5a1e34f,// 228 PAY 197 

    0x3964a54b,// 229 PAY 198 

    0x282b630a,// 230 PAY 199 

    0xd39ddc97,// 231 PAY 200 

    0xcea0b2af,// 232 PAY 201 

    0xf4aec525,// 233 PAY 202 

    0x8ff12767,// 234 PAY 203 

    0x30ced89f,// 235 PAY 204 

    0x9648745e,// 236 PAY 205 

    0x240f0d56,// 237 PAY 206 

    0x92f50597,// 238 PAY 207 

    0x6ba2d1a5,// 239 PAY 208 

    0x973739ff,// 240 PAY 209 

    0xcad24cba,// 241 PAY 210 

    0xc6aac81a,// 242 PAY 211 

    0xfa651065,// 243 PAY 212 

    0x824008f2,// 244 PAY 213 

    0x5af4ba8a,// 245 PAY 214 

    0xf86ca7de,// 246 PAY 215 

    0xbfe2b849,// 247 PAY 216 

    0xebcba6c3,// 248 PAY 217 

    0x3f1c530c,// 249 PAY 218 

    0xe6d7b8ed,// 250 PAY 219 

    0x44820cdf,// 251 PAY 220 

    0x082419ba,// 252 PAY 221 

    0x71b08d7e,// 253 PAY 222 

    0xafc2478a,// 254 PAY 223 

    0x60ec8482,// 255 PAY 224 

    0xe3947f28,// 256 PAY 225 

    0x0933f155,// 257 PAY 226 

    0x9f3f0a7a,// 258 PAY 227 

    0x660f5226,// 259 PAY 228 

    0x6cd26d2b,// 260 PAY 229 

    0x3ff158a8,// 261 PAY 230 

    0xe134f01d,// 262 PAY 231 

    0x51fd036b,// 263 PAY 232 

    0x803364d1,// 264 PAY 233 

    0xa0381744,// 265 PAY 234 

    0x96594988,// 266 PAY 235 

    0x0cead9c0,// 267 PAY 236 

    0x9f8f7033,// 268 PAY 237 

    0xa871c9bc,// 269 PAY 238 

    0x5655fc46,// 270 PAY 239 

    0x55cdbf54,// 271 PAY 240 

    0x5b2193fb,// 272 PAY 241 

    0xda924f83,// 273 PAY 242 

    0xff5fe806,// 274 PAY 243 

    0x010ce3b8,// 275 PAY 244 

    0x2f4e0d90,// 276 PAY 245 

    0x3050b54c,// 277 PAY 246 

    0xe5b7414e,// 278 PAY 247 

    0x75a39ec6,// 279 PAY 248 

    0xccfd1028,// 280 PAY 249 

    0xe324fdd8,// 281 PAY 250 

    0xbe925b09,// 282 PAY 251 

    0xb3356859,// 283 PAY 252 

    0x2981b477,// 284 PAY 253 

    0x712a3aa4,// 285 PAY 254 

    0x07394cfc,// 286 PAY 255 

    0x91aff1b3,// 287 PAY 256 

    0x3f4888cb,// 288 PAY 257 

    0x56403f25,// 289 PAY 258 

    0x9e92171e,// 290 PAY 259 

    0xefa85b9b,// 291 PAY 260 

    0x326fe355,// 292 PAY 261 

    0x6ceb6e20,// 293 PAY 262 

    0x778cb3e7,// 294 PAY 263 

    0xd36b9772,// 295 PAY 264 

    0x602891c6,// 296 PAY 265 

    0xc207658d,// 297 PAY 266 

    0x3d212ead,// 298 PAY 267 

    0xa7d619f2,// 299 PAY 268 

    0x2616e394,// 300 PAY 269 

    0xbfe7ad24,// 301 PAY 270 

    0x8e6d0bac,// 302 PAY 271 

    0x5d00317d,// 303 PAY 272 

    0x6f48a1f7,// 304 PAY 273 

    0xe2ce266b,// 305 PAY 274 

    0x4ff4a92b,// 306 PAY 275 

    0x1cfd7fd4,// 307 PAY 276 

    0xcb2cba90,// 308 PAY 277 

    0x4251e762,// 309 PAY 278 

    0x6f14bcb1,// 310 PAY 279 

    0x05e8f7e1,// 311 PAY 280 

    0x6af7a6a5,// 312 PAY 281 

    0x9fd0b7c2,// 313 PAY 282 

    0x899938d6,// 314 PAY 283 

    0x1f374566,// 315 PAY 284 

    0xcd5d78ef,// 316 PAY 285 

    0x1ad7c31a,// 317 PAY 286 

    0xefcafd26,// 318 PAY 287 

    0x4c8b7e68,// 319 PAY 288 

    0xa2c38a6a,// 320 PAY 289 

    0xa9a9ba39,// 321 PAY 290 

    0x964d0e83,// 322 PAY 291 

    0x7281077b,// 323 PAY 292 

    0x33a7509b,// 324 PAY 293 

    0xc187ca2a,// 325 PAY 294 

    0x531e7512,// 326 PAY 295 

    0x9510a407,// 327 PAY 296 

    0x626a7b3b,// 328 PAY 297 

    0xa9069a01,// 329 PAY 298 

    0xf0f01534,// 330 PAY 299 

    0x19841239,// 331 PAY 300 

    0x55af6c9e,// 332 PAY 301 

    0x0b1c1f67,// 333 PAY 302 

    0xd3af9e49,// 334 PAY 303 

    0x52e5f12f,// 335 PAY 304 

    0xf3f3c25c,// 336 PAY 305 

    0xf315d661,// 337 PAY 306 

    0xd1f168eb,// 338 PAY 307 

    0x48e3c554,// 339 PAY 308 

    0x774c698d,// 340 PAY 309 

    0x5b576c5f,// 341 PAY 310 

    0x93f0c9a2,// 342 PAY 311 

    0x59ee121c,// 343 PAY 312 

    0xbafaf42f,// 344 PAY 313 

    0xc13a386f,// 345 PAY 314 

    0xcbf81839,// 346 PAY 315 

    0x1202e478,// 347 PAY 316 

    0xe52ed787,// 348 PAY 317 

    0x5cd180cf,// 349 PAY 318 

    0xe7f4ff41,// 350 PAY 319 

    0x4afb77e7,// 351 PAY 320 

    0xfa6c750a,// 352 PAY 321 

    0x85e86d16,// 353 PAY 322 

    0xc3075d99,// 354 PAY 323 

    0xcfe904bd,// 355 PAY 324 

    0xff84d7c2,// 356 PAY 325 

    0xf9ef90a6,// 357 PAY 326 

    0x40c4edfc,// 358 PAY 327 

    0x184a7758,// 359 PAY 328 

    0x7bb99730,// 360 PAY 329 

    0x51d3bd5c,// 361 PAY 330 

    0x06709dc4,// 362 PAY 331 

    0x6f817624,// 363 PAY 332 

    0x92b0c597,// 364 PAY 333 

    0x23020000,// 365 PAY 334 

/// STA is 1 words. 

/// STA num_pkts       : 51 

/// STA pkt_idx        : 53 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x45 

    0x00d44533 // 366 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt66_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0000000f,// 3 SCX   1 

    0x8084281d,// 4 SCX   2 

    0x00004244,// 5 SCX   3 

    0xef266256,// 6 SCX   4 

    0xc35815aa,// 7 SCX   5 

    0x4d4da7cf,// 8 SCX   6 

    0xc283b0bb,// 9 SCX   7 

    0xd261a599,// 10 SCX   8 

    0x4a1eb3ec,// 11 SCX   9 

    0xb95f2f0f,// 12 SCX  10 

    0x9248f0cf,// 13 SCX  11 

    0xfcfb860e,// 14 SCX  12 

    0xdd010728,// 15 SCX  13 

    0x04558d6d,// 16 SCX  14 

    0xb2577588,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1143 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 365 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 365 

/// BFD lencrypto      : 160 

/// BFD ofstcrypto     : 116 

/// BFD (ofst+len)cry  : 276 

/// BFD ofstiv         : 12 

/// BFD ofsticv        : 980 

    0x0000016d,// 18 BFD   1 

    0x007400a0,// 19 BFD   2 

    0x03d4000c,// 20 BFD   3 

/// MFM is 7 words. 

/// MFM vldnibs        : 32 

    0x3200ec70,// 21 MFM   1 

    0xdba3895f,// 22 MFM   2 

    0x3df6f809,// 23 MFM   3 

    0x4eb99562,// 24 MFM   4 

    0xa6d8353e,// 25 MFM   5 

    0x91e2e261,// 26 MFM   6 

    0x83f45600,// 27 MFM   7 

/// BDA is 287 words. 

/// BDA size     is 1143 (0x477) 

/// BDA id       is 0xb717 

    0x0477b717,// 28 BDA   1 

/// PAY Generic Data size   : 1143 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x891ff451,// 29 PAY   1 

    0x1dccd13f,// 30 PAY   2 

    0x00eb2dd8,// 31 PAY   3 

    0x5ce548e0,// 32 PAY   4 

    0xb57fc470,// 33 PAY   5 

    0x1f5e45c0,// 34 PAY   6 

    0x0e3bd5b4,// 35 PAY   7 

    0x40f8c8c6,// 36 PAY   8 

    0x040b1128,// 37 PAY   9 

    0xd08ceee5,// 38 PAY  10 

    0x5ccb141d,// 39 PAY  11 

    0x6918058c,// 40 PAY  12 

    0x489f9869,// 41 PAY  13 

    0xe15f9111,// 42 PAY  14 

    0x63d8780c,// 43 PAY  15 

    0x8b7fe659,// 44 PAY  16 

    0xe614c8c6,// 45 PAY  17 

    0x0af6b299,// 46 PAY  18 

    0x649e241d,// 47 PAY  19 

    0x9c9e9a56,// 48 PAY  20 

    0xdfe47dc8,// 49 PAY  21 

    0xcab1e5bf,// 50 PAY  22 

    0xbe376eca,// 51 PAY  23 

    0x92f3d1c8,// 52 PAY  24 

    0x71f97929,// 53 PAY  25 

    0xdddfee3c,// 54 PAY  26 

    0x6d4e0042,// 55 PAY  27 

    0xdc0c1f71,// 56 PAY  28 

    0x9a679176,// 57 PAY  29 

    0xcc20271a,// 58 PAY  30 

    0x62c420a2,// 59 PAY  31 

    0xe74a8130,// 60 PAY  32 

    0xa81028fc,// 61 PAY  33 

    0x77cbf6b9,// 62 PAY  34 

    0x9523a769,// 63 PAY  35 

    0x68c48a8b,// 64 PAY  36 

    0x90ea7caa,// 65 PAY  37 

    0x5b994fa4,// 66 PAY  38 

    0x910913cd,// 67 PAY  39 

    0xe7a904a7,// 68 PAY  40 

    0xdeefcb1c,// 69 PAY  41 

    0x1dbace5a,// 70 PAY  42 

    0x0e9c9012,// 71 PAY  43 

    0xdae49074,// 72 PAY  44 

    0xe47a53e8,// 73 PAY  45 

    0x63d3b8ae,// 74 PAY  46 

    0x7ca4384f,// 75 PAY  47 

    0x7d24903c,// 76 PAY  48 

    0x6ddea5f2,// 77 PAY  49 

    0x3b537467,// 78 PAY  50 

    0xdc6c178f,// 79 PAY  51 

    0xfc42c770,// 80 PAY  52 

    0x5832a8b0,// 81 PAY  53 

    0x67ea221a,// 82 PAY  54 

    0x8b461915,// 83 PAY  55 

    0x85de4d9f,// 84 PAY  56 

    0x23361657,// 85 PAY  57 

    0x682f5c91,// 86 PAY  58 

    0x83d26aae,// 87 PAY  59 

    0xa28eaf70,// 88 PAY  60 

    0x1b4568c9,// 89 PAY  61 

    0xcde4ba85,// 90 PAY  62 

    0x3c281978,// 91 PAY  63 

    0x2293bbfe,// 92 PAY  64 

    0x1c3a2066,// 93 PAY  65 

    0xaa9a06d6,// 94 PAY  66 

    0x3d6621c0,// 95 PAY  67 

    0xf06d60a6,// 96 PAY  68 

    0x29f2efff,// 97 PAY  69 

    0x1796ae18,// 98 PAY  70 

    0xb698f1c5,// 99 PAY  71 

    0x476b57e8,// 100 PAY  72 

    0x14653fcd,// 101 PAY  73 

    0xb3dc58b7,// 102 PAY  74 

    0x9ac96ce3,// 103 PAY  75 

    0x629787a7,// 104 PAY  76 

    0xf66568f0,// 105 PAY  77 

    0xa83ed914,// 106 PAY  78 

    0x45a9295c,// 107 PAY  79 

    0x8e768f10,// 108 PAY  80 

    0x497a473e,// 109 PAY  81 

    0xfe485afc,// 110 PAY  82 

    0xa0e50bbd,// 111 PAY  83 

    0x835a00ee,// 112 PAY  84 

    0x4f0e864f,// 113 PAY  85 

    0x99366bdf,// 114 PAY  86 

    0x4026a268,// 115 PAY  87 

    0xc21b383a,// 116 PAY  88 

    0x09d5ba9e,// 117 PAY  89 

    0x620913b3,// 118 PAY  90 

    0xbf05dfe2,// 119 PAY  91 

    0x75c8f7ea,// 120 PAY  92 

    0x983d1394,// 121 PAY  93 

    0x6e32a371,// 122 PAY  94 

    0x5d08ba9a,// 123 PAY  95 

    0x12e528e3,// 124 PAY  96 

    0x9f881c2a,// 125 PAY  97 

    0xca0664f8,// 126 PAY  98 

    0x1297bf68,// 127 PAY  99 

    0xb62d3eb3,// 128 PAY 100 

    0xb7db6827,// 129 PAY 101 

    0x76622e61,// 130 PAY 102 

    0x19861dee,// 131 PAY 103 

    0x8c2476a4,// 132 PAY 104 

    0xe9243794,// 133 PAY 105 

    0x9d86996c,// 134 PAY 106 

    0xe64f0a2d,// 135 PAY 107 

    0x0a4eb5f6,// 136 PAY 108 

    0x092333b0,// 137 PAY 109 

    0x2f009ce8,// 138 PAY 110 

    0x38460f8b,// 139 PAY 111 

    0x0879f970,// 140 PAY 112 

    0x3d68f0dc,// 141 PAY 113 

    0x0d3b02a2,// 142 PAY 114 

    0x55821923,// 143 PAY 115 

    0x2dd04c03,// 144 PAY 116 

    0xc7047fc2,// 145 PAY 117 

    0x5f4b9858,// 146 PAY 118 

    0x3b1920c3,// 147 PAY 119 

    0x26497a2e,// 148 PAY 120 

    0x3686955a,// 149 PAY 121 

    0x6b54016e,// 150 PAY 122 

    0xeb395c38,// 151 PAY 123 

    0x82c30fdf,// 152 PAY 124 

    0xd2375ffc,// 153 PAY 125 

    0xf48292e3,// 154 PAY 126 

    0xf22d2879,// 155 PAY 127 

    0x8b344cbe,// 156 PAY 128 

    0x4fd3c65a,// 157 PAY 129 

    0xd1701901,// 158 PAY 130 

    0x6fa80643,// 159 PAY 131 

    0xcff59b85,// 160 PAY 132 

    0x86875480,// 161 PAY 133 

    0xdec83929,// 162 PAY 134 

    0x96a268d1,// 163 PAY 135 

    0xdecffb29,// 164 PAY 136 

    0x3f0383b8,// 165 PAY 137 

    0xb5cd0f78,// 166 PAY 138 

    0x8a46879c,// 167 PAY 139 

    0x4670c4d8,// 168 PAY 140 

    0x943020ce,// 169 PAY 141 

    0x6b6d49ff,// 170 PAY 142 

    0x2e22d337,// 171 PAY 143 

    0x68f079e8,// 172 PAY 144 

    0x346a862a,// 173 PAY 145 

    0xf72519fa,// 174 PAY 146 

    0x9f0403fd,// 175 PAY 147 

    0x0fba535e,// 176 PAY 148 

    0xdc84fb40,// 177 PAY 149 

    0x4dd6e941,// 178 PAY 150 

    0x04dc387a,// 179 PAY 151 

    0x2a7f1d26,// 180 PAY 152 

    0x97725893,// 181 PAY 153 

    0xc1462b0e,// 182 PAY 154 

    0xceab12d9,// 183 PAY 155 

    0x0f694a31,// 184 PAY 156 

    0xbbfdb928,// 185 PAY 157 

    0x30ea9923,// 186 PAY 158 

    0x8efaaab1,// 187 PAY 159 

    0x01fd9075,// 188 PAY 160 

    0x7ca7d515,// 189 PAY 161 

    0x27f9eef2,// 190 PAY 162 

    0x1c03a2c3,// 191 PAY 163 

    0x7aae0306,// 192 PAY 164 

    0xeb2564cb,// 193 PAY 165 

    0x7003ae1c,// 194 PAY 166 

    0xfa6ef326,// 195 PAY 167 

    0x54d61e10,// 196 PAY 168 

    0x068c4a02,// 197 PAY 169 

    0x3a247e40,// 198 PAY 170 

    0x377e480c,// 199 PAY 171 

    0x8a5e6c6d,// 200 PAY 172 

    0xb03e7582,// 201 PAY 173 

    0x96c74b4d,// 202 PAY 174 

    0xd1e957a5,// 203 PAY 175 

    0xfbd8e4a9,// 204 PAY 176 

    0xfc2ae8dd,// 205 PAY 177 

    0x0bc079da,// 206 PAY 178 

    0x2472bbfc,// 207 PAY 179 

    0x8a82ed06,// 208 PAY 180 

    0x957b7a86,// 209 PAY 181 

    0x87f1c1ba,// 210 PAY 182 

    0xf9740eae,// 211 PAY 183 

    0x09f019e2,// 212 PAY 184 

    0x1c4489d3,// 213 PAY 185 

    0x921dc9b5,// 214 PAY 186 

    0x9555b0ac,// 215 PAY 187 

    0x3dfda80d,// 216 PAY 188 

    0x5f1ddcdd,// 217 PAY 189 

    0x4f884715,// 218 PAY 190 

    0x2e10f957,// 219 PAY 191 

    0x1b395cc4,// 220 PAY 192 

    0x7a3f87cd,// 221 PAY 193 

    0xb7ed518d,// 222 PAY 194 

    0x44197a5f,// 223 PAY 195 

    0x1183e6d6,// 224 PAY 196 

    0x583ab47c,// 225 PAY 197 

    0xe69cbe72,// 226 PAY 198 

    0x0138bcef,// 227 PAY 199 

    0x265c9899,// 228 PAY 200 

    0xee63c8cd,// 229 PAY 201 

    0x3407d6d4,// 230 PAY 202 

    0x5418b4fb,// 231 PAY 203 

    0xd26e54f1,// 232 PAY 204 

    0xac78b100,// 233 PAY 205 

    0x039c1bfe,// 234 PAY 206 

    0x922220db,// 235 PAY 207 

    0x581fb251,// 236 PAY 208 

    0x12af1350,// 237 PAY 209 

    0xbd20f4a1,// 238 PAY 210 

    0xf2e880e7,// 239 PAY 211 

    0x37506ee5,// 240 PAY 212 

    0x289709f7,// 241 PAY 213 

    0x6bd1facf,// 242 PAY 214 

    0xec730964,// 243 PAY 215 

    0x81e5c739,// 244 PAY 216 

    0xed5332fa,// 245 PAY 217 

    0x59628768,// 246 PAY 218 

    0x2892f1f3,// 247 PAY 219 

    0x0379637a,// 248 PAY 220 

    0xe3e57aef,// 249 PAY 221 

    0xe3f2e90b,// 250 PAY 222 

    0xfaf48920,// 251 PAY 223 

    0xd1f2261e,// 252 PAY 224 

    0x8e06ac90,// 253 PAY 225 

    0xfbf3389c,// 254 PAY 226 

    0xa42b4931,// 255 PAY 227 

    0x41e27537,// 256 PAY 228 

    0x8f9f44b6,// 257 PAY 229 

    0x88d20462,// 258 PAY 230 

    0xcbe52eb8,// 259 PAY 231 

    0x3ea27e10,// 260 PAY 232 

    0x6d800fe2,// 261 PAY 233 

    0x0cdb4189,// 262 PAY 234 

    0xb6fe452b,// 263 PAY 235 

    0xe96f01a4,// 264 PAY 236 

    0x753cea35,// 265 PAY 237 

    0x6f7233ca,// 266 PAY 238 

    0xfa0ff0b9,// 267 PAY 239 

    0xc68f8e60,// 268 PAY 240 

    0xab24714b,// 269 PAY 241 

    0xa7dc0697,// 270 PAY 242 

    0xfe8380bf,// 271 PAY 243 

    0x92ba3580,// 272 PAY 244 

    0x85a4dd7a,// 273 PAY 245 

    0xe034bf47,// 274 PAY 246 

    0x53b38429,// 275 PAY 247 

    0x859f18aa,// 276 PAY 248 

    0xdf8f9244,// 277 PAY 249 

    0x0681ab79,// 278 PAY 250 

    0xafca0efd,// 279 PAY 251 

    0x892c3568,// 280 PAY 252 

    0xa97f9da7,// 281 PAY 253 

    0x31afbd38,// 282 PAY 254 

    0x6560220c,// 283 PAY 255 

    0xf67191ea,// 284 PAY 256 

    0xd8f1778e,// 285 PAY 257 

    0x4354704f,// 286 PAY 258 

    0xff8886b4,// 287 PAY 259 

    0xc687062b,// 288 PAY 260 

    0xb0167870,// 289 PAY 261 

    0x71ee1fef,// 290 PAY 262 

    0xb9311fde,// 291 PAY 263 

    0x05699bda,// 292 PAY 264 

    0x3c7ebb60,// 293 PAY 265 

    0xaed44c3c,// 294 PAY 266 

    0xadb8a9ea,// 295 PAY 267 

    0x69fd67a0,// 296 PAY 268 

    0x68a89e63,// 297 PAY 269 

    0x2525c0ab,// 298 PAY 270 

    0xa87026ef,// 299 PAY 271 

    0xd2b87c8e,// 300 PAY 272 

    0xf0adc41a,// 301 PAY 273 

    0x9890b1d0,// 302 PAY 274 

    0x40cfd156,// 303 PAY 275 

    0xd9205982,// 304 PAY 276 

    0x228553f2,// 305 PAY 277 

    0x89b70d46,// 306 PAY 278 

    0xd724fae6,// 307 PAY 279 

    0xfdc91c07,// 308 PAY 280 

    0xf9d7021b,// 309 PAY 281 

    0xeb154e50,// 310 PAY 282 

    0x22d167a9,// 311 PAY 283 

    0xc7a73220,// 312 PAY 284 

    0x7492d5d6,// 313 PAY 285 

    0xa2aa9e00,// 314 PAY 286 

/// STA is 1 words. 

/// STA num_pkts       : 91 

/// STA pkt_idx        : 122 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x83 

    0x01e8835b // 315 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt67_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x09 

/// ECH pdu_tag        : 0x00 

    0x00090000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x8085280a,// 4 SCX   2 

    0x000041c4,// 5 SCX   3 

    0xa4bedec3,// 6 SCX   4 

    0xbf1a2ed5,// 7 SCX   5 

    0x29f4e898,// 8 SCX   6 

    0x1b418350,// 9 SCX   7 

    0x047343ba,// 10 SCX   8 

    0x4cb14b5a,// 11 SCX   9 

    0x4a3f9ea4,// 12 SCX  10 

    0x138befcd,// 13 SCX  11 

    0x360f846d,// 14 SCX  12 

    0xe5b47dbb,// 15 SCX  13 

    0x179dfed2,// 16 SCX  14 

    0x86954276,// 17 SCX  15 

    0xd4726524,// 18 SCX  16 

    0xf4c32e9e,// 19 SCX  17 

    0x244a0e0d,// 20 SCX  18 

    0x2402bdfe,// 21 SCX  19 

    0x7773feca,// 22 SCX  20 

    0xbd620155,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 836 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 782 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 782 

/// BFD lencrypto      : 640 

/// BFD ofstcrypto     : 124 

/// BFD (ofst+len)cry  : 764 

/// BFD ofstiv         : 64 

/// BFD ofsticv        : 800 

    0x0000030e,// 24 BFD   1 

    0x007c0280,// 25 BFD   2 

    0x03200040,// 26 BFD   3 

/// MFM is 10 words. 

/// MFM vldnibs        : 49 

    0x490004cf,// 27 MFM   1 

    0x47372d27,// 28 MFM   2 

    0x0c8301c0,// 29 MFM   3 

    0x0678dbda,// 30 MFM   4 

    0x34a228a2,// 31 MFM   5 

    0x32c5a01d,// 32 MFM   6 

    0xbdcce3e3,// 33 MFM   7 

    0x59f550f2,// 34 MFM   8 

    0xbf8b4b52,// 35 MFM   9 

    0xe6a5c000,// 36 MFM  10 

/// BDA is 210 words. 

/// BDA size     is 836 (0x344) 

/// BDA id       is 0xa522 

    0x0344a522,// 37 BDA   1 

/// PAY Generic Data size   : 836 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xfdc0b64a,// 38 PAY   1 

    0x48e46671,// 39 PAY   2 

    0x9a756873,// 40 PAY   3 

    0x3f226706,// 41 PAY   4 

    0x96463d9c,// 42 PAY   5 

    0x6646e824,// 43 PAY   6 

    0xaccfaf32,// 44 PAY   7 

    0xcd52728a,// 45 PAY   8 

    0x83da1991,// 46 PAY   9 

    0x7ef8d782,// 47 PAY  10 

    0xf71c9f37,// 48 PAY  11 

    0x0dee2f88,// 49 PAY  12 

    0x91dc4dfa,// 50 PAY  13 

    0x2815d9a5,// 51 PAY  14 

    0x57af7747,// 52 PAY  15 

    0xd0a8b854,// 53 PAY  16 

    0xf6634ace,// 54 PAY  17 

    0xaccc4e69,// 55 PAY  18 

    0x718c79c1,// 56 PAY  19 

    0xf7122a2b,// 57 PAY  20 

    0xffa2d6f5,// 58 PAY  21 

    0xcda60460,// 59 PAY  22 

    0x36ab0586,// 60 PAY  23 

    0x5d2b5dc5,// 61 PAY  24 

    0xf2d24118,// 62 PAY  25 

    0xaec89d14,// 63 PAY  26 

    0x089f889d,// 64 PAY  27 

    0x83bfc958,// 65 PAY  28 

    0x64a85ad4,// 66 PAY  29 

    0x7e005193,// 67 PAY  30 

    0x53f0f671,// 68 PAY  31 

    0xfc96fd4b,// 69 PAY  32 

    0xe6955f85,// 70 PAY  33 

    0xcdfd3869,// 71 PAY  34 

    0x47a79760,// 72 PAY  35 

    0x6142e404,// 73 PAY  36 

    0x169b2f3a,// 74 PAY  37 

    0x68dee077,// 75 PAY  38 

    0x78e5c866,// 76 PAY  39 

    0x93051d99,// 77 PAY  40 

    0x0dada100,// 78 PAY  41 

    0x25ec54b7,// 79 PAY  42 

    0x9f172f2b,// 80 PAY  43 

    0xc04fc595,// 81 PAY  44 

    0xde549692,// 82 PAY  45 

    0x081684a3,// 83 PAY  46 

    0xf178031c,// 84 PAY  47 

    0xaaffe24a,// 85 PAY  48 

    0xf0a44a91,// 86 PAY  49 

    0x091e6b4c,// 87 PAY  50 

    0x37c4491e,// 88 PAY  51 

    0x2ee4e7cd,// 89 PAY  52 

    0x549f482e,// 90 PAY  53 

    0xe1f39ff0,// 91 PAY  54 

    0xeaf9580b,// 92 PAY  55 

    0xe851c74f,// 93 PAY  56 

    0x438d22f5,// 94 PAY  57 

    0x85b78b21,// 95 PAY  58 

    0x4bfd2ede,// 96 PAY  59 

    0xf6efb062,// 97 PAY  60 

    0x9b69cbf2,// 98 PAY  61 

    0x2b660df3,// 99 PAY  62 

    0xffccfc6c,// 100 PAY  63 

    0x4adfb436,// 101 PAY  64 

    0xf1bad00f,// 102 PAY  65 

    0x1a737f3d,// 103 PAY  66 

    0xef5e7467,// 104 PAY  67 

    0xfdb1431f,// 105 PAY  68 

    0x05819e05,// 106 PAY  69 

    0xd50af7fd,// 107 PAY  70 

    0x94353c39,// 108 PAY  71 

    0xb0de679b,// 109 PAY  72 

    0xb0b08654,// 110 PAY  73 

    0x77e9653b,// 111 PAY  74 

    0xc5e055e9,// 112 PAY  75 

    0x9417d2d7,// 113 PAY  76 

    0x103587f8,// 114 PAY  77 

    0xe1822ac8,// 115 PAY  78 

    0x4e6be9da,// 116 PAY  79 

    0x1eed482e,// 117 PAY  80 

    0x662635ca,// 118 PAY  81 

    0xca8d1221,// 119 PAY  82 

    0xc75c5004,// 120 PAY  83 

    0xf1610e24,// 121 PAY  84 

    0xe7e68f9a,// 122 PAY  85 

    0x931a6da3,// 123 PAY  86 

    0x2053d35b,// 124 PAY  87 

    0xab1fbdae,// 125 PAY  88 

    0x8086f4ea,// 126 PAY  89 

    0xd217a2b9,// 127 PAY  90 

    0x3021694b,// 128 PAY  91 

    0x14236822,// 129 PAY  92 

    0xe82d973b,// 130 PAY  93 

    0x6e872829,// 131 PAY  94 

    0xa5bbcd83,// 132 PAY  95 

    0xe7cb4b5d,// 133 PAY  96 

    0xc3827774,// 134 PAY  97 

    0x771379fc,// 135 PAY  98 

    0xb6bce98b,// 136 PAY  99 

    0xb889f482,// 137 PAY 100 

    0x34af09f1,// 138 PAY 101 

    0x9a95f0f7,// 139 PAY 102 

    0x53a9a141,// 140 PAY 103 

    0x1e9b463c,// 141 PAY 104 

    0xceafb290,// 142 PAY 105 

    0x98bab251,// 143 PAY 106 

    0x073e4f13,// 144 PAY 107 

    0xf26b826a,// 145 PAY 108 

    0x4f62cbed,// 146 PAY 109 

    0xf5946952,// 147 PAY 110 

    0xf60e8f36,// 148 PAY 111 

    0x6f204dc3,// 149 PAY 112 

    0x8bf4ead9,// 150 PAY 113 

    0x1382efcc,// 151 PAY 114 

    0xa0a333f6,// 152 PAY 115 

    0xdf837316,// 153 PAY 116 

    0x90827deb,// 154 PAY 117 

    0xc4a1e150,// 155 PAY 118 

    0x9888af46,// 156 PAY 119 

    0x6b95b551,// 157 PAY 120 

    0x5c677fef,// 158 PAY 121 

    0xa9e22b52,// 159 PAY 122 

    0x96ec74f8,// 160 PAY 123 

    0x102eca7a,// 161 PAY 124 

    0x71c05e5e,// 162 PAY 125 

    0xd43db10b,// 163 PAY 126 

    0xea3c5193,// 164 PAY 127 

    0x33e200fe,// 165 PAY 128 

    0x8e75568e,// 166 PAY 129 

    0x43272cf5,// 167 PAY 130 

    0xc22885dc,// 168 PAY 131 

    0x65e87638,// 169 PAY 132 

    0x73f4cb0d,// 170 PAY 133 

    0x8a8315b7,// 171 PAY 134 

    0x29a0e2f0,// 172 PAY 135 

    0xff757163,// 173 PAY 136 

    0x6b29e3e0,// 174 PAY 137 

    0x21389773,// 175 PAY 138 

    0x22be34ee,// 176 PAY 139 

    0x0da04c0b,// 177 PAY 140 

    0x80fff7da,// 178 PAY 141 

    0x029aae7a,// 179 PAY 142 

    0xf8d66b8a,// 180 PAY 143 

    0x4c29c76a,// 181 PAY 144 

    0x602865ce,// 182 PAY 145 

    0x1552dddc,// 183 PAY 146 

    0xad9388ee,// 184 PAY 147 

    0x23f20a1e,// 185 PAY 148 

    0x1c0316de,// 186 PAY 149 

    0x7e2e7faa,// 187 PAY 150 

    0x56bd733c,// 188 PAY 151 

    0x1ea455b0,// 189 PAY 152 

    0x373678b1,// 190 PAY 153 

    0xe722009c,// 191 PAY 154 

    0xd8cb9da1,// 192 PAY 155 

    0x42090b72,// 193 PAY 156 

    0x7782c272,// 194 PAY 157 

    0xb0ac31fb,// 195 PAY 158 

    0xc97658ea,// 196 PAY 159 

    0xc6e398c9,// 197 PAY 160 

    0x5c3891e4,// 198 PAY 161 

    0x7a5e24b5,// 199 PAY 162 

    0x6d1ac348,// 200 PAY 163 

    0xdabca297,// 201 PAY 164 

    0xb26c4850,// 202 PAY 165 

    0x1e4506e8,// 203 PAY 166 

    0xa1b5407e,// 204 PAY 167 

    0x80c9483f,// 205 PAY 168 

    0x585faf75,// 206 PAY 169 

    0xd92dc667,// 207 PAY 170 

    0xa2990909,// 208 PAY 171 

    0x25c6725c,// 209 PAY 172 

    0xb6efdef3,// 210 PAY 173 

    0x7c936b71,// 211 PAY 174 

    0x81fabc0e,// 212 PAY 175 

    0x8d898fe9,// 213 PAY 176 

    0x7b9f0894,// 214 PAY 177 

    0x60691dae,// 215 PAY 178 

    0xe80b287a,// 216 PAY 179 

    0xa942f746,// 217 PAY 180 

    0xe747ab54,// 218 PAY 181 

    0x435d2b26,// 219 PAY 182 

    0x83fe8aef,// 220 PAY 183 

    0x88b14b12,// 221 PAY 184 

    0x227e0ee2,// 222 PAY 185 

    0xf183a8e9,// 223 PAY 186 

    0xf55561e9,// 224 PAY 187 

    0x5ca2e5d9,// 225 PAY 188 

    0x8b74642c,// 226 PAY 189 

    0x8c4ac380,// 227 PAY 190 

    0x35d200a1,// 228 PAY 191 

    0xc45fe56c,// 229 PAY 192 

    0x3a42abf8,// 230 PAY 193 

    0xabd54c2c,// 231 PAY 194 

    0xf6eedbd4,// 232 PAY 195 

    0xf381e49e,// 233 PAY 196 

    0x6f48ffdc,// 234 PAY 197 

    0xe6af1306,// 235 PAY 198 

    0xdf2757a9,// 236 PAY 199 

    0xe6ea34a0,// 237 PAY 200 

    0x547811bc,// 238 PAY 201 

    0x01b5b26e,// 239 PAY 202 

    0x9417a3ed,// 240 PAY 203 

    0x3f6ddca7,// 241 PAY 204 

    0xceebe4bc,// 242 PAY 205 

    0x0abd1143,// 243 PAY 206 

    0x498bdf2e,// 244 PAY 207 

    0xee88c387,// 245 PAY 208 

    0x08958878,// 246 PAY 209 

/// STA is 1 words. 

/// STA num_pkts       : 221 

/// STA pkt_idx        : 35 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xd4 

    0x008cd4dd // 247 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt68_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x80862898,// 4 SCX   2 

    0x00004444,// 5 SCX   3 

    0xac8e21cd,// 6 SCX   4 

    0x907a5f71,// 7 SCX   5 

    0x60473ae8,// 8 SCX   6 

    0xd06b1320,// 9 SCX   7 

    0xf0933ac6,// 10 SCX   8 

    0x59b95d57,// 11 SCX   9 

    0x9d715c46,// 12 SCX  10 

    0xb5dd6839,// 13 SCX  11 

    0x6b03534e,// 14 SCX  12 

    0x7acf2baf,// 15 SCX  13 

    0x3de64a8e,// 16 SCX  14 

    0x2aa9a18b,// 17 SCX  15 

    0x1bd3bfba,// 18 SCX  16 

    0xf725afdf,// 19 SCX  17 

    0x73ed1d77,// 20 SCX  18 

    0x08230f0b,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1764 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1426 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1426 

/// BFD lencrypto      : 800 

/// BFD ofstcrypto     : 108 

/// BFD (ofst+len)cry  : 908 

/// BFD ofstiv         : 28 

/// BFD ofsticv        : 1712 

    0x00000592,// 22 BFD   1 

    0x006c0320,// 23 BFD   2 

    0x06b0001c,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00e534,// 25 MFM   1 

    0xefccef14,// 26 MFM   2 

    0x327b9cba,// 27 MFM   3 

    0xd4f95a28,// 28 MFM   4 

    0xb605565c,// 29 MFM   5 

    0xfe4e9ae3,// 30 MFM   6 

    0xbfb72f69,// 31 MFM   7 

    0xb62a1a2e,// 32 MFM   8 

    0x961877e4,// 33 MFM   9 

    0x22fe1ce2,// 34 MFM  10 

    0x83da98b3,// 35 MFM  11 

    0xf52a87fb,// 36 MFM  12 

    0xaa2e0f92,// 37 MFM  13 

    0xcd13f89c,// 38 MFM  14 

    0xac25d42e,// 39 MFM  15 

    0xbdf83960,// 40 MFM  16 

/// BDA is 442 words. 

/// BDA size     is 1764 (0x6e4) 

/// BDA id       is 0x7985 

    0x06e47985,// 41 BDA   1 

/// PAY Generic Data size   : 1764 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0xab9c76e4,// 42 PAY   1 

    0x6ee5c515,// 43 PAY   2 

    0x6c0f189b,// 44 PAY   3 

    0x3dd95da6,// 45 PAY   4 

    0x10efeb9e,// 46 PAY   5 

    0xe7dc8714,// 47 PAY   6 

    0x4ead266a,// 48 PAY   7 

    0xefe6a91d,// 49 PAY   8 

    0xb10e491c,// 50 PAY   9 

    0xa2e77a0a,// 51 PAY  10 

    0x39621cad,// 52 PAY  11 

    0x827a27b1,// 53 PAY  12 

    0xc1d2d890,// 54 PAY  13 

    0x569d287b,// 55 PAY  14 

    0x24946941,// 56 PAY  15 

    0x4c28dc92,// 57 PAY  16 

    0x695b2cb2,// 58 PAY  17 

    0xd1383203,// 59 PAY  18 

    0x12b0d9a5,// 60 PAY  19 

    0xfb135f1f,// 61 PAY  20 

    0x7781165a,// 62 PAY  21 

    0x4c9a01cc,// 63 PAY  22 

    0x65ef27b0,// 64 PAY  23 

    0x65fdedc2,// 65 PAY  24 

    0x9901f36c,// 66 PAY  25 

    0x867864aa,// 67 PAY  26 

    0x9eb6fc14,// 68 PAY  27 

    0x78edacfc,// 69 PAY  28 

    0x5bbe09db,// 70 PAY  29 

    0xeb36dbcb,// 71 PAY  30 

    0xeb76a8ec,// 72 PAY  31 

    0x0ac81e6c,// 73 PAY  32 

    0xc5d690c7,// 74 PAY  33 

    0xacf56ced,// 75 PAY  34 

    0x5c6013fb,// 76 PAY  35 

    0x62f3f3d0,// 77 PAY  36 

    0x4f044ac4,// 78 PAY  37 

    0xf3d86103,// 79 PAY  38 

    0x955e8e01,// 80 PAY  39 

    0xb9c29bf7,// 81 PAY  40 

    0x58797db5,// 82 PAY  41 

    0x9ded7eac,// 83 PAY  42 

    0x86544829,// 84 PAY  43 

    0x2345618d,// 85 PAY  44 

    0xe42d8223,// 86 PAY  45 

    0x858c8403,// 87 PAY  46 

    0x943f4695,// 88 PAY  47 

    0x81ed0aca,// 89 PAY  48 

    0xd9bc6bc9,// 90 PAY  49 

    0xc275fe07,// 91 PAY  50 

    0x9b1e75c1,// 92 PAY  51 

    0x77573d77,// 93 PAY  52 

    0xfd583df1,// 94 PAY  53 

    0x137e3484,// 95 PAY  54 

    0xba0a5555,// 96 PAY  55 

    0x624d8252,// 97 PAY  56 

    0x2b910f00,// 98 PAY  57 

    0xc8b66161,// 99 PAY  58 

    0x9738c567,// 100 PAY  59 

    0x21466e5c,// 101 PAY  60 

    0xa4c22b4c,// 102 PAY  61 

    0xe70d9efb,// 103 PAY  62 

    0x41ede6e0,// 104 PAY  63 

    0x0142b678,// 105 PAY  64 

    0x2b175a22,// 106 PAY  65 

    0xb40ebc9b,// 107 PAY  66 

    0x71003289,// 108 PAY  67 

    0x0adc8eed,// 109 PAY  68 

    0x34af8a26,// 110 PAY  69 

    0x6bcdeb2a,// 111 PAY  70 

    0x7957986f,// 112 PAY  71 

    0xc8df7596,// 113 PAY  72 

    0x8fb5fa3a,// 114 PAY  73 

    0x3c6c6efd,// 115 PAY  74 

    0x5cc4d5f5,// 116 PAY  75 

    0x96a40835,// 117 PAY  76 

    0x496cf4fa,// 118 PAY  77 

    0xcef7c1d9,// 119 PAY  78 

    0x87810428,// 120 PAY  79 

    0x5062dbc6,// 121 PAY  80 

    0x046baae0,// 122 PAY  81 

    0xdc3af348,// 123 PAY  82 

    0xcc42e59f,// 124 PAY  83 

    0x90f7189f,// 125 PAY  84 

    0xc1e8dd31,// 126 PAY  85 

    0x88fcc253,// 127 PAY  86 

    0xc628f2da,// 128 PAY  87 

    0x5a2481a5,// 129 PAY  88 

    0x71cdcd98,// 130 PAY  89 

    0xf1d67564,// 131 PAY  90 

    0xdc80e7f2,// 132 PAY  91 

    0x2744f2e4,// 133 PAY  92 

    0x71519d83,// 134 PAY  93 

    0x890b7f6d,// 135 PAY  94 

    0x790c8427,// 136 PAY  95 

    0xdac016cc,// 137 PAY  96 

    0x92a99257,// 138 PAY  97 

    0xd4fea111,// 139 PAY  98 

    0xc486a4a5,// 140 PAY  99 

    0xebafd754,// 141 PAY 100 

    0xecb418eb,// 142 PAY 101 

    0x092512f1,// 143 PAY 102 

    0x735af7b5,// 144 PAY 103 

    0xb9b18340,// 145 PAY 104 

    0x85f2aebf,// 146 PAY 105 

    0x5324b94c,// 147 PAY 106 

    0x049ba35a,// 148 PAY 107 

    0x788d45cb,// 149 PAY 108 

    0xe1c3d7f2,// 150 PAY 109 

    0x970c3337,// 151 PAY 110 

    0x1eb9138a,// 152 PAY 111 

    0x3ad86b11,// 153 PAY 112 

    0xb2df32b6,// 154 PAY 113 

    0xd05ee876,// 155 PAY 114 

    0x08bd0f16,// 156 PAY 115 

    0x94dbe9bb,// 157 PAY 116 

    0x3315a4e2,// 158 PAY 117 

    0xe8ba4cfb,// 159 PAY 118 

    0x19b4be1e,// 160 PAY 119 

    0x812ccb3b,// 161 PAY 120 

    0x6107288f,// 162 PAY 121 

    0x9133c550,// 163 PAY 122 

    0xc5b8fafa,// 164 PAY 123 

    0x3bbcfe36,// 165 PAY 124 

    0x1ea2bc3c,// 166 PAY 125 

    0x2c874342,// 167 PAY 126 

    0xb41503c1,// 168 PAY 127 

    0xb5e505e8,// 169 PAY 128 

    0x26361ac3,// 170 PAY 129 

    0x03413f37,// 171 PAY 130 

    0xd8b70b84,// 172 PAY 131 

    0xe7c1a18a,// 173 PAY 132 

    0xc4a8600d,// 174 PAY 133 

    0xc9aaf015,// 175 PAY 134 

    0xa34f0f9c,// 176 PAY 135 

    0x5ed4d6b0,// 177 PAY 136 

    0xfe2015e8,// 178 PAY 137 

    0x904904d2,// 179 PAY 138 

    0xd7a2ba5a,// 180 PAY 139 

    0x23f21ecb,// 181 PAY 140 

    0xc542d9a1,// 182 PAY 141 

    0x1ab6d71e,// 183 PAY 142 

    0xbda21175,// 184 PAY 143 

    0x31526d98,// 185 PAY 144 

    0x5ab8966e,// 186 PAY 145 

    0x6e23686e,// 187 PAY 146 

    0xe633ffe8,// 188 PAY 147 

    0x8bf159e0,// 189 PAY 148 

    0xad5d7d40,// 190 PAY 149 

    0x51d2ffce,// 191 PAY 150 

    0xa581320c,// 192 PAY 151 

    0x78fe80e2,// 193 PAY 152 

    0xb415aa90,// 194 PAY 153 

    0x1c3b77b3,// 195 PAY 154 

    0x31f44502,// 196 PAY 155 

    0x8832a95a,// 197 PAY 156 

    0xbbe25c64,// 198 PAY 157 

    0x837b2d99,// 199 PAY 158 

    0x03b723c3,// 200 PAY 159 

    0xd3b44c79,// 201 PAY 160 

    0xa9dba65d,// 202 PAY 161 

    0x424d7682,// 203 PAY 162 

    0x271ad61d,// 204 PAY 163 

    0x1221e6af,// 205 PAY 164 

    0x72ce812d,// 206 PAY 165 

    0xc7ab82cd,// 207 PAY 166 

    0xe7cad271,// 208 PAY 167 

    0x5a888ac6,// 209 PAY 168 

    0x7123ff72,// 210 PAY 169 

    0x0da48ca0,// 211 PAY 170 

    0x77c4ded5,// 212 PAY 171 

    0x4401ebfa,// 213 PAY 172 

    0x26535420,// 214 PAY 173 

    0xb78be89c,// 215 PAY 174 

    0xfdc26e55,// 216 PAY 175 

    0x50b81cf0,// 217 PAY 176 

    0x7dc88015,// 218 PAY 177 

    0xe2a77626,// 219 PAY 178 

    0xaed05a84,// 220 PAY 179 

    0x98e46903,// 221 PAY 180 

    0x87918b1e,// 222 PAY 181 

    0x32b58263,// 223 PAY 182 

    0xf627182c,// 224 PAY 183 

    0x4e195534,// 225 PAY 184 

    0xc61f768d,// 226 PAY 185 

    0xfbbc78eb,// 227 PAY 186 

    0xaedbd699,// 228 PAY 187 

    0x27f07c8d,// 229 PAY 188 

    0xb9a3c624,// 230 PAY 189 

    0x54d02560,// 231 PAY 190 

    0xaf39aff6,// 232 PAY 191 

    0xd722dd08,// 233 PAY 192 

    0xa69415e2,// 234 PAY 193 

    0x12b43ab1,// 235 PAY 194 

    0xb9029eb5,// 236 PAY 195 

    0x256f3c0c,// 237 PAY 196 

    0x453f83b6,// 238 PAY 197 

    0xfd71c75a,// 239 PAY 198 

    0x1b7f60e1,// 240 PAY 199 

    0xe7d7fd56,// 241 PAY 200 

    0xacb579e8,// 242 PAY 201 

    0x500f3972,// 243 PAY 202 

    0xf2512b58,// 244 PAY 203 

    0x92d363f4,// 245 PAY 204 

    0x405a6992,// 246 PAY 205 

    0x8cb02667,// 247 PAY 206 

    0x9d9baa64,// 248 PAY 207 

    0x570bea66,// 249 PAY 208 

    0x656b5bfc,// 250 PAY 209 

    0x36eb1f23,// 251 PAY 210 

    0xd627c115,// 252 PAY 211 

    0xf86e6ade,// 253 PAY 212 

    0x7a142753,// 254 PAY 213 

    0x74f68c1a,// 255 PAY 214 

    0x7c08fc9d,// 256 PAY 215 

    0x39e7bafe,// 257 PAY 216 

    0xe46f5714,// 258 PAY 217 

    0x5172b36d,// 259 PAY 218 

    0xdc131150,// 260 PAY 219 

    0xb492745b,// 261 PAY 220 

    0x23cc09e2,// 262 PAY 221 

    0x2f20ea78,// 263 PAY 222 

    0xf35ed001,// 264 PAY 223 

    0xb105291a,// 265 PAY 224 

    0xf4dd7690,// 266 PAY 225 

    0x8eb50ccd,// 267 PAY 226 

    0x28bfd813,// 268 PAY 227 

    0xefe7f4bb,// 269 PAY 228 

    0x0e7edd55,// 270 PAY 229 

    0x8009d8ed,// 271 PAY 230 

    0x9b088c61,// 272 PAY 231 

    0xe2159b98,// 273 PAY 232 

    0xeed88430,// 274 PAY 233 

    0x8b339fe1,// 275 PAY 234 

    0x639b32ea,// 276 PAY 235 

    0x71fee5e6,// 277 PAY 236 

    0x6d35f90d,// 278 PAY 237 

    0x342af5a5,// 279 PAY 238 

    0x1c8c6d52,// 280 PAY 239 

    0xc87dd239,// 281 PAY 240 

    0x8e8d4bb1,// 282 PAY 241 

    0x208836b0,// 283 PAY 242 

    0xb54d7afe,// 284 PAY 243 

    0x18d65053,// 285 PAY 244 

    0x03e9aee6,// 286 PAY 245 

    0x97598eda,// 287 PAY 246 

    0x9d702d6b,// 288 PAY 247 

    0x75371f90,// 289 PAY 248 

    0x43f7a8fd,// 290 PAY 249 

    0x84d94c40,// 291 PAY 250 

    0x9742fbea,// 292 PAY 251 

    0xbabb5725,// 293 PAY 252 

    0xe4e80abe,// 294 PAY 253 

    0xf7f2e871,// 295 PAY 254 

    0x6edbac50,// 296 PAY 255 

    0xbba7f86c,// 297 PAY 256 

    0x846c815a,// 298 PAY 257 

    0x61d79912,// 299 PAY 258 

    0xb7f98925,// 300 PAY 259 

    0xd10a8d64,// 301 PAY 260 

    0x502e7bf2,// 302 PAY 261 

    0xbdb5967f,// 303 PAY 262 

    0xbaadb147,// 304 PAY 263 

    0xcaa81349,// 305 PAY 264 

    0x3382eb84,// 306 PAY 265 

    0x10d14573,// 307 PAY 266 

    0xa1558c42,// 308 PAY 267 

    0x90f0e0a6,// 309 PAY 268 

    0xb1b0513f,// 310 PAY 269 

    0xbd4ef02b,// 311 PAY 270 

    0xeecb15d6,// 312 PAY 271 

    0x53cccbb2,// 313 PAY 272 

    0x1213de38,// 314 PAY 273 

    0xb5d3f8f4,// 315 PAY 274 

    0x9530499a,// 316 PAY 275 

    0xb83f7e27,// 317 PAY 276 

    0xbb52d86e,// 318 PAY 277 

    0x084b0295,// 319 PAY 278 

    0x0e22523e,// 320 PAY 279 

    0x3fc7f8dc,// 321 PAY 280 

    0x55d3a3de,// 322 PAY 281 

    0x63f29116,// 323 PAY 282 

    0x3767f3ac,// 324 PAY 283 

    0x1fe2d3d0,// 325 PAY 284 

    0x14f7a05a,// 326 PAY 285 

    0xb35d1c4e,// 327 PAY 286 

    0x90c04c7b,// 328 PAY 287 

    0x550fbac0,// 329 PAY 288 

    0x9ec983a6,// 330 PAY 289 

    0xe9341f9a,// 331 PAY 290 

    0x48e5fcbf,// 332 PAY 291 

    0xc784808d,// 333 PAY 292 

    0x58ad39bd,// 334 PAY 293 

    0x5c37a590,// 335 PAY 294 

    0xc28b6b3e,// 336 PAY 295 

    0x8175e897,// 337 PAY 296 

    0xc72330d2,// 338 PAY 297 

    0x480c3e2c,// 339 PAY 298 

    0x7b56e608,// 340 PAY 299 

    0x5f0f760a,// 341 PAY 300 

    0x3e29a181,// 342 PAY 301 

    0x0b6ea9c3,// 343 PAY 302 

    0x30d2fc2c,// 344 PAY 303 

    0x63392f72,// 345 PAY 304 

    0x4d868d74,// 346 PAY 305 

    0x7bfbb405,// 347 PAY 306 

    0x1c85f184,// 348 PAY 307 

    0xadf1180d,// 349 PAY 308 

    0x4dc09921,// 350 PAY 309 

    0x8fe3515e,// 351 PAY 310 

    0x3c97b5cd,// 352 PAY 311 

    0xfe7de79a,// 353 PAY 312 

    0x4d2dd0d4,// 354 PAY 313 

    0xa626bfa2,// 355 PAY 314 

    0x18a9442b,// 356 PAY 315 

    0xdb7809d1,// 357 PAY 316 

    0xdb9fb619,// 358 PAY 317 

    0xfc79c2f1,// 359 PAY 318 

    0x0d96622f,// 360 PAY 319 

    0x6926cdf8,// 361 PAY 320 

    0x1522f7fb,// 362 PAY 321 

    0x869966ef,// 363 PAY 322 

    0xadb3d940,// 364 PAY 323 

    0x80da5716,// 365 PAY 324 

    0x1937167a,// 366 PAY 325 

    0x62d6e10a,// 367 PAY 326 

    0xb55e574a,// 368 PAY 327 

    0xbc09c30c,// 369 PAY 328 

    0x2a1d079a,// 370 PAY 329 

    0x3e06e2aa,// 371 PAY 330 

    0xa3e92ebf,// 372 PAY 331 

    0x09f9da06,// 373 PAY 332 

    0x62c8ac4f,// 374 PAY 333 

    0x5540cd62,// 375 PAY 334 

    0x8647dca5,// 376 PAY 335 

    0xd8e1e8e2,// 377 PAY 336 

    0x186d0ca7,// 378 PAY 337 

    0xe67662aa,// 379 PAY 338 

    0xccab7d6f,// 380 PAY 339 

    0xf48bf12b,// 381 PAY 340 

    0xfbdca24d,// 382 PAY 341 

    0x12b7cdec,// 383 PAY 342 

    0x1bafddf2,// 384 PAY 343 

    0x3f46de0b,// 385 PAY 344 

    0xe85a3cb3,// 386 PAY 345 

    0x4812e1c3,// 387 PAY 346 

    0x0fdb476a,// 388 PAY 347 

    0x27bc447b,// 389 PAY 348 

    0xa0e446dd,// 390 PAY 349 

    0x3c7e8259,// 391 PAY 350 

    0x16cbed18,// 392 PAY 351 

    0xdb2b171e,// 393 PAY 352 

    0x175b765d,// 394 PAY 353 

    0xd56b8f39,// 395 PAY 354 

    0x822ab482,// 396 PAY 355 

    0xc2f58efb,// 397 PAY 356 

    0xc7d11716,// 398 PAY 357 

    0x626d9739,// 399 PAY 358 

    0x6074098b,// 400 PAY 359 

    0xa85c1758,// 401 PAY 360 

    0xe231a294,// 402 PAY 361 

    0x2edc088f,// 403 PAY 362 

    0xfc0068a6,// 404 PAY 363 

    0x40939411,// 405 PAY 364 

    0xf84c3f99,// 406 PAY 365 

    0xa3af96c4,// 407 PAY 366 

    0x6df24224,// 408 PAY 367 

    0x6c37fed2,// 409 PAY 368 

    0x3de39fa1,// 410 PAY 369 

    0xa7cba219,// 411 PAY 370 

    0x9d34bf76,// 412 PAY 371 

    0xe2e8428f,// 413 PAY 372 

    0x1e6991b2,// 414 PAY 373 

    0xa8092cf9,// 415 PAY 374 

    0x2a15cbaf,// 416 PAY 375 

    0xe4aec899,// 417 PAY 376 

    0x667434af,// 418 PAY 377 

    0xc052efef,// 419 PAY 378 

    0x8a10ed3c,// 420 PAY 379 

    0x405d23ea,// 421 PAY 380 

    0xca19a5ef,// 422 PAY 381 

    0x9c7e9fe1,// 423 PAY 382 

    0x0d092e4c,// 424 PAY 383 

    0x8f44845e,// 425 PAY 384 

    0x6a3223b3,// 426 PAY 385 

    0x6b2b3497,// 427 PAY 386 

    0x8cb947ed,// 428 PAY 387 

    0x8be40ca5,// 429 PAY 388 

    0x5f531346,// 430 PAY 389 

    0x0391e257,// 431 PAY 390 

    0x145d3034,// 432 PAY 391 

    0xa7e3b420,// 433 PAY 392 

    0x26b0514e,// 434 PAY 393 

    0xf3a63d6c,// 435 PAY 394 

    0x22f18208,// 436 PAY 395 

    0xe2ce0835,// 437 PAY 396 

    0x95eccb2f,// 438 PAY 397 

    0x7c82364f,// 439 PAY 398 

    0xf57fe107,// 440 PAY 399 

    0x8ddd1f35,// 441 PAY 400 

    0x9af74a17,// 442 PAY 401 

    0x40d98854,// 443 PAY 402 

    0x93baa022,// 444 PAY 403 

    0xd889c15a,// 445 PAY 404 

    0x381898fc,// 446 PAY 405 

    0xab8c72c7,// 447 PAY 406 

    0x22e0f06c,// 448 PAY 407 

    0xefa68f50,// 449 PAY 408 

    0x159c4632,// 450 PAY 409 

    0xf1149571,// 451 PAY 410 

    0x2a17d39f,// 452 PAY 411 

    0xa6b19785,// 453 PAY 412 

    0x537bb3d4,// 454 PAY 413 

    0x5582d983,// 455 PAY 414 

    0x52921999,// 456 PAY 415 

    0x705ca01f,// 457 PAY 416 

    0xc4df5b02,// 458 PAY 417 

    0x7eb02e24,// 459 PAY 418 

    0xcd76d848,// 460 PAY 419 

    0x63801ee4,// 461 PAY 420 

    0x35f2ed30,// 462 PAY 421 

    0x6bc4804e,// 463 PAY 422 

    0xd16a3c7c,// 464 PAY 423 

    0x3f01b1c6,// 465 PAY 424 

    0xd7c41b18,// 466 PAY 425 

    0xa79a2569,// 467 PAY 426 

    0x869eedba,// 468 PAY 427 

    0x49a2581b,// 469 PAY 428 

    0xfcf7cbec,// 470 PAY 429 

    0x60f11111,// 471 PAY 430 

    0x94279226,// 472 PAY 431 

    0x7c24dc2b,// 473 PAY 432 

    0x59066568,// 474 PAY 433 

    0x7bfe764e,// 475 PAY 434 

    0xdbdc9669,// 476 PAY 435 

    0xdc9bec84,// 477 PAY 436 

    0xaebde1f9,// 478 PAY 437 

    0x182a2923,// 479 PAY 438 

    0xc4aa871e,// 480 PAY 439 

    0xb7c19f41,// 481 PAY 440 

    0xf983cd05,// 482 PAY 441 

/// STA is 1 words. 

/// STA num_pkts       : 198 

/// STA pkt_idx        : 217 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x9d 

    0x03659dc6 // 483 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt69_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x808128ec,// 4 SCX   2 

    0x00001400,// 5 SCX   3 

    0xcc0b5b25,// 6 SCX   4 

    0x35c0a106,// 7 SCX   5 

    0xee227593,// 8 SCX   6 

    0x644efeb0,// 9 SCX   7 

    0xa335a13e,// 10 SCX   8 

    0x06f4b276,// 11 SCX   9 

    0x728cf091,// 12 SCX  10 

    0x5f1a122e,// 13 SCX  11 

    0x45a8e699,// 14 SCX  12 

    0x76258abd,// 15 SCX  13 

    0x9a367729,// 16 SCX  14 

    0x50f73d9d,// 17 SCX  15 

    0x0bc24397,// 18 SCX  16 

    0xc2406e7b,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 1418 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 996 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 996 

/// BFD lencrypto      : 608 

/// BFD ofstcrypto     : 376 

/// BFD (ofst+len)cry  : 984 

/// BFD ofstiv         : 156 

/// BFD ofsticv        : 1040 

    0x000003e4,// 20 BFD   1 

    0x01780260,// 21 BFD   2 

    0x0410009c,// 22 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00c77e,// 23 MFM   1 

    0x7328bc47,// 24 MFM   2 

    0xc0eb16ce,// 25 MFM   3 

    0x0ca58bec,// 26 MFM   4 

    0xd4d5e55d,// 27 MFM   5 

    0x68628b06,// 28 MFM   6 

    0xd0e0fc42,// 29 MFM   7 

    0xc495dce6,// 30 MFM   8 

    0x374fe876,// 31 MFM   9 

    0x0854bb8e,// 32 MFM  10 

    0x057b2c1e,// 33 MFM  11 

    0xbbab5925,// 34 MFM  12 

    0xf8709818,// 35 MFM  13 

    0x284c09fe,// 36 MFM  14 

    0x37f55aa7,// 37 MFM  15 

    0x9afab575,// 38 MFM  16 

/// BDA is 356 words. 

/// BDA size     is 1418 (0x58a) 

/// BDA id       is 0xe834 

    0x058ae834,// 39 BDA   1 

/// PAY Generic Data size   : 1418 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xad39d576,// 40 PAY   1 

    0x2ba32eb4,// 41 PAY   2 

    0xcc6c2e47,// 42 PAY   3 

    0x14bd3cba,// 43 PAY   4 

    0x54b96361,// 44 PAY   5 

    0x3a752034,// 45 PAY   6 

    0x33113da8,// 46 PAY   7 

    0xa762a940,// 47 PAY   8 

    0x749acbfd,// 48 PAY   9 

    0x530b692a,// 49 PAY  10 

    0x4ee7f3ac,// 50 PAY  11 

    0x1874be4b,// 51 PAY  12 

    0xeef707c4,// 52 PAY  13 

    0xd18805c4,// 53 PAY  14 

    0x704f37c9,// 54 PAY  15 

    0xbe9f8239,// 55 PAY  16 

    0xa274de69,// 56 PAY  17 

    0xde2cf815,// 57 PAY  18 

    0xc820dbb7,// 58 PAY  19 

    0xccd9218a,// 59 PAY  20 

    0x3479fee1,// 60 PAY  21 

    0x65c96c53,// 61 PAY  22 

    0x7ee4f61c,// 62 PAY  23 

    0x1aee5a43,// 63 PAY  24 

    0x40d2339b,// 64 PAY  25 

    0xec2138ab,// 65 PAY  26 

    0x1e15d88a,// 66 PAY  27 

    0xbd0451ea,// 67 PAY  28 

    0xf3591772,// 68 PAY  29 

    0xb0af5e50,// 69 PAY  30 

    0xc444b9b0,// 70 PAY  31 

    0xe82c9792,// 71 PAY  32 

    0x2640cb83,// 72 PAY  33 

    0x5962fdae,// 73 PAY  34 

    0x522b808a,// 74 PAY  35 

    0xa644817e,// 75 PAY  36 

    0xa18dcc98,// 76 PAY  37 

    0xa937bdec,// 77 PAY  38 

    0xc8286f31,// 78 PAY  39 

    0xa4bad90e,// 79 PAY  40 

    0xdd2e6dfd,// 80 PAY  41 

    0x7fc34559,// 81 PAY  42 

    0x2b25b987,// 82 PAY  43 

    0xf23a293d,// 83 PAY  44 

    0x6883e9f6,// 84 PAY  45 

    0x55347cec,// 85 PAY  46 

    0xb9f0aa40,// 86 PAY  47 

    0x76a3fd25,// 87 PAY  48 

    0x9078f8bb,// 88 PAY  49 

    0x309c1acb,// 89 PAY  50 

    0xa123c846,// 90 PAY  51 

    0xe7684e70,// 91 PAY  52 

    0x4b816463,// 92 PAY  53 

    0x9e6fb298,// 93 PAY  54 

    0x9a5ae00f,// 94 PAY  55 

    0xa0d68f8d,// 95 PAY  56 

    0x8e4fb3f9,// 96 PAY  57 

    0x2e6e2323,// 97 PAY  58 

    0x55b33936,// 98 PAY  59 

    0xda1cadf4,// 99 PAY  60 

    0x6db92f67,// 100 PAY  61 

    0xd90d58f2,// 101 PAY  62 

    0xc75b481b,// 102 PAY  63 

    0x01989762,// 103 PAY  64 

    0xff8ee550,// 104 PAY  65 

    0xf2b0e915,// 105 PAY  66 

    0x81a56f2c,// 106 PAY  67 

    0x563c957b,// 107 PAY  68 

    0x1b7473d6,// 108 PAY  69 

    0xae261eaf,// 109 PAY  70 

    0x06d34850,// 110 PAY  71 

    0xe631444d,// 111 PAY  72 

    0x71626495,// 112 PAY  73 

    0x443caf2b,// 113 PAY  74 

    0xbd243e5c,// 114 PAY  75 

    0xeb5cd118,// 115 PAY  76 

    0xcb16489f,// 116 PAY  77 

    0xb90fb308,// 117 PAY  78 

    0x0a9a3de6,// 118 PAY  79 

    0x89802e61,// 119 PAY  80 

    0x00ce4393,// 120 PAY  81 

    0xa47abe2e,// 121 PAY  82 

    0x7fe68ac8,// 122 PAY  83 

    0xa4bf4ca5,// 123 PAY  84 

    0x0297b083,// 124 PAY  85 

    0xbe43aaa9,// 125 PAY  86 

    0x14beab49,// 126 PAY  87 

    0xbfdeab60,// 127 PAY  88 

    0xcd44bf54,// 128 PAY  89 

    0x940b9c32,// 129 PAY  90 

    0xbe4ae85f,// 130 PAY  91 

    0x49042303,// 131 PAY  92 

    0x4fbcc4fc,// 132 PAY  93 

    0x99ccdcc1,// 133 PAY  94 

    0xdafc0ebd,// 134 PAY  95 

    0x267b0dc3,// 135 PAY  96 

    0x2d778ef8,// 136 PAY  97 

    0x077e6a56,// 137 PAY  98 

    0x41292df2,// 138 PAY  99 

    0x163ded0f,// 139 PAY 100 

    0x2cfdd337,// 140 PAY 101 

    0x4bed399d,// 141 PAY 102 

    0x9e43efb7,// 142 PAY 103 

    0x6fe46a33,// 143 PAY 104 

    0x541f04be,// 144 PAY 105 

    0x270ecde3,// 145 PAY 106 

    0xf46c74eb,// 146 PAY 107 

    0x3c3690b6,// 147 PAY 108 

    0xe537f273,// 148 PAY 109 

    0xde7352f4,// 149 PAY 110 

    0x150283d2,// 150 PAY 111 

    0xc8e388db,// 151 PAY 112 

    0x89bc742d,// 152 PAY 113 

    0xd1c8ee0f,// 153 PAY 114 

    0x4d69c767,// 154 PAY 115 

    0x30ed7ce4,// 155 PAY 116 

    0x8aae5fee,// 156 PAY 117 

    0x39c6a9e4,// 157 PAY 118 

    0x6a290b9d,// 158 PAY 119 

    0x88083293,// 159 PAY 120 

    0x206f4a5e,// 160 PAY 121 

    0xd062ad15,// 161 PAY 122 

    0x5b8e86c7,// 162 PAY 123 

    0xa22cf6a6,// 163 PAY 124 

    0xbc79feec,// 164 PAY 125 

    0x6ba862fb,// 165 PAY 126 

    0xd4879304,// 166 PAY 127 

    0xe822b471,// 167 PAY 128 

    0x36533d0a,// 168 PAY 129 

    0x4eba110f,// 169 PAY 130 

    0xb0d2e9a8,// 170 PAY 131 

    0xba58f1fc,// 171 PAY 132 

    0xd6c734a9,// 172 PAY 133 

    0xb85764a3,// 173 PAY 134 

    0x061fd90f,// 174 PAY 135 

    0x8d722883,// 175 PAY 136 

    0x7bf7231a,// 176 PAY 137 

    0x5f74f3c5,// 177 PAY 138 

    0xffb3b8e9,// 178 PAY 139 

    0x880602cf,// 179 PAY 140 

    0x160efdb2,// 180 PAY 141 

    0xa8021ee8,// 181 PAY 142 

    0x0d9c314a,// 182 PAY 143 

    0xf6af037c,// 183 PAY 144 

    0x3dc7df2c,// 184 PAY 145 

    0xe29ce73b,// 185 PAY 146 

    0xfc9983d1,// 186 PAY 147 

    0xe4856a8e,// 187 PAY 148 

    0xe6cc6a82,// 188 PAY 149 

    0x3a5bafc8,// 189 PAY 150 

    0x64b15e73,// 190 PAY 151 

    0x809ab733,// 191 PAY 152 

    0x96870400,// 192 PAY 153 

    0x34b15922,// 193 PAY 154 

    0xeb53dc66,// 194 PAY 155 

    0x51d1021e,// 195 PAY 156 

    0x3a15b578,// 196 PAY 157 

    0xe9b439fb,// 197 PAY 158 

    0x01b4045e,// 198 PAY 159 

    0x9e31c306,// 199 PAY 160 

    0x4f45d038,// 200 PAY 161 

    0x27bf753e,// 201 PAY 162 

    0xa2c6d4ce,// 202 PAY 163 

    0x42b800a1,// 203 PAY 164 

    0xa9b61765,// 204 PAY 165 

    0xdc6b5097,// 205 PAY 166 

    0xbe377b83,// 206 PAY 167 

    0xa9514c96,// 207 PAY 168 

    0xbde5f0d4,// 208 PAY 169 

    0xdef28c25,// 209 PAY 170 

    0x0245d157,// 210 PAY 171 

    0x7a659383,// 211 PAY 172 

    0x23aaba24,// 212 PAY 173 

    0xafc99d3f,// 213 PAY 174 

    0x8130ce76,// 214 PAY 175 

    0xdede3478,// 215 PAY 176 

    0x074a3333,// 216 PAY 177 

    0x00d978c5,// 217 PAY 178 

    0xc2c972ab,// 218 PAY 179 

    0xb5904496,// 219 PAY 180 

    0x1a8ecb87,// 220 PAY 181 

    0x2409d8a4,// 221 PAY 182 

    0x4ae22b59,// 222 PAY 183 

    0x51e68c3e,// 223 PAY 184 

    0x3d6a1ad7,// 224 PAY 185 

    0x897346ac,// 225 PAY 186 

    0xc0a4d956,// 226 PAY 187 

    0x9118675a,// 227 PAY 188 

    0x162cdab2,// 228 PAY 189 

    0xb1a340d5,// 229 PAY 190 

    0xf3121d88,// 230 PAY 191 

    0x5ec41edd,// 231 PAY 192 

    0xc2ce9cea,// 232 PAY 193 

    0x9e8e5b1b,// 233 PAY 194 

    0xc19d2b2d,// 234 PAY 195 

    0x85d44029,// 235 PAY 196 

    0xe3a38523,// 236 PAY 197 

    0x76c5bc58,// 237 PAY 198 

    0x2090b6bc,// 238 PAY 199 

    0x0df97220,// 239 PAY 200 

    0x2fd6109f,// 240 PAY 201 

    0xe28dae96,// 241 PAY 202 

    0x1dc8f0a2,// 242 PAY 203 

    0x740367ac,// 243 PAY 204 

    0xe71902cd,// 244 PAY 205 

    0x569269f8,// 245 PAY 206 

    0x6fb9f004,// 246 PAY 207 

    0xbfb9aa58,// 247 PAY 208 

    0x28d93574,// 248 PAY 209 

    0x72c5b0d9,// 249 PAY 210 

    0xd8ca3dde,// 250 PAY 211 

    0x4f9ef45c,// 251 PAY 212 

    0x10b81d9f,// 252 PAY 213 

    0x726accfc,// 253 PAY 214 

    0xd891fe94,// 254 PAY 215 

    0x139f9f0f,// 255 PAY 216 

    0x36549110,// 256 PAY 217 

    0x6530bbfc,// 257 PAY 218 

    0x12c38ba3,// 258 PAY 219 

    0x1c7c4b70,// 259 PAY 220 

    0x038d276f,// 260 PAY 221 

    0x9ade4d7f,// 261 PAY 222 

    0x59f84f5c,// 262 PAY 223 

    0x5a3fce95,// 263 PAY 224 

    0xd4b9516c,// 264 PAY 225 

    0xde0f6dc5,// 265 PAY 226 

    0xd8547ecf,// 266 PAY 227 

    0x6f2dac58,// 267 PAY 228 

    0x826b3370,// 268 PAY 229 

    0x5b66d3ae,// 269 PAY 230 

    0x849b80db,// 270 PAY 231 

    0xd051cf38,// 271 PAY 232 

    0x4752a91d,// 272 PAY 233 

    0xd24a9a3a,// 273 PAY 234 

    0x7b21d675,// 274 PAY 235 

    0x3b251be6,// 275 PAY 236 

    0x6ffbf5e9,// 276 PAY 237 

    0x2da17a3f,// 277 PAY 238 

    0x9fadb3c4,// 278 PAY 239 

    0xd2364620,// 279 PAY 240 

    0x4943e9af,// 280 PAY 241 

    0x301ad31c,// 281 PAY 242 

    0xf8afc922,// 282 PAY 243 

    0x1fafb8d4,// 283 PAY 244 

    0x9ac5aea8,// 284 PAY 245 

    0x19a5a69f,// 285 PAY 246 

    0x875760ea,// 286 PAY 247 

    0x36655fa7,// 287 PAY 248 

    0x0b8ba831,// 288 PAY 249 

    0x054f3a60,// 289 PAY 250 

    0xa1d4aab2,// 290 PAY 251 

    0xeb1bf553,// 291 PAY 252 

    0xfc757fc4,// 292 PAY 253 

    0x142f3cec,// 293 PAY 254 

    0x510fecae,// 294 PAY 255 

    0x9a60b669,// 295 PAY 256 

    0x47226795,// 296 PAY 257 

    0x9a3eecf9,// 297 PAY 258 

    0x56bc926f,// 298 PAY 259 

    0xa1e3d37d,// 299 PAY 260 

    0x67312fe5,// 300 PAY 261 

    0x81a7f7b6,// 301 PAY 262 

    0x822b4232,// 302 PAY 263 

    0xf5f54bd6,// 303 PAY 264 

    0xf8dbfc76,// 304 PAY 265 

    0x53849eb8,// 305 PAY 266 

    0xc29261c6,// 306 PAY 267 

    0xc601c379,// 307 PAY 268 

    0xdcad3048,// 308 PAY 269 

    0xb10d6a0f,// 309 PAY 270 

    0xa4eba60c,// 310 PAY 271 

    0x10764ebd,// 311 PAY 272 

    0xbaec3cb7,// 312 PAY 273 

    0xcc5c8964,// 313 PAY 274 

    0x681ccd07,// 314 PAY 275 

    0xb6fa588f,// 315 PAY 276 

    0xa8b261a5,// 316 PAY 277 

    0x81f4d1a9,// 317 PAY 278 

    0x0aeece99,// 318 PAY 279 

    0x1ff9c546,// 319 PAY 280 

    0x7887d239,// 320 PAY 281 

    0xeea2430a,// 321 PAY 282 

    0xbe22a195,// 322 PAY 283 

    0xf15c2ddc,// 323 PAY 284 

    0x53597e09,// 324 PAY 285 

    0xe5a5bc03,// 325 PAY 286 

    0x19194cf7,// 326 PAY 287 

    0x8309b1d4,// 327 PAY 288 

    0x63ca9569,// 328 PAY 289 

    0x50fcc7bf,// 329 PAY 290 

    0xc34eac2c,// 330 PAY 291 

    0x02549b2c,// 331 PAY 292 

    0x1b07c116,// 332 PAY 293 

    0x59acf809,// 333 PAY 294 

    0xce6be8b8,// 334 PAY 295 

    0x9a8b1e79,// 335 PAY 296 

    0x9e3ae1f2,// 336 PAY 297 

    0xf67e8f7e,// 337 PAY 298 

    0x1206d9ba,// 338 PAY 299 

    0xa286c914,// 339 PAY 300 

    0xa9b33678,// 340 PAY 301 

    0xb159298f,// 341 PAY 302 

    0x87a1c565,// 342 PAY 303 

    0x931bec12,// 343 PAY 304 

    0x7025c440,// 344 PAY 305 

    0x016f8e81,// 345 PAY 306 

    0xd2ce9e2a,// 346 PAY 307 

    0x3235fc45,// 347 PAY 308 

    0xce43c89c,// 348 PAY 309 

    0x5a3a7c85,// 349 PAY 310 

    0xced3db63,// 350 PAY 311 

    0x284e87e8,// 351 PAY 312 

    0x030ebdda,// 352 PAY 313 

    0x9203a33c,// 353 PAY 314 

    0xfcb832e0,// 354 PAY 315 

    0x110d4c1d,// 355 PAY 316 

    0x7e1e2024,// 356 PAY 317 

    0x16c5a495,// 357 PAY 318 

    0x1a584b01,// 358 PAY 319 

    0xa49c5d70,// 359 PAY 320 

    0xfc486750,// 360 PAY 321 

    0xe5ed4ddd,// 361 PAY 322 

    0x5701ab69,// 362 PAY 323 

    0x49123b73,// 363 PAY 324 

    0x4bd37a76,// 364 PAY 325 

    0xf5769988,// 365 PAY 326 

    0x1f9df0fd,// 366 PAY 327 

    0xe9693a2e,// 367 PAY 328 

    0xcf6c36e4,// 368 PAY 329 

    0x7766ff24,// 369 PAY 330 

    0x16207535,// 370 PAY 331 

    0x4b1f5156,// 371 PAY 332 

    0x9e088ac9,// 372 PAY 333 

    0x78fd5086,// 373 PAY 334 

    0x907b0980,// 374 PAY 335 

    0x6853085c,// 375 PAY 336 

    0x4ec09a21,// 376 PAY 337 

    0x0a3fd5cf,// 377 PAY 338 

    0x21944149,// 378 PAY 339 

    0x40084dfa,// 379 PAY 340 

    0xed7ade8c,// 380 PAY 341 

    0x5f47ae00,// 381 PAY 342 

    0x5f8b08cd,// 382 PAY 343 

    0x18e7747e,// 383 PAY 344 

    0x41c434a1,// 384 PAY 345 

    0xa74be3b5,// 385 PAY 346 

    0x73178a4e,// 386 PAY 347 

    0x8bf04a71,// 387 PAY 348 

    0x7d41e2c8,// 388 PAY 349 

    0xa818782c,// 389 PAY 350 

    0xabc4d1fa,// 390 PAY 351 

    0x5b3c9ccf,// 391 PAY 352 

    0xe6f96be3,// 392 PAY 353 

    0x2c94cb32,// 393 PAY 354 

    0xc5910000,// 394 PAY 355 

/// STA is 1 words. 

/// STA num_pkts       : 24 

/// STA pkt_idx        : 247 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xed 

    0x03dded18 // 395 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt70_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x809228c3,// 4 SCX   2 

    0x000063c2,// 5 SCX   3 

    0xa6105a85,// 6 SCX   4 

    0xbe8e4529,// 7 SCX   5 

    0x2c971e8d,// 8 SCX   6 

    0x56a0c58b,// 9 SCX   7 

    0x6cab56ed,// 10 SCX   8 

    0x16019602,// 11 SCX   9 

    0x1348f5e2,// 12 SCX  10 

    0xe378104a,// 13 SCX  11 

    0x0e0cd394,// 14 SCX  12 

    0xe2ccc261,// 15 SCX  13 

    0xfa0a6498,// 16 SCX  14 

    0xac76feac,// 17 SCX  15 

    0x336c033d,// 18 SCX  16 

    0x6ade1c84,// 19 SCX  17 

    0x1e1a6e47,// 20 SCX  18 

    0x99e6b271,// 21 SCX  19 

    0xd7e82654,// 22 SCX  20 

    0xa9fe612f,// 23 SCX  21 

    0x56940dff,// 24 SCX  22 

    0x7132332d,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 643 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 247 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 247 

/// BFD lencrypto      : 4 

/// BFD ofstcrypto     : 132 

/// BFD (ofst+len)cry  : 136 

/// BFD ofstiv         : 88 

/// BFD ofsticv        : 280 

    0x000000f7,// 26 BFD   1 

    0x00840004,// 27 BFD   2 

    0x01180058,// 28 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : d 

    0x0d00f92c,// 29 MFM   1 

    0xa9497f06,// 30 MFM   2 

    0x60000000,// 31 MFM   3 

/// BDA is 162 words. 

/// BDA size     is 643 (0x283) 

/// BDA id       is 0x8e57 

    0x02838e57,// 32 BDA   1 

/// PAY Generic Data size   : 643 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x0a125e74,// 33 PAY   1 

    0x6b05a188,// 34 PAY   2 

    0xf8ebed97,// 35 PAY   3 

    0xb84c7e19,// 36 PAY   4 

    0x1d23e01e,// 37 PAY   5 

    0x2df2a1a7,// 38 PAY   6 

    0x7f680852,// 39 PAY   7 

    0xfd48f352,// 40 PAY   8 

    0x36175108,// 41 PAY   9 

    0xf46f7c5e,// 42 PAY  10 

    0x737e5998,// 43 PAY  11 

    0x72337774,// 44 PAY  12 

    0x78a41034,// 45 PAY  13 

    0x605ab796,// 46 PAY  14 

    0xe67e11ab,// 47 PAY  15 

    0x7e7ab23b,// 48 PAY  16 

    0xda640d81,// 49 PAY  17 

    0x845d0e54,// 50 PAY  18 

    0xbf65180e,// 51 PAY  19 

    0xddc04357,// 52 PAY  20 

    0x768e1376,// 53 PAY  21 

    0x584926fd,// 54 PAY  22 

    0x3949d5d3,// 55 PAY  23 

    0x0d73ac3b,// 56 PAY  24 

    0x2c22253e,// 57 PAY  25 

    0xe495bb76,// 58 PAY  26 

    0x89e4fcfd,// 59 PAY  27 

    0x595dcd10,// 60 PAY  28 

    0x55bced9b,// 61 PAY  29 

    0xc390f5ed,// 62 PAY  30 

    0x67395cb9,// 63 PAY  31 

    0x2cf23352,// 64 PAY  32 

    0x04839dbb,// 65 PAY  33 

    0x7103e51d,// 66 PAY  34 

    0x13b95064,// 67 PAY  35 

    0x5dc6e575,// 68 PAY  36 

    0x28645da4,// 69 PAY  37 

    0x7299113a,// 70 PAY  38 

    0x2391c3a5,// 71 PAY  39 

    0x65ff046b,// 72 PAY  40 

    0x34b32dc8,// 73 PAY  41 

    0x9e23b5fb,// 74 PAY  42 

    0x9ddbc1ac,// 75 PAY  43 

    0x1bc446a3,// 76 PAY  44 

    0x45ea6f42,// 77 PAY  45 

    0xc6ce54ee,// 78 PAY  46 

    0x03049c45,// 79 PAY  47 

    0x443ee24c,// 80 PAY  48 

    0x4d249b58,// 81 PAY  49 

    0x80710b5a,// 82 PAY  50 

    0xeaf56c05,// 83 PAY  51 

    0x646222ab,// 84 PAY  52 

    0xaf9f38e6,// 85 PAY  53 

    0x6dbb3167,// 86 PAY  54 

    0xcd722109,// 87 PAY  55 

    0x4064f3a4,// 88 PAY  56 

    0x6c21968c,// 89 PAY  57 

    0xbe51a323,// 90 PAY  58 

    0xea3bacc7,// 91 PAY  59 

    0x72f363bc,// 92 PAY  60 

    0x447f2bdc,// 93 PAY  61 

    0xc64ddc20,// 94 PAY  62 

    0xf80f611e,// 95 PAY  63 

    0x01781f3a,// 96 PAY  64 

    0xa3372629,// 97 PAY  65 

    0xbcc162d2,// 98 PAY  66 

    0xfb143844,// 99 PAY  67 

    0x17c22f5b,// 100 PAY  68 

    0x797c614d,// 101 PAY  69 

    0xb4d1b5b0,// 102 PAY  70 

    0x286e57a1,// 103 PAY  71 

    0x8560f2d2,// 104 PAY  72 

    0xd24346d9,// 105 PAY  73 

    0x27e1946f,// 106 PAY  74 

    0xd56ce862,// 107 PAY  75 

    0x6c787c47,// 108 PAY  76 

    0x244f6fd2,// 109 PAY  77 

    0x90e0d40d,// 110 PAY  78 

    0xf44f41ca,// 111 PAY  79 

    0x1b3be03d,// 112 PAY  80 

    0x8b152097,// 113 PAY  81 

    0xf288fb49,// 114 PAY  82 

    0xf7532aa4,// 115 PAY  83 

    0x86d3af55,// 116 PAY  84 

    0xb21f34a3,// 117 PAY  85 

    0x9c1bc9d7,// 118 PAY  86 

    0xbedfe443,// 119 PAY  87 

    0x048fa948,// 120 PAY  88 

    0x95409219,// 121 PAY  89 

    0x20633a5b,// 122 PAY  90 

    0x8a62e60e,// 123 PAY  91 

    0x380b8525,// 124 PAY  92 

    0x0d9d1459,// 125 PAY  93 

    0x27b4c967,// 126 PAY  94 

    0xe9390b0f,// 127 PAY  95 

    0xcbaa0100,// 128 PAY  96 

    0xdacad868,// 129 PAY  97 

    0x86d41bdb,// 130 PAY  98 

    0x86505a7e,// 131 PAY  99 

    0x3775b2bd,// 132 PAY 100 

    0xa177276d,// 133 PAY 101 

    0xb8c416c6,// 134 PAY 102 

    0x29cd38be,// 135 PAY 103 

    0xe7132556,// 136 PAY 104 

    0xea743b48,// 137 PAY 105 

    0xe94c10c8,// 138 PAY 106 

    0x316d3fc9,// 139 PAY 107 

    0x2b4d0c88,// 140 PAY 108 

    0xb02ee113,// 141 PAY 109 

    0xbbbf7b0c,// 142 PAY 110 

    0x63b955f5,// 143 PAY 111 

    0x438e1219,// 144 PAY 112 

    0x1ac5a369,// 145 PAY 113 

    0x37d3aa6c,// 146 PAY 114 

    0x6a38a241,// 147 PAY 115 

    0xce179e75,// 148 PAY 116 

    0x45c63d9c,// 149 PAY 117 

    0xed0fab78,// 150 PAY 118 

    0xf534f62d,// 151 PAY 119 

    0x7e8e6457,// 152 PAY 120 

    0xd20b7e2d,// 153 PAY 121 

    0x23225d3a,// 154 PAY 122 

    0x965e3fd9,// 155 PAY 123 

    0xc0b112ba,// 156 PAY 124 

    0xea229008,// 157 PAY 125 

    0xb121c111,// 158 PAY 126 

    0x53676940,// 159 PAY 127 

    0x7d77ee55,// 160 PAY 128 

    0x9f81d32b,// 161 PAY 129 

    0x7c567374,// 162 PAY 130 

    0x60909cb9,// 163 PAY 131 

    0x5a44dd67,// 164 PAY 132 

    0xb5dea3d1,// 165 PAY 133 

    0x4182b629,// 166 PAY 134 

    0x45e4b2c5,// 167 PAY 135 

    0x3f794277,// 168 PAY 136 

    0xb1228b04,// 169 PAY 137 

    0x3f8890c4,// 170 PAY 138 

    0x3bac7b2e,// 171 PAY 139 

    0xa867f270,// 172 PAY 140 

    0x64b65a1e,// 173 PAY 141 

    0x1a9200dc,// 174 PAY 142 

    0x00b18f21,// 175 PAY 143 

    0x6257a0e3,// 176 PAY 144 

    0xd7515be6,// 177 PAY 145 

    0x6629a81d,// 178 PAY 146 

    0xd09a7c53,// 179 PAY 147 

    0x52f4fe11,// 180 PAY 148 

    0xc2911ab0,// 181 PAY 149 

    0xd8fcbdbf,// 182 PAY 150 

    0xac1c24df,// 183 PAY 151 

    0xadea1284,// 184 PAY 152 

    0xb541c8b4,// 185 PAY 153 

    0xf65e2eb7,// 186 PAY 154 

    0x0400207c,// 187 PAY 155 

    0x48d25d28,// 188 PAY 156 

    0x75e16f28,// 189 PAY 157 

    0x3785830d,// 190 PAY 158 

    0xe6f7ef0c,// 191 PAY 159 

    0x99c443a0,// 192 PAY 160 

    0x5b6a2400,// 193 PAY 161 

/// STA is 1 words. 

/// STA num_pkts       : 20 

/// STA pkt_idx        : 132 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x13 

    0x02111314 // 194 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt71_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x09 

/// ECH pdu_tag        : 0x00 

    0x00090000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000013,// 3 SCX   1 

    0x808428b2,// 4 SCX   2 

    0x000001c4,// 5 SCX   3 

    0xeb82896f,// 6 SCX   4 

    0xfe895283,// 7 SCX   5 

    0xe30812ac,// 8 SCX   6 

    0x968c39d4,// 9 SCX   7 

    0x05fd79cd,// 10 SCX   8 

    0x73d9f557,// 11 SCX   9 

    0xa38fea6f,// 12 SCX  10 

    0x08a968c1,// 13 SCX  11 

    0xeebe293f,// 14 SCX  12 

    0x1706710b,// 15 SCX  13 

    0xeaee0523,// 16 SCX  14 

    0x9ab6cb36,// 17 SCX  15 

    0xeaaba274,// 18 SCX  16 

    0x918e7422,// 19 SCX  17 

    0xaa7b3aa3,// 20 SCX  18 

    0xfe63e2cf,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1377 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 311 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 311 

/// BFD lencrypto      : 192 

/// BFD ofstcrypto     : 112 

/// BFD (ofst+len)cry  : 304 

/// BFD ofstiv         : 20 

/// BFD ofsticv        : 696 

    0x00000137,// 22 BFD   1 

    0x007000c0,// 23 BFD   2 

    0x02b80014,// 24 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : d 

    0x0d00542f,// 25 MFM   1 

    0xef3d2c3b,// 26 MFM   2 

    0xd0000000,// 27 MFM   3 

/// BDA is 346 words. 

/// BDA size     is 1377 (0x561) 

/// BDA id       is 0xc9c9 

    0x0561c9c9,// 28 BDA   1 

/// PAY Generic Data size   : 1377 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x0f2a0ea6,// 29 PAY   1 

    0x8045e8e5,// 30 PAY   2 

    0xdce7eb9f,// 31 PAY   3 

    0xb12ddc9d,// 32 PAY   4 

    0x5720fff8,// 33 PAY   5 

    0xabe7b753,// 34 PAY   6 

    0xaee60120,// 35 PAY   7 

    0x7b908453,// 36 PAY   8 

    0x09730728,// 37 PAY   9 

    0x38b3777a,// 38 PAY  10 

    0x9d5e6b46,// 39 PAY  11 

    0xa34eb4ab,// 40 PAY  12 

    0xaddfd3e4,// 41 PAY  13 

    0x96091255,// 42 PAY  14 

    0x5f7f572f,// 43 PAY  15 

    0xb5961a23,// 44 PAY  16 

    0x0aa18ee6,// 45 PAY  17 

    0x0f57a140,// 46 PAY  18 

    0x4a1e4a53,// 47 PAY  19 

    0xe79a02d9,// 48 PAY  20 

    0x08a24421,// 49 PAY  21 

    0x0caf934b,// 50 PAY  22 

    0x730672c8,// 51 PAY  23 

    0x57217d0e,// 52 PAY  24 

    0xd2465b3f,// 53 PAY  25 

    0x079dcf2a,// 54 PAY  26 

    0x29bac8a0,// 55 PAY  27 

    0x585639c8,// 56 PAY  28 

    0xd767bcc0,// 57 PAY  29 

    0x08127827,// 58 PAY  30 

    0x30c6ef56,// 59 PAY  31 

    0x340cdde4,// 60 PAY  32 

    0xa43d622e,// 61 PAY  33 

    0x63a99dde,// 62 PAY  34 

    0x96277998,// 63 PAY  35 

    0x9270f456,// 64 PAY  36 

    0xdfb76028,// 65 PAY  37 

    0x724bb8bf,// 66 PAY  38 

    0xa6214d71,// 67 PAY  39 

    0x54e75e2f,// 68 PAY  40 

    0x64009134,// 69 PAY  41 

    0xafcfff51,// 70 PAY  42 

    0x12986183,// 71 PAY  43 

    0xe82952c1,// 72 PAY  44 

    0xd3dbe793,// 73 PAY  45 

    0xed0450e2,// 74 PAY  46 

    0x0881b0e3,// 75 PAY  47 

    0x327fad10,// 76 PAY  48 

    0xc27d0491,// 77 PAY  49 

    0x261ddc13,// 78 PAY  50 

    0x716e3e70,// 79 PAY  51 

    0x47a9d833,// 80 PAY  52 

    0x326e0c17,// 81 PAY  53 

    0xdd47e21c,// 82 PAY  54 

    0xdaf3c293,// 83 PAY  55 

    0x69f566a0,// 84 PAY  56 

    0x00866c5c,// 85 PAY  57 

    0x0d10d96b,// 86 PAY  58 

    0x12b11024,// 87 PAY  59 

    0xcfe1a9ec,// 88 PAY  60 

    0xabe11611,// 89 PAY  61 

    0x6f9f871c,// 90 PAY  62 

    0xf6ff07c8,// 91 PAY  63 

    0xcc76f474,// 92 PAY  64 

    0xba171b8f,// 93 PAY  65 

    0x91788b67,// 94 PAY  66 

    0x458a2ffc,// 95 PAY  67 

    0xb2a33a73,// 96 PAY  68 

    0xa1bb9332,// 97 PAY  69 

    0x1afb8619,// 98 PAY  70 

    0x3d7335ad,// 99 PAY  71 

    0x2c04295d,// 100 PAY  72 

    0x6d77cdc6,// 101 PAY  73 

    0x3db8c301,// 102 PAY  74 

    0xc0238b7e,// 103 PAY  75 

    0xb4261bb5,// 104 PAY  76 

    0xe97c44de,// 105 PAY  77 

    0xcd7f4f08,// 106 PAY  78 

    0x2f64b546,// 107 PAY  79 

    0xf6aa69b6,// 108 PAY  80 

    0xdcb71168,// 109 PAY  81 

    0xbab8f1bb,// 110 PAY  82 

    0x57d5ee01,// 111 PAY  83 

    0x625ff6e4,// 112 PAY  84 

    0x310f9664,// 113 PAY  85 

    0x7447cbf7,// 114 PAY  86 

    0xa517698b,// 115 PAY  87 

    0x9956d525,// 116 PAY  88 

    0x76be2f85,// 117 PAY  89 

    0x125a84cd,// 118 PAY  90 

    0x1d3d77ec,// 119 PAY  91 

    0x6f9bc390,// 120 PAY  92 

    0xac71c85c,// 121 PAY  93 

    0xb8e80ca5,// 122 PAY  94 

    0x04f74fd6,// 123 PAY  95 

    0x5a3aa35f,// 124 PAY  96 

    0xc19adc5b,// 125 PAY  97 

    0x8f3bc89d,// 126 PAY  98 

    0x16336f0c,// 127 PAY  99 

    0x7a355bae,// 128 PAY 100 

    0x64af0a55,// 129 PAY 101 

    0xfdec35d4,// 130 PAY 102 

    0xab7f2e3e,// 131 PAY 103 

    0xa78cf70c,// 132 PAY 104 

    0xcc1e79f1,// 133 PAY 105 

    0x529c4624,// 134 PAY 106 

    0x30db3a95,// 135 PAY 107 

    0xfe053af0,// 136 PAY 108 

    0xd4f46da3,// 137 PAY 109 

    0xc152c14b,// 138 PAY 110 

    0x69eb9641,// 139 PAY 111 

    0x2c56ce8a,// 140 PAY 112 

    0x29d903f2,// 141 PAY 113 

    0xca58c779,// 142 PAY 114 

    0x5aa1f2f4,// 143 PAY 115 

    0xe83dad58,// 144 PAY 116 

    0xd3747f2d,// 145 PAY 117 

    0x75883634,// 146 PAY 118 

    0x54cfc709,// 147 PAY 119 

    0x465d5fc4,// 148 PAY 120 

    0x02b97bb9,// 149 PAY 121 

    0xe6d04766,// 150 PAY 122 

    0x514593e8,// 151 PAY 123 

    0x6d5a5001,// 152 PAY 124 

    0x9dd92b0f,// 153 PAY 125 

    0x5f839c8c,// 154 PAY 126 

    0xd7463b23,// 155 PAY 127 

    0x7ef7db7e,// 156 PAY 128 

    0xe634d8cd,// 157 PAY 129 

    0xcd48fad5,// 158 PAY 130 

    0xe45e598d,// 159 PAY 131 

    0x89416bce,// 160 PAY 132 

    0xc74e002f,// 161 PAY 133 

    0x4dfece60,// 162 PAY 134 

    0x25b661a2,// 163 PAY 135 

    0x35e2be80,// 164 PAY 136 

    0x506ada4a,// 165 PAY 137 

    0xa89d856e,// 166 PAY 138 

    0x3ed855fc,// 167 PAY 139 

    0xc3bf1397,// 168 PAY 140 

    0xb5dba28a,// 169 PAY 141 

    0x056a8e30,// 170 PAY 142 

    0x937d479e,// 171 PAY 143 

    0x152e9962,// 172 PAY 144 

    0x9b4b158d,// 173 PAY 145 

    0x0b9896b2,// 174 PAY 146 

    0x2da92449,// 175 PAY 147 

    0x7bfb15cf,// 176 PAY 148 

    0x157acbc4,// 177 PAY 149 

    0x44c6e716,// 178 PAY 150 

    0x9ea8e637,// 179 PAY 151 

    0x11c8cb31,// 180 PAY 152 

    0xe4a0b65c,// 181 PAY 153 

    0x115e351f,// 182 PAY 154 

    0x696ae8a6,// 183 PAY 155 

    0x879d449b,// 184 PAY 156 

    0x1b109e06,// 185 PAY 157 

    0xa2a2db90,// 186 PAY 158 

    0x462f6625,// 187 PAY 159 

    0x2a6d7556,// 188 PAY 160 

    0xad789c3e,// 189 PAY 161 

    0x4d790bd0,// 190 PAY 162 

    0xc981d5e9,// 191 PAY 163 

    0x4b719fdf,// 192 PAY 164 

    0xbdcd798e,// 193 PAY 165 

    0x5d1e3ca2,// 194 PAY 166 

    0x40f9a928,// 195 PAY 167 

    0xc390bcdd,// 196 PAY 168 

    0x28e09484,// 197 PAY 169 

    0x43e5ac60,// 198 PAY 170 

    0x4b3ae0de,// 199 PAY 171 

    0xf22eb863,// 200 PAY 172 

    0x3ea6700e,// 201 PAY 173 

    0x5a3b5439,// 202 PAY 174 

    0xd28fb70a,// 203 PAY 175 

    0xc621085b,// 204 PAY 176 

    0xaf12bf5d,// 205 PAY 177 

    0xcade557b,// 206 PAY 178 

    0xc8d67b64,// 207 PAY 179 

    0x12cdafa1,// 208 PAY 180 

    0x3f687664,// 209 PAY 181 

    0x8053d026,// 210 PAY 182 

    0xc099092e,// 211 PAY 183 

    0x8fbd0cc5,// 212 PAY 184 

    0x5c4ffda1,// 213 PAY 185 

    0x6cad20b4,// 214 PAY 186 

    0xda78d895,// 215 PAY 187 

    0x6566ca53,// 216 PAY 188 

    0x2164dcef,// 217 PAY 189 

    0x7af3b123,// 218 PAY 190 

    0x7fae9c51,// 219 PAY 191 

    0x8591cd70,// 220 PAY 192 

    0x3820fb8e,// 221 PAY 193 

    0x78f1b4a3,// 222 PAY 194 

    0x079e2de7,// 223 PAY 195 

    0xca9431cb,// 224 PAY 196 

    0xb2866964,// 225 PAY 197 

    0xdcf8554b,// 226 PAY 198 

    0xa1d36996,// 227 PAY 199 

    0xa4c631a4,// 228 PAY 200 

    0xd1ecd319,// 229 PAY 201 

    0xff6d64a4,// 230 PAY 202 

    0x168d8bba,// 231 PAY 203 

    0x94fbb9b3,// 232 PAY 204 

    0xc23dfbc0,// 233 PAY 205 

    0xf715b97d,// 234 PAY 206 

    0xe7b29d9f,// 235 PAY 207 

    0x8b1d5ca0,// 236 PAY 208 

    0x3371df66,// 237 PAY 209 

    0xcdacaca4,// 238 PAY 210 

    0x27ba2077,// 239 PAY 211 

    0x1d99d0d5,// 240 PAY 212 

    0x8363f120,// 241 PAY 213 

    0xeffcd87f,// 242 PAY 214 

    0xea2679a9,// 243 PAY 215 

    0x52b8a574,// 244 PAY 216 

    0xc610e4e6,// 245 PAY 217 

    0x19eec8d5,// 246 PAY 218 

    0x201297c8,// 247 PAY 219 

    0xcadf3fb6,// 248 PAY 220 

    0x6276c27a,// 249 PAY 221 

    0x84544b12,// 250 PAY 222 

    0x8300bd45,// 251 PAY 223 

    0x4a369fc3,// 252 PAY 224 

    0x79a703f5,// 253 PAY 225 

    0x988fd9fe,// 254 PAY 226 

    0x1c8ede8a,// 255 PAY 227 

    0xd789560e,// 256 PAY 228 

    0x1d33b639,// 257 PAY 229 

    0xbdcc26c8,// 258 PAY 230 

    0x9300ccce,// 259 PAY 231 

    0x9495d212,// 260 PAY 232 

    0x82fa706d,// 261 PAY 233 

    0x9c07624f,// 262 PAY 234 

    0x33ad4c96,// 263 PAY 235 

    0xeb5fdabf,// 264 PAY 236 

    0xda444c9d,// 265 PAY 237 

    0x1e878f35,// 266 PAY 238 

    0x1168e676,// 267 PAY 239 

    0xf3d8c292,// 268 PAY 240 

    0x146ecb79,// 269 PAY 241 

    0xddcbbf52,// 270 PAY 242 

    0x4c5e5a74,// 271 PAY 243 

    0x0b529dbf,// 272 PAY 244 

    0x7ebc9f61,// 273 PAY 245 

    0xb7dee152,// 274 PAY 246 

    0x6c9e37f3,// 275 PAY 247 

    0x708b444d,// 276 PAY 248 

    0xc7ec48b5,// 277 PAY 249 

    0x01a1db0b,// 278 PAY 250 

    0x045e5bc9,// 279 PAY 251 

    0xa03714c9,// 280 PAY 252 

    0x2e01edfc,// 281 PAY 253 

    0x9cb882e7,// 282 PAY 254 

    0x0befb83b,// 283 PAY 255 

    0x4dee41fd,// 284 PAY 256 

    0x0a57dc0d,// 285 PAY 257 

    0x3c01a48e,// 286 PAY 258 

    0xf85a9c08,// 287 PAY 259 

    0x9a023edf,// 288 PAY 260 

    0x4eb7f442,// 289 PAY 261 

    0x3e97151d,// 290 PAY 262 

    0x6115f9f3,// 291 PAY 263 

    0x080ea43d,// 292 PAY 264 

    0x573a408a,// 293 PAY 265 

    0x08241f9d,// 294 PAY 266 

    0x0c1ba14a,// 295 PAY 267 

    0x4f18cd0d,// 296 PAY 268 

    0xbfeb67cc,// 297 PAY 269 

    0xe77664a3,// 298 PAY 270 

    0x534e9848,// 299 PAY 271 

    0xaaf72eb4,// 300 PAY 272 

    0x2f85cdc9,// 301 PAY 273 

    0x3192b929,// 302 PAY 274 

    0xbd14df0a,// 303 PAY 275 

    0x404a3993,// 304 PAY 276 

    0xafb80388,// 305 PAY 277 

    0x1c182eca,// 306 PAY 278 

    0x40b84ebb,// 307 PAY 279 

    0xdd907731,// 308 PAY 280 

    0x608a08c5,// 309 PAY 281 

    0x8dafd6ed,// 310 PAY 282 

    0x142f045c,// 311 PAY 283 

    0xcdcbed1e,// 312 PAY 284 

    0xedf6a461,// 313 PAY 285 

    0x65891603,// 314 PAY 286 

    0x454f1f0b,// 315 PAY 287 

    0x7f503409,// 316 PAY 288 

    0xfbde7e5f,// 317 PAY 289 

    0x935230fe,// 318 PAY 290 

    0x01277f0b,// 319 PAY 291 

    0x6efddc10,// 320 PAY 292 

    0x830a7469,// 321 PAY 293 

    0xb829f93a,// 322 PAY 294 

    0x28255fb1,// 323 PAY 295 

    0x7c887d1b,// 324 PAY 296 

    0x5c75c1cb,// 325 PAY 297 

    0xa335874d,// 326 PAY 298 

    0xd758d5c3,// 327 PAY 299 

    0xff1a2c86,// 328 PAY 300 

    0x92dd1480,// 329 PAY 301 

    0x81d412a6,// 330 PAY 302 

    0x2cc85308,// 331 PAY 303 

    0x812f2d65,// 332 PAY 304 

    0x80734e93,// 333 PAY 305 

    0x9b75e249,// 334 PAY 306 

    0xfe071e25,// 335 PAY 307 

    0xaf6646b9,// 336 PAY 308 

    0x61cf071a,// 337 PAY 309 

    0xb4e15e21,// 338 PAY 310 

    0xae119cc6,// 339 PAY 311 

    0x0ae46ecb,// 340 PAY 312 

    0xc59f929a,// 341 PAY 313 

    0x9e25402f,// 342 PAY 314 

    0x1247c380,// 343 PAY 315 

    0xeb34367e,// 344 PAY 316 

    0x7a22c6aa,// 345 PAY 317 

    0xfa47f032,// 346 PAY 318 

    0x02703359,// 347 PAY 319 

    0xc48349da,// 348 PAY 320 

    0xaf2e7bb4,// 349 PAY 321 

    0xaa3aaa60,// 350 PAY 322 

    0x2f74bac2,// 351 PAY 323 

    0x91ccac29,// 352 PAY 324 

    0xf54f44d5,// 353 PAY 325 

    0xbae23c5a,// 354 PAY 326 

    0x34cd7a28,// 355 PAY 327 

    0x8700f19d,// 356 PAY 328 

    0xbcd2f877,// 357 PAY 329 

    0x37175925,// 358 PAY 330 

    0x04cfdf73,// 359 PAY 331 

    0x0562638e,// 360 PAY 332 

    0x9b3e0207,// 361 PAY 333 

    0xe094e3c7,// 362 PAY 334 

    0xad67c4c5,// 363 PAY 335 

    0x2d8344b0,// 364 PAY 336 

    0xdfeabc5a,// 365 PAY 337 

    0x01ce7cf6,// 366 PAY 338 

    0x4934a073,// 367 PAY 339 

    0xb58a4b75,// 368 PAY 340 

    0xc74c15b6,// 369 PAY 341 

    0xee40a6c4,// 370 PAY 342 

    0x296e92bd,// 371 PAY 343 

    0xa5a8d7b3,// 372 PAY 344 

    0x57000000,// 373 PAY 345 

/// STA is 1 words. 

/// STA num_pkts       : 85 

/// STA pkt_idx        : 179 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xf5 

    0x02ccf555 // 374 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt72_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv !insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000015,// 3 SCX   1 

    0x8085284d,// 4 SCX   2 

    0x00004484,// 5 SCX   3 

    0xb344ee08,// 6 SCX   4 

    0x0c1be253,// 7 SCX   5 

    0x220fb0a6,// 8 SCX   6 

    0x2a14e5b5,// 9 SCX   7 

    0xfb340727,// 10 SCX   8 

    0x65641cca,// 11 SCX   9 

    0x43b99d77,// 12 SCX  10 

    0x15486249,// 13 SCX  11 

    0x83f961ac,// 14 SCX  12 

    0xdf5e5f4c,// 15 SCX  13 

    0x36e7a47e,// 16 SCX  14 

    0xf6dffe3f,// 17 SCX  15 

    0x5118b941,// 18 SCX  16 

    0xccfe693c,// 19 SCX  17 

    0x8e341009,// 20 SCX  18 

    0x8aea13cb,// 21 SCX  19 

    0x89206bbf,// 22 SCX  20 

    0x555ed925,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1263 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 328 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 328 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 68 

/// BFD (ofst+len)cry  : 148 

/// BFD ofstiv         : 44 

/// BFD ofsticv        : 860 

    0x00000148,// 24 BFD   1 

    0x00440050,// 25 BFD   2 

    0x035c002c,// 26 BFD   3 

/// MFM is 9 words. 

/// MFM vldnibs        : 40 

    0x40003de4,// 27 MFM   1 

    0xe00fe92b,// 28 MFM   2 

    0x2ff9be20,// 29 MFM   3 

    0xcc5bef4a,// 30 MFM   4 

    0xf33b37fb,// 31 MFM   5 

    0xb445d1ce,// 32 MFM   6 

    0xd18f9bca,// 33 MFM   7 

    0x279abf0d,// 34 MFM   8 

    0x6d790000,// 35 MFM   9 

/// BDA is 317 words. 

/// BDA size     is 1263 (0x4ef) 

/// BDA id       is 0xdad4 

    0x04efdad4,// 36 BDA   1 

/// PAY Generic Data size   : 1263 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x7fa7d4f4,// 37 PAY   1 

    0x4efd4d5c,// 38 PAY   2 

    0x1e447ef7,// 39 PAY   3 

    0x76ad3dff,// 40 PAY   4 

    0x29ea7c7f,// 41 PAY   5 

    0xae64bae1,// 42 PAY   6 

    0x540f5dc9,// 43 PAY   7 

    0xc42f7144,// 44 PAY   8 

    0x3a6d8d99,// 45 PAY   9 

    0x7fa81eda,// 46 PAY  10 

    0x92225263,// 47 PAY  11 

    0xbddb21a9,// 48 PAY  12 

    0xbe3ebdc6,// 49 PAY  13 

    0xaea4f97e,// 50 PAY  14 

    0xdb48aa84,// 51 PAY  15 

    0x707f72d8,// 52 PAY  16 

    0x6587d4f8,// 53 PAY  17 

    0xbbd509c8,// 54 PAY  18 

    0x0a067c98,// 55 PAY  19 

    0x4be5e45e,// 56 PAY  20 

    0xd8d5889d,// 57 PAY  21 

    0x793ab096,// 58 PAY  22 

    0x0b69a482,// 59 PAY  23 

    0x856a873b,// 60 PAY  24 

    0x9a8f6f63,// 61 PAY  25 

    0xb85f3c82,// 62 PAY  26 

    0x8302109a,// 63 PAY  27 

    0xefb36b59,// 64 PAY  28 

    0x05dce4a7,// 65 PAY  29 

    0x939a6050,// 66 PAY  30 

    0xffa46f11,// 67 PAY  31 

    0xd12da12f,// 68 PAY  32 

    0xff866a21,// 69 PAY  33 

    0x2e7d7e41,// 70 PAY  34 

    0x7eaac1e3,// 71 PAY  35 

    0x0460755c,// 72 PAY  36 

    0xa7fd784e,// 73 PAY  37 

    0x3ad0365c,// 74 PAY  38 

    0x1329ff38,// 75 PAY  39 

    0x24574afb,// 76 PAY  40 

    0x0eee4185,// 77 PAY  41 

    0x9ac52f31,// 78 PAY  42 

    0x60f71913,// 79 PAY  43 

    0x05e84e00,// 80 PAY  44 

    0xea46a2ac,// 81 PAY  45 

    0xbf155ecf,// 82 PAY  46 

    0xdeec00e8,// 83 PAY  47 

    0x3d821599,// 84 PAY  48 

    0x638edfa9,// 85 PAY  49 

    0xf1eb3ec4,// 86 PAY  50 

    0xf5853e47,// 87 PAY  51 

    0xb55192f5,// 88 PAY  52 

    0x3c2b96d2,// 89 PAY  53 

    0xa57c2b5b,// 90 PAY  54 

    0x1bd7daf2,// 91 PAY  55 

    0xbc51bc93,// 92 PAY  56 

    0x5cc2dcc9,// 93 PAY  57 

    0x67a6d49c,// 94 PAY  58 

    0x5cdcd2b1,// 95 PAY  59 

    0x80b49127,// 96 PAY  60 

    0xd59b0031,// 97 PAY  61 

    0xe187e7a7,// 98 PAY  62 

    0x8cb333c3,// 99 PAY  63 

    0xbe7fc920,// 100 PAY  64 

    0xafdc8169,// 101 PAY  65 

    0xcd65f268,// 102 PAY  66 

    0x70f02562,// 103 PAY  67 

    0x45ee6e87,// 104 PAY  68 

    0xc2d30c7e,// 105 PAY  69 

    0x4f1daee7,// 106 PAY  70 

    0x5cd0cce5,// 107 PAY  71 

    0x7dc46a9b,// 108 PAY  72 

    0x304e6994,// 109 PAY  73 

    0xb8ddc616,// 110 PAY  74 

    0xd8fffef3,// 111 PAY  75 

    0xd0cc3ae5,// 112 PAY  76 

    0x304bdb54,// 113 PAY  77 

    0x5a6b171a,// 114 PAY  78 

    0x6f0432b5,// 115 PAY  79 

    0xf5f0f146,// 116 PAY  80 

    0x62425f5e,// 117 PAY  81 

    0xa4c694ea,// 118 PAY  82 

    0xca011e10,// 119 PAY  83 

    0x0f3bd381,// 120 PAY  84 

    0x6c4a0746,// 121 PAY  85 

    0xd15c1f53,// 122 PAY  86 

    0xa79ad79a,// 123 PAY  87 

    0x854d83cd,// 124 PAY  88 

    0x4161d57b,// 125 PAY  89 

    0xbd2b6536,// 126 PAY  90 

    0x8ca0b058,// 127 PAY  91 

    0x6a82cd46,// 128 PAY  92 

    0xb67c6230,// 129 PAY  93 

    0x717e69bb,// 130 PAY  94 

    0x35ae75b5,// 131 PAY  95 

    0x9ae37904,// 132 PAY  96 

    0x65ab1eea,// 133 PAY  97 

    0x1cd926c7,// 134 PAY  98 

    0x670f9d34,// 135 PAY  99 

    0xde4ecbff,// 136 PAY 100 

    0xd58ff679,// 137 PAY 101 

    0xd2f99be9,// 138 PAY 102 

    0xa20e98b0,// 139 PAY 103 

    0xb8e7f49f,// 140 PAY 104 

    0xb0e76081,// 141 PAY 105 

    0xbcaf6df5,// 142 PAY 106 

    0xf0186e19,// 143 PAY 107 

    0x71cbb0cf,// 144 PAY 108 

    0xbfa88350,// 145 PAY 109 

    0x6234ba89,// 146 PAY 110 

    0x8c05b549,// 147 PAY 111 

    0x83cb2b81,// 148 PAY 112 

    0xb82c33e3,// 149 PAY 113 

    0xf0690031,// 150 PAY 114 

    0x7e1cf4a7,// 151 PAY 115 

    0x94662705,// 152 PAY 116 

    0xe3d64979,// 153 PAY 117 

    0x3e51f66b,// 154 PAY 118 

    0xfc8552fc,// 155 PAY 119 

    0xd4c08fb3,// 156 PAY 120 

    0xde979a30,// 157 PAY 121 

    0xfa54da25,// 158 PAY 122 

    0x81ef1650,// 159 PAY 123 

    0xeccca8c8,// 160 PAY 124 

    0xb39c3835,// 161 PAY 125 

    0x50133311,// 162 PAY 126 

    0x889edb08,// 163 PAY 127 

    0xc74aa058,// 164 PAY 128 

    0xfa1296b8,// 165 PAY 129 

    0x0012c1e4,// 166 PAY 130 

    0x12aae947,// 167 PAY 131 

    0xde804714,// 168 PAY 132 

    0x1fc34426,// 169 PAY 133 

    0x8174c32c,// 170 PAY 134 

    0xc64798ab,// 171 PAY 135 

    0xbe7f14f1,// 172 PAY 136 

    0x743de9a4,// 173 PAY 137 

    0xa329b52a,// 174 PAY 138 

    0x08e618ee,// 175 PAY 139 

    0xadd366bb,// 176 PAY 140 

    0xf8ae6c9f,// 177 PAY 141 

    0x2a31b684,// 178 PAY 142 

    0x19b57234,// 179 PAY 143 

    0x98533061,// 180 PAY 144 

    0xdd4ec9ed,// 181 PAY 145 

    0x3787ec90,// 182 PAY 146 

    0xd5789aac,// 183 PAY 147 

    0x210f46ab,// 184 PAY 148 

    0xaaf74bd0,// 185 PAY 149 

    0x85d11338,// 186 PAY 150 

    0xb232111b,// 187 PAY 151 

    0xe187154e,// 188 PAY 152 

    0x5c583b2a,// 189 PAY 153 

    0xc45172b6,// 190 PAY 154 

    0xcfce8f28,// 191 PAY 155 

    0x651377f9,// 192 PAY 156 

    0xd5a550ef,// 193 PAY 157 

    0xa950fdeb,// 194 PAY 158 

    0x847273c3,// 195 PAY 159 

    0x99d2fe59,// 196 PAY 160 

    0x8f54d1fc,// 197 PAY 161 

    0x3ba48508,// 198 PAY 162 

    0x972ee34a,// 199 PAY 163 

    0xea4fceb0,// 200 PAY 164 

    0x23caaf93,// 201 PAY 165 

    0xfb4d5d7f,// 202 PAY 166 

    0xe9556205,// 203 PAY 167 

    0x8bc54877,// 204 PAY 168 

    0x85e6f3e2,// 205 PAY 169 

    0x50d591ce,// 206 PAY 170 

    0x16543faa,// 207 PAY 171 

    0x27855252,// 208 PAY 172 

    0x89a3ee53,// 209 PAY 173 

    0x6ca387c3,// 210 PAY 174 

    0x01ef738b,// 211 PAY 175 

    0x47464175,// 212 PAY 176 

    0x8eb93453,// 213 PAY 177 

    0x462e10d6,// 214 PAY 178 

    0xa591e735,// 215 PAY 179 

    0x3d3800db,// 216 PAY 180 

    0xc5164366,// 217 PAY 181 

    0x64210e02,// 218 PAY 182 

    0xca09626b,// 219 PAY 183 

    0x933d01db,// 220 PAY 184 

    0xdeeab75a,// 221 PAY 185 

    0x5f3e9f5a,// 222 PAY 186 

    0xe4941815,// 223 PAY 187 

    0xf132aaec,// 224 PAY 188 

    0xf338b9bf,// 225 PAY 189 

    0xe2b9dedf,// 226 PAY 190 

    0x8d50a987,// 227 PAY 191 

    0x32f7f7ee,// 228 PAY 192 

    0x8896a3ab,// 229 PAY 193 

    0x4bf29696,// 230 PAY 194 

    0x41f4e14f,// 231 PAY 195 

    0xe5602606,// 232 PAY 196 

    0x912b84ee,// 233 PAY 197 

    0x38c1aa12,// 234 PAY 198 

    0x1dd3b0f5,// 235 PAY 199 

    0x32ecf93b,// 236 PAY 200 

    0x7e437b63,// 237 PAY 201 

    0x59096046,// 238 PAY 202 

    0x0fb46115,// 239 PAY 203 

    0xdf7b73fd,// 240 PAY 204 

    0x209a8185,// 241 PAY 205 

    0x0ba7d483,// 242 PAY 206 

    0x51090e6d,// 243 PAY 207 

    0xa804149e,// 244 PAY 208 

    0xe41368c3,// 245 PAY 209 

    0x1c4a489d,// 246 PAY 210 

    0xda12f071,// 247 PAY 211 

    0xe4ae2c37,// 248 PAY 212 

    0x43d7ce2b,// 249 PAY 213 

    0x72a3f2c3,// 250 PAY 214 

    0xb7ffd6cf,// 251 PAY 215 

    0x4ed6b4f7,// 252 PAY 216 

    0xba1aaf99,// 253 PAY 217 

    0xdfb90e2e,// 254 PAY 218 

    0x1ffc5f1e,// 255 PAY 219 

    0xda01c8d7,// 256 PAY 220 

    0xac740480,// 257 PAY 221 

    0x48c12fea,// 258 PAY 222 

    0x9ab93c9e,// 259 PAY 223 

    0x5a848fdf,// 260 PAY 224 

    0x48033ee8,// 261 PAY 225 

    0x31f316f7,// 262 PAY 226 

    0xd11b4f84,// 263 PAY 227 

    0xa6a0e9f6,// 264 PAY 228 

    0x97c7f6b5,// 265 PAY 229 

    0x67cbdb34,// 266 PAY 230 

    0x6678b306,// 267 PAY 231 

    0xc7e82d37,// 268 PAY 232 

    0xd2ff3a69,// 269 PAY 233 

    0x3469f16c,// 270 PAY 234 

    0x491d7323,// 271 PAY 235 

    0x0f9ea291,// 272 PAY 236 

    0xd707c7ec,// 273 PAY 237 

    0x22dfdc0c,// 274 PAY 238 

    0x6ea055e0,// 275 PAY 239 

    0x28e62867,// 276 PAY 240 

    0x30273cc1,// 277 PAY 241 

    0xe94241c8,// 278 PAY 242 

    0x5cbb090f,// 279 PAY 243 

    0x390a9037,// 280 PAY 244 

    0x2702f28f,// 281 PAY 245 

    0x5049654a,// 282 PAY 246 

    0x69991ecb,// 283 PAY 247 

    0xe5ccc072,// 284 PAY 248 

    0x4e766e22,// 285 PAY 249 

    0xa1dcc1ed,// 286 PAY 250 

    0x9981a7ef,// 287 PAY 251 

    0xea5296cf,// 288 PAY 252 

    0x739cc13b,// 289 PAY 253 

    0x288c04ea,// 290 PAY 254 

    0x9d6049be,// 291 PAY 255 

    0x210628b9,// 292 PAY 256 

    0xd47d6a26,// 293 PAY 257 

    0x49576ac4,// 294 PAY 258 

    0xce7d268f,// 295 PAY 259 

    0x652a11e3,// 296 PAY 260 

    0xb0156eb5,// 297 PAY 261 

    0x9a05da57,// 298 PAY 262 

    0x7ad95936,// 299 PAY 263 

    0x557a8b82,// 300 PAY 264 

    0x47dd0d85,// 301 PAY 265 

    0xfbd70447,// 302 PAY 266 

    0xfbd89278,// 303 PAY 267 

    0xea9f7ae7,// 304 PAY 268 

    0x60fac404,// 305 PAY 269 

    0x6d6798d5,// 306 PAY 270 

    0x8c79f1af,// 307 PAY 271 

    0x434e5d13,// 308 PAY 272 

    0xa6551347,// 309 PAY 273 

    0x5404e469,// 310 PAY 274 

    0x2c87a576,// 311 PAY 275 

    0xfab3ae88,// 312 PAY 276 

    0xad46684f,// 313 PAY 277 

    0xde77ee34,// 314 PAY 278 

    0x84a95396,// 315 PAY 279 

    0xdc79cfdb,// 316 PAY 280 

    0xdac9171c,// 317 PAY 281 

    0xb9c06e32,// 318 PAY 282 

    0x08b1072a,// 319 PAY 283 

    0x52211e95,// 320 PAY 284 

    0xed311425,// 321 PAY 285 

    0x8e3e0d0c,// 322 PAY 286 

    0x38fdb9e7,// 323 PAY 287 

    0xabb16910,// 324 PAY 288 

    0x8537fb64,// 325 PAY 289 

    0x79637e8d,// 326 PAY 290 

    0x3e0a2d83,// 327 PAY 291 

    0xa59ab660,// 328 PAY 292 

    0x10f9b988,// 329 PAY 293 

    0xed9c665b,// 330 PAY 294 

    0x04f8b697,// 331 PAY 295 

    0x9960c693,// 332 PAY 296 

    0xcccc8cba,// 333 PAY 297 

    0xf16a2197,// 334 PAY 298 

    0xbd22ee16,// 335 PAY 299 

    0xe16ff8ed,// 336 PAY 300 

    0xe5636005,// 337 PAY 301 

    0x6ffce3c0,// 338 PAY 302 

    0x65ab6a02,// 339 PAY 303 

    0x61af63f9,// 340 PAY 304 

    0xf1859b1f,// 341 PAY 305 

    0xb201dc02,// 342 PAY 306 

    0xbe0ba268,// 343 PAY 307 

    0x574d6dcc,// 344 PAY 308 

    0x727c9b7d,// 345 PAY 309 

    0xba99aaa7,// 346 PAY 310 

    0x7974e705,// 347 PAY 311 

    0x6dccc142,// 348 PAY 312 

    0xf4335d3d,// 349 PAY 313 

    0x3b25477c,// 350 PAY 314 

    0x18845d45,// 351 PAY 315 

    0x49505800,// 352 PAY 316 

/// STA is 1 words. 

/// STA num_pkts       : 44 

/// STA pkt_idx        : 45 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x94 

    0x00b5942c // 353 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt73_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80822853,// 4 SCX   2 

    0x00004200,// 5 SCX   3 

    0xdf92daf3,// 6 SCX   4 

    0xcbf24784,// 7 SCX   5 

    0x9c2a1047,// 8 SCX   6 

    0x2d61c73f,// 9 SCX   7 

    0x49f3bb13,// 10 SCX   8 

    0x583ac0bf,// 11 SCX   9 

    0x69f7a5f3,// 12 SCX  10 

    0x8c8ac7f3,// 13 SCX  11 

    0xba60962c,// 14 SCX  12 

    0x407e0e3f,// 15 SCX  13 

    0x79e46655,// 16 SCX  14 

    0xd8fcccbe,// 17 SCX  15 

    0x8bc460ab,// 18 SCX  16 

    0xe6781985,// 19 SCX  17 

    0x7e9c9ae3,// 20 SCX  18 

    0xc263d0ae,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1358 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 38 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 38 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 20 

/// BFD (ofst+len)cry  : 36 

/// BFD ofstiv         : 0 

/// BFD ofsticv        : 1308 

    0x00000026,// 22 BFD   1 

    0x00140010,// 23 BFD   2 

    0x051c0000,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 9 

    0x0900dc5f,// 25 MFM   1 

    0xd71a8000,// 26 MFM   2 

/// BDA is 341 words. 

/// BDA size     is 1358 (0x54e) 

/// BDA id       is 0xb041 

    0x054eb041,// 27 BDA   1 

/// PAY Generic Data size   : 1358 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x7388c811,// 28 PAY   1 

    0x012c377e,// 29 PAY   2 

    0x5f6c5a15,// 30 PAY   3 

    0x7db9e8d8,// 31 PAY   4 

    0x3c3635cc,// 32 PAY   5 

    0x44010a57,// 33 PAY   6 

    0xbc60e3d6,// 34 PAY   7 

    0x4f92a1fd,// 35 PAY   8 

    0x8e64bcbd,// 36 PAY   9 

    0xee6c611e,// 37 PAY  10 

    0x82324144,// 38 PAY  11 

    0xa7804274,// 39 PAY  12 

    0x3aa4ca96,// 40 PAY  13 

    0xed08c494,// 41 PAY  14 

    0x313169a7,// 42 PAY  15 

    0x74fda078,// 43 PAY  16 

    0x866ed2d6,// 44 PAY  17 

    0xae85130d,// 45 PAY  18 

    0x2748a1f0,// 46 PAY  19 

    0xaccf3dc5,// 47 PAY  20 

    0x8ced46fc,// 48 PAY  21 

    0x5bb60325,// 49 PAY  22 

    0x9c4389e5,// 50 PAY  23 

    0x59ed7d6e,// 51 PAY  24 

    0x53bb222b,// 52 PAY  25 

    0xe8e80a3c,// 53 PAY  26 

    0x6025dd6b,// 54 PAY  27 

    0xd3fa9964,// 55 PAY  28 

    0x43dd68b9,// 56 PAY  29 

    0x1afd1265,// 57 PAY  30 

    0x3bb3d4d4,// 58 PAY  31 

    0xf4f7f3b4,// 59 PAY  32 

    0xcb51863a,// 60 PAY  33 

    0x67f95ecb,// 61 PAY  34 

    0x324e5292,// 62 PAY  35 

    0xff1078a7,// 63 PAY  36 

    0x5cf4b16e,// 64 PAY  37 

    0x9cc761e4,// 65 PAY  38 

    0x0d718da3,// 66 PAY  39 

    0x6cd36d18,// 67 PAY  40 

    0x147144bd,// 68 PAY  41 

    0xe20b2cb5,// 69 PAY  42 

    0x5d902b34,// 70 PAY  43 

    0xdbcd395b,// 71 PAY  44 

    0x347060f3,// 72 PAY  45 

    0x84dfc1f9,// 73 PAY  46 

    0xcee5921e,// 74 PAY  47 

    0x992a9239,// 75 PAY  48 

    0xa89b4a78,// 76 PAY  49 

    0x376fe45c,// 77 PAY  50 

    0x670ca631,// 78 PAY  51 

    0xc151850f,// 79 PAY  52 

    0xbee99544,// 80 PAY  53 

    0x9211b06f,// 81 PAY  54 

    0x85bc3ef2,// 82 PAY  55 

    0xf02b6ecd,// 83 PAY  56 

    0x2059a0a2,// 84 PAY  57 

    0x861e9ec3,// 85 PAY  58 

    0xb378ad21,// 86 PAY  59 

    0xa6643462,// 87 PAY  60 

    0x6ce982e3,// 88 PAY  61 

    0x0293a872,// 89 PAY  62 

    0x32995eec,// 90 PAY  63 

    0xc034a89e,// 91 PAY  64 

    0xd5542cc9,// 92 PAY  65 

    0x5da09039,// 93 PAY  66 

    0xdf634ac0,// 94 PAY  67 

    0x3516ab99,// 95 PAY  68 

    0xc47cbc23,// 96 PAY  69 

    0xd9649782,// 97 PAY  70 

    0x32028d2d,// 98 PAY  71 

    0xa08685f3,// 99 PAY  72 

    0xd8408d0c,// 100 PAY  73 

    0xfc164dfd,// 101 PAY  74 

    0xc3cdde75,// 102 PAY  75 

    0x00faaf99,// 103 PAY  76 

    0xded6c919,// 104 PAY  77 

    0x2356a441,// 105 PAY  78 

    0x3ccfc340,// 106 PAY  79 

    0x6903a6d1,// 107 PAY  80 

    0x7343ff13,// 108 PAY  81 

    0x0a9546f3,// 109 PAY  82 

    0x0ef429e2,// 110 PAY  83 

    0xd2f3ca73,// 111 PAY  84 

    0x429f789b,// 112 PAY  85 

    0xf9fcd9e5,// 113 PAY  86 

    0x83eb7146,// 114 PAY  87 

    0x14fe9aa0,// 115 PAY  88 

    0xfdc0e7ee,// 116 PAY  89 

    0x1e86febb,// 117 PAY  90 

    0xaf762605,// 118 PAY  91 

    0xf03db7f6,// 119 PAY  92 

    0x1b18fe76,// 120 PAY  93 

    0x52d511bc,// 121 PAY  94 

    0x0ee92347,// 122 PAY  95 

    0xd481b7ec,// 123 PAY  96 

    0x0f895230,// 124 PAY  97 

    0x0b8488a0,// 125 PAY  98 

    0xc548ba0f,// 126 PAY  99 

    0x5a7987d5,// 127 PAY 100 

    0xd7f4e0f8,// 128 PAY 101 

    0x82cfffe0,// 129 PAY 102 

    0x3441b6e3,// 130 PAY 103 

    0xa87fc5ae,// 131 PAY 104 

    0x6e584197,// 132 PAY 105 

    0x2784c0cb,// 133 PAY 106 

    0x4a1d6000,// 134 PAY 107 

    0xfc60aa81,// 135 PAY 108 

    0x3884d975,// 136 PAY 109 

    0x8572f701,// 137 PAY 110 

    0x494e5c5a,// 138 PAY 111 

    0x00d10d5f,// 139 PAY 112 

    0xe768713a,// 140 PAY 113 

    0x3f5dc95f,// 141 PAY 114 

    0x23aca171,// 142 PAY 115 

    0x071baae8,// 143 PAY 116 

    0x11bdd6f9,// 144 PAY 117 

    0x88a7bc68,// 145 PAY 118 

    0xe2d0c475,// 146 PAY 119 

    0x22eaab71,// 147 PAY 120 

    0x63079f27,// 148 PAY 121 

    0x7ce32da1,// 149 PAY 122 

    0x7ad60baa,// 150 PAY 123 

    0x28663f7c,// 151 PAY 124 

    0xe41e4603,// 152 PAY 125 

    0x0ffbf733,// 153 PAY 126 

    0x37799363,// 154 PAY 127 

    0x3c627bff,// 155 PAY 128 

    0x5a9c1be5,// 156 PAY 129 

    0x606c14b4,// 157 PAY 130 

    0xdc54bbd1,// 158 PAY 131 

    0x5fa18cda,// 159 PAY 132 

    0xb7267cd6,// 160 PAY 133 

    0x2fa46942,// 161 PAY 134 

    0xbe7cd425,// 162 PAY 135 

    0xc38ac45d,// 163 PAY 136 

    0x72a8c5b1,// 164 PAY 137 

    0x2a165073,// 165 PAY 138 

    0xdf7895da,// 166 PAY 139 

    0x2774c568,// 167 PAY 140 

    0x9718f502,// 168 PAY 141 

    0x89290550,// 169 PAY 142 

    0x939da5a4,// 170 PAY 143 

    0xacb07082,// 171 PAY 144 

    0x752b8970,// 172 PAY 145 

    0xe04e2647,// 173 PAY 146 

    0x007337d9,// 174 PAY 147 

    0x9eb8edda,// 175 PAY 148 

    0xa8cf3c8e,// 176 PAY 149 

    0x15b99ef9,// 177 PAY 150 

    0xdfac629c,// 178 PAY 151 

    0x7040633c,// 179 PAY 152 

    0xe5f2b7f8,// 180 PAY 153 

    0x0cb854ba,// 181 PAY 154 

    0xb7741103,// 182 PAY 155 

    0x8156c4c1,// 183 PAY 156 

    0x16286725,// 184 PAY 157 

    0x16d276d2,// 185 PAY 158 

    0x0d8dbd19,// 186 PAY 159 

    0x6e4bfade,// 187 PAY 160 

    0xd000def4,// 188 PAY 161 

    0x9cb4ebbd,// 189 PAY 162 

    0x80ff3c74,// 190 PAY 163 

    0x5936f5fe,// 191 PAY 164 

    0x9562435a,// 192 PAY 165 

    0xf1e2e251,// 193 PAY 166 

    0x57172034,// 194 PAY 167 

    0xd27e0edc,// 195 PAY 168 

    0xed5faf66,// 196 PAY 169 

    0x59412233,// 197 PAY 170 

    0x895f0336,// 198 PAY 171 

    0x23c5c0aa,// 199 PAY 172 

    0x31f8deec,// 200 PAY 173 

    0x3b4f6f75,// 201 PAY 174 

    0xa30f760e,// 202 PAY 175 

    0x69ec7430,// 203 PAY 176 

    0x82aa3970,// 204 PAY 177 

    0x94d941c3,// 205 PAY 178 

    0x6e446ca1,// 206 PAY 179 

    0x4635af4c,// 207 PAY 180 

    0xc7381dc5,// 208 PAY 181 

    0x55dabcf8,// 209 PAY 182 

    0x8082040d,// 210 PAY 183 

    0xd611b4b9,// 211 PAY 184 

    0x10f53a5a,// 212 PAY 185 

    0x8e3c078c,// 213 PAY 186 

    0x118ebe6c,// 214 PAY 187 

    0x4302fbb6,// 215 PAY 188 

    0x58bdb951,// 216 PAY 189 

    0x97ee2824,// 217 PAY 190 

    0x354a5099,// 218 PAY 191 

    0x332b2dab,// 219 PAY 192 

    0x1b3b6b13,// 220 PAY 193 

    0x3c952092,// 221 PAY 194 

    0xcf93b0d4,// 222 PAY 195 

    0xc426c46f,// 223 PAY 196 

    0x2c0e713b,// 224 PAY 197 

    0x04cb773a,// 225 PAY 198 

    0x52e88a24,// 226 PAY 199 

    0xda9e41ff,// 227 PAY 200 

    0x706533f0,// 228 PAY 201 

    0xccb1c430,// 229 PAY 202 

    0x86797484,// 230 PAY 203 

    0xadd517fe,// 231 PAY 204 

    0x5e643583,// 232 PAY 205 

    0xa0834d81,// 233 PAY 206 

    0xa68fe74c,// 234 PAY 207 

    0x29dbe5e2,// 235 PAY 208 

    0xe467e72d,// 236 PAY 209 

    0xa5c42125,// 237 PAY 210 

    0xcb03cb6e,// 238 PAY 211 

    0x75cb9a66,// 239 PAY 212 

    0x24bbe5dd,// 240 PAY 213 

    0x3f05d5e2,// 241 PAY 214 

    0xfe601717,// 242 PAY 215 

    0x9d60649b,// 243 PAY 216 

    0x74f28379,// 244 PAY 217 

    0x82c9deaf,// 245 PAY 218 

    0x13cc5c82,// 246 PAY 219 

    0x2c411448,// 247 PAY 220 

    0x92c113d1,// 248 PAY 221 

    0xba632ebf,// 249 PAY 222 

    0xe02ff658,// 250 PAY 223 

    0x7f3d5b7d,// 251 PAY 224 

    0x3a09eec3,// 252 PAY 225 

    0xcbf1deb2,// 253 PAY 226 

    0xb49f993a,// 254 PAY 227 

    0x5ce3d0dd,// 255 PAY 228 

    0xb53817c5,// 256 PAY 229 

    0xf698ceb0,// 257 PAY 230 

    0xc6766113,// 258 PAY 231 

    0xddcdab5b,// 259 PAY 232 

    0xadec1e70,// 260 PAY 233 

    0x96479cda,// 261 PAY 234 

    0xb431aa22,// 262 PAY 235 

    0x132a544e,// 263 PAY 236 

    0xfb78a1a8,// 264 PAY 237 

    0x22d82d45,// 265 PAY 238 

    0x67d8fdad,// 266 PAY 239 

    0xcfa030b9,// 267 PAY 240 

    0x9a16c319,// 268 PAY 241 

    0x2f3a5478,// 269 PAY 242 

    0x2374aac3,// 270 PAY 243 

    0x8ab60de3,// 271 PAY 244 

    0x13d71835,// 272 PAY 245 

    0xf86c920a,// 273 PAY 246 

    0xf3217782,// 274 PAY 247 

    0xe009e839,// 275 PAY 248 

    0x7f47abbd,// 276 PAY 249 

    0xde42ca9f,// 277 PAY 250 

    0x586cef52,// 278 PAY 251 

    0x6554a9aa,// 279 PAY 252 

    0xbe9bb724,// 280 PAY 253 

    0x7964ed60,// 281 PAY 254 

    0xdaddf3b3,// 282 PAY 255 

    0x5f948027,// 283 PAY 256 

    0x1c6f8b99,// 284 PAY 257 

    0x594f59ec,// 285 PAY 258 

    0x9fbc5145,// 286 PAY 259 

    0xfe8cb550,// 287 PAY 260 

    0x43893178,// 288 PAY 261 

    0x68836899,// 289 PAY 262 

    0xa6a891d6,// 290 PAY 263 

    0xae0b86cc,// 291 PAY 264 

    0xe6e9eb05,// 292 PAY 265 

    0x7b6b0bff,// 293 PAY 266 

    0xbac9fc98,// 294 PAY 267 

    0xdea3de6a,// 295 PAY 268 

    0x8492a91b,// 296 PAY 269 

    0xb6c50a3d,// 297 PAY 270 

    0x441997fd,// 298 PAY 271 

    0xda88272f,// 299 PAY 272 

    0x7bf6883a,// 300 PAY 273 

    0x3bd15af5,// 301 PAY 274 

    0x024a971a,// 302 PAY 275 

    0xe3b805b5,// 303 PAY 276 

    0x29aa10e0,// 304 PAY 277 

    0x6b710610,// 305 PAY 278 

    0xf63436ae,// 306 PAY 279 

    0xc4dd50cc,// 307 PAY 280 

    0xf54ec43d,// 308 PAY 281 

    0x8e71d3ba,// 309 PAY 282 

    0x3a63e8e0,// 310 PAY 283 

    0x8ea8f3a4,// 311 PAY 284 

    0x769f962b,// 312 PAY 285 

    0xd8fa233a,// 313 PAY 286 

    0x8dc2da27,// 314 PAY 287 

    0x940cee2e,// 315 PAY 288 

    0xc5a1de9b,// 316 PAY 289 

    0x66e2c30d,// 317 PAY 290 

    0x537614c9,// 318 PAY 291 

    0x10e62497,// 319 PAY 292 

    0xeeb49950,// 320 PAY 293 

    0x8435c15f,// 321 PAY 294 

    0x317017f6,// 322 PAY 295 

    0x5bed7c2e,// 323 PAY 296 

    0x18d3dc05,// 324 PAY 297 

    0xe45fb695,// 325 PAY 298 

    0xaba8c706,// 326 PAY 299 

    0x2e8baa42,// 327 PAY 300 

    0xbc418d19,// 328 PAY 301 

    0x31fad492,// 329 PAY 302 

    0xcceb9f3e,// 330 PAY 303 

    0xbe143f88,// 331 PAY 304 

    0x10b9d527,// 332 PAY 305 

    0x0de0615a,// 333 PAY 306 

    0xebeb30cc,// 334 PAY 307 

    0x521486cf,// 335 PAY 308 

    0x9af00c27,// 336 PAY 309 

    0xfb78c2d8,// 337 PAY 310 

    0x623585e7,// 338 PAY 311 

    0x1f508a35,// 339 PAY 312 

    0x76730218,// 340 PAY 313 

    0xd1317ab1,// 341 PAY 314 

    0x567f10e4,// 342 PAY 315 

    0x1b36c02d,// 343 PAY 316 

    0x08e016a3,// 344 PAY 317 

    0xeb7e44bf,// 345 PAY 318 

    0x636e253d,// 346 PAY 319 

    0x4396da5a,// 347 PAY 320 

    0xc181ea9a,// 348 PAY 321 

    0x2d3b57ab,// 349 PAY 322 

    0xd22a02f9,// 350 PAY 323 

    0x0a8f2240,// 351 PAY 324 

    0x17c18144,// 352 PAY 325 

    0xc3e0ada1,// 353 PAY 326 

    0xad3c52aa,// 354 PAY 327 

    0x7082fa44,// 355 PAY 328 

    0xc6a41065,// 356 PAY 329 

    0x343e3eac,// 357 PAY 330 

    0x07fa9ac5,// 358 PAY 331 

    0xdf9d4abf,// 359 PAY 332 

    0x1aa063a1,// 360 PAY 333 

    0xe88ed1e4,// 361 PAY 334 

    0xc34f2b53,// 362 PAY 335 

    0x33d10184,// 363 PAY 336 

    0x623cbec1,// 364 PAY 337 

    0xd5dbca9d,// 365 PAY 338 

    0x9424da99,// 366 PAY 339 

    0x78580000,// 367 PAY 340 

/// STA is 1 words. 

/// STA num_pkts       : 218 

/// STA pkt_idx        : 241 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x44 

    0x03c544da // 368 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt74_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0c 

/// ECH pdu_tag        : 0x00 

    0x000c0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv !check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x2 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x8080287e,// 4 SCX   2 

    0x00004200,// 5 SCX   3 

    0xee85b63a,// 6 SCX   4 

    0xa99b7144,// 7 SCX   5 

    0x6d3b500d,// 8 SCX   6 

    0xd526e171,// 9 SCX   7 

    0x81c7d3f4,// 10 SCX   8 

    0xd9c06785,// 11 SCX   9 

    0xb4018431,// 12 SCX  10 

    0xe621acc6,// 13 SCX  11 

    0xb5e4797a,// 14 SCX  12 

    0x94d975ed,// 15 SCX  13 

    0x26010b0d,// 16 SCX  14 

    0xcc25b7b8,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1481 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 1411 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 1411 

/// BFD lencrypto      : 240 

/// BFD ofstcrypto     : 1072 

/// BFD (ofst+len)cry  : 1312 

/// BFD ofstiv         : 684 

/// BFD ofsticv        : 1460 

    0x00000583,// 18 BFD   1 

    0x043000f0,// 19 BFD   2 

    0x05b402ac,// 20 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c00974e,// 21 MFM   1 

    0xbe86dc50,// 22 MFM   2 

    0xec0a32bb,// 23 MFM   3 

    0xac7934f8,// 24 MFM   4 

    0xffcdeee9,// 25 MFM   5 

    0x86b3a1f9,// 26 MFM   6 

    0x5947843c,// 27 MFM   7 

    0xcf251f3c,// 28 MFM   8 

    0xc131e9fe,// 29 MFM   9 

    0xa44a236f,// 30 MFM  10 

    0xb6d00254,// 31 MFM  11 

    0x3ef1e5a8,// 32 MFM  12 

    0x12fd316c,// 33 MFM  13 

    0xd0d8d22f,// 34 MFM  14 

    0x29644e02,// 35 MFM  15 

    0xe3f437ad,// 36 MFM  16 

/// BDA is 372 words. 

/// BDA size     is 1481 (0x5c9) 

/// BDA id       is 0xa0be 

    0x05c9a0be,// 37 BDA   1 

/// PAY Generic Data size   : 1481 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x7315097e,// 38 PAY   1 

    0xe72f8d85,// 39 PAY   2 

    0x94b70bd2,// 40 PAY   3 

    0x3b88602d,// 41 PAY   4 

    0xbd285e81,// 42 PAY   5 

    0x69f3e9bd,// 43 PAY   6 

    0x9bdf9754,// 44 PAY   7 

    0xd2b9db87,// 45 PAY   8 

    0xa2860402,// 46 PAY   9 

    0x17d16007,// 47 PAY  10 

    0xe43b1d1e,// 48 PAY  11 

    0x59a031ad,// 49 PAY  12 

    0x82d9b4cc,// 50 PAY  13 

    0x9780a35c,// 51 PAY  14 

    0xa08f245f,// 52 PAY  15 

    0xbac0d4f5,// 53 PAY  16 

    0xa7e60765,// 54 PAY  17 

    0x0e7023d9,// 55 PAY  18 

    0x59ae43e5,// 56 PAY  19 

    0x14dc53d9,// 57 PAY  20 

    0xb803ea3e,// 58 PAY  21 

    0x8260d4bc,// 59 PAY  22 

    0xcb996224,// 60 PAY  23 

    0x89eb6c34,// 61 PAY  24 

    0x58997201,// 62 PAY  25 

    0x594724d6,// 63 PAY  26 

    0x051dc8b1,// 64 PAY  27 

    0xd46ebad7,// 65 PAY  28 

    0x12e42241,// 66 PAY  29 

    0xc55948f6,// 67 PAY  30 

    0x3325265d,// 68 PAY  31 

    0x36961964,// 69 PAY  32 

    0xdd756f37,// 70 PAY  33 

    0x2d986d2b,// 71 PAY  34 

    0xd9c09370,// 72 PAY  35 

    0x62ca018c,// 73 PAY  36 

    0xf098a446,// 74 PAY  37 

    0x38b59c0a,// 75 PAY  38 

    0xc7b99249,// 76 PAY  39 

    0x83b0c8b5,// 77 PAY  40 

    0x55a4cc5f,// 78 PAY  41 

    0x6e96cb92,// 79 PAY  42 

    0x9aa9f9f9,// 80 PAY  43 

    0x5c8daf86,// 81 PAY  44 

    0xcf1a7c20,// 82 PAY  45 

    0xc8b1b60d,// 83 PAY  46 

    0x0c2b554c,// 84 PAY  47 

    0x8410e312,// 85 PAY  48 

    0x308ba223,// 86 PAY  49 

    0x32cb46a0,// 87 PAY  50 

    0x299dbedc,// 88 PAY  51 

    0xfcadb498,// 89 PAY  52 

    0x8ca4e92b,// 90 PAY  53 

    0xd7dee074,// 91 PAY  54 

    0x36d17fff,// 92 PAY  55 

    0xcbe2ef57,// 93 PAY  56 

    0x3017080d,// 94 PAY  57 

    0x119ef9ff,// 95 PAY  58 

    0x2299459a,// 96 PAY  59 

    0x199d48c2,// 97 PAY  60 

    0x0eb7257d,// 98 PAY  61 

    0x77a8baf3,// 99 PAY  62 

    0xf9e762f1,// 100 PAY  63 

    0xba5affb5,// 101 PAY  64 

    0x2354a2b3,// 102 PAY  65 

    0x00ee7e71,// 103 PAY  66 

    0xd92857a6,// 104 PAY  67 

    0x53fc7e6c,// 105 PAY  68 

    0xdb118f31,// 106 PAY  69 

    0xc6e88ea5,// 107 PAY  70 

    0x49a46a37,// 108 PAY  71 

    0x09d65013,// 109 PAY  72 

    0x9ec41a7d,// 110 PAY  73 

    0x2bb83801,// 111 PAY  74 

    0x1b5ce2d8,// 112 PAY  75 

    0x41996c8b,// 113 PAY  76 

    0x92d91835,// 114 PAY  77 

    0x0fe74866,// 115 PAY  78 

    0xd1276cf8,// 116 PAY  79 

    0x900590eb,// 117 PAY  80 

    0x8da2f86e,// 118 PAY  81 

    0x69d45ef1,// 119 PAY  82 

    0xe04c2017,// 120 PAY  83 

    0xdb8189c2,// 121 PAY  84 

    0x5ba0bfbe,// 122 PAY  85 

    0x7e29548b,// 123 PAY  86 

    0x55c6eb23,// 124 PAY  87 

    0x28baaa31,// 125 PAY  88 

    0xd7ca024a,// 126 PAY  89 

    0x53475973,// 127 PAY  90 

    0xad06c8fe,// 128 PAY  91 

    0x74314507,// 129 PAY  92 

    0x565c7098,// 130 PAY  93 

    0xf23663d5,// 131 PAY  94 

    0x2ec1522d,// 132 PAY  95 

    0x50ad5217,// 133 PAY  96 

    0xbac8755a,// 134 PAY  97 

    0xfa368c76,// 135 PAY  98 

    0x222e87a5,// 136 PAY  99 

    0x1bfa97cb,// 137 PAY 100 

    0xb91986a6,// 138 PAY 101 

    0x963cd0a8,// 139 PAY 102 

    0x0200d3ac,// 140 PAY 103 

    0x23b258a1,// 141 PAY 104 

    0x97e29b1f,// 142 PAY 105 

    0x2ff73a01,// 143 PAY 106 

    0x5d7611c9,// 144 PAY 107 

    0xe1a29d69,// 145 PAY 108 

    0xb3896a57,// 146 PAY 109 

    0xac3eaee2,// 147 PAY 110 

    0x71f0872f,// 148 PAY 111 

    0x0268da8a,// 149 PAY 112 

    0xf50149de,// 150 PAY 113 

    0x5e7a4aa2,// 151 PAY 114 

    0x722fcf4c,// 152 PAY 115 

    0xc5a32e60,// 153 PAY 116 

    0x34f939e5,// 154 PAY 117 

    0x705ae970,// 155 PAY 118 

    0x9a372907,// 156 PAY 119 

    0x29e27d61,// 157 PAY 120 

    0x54573dbb,// 158 PAY 121 

    0x0e7fe132,// 159 PAY 122 

    0xd0469e63,// 160 PAY 123 

    0x180cf2b0,// 161 PAY 124 

    0xf9a72977,// 162 PAY 125 

    0xd27d37d0,// 163 PAY 126 

    0xd4ac9d1a,// 164 PAY 127 

    0x77fbbaab,// 165 PAY 128 

    0xdb00e757,// 166 PAY 129 

    0x40ac1a0f,// 167 PAY 130 

    0x9da9588f,// 168 PAY 131 

    0xa8455ca3,// 169 PAY 132 

    0x538b7fe3,// 170 PAY 133 

    0x4e16ed52,// 171 PAY 134 

    0x86e7b7ed,// 172 PAY 135 

    0xc7ab0d6e,// 173 PAY 136 

    0xc3393b4d,// 174 PAY 137 

    0x33c0f2ed,// 175 PAY 138 

    0x494459f6,// 176 PAY 139 

    0x231c41e7,// 177 PAY 140 

    0xe449232b,// 178 PAY 141 

    0xc02f774f,// 179 PAY 142 

    0xc4c57af5,// 180 PAY 143 

    0xda5a6408,// 181 PAY 144 

    0x0f979424,// 182 PAY 145 

    0x9d7659b7,// 183 PAY 146 

    0x9e8edfa1,// 184 PAY 147 

    0x18e3a303,// 185 PAY 148 

    0x9a5e71a9,// 186 PAY 149 

    0x7935e6b4,// 187 PAY 150 

    0x1db9db8b,// 188 PAY 151 

    0x76002205,// 189 PAY 152 

    0x56601a3a,// 190 PAY 153 

    0x3e406b2f,// 191 PAY 154 

    0xcb9ba5f5,// 192 PAY 155 

    0xe50d0b97,// 193 PAY 156 

    0xdabc4026,// 194 PAY 157 

    0x9ca6bc5c,// 195 PAY 158 

    0x691f84b6,// 196 PAY 159 

    0x79f67535,// 197 PAY 160 

    0x2ea16c0b,// 198 PAY 161 

    0x279d2b06,// 199 PAY 162 

    0xbf3a801c,// 200 PAY 163 

    0x45bf0f16,// 201 PAY 164 

    0xb10e4de8,// 202 PAY 165 

    0xbc8f63df,// 203 PAY 166 

    0x05bf2ba1,// 204 PAY 167 

    0xbdda616a,// 205 PAY 168 

    0xec1cf311,// 206 PAY 169 

    0x04cb59af,// 207 PAY 170 

    0xa848baaf,// 208 PAY 171 

    0xbe4e1ca3,// 209 PAY 172 

    0x58398a48,// 210 PAY 173 

    0x0fdd6bd6,// 211 PAY 174 

    0x14d1c818,// 212 PAY 175 

    0xd7a8765f,// 213 PAY 176 

    0x23aaf16b,// 214 PAY 177 

    0x1419240a,// 215 PAY 178 

    0xa0ea66c5,// 216 PAY 179 

    0x91c2f33c,// 217 PAY 180 

    0xb01aae80,// 218 PAY 181 

    0x9b39e47c,// 219 PAY 182 

    0x36cec22f,// 220 PAY 183 

    0x8664581c,// 221 PAY 184 

    0xb3ea1a58,// 222 PAY 185 

    0x44b91cfb,// 223 PAY 186 

    0x8ea1005c,// 224 PAY 187 

    0x4c4e3662,// 225 PAY 188 

    0x1c063a8c,// 226 PAY 189 

    0xdd9a4888,// 227 PAY 190 

    0x205c4dbd,// 228 PAY 191 

    0x85dedfc6,// 229 PAY 192 

    0xf7ad661a,// 230 PAY 193 

    0x33e21ddd,// 231 PAY 194 

    0x97a041aa,// 232 PAY 195 

    0x067ac870,// 233 PAY 196 

    0x3f4bda2c,// 234 PAY 197 

    0xc515e98f,// 235 PAY 198 

    0x1396a715,// 236 PAY 199 

    0xbc3ac6e9,// 237 PAY 200 

    0xdd7ea8a8,// 238 PAY 201 

    0xd2d7c14b,// 239 PAY 202 

    0x90037ccf,// 240 PAY 203 

    0xf06688ba,// 241 PAY 204 

    0x51025a28,// 242 PAY 205 

    0xf24c2cb6,// 243 PAY 206 

    0xc1461b90,// 244 PAY 207 

    0xdd949721,// 245 PAY 208 

    0xa497a089,// 246 PAY 209 

    0x94f48e47,// 247 PAY 210 

    0x9e21527a,// 248 PAY 211 

    0xd6e91437,// 249 PAY 212 

    0xa4f89f16,// 250 PAY 213 

    0x1fff154f,// 251 PAY 214 

    0xebdd0c7a,// 252 PAY 215 

    0x921b2af8,// 253 PAY 216 

    0x1906f19c,// 254 PAY 217 

    0xe8318ee3,// 255 PAY 218 

    0xe93aa7f6,// 256 PAY 219 

    0xf4fe48d5,// 257 PAY 220 

    0x0f9b7b95,// 258 PAY 221 

    0x0f6b9859,// 259 PAY 222 

    0xf83167f3,// 260 PAY 223 

    0x3a362e2a,// 261 PAY 224 

    0xd720cabd,// 262 PAY 225 

    0xd3e8052a,// 263 PAY 226 

    0x12362c33,// 264 PAY 227 

    0x2797c1ca,// 265 PAY 228 

    0x0323a598,// 266 PAY 229 

    0x69a22c37,// 267 PAY 230 

    0x949fce74,// 268 PAY 231 

    0x7012f8e2,// 269 PAY 232 

    0x7524547c,// 270 PAY 233 

    0xa15ab73d,// 271 PAY 234 

    0xd80786db,// 272 PAY 235 

    0x4e701f03,// 273 PAY 236 

    0x0495ebf6,// 274 PAY 237 

    0xe7245316,// 275 PAY 238 

    0x619c7f13,// 276 PAY 239 

    0x82549745,// 277 PAY 240 

    0x23868c3e,// 278 PAY 241 

    0x9896bea4,// 279 PAY 242 

    0x38be4079,// 280 PAY 243 

    0x2fdde9a1,// 281 PAY 244 

    0x4f1635f8,// 282 PAY 245 

    0x108df2c9,// 283 PAY 246 

    0xa7cc977c,// 284 PAY 247 

    0x7ef94b7e,// 285 PAY 248 

    0xe154a60c,// 286 PAY 249 

    0xa1a1b518,// 287 PAY 250 

    0x29515165,// 288 PAY 251 

    0x3ee6b087,// 289 PAY 252 

    0xa96946f6,// 290 PAY 253 

    0xee4984ad,// 291 PAY 254 

    0x570cb07c,// 292 PAY 255 

    0xd3d0f9dd,// 293 PAY 256 

    0x2feb8a64,// 294 PAY 257 

    0x21ef9e54,// 295 PAY 258 

    0x67c010ec,// 296 PAY 259 

    0x8c0ceee0,// 297 PAY 260 

    0xa8b0f22e,// 298 PAY 261 

    0x8e058da7,// 299 PAY 262 

    0x0b342d97,// 300 PAY 263 

    0x4a3dbee5,// 301 PAY 264 

    0x34dc77a2,// 302 PAY 265 

    0x95603532,// 303 PAY 266 

    0xd411b107,// 304 PAY 267 

    0x92edff7e,// 305 PAY 268 

    0xd79a8317,// 306 PAY 269 

    0x84cb9d5b,// 307 PAY 270 

    0x75d4aa1b,// 308 PAY 271 

    0x3d5ec802,// 309 PAY 272 

    0x6200b497,// 310 PAY 273 

    0xe9d1a871,// 311 PAY 274 

    0x31a8d92b,// 312 PAY 275 

    0xf474efb1,// 313 PAY 276 

    0x7e2f4edb,// 314 PAY 277 

    0xa548692a,// 315 PAY 278 

    0xf77cb740,// 316 PAY 279 

    0x91b5e023,// 317 PAY 280 

    0xa61eacb3,// 318 PAY 281 

    0xfe49595a,// 319 PAY 282 

    0x3e14d137,// 320 PAY 283 

    0xcfa3cedc,// 321 PAY 284 

    0xb2dcd91c,// 322 PAY 285 

    0x7ef2febb,// 323 PAY 286 

    0xb423e019,// 324 PAY 287 

    0x4a384150,// 325 PAY 288 

    0x35cee008,// 326 PAY 289 

    0xcf88b506,// 327 PAY 290 

    0x47c41ce0,// 328 PAY 291 

    0xd83e5e2b,// 329 PAY 292 

    0x229c4372,// 330 PAY 293 

    0xa3c68245,// 331 PAY 294 

    0x77842a2f,// 332 PAY 295 

    0x330b0364,// 333 PAY 296 

    0xa318ee51,// 334 PAY 297 

    0x0f9a9c0b,// 335 PAY 298 

    0x6cc04d6f,// 336 PAY 299 

    0x695f2010,// 337 PAY 300 

    0xe410f69b,// 338 PAY 301 

    0xe15cabf9,// 339 PAY 302 

    0x2733b41f,// 340 PAY 303 

    0xa99492ae,// 341 PAY 304 

    0x47863562,// 342 PAY 305 

    0x8d173679,// 343 PAY 306 

    0x06a8b866,// 344 PAY 307 

    0x1d1e11c8,// 345 PAY 308 

    0x4cd5adc5,// 346 PAY 309 

    0x252bcd8e,// 347 PAY 310 

    0x12551594,// 348 PAY 311 

    0x5eabefb3,// 349 PAY 312 

    0x9ec04168,// 350 PAY 313 

    0x5491c57e,// 351 PAY 314 

    0xea352bbf,// 352 PAY 315 

    0xe688d726,// 353 PAY 316 

    0x6e3edd22,// 354 PAY 317 

    0xe06861ae,// 355 PAY 318 

    0x324ecec4,// 356 PAY 319 

    0x083266cc,// 357 PAY 320 

    0x94c0b34d,// 358 PAY 321 

    0x5d3eb7dd,// 359 PAY 322 

    0x49b8ad09,// 360 PAY 323 

    0x2d34e797,// 361 PAY 324 

    0x6d237550,// 362 PAY 325 

    0x16137859,// 363 PAY 326 

    0x638c76bf,// 364 PAY 327 

    0xb68bdc20,// 365 PAY 328 

    0xa9e0c1fc,// 366 PAY 329 

    0x16af5290,// 367 PAY 330 

    0xfad0e040,// 368 PAY 331 

    0x4d7117fc,// 369 PAY 332 

    0xad76ed0e,// 370 PAY 333 

    0x52ac3ca3,// 371 PAY 334 

    0x9cfa711a,// 372 PAY 335 

    0x06ba1d61,// 373 PAY 336 

    0x171d9438,// 374 PAY 337 

    0x1136e9e4,// 375 PAY 338 

    0xc8bf672a,// 376 PAY 339 

    0xc84ddbf0,// 377 PAY 340 

    0x50aa7dea,// 378 PAY 341 

    0xe7fab572,// 379 PAY 342 

    0x4488688c,// 380 PAY 343 

    0x566ade33,// 381 PAY 344 

    0x04b6b263,// 382 PAY 345 

    0xf8bbf3d7,// 383 PAY 346 

    0x294ebfed,// 384 PAY 347 

    0x49694676,// 385 PAY 348 

    0xe17145dd,// 386 PAY 349 

    0x795993cb,// 387 PAY 350 

    0x1093867c,// 388 PAY 351 

    0xd5471a81,// 389 PAY 352 

    0xf0705c8e,// 390 PAY 353 

    0x999e2a9e,// 391 PAY 354 

    0x94730033,// 392 PAY 355 

    0xfb580dd8,// 393 PAY 356 

    0x1fe3bf69,// 394 PAY 357 

    0x59841b14,// 395 PAY 358 

    0xc428db12,// 396 PAY 359 

    0xfca66c24,// 397 PAY 360 

    0x9250c07a,// 398 PAY 361 

    0x63746feb,// 399 PAY 362 

    0x90817ea6,// 400 PAY 363 

    0xfd5a283f,// 401 PAY 364 

    0x95411166,// 402 PAY 365 

    0x50ead699,// 403 PAY 366 

    0x4122cb6e,// 404 PAY 367 

    0x42b5993a,// 405 PAY 368 

    0x1e6551e9,// 406 PAY 369 

    0xcba0a303,// 407 PAY 370 

    0x1b000000,// 408 PAY 371 

/// STA is 1 words. 

/// STA num_pkts       : 111 

/// STA pkt_idx        : 124 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x4d 

    0x01f04d6f // 409 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt75_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x02 

/// ECH pdu_tag        : 0x00 

    0x00020000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x80922898,// 4 SCX   2 

    0x00003482,// 5 SCX   3 

    0x032691ce,// 6 SCX   4 

    0x61556187,// 7 SCX   5 

    0x99f72ba2,// 8 SCX   6 

    0x1d982586,// 9 SCX   7 

    0x5edc1e2f,// 10 SCX   8 

    0x684aa6b4,// 11 SCX   9 

    0xb597d8b1,// 12 SCX  10 

    0x47af6c14,// 13 SCX  11 

    0xe301e4b5,// 14 SCX  12 

    0x257520e6,// 15 SCX  13 

    0x9004011e,// 16 SCX  14 

    0xb29d66a3,// 17 SCX  15 

    0x257dead4,// 18 SCX  16 

    0x77bd714f,// 19 SCX  17 

    0xceb39b2a,// 20 SCX  18 

    0x4ceb23ed,// 21 SCX  19 

    0xc4de7c3e,// 22 SCX  20 

    0x843134b0,// 23 SCX  21 

    0x0940ac50,// 24 SCX  22 

    0x25fa5d4c,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 870 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 213 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 213 

/// BFD lencrypto      : 16 

/// BFD ofstcrypto     : 188 

/// BFD (ofst+len)cry  : 204 

/// BFD ofstiv         : 140 

/// BFD ofsticv        : 436 

    0x000000d5,// 26 BFD   1 

    0x00bc0010,// 27 BFD   2 

    0x01b4008c,// 28 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 8 

    0x080057ef,// 29 MFM   1 

    0xed610000,// 30 MFM   2 

/// BDA is 219 words. 

/// BDA size     is 870 (0x366) 

/// BDA id       is 0xec5d 

    0x0366ec5d,// 31 BDA   1 

/// PAY Generic Data size   : 870 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x29a42481,// 32 PAY   1 

    0x4d27ff2d,// 33 PAY   2 

    0xdce56b9c,// 34 PAY   3 

    0x5b6e42ce,// 35 PAY   4 

    0x59309030,// 36 PAY   5 

    0x48a5d4ba,// 37 PAY   6 

    0xc7d670a0,// 38 PAY   7 

    0xb83d96dc,// 39 PAY   8 

    0x282878d1,// 40 PAY   9 

    0x733c0f4a,// 41 PAY  10 

    0xf923e892,// 42 PAY  11 

    0xaa0ef708,// 43 PAY  12 

    0xa57c7787,// 44 PAY  13 

    0xb57936e4,// 45 PAY  14 

    0x218da0aa,// 46 PAY  15 

    0x2b156a7f,// 47 PAY  16 

    0xd9ef9a97,// 48 PAY  17 

    0xb9ac02a9,// 49 PAY  18 

    0xb47cbbbb,// 50 PAY  19 

    0xac6b5fe8,// 51 PAY  20 

    0xff30d560,// 52 PAY  21 

    0xf6bf8b66,// 53 PAY  22 

    0xd100e96a,// 54 PAY  23 

    0x19c05107,// 55 PAY  24 

    0x8bb5ea26,// 56 PAY  25 

    0x51b00bd2,// 57 PAY  26 

    0xc58557e4,// 58 PAY  27 

    0xe379239c,// 59 PAY  28 

    0x1167157d,// 60 PAY  29 

    0x14d517b0,// 61 PAY  30 

    0x8f0700fd,// 62 PAY  31 

    0x8b2d9e48,// 63 PAY  32 

    0x30797c37,// 64 PAY  33 

    0x3aa817f4,// 65 PAY  34 

    0x47c14a0e,// 66 PAY  35 

    0xe0216858,// 67 PAY  36 

    0xa7dd5e73,// 68 PAY  37 

    0x874fe438,// 69 PAY  38 

    0xb1129080,// 70 PAY  39 

    0x980dab0b,// 71 PAY  40 

    0x1fac6909,// 72 PAY  41 

    0x4b5e5f12,// 73 PAY  42 

    0x42739e78,// 74 PAY  43 

    0x029f6d63,// 75 PAY  44 

    0x4055a2b2,// 76 PAY  45 

    0x1bdf9297,// 77 PAY  46 

    0xa65fc2dc,// 78 PAY  47 

    0xbb3fc69e,// 79 PAY  48 

    0x7ce48f22,// 80 PAY  49 

    0xb80a89f6,// 81 PAY  50 

    0x50f6daa5,// 82 PAY  51 

    0xf4d16519,// 83 PAY  52 

    0x5c721db2,// 84 PAY  53 

    0x63fc2a3e,// 85 PAY  54 

    0x856e31e5,// 86 PAY  55 

    0xf23b95eb,// 87 PAY  56 

    0x6adb0942,// 88 PAY  57 

    0xe7a1c534,// 89 PAY  58 

    0xd88ce8c3,// 90 PAY  59 

    0x4a8835cd,// 91 PAY  60 

    0x649757a4,// 92 PAY  61 

    0x09359d39,// 93 PAY  62 

    0xe3f3fa1f,// 94 PAY  63 

    0xb6db107d,// 95 PAY  64 

    0xc17ed348,// 96 PAY  65 

    0xcb50442e,// 97 PAY  66 

    0x25e8d736,// 98 PAY  67 

    0xe9acd502,// 99 PAY  68 

    0x0fdf8cfa,// 100 PAY  69 

    0x6e8f30da,// 101 PAY  70 

    0x58187263,// 102 PAY  71 

    0x09debf14,// 103 PAY  72 

    0x593f2def,// 104 PAY  73 

    0xe2d02e39,// 105 PAY  74 

    0x9f9d6d7e,// 106 PAY  75 

    0x6650491e,// 107 PAY  76 

    0x2635b79d,// 108 PAY  77 

    0xab7e90eb,// 109 PAY  78 

    0x8e119e1d,// 110 PAY  79 

    0x60c070c5,// 111 PAY  80 

    0x454d54f2,// 112 PAY  81 

    0x369000fe,// 113 PAY  82 

    0x4b96fdda,// 114 PAY  83 

    0xf1125a51,// 115 PAY  84 

    0x30dcf55b,// 116 PAY  85 

    0xb9a207c4,// 117 PAY  86 

    0xc8c9e3d8,// 118 PAY  87 

    0xfcf5f07e,// 119 PAY  88 

    0x5cbdc94b,// 120 PAY  89 

    0x4e5e51f4,// 121 PAY  90 

    0x82b72e84,// 122 PAY  91 

    0x31ec8c8f,// 123 PAY  92 

    0xa098be60,// 124 PAY  93 

    0x155cde0b,// 125 PAY  94 

    0x7bc9d511,// 126 PAY  95 

    0xdfffd7c3,// 127 PAY  96 

    0xafa3cf61,// 128 PAY  97 

    0x03652780,// 129 PAY  98 

    0x8b296bf3,// 130 PAY  99 

    0x26844df6,// 131 PAY 100 

    0x90f73ce9,// 132 PAY 101 

    0x38ad34e7,// 133 PAY 102 

    0xe8fe61f4,// 134 PAY 103 

    0x896f79cb,// 135 PAY 104 

    0x9fc9e4a4,// 136 PAY 105 

    0x32205cad,// 137 PAY 106 

    0x8f010d42,// 138 PAY 107 

    0x04c4a0e7,// 139 PAY 108 

    0x40e35df3,// 140 PAY 109 

    0x6770cfaa,// 141 PAY 110 

    0x7284998a,// 142 PAY 111 

    0x32aeec8a,// 143 PAY 112 

    0xd8aaad02,// 144 PAY 113 

    0x95c5cc85,// 145 PAY 114 

    0xf1ab8ef0,// 146 PAY 115 

    0xc9bc788b,// 147 PAY 116 

    0x00ca02b4,// 148 PAY 117 

    0x19e631f6,// 149 PAY 118 

    0x808039ed,// 150 PAY 119 

    0x58597b2d,// 151 PAY 120 

    0xb9e63dec,// 152 PAY 121 

    0xe79ba792,// 153 PAY 122 

    0x193a98e4,// 154 PAY 123 

    0x0185e734,// 155 PAY 124 

    0xffb1b515,// 156 PAY 125 

    0x1117e0d8,// 157 PAY 126 

    0x4119eefe,// 158 PAY 127 

    0xe000ec93,// 159 PAY 128 

    0xacddf1f1,// 160 PAY 129 

    0x6cdb5a68,// 161 PAY 130 

    0x318954e4,// 162 PAY 131 

    0x27cb669d,// 163 PAY 132 

    0x7a51aa2b,// 164 PAY 133 

    0x9705d3df,// 165 PAY 134 

    0x2694cd72,// 166 PAY 135 

    0xa0fcc600,// 167 PAY 136 

    0xccd94411,// 168 PAY 137 

    0xdff2e8e0,// 169 PAY 138 

    0xebc87e88,// 170 PAY 139 

    0xe415feac,// 171 PAY 140 

    0xf9164741,// 172 PAY 141 

    0xa80090f3,// 173 PAY 142 

    0x82089177,// 174 PAY 143 

    0x1327e04e,// 175 PAY 144 

    0x84910e1c,// 176 PAY 145 

    0x7a93344c,// 177 PAY 146 

    0x92919e9b,// 178 PAY 147 

    0x6a4fe762,// 179 PAY 148 

    0x0d501787,// 180 PAY 149 

    0xf7f00a73,// 181 PAY 150 

    0x6e270bc8,// 182 PAY 151 

    0xe65f869e,// 183 PAY 152 

    0x4f2ab923,// 184 PAY 153 

    0x33c9322a,// 185 PAY 154 

    0xa4d96969,// 186 PAY 155 

    0x8dad229b,// 187 PAY 156 

    0xe6baaf19,// 188 PAY 157 

    0xc3590822,// 189 PAY 158 

    0x641ecc02,// 190 PAY 159 

    0x89f9cc60,// 191 PAY 160 

    0x31ef92ae,// 192 PAY 161 

    0xebc28077,// 193 PAY 162 

    0xe8c36d02,// 194 PAY 163 

    0x02af50a4,// 195 PAY 164 

    0x02379e75,// 196 PAY 165 

    0xec882d29,// 197 PAY 166 

    0xedfc20d6,// 198 PAY 167 

    0x193a46b6,// 199 PAY 168 

    0xe152f48f,// 200 PAY 169 

    0xb614b718,// 201 PAY 170 

    0xda96321f,// 202 PAY 171 

    0xff2c0631,// 203 PAY 172 

    0x2dca2849,// 204 PAY 173 

    0x45804a72,// 205 PAY 174 

    0xe939a65a,// 206 PAY 175 

    0xb225ca09,// 207 PAY 176 

    0x6c906495,// 208 PAY 177 

    0x4055e408,// 209 PAY 178 

    0xbde3b7a4,// 210 PAY 179 

    0xb33d552a,// 211 PAY 180 

    0xaa56404f,// 212 PAY 181 

    0x62c902b8,// 213 PAY 182 

    0x75841cc2,// 214 PAY 183 

    0x91f118d9,// 215 PAY 184 

    0xcd6ac39b,// 216 PAY 185 

    0xdc6bfaa1,// 217 PAY 186 

    0xa7e3a5f1,// 218 PAY 187 

    0x67da098f,// 219 PAY 188 

    0x675e03fc,// 220 PAY 189 

    0x132567c8,// 221 PAY 190 

    0x9bb4c358,// 222 PAY 191 

    0xd6256d53,// 223 PAY 192 

    0xf4c279fb,// 224 PAY 193 

    0xe6f8814c,// 225 PAY 194 

    0xe051f52e,// 226 PAY 195 

    0xb3a2d05c,// 227 PAY 196 

    0x20b625f3,// 228 PAY 197 

    0xdd497ed5,// 229 PAY 198 

    0xfe7de7bd,// 230 PAY 199 

    0xbaab08a2,// 231 PAY 200 

    0x09d8d62b,// 232 PAY 201 

    0x09cdbacb,// 233 PAY 202 

    0x1c948014,// 234 PAY 203 

    0x7eabce81,// 235 PAY 204 

    0xbdd34667,// 236 PAY 205 

    0x6d128835,// 237 PAY 206 

    0x34933532,// 238 PAY 207 

    0xec2f07df,// 239 PAY 208 

    0x397db6f8,// 240 PAY 209 

    0x26214287,// 241 PAY 210 

    0xe84ca959,// 242 PAY 211 

    0x85655109,// 243 PAY 212 

    0xaf926b40,// 244 PAY 213 

    0x0e45acc4,// 245 PAY 214 

    0xb7fe7dfe,// 246 PAY 215 

    0xd360bda9,// 247 PAY 216 

    0x225efab7,// 248 PAY 217 

    0xe4320000,// 249 PAY 218 

/// STA is 1 words. 

/// STA num_pkts       : 147 

/// STA pkt_idx        : 180 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x96 

    0x02d09693 // 250 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt76_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x05 

/// ECH pdu_tag        : 0x00 

    0x00050000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x8080283a,// 4 SCX   2 

    0x00001400,// 5 SCX   3 

    0x90241325,// 6 SCX   4 

    0x785e483b,// 7 SCX   5 

    0x5c936625,// 8 SCX   6 

    0x51525c06,// 9 SCX   7 

    0xf4abe146,// 10 SCX   8 

    0x176e0403,// 11 SCX   9 

    0xed87a02c,// 12 SCX  10 

    0xd9e503bf,// 13 SCX  11 

    0x9b274780,// 14 SCX  12 

    0x96efac3a,// 15 SCX  13 

    0xaa472b78,// 16 SCX  14 

    0xc021cf6f,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 1247 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 313 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 313 

/// BFD lencrypto      : 176 

/// BFD ofstcrypto     : 32 

/// BFD (ofst+len)cry  : 208 

/// BFD ofstiv         : 4 

/// BFD ofsticv        : 532 

    0x00000139,// 18 BFD   1 

    0x002000b0,// 19 BFD   2 

    0x02140004,// 20 BFD   3 

/// MFM is 7 words. 

/// MFM vldnibs        : 30 

    0x30004229,// 21 MFM   1 

    0xe914abd8,// 22 MFM   2 

    0x902f7b73,// 23 MFM   3 

    0xf29d8b47,// 24 MFM   4 

    0x525a8c73,// 25 MFM   5 

    0x3972c6a4,// 26 MFM   6 

    0x02930000,// 27 MFM   7 

/// BDA is 313 words. 

/// BDA size     is 1247 (0x4df) 

/// BDA id       is 0xd76a 

    0x04dfd76a,// 28 BDA   1 

/// PAY Generic Data size   : 1247 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0x8e3d3439,// 29 PAY   1 

    0x883c6f0c,// 30 PAY   2 

    0x6ca6560a,// 31 PAY   3 

    0x3cc909e3,// 32 PAY   4 

    0xbc8fe09e,// 33 PAY   5 

    0x90a8bf78,// 34 PAY   6 

    0x699dcc08,// 35 PAY   7 

    0x5612cd75,// 36 PAY   8 

    0x41eee760,// 37 PAY   9 

    0x6df7dbd9,// 38 PAY  10 

    0x199227c8,// 39 PAY  11 

    0x70b238d9,// 40 PAY  12 

    0xa669e21b,// 41 PAY  13 

    0xf03e66f0,// 42 PAY  14 

    0x0f9d42a7,// 43 PAY  15 

    0xce38601c,// 44 PAY  16 

    0x5f6c7603,// 45 PAY  17 

    0x61f80125,// 46 PAY  18 

    0xaed13efb,// 47 PAY  19 

    0xf91b6968,// 48 PAY  20 

    0x6268b934,// 49 PAY  21 

    0xb833465c,// 50 PAY  22 

    0x8d967206,// 51 PAY  23 

    0x7c1dfaca,// 52 PAY  24 

    0xfbc16296,// 53 PAY  25 

    0x770be741,// 54 PAY  26 

    0x354177c2,// 55 PAY  27 

    0x099fa2d8,// 56 PAY  28 

    0x244cdaa0,// 57 PAY  29 

    0x79b90020,// 58 PAY  30 

    0x0328159b,// 59 PAY  31 

    0x8be74d91,// 60 PAY  32 

    0x93178718,// 61 PAY  33 

    0x86e00e76,// 62 PAY  34 

    0x92886090,// 63 PAY  35 

    0x1d2a9ab4,// 64 PAY  36 

    0x28b6157d,// 65 PAY  37 

    0x58cb4f1d,// 66 PAY  38 

    0x235894f0,// 67 PAY  39 

    0x5d9dae83,// 68 PAY  40 

    0x6707ad89,// 69 PAY  41 

    0x3282a973,// 70 PAY  42 

    0x6a8fef95,// 71 PAY  43 

    0x39f7e149,// 72 PAY  44 

    0xdb0be002,// 73 PAY  45 

    0x411b67cf,// 74 PAY  46 

    0x464f4aca,// 75 PAY  47 

    0x0ae6beaf,// 76 PAY  48 

    0xfdc5057e,// 77 PAY  49 

    0x3d5194a8,// 78 PAY  50 

    0xc6e1b8ab,// 79 PAY  51 

    0xf1b1fcb9,// 80 PAY  52 

    0x3ee5970a,// 81 PAY  53 

    0xd201b36c,// 82 PAY  54 

    0x4f11bdef,// 83 PAY  55 

    0xb1191293,// 84 PAY  56 

    0xbeda3842,// 85 PAY  57 

    0x030f1b0b,// 86 PAY  58 

    0x11bd7650,// 87 PAY  59 

    0x375203f5,// 88 PAY  60 

    0x504fa5ea,// 89 PAY  61 

    0xee5c6649,// 90 PAY  62 

    0x3bb7ff3a,// 91 PAY  63 

    0x15e554d9,// 92 PAY  64 

    0x3522aefd,// 93 PAY  65 

    0x6e13b2c7,// 94 PAY  66 

    0x114be5ab,// 95 PAY  67 

    0x40ace4fc,// 96 PAY  68 

    0xa1a2723b,// 97 PAY  69 

    0x88b3da3a,// 98 PAY  70 

    0x8ea39e52,// 99 PAY  71 

    0x5f5d8290,// 100 PAY  72 

    0x26b8969c,// 101 PAY  73 

    0x1faf59f4,// 102 PAY  74 

    0x2ddf1acc,// 103 PAY  75 

    0x5a92d801,// 104 PAY  76 

    0x9c38897b,// 105 PAY  77 

    0x749a2521,// 106 PAY  78 

    0x4dbb4fc6,// 107 PAY  79 

    0xb04b5bfd,// 108 PAY  80 

    0xd9d7d590,// 109 PAY  81 

    0xea2e48bb,// 110 PAY  82 

    0x6885c108,// 111 PAY  83 

    0x65294ced,// 112 PAY  84 

    0x6c8be1b7,// 113 PAY  85 

    0x3007ac7e,// 114 PAY  86 

    0xacc53174,// 115 PAY  87 

    0xc44e2672,// 116 PAY  88 

    0x79aa7101,// 117 PAY  89 

    0x5e2b9a61,// 118 PAY  90 

    0x157873db,// 119 PAY  91 

    0xb5f9b1e0,// 120 PAY  92 

    0xebd9dfa9,// 121 PAY  93 

    0x74fd9937,// 122 PAY  94 

    0x0a1b2c33,// 123 PAY  95 

    0xfc932084,// 124 PAY  96 

    0x4c075bdf,// 125 PAY  97 

    0xc3558a20,// 126 PAY  98 

    0xcda700cd,// 127 PAY  99 

    0xf8a0f3ec,// 128 PAY 100 

    0xf1a6b214,// 129 PAY 101 

    0x722fbc6c,// 130 PAY 102 

    0xdbf37a00,// 131 PAY 103 

    0x09c2434e,// 132 PAY 104 

    0xc714f3cc,// 133 PAY 105 

    0xfa0fb82d,// 134 PAY 106 

    0xc7b7d619,// 135 PAY 107 

    0x33037434,// 136 PAY 108 

    0x92fc8467,// 137 PAY 109 

    0x1a342875,// 138 PAY 110 

    0xe85aafe7,// 139 PAY 111 

    0x398c50e6,// 140 PAY 112 

    0xd3024423,// 141 PAY 113 

    0x7b01b4eb,// 142 PAY 114 

    0x96b9a6d0,// 143 PAY 115 

    0x19782474,// 144 PAY 116 

    0xc3b32ffe,// 145 PAY 117 

    0x0e3883db,// 146 PAY 118 

    0x3f38026d,// 147 PAY 119 

    0xe4b8703f,// 148 PAY 120 

    0x750fe484,// 149 PAY 121 

    0xb550fd68,// 150 PAY 122 

    0x305b7778,// 151 PAY 123 

    0x0d5ffaf1,// 152 PAY 124 

    0x31f95267,// 153 PAY 125 

    0xcd837f05,// 154 PAY 126 

    0x8dd49460,// 155 PAY 127 

    0x2f6088b9,// 156 PAY 128 

    0x168c0702,// 157 PAY 129 

    0x9e7ce4d3,// 158 PAY 130 

    0x401cfc87,// 159 PAY 131 

    0x3d371a6a,// 160 PAY 132 

    0x06c6fc32,// 161 PAY 133 

    0x0a024201,// 162 PAY 134 

    0x39dde6aa,// 163 PAY 135 

    0xec658750,// 164 PAY 136 

    0x5f67234c,// 165 PAY 137 

    0x7f4a1811,// 166 PAY 138 

    0x1abeb7d7,// 167 PAY 139 

    0x5ec8f571,// 168 PAY 140 

    0x5a1d13d7,// 169 PAY 141 

    0xdce1c05c,// 170 PAY 142 

    0xf545212e,// 171 PAY 143 

    0x48327e24,// 172 PAY 144 

    0x7031fc78,// 173 PAY 145 

    0x812804f9,// 174 PAY 146 

    0xb128b209,// 175 PAY 147 

    0x8eca133e,// 176 PAY 148 

    0x8e391398,// 177 PAY 149 

    0x0642ae4a,// 178 PAY 150 

    0x2b03acfd,// 179 PAY 151 

    0xa3c88df9,// 180 PAY 152 

    0x2c0746ef,// 181 PAY 153 

    0x107aff09,// 182 PAY 154 

    0xcf2a31b3,// 183 PAY 155 

    0xd8901bff,// 184 PAY 156 

    0x3ae098f8,// 185 PAY 157 

    0x1b5d5fe9,// 186 PAY 158 

    0xad1e6b76,// 187 PAY 159 

    0xf8f5241e,// 188 PAY 160 

    0xf95318d2,// 189 PAY 161 

    0xefcd6568,// 190 PAY 162 

    0xcdac554c,// 191 PAY 163 

    0xffce896e,// 192 PAY 164 

    0x9da1a8af,// 193 PAY 165 

    0x9529482b,// 194 PAY 166 

    0xbb00810e,// 195 PAY 167 

    0x569c2792,// 196 PAY 168 

    0x9e59d3a1,// 197 PAY 169 

    0x6a9f26bf,// 198 PAY 170 

    0xfebfac20,// 199 PAY 171 

    0x4502417d,// 200 PAY 172 

    0xbaf8de61,// 201 PAY 173 

    0xd8009212,// 202 PAY 174 

    0x5885bca8,// 203 PAY 175 

    0xc9647a60,// 204 PAY 176 

    0xb4493643,// 205 PAY 177 

    0x243d5ecc,// 206 PAY 178 

    0xdebc3d76,// 207 PAY 179 

    0x6f24e230,// 208 PAY 180 

    0x63bd8933,// 209 PAY 181 

    0x0b946ec6,// 210 PAY 182 

    0x83ef235e,// 211 PAY 183 

    0xaede92cc,// 212 PAY 184 

    0x7510d96c,// 213 PAY 185 

    0x65ff2e16,// 214 PAY 186 

    0xd36fdfd5,// 215 PAY 187 

    0xcdc3b1c5,// 216 PAY 188 

    0xda2f3bd6,// 217 PAY 189 

    0x5595aacf,// 218 PAY 190 

    0x4a2fed41,// 219 PAY 191 

    0x4d3768a5,// 220 PAY 192 

    0xa55eaacb,// 221 PAY 193 

    0x4ec9f68a,// 222 PAY 194 

    0x19a2368e,// 223 PAY 195 

    0xc8801f43,// 224 PAY 196 

    0x0927de40,// 225 PAY 197 

    0xc4ab8bd8,// 226 PAY 198 

    0x60dfe6a8,// 227 PAY 199 

    0x0a9ba76d,// 228 PAY 200 

    0x3715475d,// 229 PAY 201 

    0xa44eb991,// 230 PAY 202 

    0xea21eb45,// 231 PAY 203 

    0x289ab71b,// 232 PAY 204 

    0xd0c141ce,// 233 PAY 205 

    0x52982cb3,// 234 PAY 206 

    0x3dd1f213,// 235 PAY 207 

    0xdfde137e,// 236 PAY 208 

    0x42a3a472,// 237 PAY 209 

    0x31410465,// 238 PAY 210 

    0x3491fbe0,// 239 PAY 211 

    0x1c7491d2,// 240 PAY 212 

    0x4ffcac54,// 241 PAY 213 

    0x5033e5e0,// 242 PAY 214 

    0x8d516ba4,// 243 PAY 215 

    0x432bc37d,// 244 PAY 216 

    0xc5149b1d,// 245 PAY 217 

    0x8da90d64,// 246 PAY 218 

    0x312d5991,// 247 PAY 219 

    0x1a09df1c,// 248 PAY 220 

    0x8020b641,// 249 PAY 221 

    0x33e0d04a,// 250 PAY 222 

    0x9a3b48c3,// 251 PAY 223 

    0x3dca9bc4,// 252 PAY 224 

    0x5ed9c417,// 253 PAY 225 

    0x8d9b3e3a,// 254 PAY 226 

    0xaa226e02,// 255 PAY 227 

    0x99196241,// 256 PAY 228 

    0x6fed8bc0,// 257 PAY 229 

    0xc7223205,// 258 PAY 230 

    0xbc2b1411,// 259 PAY 231 

    0xaa0e8489,// 260 PAY 232 

    0x0dba8ee2,// 261 PAY 233 

    0xc07cd2a4,// 262 PAY 234 

    0xe6f59b47,// 263 PAY 235 

    0x9f0ca412,// 264 PAY 236 

    0x58685b4e,// 265 PAY 237 

    0x46566cd4,// 266 PAY 238 

    0x342c09f6,// 267 PAY 239 

    0x17f03722,// 268 PAY 240 

    0xbcfc824f,// 269 PAY 241 

    0x6bf28c54,// 270 PAY 242 

    0xe5c017bc,// 271 PAY 243 

    0x86ac8c6d,// 272 PAY 244 

    0xb3e34b1f,// 273 PAY 245 

    0x8b8b0bb9,// 274 PAY 246 

    0x944e085c,// 275 PAY 247 

    0x14025487,// 276 PAY 248 

    0xd7dc6d82,// 277 PAY 249 

    0x734e90cd,// 278 PAY 250 

    0xa1b2d00a,// 279 PAY 251 

    0x3bef63d9,// 280 PAY 252 

    0xefa2a6b7,// 281 PAY 253 

    0xe7116dfa,// 282 PAY 254 

    0xb3442ba5,// 283 PAY 255 

    0xce6fc95f,// 284 PAY 256 

    0x3fdfcda6,// 285 PAY 257 

    0x54ec39e0,// 286 PAY 258 

    0xf41f3a04,// 287 PAY 259 

    0x4e3c295c,// 288 PAY 260 

    0xc25e1a6f,// 289 PAY 261 

    0x0962ab9c,// 290 PAY 262 

    0xab752ebb,// 291 PAY 263 

    0x70973dcf,// 292 PAY 264 

    0xd74dd6bb,// 293 PAY 265 

    0x44932023,// 294 PAY 266 

    0xf1d905a1,// 295 PAY 267 

    0x3803f51e,// 296 PAY 268 

    0xa95a2ba3,// 297 PAY 269 

    0x6fed935d,// 298 PAY 270 

    0x542d8883,// 299 PAY 271 

    0xda026a27,// 300 PAY 272 

    0xfd083ca5,// 301 PAY 273 

    0x6a32aa5c,// 302 PAY 274 

    0x32bb9c17,// 303 PAY 275 

    0x3f3a08d1,// 304 PAY 276 

    0x9e2d4ad8,// 305 PAY 277 

    0xb0d123a5,// 306 PAY 278 

    0xeedcee9e,// 307 PAY 279 

    0x74092336,// 308 PAY 280 

    0x631632c9,// 309 PAY 281 

    0xdddbf367,// 310 PAY 282 

    0x7bc030e1,// 311 PAY 283 

    0x3f299402,// 312 PAY 284 

    0xa188eee5,// 313 PAY 285 

    0x1612afb7,// 314 PAY 286 

    0x632e5e2a,// 315 PAY 287 

    0x4d315e33,// 316 PAY 288 

    0xda306697,// 317 PAY 289 

    0xc81f0d7e,// 318 PAY 290 

    0x155595e7,// 319 PAY 291 

    0x880ab7d6,// 320 PAY 292 

    0xd9312d17,// 321 PAY 293 

    0x0932993a,// 322 PAY 294 

    0xf2917a94,// 323 PAY 295 

    0x6bfea16f,// 324 PAY 296 

    0x84a6a769,// 325 PAY 297 

    0x73fb7aa3,// 326 PAY 298 

    0xdf6ee810,// 327 PAY 299 

    0xb230bb06,// 328 PAY 300 

    0xb735a632,// 329 PAY 301 

    0x87b62d07,// 330 PAY 302 

    0xcf70a856,// 331 PAY 303 

    0x882d878f,// 332 PAY 304 

    0xfba09a91,// 333 PAY 305 

    0x26ea3f10,// 334 PAY 306 

    0xef6e7513,// 335 PAY 307 

    0x1e15f97e,// 336 PAY 308 

    0x845747e3,// 337 PAY 309 

    0x4b0f136f,// 338 PAY 310 

    0xc20ee2f5,// 339 PAY 311 

    0x35a79c00,// 340 PAY 312 

/// STA is 1 words. 

/// STA num_pkts       : 235 

/// STA pkt_idx        : 178 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x1c 

    0x02c81ceb // 341 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt77_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x08 

/// ECH pdu_tag        : 0x00 

    0x00080000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000015,// 3 SCX   1 

    0x809128ab,// 4 SCX   2 

    0x00007182,// 5 SCX   3 

    0x22594197,// 6 SCX   4 

    0x1cf18f4b,// 7 SCX   5 

    0xe814dc87,// 8 SCX   6 

    0x946fcc75,// 9 SCX   7 

    0x2841a9c2,// 10 SCX   8 

    0x460f4f23,// 11 SCX   9 

    0xa7eccdda,// 12 SCX  10 

    0x716bab38,// 13 SCX  11 

    0xb2f68dff,// 14 SCX  12 

    0x4e1c8b2e,// 15 SCX  13 

    0xe0e78f94,// 16 SCX  14 

    0x396230a6,// 17 SCX  15 

    0xdabfa876,// 18 SCX  16 

    0xc3f000c4,// 19 SCX  17 

    0x48dca982,// 20 SCX  18 

    0x0541c691,// 21 SCX  19 

    0xf03d9ecb,// 22 SCX  20 

    0xda0d4b35,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 161 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 127 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 127 

/// BFD lencrypto      : 48 

/// BFD ofstcrypto     : 72 

/// BFD (ofst+len)cry  : 120 

/// BFD ofstiv         : 44 

/// BFD ofsticv        : 136 

    0x0000007f,// 24 BFD   1 

    0x00480030,// 25 BFD   2 

    0x0088002c,// 26 BFD   3 

/// MFM is 1 words. 

/// MFM vldnibs        : 3 

    0x0300b520,// 27 MFM   1 

/// BDA is 42 words. 

/// BDA size     is 161 (0xa1) 

/// BDA id       is 0xaa5 

    0x00a10aa5,// 28 BDA   1 

/// PAY Generic Data size   : 161 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x8d882227,// 29 PAY   1 

    0x4a2f0890,// 30 PAY   2 

    0xe860a79d,// 31 PAY   3 

    0xd23bcb7e,// 32 PAY   4 

    0x2ecfe28a,// 33 PAY   5 

    0xef6ea9fd,// 34 PAY   6 

    0x3e00f32d,// 35 PAY   7 

    0x64c4aab1,// 36 PAY   8 

    0x9862181e,// 37 PAY   9 

    0x4a87d215,// 38 PAY  10 

    0x33151bd1,// 39 PAY  11 

    0xeab7a399,// 40 PAY  12 

    0x9928858b,// 41 PAY  13 

    0x173a1f90,// 42 PAY  14 

    0xe031344b,// 43 PAY  15 

    0x21ac2f4f,// 44 PAY  16 

    0xd9249200,// 45 PAY  17 

    0xaee959bc,// 46 PAY  18 

    0xb10abbf2,// 47 PAY  19 

    0x0d99766b,// 48 PAY  20 

    0xd5313475,// 49 PAY  21 

    0x7ddbe6ea,// 50 PAY  22 

    0x384f8467,// 51 PAY  23 

    0xe9e9b068,// 52 PAY  24 

    0x525abe7b,// 53 PAY  25 

    0x212641a9,// 54 PAY  26 

    0xf28ad4a7,// 55 PAY  27 

    0x382d3b71,// 56 PAY  28 

    0x0b975de6,// 57 PAY  29 

    0xeb247dd5,// 58 PAY  30 

    0x95f0a51f,// 59 PAY  31 

    0xe2fdd873,// 60 PAY  32 

    0x04bdb5c4,// 61 PAY  33 

    0x6c87f6c2,// 62 PAY  34 

    0x4a01a30d,// 63 PAY  35 

    0x4ed12686,// 64 PAY  36 

    0x9d9b29a9,// 65 PAY  37 

    0x24dc56f7,// 66 PAY  38 

    0x9c9271c2,// 67 PAY  39 

    0x161adddb,// 68 PAY  40 

    0x68000000,// 69 PAY  41 

/// STA is 1 words. 

/// STA num_pkts       : 254 

/// STA pkt_idx        : 71 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xbe 

    0x011dbefe // 70 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt78_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x00 

/// ECH pdu_tag        : 0x00 

    0x00000000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound save_icv insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x809228af,// 4 SCX   2 

    0x000061c2,// 5 SCX   3 

    0x432081a7,// 6 SCX   4 

    0x243f7d43,// 7 SCX   5 

    0x1aac986c,// 8 SCX   6 

    0xd91f4982,// 9 SCX   7 

    0xe3d9434f,// 10 SCX   8 

    0xfe607322,// 11 SCX   9 

    0x7da1d66f,// 12 SCX  10 

    0x6a997072,// 13 SCX  11 

    0xf112447b,// 14 SCX  12 

    0x1dbe92b7,// 15 SCX  13 

    0xc3a91a68,// 16 SCX  14 

    0x1a354c12,// 17 SCX  15 

    0x6745138a,// 18 SCX  16 

    0x3c62f524,// 19 SCX  17 

    0xd8dcbe5e,// 20 SCX  18 

    0x26b2532c,// 21 SCX  19 

    0x99c4cff9,// 22 SCX  20 

    0xd997c306,// 23 SCX  21 

    0xa62b843e,// 24 SCX  22 

    0x2e52661b,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 959 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 414 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 414 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 328 

/// BFD (ofst+len)cry  : 408 

/// BFD ofstiv         : 308 

/// BFD ofsticv        : 556 

    0x0000019e,// 26 BFD   1 

    0x01480050,// 27 BFD   2 

    0x022c0134,// 28 BFD   3 

/// MFM is 12 words. 

/// MFM vldnibs        : 59 

    0x5900cb0d,// 29 MFM   1 

    0xb868951b,// 30 MFM   2 

    0x43a8b2ac,// 31 MFM   3 

    0xdc8f0ef1,// 32 MFM   4 

    0x8a944129,// 33 MFM   5 

    0x902dca02,// 34 MFM   6 

    0x9e445f62,// 35 MFM   7 

    0x8602b6b1,// 36 MFM   8 

    0x6dc43938,// 37 MFM   9 

    0x4716c958,// 38 MFM  10 

    0xa178de20,// 39 MFM  11 

    0x44b82000,// 40 MFM  12 

/// BDA is 241 words. 

/// BDA size     is 959 (0x3bf) 

/// BDA id       is 0xdef3 

    0x03bfdef3,// 41 BDA   1 

/// PAY Generic Data size   : 959 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0xeb60adb5,// 42 PAY   1 

    0x3449c59c,// 43 PAY   2 

    0x0467fa44,// 44 PAY   3 

    0xa79b1550,// 45 PAY   4 

    0x7b8ee55f,// 46 PAY   5 

    0xda2535f8,// 47 PAY   6 

    0x6520aac7,// 48 PAY   7 

    0xcb596df1,// 49 PAY   8 

    0x6d4c22e5,// 50 PAY   9 

    0xd80ce3fa,// 51 PAY  10 

    0x30b09b60,// 52 PAY  11 

    0xcacfb2b9,// 53 PAY  12 

    0xed5b0c59,// 54 PAY  13 

    0x45afec8c,// 55 PAY  14 

    0x227fa658,// 56 PAY  15 

    0x1243d9c9,// 57 PAY  16 

    0x391a2a9f,// 58 PAY  17 

    0x16d9ba47,// 59 PAY  18 

    0x7727e89b,// 60 PAY  19 

    0x456e94c5,// 61 PAY  20 

    0x8fcb5008,// 62 PAY  21 

    0x81a7151b,// 63 PAY  22 

    0xa1a18065,// 64 PAY  23 

    0x3fbd32f4,// 65 PAY  24 

    0xa14aff75,// 66 PAY  25 

    0x164d7e8f,// 67 PAY  26 

    0x1bb1b336,// 68 PAY  27 

    0xdf1a14e0,// 69 PAY  28 

    0x004036ba,// 70 PAY  29 

    0x763e9e09,// 71 PAY  30 

    0x9e3825dc,// 72 PAY  31 

    0xbe96f7e7,// 73 PAY  32 

    0x6db32d12,// 74 PAY  33 

    0xb3724b12,// 75 PAY  34 

    0x9c6fc1fe,// 76 PAY  35 

    0x39f2f85f,// 77 PAY  36 

    0x516aaaf1,// 78 PAY  37 

    0x3bd84c7f,// 79 PAY  38 

    0x35627b58,// 80 PAY  39 

    0x66da6db5,// 81 PAY  40 

    0xfd6fdaa9,// 82 PAY  41 

    0x566d09fc,// 83 PAY  42 

    0xd691de97,// 84 PAY  43 

    0x3c62c31f,// 85 PAY  44 

    0x61bfa746,// 86 PAY  45 

    0xc05d5177,// 87 PAY  46 

    0x78077788,// 88 PAY  47 

    0x2e0e05a6,// 89 PAY  48 

    0xe7465b26,// 90 PAY  49 

    0xa2ac4240,// 91 PAY  50 

    0x191eec52,// 92 PAY  51 

    0x5a0f491e,// 93 PAY  52 

    0x70806509,// 94 PAY  53 

    0xe4b85ba1,// 95 PAY  54 

    0xa35abf9b,// 96 PAY  55 

    0xf2f55ec7,// 97 PAY  56 

    0x2df3f1e5,// 98 PAY  57 

    0x1d8a9f46,// 99 PAY  58 

    0xec4f7d57,// 100 PAY  59 

    0xf8852ac5,// 101 PAY  60 

    0x0a9cb98f,// 102 PAY  61 

    0xcb1b6bae,// 103 PAY  62 

    0x1c3c6759,// 104 PAY  63 

    0x2b0bede6,// 105 PAY  64 

    0xcc57fea4,// 106 PAY  65 

    0x8a3c1008,// 107 PAY  66 

    0x61bc2290,// 108 PAY  67 

    0xc50fc322,// 109 PAY  68 

    0x16dbe889,// 110 PAY  69 

    0x9df4feeb,// 111 PAY  70 

    0x13146578,// 112 PAY  71 

    0x388ba55a,// 113 PAY  72 

    0x31e5dce8,// 114 PAY  73 

    0x2e583c85,// 115 PAY  74 

    0xc9b14c48,// 116 PAY  75 

    0x1eabfe90,// 117 PAY  76 

    0x8bbaf334,// 118 PAY  77 

    0x407089ce,// 119 PAY  78 

    0xb240381c,// 120 PAY  79 

    0xa462509a,// 121 PAY  80 

    0xf437c5c6,// 122 PAY  81 

    0x26908ef2,// 123 PAY  82 

    0xe48f9283,// 124 PAY  83 

    0x15249104,// 125 PAY  84 

    0xd15236a7,// 126 PAY  85 

    0x0220e925,// 127 PAY  86 

    0xfcc8d34c,// 128 PAY  87 

    0x0fac354f,// 129 PAY  88 

    0xe397dbe8,// 130 PAY  89 

    0x20750bcc,// 131 PAY  90 

    0xbeb31ba7,// 132 PAY  91 

    0xb7a4e105,// 133 PAY  92 

    0xb4ab3bc8,// 134 PAY  93 

    0xd7644c02,// 135 PAY  94 

    0x441f03ba,// 136 PAY  95 

    0x56d50faf,// 137 PAY  96 

    0xe1493653,// 138 PAY  97 

    0x414ec154,// 139 PAY  98 

    0xeea685af,// 140 PAY  99 

    0x53d8be79,// 141 PAY 100 

    0x5ae3bbd7,// 142 PAY 101 

    0xf5699134,// 143 PAY 102 

    0x6478bd8f,// 144 PAY 103 

    0x640926ff,// 145 PAY 104 

    0x4bd0de10,// 146 PAY 105 

    0x0ff5300a,// 147 PAY 106 

    0x84876017,// 148 PAY 107 

    0x44126d12,// 149 PAY 108 

    0xe6d2851c,// 150 PAY 109 

    0xc427bc98,// 151 PAY 110 

    0x1716ea80,// 152 PAY 111 

    0x1746be75,// 153 PAY 112 

    0x271ca9c4,// 154 PAY 113 

    0xa76a7a0c,// 155 PAY 114 

    0x0ddbb3c7,// 156 PAY 115 

    0x181eb68c,// 157 PAY 116 

    0x0b3f09a9,// 158 PAY 117 

    0xfecbaf63,// 159 PAY 118 

    0xed760ee7,// 160 PAY 119 

    0xe80f305a,// 161 PAY 120 

    0xfa9013fd,// 162 PAY 121 

    0x8d4732d5,// 163 PAY 122 

    0xcccdfe0e,// 164 PAY 123 

    0xf4b4cf94,// 165 PAY 124 

    0x45b41eb5,// 166 PAY 125 

    0x6ec22e4a,// 167 PAY 126 

    0xafb15c94,// 168 PAY 127 

    0x6ca8530b,// 169 PAY 128 

    0x88a8e23b,// 170 PAY 129 

    0x3fe07c65,// 171 PAY 130 

    0x10875276,// 172 PAY 131 

    0x1c05bb10,// 173 PAY 132 

    0x29ae52a2,// 174 PAY 133 

    0x3cf52bde,// 175 PAY 134 

    0xfa23ef33,// 176 PAY 135 

    0xfd79d597,// 177 PAY 136 

    0x9137b6fd,// 178 PAY 137 

    0xf95b8fd8,// 179 PAY 138 

    0x8c1fbf0d,// 180 PAY 139 

    0x0e7a129b,// 181 PAY 140 

    0xa947a92f,// 182 PAY 141 

    0x98f33f08,// 183 PAY 142 

    0x8d7803ad,// 184 PAY 143 

    0x711ca66c,// 185 PAY 144 

    0xc23de4ad,// 186 PAY 145 

    0x17d924dc,// 187 PAY 146 

    0x9ce3d29f,// 188 PAY 147 

    0x33b46195,// 189 PAY 148 

    0x0b629d67,// 190 PAY 149 

    0x42b81b9f,// 191 PAY 150 

    0xa1cc8730,// 192 PAY 151 

    0xc3966d05,// 193 PAY 152 

    0xad6e8510,// 194 PAY 153 

    0x0d8063c5,// 195 PAY 154 

    0x4be0c034,// 196 PAY 155 

    0x0fdb991d,// 197 PAY 156 

    0x9a64780a,// 198 PAY 157 

    0xcfd6c24f,// 199 PAY 158 

    0x033c5bcf,// 200 PAY 159 

    0x08bcc024,// 201 PAY 160 

    0x443a2f05,// 202 PAY 161 

    0xc19208b9,// 203 PAY 162 

    0x99213359,// 204 PAY 163 

    0xbd078312,// 205 PAY 164 

    0x41944a21,// 206 PAY 165 

    0xc7fae7b8,// 207 PAY 166 

    0x447658ac,// 208 PAY 167 

    0x643e1bfa,// 209 PAY 168 

    0x324e4124,// 210 PAY 169 

    0xc99f7974,// 211 PAY 170 

    0x7ae8cc50,// 212 PAY 171 

    0x0337e98d,// 213 PAY 172 

    0x61ba634c,// 214 PAY 173 

    0xda544797,// 215 PAY 174 

    0xbc1c97ff,// 216 PAY 175 

    0x7c5fd6a3,// 217 PAY 176 

    0x8b1e548b,// 218 PAY 177 

    0x5b1420b7,// 219 PAY 178 

    0x5f1730ba,// 220 PAY 179 

    0x6400ddd4,// 221 PAY 180 

    0x3c1e387e,// 222 PAY 181 

    0x7571abb1,// 223 PAY 182 

    0x71c2950b,// 224 PAY 183 

    0xb682e986,// 225 PAY 184 

    0xc476b87f,// 226 PAY 185 

    0x8eea0018,// 227 PAY 186 

    0x406740c7,// 228 PAY 187 

    0x4f9548bd,// 229 PAY 188 

    0xcf13660f,// 230 PAY 189 

    0x8a5fdb28,// 231 PAY 190 

    0x890ab3a4,// 232 PAY 191 

    0xec216813,// 233 PAY 192 

    0x792db5b7,// 234 PAY 193 

    0xf189dff1,// 235 PAY 194 

    0x28006226,// 236 PAY 195 

    0x42c2872f,// 237 PAY 196 

    0x284481af,// 238 PAY 197 

    0xfe590fba,// 239 PAY 198 

    0x94a13399,// 240 PAY 199 

    0x0d4397e8,// 241 PAY 200 

    0x913e5173,// 242 PAY 201 

    0x4ad3fb8a,// 243 PAY 202 

    0xb4eb83bd,// 244 PAY 203 

    0xc52ad38b,// 245 PAY 204 

    0x84834d59,// 246 PAY 205 

    0x1778f8c3,// 247 PAY 206 

    0x2e5410fc,// 248 PAY 207 

    0xa49dbcf4,// 249 PAY 208 

    0x392b1124,// 250 PAY 209 

    0x2553d300,// 251 PAY 210 

    0xfc0305a7,// 252 PAY 211 

    0xe4fd922d,// 253 PAY 212 

    0xe5b0379c,// 254 PAY 213 

    0xdc0221ed,// 255 PAY 214 

    0xaf163ab8,// 256 PAY 215 

    0x95fe0955,// 257 PAY 216 

    0x915949b5,// 258 PAY 217 

    0x78814b58,// 259 PAY 218 

    0x604973c0,// 260 PAY 219 

    0x052fd3bd,// 261 PAY 220 

    0xc4d4f180,// 262 PAY 221 

    0xa6438492,// 263 PAY 222 

    0x64f00779,// 264 PAY 223 

    0x57551ac0,// 265 PAY 224 

    0xb079e2b8,// 266 PAY 225 

    0xb4f04480,// 267 PAY 226 

    0x6f06b6e4,// 268 PAY 227 

    0xef5ca4b9,// 269 PAY 228 

    0x24edc366,// 270 PAY 229 

    0xa76548c3,// 271 PAY 230 

    0xf2118ec4,// 272 PAY 231 

    0xb88c6795,// 273 PAY 232 

    0x990d6ffc,// 274 PAY 233 

    0x4a70e0c6,// 275 PAY 234 

    0x92471cd5,// 276 PAY 235 

    0xf59d1f45,// 277 PAY 236 

    0x71b21bb8,// 278 PAY 237 

    0x2823ed7b,// 279 PAY 238 

    0xac26dddf,// 280 PAY 239 

    0x8b60d200,// 281 PAY 240 

/// STA is 1 words. 

/// STA num_pkts       : 55 

/// STA pkt_idx        : 168 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xf4 

    0x02a0f437 // 282 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt79_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0c 

/// ECH pdu_tag        : 0x00 

    0x000c0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x809028d1,// 4 SCX   2 

    0x00005382,// 5 SCX   3 

    0xe2db2c84,// 6 SCX   4 

    0xa88ce90e,// 7 SCX   5 

    0xdea63dfb,// 8 SCX   6 

    0x892e6578,// 9 SCX   7 

    0xa92fba19,// 10 SCX   8 

    0x99ff7411,// 11 SCX   9 

    0xb2e9a30b,// 12 SCX  10 

    0x28df1edb,// 13 SCX  11 

    0x9d0b491b,// 14 SCX  12 

    0x9cdef69c,// 15 SCX  13 

    0x8b4ef2ef,// 16 SCX  14 

    0x7bd52f98,// 17 SCX  15 

    0xcc490d35,// 18 SCX  16 

    0xfad6da2e,// 19 SCX  17 

    0x614ad6d7,// 20 SCX  18 

    0x9d814009,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 1414 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 493 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 493 

/// BFD lencrypto      : 76 

/// BFD ofstcrypto     : 176 

/// BFD (ofst+len)cry  : 252 

/// BFD ofstiv         : 16 

/// BFD ofsticv        : 532 

    0x000001ed,// 22 BFD   1 

    0x00b0004c,// 23 BFD   2 

    0x02140010,// 24 BFD   3 

/// MFM is 2 words. 

/// MFM vldnibs        : 7 

    0x0700a37d,// 25 MFM   1 

    0xc4400000,// 26 MFM   2 

/// BDA is 355 words. 

/// BDA size     is 1414 (0x586) 

/// BDA id       is 0x4d3 

    0x058604d3,// 27 BDA   1 

/// PAY Generic Data size   : 1414 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xa44f112f,// 28 PAY   1 

    0xb103ef88,// 29 PAY   2 

    0x7df9e0ca,// 30 PAY   3 

    0x6ffc6855,// 31 PAY   4 

    0xb46a6a90,// 32 PAY   5 

    0x70b0a7fc,// 33 PAY   6 

    0x897b312a,// 34 PAY   7 

    0x179b476e,// 35 PAY   8 

    0x8d635ef5,// 36 PAY   9 

    0xfb7e0057,// 37 PAY  10 

    0x64ba4f58,// 38 PAY  11 

    0xcdb34a39,// 39 PAY  12 

    0x65b4f690,// 40 PAY  13 

    0x0a8dd642,// 41 PAY  14 

    0x3a498e74,// 42 PAY  15 

    0x69bec744,// 43 PAY  16 

    0x36112f4d,// 44 PAY  17 

    0x2943c8f2,// 45 PAY  18 

    0x6b5658bd,// 46 PAY  19 

    0xcd04d52d,// 47 PAY  20 

    0xb8ddd4f0,// 48 PAY  21 

    0xbb7eb4c1,// 49 PAY  22 

    0x4021f3e1,// 50 PAY  23 

    0x1b10a3de,// 51 PAY  24 

    0x78a4d2fd,// 52 PAY  25 

    0x495de48f,// 53 PAY  26 

    0xb4cb3696,// 54 PAY  27 

    0xe254e37c,// 55 PAY  28 

    0xf27caec1,// 56 PAY  29 

    0x0fe681a2,// 57 PAY  30 

    0xd3b28af7,// 58 PAY  31 

    0x70c8e73c,// 59 PAY  32 

    0xb39d490d,// 60 PAY  33 

    0xfbc9835f,// 61 PAY  34 

    0x77b13510,// 62 PAY  35 

    0x5e963f40,// 63 PAY  36 

    0xb00adfd1,// 64 PAY  37 

    0xe824110b,// 65 PAY  38 

    0xa00ebbb9,// 66 PAY  39 

    0x08c2a3ad,// 67 PAY  40 

    0xb4fd2a4b,// 68 PAY  41 

    0xc6487a82,// 69 PAY  42 

    0x2d15d445,// 70 PAY  43 

    0x8b6da151,// 71 PAY  44 

    0x8dcb5711,// 72 PAY  45 

    0x7a32bd43,// 73 PAY  46 

    0xcabc0649,// 74 PAY  47 

    0x08ab7728,// 75 PAY  48 

    0xd2f64456,// 76 PAY  49 

    0x16ca2dc1,// 77 PAY  50 

    0x57676d89,// 78 PAY  51 

    0xa4a08d97,// 79 PAY  52 

    0xa023e260,// 80 PAY  53 

    0x22b25330,// 81 PAY  54 

    0xe3e1c48d,// 82 PAY  55 

    0xf69a6ca0,// 83 PAY  56 

    0xd5508434,// 84 PAY  57 

    0x6c7ff847,// 85 PAY  58 

    0x9bc44162,// 86 PAY  59 

    0xff346a66,// 87 PAY  60 

    0xd613c6ec,// 88 PAY  61 

    0xfc84d4a1,// 89 PAY  62 

    0x6e0d4731,// 90 PAY  63 

    0x32e2182e,// 91 PAY  64 

    0x8803ea68,// 92 PAY  65 

    0xf07a1945,// 93 PAY  66 

    0xb9c9e1d9,// 94 PAY  67 

    0xb0c8d4f6,// 95 PAY  68 

    0x262a94a0,// 96 PAY  69 

    0xf6ecb4ab,// 97 PAY  70 

    0xb6a3289b,// 98 PAY  71 

    0xb28f0e14,// 99 PAY  72 

    0xc402a3ef,// 100 PAY  73 

    0x2e26c3d5,// 101 PAY  74 

    0x2946e422,// 102 PAY  75 

    0x45b04ec3,// 103 PAY  76 

    0xfbd53d44,// 104 PAY  77 

    0xe06b12ea,// 105 PAY  78 

    0x2e9e2164,// 106 PAY  79 

    0xaba69ceb,// 107 PAY  80 

    0xfc8abc5d,// 108 PAY  81 

    0xe34b5d54,// 109 PAY  82 

    0xc7c91eeb,// 110 PAY  83 

    0x1d8b54ad,// 111 PAY  84 

    0xb7169159,// 112 PAY  85 

    0x5072bb41,// 113 PAY  86 

    0x6e7c4a56,// 114 PAY  87 

    0x2c2aebb2,// 115 PAY  88 

    0xd9ef38d4,// 116 PAY  89 

    0xd8eb48bc,// 117 PAY  90 

    0xd0440665,// 118 PAY  91 

    0xd8447918,// 119 PAY  92 

    0x9ee01def,// 120 PAY  93 

    0x132344ff,// 121 PAY  94 

    0xdc79ade6,// 122 PAY  95 

    0x54d79efc,// 123 PAY  96 

    0x6494f8c7,// 124 PAY  97 

    0x7b6866bb,// 125 PAY  98 

    0x7e0c4dd2,// 126 PAY  99 

    0x5f690812,// 127 PAY 100 

    0xde14d3d3,// 128 PAY 101 

    0xe3f2821b,// 129 PAY 102 

    0xcf82e15e,// 130 PAY 103 

    0x6e904e6f,// 131 PAY 104 

    0xa30d2991,// 132 PAY 105 

    0xee290e1d,// 133 PAY 106 

    0x47c28246,// 134 PAY 107 

    0xfccc7aef,// 135 PAY 108 

    0x5ae317b4,// 136 PAY 109 

    0xe94dd933,// 137 PAY 110 

    0xda6e4fd9,// 138 PAY 111 

    0x5c06a162,// 139 PAY 112 

    0x33117560,// 140 PAY 113 

    0x1988b225,// 141 PAY 114 

    0xade64ee0,// 142 PAY 115 

    0x10291000,// 143 PAY 116 

    0x3ca7aae1,// 144 PAY 117 

    0x0b5ae26b,// 145 PAY 118 

    0xc0a3d11f,// 146 PAY 119 

    0x6e9cf915,// 147 PAY 120 

    0x33ed060d,// 148 PAY 121 

    0x74131d3d,// 149 PAY 122 

    0xae7b294a,// 150 PAY 123 

    0x23d876ac,// 151 PAY 124 

    0x0404c9c5,// 152 PAY 125 

    0xf018b9b7,// 153 PAY 126 

    0x8485a975,// 154 PAY 127 

    0x6d9aec6c,// 155 PAY 128 

    0xd4816cbb,// 156 PAY 129 

    0xf150c848,// 157 PAY 130 

    0xa996f30c,// 158 PAY 131 

    0xa2b71d23,// 159 PAY 132 

    0x20615765,// 160 PAY 133 

    0x9edb48da,// 161 PAY 134 

    0xed11a5da,// 162 PAY 135 

    0xa5b01817,// 163 PAY 136 

    0x30c3d750,// 164 PAY 137 

    0xd82a4df9,// 165 PAY 138 

    0x2c08faf8,// 166 PAY 139 

    0x39f740e4,// 167 PAY 140 

    0xc1e3d278,// 168 PAY 141 

    0xfc962da2,// 169 PAY 142 

    0x04033476,// 170 PAY 143 

    0xba39f6c4,// 171 PAY 144 

    0x1f307497,// 172 PAY 145 

    0x884574b6,// 173 PAY 146 

    0x635f18c7,// 174 PAY 147 

    0xde264c77,// 175 PAY 148 

    0x4732b862,// 176 PAY 149 

    0x3b91f0dd,// 177 PAY 150 

    0xc80312c2,// 178 PAY 151 

    0x0915cc14,// 179 PAY 152 

    0x35943c20,// 180 PAY 153 

    0x995f6c93,// 181 PAY 154 

    0x50594e51,// 182 PAY 155 

    0x4b5d8f2e,// 183 PAY 156 

    0x56fbc12d,// 184 PAY 157 

    0x944b7ebc,// 185 PAY 158 

    0x51c2d709,// 186 PAY 159 

    0xd9d95426,// 187 PAY 160 

    0xcba00c62,// 188 PAY 161 

    0x63c0e979,// 189 PAY 162 

    0x0a028882,// 190 PAY 163 

    0x59911d53,// 191 PAY 164 

    0x81217b4e,// 192 PAY 165 

    0x78c568c0,// 193 PAY 166 

    0xe96df748,// 194 PAY 167 

    0x1e6fd184,// 195 PAY 168 

    0xf5c0b2e6,// 196 PAY 169 

    0x6d967f18,// 197 PAY 170 

    0xd7edadc5,// 198 PAY 171 

    0x9a2ddec2,// 199 PAY 172 

    0xe515affa,// 200 PAY 173 

    0xe755b4eb,// 201 PAY 174 

    0x93656266,// 202 PAY 175 

    0x107336cc,// 203 PAY 176 

    0x0cc9ad16,// 204 PAY 177 

    0xff0bd07e,// 205 PAY 178 

    0x979a7b90,// 206 PAY 179 

    0x24853716,// 207 PAY 180 

    0x0362db59,// 208 PAY 181 

    0x7b3a7e30,// 209 PAY 182 

    0x8661bf6e,// 210 PAY 183 

    0x5ba02c50,// 211 PAY 184 

    0x44787274,// 212 PAY 185 

    0x2087cbf0,// 213 PAY 186 

    0xd08e9cd4,// 214 PAY 187 

    0x949251fc,// 215 PAY 188 

    0x02df3435,// 216 PAY 189 

    0xb8163cac,// 217 PAY 190 

    0x0bda4a97,// 218 PAY 191 

    0x3dcbedd2,// 219 PAY 192 

    0x00988fe3,// 220 PAY 193 

    0x770b4849,// 221 PAY 194 

    0xaf774cd3,// 222 PAY 195 

    0x2c40d3cc,// 223 PAY 196 

    0xff9a8e57,// 224 PAY 197 

    0x75f27f59,// 225 PAY 198 

    0x5015a05e,// 226 PAY 199 

    0xec399f06,// 227 PAY 200 

    0x15a33a46,// 228 PAY 201 

    0x5c9ecf67,// 229 PAY 202 

    0xc776eb66,// 230 PAY 203 

    0xcdee9cbd,// 231 PAY 204 

    0x6230f2e9,// 232 PAY 205 

    0x18b8d48a,// 233 PAY 206 

    0x57dbe6ba,// 234 PAY 207 

    0x68cbdffe,// 235 PAY 208 

    0x898c3b92,// 236 PAY 209 

    0x0360091a,// 237 PAY 210 

    0x1bceeb47,// 238 PAY 211 

    0x71ca1a0c,// 239 PAY 212 

    0x95a8a34a,// 240 PAY 213 

    0x9b9a04c6,// 241 PAY 214 

    0xf25e742a,// 242 PAY 215 

    0xba7017ee,// 243 PAY 216 

    0x22c16305,// 244 PAY 217 

    0x2ca4d41d,// 245 PAY 218 

    0xddee6527,// 246 PAY 219 

    0xba2b29ab,// 247 PAY 220 

    0x1ebc7565,// 248 PAY 221 

    0xdb094193,// 249 PAY 222 

    0x0f8012c2,// 250 PAY 223 

    0x6ddae70e,// 251 PAY 224 

    0x3e9dc1f3,// 252 PAY 225 

    0xe63acc4c,// 253 PAY 226 

    0x365c3be3,// 254 PAY 227 

    0x7a3abdaa,// 255 PAY 228 

    0x8464bfe7,// 256 PAY 229 

    0x09c0e809,// 257 PAY 230 

    0xe5307516,// 258 PAY 231 

    0xa8c84596,// 259 PAY 232 

    0x03246ea4,// 260 PAY 233 

    0xcbc7592a,// 261 PAY 234 

    0x36dc0f5c,// 262 PAY 235 

    0xe4c8b61b,// 263 PAY 236 

    0x31d91536,// 264 PAY 237 

    0xb016bbf4,// 265 PAY 238 

    0x90a5f955,// 266 PAY 239 

    0x88d4e711,// 267 PAY 240 

    0x9db17ab5,// 268 PAY 241 

    0xad449f9e,// 269 PAY 242 

    0x292e7b21,// 270 PAY 243 

    0x7486dcc0,// 271 PAY 244 

    0xe0fa86d8,// 272 PAY 245 

    0x9b72939b,// 273 PAY 246 

    0x99402dee,// 274 PAY 247 

    0x93804a5d,// 275 PAY 248 

    0xda3217e6,// 276 PAY 249 

    0x97d7c005,// 277 PAY 250 

    0xe3d6095a,// 278 PAY 251 

    0xcf884b0f,// 279 PAY 252 

    0xd0095a68,// 280 PAY 253 

    0xb528602a,// 281 PAY 254 

    0x59d290b7,// 282 PAY 255 

    0x490dcc6c,// 283 PAY 256 

    0x1eb91476,// 284 PAY 257 

    0x17f09b38,// 285 PAY 258 

    0x2a5b3e7f,// 286 PAY 259 

    0x8e342218,// 287 PAY 260 

    0xcab2b610,// 288 PAY 261 

    0x113c97cc,// 289 PAY 262 

    0x08ee2f74,// 290 PAY 263 

    0xb3b7f18b,// 291 PAY 264 

    0x64242487,// 292 PAY 265 

    0xbf23fc13,// 293 PAY 266 

    0x9d7b9bb6,// 294 PAY 267 

    0x684782d2,// 295 PAY 268 

    0xea416f87,// 296 PAY 269 

    0x3edc4314,// 297 PAY 270 

    0xa13040a7,// 298 PAY 271 

    0x372b5406,// 299 PAY 272 

    0x135757ff,// 300 PAY 273 

    0x52cbb5dc,// 301 PAY 274 

    0x83006b8f,// 302 PAY 275 

    0xe18c914c,// 303 PAY 276 

    0x13fc0b6c,// 304 PAY 277 

    0x1d401038,// 305 PAY 278 

    0xf232d9c4,// 306 PAY 279 

    0x2d251337,// 307 PAY 280 

    0xf1c7a9f1,// 308 PAY 281 

    0xb9c1fd46,// 309 PAY 282 

    0xf82ea63a,// 310 PAY 283 

    0xbe41a74c,// 311 PAY 284 

    0x007c799e,// 312 PAY 285 

    0x876ca738,// 313 PAY 286 

    0xca5862f5,// 314 PAY 287 

    0x6566ac5e,// 315 PAY 288 

    0xcb259acf,// 316 PAY 289 

    0xeeafdf22,// 317 PAY 290 

    0x3b39706d,// 318 PAY 291 

    0x23e5c72b,// 319 PAY 292 

    0xbd5edce5,// 320 PAY 293 

    0xda6488d8,// 321 PAY 294 

    0xaf8ed06d,// 322 PAY 295 

    0xfa992f35,// 323 PAY 296 

    0x6935044b,// 324 PAY 297 

    0xdcf6f4a9,// 325 PAY 298 

    0xf925f9d9,// 326 PAY 299 

    0xb6642cbe,// 327 PAY 300 

    0x1654f63f,// 328 PAY 301 

    0xdedb3b57,// 329 PAY 302 

    0x31dc8ee6,// 330 PAY 303 

    0x9e7e3505,// 331 PAY 304 

    0x23ad48a1,// 332 PAY 305 

    0x464cb102,// 333 PAY 306 

    0x4c82bd54,// 334 PAY 307 

    0x42484f9c,// 335 PAY 308 

    0xfead2285,// 336 PAY 309 

    0x11ffbd75,// 337 PAY 310 

    0x88c85ebb,// 338 PAY 311 

    0xce497c5b,// 339 PAY 312 

    0xc7649772,// 340 PAY 313 

    0x6dc01a2c,// 341 PAY 314 

    0x86dcebb5,// 342 PAY 315 

    0x941c5b30,// 343 PAY 316 

    0x7dc771bc,// 344 PAY 317 

    0x8324547b,// 345 PAY 318 

    0x318d0a90,// 346 PAY 319 

    0x662c14f7,// 347 PAY 320 

    0x769c77f8,// 348 PAY 321 

    0x11acf37d,// 349 PAY 322 

    0x5c7865cf,// 350 PAY 323 

    0xe1bf0fa5,// 351 PAY 324 

    0x0ec9ba25,// 352 PAY 325 

    0xe906f9da,// 353 PAY 326 

    0x7b8d2a24,// 354 PAY 327 

    0xfb741fe8,// 355 PAY 328 

    0xefa61b68,// 356 PAY 329 

    0x8df342b2,// 357 PAY 330 

    0x69c92aa1,// 358 PAY 331 

    0xb2f92f4e,// 359 PAY 332 

    0x4f3e3a3b,// 360 PAY 333 

    0xd67949c1,// 361 PAY 334 

    0x2a5f2927,// 362 PAY 335 

    0x16fdf7fc,// 363 PAY 336 

    0xc7e5a0c9,// 364 PAY 337 

    0xc8bcd42d,// 365 PAY 338 

    0xfab67935,// 366 PAY 339 

    0xf48c16ba,// 367 PAY 340 

    0xd988788a,// 368 PAY 341 

    0x88697738,// 369 PAY 342 

    0x96c0e8bf,// 370 PAY 343 

    0x18834df7,// 371 PAY 344 

    0xad5b163f,// 372 PAY 345 

    0xa20a9405,// 373 PAY 346 

    0xc4e3530b,// 374 PAY 347 

    0xa4815b32,// 375 PAY 348 

    0x06220567,// 376 PAY 349 

    0xc83b3e39,// 377 PAY 350 

    0xe4840966,// 378 PAY 351 

    0x7e18622e,// 379 PAY 352 

    0xddde866c,// 380 PAY 353 

    0x8e440000,// 381 PAY 354 

/// STA is 1 words. 

/// STA num_pkts       : 45 

/// STA pkt_idx        : 90 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xf 

    0x01690f2d // 382 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt80_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x0a 

/// ECH pdu_tag        : 0x00 

    0x000a0000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en !lock_en  

/// SCX inbound !save_icv insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x00000017,// 3 SCX   1 

    0x80922842,// 4 SCX   2 

    0x00003382,// 5 SCX   3 

    0xb6496f6e,// 6 SCX   4 

    0xcb0e07d3,// 7 SCX   5 

    0xf047cdaf,// 8 SCX   6 

    0x769546c1,// 9 SCX   7 

    0xdca4c844,// 10 SCX   8 

    0x12561828,// 11 SCX   9 

    0xe783c154,// 12 SCX  10 

    0x08c6be86,// 13 SCX  11 

    0x68e8e32f,// 14 SCX  12 

    0xd791b64d,// 15 SCX  13 

    0x070d8b5c,// 16 SCX  14 

    0xe2381f44,// 17 SCX  15 

    0xd7ebb111,// 18 SCX  16 

    0xdeccf843,// 19 SCX  17 

    0xa0e0d3ef,// 20 SCX  18 

    0x644e8481,// 21 SCX  19 

    0xdd465d33,// 22 SCX  20 

    0x09a5f40c,// 23 SCX  21 

    0xebe8aaff,// 24 SCX  22 

    0x2449cbc1,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 1151 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 342 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 342 

/// BFD lencrypto      : 12 

/// BFD ofstcrypto     : 328 

/// BFD (ofst+len)cry  : 340 

/// BFD ofstiv         : 188 

/// BFD ofsticv        : 724 

    0x00000156,// 26 BFD   1 

    0x0148000c,// 27 BFD   2 

    0x02d400bc,// 28 BFD   3 

/// MFM is 6 words. 

/// MFM vldnibs        : 29 

    0x2900e441,// 29 MFM   1 

    0xf1151c4c,// 30 MFM   2 

    0xa4814fff,// 31 MFM   3 

    0xbfd86adf,// 32 MFM   4 

    0xe55db73d,// 33 MFM   5 

    0xcff06000,// 34 MFM   6 

/// BDA is 289 words. 

/// BDA size     is 1151 (0x47f) 

/// BDA id       is 0xcf5d 

    0x047fcf5d,// 35 BDA   1 

/// PAY Generic Data size   : 1151 byte(s) 

/// PAD Buffer Data Pad size   : 1 byte(s) 

    0xc9fb8d51,// 36 PAY   1 

    0xa3f07b74,// 37 PAY   2 

    0x70ee2e66,// 38 PAY   3 

    0x1bc56bf5,// 39 PAY   4 

    0x3f551aaf,// 40 PAY   5 

    0x17923275,// 41 PAY   6 

    0x89d4a59a,// 42 PAY   7 

    0x111432fe,// 43 PAY   8 

    0x7d2ca925,// 44 PAY   9 

    0x6a12443a,// 45 PAY  10 

    0x612e5438,// 46 PAY  11 

    0x6738b053,// 47 PAY  12 

    0x5aefaf3f,// 48 PAY  13 

    0x9eba340a,// 49 PAY  14 

    0xc82d4882,// 50 PAY  15 

    0x51370da4,// 51 PAY  16 

    0xa3bd2f68,// 52 PAY  17 

    0x47688d5a,// 53 PAY  18 

    0x543ee284,// 54 PAY  19 

    0x53bcf2d1,// 55 PAY  20 

    0x6d308cdf,// 56 PAY  21 

    0x6e95cb04,// 57 PAY  22 

    0x36a1cc08,// 58 PAY  23 

    0x97578dce,// 59 PAY  24 

    0x5f9e14e7,// 60 PAY  25 

    0x8f2c046c,// 61 PAY  26 

    0x5f3d9d21,// 62 PAY  27 

    0xdb484309,// 63 PAY  28 

    0xf91c5414,// 64 PAY  29 

    0x3c3242af,// 65 PAY  30 

    0x527ed3a3,// 66 PAY  31 

    0xe7182a9e,// 67 PAY  32 

    0x193870b9,// 68 PAY  33 

    0xe1cac12d,// 69 PAY  34 

    0xc2c8a2d2,// 70 PAY  35 

    0xc86a8bb3,// 71 PAY  36 

    0x17e792e2,// 72 PAY  37 

    0xf7762bcc,// 73 PAY  38 

    0xff3cc911,// 74 PAY  39 

    0x18475786,// 75 PAY  40 

    0x178c742c,// 76 PAY  41 

    0x852acbf7,// 77 PAY  42 

    0x0ff5f437,// 78 PAY  43 

    0x8bdd4c9b,// 79 PAY  44 

    0x92f64d9c,// 80 PAY  45 

    0x6b1f0877,// 81 PAY  46 

    0xc417316e,// 82 PAY  47 

    0x4ebd9f60,// 83 PAY  48 

    0xaee168ef,// 84 PAY  49 

    0xe8201e18,// 85 PAY  50 

    0xeab6be69,// 86 PAY  51 

    0x6b26d1bf,// 87 PAY  52 

    0x9b56c3bf,// 88 PAY  53 

    0xa0cf302e,// 89 PAY  54 

    0xb40e30f9,// 90 PAY  55 

    0x59442201,// 91 PAY  56 

    0x9172ffcc,// 92 PAY  57 

    0xa685e8e7,// 93 PAY  58 

    0xe426a36b,// 94 PAY  59 

    0x529d4660,// 95 PAY  60 

    0xd7710658,// 96 PAY  61 

    0x4ab7a77b,// 97 PAY  62 

    0xf4b03aec,// 98 PAY  63 

    0x679583e6,// 99 PAY  64 

    0x8e6c761c,// 100 PAY  65 

    0x7ca721fb,// 101 PAY  66 

    0x50d482ed,// 102 PAY  67 

    0x864095d2,// 103 PAY  68 

    0x7985e100,// 104 PAY  69 

    0x0cc04a1a,// 105 PAY  70 

    0x5ccbfb6e,// 106 PAY  71 

    0xae49e54a,// 107 PAY  72 

    0x931cee03,// 108 PAY  73 

    0x1c9f6324,// 109 PAY  74 

    0x53f7e947,// 110 PAY  75 

    0x0e9c020c,// 111 PAY  76 

    0x453227fc,// 112 PAY  77 

    0x3d9e8a0f,// 113 PAY  78 

    0xe784c83b,// 114 PAY  79 

    0xdca176ee,// 115 PAY  80 

    0xa18af0b0,// 116 PAY  81 

    0x79e068ee,// 117 PAY  82 

    0xb551d836,// 118 PAY  83 

    0x28b809ab,// 119 PAY  84 

    0xfbe39856,// 120 PAY  85 

    0x4c01980e,// 121 PAY  86 

    0x0866ab7e,// 122 PAY  87 

    0x5a2174e0,// 123 PAY  88 

    0x3c6f7719,// 124 PAY  89 

    0xae51d6f4,// 125 PAY  90 

    0x7f48b6d2,// 126 PAY  91 

    0x99e0117d,// 127 PAY  92 

    0x0cacb1c5,// 128 PAY  93 

    0x781be9aa,// 129 PAY  94 

    0xd354d806,// 130 PAY  95 

    0xf79b01ea,// 131 PAY  96 

    0xc102edeb,// 132 PAY  97 

    0xd43ef34c,// 133 PAY  98 

    0x609be1fb,// 134 PAY  99 

    0xf7482b3e,// 135 PAY 100 

    0x85a61b26,// 136 PAY 101 

    0xadf79deb,// 137 PAY 102 

    0xf239abb7,// 138 PAY 103 

    0x8249043f,// 139 PAY 104 

    0x9ba0ed34,// 140 PAY 105 

    0x5dc19299,// 141 PAY 106 

    0xe8da82b3,// 142 PAY 107 

    0xd5d17982,// 143 PAY 108 

    0x87ae7cae,// 144 PAY 109 

    0x374b9c10,// 145 PAY 110 

    0x513cecf8,// 146 PAY 111 

    0x1c2a46f7,// 147 PAY 112 

    0x16884b24,// 148 PAY 113 

    0x74a13a57,// 149 PAY 114 

    0x76799451,// 150 PAY 115 

    0xc15ddb17,// 151 PAY 116 

    0x14d63280,// 152 PAY 117 

    0x3540ee39,// 153 PAY 118 

    0x4118f8c0,// 154 PAY 119 

    0xbe609ffd,// 155 PAY 120 

    0x5ed465c5,// 156 PAY 121 

    0x98827375,// 157 PAY 122 

    0x5b437afb,// 158 PAY 123 

    0xc194d7f7,// 159 PAY 124 

    0xf4c73104,// 160 PAY 125 

    0xedcc60bd,// 161 PAY 126 

    0x6b3217fe,// 162 PAY 127 

    0xd06c015a,// 163 PAY 128 

    0x9d691bed,// 164 PAY 129 

    0x09d48758,// 165 PAY 130 

    0x4e36ce2f,// 166 PAY 131 

    0xb7960dda,// 167 PAY 132 

    0xac1a38e7,// 168 PAY 133 

    0x544f85cd,// 169 PAY 134 

    0x473b7769,// 170 PAY 135 

    0xa33c2929,// 171 PAY 136 

    0x921c596e,// 172 PAY 137 

    0x3e5d72d9,// 173 PAY 138 

    0xbbe949f9,// 174 PAY 139 

    0xde7d9238,// 175 PAY 140 

    0xec8d2070,// 176 PAY 141 

    0x9bf16ba7,// 177 PAY 142 

    0x7637ee35,// 178 PAY 143 

    0xf7fce72a,// 179 PAY 144 

    0x3f62c00f,// 180 PAY 145 

    0xe9d93f44,// 181 PAY 146 

    0xa188a067,// 182 PAY 147 

    0x5a3cb21d,// 183 PAY 148 

    0xc2348db5,// 184 PAY 149 

    0x5e538f88,// 185 PAY 150 

    0xc5894437,// 186 PAY 151 

    0xd1fb5531,// 187 PAY 152 

    0x56f702b5,// 188 PAY 153 

    0x4c197211,// 189 PAY 154 

    0xa8edd9af,// 190 PAY 155 

    0x4abc2832,// 191 PAY 156 

    0x8dd86f98,// 192 PAY 157 

    0x73773cbc,// 193 PAY 158 

    0x0b01f161,// 194 PAY 159 

    0xb589614a,// 195 PAY 160 

    0x0f8fa6b2,// 196 PAY 161 

    0xad1b7f8b,// 197 PAY 162 

    0xf287ffd5,// 198 PAY 163 

    0xf5b88715,// 199 PAY 164 

    0xcd71a435,// 200 PAY 165 

    0x45cd6e25,// 201 PAY 166 

    0x61602233,// 202 PAY 167 

    0x0948c53c,// 203 PAY 168 

    0x8aac0c21,// 204 PAY 169 

    0x1b624ee3,// 205 PAY 170 

    0x81c0097b,// 206 PAY 171 

    0xc33c1d74,// 207 PAY 172 

    0xa86f89b4,// 208 PAY 173 

    0x49ec0018,// 209 PAY 174 

    0xfd977a52,// 210 PAY 175 

    0xefe3bb7c,// 211 PAY 176 

    0xfc2e56a8,// 212 PAY 177 

    0xd4ef5e05,// 213 PAY 178 

    0xf8fddd61,// 214 PAY 179 

    0xe984322e,// 215 PAY 180 

    0xd456e1ff,// 216 PAY 181 

    0xe3f71309,// 217 PAY 182 

    0x13345b1b,// 218 PAY 183 

    0x9802427b,// 219 PAY 184 

    0x20a527b7,// 220 PAY 185 

    0xe4640979,// 221 PAY 186 

    0x78f27caa,// 222 PAY 187 

    0x087fb9ce,// 223 PAY 188 

    0xba762e4e,// 224 PAY 189 

    0xb31dd1b6,// 225 PAY 190 

    0x4a3f5544,// 226 PAY 191 

    0x4bdb92f0,// 227 PAY 192 

    0x0a1c9737,// 228 PAY 193 

    0x1152652d,// 229 PAY 194 

    0xffe03fd1,// 230 PAY 195 

    0xc85f9ccd,// 231 PAY 196 

    0xc324c133,// 232 PAY 197 

    0x869fd22a,// 233 PAY 198 

    0xc0a8b84f,// 234 PAY 199 

    0xfcb02e9a,// 235 PAY 200 

    0x3b2cc0ed,// 236 PAY 201 

    0x1f666ba8,// 237 PAY 202 

    0x37d234d0,// 238 PAY 203 

    0xd9be96a5,// 239 PAY 204 

    0x9c70b3a7,// 240 PAY 205 

    0x43ccb088,// 241 PAY 206 

    0xff56cd39,// 242 PAY 207 

    0x19a3946e,// 243 PAY 208 

    0x789fe741,// 244 PAY 209 

    0x85d2e807,// 245 PAY 210 

    0x0a8d95a6,// 246 PAY 211 

    0x2839edc4,// 247 PAY 212 

    0xfdc2578b,// 248 PAY 213 

    0xd0a52159,// 249 PAY 214 

    0x9c320f56,// 250 PAY 215 

    0x9491ffe1,// 251 PAY 216 

    0x1feaf8a0,// 252 PAY 217 

    0xfd9792a9,// 253 PAY 218 

    0x2d68d157,// 254 PAY 219 

    0xfb95633d,// 255 PAY 220 

    0x51354e53,// 256 PAY 221 

    0xb8a4211b,// 257 PAY 222 

    0xa74d725c,// 258 PAY 223 

    0xe466e420,// 259 PAY 224 

    0xe809096b,// 260 PAY 225 

    0x85ac0bbd,// 261 PAY 226 

    0x21c0191a,// 262 PAY 227 

    0x3d345847,// 263 PAY 228 

    0x75cf24ed,// 264 PAY 229 

    0xbbba0272,// 265 PAY 230 

    0x7f218899,// 266 PAY 231 

    0x323773d8,// 267 PAY 232 

    0x34227fef,// 268 PAY 233 

    0x742d53b5,// 269 PAY 234 

    0xc17677f9,// 270 PAY 235 

    0x0ceb32b4,// 271 PAY 236 

    0x54cb7777,// 272 PAY 237 

    0xeb13bccb,// 273 PAY 238 

    0x8d257e35,// 274 PAY 239 

    0x3d16a20b,// 275 PAY 240 

    0x2a8efe05,// 276 PAY 241 

    0x09567af1,// 277 PAY 242 

    0x2d5ddb01,// 278 PAY 243 

    0x57702a3b,// 279 PAY 244 

    0xd3e6c183,// 280 PAY 245 

    0x79c4f58f,// 281 PAY 246 

    0x203e4abd,// 282 PAY 247 

    0x62ef77c1,// 283 PAY 248 

    0x9357281e,// 284 PAY 249 

    0x7f0fb911,// 285 PAY 250 

    0x659ae8fc,// 286 PAY 251 

    0x9c431cb1,// 287 PAY 252 

    0x1e91a8d1,// 288 PAY 253 

    0xb3b344ca,// 289 PAY 254 

    0x6b8d17d0,// 290 PAY 255 

    0x5106272c,// 291 PAY 256 

    0xbd9eb1a9,// 292 PAY 257 

    0x91463475,// 293 PAY 258 

    0x85ae7c11,// 294 PAY 259 

    0xe3e99b37,// 295 PAY 260 

    0x9108b5c5,// 296 PAY 261 

    0x82b0eaa1,// 297 PAY 262 

    0x314ac907,// 298 PAY 263 

    0xae06ac7f,// 299 PAY 264 

    0x2bbd51ed,// 300 PAY 265 

    0x4c2f7471,// 301 PAY 266 

    0x5a2677ab,// 302 PAY 267 

    0xf5968ae6,// 303 PAY 268 

    0x7d5f67ca,// 304 PAY 269 

    0xa135c250,// 305 PAY 270 

    0x61a6781d,// 306 PAY 271 

    0x07b21f6f,// 307 PAY 272 

    0x28f25a8b,// 308 PAY 273 

    0xd0bf1b28,// 309 PAY 274 

    0x63a0dcc3,// 310 PAY 275 

    0x97773b16,// 311 PAY 276 

    0xf4e2beff,// 312 PAY 277 

    0xef330c9d,// 313 PAY 278 

    0x0fd2a971,// 314 PAY 279 

    0xbe1a9f7b,// 315 PAY 280 

    0x187196bd,// 316 PAY 281 

    0x6410e874,// 317 PAY 282 

    0xa65958fb,// 318 PAY 283 

    0xf78124c5,// 319 PAY 284 

    0x9bbf0d02,// 320 PAY 285 

    0x25f84150,// 321 PAY 286 

    0x2c9168c6,// 322 PAY 287 

    0x11e4eb00,// 323 PAY 288 

/// STA is 1 words. 

/// STA num_pkts       : 133 

/// STA pkt_idx        : 255 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x4 

    0x03fc0485 // 324 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 72 (0x48) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt81_tmpl[] = {
    0xb8010048,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 17 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x1 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x08000011,// 3 SCX   1 

    0x8081281c,// 4 SCX   2 

    0x00003100,// 5 SCX   3 

    0xadf4ebc4,// 6 SCX   4 

    0x478bf908,// 7 SCX   5 

    0xcec20a19,// 8 SCX   6 

    0x137a53f9,// 9 SCX   7 

    0xb81adaa1,// 10 SCX   8 

    0x2dee0860,// 11 SCX   9 

    0x25964cc2,// 12 SCX  10 

    0x3c3ff92f,// 13 SCX  11 

    0xdfcdcf30,// 14 SCX  12 

    0x5dde79c8,// 15 SCX  13 

    0x397dca45,// 16 SCX  14 

    0xa82025c0,// 17 SCX  15 

    0x95fb358b,// 18 SCX  16 

    0xcb929bb1,// 19 SCX  17 

/// BFD is 3 words. 

/// BFD tot_len        : 914 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 625 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 625 

/// BFD lencrypto      : 80 

/// BFD ofstcrypto     : 248 

/// BFD (ofst+len)cry  : 328 

/// BFD ofstiv         : 164 

/// BFD ofsticv        : 656 

    0x00000271,// 20 BFD   1 

    0x00f80050,// 21 BFD   2 

    0x029000a4,// 22 BFD   3 

/// MFM is 5 words. 

/// MFM vldnibs        : 22 

    0x2200015e,// 23 MFM   1 

    0x2aa03ea4,// 24 MFM   2 

    0xddd36631,// 25 MFM   3 

    0x3ca7e830,// 26 MFM   4 

    0x46471b00,// 27 MFM   5 

/// BDA is 230 words. 

/// BDA size     is 914 (0x392) 

/// BDA id       is 0xe599 

    0x0392e599,// 28 BDA   1 

/// PAY Generic Data size   : 914 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0x94230425,// 29 PAY   1 

    0x6d8bcc38,// 30 PAY   2 

    0x8443b24b,// 31 PAY   3 

    0x86da18df,// 32 PAY   4 

    0x920289e5,// 33 PAY   5 

    0xa1304295,// 34 PAY   6 

    0x88008301,// 35 PAY   7 

    0x5f8dd84a,// 36 PAY   8 

    0x57ff1870,// 37 PAY   9 

    0x53c84c1a,// 38 PAY  10 

    0x225ddf92,// 39 PAY  11 

    0xf3575e80,// 40 PAY  12 

    0xd5506bb7,// 41 PAY  13 

    0x9b498e56,// 42 PAY  14 

    0xaaf46576,// 43 PAY  15 

    0x3f51643c,// 44 PAY  16 

    0xc00cacac,// 45 PAY  17 

    0x93b60e1a,// 46 PAY  18 

    0xb596f2e4,// 47 PAY  19 

    0x9bc0ec5b,// 48 PAY  20 

    0x55e49ac3,// 49 PAY  21 

    0x9e246637,// 50 PAY  22 

    0x1d2fa965,// 51 PAY  23 

    0xdb5e9973,// 52 PAY  24 

    0x76412bf2,// 53 PAY  25 

    0xeb0b2483,// 54 PAY  26 

    0xf3f9b941,// 55 PAY  27 

    0xecebc5d1,// 56 PAY  28 

    0xa91e8c32,// 57 PAY  29 

    0x87a68a14,// 58 PAY  30 

    0x69c2a85e,// 59 PAY  31 

    0x9fd18715,// 60 PAY  32 

    0x12760fb4,// 61 PAY  33 

    0xb5415d2b,// 62 PAY  34 

    0x4fce6c94,// 63 PAY  35 

    0x459f143d,// 64 PAY  36 

    0x6f76a89f,// 65 PAY  37 

    0x3a4ba348,// 66 PAY  38 

    0x5cf66e7c,// 67 PAY  39 

    0xf0c646dc,// 68 PAY  40 

    0x8dfd79d4,// 69 PAY  41 

    0x53fd7d0d,// 70 PAY  42 

    0x46d79d72,// 71 PAY  43 

    0x2a97ebba,// 72 PAY  44 

    0xd4ffefd7,// 73 PAY  45 

    0x009fab53,// 74 PAY  46 

    0x3df91fee,// 75 PAY  47 

    0xfbde531f,// 76 PAY  48 

    0x5c008d25,// 77 PAY  49 

    0x22f7a4aa,// 78 PAY  50 

    0x2c3f4de0,// 79 PAY  51 

    0x58b36a15,// 80 PAY  52 

    0xd0bdfef8,// 81 PAY  53 

    0xa6abb190,// 82 PAY  54 

    0xeb27e11e,// 83 PAY  55 

    0x59fc4f1c,// 84 PAY  56 

    0xed85a9ea,// 85 PAY  57 

    0xd2b6cd73,// 86 PAY  58 

    0x799a5d61,// 87 PAY  59 

    0xe056aeaa,// 88 PAY  60 

    0x357f8a31,// 89 PAY  61 

    0xd7ec6a84,// 90 PAY  62 

    0x23729bb7,// 91 PAY  63 

    0x20526c37,// 92 PAY  64 

    0x1e19bee0,// 93 PAY  65 

    0x7b49eb34,// 94 PAY  66 

    0x684f2cca,// 95 PAY  67 

    0x9c274b8c,// 96 PAY  68 

    0x2f57b8ab,// 97 PAY  69 

    0x3f8ed652,// 98 PAY  70 

    0x45305fc7,// 99 PAY  71 

    0x16569f7a,// 100 PAY  72 

    0x38f32dcf,// 101 PAY  73 

    0xcf20a620,// 102 PAY  74 

    0xd6f9c8b1,// 103 PAY  75 

    0x4f8bbc52,// 104 PAY  76 

    0x5327525f,// 105 PAY  77 

    0xcddb70c8,// 106 PAY  78 

    0xf600fc09,// 107 PAY  79 

    0xb7ee9179,// 108 PAY  80 

    0xf993adf3,// 109 PAY  81 

    0x8dc0a477,// 110 PAY  82 

    0xfbc0c7bb,// 111 PAY  83 

    0x8427a613,// 112 PAY  84 

    0x27f5892c,// 113 PAY  85 

    0xe62661b3,// 114 PAY  86 

    0x6f2d63f4,// 115 PAY  87 

    0x49527b96,// 116 PAY  88 

    0x287b2b74,// 117 PAY  89 

    0xab2ca7c0,// 118 PAY  90 

    0x0938a645,// 119 PAY  91 

    0xc18ff1fd,// 120 PAY  92 

    0x646c6c82,// 121 PAY  93 

    0x76b1d57d,// 122 PAY  94 

    0xdb86a778,// 123 PAY  95 

    0x992c6ffe,// 124 PAY  96 

    0x4f6ec91b,// 125 PAY  97 

    0x2f045ee6,// 126 PAY  98 

    0xa32a56fb,// 127 PAY  99 

    0xda0ea239,// 128 PAY 100 

    0xc519621c,// 129 PAY 101 

    0xd48ab583,// 130 PAY 102 

    0x66407d86,// 131 PAY 103 

    0x9bcdc3fe,// 132 PAY 104 

    0xe07a8bdc,// 133 PAY 105 

    0xc25534f6,// 134 PAY 106 

    0x9c3851b2,// 135 PAY 107 

    0x3491a0cd,// 136 PAY 108 

    0x44c768ff,// 137 PAY 109 

    0x08f18bc4,// 138 PAY 110 

    0x53c019f0,// 139 PAY 111 

    0x4cab9e7d,// 140 PAY 112 

    0x37a884f9,// 141 PAY 113 

    0xa53e1357,// 142 PAY 114 

    0x42011228,// 143 PAY 115 

    0x4ed7d08d,// 144 PAY 116 

    0x2a964ac8,// 145 PAY 117 

    0x98c630b0,// 146 PAY 118 

    0x7bc2bca7,// 147 PAY 119 

    0x04cfc317,// 148 PAY 120 

    0xfc1ce5de,// 149 PAY 121 

    0x6e036a89,// 150 PAY 122 

    0x1a9ce7e9,// 151 PAY 123 

    0xab26edea,// 152 PAY 124 

    0xb2939101,// 153 PAY 125 

    0x0c3a3523,// 154 PAY 126 

    0x440e1b4e,// 155 PAY 127 

    0x633d6f85,// 156 PAY 128 

    0x67b98601,// 157 PAY 129 

    0xa2ccbee3,// 158 PAY 130 

    0xfc863b9d,// 159 PAY 131 

    0x0493c2f1,// 160 PAY 132 

    0xe8bebf9b,// 161 PAY 133 

    0x8954ba02,// 162 PAY 134 

    0xdd5d00ac,// 163 PAY 135 

    0x59bb9515,// 164 PAY 136 

    0x5471581e,// 165 PAY 137 

    0x0dbe226b,// 166 PAY 138 

    0xbe6d5324,// 167 PAY 139 

    0xce6ab920,// 168 PAY 140 

    0x4ed8580e,// 169 PAY 141 

    0xdef7db4b,// 170 PAY 142 

    0xbc4c035a,// 171 PAY 143 

    0x64122b44,// 172 PAY 144 

    0xf83eb135,// 173 PAY 145 

    0xc3027e22,// 174 PAY 146 

    0x49e9f2df,// 175 PAY 147 

    0x3f20be0f,// 176 PAY 148 

    0x4a5860f1,// 177 PAY 149 

    0x94558a0c,// 178 PAY 150 

    0x66d48a0c,// 179 PAY 151 

    0xc0b0b2c9,// 180 PAY 152 

    0xc9bdec6f,// 181 PAY 153 

    0x50fba84a,// 182 PAY 154 

    0xfffb7de1,// 183 PAY 155 

    0xc23bb6da,// 184 PAY 156 

    0x6bd7e5ba,// 185 PAY 157 

    0xb19780b2,// 186 PAY 158 

    0xd08d3fde,// 187 PAY 159 

    0xac9f8aad,// 188 PAY 160 

    0x85a23697,// 189 PAY 161 

    0x7b719f9e,// 190 PAY 162 

    0x79de39bc,// 191 PAY 163 

    0xdee43a7e,// 192 PAY 164 

    0x728b47b7,// 193 PAY 165 

    0x323876d0,// 194 PAY 166 

    0x59f642b8,// 195 PAY 167 

    0x8940edb4,// 196 PAY 168 

    0xb2cffda7,// 197 PAY 169 

    0x8aa0a788,// 198 PAY 170 

    0x2a0fafc6,// 199 PAY 171 

    0x09642262,// 200 PAY 172 

    0xa9b3cfdf,// 201 PAY 173 

    0x8061ae36,// 202 PAY 174 

    0xb1f4ab69,// 203 PAY 175 

    0xe80eee85,// 204 PAY 176 

    0x2db26279,// 205 PAY 177 

    0xd550e4ca,// 206 PAY 178 

    0x4f934677,// 207 PAY 179 

    0x7a9f3c33,// 208 PAY 180 

    0x0961d5a7,// 209 PAY 181 

    0x22fabbb0,// 210 PAY 182 

    0x3d76dd7a,// 211 PAY 183 

    0x13eae999,// 212 PAY 184 

    0xa1fd140e,// 213 PAY 185 

    0x9d596bdb,// 214 PAY 186 

    0x9de514c7,// 215 PAY 187 

    0xc219dd77,// 216 PAY 188 

    0x7de487ec,// 217 PAY 189 

    0x4b0194ae,// 218 PAY 190 

    0xe0f84e54,// 219 PAY 191 

    0x601cf868,// 220 PAY 192 

    0xaff7d714,// 221 PAY 193 

    0x745610af,// 222 PAY 194 

    0xdb20ddf8,// 223 PAY 195 

    0x3fbecfef,// 224 PAY 196 

    0xefc9aae3,// 225 PAY 197 

    0x0b202a3b,// 226 PAY 198 

    0x0ef7a387,// 227 PAY 199 

    0x02a2c025,// 228 PAY 200 

    0x9c57ed21,// 229 PAY 201 

    0xbf4bf1aa,// 230 PAY 202 

    0xd93993e1,// 231 PAY 203 

    0xf34ce29a,// 232 PAY 204 

    0x6efe0d8f,// 233 PAY 205 

    0x60825ff1,// 234 PAY 206 

    0x4f72bf4b,// 235 PAY 207 

    0x3a114a0a,// 236 PAY 208 

    0xbb2cd7da,// 237 PAY 209 

    0xd8d31723,// 238 PAY 210 

    0xdc9db719,// 239 PAY 211 

    0x5a5eae8e,// 240 PAY 212 

    0x1a5e9b9b,// 241 PAY 213 

    0x67009260,// 242 PAY 214 

    0x0b6b5ff5,// 243 PAY 215 

    0x308aa2df,// 244 PAY 216 

    0xe733cc0b,// 245 PAY 217 

    0xa393335d,// 246 PAY 218 

    0x39f9acb3,// 247 PAY 219 

    0x86f13115,// 248 PAY 220 

    0x40b06392,// 249 PAY 221 

    0xaf5851ef,// 250 PAY 222 

    0xff50520a,// 251 PAY 223 

    0xc208aad5,// 252 PAY 224 

    0x51a76c53,// 253 PAY 225 

    0x6615a927,// 254 PAY 226 

    0x90c62b9b,// 255 PAY 227 

    0x5a7b2da5,// 256 PAY 228 

    0x0b720000,// 257 PAY 229 

/// STA is 1 words. 

/// STA num_pkts       : 210 

/// STA pkt_idx        : 251 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x1f 

    0x03ed1fd2 // 258 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 96 (0x60) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt82_tmpl[] = {
    0xb8010060,// 1 CCH   1 

/// ECH cache_idx      : 0x06 

/// ECH pdu_tag        : 0x00 

    0x00060000,// 2 ECH   1 

/// SCX is 23 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv !check_icv sctx_iv  

/// SCX exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : AES256 

/// SCX aes_mode        : CBC 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x4 

/// SCX cryptokey_size  : 32 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000017,// 3 SCX   1 

    0x808628ab,// 4 SCX   2 

    0x000003c4,// 5 SCX   3 

    0x8f277c0a,// 6 SCX   4 

    0x12a933ea,// 7 SCX   5 

    0x2d365d71,// 8 SCX   6 

    0x461512a6,// 9 SCX   7 

    0xfd097baa,// 10 SCX   8 

    0x1401f307,// 11 SCX   9 

    0x0e35b84d,// 12 SCX  10 

    0x232fe176,// 13 SCX  11 

    0x19adfa66,// 14 SCX  12 

    0xd74b6797,// 15 SCX  13 

    0xc5023848,// 16 SCX  14 

    0x7a3e0acb,// 17 SCX  15 

    0xfce1f836,// 18 SCX  16 

    0x7c96e04e,// 19 SCX  17 

    0x6973b00c,// 20 SCX  18 

    0xf8751509,// 21 SCX  19 

    0x84bdecb2,// 22 SCX  20 

    0xaba3a179,// 23 SCX  21 

    0xcbc75ce5,// 24 SCX  22 

    0x913c6a41,// 25 SCX  23 

/// BFD is 3 words. 

/// BFD tot_len        : 326 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 159 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 159 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 124 

/// BFD (ofst+len)cry  : 156 

/// BFD ofstiv         : 64 

/// BFD ofsticv        : 168 

    0x0000009f,// 26 BFD   1 

    0x007c0020,// 27 BFD   2 

    0x00a80040,// 28 BFD   3 

/// MFM is 3 words. 

/// MFM vldnibs        : 10 

    0x1000a09d,// 29 MFM   1 

    0x006b950c,// 30 MFM   2 

    0x26770000,// 31 MFM   3 

/// BDA is 83 words. 

/// BDA size     is 326 (0x146) 

/// BDA id       is 0x8517 

    0x01468517,// 32 BDA   1 

/// PAY Generic Data size   : 326 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xe1a2d3a3,// 33 PAY   1 

    0xa4ae1a85,// 34 PAY   2 

    0x715d1c2f,// 35 PAY   3 

    0x527f5a14,// 36 PAY   4 

    0xbdde675b,// 37 PAY   5 

    0x66494114,// 38 PAY   6 

    0x908e957b,// 39 PAY   7 

    0x90c7f957,// 40 PAY   8 

    0x2bf2816d,// 41 PAY   9 

    0x20cdbae3,// 42 PAY  10 

    0x00eda6e9,// 43 PAY  11 

    0x9619b3d5,// 44 PAY  12 

    0xf82c60cd,// 45 PAY  13 

    0x22178c5c,// 46 PAY  14 

    0x882a41ef,// 47 PAY  15 

    0x8adbab1d,// 48 PAY  16 

    0x92e4795e,// 49 PAY  17 

    0x7bab02f1,// 50 PAY  18 

    0xb77e7b5c,// 51 PAY  19 

    0x340b2f28,// 52 PAY  20 

    0x060ae5de,// 53 PAY  21 

    0xb3d968cd,// 54 PAY  22 

    0x5d8249ed,// 55 PAY  23 

    0x15cd0d6f,// 56 PAY  24 

    0xf70ccb11,// 57 PAY  25 

    0xeed59214,// 58 PAY  26 

    0x20e20b4e,// 59 PAY  27 

    0xe685694a,// 60 PAY  28 

    0x57d9e6a2,// 61 PAY  29 

    0xe4ce15a6,// 62 PAY  30 

    0x6870f1b0,// 63 PAY  31 

    0x61d11962,// 64 PAY  32 

    0x14de7f0a,// 65 PAY  33 

    0x72d9ff22,// 66 PAY  34 

    0xadcd8c72,// 67 PAY  35 

    0x8a9fbbc2,// 68 PAY  36 

    0x75327e20,// 69 PAY  37 

    0xdee599b6,// 70 PAY  38 

    0xe8b847d4,// 71 PAY  39 

    0xdf01f985,// 72 PAY  40 

    0x4ee71f7e,// 73 PAY  41 

    0x3264d1c5,// 74 PAY  42 

    0x4294a60d,// 75 PAY  43 

    0x57639a0f,// 76 PAY  44 

    0x3a42e6ae,// 77 PAY  45 

    0xf623077a,// 78 PAY  46 

    0x4a3ccd68,// 79 PAY  47 

    0x44ae72fe,// 80 PAY  48 

    0xee50ef4a,// 81 PAY  49 

    0x0bcee416,// 82 PAY  50 

    0x69c85e12,// 83 PAY  51 

    0xc125ea04,// 84 PAY  52 

    0x245e8843,// 85 PAY  53 

    0xc09e2ef5,// 86 PAY  54 

    0x986b0f6b,// 87 PAY  55 

    0x84db9c50,// 88 PAY  56 

    0x1297b421,// 89 PAY  57 

    0x395d6c5c,// 90 PAY  58 

    0xbd27924f,// 91 PAY  59 

    0x2cd0ac9e,// 92 PAY  60 

    0x1399f1ae,// 93 PAY  61 

    0x9723f5c7,// 94 PAY  62 

    0xe3c21aa7,// 95 PAY  63 

    0x8da1031b,// 96 PAY  64 

    0x7baef824,// 97 PAY  65 

    0x8243f1b8,// 98 PAY  66 

    0xe4279c7f,// 99 PAY  67 

    0xf6ee366f,// 100 PAY  68 

    0xe9c5ce5d,// 101 PAY  69 

    0xd0d560c1,// 102 PAY  70 

    0x4c024901,// 103 PAY  71 

    0x8a2d8d44,// 104 PAY  72 

    0x7d00b943,// 105 PAY  73 

    0x040e94cd,// 106 PAY  74 

    0x3ab1a727,// 107 PAY  75 

    0x0b2187f4,// 108 PAY  76 

    0xfd052d1c,// 109 PAY  77 

    0x4732be9c,// 110 PAY  78 

    0xd233acf0,// 111 PAY  79 

    0xf685114f,// 112 PAY  80 

    0x4fdbbed9,// 113 PAY  81 

    0xdd120000,// 114 PAY  82 

/// STA is 1 words. 

/// STA num_pkts       : 81 

/// STA pkt_idx        : 247 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xdc 

    0x03dcdc51 // 115 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 80 (0x50) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt83_tmpl[] = {
    0xb8010050,// 1 CCH   1 

/// ECH cache_idx      : 0x0f 

/// ECH pdu_tag        : 0x00 

    0x000f0000,// 2 ECH   1 

/// SCX is 19 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv insert_icv !check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000013,// 3 SCX   1 

    0x80902853,// 4 SCX   2 

    0x00002382,// 5 SCX   3 

    0x79977ea9,// 6 SCX   4 

    0xf1e2ae03,// 7 SCX   5 

    0xb9050b61,// 8 SCX   6 

    0xa888e3b0,// 9 SCX   7 

    0x32fd3cf7,// 10 SCX   8 

    0xc851297e,// 11 SCX   9 

    0xc939c3fd,// 12 SCX  10 

    0x1e093ebb,// 13 SCX  11 

    0xbcf77dde,// 14 SCX  12 

    0xf1ab0f72,// 15 SCX  13 

    0xfc085ac8,// 16 SCX  14 

    0x810e69fa,// 17 SCX  15 

    0xab6ba3c1,// 18 SCX  16 

    0x8e641d2c,// 19 SCX  17 

    0xc78cbbe1,// 20 SCX  18 

    0xc1532387,// 21 SCX  19 

/// BFD is 3 words. 

/// BFD tot_len        : 812 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 724 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 724 

/// BFD lencrypto      : 112 

/// BFD ofstcrypto     : 524 

/// BFD (ofst+len)cry  : 636 

/// BFD ofstiv         : 168 

/// BFD ofsticv        : 752 

    0x000002d4,// 22 BFD   1 

    0x020c0070,// 23 BFD   2 

    0x02f000a8,// 24 BFD   3 

/// MFM is 16 words. 

/// MFM vldnibs        : 7c 

    0x7c007043,// 25 MFM   1 

    0xf63cb23b,// 26 MFM   2 

    0x6fbab7c8,// 27 MFM   3 

    0x3c164ff6,// 28 MFM   4 

    0x369059b0,// 29 MFM   5 

    0x4ff76c24,// 30 MFM   6 

    0x37715bae,// 31 MFM   7 

    0x691f52ca,// 32 MFM   8 

    0xce808c65,// 33 MFM   9 

    0xc54ab6d7,// 34 MFM  10 

    0xb09583e2,// 35 MFM  11 

    0x7da02b0a,// 36 MFM  12 

    0x18941163,// 37 MFM  13 

    0xfbd0879d,// 38 MFM  14 

    0x6bf8555f,// 39 MFM  15 

    0x5c160f06,// 40 MFM  16 

/// BDA is 204 words. 

/// BDA size     is 812 (0x32c) 

/// BDA id       is 0x8d6d 

    0x032c8d6d,// 41 BDA   1 

/// PAY Generic Data size   : 812 byte(s) 

/// PAD Buffer Data Pad size   : 0 byte(s) 

    0x54173ba1,// 42 PAY   1 

    0x1e0218fd,// 43 PAY   2 

    0x13ee3fcd,// 44 PAY   3 

    0xfca0e32d,// 45 PAY   4 

    0x175f4b32,// 46 PAY   5 

    0x557f8214,// 47 PAY   6 

    0x0a073bfb,// 48 PAY   7 

    0x69926f2c,// 49 PAY   8 

    0xef1dc559,// 50 PAY   9 

    0x59f7daed,// 51 PAY  10 

    0x788a96bc,// 52 PAY  11 

    0x671972a9,// 53 PAY  12 

    0x5d9e4d4a,// 54 PAY  13 

    0x3e4da874,// 55 PAY  14 

    0xd11cc43f,// 56 PAY  15 

    0x31a35934,// 57 PAY  16 

    0x12284260,// 58 PAY  17 

    0xdcd293de,// 59 PAY  18 

    0xd0fc72aa,// 60 PAY  19 

    0x71e325df,// 61 PAY  20 

    0xc28521ee,// 62 PAY  21 

    0x6f8c8eb6,// 63 PAY  22 

    0xff633c45,// 64 PAY  23 

    0x56f84a2c,// 65 PAY  24 

    0x1f9705ba,// 66 PAY  25 

    0xd142f485,// 67 PAY  26 

    0x909c79e8,// 68 PAY  27 

    0x6bd046d6,// 69 PAY  28 

    0xd21d2fea,// 70 PAY  29 

    0xe521f8c3,// 71 PAY  30 

    0x88e5a38b,// 72 PAY  31 

    0xd9b92207,// 73 PAY  32 

    0x29eca6e0,// 74 PAY  33 

    0xe6e1a723,// 75 PAY  34 

    0x46e944e2,// 76 PAY  35 

    0xf6a9dfd1,// 77 PAY  36 

    0xfb150425,// 78 PAY  37 

    0x36a1c73d,// 79 PAY  38 

    0x1c12f23b,// 80 PAY  39 

    0x4a7d8386,// 81 PAY  40 

    0xb0444711,// 82 PAY  41 

    0x4a19588c,// 83 PAY  42 

    0x51c819cd,// 84 PAY  43 

    0xd18ca433,// 85 PAY  44 

    0xbaed1e5e,// 86 PAY  45 

    0x23170e0c,// 87 PAY  46 

    0x59f3172a,// 88 PAY  47 

    0xa2599579,// 89 PAY  48 

    0xc2359d5c,// 90 PAY  49 

    0x0a74fcf4,// 91 PAY  50 

    0x23ef5473,// 92 PAY  51 

    0x6e8dfe20,// 93 PAY  52 

    0x3872cea7,// 94 PAY  53 

    0x2c11878e,// 95 PAY  54 

    0xeae37ae2,// 96 PAY  55 

    0xdaa3772a,// 97 PAY  56 

    0x75f9efd1,// 98 PAY  57 

    0xdbe1d59a,// 99 PAY  58 

    0x3f651cdb,// 100 PAY  59 

    0xeba98aa9,// 101 PAY  60 

    0xf34f09ba,// 102 PAY  61 

    0xb02dd938,// 103 PAY  62 

    0x4ea74df8,// 104 PAY  63 

    0x0cf49eef,// 105 PAY  64 

    0x6e816aa8,// 106 PAY  65 

    0x0b32234f,// 107 PAY  66 

    0xee701258,// 108 PAY  67 

    0xc433fd04,// 109 PAY  68 

    0x5260b796,// 110 PAY  69 

    0x052ade5b,// 111 PAY  70 

    0x41a966ad,// 112 PAY  71 

    0x85105bc7,// 113 PAY  72 

    0x7597db59,// 114 PAY  73 

    0xbd960b34,// 115 PAY  74 

    0x9a86b8bd,// 116 PAY  75 

    0x938f18d5,// 117 PAY  76 

    0xa502a7ed,// 118 PAY  77 

    0x1c74eb5a,// 119 PAY  78 

    0x62f273d8,// 120 PAY  79 

    0x37fa9063,// 121 PAY  80 

    0xed9f424a,// 122 PAY  81 

    0xf5a970fe,// 123 PAY  82 

    0x5f165cc4,// 124 PAY  83 

    0xe16a270c,// 125 PAY  84 

    0x0b3c2733,// 126 PAY  85 

    0xd5745bb8,// 127 PAY  86 

    0x0ee00a28,// 128 PAY  87 

    0x06733a55,// 129 PAY  88 

    0x428b7432,// 130 PAY  89 

    0x74d23e01,// 131 PAY  90 

    0x2be56125,// 132 PAY  91 

    0x8a400792,// 133 PAY  92 

    0x028ae596,// 134 PAY  93 

    0xb20875b3,// 135 PAY  94 

    0xc00bf066,// 136 PAY  95 

    0x21477532,// 137 PAY  96 

    0x62261918,// 138 PAY  97 

    0xd33b9a9f,// 139 PAY  98 

    0xd0d3ab74,// 140 PAY  99 

    0xb1d22169,// 141 PAY 100 

    0x13dec11e,// 142 PAY 101 

    0x39318545,// 143 PAY 102 

    0xe6e4505b,// 144 PAY 103 

    0x941ff45e,// 145 PAY 104 

    0x66063f3a,// 146 PAY 105 

    0x150466df,// 147 PAY 106 

    0x181ce2cd,// 148 PAY 107 

    0x4a52a3a8,// 149 PAY 108 

    0x9c7f3a54,// 150 PAY 109 

    0xe52031d9,// 151 PAY 110 

    0xd5d053b7,// 152 PAY 111 

    0xfa09ad09,// 153 PAY 112 

    0x22ccfadc,// 154 PAY 113 

    0xda0417bf,// 155 PAY 114 

    0x791e92a1,// 156 PAY 115 

    0xf21c84b9,// 157 PAY 116 

    0x47343679,// 158 PAY 117 

    0xdc2991b8,// 159 PAY 118 

    0x98003b30,// 160 PAY 119 

    0x60f6bc5b,// 161 PAY 120 

    0x08c3a8b5,// 162 PAY 121 

    0x58926b5d,// 163 PAY 122 

    0xf41cacb8,// 164 PAY 123 

    0x72b746bd,// 165 PAY 124 

    0xd9a0e195,// 166 PAY 125 

    0x0c6769e9,// 167 PAY 126 

    0x9743a9c5,// 168 PAY 127 

    0x5ce5e368,// 169 PAY 128 

    0x81c83c23,// 170 PAY 129 

    0x8558720b,// 171 PAY 130 

    0xde035db5,// 172 PAY 131 

    0xbe8bc77f,// 173 PAY 132 

    0x577fc2d5,// 174 PAY 133 

    0x0c0c13c3,// 175 PAY 134 

    0xed800197,// 176 PAY 135 

    0xbce2d3bd,// 177 PAY 136 

    0x5d94948f,// 178 PAY 137 

    0xa1b41ba6,// 179 PAY 138 

    0x26869a75,// 180 PAY 139 

    0xb63d32e0,// 181 PAY 140 

    0xaf8e6439,// 182 PAY 141 

    0x4ecabc54,// 183 PAY 142 

    0x3b0da57b,// 184 PAY 143 

    0xc197d1f5,// 185 PAY 144 

    0x6019ec1a,// 186 PAY 145 

    0xf7789d76,// 187 PAY 146 

    0x5fb6d1bc,// 188 PAY 147 

    0x9574102a,// 189 PAY 148 

    0xdb83515b,// 190 PAY 149 

    0x715a34da,// 191 PAY 150 

    0x3ce73a40,// 192 PAY 151 

    0x1d1c8eb9,// 193 PAY 152 

    0xbfaacb54,// 194 PAY 153 

    0x19ce7dd7,// 195 PAY 154 

    0xbfd03621,// 196 PAY 155 

    0x138bc7bc,// 197 PAY 156 

    0x87b69e0d,// 198 PAY 157 

    0x262fcecc,// 199 PAY 158 

    0x786384cc,// 200 PAY 159 

    0xd0ad3359,// 201 PAY 160 

    0xd6a5bf45,// 202 PAY 161 

    0x33a8421b,// 203 PAY 162 

    0x006dccbd,// 204 PAY 163 

    0x459835f2,// 205 PAY 164 

    0x67ca43db,// 206 PAY 165 

    0xa36cba42,// 207 PAY 166 

    0x723184f1,// 208 PAY 167 

    0xa482902c,// 209 PAY 168 

    0x1b2b20d1,// 210 PAY 169 

    0x8691c5de,// 211 PAY 170 

    0xce49e9c3,// 212 PAY 171 

    0x42268132,// 213 PAY 172 

    0x783261be,// 214 PAY 173 

    0xa3277dde,// 215 PAY 174 

    0xb6b2c76f,// 216 PAY 175 

    0x4c5e5568,// 217 PAY 176 

    0x951e0a48,// 218 PAY 177 

    0x39559662,// 219 PAY 178 

    0xaed2ddd3,// 220 PAY 179 

    0x78e3fa26,// 221 PAY 180 

    0x2bf77fa6,// 222 PAY 181 

    0xa941e93a,// 223 PAY 182 

    0xc3fad5ba,// 224 PAY 183 

    0xb35004a6,// 225 PAY 184 

    0x2102bb5e,// 226 PAY 185 

    0xd8556deb,// 227 PAY 186 

    0x6e7c3ef5,// 228 PAY 187 

    0x0246f9dd,// 229 PAY 188 

    0x5fdc88b7,// 230 PAY 189 

    0x16be45b1,// 231 PAY 190 

    0xbad4c285,// 232 PAY 191 

    0xf5277b33,// 233 PAY 192 

    0xdf8f7de9,// 234 PAY 193 

    0x30ddfa26,// 235 PAY 194 

    0x9134daaa,// 236 PAY 195 

    0x33fda7f6,// 237 PAY 196 

    0x62d65833,// 238 PAY 197 

    0xc2bc7eea,// 239 PAY 198 

    0xc37dadf8,// 240 PAY 199 

    0x32b3958b,// 241 PAY 200 

    0x5bd124cc,// 242 PAY 201 

    0x40202be2,// 243 PAY 202 

    0x871ca3b1,// 244 PAY 203 

/// STA is 1 words. 

/// STA num_pkts       : 73 

/// STA pkt_idx        : 206 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0x16 

    0x03391649 // 245 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 64 (0x40) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt84_tmpl[] = {
    0xb8010040,// 1 CCH   1 

/// ECH cache_idx      : 0x0e 

/// ECH pdu_tag        : 0x00 

    0x000e0000,// 2 ECH   1 

/// SCX is 15 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound save_icv !insert_icv check_icv !sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : NORMAL_RC4INIT_AES128 

/// SCX aes_mode        : ECB 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x3 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x0 

/// SCX cryptokey_size  : 16 

/// SCX cryptoiv_size   : 0 

/// SCX authctx_size    : 32 

    0x0800000f,// 3 SCX   1 

    0x8080287c,// 4 SCX   2 

    0x00005300,// 5 SCX   3 

    0x7c784d68,// 6 SCX   4 

    0xe38a76ac,// 7 SCX   5 

    0xece11010,// 8 SCX   6 

    0xbc101ef9,// 9 SCX   7 

    0xd7e5108c,// 10 SCX   8 

    0xcdbe1d5f,// 11 SCX   9 

    0x747f5c5f,// 12 SCX  10 

    0x3b1b3d44,// 13 SCX  11 

    0x0c4f67a4,// 14 SCX  12 

    0xb1ea9b73,// 15 SCX  13 

    0x646987f1,// 16 SCX  14 

    0x41d21022,// 17 SCX  15 

/// BFD is 3 words. 

/// BFD tot_len        : 694 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCBC 

/// BFD lenmac         : 440 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 440 

/// BFD lencrypto      : 32 

/// BFD ofstcrypto     : 400 

/// BFD (ofst+len)cry  : 432 

/// BFD ofstiv         : 368 

/// BFD ofsticv        : 564 

    0x000001b8,// 18 BFD   1 

    0x01900020,// 19 BFD   2 

    0x02340170,// 20 BFD   3 

/// MFM is 13 words. 

/// MFM vldnibs        : 5f 

    0x5f00c046,// 21 MFM   1 

    0xa46afc68,// 22 MFM   2 

    0x9962a95e,// 23 MFM   3 

    0xcc138544,// 24 MFM   4 

    0x49ea920c,// 25 MFM   5 

    0xc104de8d,// 26 MFM   6 

    0x7434d0f6,// 27 MFM   7 

    0x9e4d145a,// 28 MFM   8 

    0x3fb88d69,// 29 MFM   9 

    0x7f2cdaa9,// 30 MFM  10 

    0x9ecce59f,// 31 MFM  11 

    0x903daaa5,// 32 MFM  12 

    0x6a500000,// 33 MFM  13 

/// BDA is 175 words. 

/// BDA size     is 694 (0x2b6) 

/// BDA id       is 0x8ef 

    0x02b608ef,// 34 BDA   1 

/// PAY Generic Data size   : 694 byte(s) 

/// PAD Buffer Data Pad size   : 2 byte(s) 

    0xe10f4253,// 35 PAY   1 

    0x2ae8f95d,// 36 PAY   2 

    0x94e2c3cb,// 37 PAY   3 

    0xce1a5858,// 38 PAY   4 

    0x1f66b70a,// 39 PAY   5 

    0x78793d2e,// 40 PAY   6 

    0x96d97e28,// 41 PAY   7 

    0xba7b18c0,// 42 PAY   8 

    0xbd634ce0,// 43 PAY   9 

    0x4a2b40d7,// 44 PAY  10 

    0x2aac08df,// 45 PAY  11 

    0x59188c0f,// 46 PAY  12 

    0x19346625,// 47 PAY  13 

    0x58bf65b2,// 48 PAY  14 

    0x35b584a9,// 49 PAY  15 

    0xd25c1a33,// 50 PAY  16 

    0x8fec958d,// 51 PAY  17 

    0x513bfce8,// 52 PAY  18 

    0xcb4bc9b5,// 53 PAY  19 

    0x345f339a,// 54 PAY  20 

    0xa018fdcb,// 55 PAY  21 

    0xb903aa28,// 56 PAY  22 

    0xbf8045ee,// 57 PAY  23 

    0x8a344f53,// 58 PAY  24 

    0xe596b21a,// 59 PAY  25 

    0x90ef5508,// 60 PAY  26 

    0x4eb40ae2,// 61 PAY  27 

    0x6da42f72,// 62 PAY  28 

    0x6b913555,// 63 PAY  29 

    0x7df7f9ae,// 64 PAY  30 

    0x74a4dd2c,// 65 PAY  31 

    0x547c3890,// 66 PAY  32 

    0x7a554b9a,// 67 PAY  33 

    0x9574de71,// 68 PAY  34 

    0x4c6744f8,// 69 PAY  35 

    0x44763556,// 70 PAY  36 

    0xe3b96274,// 71 PAY  37 

    0xed8e9420,// 72 PAY  38 

    0x14fb0b7a,// 73 PAY  39 

    0xcd71f94a,// 74 PAY  40 

    0xb8866231,// 75 PAY  41 

    0xb826cf93,// 76 PAY  42 

    0x237164d5,// 77 PAY  43 

    0xcc49bf10,// 78 PAY  44 

    0xa5c0ec07,// 79 PAY  45 

    0x323f93ea,// 80 PAY  46 

    0xb1354502,// 81 PAY  47 

    0xd9028538,// 82 PAY  48 

    0xe8dbb344,// 83 PAY  49 

    0x6883436f,// 84 PAY  50 

    0xbb2117f9,// 85 PAY  51 

    0x83960ec6,// 86 PAY  52 

    0x6fb6cf41,// 87 PAY  53 

    0xa431a25c,// 88 PAY  54 

    0x527e83ff,// 89 PAY  55 

    0xd6f94d60,// 90 PAY  56 

    0x7e4a5973,// 91 PAY  57 

    0xd369b1b3,// 92 PAY  58 

    0xbe0c3d70,// 93 PAY  59 

    0xdfde5652,// 94 PAY  60 

    0x9b3b0617,// 95 PAY  61 

    0x606de13b,// 96 PAY  62 

    0x7f4b900b,// 97 PAY  63 

    0x8bdf4526,// 98 PAY  64 

    0x56bc6665,// 99 PAY  65 

    0xec4d3f1c,// 100 PAY  66 

    0x6020e600,// 101 PAY  67 

    0x91151d0a,// 102 PAY  68 

    0xd7afb158,// 103 PAY  69 

    0x17367c4c,// 104 PAY  70 

    0x7cd746d0,// 105 PAY  71 

    0xf9bc1e29,// 106 PAY  72 

    0x2d8e9694,// 107 PAY  73 

    0x92dc16dd,// 108 PAY  74 

    0xd3263e63,// 109 PAY  75 

    0x503b3bbc,// 110 PAY  76 

    0xeb53c9a0,// 111 PAY  77 

    0x7e6ae970,// 112 PAY  78 

    0x499c8b98,// 113 PAY  79 

    0x7e8c3c14,// 114 PAY  80 

    0x34588efd,// 115 PAY  81 

    0x7eee850d,// 116 PAY  82 

    0xb779e92e,// 117 PAY  83 

    0xf1c865cc,// 118 PAY  84 

    0x8b00f71e,// 119 PAY  85 

    0x061cd096,// 120 PAY  86 

    0x234bc349,// 121 PAY  87 

    0x7aab9f50,// 122 PAY  88 

    0x13492f83,// 123 PAY  89 

    0xf6f4459d,// 124 PAY  90 

    0x74ffd6c4,// 125 PAY  91 

    0x5f68788b,// 126 PAY  92 

    0x644f79c8,// 127 PAY  93 

    0x07ab1194,// 128 PAY  94 

    0x340e4d4e,// 129 PAY  95 

    0xed9afba0,// 130 PAY  96 

    0xc2222841,// 131 PAY  97 

    0x11229757,// 132 PAY  98 

    0x96dd8c64,// 133 PAY  99 

    0xf39b1243,// 134 PAY 100 

    0x3e504291,// 135 PAY 101 

    0x3b3c4a28,// 136 PAY 102 

    0x74c80193,// 137 PAY 103 

    0x122cb7c8,// 138 PAY 104 

    0x217766a1,// 139 PAY 105 

    0xa35d3aa4,// 140 PAY 106 

    0x9aa5c91c,// 141 PAY 107 

    0x10c91683,// 142 PAY 108 

    0xe61eef37,// 143 PAY 109 

    0x22c4550b,// 144 PAY 110 

    0x5465dccf,// 145 PAY 111 

    0x218a6568,// 146 PAY 112 

    0x7369af7a,// 147 PAY 113 

    0x77cb6eae,// 148 PAY 114 

    0xb821e141,// 149 PAY 115 

    0x96007781,// 150 PAY 116 

    0x85205458,// 151 PAY 117 

    0x9006be85,// 152 PAY 118 

    0x56857217,// 153 PAY 119 

    0x4cea4010,// 154 PAY 120 

    0x6c78a71d,// 155 PAY 121 

    0x59206219,// 156 PAY 122 

    0xfa5dc3ff,// 157 PAY 123 

    0x9a5247a1,// 158 PAY 124 

    0xab798c61,// 159 PAY 125 

    0xf767aa5c,// 160 PAY 126 

    0x9f8daa28,// 161 PAY 127 

    0xc41cb42b,// 162 PAY 128 

    0x6b8df4df,// 163 PAY 129 

    0xc616ed27,// 164 PAY 130 

    0x2b10a9d7,// 165 PAY 131 

    0xcef4b446,// 166 PAY 132 

    0x29ba26fa,// 167 PAY 133 

    0xb90eeb08,// 168 PAY 134 

    0x3f04a85f,// 169 PAY 135 

    0x552d62ee,// 170 PAY 136 

    0x66129fcc,// 171 PAY 137 

    0x02419e0b,// 172 PAY 138 

    0x47b95783,// 173 PAY 139 

    0xfa32af51,// 174 PAY 140 

    0xb14d7c81,// 175 PAY 141 

    0x61687170,// 176 PAY 142 

    0x4a9e0853,// 177 PAY 143 

    0x94ede532,// 178 PAY 144 

    0x66aede3a,// 179 PAY 145 

    0x4241ad8f,// 180 PAY 146 

    0x84cf2841,// 181 PAY 147 

    0x9ba7bd90,// 182 PAY 148 

    0xb3abbbd3,// 183 PAY 149 

    0x1cb90bd4,// 184 PAY 150 

    0x67394d0e,// 185 PAY 151 

    0x3d8f4c04,// 186 PAY 152 

    0xc2c97f0f,// 187 PAY 153 

    0x57b3f1eb,// 188 PAY 154 

    0xa365d9ec,// 189 PAY 155 

    0xc4c41321,// 190 PAY 156 

    0x4ab6053f,// 191 PAY 157 

    0x52957e0b,// 192 PAY 158 

    0x5266814b,// 193 PAY 159 

    0x8af58d99,// 194 PAY 160 

    0xaea5079d,// 195 PAY 161 

    0x70e2b4a4,// 196 PAY 162 

    0x7eece6dc,// 197 PAY 163 

    0xc29d49a2,// 198 PAY 164 

    0xf6e04cec,// 199 PAY 165 

    0xb7555d24,// 200 PAY 166 

    0xa6b27ff6,// 201 PAY 167 

    0x3e555b96,// 202 PAY 168 

    0xce1d0564,// 203 PAY 169 

    0x4b364e61,// 204 PAY 170 

    0x78154c8c,// 205 PAY 171 

    0x74f7486f,// 206 PAY 172 

    0x0620c2f1,// 207 PAY 173 

    0x195c0000,// 208 PAY 174 

/// STA is 1 words. 

/// STA num_pkts       : 53 

/// STA pkt_idx        : 49 

/// STA err_code       : SUCCESS 

/// STA error_details  : 0xb4 

    0x00c4b435 // 209 STA   1 

};

//

/// CCH is 1 words  

/// CCH is NEW format  

/// CCH Opcode      = GENERIC (0x1) 

/// CCH CCTX length = 88 (0x58) 

/// CCH pipe select = 0 

/// CCH incl_sctx !incl_bct incl_bdesc incl_mfm  

/// CCH incl_bdata !incl_hash !incl_supdt !incl_sps !drop_bdata  

uint32 tx_aes_md5_pkt85_tmpl[] = {
    0xb8010058,// 1 CCH   1 

/// ECH cache_idx      : 0x04 

/// ECH pdu_tag        : 0x00 

    0x00040000,// 2 ECH   1 

/// SCX is 21 words. 

/// SCX SA Type (sa_type) GENERIC  

/// SCX !cacheable !update_en lock_en  

/// SCX inbound !save_icv !insert_icv check_icv sctx_iv  

/// SCX !exp_iv !gen_iv  

/// SCX order           : ENC_AUTH 

/// SCX encralg         : AES 

/// SCX authalg         : MD5 

/// SCX aes_size        : RC4UPDT_AES192 

/// SCX aes_mode        : CTR 

/// SCX authmode        : HMAC 

/// SCX authtype        : NORMAL_AES128 

/// SCX icv_size        : 0x4 

/// SCX iv_ovr_ofst     : 0x0 

/// SCX exp_iv_size     : 0x2 

/// SCX cryptokey_size  : 24 

/// SCX cryptoiv_size   : 16 

/// SCX authctx_size    : 32 

    0x08000015,// 3 SCX   1 

    0x8091287f,// 4 SCX   2 

    0x00001482,// 5 SCX   3 

    0xf286fac9,// 6 SCX   4 

    0x72c1f7fe,// 7 SCX   5 

    0xfe4c4405,// 8 SCX   6 

    0xe7011972,// 9 SCX   7 

    0x3322cb8b,// 10 SCX   8 

    0xcd8063d9,// 11 SCX   9 

    0x78be647e,// 12 SCX  10 

    0xf4e82fd5,// 13 SCX  11 

    0x884dae2d,// 14 SCX  12 

    0x78d220fa,// 15 SCX  13 

    0x18d8b55a,// 16 SCX  14 

    0x997133dc,// 17 SCX  15 

    0x19b9791c,// 18 SCX  16 

    0x0247d78a,// 19 SCX  17 

    0x6938a9a5,// 20 SCX  18 

    0x9d151e11,// 21 SCX  19 

    0x0501133b,// 22 SCX  20 

    0xda79cdce,// 23 SCX  21 

/// BFD is 3 words. 

/// BFD tot_len        : 1697 

/// BFD hdr_len        : 0 

/// BFD sad_type       : ESP_BOTH 

/// BFD crypto_type    : AESCTR 

/// BFD lenmac         : 971 

/// BFD ofstmac        : 0 

/// BFD (ofst+len)mac  : 971 

/// BFD lencrypto      : 20 

/// BFD ofstcrypto     : 760 

/// BFD (ofst+len)cry  : 780 

/// BFD ofstiv         : 484 

/// BFD ofsticv        : 1472 

    0x000003cb,// 24 BFD   1 

    0x02f80014,// 25 BFD   2 

    0x05c001e4,// 26 BFD   3 

/// MFM is 11 words. 

/// MFM vldnibs        : 52 

    0x5200b95f,// 27 MFM   1 

    0xb7060264,// 28 MFM   2 

    0x850346c8,// 29 MFM   3 

    0x565c23ad,// 30 MFM   4 

    0x32252a33,// 31 MFM   5 

    0xfa9a5be8,// 32 MFM   6 

    0xcf2a7c65,// 33 MFM   7 

    0x9442aca9,// 34 MFM   8 

    0x5fa823c8,// 35 MFM   9 

    0xe6075814,// 36 MFM  10 

    0x7672f000,// 37 MFM  11 

/// BDA is 426 words. 

/// BDA size     is 1697 (0x6a1) 

/// BDA id       is 0xca9 

    0x06a10ca9,// 38 BDA   1 

/// PAY Generic Data size   : 1697 byte(s) 

/// PAD Buffer Data Pad size   : 3 byte(s) 

    0x8630a9b3,// 39 PAY   1 

    0x24c6f4d3,// 40 PAY   2 

    0x21de246a,// 41 PAY   3 

    0xf20b2c33,// 42 PAY   4 

    0xfb044540,// 43 PAY   5 

    0x90b8f949,// 44 PAY   6 

    0x66bd8f66,// 45 PAY   7 

    0xec60668c,// 46 PAY   8 

    0x813d9c4d,// 47 PAY   9 

    0xdc208dad,// 48 PAY  10 

    0xaddc71b7,// 49 PAY  11 

    0x4860682b,// 50 PAY  12 

    0x39b759a7,// 51 PAY  13 

    0x9d3f4e8a,// 52 PAY  14 

    0x4e6c6bfc,// 53 PAY  15 

    0xa783a986,// 54 PAY  16 

    0x68953716,// 55 PAY  17 

    0xa66ad17d,// 56 PAY  18 

    0xde61c72a,// 57 PAY  19 

    0xc6da347f,// 58 PAY  20 

    0xeded06ab,// 59 PAY  21 

    0xdb043257,// 60 PAY  22 

    0x6b9f2490,// 61 PAY  23 

    0xbda9e4f9,// 62 PAY  24 

    0x333192f6,// 63 PAY  25 

    0xd7a59b53,// 64 PAY  26 

    0xffceb69a,// 65 PAY  27 

    0x87aa0bd0,// 66 PAY  28 

    0xfdb4c8db,// 67 PAY  29 

    0xdbee72e5,// 68 PAY  30 

    0x743de8e7,// 69 PAY  31 

    0xdee7e5fc,// 70 PAY  32 

    0xaafc315a,// 71 PAY  33 

    0xbb91153f,// 72 PAY  34 

    0x374a800f,// 73 PAY  35 

    0x979448c0,// 74 PAY  36 

    0x60e38f65,// 75 PAY  37 

    0x0a55a70a,// 76 PAY  38 

    0xb1316089,// 77 PAY  39 

    0xac0f7394,// 78 PAY  40 

    0xa1d94a8a,// 79 PAY  41 

    0x2a29aa5b,// 80 PAY  42 

    0x5b9adce0,// 81 PAY  43 

    0xdf7b2316,// 82 PAY  44 

    0x4e29b2c1,// 83 PAY  45 

    0x97440b87,// 84 PAY  46 

    0x38efe35d,// 85 PAY  47 

    0x92070a0d,// 86 PAY  48 

    0xc228f703,// 87 PAY  49 

    0x7dc16c6f,// 88 PAY  50 

    0x46223e77,// 89 PAY  51 

    0xcc75e613,// 90 PAY  52 

    0x77835261,// 91 PAY  53 

    0x806c5f95,// 92 PAY  54 

    0x22e43d85,// 93 PAY  55 

    0x70fc2e54,// 94 PAY  56 

    0xac05eb29,// 95 PAY  57 

    0x5848bd5d,// 96 PAY  58 

    0x1b5d5353,// 97 PAY  59 

    0x83bc6ef5,// 98 PAY  60 

    0xf9127a87,// 99 PAY  61 

    0xf484b714,// 100 PAY  62 

    0x895a8c40,// 101 PAY  63 

    0x14fcd826,// 102 PAY  64 

    0x10e0490d,// 103 PAY  65 

    0x835e92d4,// 104 PAY  66 

    0xe933d85f,// 105 PAY  67 

    0x493eb7d0,// 106 PAY  68 

    0x904639dd,// 107 PAY  69 

    0x1688936c,// 108 PAY  70 

    0x70ee9107,// 109 PAY  71 

    0x01072573,// 110 PAY  72 

    0xb7bcd260,// 111 PAY  73 

    0xe60f0a7e,// 112 PAY  74 

    0xdbaeb255,// 113 PAY  75 

    0xa4096421,// 114 PAY  76 

    0xac6029dd,// 115 PAY  77 

    0xf1ea51b2,// 116 PAY  78 

    0xc9188ffd,// 117 PAY  79 

    0x0c9f8727,// 118 PAY  80 

    0x00656b1a,// 119 PAY  81 

    0x43f0e599,// 120 PAY  82 

    0x6a607772,// 121 PAY  83 

    0x83fec90f,// 122 PAY  84 

    0xed462986,// 123 PAY  85 

    0x094ad044,// 124 PAY  86 

    0xf486f5f3,// 125 PAY  87 

    0xebfe45a7,// 126 PAY  88 

    0xdd46f8b0,// 127 PAY  89 

    0x65f92fb8,// 128 PAY  90 

    0x15294aba,// 129 PAY  91 

    0xa58bda9c,// 130 PAY  92 

    0x79e30939,// 131 PAY  93 

    0x8121e6df,// 132 PAY  94 

    0x0536d802,// 133 PAY  95 

    0xf566336d,// 134 PAY  96 

    0x66c3f1d7,// 135 PAY  97 

    0x6b3e033a,// 136 PAY  98 

    0x2630235c,// 137 PAY  99 

    0x0a8de052,// 138 PAY 100 

    0xb0f5839f,// 139 PAY 101 

    0x74ecd3f9,// 140 PAY 102 

    0xb9f1107e,// 141 PAY 103 

    0x72976232,// 142 PAY 104 

    0xabba1d88,// 143 PAY 105 

    0xc4fd2844,// 144 PAY 106 

    0x3f83bb36,// 145 PAY 107 

    0xc41cfef7,// 146 PAY 108 

    0x7dcbe89a,// 147 PAY 109 

    0x540a0950,// 148 PAY 110 

    0x2cd8ffde,// 149 PAY 111 

    0xc74db79e,// 150 PAY 112 

    0xb5fa3de9,// 151 PAY 113 

    0x19827b69,// 152 PAY 114 

    0x96c41506,// 153 PAY 115 

    0x820d6678,// 154 PAY 116 

    0x04a0a223,// 155 PAY 117 

    0xc3a93982,// 156 PAY 118 

    0x1253e6ed,// 157 PAY 119 

    0xf15de90b,// 158 PAY 120 

    0x3b432aa4,// 159 PAY 121 

    0x31f51ee4,// 160 PAY 122 

    0xe7ee56c5,// 161 PAY 123 

    0x8632944c,// 162 PAY 124 

    0x50098d22,// 163 PAY 125 

    0x4d9eeac6,// 164 PAY 126 

    0x0175df5d,// 165 PAY 127 

    0xed226395,// 166 PAY 128 

    0xe6cc5d9d,// 167 PAY 129 

    0xe262a35d,// 168 PAY 130 

    0x2a05f414,// 169 PAY 131 

    0x91e04cbe,// 170 PAY 132 

    0x744de4b8,// 171 PAY 133 

    0xdd0714c3,// 172 PAY 134 

    0xae680de0,// 173 PAY 135 

    0x8fc7b716,// 174 PAY 136 

    0x75b4eb9e,// 175 PAY 137 

    0x501dc5f1,// 176 PAY 138 

    0x564a30e5,// 177 PAY 139 

    0xfb5cfda3,// 178 PAY 140 

    0x5cdb57dd,// 179 PAY 141 

    0x90001c47,// 180 PAY 142 

    0x32483098,// 181 PAY 143 

    0x3da4adc3,// 182 PAY 144 

    0xec4b5bb1,// 183 PAY 145 

    0xd99d625f,// 184 PAY 146 

    0x9099b849,// 185 PAY 147 

    0x9483d326,// 186 PAY 148 

    0x8180b450,// 187 PAY 149 

    0x22c47346,// 188 PAY 150 

    0xe146635f,// 189 PAY 151 

    0x89d2da83,// 190 PAY 152 

    0x1f6dba17,// 191 PAY 153 

    0xe86c2b07,// 192 PAY 154 

    0x10c0fe65,// 193 PAY 155 

    0x8b34e1ca,// 194 PAY 156 

    0x0df221e4,// 195 PAY 157 

    0x33fb03d5,// 196 PAY 158 

    0x1b51fc89,// 197 PAY 159 

    0xec072aeb,// 198 PAY 160 

    0x90b039d5,// 199 PAY 161 

    0xb3954bfb,// 200 PAY 162 

    0x8dd28ec7,// 201 PAY 163 

    0x1ff7ced1,// 202 PAY 164 

    0x1ee7888a,// 203 PAY 165 

    0xd29f717a,// 204 PAY 166 

    0x063f512e,// 205 PAY 167 

    0xc0de4218,// 206 PAY 168 

    0x780dae5a,// 207 PAY 169 

    0x2450aadb,// 208 PAY 170 

    0xebf2c28c,// 209 PAY 171 

    0x499eeb91,// 210 PAY 172 

    0x68bf1f2f,// 211 PAY 173 

    0x97e8ef3e,// 212 PAY 174 

    0x7b31de36,// 213 PAY 175 

    0xa68e54aa,// 214 PAY 176 

    0x1e436caf,// 215 PAY 177 

    0xe8866f52,// 216 PAY 178 

    0x75a6638c,// 217 PAY 179 

    0x6d2eb596,// 218 PAY 180 

    0x6b12e1e1,// 219 PAY 181 

    0x334280fc,// 220 PAY 182 

    0x120edeff,// 221 PAY 183 

    0x21a7a5d1,// 222 PAY 184 

    0x134ee840,// 223 PAY 185 

    0x3e333d85,// 224 PAY 186 

    0x0ba6865f,// 225 PAY 187 

    0xccbd015f,// 226 PAY 188 

    0x97c77712,// 227 PAY 189 

    0x89e61caa,// 228 PAY 190 

    0xdf83f819,// 229 PAY 191 

    0x7f002916,// 230 PAY 192 

    0x8d0611ea,// 231 PAY 193 

    0x0392a0ed,// 232 PAY 194 

    0xd7eb8f69,// 233 PAY 195 

    0x22bd4783,// 234 PAY 196 

    0x53555b98,// 235 PAY 197 

    0x47fcd24d,// 236 PAY 198 

    0x9d3f0630,// 237 PAY 199 

    0x02dce6d8,// 238 PAY 200 

    0xdfdfdef0,// 239 PAY 201 

    0x4166b5a4,// 240 PAY 202 

    0x05a43c5b,// 241 PAY 203 

    0x7f64a1d3,// 242 PAY 204 

    0x2ea6205a,// 243 PAY 205 

    0x3dfc156f,// 244 PAY 206 

    0xf7fbba5e,// 245 PAY 207 

    0xd38d8990,// 246 PAY 208 

    0xd17981e4,// 247 PAY 209 

    0xa27b794d,// 248 PAY 210 

    0x4676f912,// 249 PAY 211 

    0x42cb9c40,// 250 PAY 212 

    0x4772b27e,// 251 PAY 213 

    0x8bfea91e,// 252 PAY 214 

    0xf55f1724,// 253 PAY 215 

    0x8b9bbe96,// 254 PAY 216 

    0x8562c330,// 255 PAY 217 

    0x8262ef5a,// 256 PAY 218 

    0x91d84f48,// 257 PAY 219 

    0xbe18e47d,// 258 PAY 220 

    0xe36f344e,// 259 PAY 221 

    0xe655866b,// 260 PAY 222 

    0xfb2fde75,// 261 PAY 223 

    0x62abcc65,// 262 PAY 224 

    0x0da6ced8,// 263 PAY 225 

    0x571998c7,// 264 PAY 226 

    0xa6267136,// 265 PAY 227 

    0x426a1ee4,// 266 PAY 228 

    0x258790aa,// 267 PAY 229 

    0x9b668ec1,// 268 PAY 230 

    0xef2407c4,// 269 PAY 231 

    0x424cd6bf,// 270 PAY 232 

    0x1db1feb3,// 271 PAY 233 

    0x820689a2,// 272 PAY 234 

    0x6dcee281,// 273 PAY 235 

    0x260c2207,// 274 PAY 236 

    0x75960025,// 275 PAY 237 

    0xa1777cc2,// 276 PAY 238 

    0x154392d5,// 277 PAY 239 

    0x29458cf7,// 278 PAY 240 

    0x83df5766,// 279 PAY 241 

    0x86a083b6,// 280 PAY 242 

    0xdfc697b8,// 281 PAY 243 

    0x903d06e6,// 282 PAY 244 

    0x689ae8c3,// 283 PAY 245 

    0xf59ba270,// 284 PAY 246 

    0xd1df899e,// 285 PAY 247 

    0x3b3ec44f,// 286 PAY 248 

    0xeb9f7ac9,// 287 PAY 249 

    0x119eb4ad,// 288 PAY 250 

    0xbe3c9ab6,// 289 PAY 251 

    0xa330ca22,// 290 PAY 252 

    0xacd6800e,// 291 PAY 253 

    0x92823421,// 292 PAY 254 

    0x576165bf,// 293 PAY 255 

    0xb7ba9853,// 294 PAY 256 

    0xe2d8f521,// 295 PAY 257 

    0x571e4c47,// 296 PAY 258 

    0x39e00c39,// 297 PAY 259 

    0x774f258b,// 298 PAY 260 

    0xca81a2c9,// 299 PAY 261 

    0x03f73255,// 300 PAY 262 

    0x5b8cdfba,// 301 PAY 263 

    0x8c09a786,// 302 PAY 264 

    0x0a5f91da,// 303 PAY 265 

    0x7ed251ab,// 304 PAY 266 

    0x73caa0af,// 305 PAY 267 

    0xb4030c5a,// 306 PAY 268 

    0x8c67282b,// 307 PAY 269 

    0xafcfcee9,// 308 PAY 270 

    0x06fa06c8,// 309 PAY 271 

    0x12d544df,// 310 PAY 272 

    0x4f1b11e7,// 311 PAY 273 

    0xc8049043,// 312 PAY 274 

    0xe790659b,// 313 PAY 275 

    0x1fc86d77,// 314 PAY 276 

    0xecb3d902,// 315 PAY 277 

    0xa65fe930,// 316 PAY 278 

    0x6df8be46,// 317 PAY 279 

    0x45fe91bd,// 318 PAY 280 

    0xe9cd6111,// 319 PAY 281 

    0x9d745a77,// 320 PAY 282 

    0x32bf0553,// 321 PAY 283 

    0x0eb7c3d9,// 322 PAY 284 

    0x13134e98,// 323 PAY 285 

    0x5cdfa052,// 324 PAY 286 

    0x039ef2b5,// 325 PAY 287 

    0x71a50376,// 326 PAY 288 

    0xa417a849,// 327 PAY 289 

    0xe3e586b0,// 328 PAY 290 

    0x97b3e520,// 329 PAY 291 

    0xa1541371,// 330 PAY 292 

    0xa92f0e5d,// 331 PAY 293 

    0xbfeb1183,// 332 PAY 294 

    0x54db508c,// 333 PAY 295 

    0xf97a3e6e,// 334 PAY 296 

    0x41b866d4,// 335 PAY 297 

    0xe170b017,// 336 PAY 298 

    0x8ea8cd41,// 337 PAY 299 

    0xb3a3a48e,// 338 PAY 300 

    0xc31b5bb4,// 339 PAY 301 

    0x60a486db,// 340 PAY 302 

    0xe3abeb8e,// 341 PAY 303 

    0x014cdf92,// 342 PAY 304 

    0x147cb431,// 343 PAY 305 

    0xdd6ac5d4,// 344 PAY 306 

    0x1620da8a,// 345 PAY 307 

    0x32026866,// 346 PAY 308 

    0x82606a2f,// 347 PAY 309 

    0x9a86a02e,// 348 PAY 310 

    0x0aee8706,// 349 PAY 311 

    0x12524680,// 350 PAY 312 

    0x7b24a466,// 351 PAY 313 

    0xfef024f4,// 352 PAY 314 

    0x774c5883,// 353 PAY 315 

    0xb5dcb50d,// 354 PAY 316 

    0x9bd9d9f7,// 355 PAY 317 

    0x109d3743,// 356 PAY 318 

    0xf4c4f146,// 357 PAY 319 

    0xe042fd4d,// 358 PAY 320 

    0x48181323,// 359 PAY 321 

    0x492d1c7c,// 360 PAY 322 

    0x387d2b02,// 361 PAY 323 

    0x75c6695f,// 362 PAY 324 

    0x78757465,// 363 PAY 325 

    0x9e5b134f,// 364 PAY 326 

    0xb5a5075a,// 365 PAY 327 

    0x6da792bb,// 366 PAY 328 

    0x8aeeea73,// 367 PAY 329 

    0xef8c8912,// 368 PAY 330 

    0xd399f54b,// 369 PAY 331 

    0x9788b692,// 370 PAY 332 

    0x2179641c,// 371 PAY 333 

    0x30b3cdd4,// 372 PAY 334 

    0x29ed8b29,// 373 PAY 335 

    0xe64db0ad,// 374 PAY 336 

    0x21b87157,// 375 PAY 337 

    0x11f47e82,// 376 PAY 338 

    0xda0b5fab,// 377 PAY 339 

    0x40f67a1d,// 378 PAY 340 

    0xc9a2f241,// 379 PAY 341 

    0x0dd11071,// 380 PAY 342 

    0x06aed9b4,// 381 PAY 343 

    0x726d2d03,// 382 PAY 344 

    0xc47673c9,// 383 PAY 345 

    0xcc59a4a7,// 384 PAY 346 

    0x73192f54,// 385 PAY 347 

    0x000da121,// 386 PAY 348 

    0xc33560be,// 387 PAY 349 

    0xaae61224,// 388 PAY 350 

    0x1f2b64bc,// 389 PAY 351 

    0xd5b53040,// 390 PAY 352 

    0xd024af82,// 391 PAY 353 

    0xef952c87,// 392 PAY 354 

    0x6816a51b,// 393 PAY 355 

    0x5035b8b6,// 394 PAY 356 

    0x33f10082,// 395 PAY 357 

    0x5750db5c,// 396 PAY 358 

    0x67c9e0c6,// 397 PAY 359 

    0xb58baee6,// 398 PAY 360 

    0x1e10d6e4,// 399 PAY 361 

    0x25250408,// 400 PAY 362 

    0xc9b4519f,// 401 PAY 363 

    0x9b0444cb,// 402 PAY 364 

    0xd0ca6e8b,// 403 PAY 365 

    0xae36a819,// 404 PAY 366 

    0xd6103b82,// 405 PAY 367 

    0x5d52e677,// 406 PAY 368 

    0xc0a452a7,// 407 PAY 369 

    0xc0d19747,// 408 PAY 370 

    0xfa57e876,// 409 PAY 371 

    0xa277d43b,// 410 PAY 372 

    0x3bff6f37,// 411 PAY 373 

    0x2a5f964e,// 412 PAY 374 

    0x2507a826,// 413 PAY 375 

    0xb7d0e500,// 414 PAY 376 

    0x7bf4b088,// 415 PAY 377 

    0x0609841f,// 416 PAY 378 

    0xe234c2b5,// 417 PAY 379 

    0x4c821848,// 418 PAY 380 

    0x17a3f34d,// 419 PAY 381 

    0x7cf9d7d1,// 420 PAY 382 

    0x9b505a4e,// 421 PAY 383 

    0x083226c7,// 422 PAY 384 

    0xffbaee42,// 423 PAY 385 

    0x7d9d42a7,// 424 PAY 386 

    0x85aa3acb,// 425 PAY 387 

    0xf919bd6c,// 426 PAY 388 

    0x363f1783,// 427 PAY 389 

    0x9964b028,// 428 PAY 390 

    0x04369646,// 429 PAY 391 

    0xfa283c81,// 430 PAY 392 

    0xea01ac82,// 431 PAY 393 

    0xc9cf23ba,// 432 PAY 394 

    0x0180a019,// 433 PAY 395 









