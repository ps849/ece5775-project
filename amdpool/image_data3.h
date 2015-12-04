in_flag =1;
in_width = 60;
in_height = 60;
in_maxgrey = 255;
unsigned char Data[60][60]={
{0x84,0x92,0xa2,0xa6,0xa0,0x9c,0xa0,0xa7,0xb7,0xba,0xbf,0xc3,0xc3,0xc1,0xc3,0xc7,0xc6,0xc1,0xc8,0xcf,0xcd,0xd0,0xd0,0xc6,0xc3,0xbf,0xc5,0xb7,0xbd,0xd1,0xc8,0xc6,0xca,0xca,0xc6,0xc8,0xcd,0xc4,0xbf,0xc9,0xc5,0xcf,0xcd,0xca,0xcc,0xc6,0xc4,0xce,0xcb,0xc9,0xc4,0xba,0xb1,0xae,0xb0,0xb4,0xbc,0xbb,0xb9,0xb7},

{0xa2,0xa9,0xae,0xaa,0xa2,0x9f,0xa4,0xab,0xb8,0xbb,0xbf,0xc1,0xc0,0xbf,0xc0,0xc4,0xc9,0xc9,0xd1,0xd2,0xc7,0xc9,0xd4,0xd5,0xdd,0xc9,0xbd,0xa4,0xa2,0xb6,0xbc,0xcc,0xc5,0xc6,0xc3,0xc0,0xc8,0xd4,0xcf,0xbf,0xc2,0xcf,0xce,0xc9,0xcf,0xd0,0xcd,0xd1,0xcd,0xca,0xc4,0xbc,0xb6,0xb4,0xb6,0xb8,0xb6,0xb6,0xb6,0xb5},

{0xb7,0xb6,0xb0,0xa8,0xa2,0xa4,0xac,0xb3,0xba,0xbd,0xbf,0xbe,0xbe,0xbe,0xc0,0xc1,0xc4,0xbf,0xc3,0xc6,0xc0,0xc7,0xd2,0xd1,0xc7,0xac,0xa0,0x8e,0x8b,0x9a,0xaa,0xcc,0xd3,0xc3,0xbb,0xae,0xa0,0xaf,0xc0,0xb5,0xb0,0xc6,0xca,0xc4,0xcd,0xd5,0xd1,0xcf,0xc8,0xc3,0xbd,0xb9,0xb7,0xb7,0xb7,0xb7,0xaf,0xae,0xad,0xac},

{0xb6,0xb0,0xa8,0xa1,0xa0,0xa7,0xb1,0xb8,0xbb,0xbe,0xbf,0xbd,0xbe,0xc1,0xc3,0xc2,0xcd,0xc0,0xc0,0xca,0xd0,0xd7,0xd4,0xc3,0xa7,0x86,0x7c,0x6f,0x68,0x70,0x87,0xb6,0xc0,0xb2,0xc2,0xc3,0x9f,0x9a,0xb1,0xb1,0x90,0xb5,0xc5,0xc1,0xc8,0xd1,0xcd,0xc8,0xc0,0xba,0xb4,0xb1,0xb3,0xb4,0xb4,0xb2,0xad,0xa8,0xa2,0x9d},

{0xb5,0xaf,0xa6,0xa1,0xa1,0xa7,0xaf,0xb5,0xbb,0xbf,0xc0,0xbe,0xc1,0xc6,0xc7,0xc3,0xbd,0xb8,0xbe,0xc2,0xb8,0xaf,0xa3,0x91,0x93,0x70,0x66,0x59,0x4a,0x45,0x56,0x87,0xd9,0xc3,0xba,0x9f,0x79,0x87,0xa6,0xa0,0x75,0xa5,0xc4,0xc5,0xc9,0xcd,0xc8,0xc5,0xbe,0xb9,0xb3,0xb1,0xb2,0xb3,0xb2,0xb0,0xaf,0xa6,0x9a,0x91},

{0xb7,0xb3,0xac,0xa6,0xa4,0xa6,0xaa,0xae,0xbb,0xc1,0xc3,0xc0,0xc3,0xca,0xc7,0xbf,0x9c,0xa5,0xb1,0xa2,0x77,0x5c,0x56,0x53,0x50,0x43,0x57,0x61,0x54,0x3e,0x35,0x53,0xa3,0x95,0x78,0x4e,0x44,0x70,0x83,0x62,0x68,0x99,0xbe,0xc8,0xcc,0xca,0xc3,0xc3,0xc1,0xbd,0xb9,0xb5,0xb4,0xb3,0xb1,0xb0,0xad,0xa2,0x94,0x8b},

{0xac,0xab,0xa9,0xa4,0xa1,0xa3,0xa9,0xae,0xbc,0xc4,0xc5,0xc1,0xc3,0xc9,0xc3,0xb6,0x9c,0x9c,0x9c,0x81,0x51,0x37,0x39,0x3c,0x18,0x19,0x3e,0x54,0x4f,0x39,0x26,0x38,0x25,0x32,0x3f,0x47,0x57,0x65,0x58,0x3c,0x62,0x88,0xaa,0xbd,0xc9,0xc4,0xb9,0xba,0xbe,0xbc,0xb9,0xb4,0xae,0xaa,0xa9,0xa9,0x9f,0x97,0x8d,0x89},

{0x99,0x9b,0x9c,0x9c,0x9c,0xa1,0xab,0xb3,0xbd,0xc6,0xc7,0xc1,0xc2,0xc7,0xbe,0xaf,0x9d,0x88,0x74,0x59,0x3b,0x31,0x33,0x2e,0x25,0x18,0x26,0x29,0x22,0x1b,0x1a,0x37,0x4c,0x42,0x44,0x55,0x53,0x38,0x39,0x5c,0x5d,0x79,0x96,0xaf,0xc1,0xbb,0xae,0xae,0xb7,0xb7,0xb4,0xad,0xa4,0x9e,0x9e,0x9f,0x90,0x8a,0x85,0x86},

{0x88,0x85,0x87,0x8e,0x92,0x97,0xa5,0xb5,0xba,0xc7,0xca,0xbb,0xb0,0xd8,0xab,0x96,0x82,0x5f,0x1e,0x3a,0x36,0x40,0x3a,0x20,0x18,0x2e,0x2b,0x13,0x19,0x40,0x54,0x4b,0x4e,0x4d,0x5b,0x66,0x51,0x32,0x38,0x58,0x7e,0x73,0x80,0x9d,0xad,0xb4,0xb0,0xa3,0xac,0xb4,0xa8,0xa6,0x9e,0x92,0x9a,0x93,0x92,0x86,0x84,0x90},

{0x75,0x71,0x74,0x80,0x8f,0x9d,0xb0,0xbf,0xd0,0xc4,0xc0,0xbf,0xac,0xae,0x79,0x6e,0x91,0x69,0x39,0x39,0x2a,0x27,0x29,0x22,0x20,0x23,0x1d,0x19,0x2c,0x4a,0x50,0x44,0x53,0x51,0x4c,0x42,0x33,0x2c,0x38,0x49,0x62,0x70,0x88,0x94,0x95,0xa2,0xac,0xa5,0xb5,0xb9,0xa7,0xa5,0xa1,0x9b,0xa5,0x9d,0x96,0x8c,0x8b,0x97},

{0x69,0x62,0x62,0x71,0x88,0x9e,0xb1,0xbe,0xbf,0xb6,0xba,0xc4,0xba,0xb3,0x88,0x7e,0x6f,0x3d,0x2f,0x25,0x2b,0x2c,0x35,0x3d,0x37,0x39,0x36,0x2d,0x25,0x24,0x25,0x25,0x36,0x3e,0x3a,0x29,0x22,0x25,0x22,0x17,0x41,0x5b,0x77,0x7c,0x7f,0x9b,0xb3,0xb0,0xb4,0xb9,0xa8,0xa7,0xa7,0xa6,0xb0,0xa6,0x98,0x91,0x92,0x9e},

{0x6d,0x64,0x60,0x6b,0x80,0x96,0xa5,0xab,0xac,0xb8,0xbc,0xae,0x99,0x8b,0x68,0x4f,0x5f,0x24,0x2f,0x22,0x3b,0x38,0x34,0x37,0x33,0x3a,0x38,0x2b,0x20,0x20,0x23,0x23,0x29,0x33,0x34,0x2d,0x2c,0x31,0x29,0x19,0x36,0x40,0x50,0x55,0x5f,0x81,0x9f,0xa1,0x9c,0xad,0xab,0xb0,0xaf,0xab,0xb2,0xa5,0x95,0x92,0x95,0xa0},

{0x70,0x6b,0x67,0x6d,0x7e,0x90,0x99,0x9b,0xa4,0xb4,0xb7,0xa1,0x7d,0x51,0x3b,0x29,0x45,0x21,0x3f,0x32,0x41,0x37,0x30,0x31,0x49,0x46,0x36,0x2a,0x39,0x50,0x49,0x2f,0x35,0x2f,0x2b,0x2d,0x34,0x3e,0x4a,0x53,0x33,0x30,0x38,0x3c,0x3a,0x4f,0x75,0x8d,0x7b,0x9f,0xaf,0xb9,0xb4,0xaa,0xac,0x9c,0x91,0x92,0x99,0xa2},

{0x68,0x6d,0x71,0x77,0x81,0x8d,0x94,0x94,0x9a,0x9d,0xaa,0xae,0x8b,0x3f,0x3a,0x44,0x21,0x23,0x40,0x34,0x28,0x23,0x2f,0x38,0x3a,0x42,0x3b,0x2f,0x3c,0x55,0x53,0x3c,0x28,0x1a,0x17,0x22,0x2a,0x2d,0x3b,0x4e,0x22,0x26,0x38,0x3e,0x33,0x41,0x71,0x99,0x6c,0x99,0xb1,0xbc,0xb3,0xa6,0xa6,0x95,0x90,0x95,0x9d,0xa5},

{0x63,0x72,0x80,0x82,0x83,0x87,0x8a,0x8a,0x92,0x95,0xa4,0xab,0x8a,0x2e,0x2d,0x34,0x2b,0x3a,0x32,0x2d,0x16,0x29,0x46,0x4a,0x2d,0x44,0x56,0x59,0x5c,0x67,0x71,0x73,0x4b,0x37,0x27,0x25,0x22,0x1c,0x1d,0x26,0x18,0x20,0x32,0x3a,0x39,0x4e,0x6e,0x7e,0x77,0xa0,0xb0,0xb6,0xad,0xa4,0xa7,0x95,0x8e,0x96,0x9f,0xa6},

{0x65,0x7b,0x8c,0x8b,0x83,0x80,0x7f,0x7d,0x80,0x96,0xa7,0xa2,0x86,0x36,0x35,0x26,0x2e,0x39,0x12,0x26,0x2a,0x67,0x94,0x8f,0x9c,0xa1,0xae,0xbd,0xc0,0xb6,0xad,0xaa,0xac,0x88,0x58,0x35,0x25,0x23,0x27,0x2b,0x23,0x21,0x22,0x25,0x32,0x4b,0x4a,0x2f,0x8a,0xaa,0xaf,0xae,0xa7,0xa3,0xaa,0x99,0x8b,0x94,0x9e,0xa4},

{0x66,0x7b,0x88,0x85,0x81,0x84,0x83,0x7d,0x86,0xa1,0xb0,0xae,0x62,0x40,0x2a,0x2f,0x30,0x34,0x13,0x18,0x62,0x8b,0x90,0xa8,0xb4,0xbf,0xc9,0xcc,0xcd,0xcd,0xc8,0xc2,0xbb,0xb9,0xab,0x8c,0x63,0x40,0x2e,0x28,0x2c,0x18,0x32,0x21,0x48,0x35,0x2d,0x7e,0xa0,0x9e,0x9a,0x98,0x9f,0xa7,0xa7,0xa1,0x9e,0x95,0x91,0x96},

{0x5c,0x70,0x80,0x82,0x83,0x8b,0x8e,0x8b,0x9d,0x91,0x9e,0x82,0x65,0x34,0x37,0x33,0x30,0x2b,0x1f,0x3c,0x78,0x8e,0x96,0xb2,0xc3,0xcd,0xd5,0xd6,0xd4,0xd1,0xcb,0xc5,0xbe,0xbc,0xbc,0xba,0xac,0x89,0x5a,0x37,0x1a,0x1a,0x35,0x1e,0x32,0x32,0x3f,0x71,0x95,0x93,0x8d,0x8c,0x94,0xa0,0xa4,0xa1,0xa7,0x9d,0x97,0x99},

{0x56,0x6a,0x7d,0x85,0x8c,0x97,0x9d,0x9c,0xa9,0x98,0x9b,0x77,0x58,0x2b,0x36,0x36,0x2d,0x21,0x34,0x69,0x8f,0x92,0x9e,0xba,0xcc,0xd4,0xda,0xda,0xd6,0xd2,0xcb,0xc4,0xc8,0xbf,0xb9,0xba,0xba,0xa9,0x89,0x6e,0x2d,0x22,0x2d,0x23,0x23,0x2d,0x5d,0x82,0xa6,0xa1,0x99,0x93,0x98,0xa3,0xa9,0xa8,0xaf,0xa6,0x9e,0x9c},

{0x62,0x74,0x87,0x92,0x9a,0xa3,0xa7,0xa6,0xa0,0xb3,0xaa,0x8c,0x3c,0x2d,0x29,0x33,0x26,0x20,0x4b,0x85,0x95,0x95,0xa6,0xb7,0xc5,0xce,0xd4,0xd3,0xcf,0xcc,0xc6,0xbf,0xc6,0xc0,0xb4,0xa6,0x9b,0x97,0x9c,0xa1,0x6b,0x38,0x24,0x30,0x26,0x29,0x6d,0x99,0xbf,0xba,0xb0,0xa5,0xa3,0xa7,0xa8,0xa5,0xb0,0xaa,0xa2,0x9c},

{0x7b,0x88,0x96,0x9f,0xa3,0xa6,0xa6,0xa5,0x9c,0xbb,0xad,0x7c,0x2c,0x2f,0x2e,0x2c,0x20,0x29,0x5d,0x89,0x8c,0x95,0xab,0xae,0xb8,0xc1,0xc8,0xc8,0xc7,0xc6,0xc2,0xbd,0xbd,0xbd,0xb8,0xaa,0x99,0x93,0x98,0xa0,0x99,0x5d,0x30,0x38,0x2c,0x2b,0x57,0x7b,0xc1,0xbf,0xb7,0xad,0xa7,0xa6,0xa3,0x9d,0xac,0xa9,0xa4,0x9c},

{0x92,0x96,0x9b,0x9e,0x9e,0x9e,0x9e,0x9f,0xa7,0xac,0xa2,0x53,0x31,0x2b,0x3f,0x27,0x21,0x36,0x65,0x83,0x84,0x97,0xad,0xa9,0xb3,0xbc,0xc3,0xc4,0xc4,0xc5,0xc2,0xbe,0xc5,0xb9,0xa9,0x9e,0x99,0x96,0x91,0x8c,0x97,0x7f,0x4d,0x36,0x2c,0x30,0x2b,0x48,0xbe,0xc0,0xbd,0xb5,0xb0,0xad,0xa9,0xa3,0xa8,0xaa,0xa8,0xa1},

{0x9b,0x97,0x92,0x8e,0x8d,0x8f,0x95,0x9a,0xb1,0xac,0xa3,0x5f,0x3b,0x26,0x37,0x27,0x29,0x40,0x66,0x80,0x88,0x99,0xac,0xaf,0xb7,0xc0,0xc6,0xc6,0xc4,0xc5,0xc2,0xbd,0xcd,0xba,0xa2,0x95,0x93,0x94,0x91,0x8d,0x85,0x89,0x5c,0x34,0x32,0x32,0xf,0x55,0xc4,0xc6,0xc3,0xbb,0xb4,0xb0,0xaa,0xa4,0xaa,0xb0,0xb0,0xa9},

{0x9b,0x91,0x85,0x7e,0x7d,0x83,0x8e,0x99,0xb1,0xbd,0xb0,0x92,0x3d,0x25,0x1d,0x2a,0x31,0x45,0x65,0x81,0x90,0x9c,0xab,0xb8,0xbd,0xc5,0xca,0xc8,0xc5,0xc4,0xc0,0xbb,0xc4,0xc0,0xb7,0xab,0xa0,0x98,0x96,0x96,0x80,0x83,0x59,0x36,0x3b,0x31,0xb,0x8d,0xc8,0xc9,0xc2,0xb5,0xaa,0xa3,0x9c,0x96,0xad,0xb5,0xb7,0xb1},

{0x93,0x8c,0x7b,0x6b,0x6e,0x83,0x96,0x9e,0xb4,0x9d,0xaf,0x5f,0x38,0x29,0x33,0x2a,0x13,0x51,0x70,0x82,0x90,0x9d,0xb5,0xba,0xc6,0xbb,0xcf,0xdc,0xc9,0xba,0xc6,0xcb,0xc7,0xbb,0xae,0xad,0xb1,0xaf,0xa3,0x96,0x7e,0x69,0x5a,0x3e,0x35,0x3d,0xe,0x69,0xd5,0xda,0xd7,0xc6,0xb4,0xa6,0x97,0x8a,0x8f,0xa5,0xb6,0xb3},

{0x93,0x92,0x8a,0x7f,0x80,0x8f,0x9f,0xa7,0x9c,0xa1,0x98,0x6a,0x1a,0x32,0x21,0x1e,0x21,0x57,0x6d,0x7e,0x92,0xa2,0xb8,0xb8,0xbc,0xc0,0xb0,0xab,0xc1,0xcd,0xc3,0xbe,0xbd,0xab,0x9b,0x9f,0xad,0xb0,0x9e,0x8b,0x75,0x6c,0x7b,0x36,0x38,0x25,0x2f,0xa4,0xe0,0xe8,0xe9,0xdc,0xc9,0xb6,0xa1,0x91,0x87,0x96,0xa3,0xa6},

{0x91,0x98,0x9b,0x95,0x91,0x98,0xa4,0xac,0xa1,0xa4,0x8f,0x7d,0x20,0x37,0x1f,0x28,0x23,0x59,0x71,0x86,0x9a,0xa5,0xb0,0xa7,0x9e,0xb6,0xa2,0x93,0xb0,0xb3,0xa2,0xab,0x9f,0x9f,0x9e,0x9c,0x9a,0x98,0x97,0x97,0x87,0x7a,0x76,0x31,0x3e,0x2f,0x3c,0xac,0xe4,0xef,0xf3,0xeb,0xd7,0xbe,0xa6,0x95,0x85,0x88,0x90,0x98},

{0x91,0x9c,0xa5,0xa1,0x97,0x95,0x9d,0xa7,0xb1,0x9a,0x8b,0x7e,0x3a,0x2b,0x26,0x34,0x25,0x61,0x7d,0x87,0x84,0x75,0x6e,0x5f,0x53,0x5c,0x62,0x72,0x85,0x82,0x7b,0x87,0x6e,0x74,0x78,0x71,0x68,0x66,0x70,0x7c,0x90,0x8e,0x6a,0x3f,0x30,0x3b,0x2f,0x95,0xe8,0xf1,0xf4,0xee,0xda,0xc1,0xad,0xa1,0x90,0x87,0x88,0x92},

{0x93,0x9f,0xa7,0xa1,0x91,0x87,0x8c,0x98,0xa0,0x93,0x7c,0x6f,0x2f,0x25,0x26,0x27,0x23,0x66,0x82,0x81,0x6e,0x59,0x5b,0x56,0x4b,0x2f,0x39,0x50,0x5b,0x7a,0x83,0x5c,0x5d,0x4e,0x40,0x3f,0x49,0x53,0x55,0x51,0x72,0x90,0x83,0x4d,0x19,0x29,0x45,0xb2,0xe9,0xed,0xef,0xe6,0xd3,0xbf,0xb3,0xb0,0xa1,0x93,0x8b,0x90},

{0x94,0x9d,0xa3,0x9c,0x87,0x76,0x77,0x82,0x81,0x9c,0x7c,0x77,0x20,0x34,0x2b,0x1c,0x35,0x70,0x7f,0x71,0x5a,0x4e,0x60,0x68,0x50,0x3e,0x45,0x3c,0x40,0x99,0xc2,0x7c,0x4e,0x43,0x37,0x34,0x3b,0x45,0x4c,0x4e,0x5b,0x7b,0x94,0x45,0x21,0x31,0x88,0xd8,0xdc,0xdd,0xdd,0xd4,0xc2,0xb1,0xab,0xaf,0xb0,0xa2,0x93,0x8e},

{0x8d,0x94,0x9a,0x93,0x7b,0x65,0x62,0x6a,0x75,0x96,0x90,0x92,0x40,0x2f,0x30,0x25,0x4e,0x7b,0x7c,0x68,0x54,0x48,0x54,0x54,0x38,0x3e,0x3d,0x27,0x47,0xba,0xe2,0xb2,0x35,0x39,0x3a,0x34,0x2e,0x33,0x43,0x52,0x5a,0x6c,0x8b,0x4e,0x37,0x60,0xb1,0xc5,0xd6,0xd8,0xda,0xd5,0xc2,0xaf,0xa9,0xae,0xba,0xb0,0x9e,0x8e},

{0x84,0x8a,0x90,0x8b,0x73,0x5a,0x53,0x59,0x75,0x7a,0x9f,0xa2,0x6f,0xf,0x2b,0x30,0x44,0x71,0x7b,0x7e,0x83,0x84,0x8b,0x83,0x73,0x69,0x42,0x2f,0x70,0xce,0xd1,0x9b,0x43,0x3e,0x3b,0x3c,0x43,0x4c,0x52,0x55,0x55,0x72,0x86,0x71,0x3b,0x81,0xab,0x9e,0xe4,0xe7,0xed,0xea,0xd8,0xc0,0xb8,0xbb,0xc1,0xba,0xa6,0x8f},

{0x74,0x7f,0x7e,0x77,0x73,0x65,0x59,0x5d,0x79,0x8b,0x9d,0xb3,0x8f,0x20,0x31,0x3b,0x4e,0x6e,0x82,0x81,0x85,0x91,0x8e,0x7c,0x6a,0x6f,0x84,0xa6,0xb4,0xc2,0xcb,0xad,0x75,0x69,0x43,0x31,0x47,0x57,0x5a,0x67,0x68,0x76,0x8f,0x6e,0x4d,0x41,0x8c,0xa1,0xdb,0xee,0xf2,0xf9,0xef,0xd4,0xca,0xb8,0xc0,0xb9,0xaf,0xa6},

{0x70,0x7e,0x83,0x83,0x82,0x71,0x5f,0x5d,0x76,0x90,0x9e,0xad,0x9c,0x4c,0x4c,0x34,0x5b,0x71,0x80,0x82,0x8b,0x9b,0xa1,0x9a,0x9f,0xb5,0xc5,0xc9,0xc9,0xd2,0xcd,0xa7,0x81,0x9d,0xa9,0x97,0x77,0x5a,0x55,0x62,0x71,0x79,0x91,0x6a,0x3d,0x50,0x92,0xa7,0xe8,0xf5,0xf2,0xf6,0xeb,0xd5,0xd1,0xc4,0xc1,0xbd,0xb6,0xb0},

{0x6d,0x80,0x8c,0x91,0x90,0x7a,0x60,0x59,0x6c,0x8e,0x98,0xa3,0xa7,0x80,0x71,0x3a,0x6b,0x73,0x7b,0x83,0x91,0xa5,0xb5,0xbc,0xd1,0xda,0xd5,0xbe,0xbb,0xce,0xc9,0xb1,0x81,0x99,0xbf,0xd0,0xbe,0xa7,0x96,0x88,0x71,0x6f,0x8a,0x64,0x33,0x7a,0xb0,0xc4,0xd1,0xe4,0xea,0xf5,0xec,0xd1,0xc5,0xb1,0xbf,0xbd,0xbc,0xba},

{0x6f,0x87,0x96,0x97,0x8d,0x70,0x56,0x50,0x5d,0x7e,0x87,0x95,0xa4,0x9c,0x8c,0x58,0x78,0x75,0x79,0x85,0x96,0xa8,0xbc,0xca,0xd4,0xc5,0xb8,0xae,0xbd,0xd0,0xc7,0xc3,0xa4,0x92,0xa2,0xc1,0xce,0xd1,0xc0,0x9b,0x83,0x76,0x8b,0x67,0x3a,0xa0,0xc1,0xcd,0xb4,0xc5,0xc8,0xd4,0xcd,0xb7,0xb1,0xa1,0xb6,0xb7,0xb9,0xbb},

{0x73,0x8c,0x98,0x8f,0x7a,0x5a,0x45,0x47,0x4e,0x65,0x71,0x88,0x93,0x98,0x92,0x7e,0x81,0x7a,0x7a,0x88,0x98,0xa4,0xb1,0xbc,0xb0,0x88,0x97,0xb7,0xd0,0xd0,0xb5,0xb9,0xa4,0x89,0x8c,0xa2,0xad,0xba,0xbd,0xaa,0xa4,0x8e,0x98,0x75,0x52,0xac,0xb2,0xaf,0xb0,0xb3,0xa1,0x9d,0x96,0x94,0xaa,0xaf,0xab,0xad,0xb0,0xb3},

{0x74,0x88,0x8c,0x7d,0x66,0x49,0x3b,0x43,0x48,0x55,0x62,0x7f,0x82,0x8a,0x89,0x92,0x82,0x7c,0x7c,0x86,0x91,0x97,0x98,0x99,0x7d,0x52,0x79,0x94,0x91,0x91,0x80,0x88,0x75,0x66,0x6c,0x84,0x97,0xa3,0xab,0xa9,0x9b,0x8f,0x98,0x86,0x7d,0xaf,0xab,0xa3,0xa6,0xac,0x9c,0x96,0x8d,0x8c,0xa9,0xb4,0xa8,0xa9,0xaa,0xab},

{0x71,0x7d,0x79,0x6a,0x5b,0x48,0x3e,0x46,0x4c,0x52,0x5d,0x7c,0x79,0x85,0x7b,0x8a,0x7b,0x78,0x77,0x7a,0x80,0x82,0x7a,0x6f,0x52,0x49,0x88,0x6e,0x32,0x46,0x51,0x53,0x58,0x54,0x58,0x6f,0x88,0x85,0x7a,0x7b,0x7b,0x84,0x96,0x99,0xae,0xb0,0xae,0xaa,0x9c,0xae,0xac,0xac,0x9f,0x95,0xaa,0xb1,0xae,0xac,0xaa,0xa8},

{0x6c,0x72,0x69,0x5e,0x59,0x4d,0x45,0x4a,0x52,0x57,0x5f,0x7b,0x77,0x88,0x72,0x7a,0x72,0x72,0x6f,0x6d,0x71,0x72,0x64,0x52,0x39,0x62,0xc1,0x81,0x18,0x34,0x48,0x35,0x32,0x44,0x50,0x64,0x77,0x69,0x5c,0x6e,0x73,0x8a,0xa1,0xab,0xcd,0xa6,0xa6,0xa6,0xa7,0xb8,0xb3,0xae,0x9d,0x95,0xb0,0xbd,0xb5,0xb2,0xad,0xa8},

{0x6c,0x62,0x5c,0x60,0x63,0x5c,0x50,0x48,0x64,0x65,0x69,0x72,0x7d,0x80,0x79,0x70,0x53,0x55,0x80,0x6c,0x68,0x58,0x53,0x47,0x44,0x93,0xb4,0xb3,0xa7,0x61,0x2f,0x4d,0x42,0x4a,0x31,0x73,0x64,0x64,0x5b,0x64,0x6b,0x7f,0x9a,0x9a,0xac,0xbd,0xae,0xa2,0xac,0xc0,0xbd,0xb5,0x9f,0x93,0xb1,0xc2,0xb6,0xb7,0xba,0xbe},

{0x63,0x5d,0x5d,0x63,0x65,0x5e,0x55,0x50,0x68,0x7c,0x8c,0x86,0x75,0x6b,0x6f,0x77,0x73,0x6c,0x7d,0x5e,0x69,0x70,0x5b,0x2c,0x6d,0x89,0x7c,0x9a,0xa7,0x8e,0x42,0x39,0x50,0x57,0x53,0x60,0x5e,0x47,0x57,0x58,0x6c,0x90,0x48,0x1c,0x99,0xa6,0xaa,0xb3,0xb0,0xc4,0xc2,0xbb,0xa5,0x96,0xaf,0xbb,0xb9,0xc2,0xcd,0xd5},

{0x64,0x68,0x71,0x77,0x72,0x69,0x65,0x67,0x7e,0x99,0xac,0x9e,0x7f,0x6c,0x6f,0x78,0x79,0x6f,0x7b,0x61,0x64,0x6e,0x62,0x47,0x69,0x57,0x1d,0x2d,0x30,0x55,0x3f,0x4c,0x3d,0x49,0x43,0x45,0x4e,0x53,0x63,0x58,0x59,0x91,0x38,0x45,0xca,0xbc,0xa4,0xa8,0xbd,0xd2,0xd1,0xc9,0xae,0x9b,0xae,0xb8,0xaf,0xbe,0xd1,0xdd},

{0x80,0x8e,0x9d,0x9a,0x85,0x72,0x73,0x7d,0x9d,0xb0,0xbc,0xb3,0xa2,0x93,0x86,0x7c,0x78,0x5e,0x6b,0x6a,0x65,0x66,0x6b,0x7b,0x84,0x76,0x5c,0x5a,0x42,0x48,0x3c,0x3b,0x33,0x41,0x24,0x41,0x48,0x84,0x71,0x5c,0x6b,0x74,0x46,0x9f,0xab,0xae,0xa0,0xb7,0xce,0xe5,0xe2,0xd5,0xb2,0x9a,0xad,0xb9,0xb7,0xc4,0xd5,0xe1},

{0xaf,0xc1,0xcd,0xbb,0x90,0x70,0x70,0x80,0xb2,0xc4,0xd1,0xcf,0xc8,0xbe,0xaa,0x95,0x91,0x73,0x72,0x73,0x68,0x70,0x71,0x82,0x98,0x8d,0xa3,0xa8,0xb4,0xa3,0x98,0x73,0x48,0x52,0x39,0x4d,0x50,0x8e,0x6e,0x57,0x7b,0x61,0x6f,0xc0,0x94,0xa8,0xab,0xc9,0xd7,0xed,0xe8,0xd5,0xae,0x95,0xac,0xbc,0xbd,0xc1,0xc8,0xce},

{0xd6,0xe4,0xe9,0xcf,0x9e,0x7a,0x79,0x89,0xc0,0xdb,0xef,0xeb,0xdf,0xd6,0xc7,0xb6,0xa8,0xb4,0xb8,0x93,0x5f,0x6c,0x6b,0x74,0x8b,0x7b,0x92,0x82,0xa1,0x93,0xa2,0x88,0x4c,0x4e,0x58,0x47,0x54,0x6a,0x66,0x5e,0x77,0x77,0xab,0xbd,0xcb,0xc9,0xc4,0xc7,0xd7,0xe9,0xe0,0xd0,0xb1,0x9e,0xb7,0xc5,0xc4,0xc1,0xbf,0xbf},

{0xe5,0xec,0xee,0xdd,0xbe,0xa8,0xab,0xba,0xdb,0xf2,0xfa,0xf5,0xed,0xe6,0xd7,0xc3,0xb5,0xdf,0xf0,0xc0,0x68,0x67,0x65,0x75,0x90,0x98,0xa9,0x8c,0x85,0x61,0x5c,0x4c,0x5b,0x4e,0x58,0x48,0x4f,0x61,0x62,0x71,0x98,0xa4,0xb8,0xb1,0xd7,0xc8,0xdd,0xd3,0xda,0xe4,0xd9,0xd4,0xc6,0xbe,0xd4,0xdb,0xe1,0xdf,0xdb,0xd7},

{0xe4,0xe7,0xea,0xe8,0xe0,0xdc,0xe5,0xf3,0xf8,0xfb,0xf9,0xf4,0xf5,0xf4,0xdd,0xbc,0xc6,0xde,0xef,0xd7,0x88,0x79,0x66,0x77,0x78,0x92,0xa1,0xa3,0xa8,0xa5,0x9d,0x9c,0x8a,0x6e,0x53,0x60,0x4f,0x7b,0x60,0x7c,0xb6,0xc1,0xc2,0xe9,0xe0,0xc5,0xe8,0xd4,0xe0,0xe5,0xd8,0xdd,0xde,0xde,0xf1,0xf0,0xec,0xee,0xed,0xe6},

{0xe0,0xe3,0xe7,0xe9,0xe9,0xeb,0xef,0xf3,0xfc,0xf7,0xf9,0xf9,0xef,0xef,0xda,0xab,0xbe,0xdb,0xf9,0xde,0x84,0x7e,0x75,0x69,0x80,0x8e,0xa1,0xb0,0xb4,0xaf,0xa6,0xa0,0xa7,0xa7,0x83,0x60,0x60,0x68,0x73,0x89,0x9c,0xce,0xd4,0xce,0xe1,0xd4,0xc3,0xdc,0xdc,0xe7,0xee,0xf2,0xf7,0xfc,0xf9,0xee,0xea,0xee,0xef,0xeb},

{0xda,0xdc,0xe0,0xe6,0xed,0xf1,0xf2,0xf1,0xf4,0xf7,0xfb,0xfb,0xeb,0xe4,0xd2,0xac,0xa7,0xc3,0xdc,0xd5,0x84,0x77,0x7f,0x79,0x79,0x82,0x8f,0x99,0x9d,0x9b,0x98,0x95,0x9d,0x93,0x79,0x6b,0x78,0x85,0x84,0x82,0x9f,0xd2,0xdb,0xd1,0xdb,0xc6,0xb0,0xc3,0xd1,0xe2,0xef,0xf4,0xf8,0xfb,0xf7,0xee,0xec,0xf0,0xf0,0xeb},

{0xde,0xdc,0xdc,0xe0,0xe8,0xeb,0xe9,0xe6,0xeb,0xee,0xf4,0xf1,0xe4,0xdb,0xc0,0x96,0x89,0xa3,0xb5,0xcd,0x86,0x6c,0x87,0x86,0x78,0x7a,0x7c,0x7c,0x7a,0x79,0x7a,0x7b,0x76,0x6e,0x6e,0x73,0x7a,0x86,0x85,0x76,0x9d,0xd2,0xde,0xd0,0xcd,0xb2,0x98,0xa4,0xc1,0xdb,0xf0,0xf8,0xf8,0xf7,0xf4,0xed,0xed,0xf0,0xee,0xe8},

{0xeb,0xe6,0xde,0xd9,0xd8,0xda,0xdc,0xde,0xef,0xe2,0xd5,0xd3,0xdb,0xd8,0xae,0x7a,0x7a,0x93,0x9f,0xcf,0x8e,0x62,0x83,0x82,0x7d,0x7a,0x74,0x6b,0x62,0x5e,0x5e,0x5f,0x57,0x5b,0x73,0x7d,0x6e,0x71,0x7d,0x76,0x98,0xca,0xd9,0xc9,0xbd,0xa4,0x8f,0x96,0xb5,0xd6,0xf1,0xf9,0xf7,0xf5,0xf2,0xed,0xec,0xee,0xea,0xe2},

{0xf2,0xec,0xe1,0xd3,0xcb,0xcf,0xdd,0xe9,0xf5,0xe8,0xcf,0xc5,0xd3,0xd3,0xad,0x83,0x84,0x9a,0xa5,0xd7,0x93,0x5e,0x76,0x70,0x79,0x76,0x70,0x67,0x5e,0x5a,0x5a,0x5b,0x61,0x63,0x7a,0x82,0x6f,0x6e,0x7b,0x78,0x96,0xc3,0xd3,0xc1,0xb4,0xa6,0x9d,0xa3,0xb4,0xd4,0xf0,0xf7,0xf5,0xf4,0xf3,0xef,0xee,0xef,0xe9,0xde},

{0xea,0xe6,0xdd,0xd0,0xc9,0xd1,0xe6,0xf8,0xf5,0xf7,0xe1,0xca,0xcc,0xcb,0xba,0xac,0xa1,0xb0,0xbd,0xd9,0x8f,0x62,0x6a,0x60,0x68,0x68,0x67,0x64,0x61,0x60,0x62,0x65,0x6d,0x65,0x69,0x70,0x6e,0x6d,0x6f,0x6a,0x9c,0xc2,0xd0,0xbf,0xb3,0xb3,0xb5,0xb9,0xbe,0xd7,0xec,0xf2,0xf2,0xf5,0xf6,0xf2,0xf4,0xf3,0xeb,0xdf},

{0xdf,0xdd,0xd7,0xd0,0xcc,0xd3,0xe2,0xef,0xef,0xf7,0xdf,0xc4,0xc8,0xcc,0xc4,0xc4,0xc2,0xc8,0xd4,0xd2,0x83,0x6a,0x66,0x5d,0x58,0x59,0x5a,0x5a,0x59,0x5a,0x5d,0x60,0x5d,0x5e,0x5b,0x5f,0x65,0x5f,0x5a,0x63,0xa5,0xc4,0xd0,0xbf,0xb4,0xbd,0xc5,0xc6,0xcd,0xdc,0xe7,0xea,0xef,0xf7,0xfa,0xf5,0xf6,0xf5,0xec,0xdd},

{0xdb,0xd8,0xd3,0xcf,0xcd,0xcf,0xd4,0xd8,0xea,0xea,0xc9,0xb2,0xc6,0xd1,0xc5,0xc1,0xd7,0xd6,0xe2,0xc9,0x77,0x70,0x67,0x61,0x52,0x52,0x51,0x4f,0x4c,0x4b,0x4d,0x4f,0x49,0x5f,0x65,0x63,0x62,0x52,0x53,0x70,0xaa,0xc5,0xd0,0xbe,0xb3,0xbf,0xca,0xc7,0xd8,0xe0,0xe4,0xe4,0xec,0xf9,0xfd,0xf7,0xf6,0xf3,0xe9,0xda},

{0xd4,0xd4,0xd3,0xd1,0xcf,0xd0,0xd3,0xd7,0xd6,0xd3,0xcc,0xc6,0xc7,0xd2,0xe0,0xea,0xfc,0xf2,0xdd,0xc1,0x7f,0x56,0x63,0x5c,0x59,0x54,0x4e,0x4c,0x4a,0x49,0x4b,0x4f,0x56,0x46,0x62,0x54,0x63,0x47,0x46,0x9c,0xaa,0xc2,0xcd,0xbf,0xb1,0xb3,0xba,0xbd,0xb8,0xbd,0xd1,0xe2,0xe9,0xf5,0xfd,0xf8,0xf7,0xf0,0xe0,0xd0},

{0xd3,0xd4,0xd4,0xd2,0xcf,0xcf,0xd1,0xd3,0xd0,0xd4,0xd6,0xd8,0xdf,0xe9,0xf1,0xf4,0xfc,0xf3,0xdd,0xc0,0x7f,0x52,0x5b,0x54,0x57,0x53,0x4e,0x4b,0x4a,0x4a,0x4d,0x50,0x52,0x45,0x57,0x4d,0x55,0x40,0x5a,0x9e,0xb1,0xc4,0xc9,0xb7,0xa9,0xad,0xb3,0xb1,0xbd,0xb7,0xbc,0xc1,0xc7,0xdd,0xf2,0xf5,0xf0,0xe5,0xd1,0xbc},

{0xca,0xcc,0xcc,0xcb,0xc7,0xc5,0xc4,0xc5,0xc3,0xd3,0xe4,0xef,0xf7,0xfc,0xfd,0xfb,0xfb,0xf3,0xdb,0xbf,0x81,0x4f,0x51,0x4c,0x53,0x51,0x4d,0x4a,0x4a,0x4c,0x4f,0x51,0x50,0x49,0x4d,0x49,0x46,0x3d,0x7d,0xa3,0xb8,0xc6,0xc3,0xac,0xa0,0xa7,0xa9,0x9f,0xaf,0xa7,0xa8,0xac,0xb6,0xd5,0xf0,0xf4,0xdf,0xd4,0xbe,0xa8},

{0xbc,0xbe,0xc0,0xbf,0xba,0xb6,0xb3,0xb3,0xb4,0xd2,0xf0,0xfc,0xfd,0xfd,0xfd,0xfd,0xfa,0xf4,0xda,0xbf,0x86,0x4f,0x4a,0x49,0x4f,0x4f,0x4d,0x49,0x49,0x4e,0x51,0x51,0x4e,0x4f,0x4b,0x4c,0x40,0x40,0x9e,0xa9,0xba,0xc7,0xc0,0xa6,0x9d,0xa8,0xa3,0x90,0x95,0x96,0xa3,0xb3,0xc6,0xe6,0xfb,0xf6,0xfd,0xfc,0xee,0xde}

};

