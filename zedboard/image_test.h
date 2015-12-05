in_flag =1;
in_width = 60;
in_height = 60;
in_maxgrey = 255;
unsigned char Data[60][60]={
{0xb8,0xb8,0xb8,0xba,0xba,0xbc,0xbc,0xbc,0xbe,0xc0,0xbf,0xc1,0xc1,0xc3,0xc3,0xc3,0xc5,0xc5,0xc5,0xc7,0xc7,0xc9,0xc8,0xc8,0xd1,0xca,0xc8,0xcb,0xd4,0xd6,0xd1,0xd8,0xcb,0xd2,0xd3,0x67,0x11,0x24,0x36,0x1f,0x24,0x2c,0x16,0xe,0x11,0x12,0x16,0x1b,0x1b,0x18,0x29,0x17,0x1a,0x16,0x2b,0x92,0xee,0xe4,0xe1,0xf0},

{0xb6,0xb8,0xb8,0xb8,0xba,0xbb,0xbb,0xbb,0xbd,0xbe,0xc0,0xc0,0xc1,0xc1,0xc3,0xc3,0xc4,0xc4,0xc5,0xc7,0xc7,0xc9,0xc9,0xc9,0xc3,0xd0,0xd2,0xc6,0xc8,0xd0,0xd0,0xd0,0xd3,0xe0,0x5c,0x20,0x9,0x17,0x2c,0x18,0x10,0x10,0x19,0x1b,0x10,0xb,0xd,0xf,0xf,0x13,0x29,0x18,0x18,0x10,0xa,0x16,0x49,0xc8,0xe9,0xe1},

{0xb6,0xb6,0xb6,0xb8,0xb8,0xba,0xba,0xbc,0xbe,0xbe,0xbd,0xbf,0xbf,0xc1,0xc1,0xc1,0xc5,0xc5,0xc5,0xc7,0xc7,0xc8,0xc8,0xc8,0xc6,0xd2,0xce,0xcc,0xd7,0xd9,0xd2,0xce,0xce,0x7a,0x17,0x15,0x11,0xb,0xd,0x10,0xd,0x1f,0x37,0x21,0xe,0x9,0x5,0x9,0x6,0x10,0x29,0x13,0xe,0xc,0x8,0x9,0x10,0x79,0xf2,0xe3},

{0xb5,0xb5,0xb6,0xb6,0xb8,0xb8,0xba,0xba,0xbc,0xbc,0xbb,0xbd,0xbd,0xbf,0xbf,0xc1,0xc3,0xc3,0xc5,0xc5,0xc7,0xc7,0xc9,0xc9,0xd4,0xcd,0xc2,0xcc,0xcf,0xc2,0xc8,0xcb,0xa5,0x2e,0xf,0x19,0x14,0xc,0x9,0x18,0x17,0x11,0x28,0x33,0x16,0xb,0x8,0x4,0x4,0xe,0x27,0x12,0x8,0x9,0xc,0xf,0xf,0x26,0xb9,0xf5},

{0xb3,0xb3,0xb5,0xb5,0xb7,0xb7,0xb9,0xb9,0xbb,0xba,0xbc,0xbc,0xbe,0xbe,0xc0,0xc0,0xc1,0xc3,0xc3,0xc3,0xc5,0xc7,0xc7,0xc6,0xc7,0xc8,0xc7,0xd1,0xc9,0xc7,0xd5,0xc2,0x43,0x1c,0x1a,0x14,0xf,0x1d,0x19,0x18,0x1a,0x2b,0x25,0x1e,0x18,0xa,0x6,0x7,0x4,0x7,0x12,0xc,0x7,0x9,0xe,0xf,0xf,0x7,0x41,0xd7},

{0xb2,0xb4,0xb4,0xb5,0xb5,0xb7,0xb7,0xb7,0xb8,0xb8,0xba,0xba,0xbc,0xbc,0xbd,0xbd,0xc0,0xc0,0xc2,0xc1,0xc3,0xc3,0xc5,0xc5,0xc1,0xcb,0xcb,0xd3,0xd3,0xe1,0xbb,0x56,0x1c,0x23,0x24,0x24,0x25,0x2f,0x26,0x15,0x13,0x37,0x47,0x29,0xe,0xa,0xd,0x4,0x4,0x3,0x6,0x9,0xb,0xe,0x13,0x11,0xf,0x9,0x10,0x87},

{0xb2,0xb2,0xb2,0xb3,0xb5,0xb5,0xb5,0xb7,0xb9,0xb9,0xb9,0xbb,0xba,0xbc,0xbc,0xbc,0xbe,0xbe,0xc0,0xc0,0xc2,0xc2,0xc4,0xc4,0xcc,0xc9,0xc4,0xc9,0xc8,0xd2,0x87,0x16,0x30,0x3d,0x2e,0x41,0x56,0x41,0x37,0x2e,0x27,0x3b,0x2e,0x18,0x10,0xb,0x7,0x6,0x4,0x4,0x8,0xf,0x12,0x14,0x13,0xd,0xa,0xc,0x7,0x28},

{0xb1,0xb1,0xb1,0xb3,0xb3,0xb5,0xb5,0xb5,0xb7,0xb7,0xb9,0xb9,0xbb,0xbb,0xbc,0xbc,0xbd,0xbf,0xbe,0xbe,0xc0,0xc2,0xc2,0xc2,0xc8,0xbf,0xc1,0xd0,0xc0,0xd0,0x98,0x20,0x40,0x4f,0x3a,0x3e,0x5d,0x58,0x4e,0x45,0x38,0x31,0x29,0x12,0xb,0xf,0x9,0x4,0x4,0x5,0x8,0xe,0x13,0x13,0x10,0x9,0xa,0xc,0xf,0xe},

{0xaf,0xaf,0xb1,0xb1,0xb3,0xb4,0xb6,0xb8,0xaf,0xb4,0xb8,0xb9,0xb5,0xb5,0xb9,0xbd,0xbb,0xbf,0xc1,0xc2,0xc5,0xc4,0xc2,0xc0,0xc4,0xcc,0xc0,0xc8,0xcd,0xbd,0x3f,0x34,0x32,0x3e,0x3f,0x40,0x3e,0x4a,0x61,0x51,0x2a,0x22,0x14,0xc,0xc,0xd,0x8,0x5,0x7,0x6,0x7,0x12,0x18,0xf,0x15,0xb,0xa,0xc,0xb,0xa},

{0xae,0xb0,0xb1,0xb0,0xb0,0xb1,0xb1,0xb2,0xbe,0xba,0xb5,0xb4,0xb8,0xbc,0xb9,0xb7,0xb7,0xb8,0xba,0xb9,0xb9,0xbb,0xbc,0xbf,0xc1,0xc1,0xc3,0xd4,0xc3,0x81,0x26,0x22,0x32,0x3a,0x56,0x58,0x89,0xa3,0x40,0x1a,0x14,0x10,0x16,0x1a,0x10,0xb,0xb,0x8,0xc,0x12,0xe,0xe,0x15,0xf,0x14,0x10,0xe,0xe,0xb,0x7},

{0xaa,0xae,0xb2,0xb1,0xad,0xab,0xad,0xaf,0xb6,0xb1,0xad,0xb2,0xb6,0xbc,0xbb,0xb8,0xb4,0xba,0xbf,0xc0,0xbe,0xbf,0xbf,0xc1,0xc8,0xbb,0xbc,0xc1,0x9f,0x46,0x1b,0x20,0x2a,0x58,0x50,0x4f,0x8f,0x6d,0x23,0x1c,0x20,0x20,0x2c,0x2a,0x17,0x14,0x14,0xc,0x11,0x24,0x1e,0x11,0x17,0x11,0xf,0xe,0xc,0xf,0xd,0x8},

{0xa9,0xad,0xaf,0xaf,0xac,0xac,0xae,0xb2,0xae,0xb4,0xb7,0xb5,0xb0,0xae,0xaf,0xb1,0xb6,0xba,0xbc,0xbb,0xb8,0xb8,0xbc,0xbe,0xcf,0xc0,0xcc,0xc6,0x9c,0x44,0x35,0x46,0x4c,0x53,0x59,0x75,0x6e,0x4b,0x44,0x3e,0x3d,0x4b,0x42,0x2b,0x22,0x24,0x25,0x26,0x12,0x21,0x23,0x13,0x14,0x11,0xd,0xa,0xc,0x10,0x11,0xc},

{0xa9,0xaa,0xab,0xab,0xac,0xad,0xb0,0xb4,0xae,0xb4,0xb6,0xb3,0xad,0xa7,0xa5,0xa7,0xa8,0xa4,0x9d,0x95,0x94,0x99,0xa4,0xab,0xac,0xb1,0xc6,0xac,0x7b,0x33,0x2e,0x35,0x47,0x52,0x92,0xa9,0x99,0x80,0x64,0x78,0x6f,0x79,0x5f,0x44,0x3c,0x37,0x3f,0x5f,0x30,0x2d,0x2c,0x18,0x11,0xf,0xf,0xa,0x7,0xa,0xa,0x7},

{0xa9,0xa9,0xa9,0xa9,0xab,0xae,0xae,0xb0,0xb5,0xab,0x9e,0x96,0x90,0x8c,0x87,0x83,0x7d,0x7a,0x77,0x76,0x77,0x7a,0x7f,0x82,0x8a,0x97,0xac,0x83,0x55,0x30,0x2f,0x2b,0x2b,0x7f,0x8d,0x87,0xad,0x91,0x7f,0xae,0x90,0x89,0x71,0x56,0x44,0x45,0x48,0x47,0x57,0x40,0x36,0x20,0x13,0x10,0x12,0xd,0x8,0x9,0x9,0x9},

{0xa7,0xa6,0xa6,0xa9,0xad,0xab,0xa6,0xa1,0x9d,0x89,0x72,0x5f,0x58,0x56,0x56,0x56,0x57,0x53,0x4e,0x4e,0x54,0x5a,0x5f,0x61,0x72,0x7a,0x7a,0x50,0x31,0x32,0x38,0x31,0x5d,0x8a,0x6b,0x8a,0x8f,0x85,0xc5,0xae,0xa5,0x95,0x84,0x66,0x54,0x64,0x63,0x41,0x48,0x41,0x33,0x21,0x1a,0x11,0x11,0xe,0x8,0x7,0x9,0xd},

{0xa7,0xa5,0xa5,0xaa,0xad,0xa9,0x9d,0x95,0x60,0x56,0x46,0x39,0x34,0x3a,0x47,0x52,0x45,0x3b,0x2f,0x2c,0x31,0x3e,0x4c,0x54,0x4f,0x50,0x4e,0x31,0x22,0x3b,0x50,0x4d,0x9a,0x81,0x83,0xb1,0xa7,0x90,0xbd,0xb9,0xa9,0x94,0x86,0x73,0x60,0x64,0x6a,0x5e,0x49,0x54,0x3c,0x25,0x25,0x13,0xe,0xe,0xc,0x9,0xa,0x11},

{0xa8,0x9a,0xac,0xa7,0xa2,0x9f,0x6f,0x4e,0x54,0x50,0x32,0x1c,0x23,0x3c,0x53,0x5d,0x53,0x4d,0x43,0x36,0x2e,0x2d,0x36,0x42,0x41,0x40,0x41,0x30,0x34,0x35,0x39,0x5d,0x8a,0x6b,0x94,0xa6,0x97,0x98,0xb4,0xb0,0x9b,0x97,0x93,0x72,0x64,0x6b,0x64,0x62,0x5f,0x4a,0x44,0x2c,0x23,0x14,0x12,0xa,0xc,0xb,0x9,0xb},

{0xab,0xac,0xa2,0xae,0xaa,0x6c,0x49,0x4f,0x3a,0x1d,0xd,0x16,0x44,0x72,0x6b,0x57,0x53,0x54,0x63,0x6c,0x53,0x37,0x32,0x3c,0x3e,0x35,0x46,0x39,0x25,0x2d,0x39,0x5f,0x94,0x72,0x7a,0xa2,0x9c,0x85,0xaa,0xa3,0x92,0x83,0x84,0x7f,0x78,0x74,0x67,0x64,0x5d,0x56,0x4a,0x38,0x30,0x1b,0xf,0xb,0xc,0xc,0xe,0xe},

{0x9f,0xa0,0xa1,0xab,0x80,0x53,0x47,0x32,0x19,0xd,0xd,0x1f,0x3c,0x3e,0x36,0x35,0x2d,0x29,0x35,0x4f,0x5a,0x54,0x45,0x36,0x4d,0x4c,0x54,0x3a,0x20,0x33,0x4b,0x88,0x92,0x56,0x76,0xab,0x93,0x7a,0x9d,0x95,0x8e,0x8c,0x81,0x79,0x76,0x79,0x74,0x5c,0x5b,0x5c,0x38,0x31,0x26,0x21,0xd,0xc,0xc,0xa,0xe,0xf},

{0xa5,0xa2,0xa9,0x95,0x5a,0x46,0x3c,0x1b,0x20,0x18,0x1e,0x35,0x3d,0x30,0x2d,0x34,0x2c,0x27,0x25,0x25,0x31,0x4b,0x4d,0x35,0x2e,0x47,0x6c,0x65,0x23,0x27,0x4c,0x7c,0x5f,0x3b,0x84,0xaf,0x9f,0x99,0x94,0xa4,0xa5,0x9c,0x8f,0x9c,0x97,0x86,0x83,0x70,0x5d,0x42,0x33,0x20,0x2c,0x21,0x16,0x7,0x12,0x9,0xb,0xd},

{0xa5,0xa4,0x9f,0x75,0x4d,0x35,0x2b,0x31,0x33,0x22,0x23,0x34,0x3f,0x42,0x43,0x42,0x48,0x4e,0x4b,0x36,0x28,0x33,0x4f,0x5f,0x34,0x2f,0x4e,0x8e,0x3d,0x21,0x3e,0x47,0x47,0x52,0x92,0x9e,0xa2,0x78,0x4c,0x57,0x67,0x8b,0x90,0x90,0x99,0xa2,0x9d,0x72,0x3b,0x30,0x39,0x4a,0x2e,0x26,0x15,0x8,0x1f,0x12,0xb,0xb},

{0x9b,0x94,0x97,0x61,0x31,0x28,0x37,0x61,0x2c,0x20,0x22,0x2e,0x30,0x35,0x38,0x32,0x3b,0x3a,0x41,0x42,0x31,0x24,0x33,0x57,0x73,0x48,0x2a,0x61,0x73,0x32,0x2e,0x3f,0x48,0x70,0x90,0xa3,0x7f,0x43,0x32,0x13,0x29,0x5d,0x92,0xa4,0xa2,0x80,0x54,0x39,0x22,0x17,0x2a,0x65,0x4a,0x34,0x18,0x9,0x26,0x22,0xe,0xa},

{0xa2,0x95,0x87,0x4a,0x1b,0x20,0x46,0x65,0x2e,0x22,0x28,0x37,0x33,0x31,0x32,0x2b,0x3b,0x36,0x35,0x41,0x45,0x33,0x2a,0x34,0x62,0x70,0x3e,0x3a,0x78,0x3f,0x25,0x37,0x31,0x69,0x8a,0xab,0x8b,0x59,0x65,0x25,0x54,0x5f,0x8e,0xb7,0x8c,0x2b,0x1f,0x5c,0x8a,0x26,0x23,0x1b,0x57,0x2b,0x29,0xd,0x24,0x2f,0x12,0x10},

{0x98,0x9c,0x5d,0x31,0x20,0x20,0x3f,0x66,0x36,0x26,0x2f,0x3e,0x31,0x27,0x2d,0x30,0x2b,0x38,0x36,0x36,0x46,0x48,0x39,0x32,0x3d,0x6f,0x6a,0x30,0x55,0x53,0x33,0x1b,0x1e,0x78,0x93,0x97,0xab,0x88,0x81,0x67,0x53,0x72,0xaa,0xba,0x73,0x1f,0x24,0x9b,0x98,0x59,0x31,0x33,0x57,0x47,0x27,0x17,0x23,0x35,0x14,0x1b},

{0x9a,0x8d,0x55,0x2a,0x15,0x2a,0x6b,0x57,0x2e,0x3e,0x55,0x56,0x43,0x32,0x2c,0x2f,0x2b,0x35,0x39,0x37,0x43,0x55,0x53,0x42,0x43,0x47,0x6f,0x52,0x40,0x7a,0x2b,0x1a,0x15,0x68,0x7e,0x9d,0x9f,0xb1,0xb4,0x9e,0x90,0x8f,0xad,0xbd,0x6d,0x2b,0x3b,0x86,0x98,0x81,0x8b,0x87,0x68,0x49,0x2b,0x1a,0x30,0x26,0x13,0x1f},

{0x92,0x86,0x47,0x1d,0x1f,0x4f,0x67,0x35,0x3b,0x5b,0x84,0x8b,0x68,0x45,0x3a,0x3a,0x34,0x40,0x47,0x41,0x3c,0x45,0x56,0x61,0x4b,0x3e,0x50,0x53,0x38,0x58,0x40,0x1c,0xd,0x3b,0x6f,0x7e,0xa2,0xa5,0x99,0xa3,0xa5,0xaf,0xb4,0xb0,0x6a,0x31,0x3d,0x7a,0x99,0x8f,0x8d,0x7a,0x57,0x3d,0x25,0x16,0x27,0x14,0x1b,0x79},

{0x8e,0x78,0x3b,0x1c,0x2d,0x54,0x41,0x1e,0x46,0x6e,0x8a,0x96,0x87,0x67,0x54,0x3c,0x4a,0x50,0x54,0x53,0x4e,0x4f,0x5d,0x71,0x70,0x3c,0x2a,0x47,0x38,0x41,0x5e,0x20,0xe,0x20,0x77,0x84,0xa7,0xa5,0x99,0xaf,0xb3,0xc3,0xb3,0x9d,0x6a,0x38,0x3c,0x67,0x97,0x9d,0x8d,0x6d,0x47,0x37,0x28,0x19,0xe,0xf,0x54,0xee},

{0x91,0x6a,0x37,0x2b,0x37,0x31,0x21,0x20,0x54,0x7d,0x81,0x85,0x8a,0x85,0x78,0x4a,0x4b,0x4d,0x55,0x63,0x6b,0x6d,0x6f,0x72,0x95,0x4a,0x17,0x2d,0x38,0x2f,0x5b,0x31,0x13,0xf,0x5a,0x87,0x95,0xb4,0xad,0xa7,0xa4,0xb2,0xb1,0xa7,0x6e,0x37,0x36,0x4e,0x8e,0x92,0x7e,0x68,0x46,0x37,0x20,0xc,0x5,0xc,0x7f,0xeb},

{0x80,0x57,0x29,0x28,0x2e,0x1a,0x14,0x24,0x5b,0x81,0x87,0x8d,0x88,0x7e,0x83,0x66,0x50,0x57,0x5f,0x65,0x6a,0x6f,0x75,0x76,0x8f,0x5f,0x15,0x18,0x29,0x1b,0x35,0x4e,0x26,0x15,0x3d,0x7a,0x81,0xb7,0xa2,0x7c,0x9c,0x9c,0xb2,0xb1,0x68,0x2f,0x2b,0x38,0x88,0x8a,0x74,0x61,0x40,0x2f,0x13,0x6,0xd,0x43,0xee,0xee},

{0x82,0x57,0x24,0x19,0x23,0x18,0x11,0x25,0x67,0x7c,0x8c,0xa7,0x9e,0x81,0x86,0x86,0x71,0x71,0x6c,0x64,0x68,0x77,0x83,0x87,0x7f,0x6c,0x1b,0xd,0x17,0xf,0x16,0x52,0x3f,0x35,0x44,0x71,0x79,0xa3,0x7f,0x70,0xa6,0x99,0x9f,0x97,0x51,0x27,0x27,0x2d,0x73,0x91,0x7d,0x54,0x32,0x26,0x1c,0x37,0xbc,0xdd,0xe7,0xe5},

{0x75,0x4b,0x1f,0xb,0x13,0xe,0x5,0x28,0x86,0x87,0x94,0xb0,0xb2,0x9b,0x92,0x95,0x82,0x7a,0x72,0x71,0x7a,0x88,0x8e,0x8a,0x82,0x7f,0x2e,0x11,0xc,0x8,0x9,0x40,0x44,0x40,0x4d,0x61,0x75,0x86,0x79,0x84,0xaa,0xae,0xab,0x97,0x64,0x42,0x3b,0x32,0x38,0x76,0x76,0x4c,0x35,0x2a,0x32,0xd8,0xd4,0xf4,0xe9,0xee},

{0x7d,0x4d,0x2c,0xf,0x15,0xc,0x3,0x4c,0x96,0x95,0x9a,0x98,0x95,0x91,0x87,0x85,0x86,0x86,0x88,0x89,0x84,0x79,0x6d,0x67,0x86,0x97,0x54,0x1f,0x6,0x4,0x6,0x37,0x56,0x3c,0x52,0x58,0x7e,0x83,0x86,0x87,0x6b,0x89,0x8b,0x7a,0x65,0x4c,0x31,0x1b,0x35,0x89,0x8b,0x59,0x41,0x1f,0x10,0x97,0xe9,0xdd,0xef,0xe7},

{0x72,0x55,0x32,0x17,0x11,0x1d,0x1c,0x6f,0x79,0x6d,0x5b,0x38,0x49,0x74,0x91,0x8a,0x8c,0x80,0x87,0x67,0x40,0x2f,0x46,0x5d,0x77,0x9f,0x7e,0x2b,0xc,0x9,0x8,0x34,0x63,0x33,0x42,0x4b,0x78,0x91,0x9b,0x9b,0x67,0x4a,0x86,0x7e,0x78,0x3e,0x16,0x1b,0x6b,0xa8,0x81,0x5e,0x3c,0x15,0xd,0x26,0xe3,0xea,0xda,0xef},

{0x72,0x4e,0x2f,0x15,0xb,0x26,0x4a,0x9a,0xad,0x73,0x3f,0x31,0x45,0x56,0x7c,0x81,0x82,0x8a,0x85,0x53,0x32,0x22,0x37,0x57,0x91,0xb3,0x89,0x3c,0x1f,0x11,0xb,0x2d,0x57,0x23,0x2d,0x39,0x63,0x83,0x9d,0xa8,0xa0,0x65,0x70,0x57,0x53,0x37,0x2c,0x4f,0x7c,0x92,0x7e,0x58,0x27,0x11,0xb,0xf,0x67,0xdd,0xf6,0xda},

{0x75,0x5c,0x37,0x17,0x7,0x25,0x73,0xae,0x65,0x1b,0x12,0x12,0x2d,0x4b,0x50,0x80,0x8e,0x90,0x73,0x42,0x2e,0x1a,0x16,0x18,0x3d,0x86,0x99,0x52,0x28,0xb,0xc,0x39,0x57,0x20,0x27,0x34,0x55,0x74,0x98,0xaf,0xc0,0x98,0x8d,0x65,0x5e,0x4f,0x4d,0x66,0x79,0x72,0x67,0x3b,0x12,0xe,0xf,0xd,0x1a,0x8a,0xe3,0xe6},

{0x6c,0x64,0x3c,0x1f,0xc,0x25,0x7a,0xb3,0x7c,0x3c,0x4f,0x42,0x49,0x51,0x4d,0x95,0xa9,0x8d,0x66,0x4a,0x52,0x47,0x39,0x30,0x35,0x77,0x8f,0x57,0x2e,0x9,0xe,0x3a,0x47,0x1e,0x29,0x36,0x4c,0x64,0x83,0xa8,0xa7,0xaf,0xba,0x90,0x86,0x76,0x66,0x55,0x62,0x55,0x40,0x1b,0xc,0xe,0xf,0x12,0xd,0x2f,0x7d,0xd3},

{0x72,0x66,0x45,0x32,0x16,0x1c,0x5e,0xa9,0xa7,0x9e,0x88,0x7b,0x72,0x5f,0x8e,0xae,0xad,0x8d,0x78,0x68,0x73,0x6c,0x6e,0x69,0x73,0x8a,0x82,0x5a,0x29,0x7,0x11,0x3f,0x32,0x1c,0x2c,0x3c,0x56,0x63,0x71,0xa1,0xab,0xac,0xb1,0xa2,0x91,0x70,0x62,0x56,0x3a,0x30,0x21,0xf,0xf,0x13,0x12,0x15,0x14,0xf,0x30,0x75},

{0x75,0x68,0x5e,0x49,0x17,0xb,0x30,0x91,0xb8,0xb2,0x92,0x83,0x94,0x99,0xc0,0xb2,0xa7,0x96,0x93,0x83,0x7f,0x6c,0x69,0x65,0x82,0x83,0x8b,0x63,0x15,0x3,0x17,0x52,0x27,0x20,0x30,0x44,0x63,0x5a,0x53,0x96,0xa4,0xaa,0xb2,0xa1,0x81,0x5f,0x4b,0x3c,0x2d,0x24,0x1d,0x13,0x13,0x18,0x20,0x20,0x17,0xf,0x1e,0x30},

{0x67,0x66,0x68,0x52,0x25,0xb,0x18,0x7f,0xac,0xad,0xc7,0xac,0xa5,0xa6,0xaa,0xc0,0xaf,0xa2,0x8f,0x7a,0x93,0x93,0x96,0x96,0x86,0x82,0x8d,0x59,0xa,0x6,0x26,0x3e,0x1f,0x24,0x35,0x49,0x60,0x3c,0x31,0x90,0x85,0x8b,0x98,0x8c,0x71,0x59,0x42,0x2f,0x3e,0x37,0x2a,0x1a,0x1a,0x1f,0x2a,0x26,0x15,0x1f,0x26,0x23},

{0x6f,0x71,0x61,0x51,0x4c,0x1a,0x10,0x66,0x9b,0xa3,0x9b,0x92,0x86,0x74,0xad,0xd5,0xad,0xa7,0x7a,0x59,0x7a,0x86,0x86,0x8a,0x8d,0x87,0x83,0x3f,0x5,0x10,0x3d,0x26,0x1d,0x2c,0x41,0x54,0x61,0x2e,0x26,0xa4,0x97,0x71,0x68,0x6f,0x67,0x5b,0x57,0x60,0x4c,0x46,0x28,0x19,0x2b,0x32,0x32,0x21,0x17,0x33,0x31,0x2a},

{0x69,0x6d,0x70,0x55,0x55,0x15,0x7,0x58,0x92,0x8f,0x8c,0x87,0x55,0x5f,0xba,0xb3,0xa7,0xae,0x84,0x65,0x4d,0x64,0x7e,0x79,0x89,0x75,0x81,0x3a,0x14,0x28,0x2c,0x1f,0x25,0x37,0x42,0x65,0x55,0x19,0x59,0xa5,0xa2,0x92,0x86,0x89,0x8c,0x80,0x6d,0x61,0x5a,0x45,0x28,0x27,0x42,0x3a,0x3f,0x1d,0x35,0x41,0x40,0x34},

{0x63,0x69,0x66,0x5c,0x56,0x2d,0xc,0x49,0x7e,0x78,0x78,0x63,0x50,0x59,0x6a,0x6c,0x7f,0x76,0x70,0x72,0x49,0x47,0x64,0x74,0x6c,0x75,0x86,0x3d,0x1a,0x1f,0x1f,0x21,0x2e,0x36,0x59,0x5e,0x49,0x25,0x82,0xa3,0x8d,0x91,0x93,0x91,0x8c,0x82,0x74,0x6b,0x54,0x46,0x32,0x42,0x4a,0x4c,0x2c,0x2c,0x4b,0x4c,0x46,0x3e},

{0x5c,0x64,0x62,0x68,0x53,0x44,0x15,0x38,0x8b,0x64,0x5c,0x47,0x4f,0x81,0x7f,0x63,0x7c,0x65,0x4e,0x74,0x85,0x5f,0x49,0x62,0x5a,0x6c,0x73,0x2b,0x15,0x12,0x1a,0x25,0x39,0x40,0x67,0x5d,0x30,0x47,0xa1,0x9e,0x8f,0x9e,0xa0,0x97,0x8a,0x7f,0x72,0x67,0x4c,0x3e,0x43,0x53,0x54,0x4a,0x21,0x41,0x4f,0x43,0x3a,0x38},

{0x67,0x69,0x67,0x70,0x54,0x4f,0x31,0x38,0x88,0x65,0x5a,0x3a,0x1b,0x29,0x4e,0x48,0x3e,0x3c,0x51,0x56,0x25,0x25,0x43,0x58,0x61,0x71,0x61,0x1e,0x15,0x13,0x25,0x2f,0x40,0x59,0x62,0x5f,0x23,0x7d,0x9b,0x9b,0xa6,0xa4,0xa0,0x99,0x8f,0x7e,0x6a,0x5a,0x4d,0x3f,0x54,0x51,0x5d,0x35,0x2e,0x55,0x56,0x45,0x3b,0x3c},

{0x61,0x5f,0x59,0x59,0x50,0x4f,0x55,0x2b,0x4e,0x79,0x6e,0x58,0x2c,0x22,0x62,0x84,0x6b,0x82,0x85,0x47,0x14,0x24,0x59,0x72,0x66,0x7c,0x49,0x16,0x23,0x1f,0x2a,0x2f,0x47,0x6d,0x5f,0x4d,0x37,0xa5,0x94,0xa8,0xa6,0xa0,0x9e,0x9e,0x94,0x7c,0x63,0x57,0x51,0x51,0x57,0x5a,0x54,0x30,0x4d,0x63,0x5f,0x53,0x4b,0x4b},

{0x49,0x4e,0x46,0x49,0x53,0x4b,0x49,0x16,0x29,0x8f,0x81,0x77,0x82,0x6d,0x88,0x8d,0xa1,0x95,0x5d,0x4b,0x60,0x76,0x62,0x71,0x6f,0x7f,0x2c,0x13,0x35,0x2a,0x24,0x2e,0x49,0x63,0x5d,0x2f,0x6a,0xa5,0x9f,0xb2,0x99,0x9d,0xa4,0xa5,0x8f,0x6b,0x59,0x54,0x4c,0x5e,0x4d,0x63,0x3e,0x3d,0x5f,0x60,0x59,0x55,0x52,0x4e},

{0x4a,0x55,0x47,0x58,0x5a,0x41,0x2d,0x1f,0x31,0x56,0x76,0x8e,0xa5,0x8f,0x6f,0x5e,0x5f,0x45,0x4d,0x7e,0x93,0x96,0x78,0x79,0x86,0x6a,0x1a,0x1c,0x46,0x32,0x29,0x35,0x3f,0x4a,0x46,0x1c,0x84,0x97,0x9a,0xa5,0x99,0xa3,0xa7,0x98,0x78,0x5e,0x54,0x53,0x51,0x59,0x51,0x53,0x38,0x51,0x63,0x5d,0x58,0x58,0x54,0x52},

{0x60,0x64,0x47,0x62,0x4f,0x30,0x1c,0x4c,0x32,0xb,0x39,0xa0,0xa8,0x98,0x7b,0x7d,0x80,0x8b,0x92,0x98,0x94,0x95,0x76,0x81,0x87,0x44,0xf,0x28,0x47,0x30,0x2c,0x34,0x34,0x38,0x2c,0x16,0x74,0x89,0x88,0x8d,0x9a,0xa5,0xa1,0x84,0x66,0x5a,0x59,0x59,0x5f,0x50,0x68,0x3e,0x42,0x5e,0x6b,0x63,0x5a,0x58,0x55,0x53},

{0x50,0x3b,0x54,0x5e,0x36,0x1d,0x38,0x59,0x1c,0x5,0x7,0x38,0xb4,0xbd,0x9a,0x9d,0x95,0xaf,0x98,0x9c,0xac,0x92,0x85,0x87,0x78,0x19,0x15,0x3a,0x3e,0x35,0x29,0x32,0x2d,0x43,0x2d,0x11,0x42,0x70,0x72,0x84,0x88,0x8e,0x81,0x6e,0x63,0x5b,0x57,0x5a,0x55,0x61,0x4a,0x3d,0x5c,0x70,0x68,0x6b,0x61,0x5d,0x58,0x54},

{0x42,0x32,0x5f,0x3f,0x17,0x2a,0x52,0x38,0x19,0x6,0x3,0x10,0x5e,0xb4,0xc2,0xae,0xa9,0x9e,0x9c,0xa3,0x9e,0x89,0x80,0x7f,0x4a,0x10,0x19,0x3b,0x3b,0x3b,0x2d,0x31,0x2a,0x46,0x51,0x27,0x37,0x45,0x55,0x6a,0x69,0x72,0x6b,0x5c,0x5a,0x5a,0x59,0x5a,0x5a,0x5e,0x4d,0x49,0x62,0x75,0x6b,0x61,0x61,0x5e,0x59,0x55},

{0x2b,0x42,0x61,0x25,0x18,0x51,0x61,0x2a,0x16,0x6,0x4,0xb,0x3c,0x8c,0xae,0xa8,0xac,0xa5,0xa7,0x98,0x85,0x82,0x71,0x5e,0x1f,0xd,0x24,0x3c,0x34,0x41,0x34,0x29,0x30,0x3d,0x5d,0x44,0x50,0x4d,0x42,0x34,0x3f,0x4c,0x50,0x50,0x59,0x60,0x5c,0x58,0x5f,0x4f,0x4b,0x5a,0x6c,0x75,0x70,0x68,0x63,0x5f,0x5b,0x57},

{0x23,0x64,0x3d,0x17,0x3a,0x64,0x40,0x28,0x14,0x9,0xd,0x1d,0x3f,0x67,0x7b,0x81,0x79,0x7e,0x7d,0x77,0x6e,0x67,0x57,0x3f,0xc,0x15,0x33,0x3d,0x2d,0x3f,0x40,0x21,0x2d,0x3b,0x5e,0x44,0x51,0x55,0x49,0x3c,0x37,0x3d,0x40,0x47,0x54,0x5b,0x58,0x58,0x63,0x44,0x4c,0x6c,0x71,0x6d,0x72,0x74,0x67,0x63,0x5c,0x58},

{0x3b,0x64,0x22,0x24,0x66,0x51,0x30,0x29,0x15,0xe,0x18,0x27,0x38,0x61,0x72,0x64,0x66,0x62,0x60,0x71,0x5f,0x4b,0x41,0x21,0x8,0x25,0x3e,0x39,0x2a,0x3b,0x52,0x21,0x1f,0x3b,0x62,0x3d,0x4f,0x58,0x4d,0x4e,0x4f,0x45,0x39,0x3a,0x46,0x4c,0x53,0x5f,0x57,0x48,0x58,0x74,0x6f,0x6b,0x74,0x70,0x6b,0x65,0x5e,0x59},

{0x56,0x36,0x20,0x55,0x6a,0x3e,0x35,0x22,0x1a,0xe,0x16,0x25,0x32,0x64,0x79,0x66,0x6c,0x68,0x6e,0x6c,0x4d,0x47,0x35,0xa,0x10,0x36,0x43,0x34,0x2a,0x3b,0x5e,0x2e,0x17,0x35,0x61,0x3b,0x50,0x5f,0x4b,0x45,0x57,0x48,0x38,0x35,0x3f,0x47,0x50,0x5f,0x40,0x4f,0x69,0x70,0x6b,0x78,0x7d,0x6a,0x6c,0x67,0x5f,0x5a},

{0x4d,0x1f,0x32,0x70,0x4f,0x38,0x2c,0x1b,0x1f,0xf,0x19,0x31,0x32,0x57,0x73,0x71,0x5d,0x5b,0x65,0x52,0x45,0x46,0x23,0x8,0x25,0x3f,0x44,0x30,0x2c,0x3b,0x5d,0x43,0x17,0x2f,0x68,0x3a,0x36,0x48,0x4e,0x4c,0x52,0x48,0x38,0x31,0x3a,0x45,0x4c,0x52,0x41,0x5d,0x6f,0x68,0x6b,0x7d,0x7d,0x6a,0x6b,0x67,0x62,0x5e},

{0x49,0x2a,0x56,0x64,0x41,0x3d,0x1e,0x1f,0x22,0x18,0x2c,0x3f,0x2d,0x49,0x6c,0x73,0x68,0x53,0x55,0x49,0x57,0x40,0xf,0x12,0x3c,0x44,0x44,0x2d,0x2e,0x3b,0x53,0x54,0x1b,0x26,0x64,0x3c,0x2b,0x41,0x54,0x4a,0x57,0x52,0x3b,0x2a,0x2f,0x3e,0x45,0x43,0x59,0x6e,0x6f,0x65,0x6b,0x70,0x6c,0x69,0x68,0x67,0x63,0x60},

{0x34,0x25,0x44,0x5f,0x45,0x2e,0x24,0x19,0x22,0x1e,0x31,0x5a,0x28,0x36,0x66,0x72,0x6e,0x5b,0x68,0x61,0x55,0x31,0x1a,0x41,0x49,0x49,0x35,0x2f,0x33,0x3b,0x55,0x68,0x1c,0x23,0x5d,0x3b,0x2e,0x3b,0x48,0x4f,0x51,0x4f,0x3a,0x28,0x2d,0x38,0x3f,0x44,0x64,0x76,0x69,0x65,0x75,0x74,0x6e,0x6d,0x6e,0x6d,0x68,0x60},

{0x22,0xe,0x18,0x3e,0x3c,0x2b,0x1e,0x1a,0x2a,0x21,0x2d,0x66,0x44,0x44,0x52,0x60,0x6a,0x6e,0x72,0x5f,0x3e,0x2c,0x2d,0x6c,0x57,0x4b,0x31,0x28,0x30,0x43,0x5a,0x68,0x22,0x25,0x5a,0x39,0x2c,0x3b,0x46,0x46,0x47,0x46,0x35,0x26,0x26,0x2f,0x3b,0x4a,0x68,0x6e,0x63,0x68,0x78,0x74,0x6e,0x6a,0x6e,0x6c,0x62,0x59},

{0x18,0xf,0x1a,0x3e,0x31,0x25,0x1e,0x26,0x2b,0x1f,0x22,0x5b,0x66,0x56,0x4d,0x52,0x50,0x56,0x4f,0x61,0x46,0x26,0x19,0x2c,0x57,0x4b,0x35,0x26,0x2d,0x43,0x59,0x6c,0x31,0x24,0x51,0x3b,0x2e,0x36,0x3e,0x40,0x41,0x3c,0x2c,0x21,0x23,0x2a,0x3b,0x51,0x67,0x66,0x60,0x6f,0x76,0x6c,0x6d,0x6d,0x70,0x69,0x5c,0x51},

{0x12,0x15,0x20,0x36,0x24,0x28,0x21,0x26,0x2c,0x22,0x20,0x42,0x6a,0x56,0x44,0x47,0x9f,0x66,0x34,0x5b,0x5f,0x31,0x1c,0x24,0x24,0x2d,0x34,0x2c,0x2f,0x41,0x4f,0x63,0x42,0x20,0x47,0x41,0x32,0x2f,0x36,0x3f,0x44,0x36,0x24,0x1e,0x24,0x2b,0x3d,0x55,0x62,0x60,0x65,0x79,0x73,0x61,0x6a,0x74,0x70,0x68,0x58,0x4c}

};

