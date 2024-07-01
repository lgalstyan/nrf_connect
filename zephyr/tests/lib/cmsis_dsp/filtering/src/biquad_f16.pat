static const uint16_t in_default_val[100] = {
    0xb09e, 0x3816, 0x3626, 0x34c1, 0x3773, 0x39c3, 0x39a2, 0x39e7,
    0x31a7, 0xacbc, 0xa80f, 0xa1d4, 0xb003, 0xb9b3, 0xb6f4, 0xba09,
    0xb1b3, 0xb424, 0xb42c, 0xb70b, 0x2d56, 0x381e, 0x388f, 0x32c7,
    0x33d9, 0x3984, 0x3a38, 0x3708, 0xa596, 0x2cc8, 0xa5ea, 0x2989,
    0xb52a, 0xb972, 0xb7a0, 0xb6c1, 0xb2cf, 0xb84f, 0xb71c, 0xb485,
    0x352c, 0x376e, 0x381f, 0x3496, 0x2de2, 0x3a32, 0x3a68, 0x3820,
    0xacc8, 0xab2c, 0x3094, 0xaf66, 0xb411, 0xb969, 0xba0c, 0xb5e3,
    0xb41a, 0xb940, 0xb792, 0xb0af, 0x3632, 0x37ba, 0x35e0, 0x3619,
    0x3873, 0x38ee, 0x384f, 0x3712, 0xa660, 0x2a80, 0xab3a, 0xb061,
    0xb7fb, 0xbc00, 0xba5e, 0xb3b5, 0xb483, 0xb748, 0xb74c, 0x232e,
    0x33e5, 0x37bb, 0x36cc, 0x37ce, 0x37a3, 0x39cb, 0x3841, 0x358e,
    0x298b, 0x299d, 0x2c3a, 0xb173, 0xb78d, 0xb9e0, 0xb995, 0xb0ab,
    0xb33b, 0xb88e, 0xb85c, 0x2408
    };

static const uint16_t in_default_coeff[15] = {
    0x251f, 0xa588, 0x251f, 0x3efa, 0xba7b, 0x3c00, 0xbe5e, 0x3c00,
    0x3efd, 0xbb87, 0x3c00, 0xc000, 0x3c00, 0x3fd5, 0xbbaf
    };

static const uint16_t ref_default[100] = {
    0x99e9, 0x2015, 0x217a, 0x25a4, 0x298b, 0x2cae, 0x2eed, 0x30ed,
    0x323c, 0x3396, 0x3454, 0x3491, 0x346d, 0x3378, 0x3186, 0x2c88,
    0xa8ee, 0xb169, 0xb4b2, 0xb67d, 0xb7ac, 0xb81e, 0xb808, 0xb72a,
    0xb57b, 0xb267, 0xa97b, 0x2f51, 0x3416, 0x35f3, 0x3706, 0x375b,
    0x36ca, 0x357c, 0x335d, 0x2db8, 0xab22, 0xb26e, 0xb51a, 0xb686,
    0xb738, 0xb750, 0xb6ae, 0xb57f, 0xb3bb, 0xaf0a, 0x251d, 0x30b5,
    0x3419, 0x358d, 0x367b, 0x36b6, 0x3664, 0x3565, 0x33d9, 0x303e,
    0x16fa, 0xb067, 0xb424, 0xb5c0, 0xb6c9, 0xb739, 0xb6ef, 0xb5e4,
    0xb433, 0xb01d, 0x258f, 0x319b, 0x34f0, 0x36b8, 0x37c4, 0x3807,
    0x3777, 0x3609, 0x340e, 0x2eaf, 0xac05, 0xb319, 0xb5b2, 0xb72b,
    0xb7f4, 0xb7db, 0xb6f6, 0xb549, 0xb22a, 0xa7c9, 0x302b, 0x347e,
    0x366e, 0x37cc, 0x3836, 0x381d, 0x374a, 0x35b2, 0x3348, 0x2da3,
    0xabfb, 0xb280, 0xb516, 0xb656
    };

static const uint16_t in_rand_coeff[690] = {
    0x251f, 0x1c55, 0x251f, 0x1bd9, 0x86fc, 0x3c00, 0xb114, 0x3c00,
    0x24c4, 0x939e, 0x3c00, 0x3c9e, 0x3c00, 0xafbc, 0xa429, 0x3c00,
    0x3e23, 0x3c00, 0xb664, 0xab3b, 0x3c00, 0x3fff, 0x3c00, 0xb7c3,
    0xac1d, 0x3c00, 0xb779, 0x3c00, 0x39bf, 0xb025, 0x3c00, 0xb788,
    0x3c00, 0x3669, 0xb028, 0x251f, 0xa919, 0x251f, 0x1a24, 0x839b,
    0x3c00, 0x4000, 0x3c00, 0xa4a4, 0x88ba, 0x3c00, 0xbfa6, 0x3c00,
    0x346e, 0xa6fb, 0x3c00, 0x31f1, 0x3c00, 0x3381, 0xabf7, 0x3c00,
    0x374c, 0x3c00, 0xb448, 0xb107, 0x3c00, 0xba66, 0x3c00, 0x3633,
    0xb533, 0x3c00, 0x3f81, 0x3c00, 0xbcaa, 0xb60c, 0x251f, 0xa839,
    0x251f, 0x2faa, 0xa4f3, 0x3c00, 0x3cd4, 0x3c00, 0xa51b, 0xa61e,
    0x3c00, 0xbf61, 0x3c00, 0x3876, 0xacfa, 0x3c00, 0x3c0b, 0x3c00,
    0xa8e6, 0xad20, 0x3c00, 0x3872, 0x3c00, 0xa6c4, 0xb040, 0x3c00,
    0xbf80, 0x3c00, 0x3acb, 0xb1f5, 0x3c00, 0x3fbd, 0x3c00, 0xbd58,
    0xb725, 0x251f, 0x2813, 0x251f, 0xa9ea, 0x913d, 0x3c00, 0xbff6,
    0x3c00, 0x2927, 0x940e, 0x3c00, 0xbfe6, 0x3c00, 0x2b18, 0x9dc1,
    0x3c00, 0x3b88, 0x3c00, 0x2844, 0x9dcb, 0x3c00, 0xbfd9, 0x3c00,
    0x326a, 0xa700, 0x3c00, 0x3f9a, 0x3c00, 0xb5c4, 0xa829, 0x3c00,
    0x3f1e, 0x3c00, 0xb55c, 0xa8e4, 0x3c00, 0xb320, 0x3c00, 0x349a,
    0xaccc, 0x3c00, 0xbfb5, 0x3c00, 0x390c, 0xaf2c, 0x3c00, 0xb47c,
    0x3c00, 0x3677, 0xafa9, 0x3c00, 0x39c3, 0x3c00, 0xb280, 0xafcd,
    0x3c00, 0xbd46, 0x3c00, 0x36de, 0xb3f4, 0x3c00, 0x3848, 0x3c00,
    0xb4b7, 0xb55b, 0x3c00, 0xbe63, 0x3c00, 0x3b4e, 0xb5bb, 0x3c00,
    0xbf9b, 0x3c00, 0x3cc1, 0xb661, 0x3c00, 0xbfc2, 0x3c00, 0x3cfd,
    0xb68e, 0x251f, 0xa8fe, 0x251f, 0x234e, 0x9353, 0x3c00, 0xbfa4,
    0x3c00, 0xa820, 0x95c5, 0x3c00, 0xbda1, 0x3c00, 0xabf2, 0xa4fd,
    0x3c00, 0xbd1e, 0x3c00, 0x29bc, 0xa653, 0x3c00, 0x322e, 0x3c00,
    0xb0b5, 0xa712, 0x3c00, 0xbc1a, 0x3c00, 0x343e, 0xabe5, 0x3c00,
    0x37f4, 0x3c00, 0xb628, 0xaed3, 0x3c00, 0x3ae2, 0x3c00, 0xb4f3,
    0xb15a, 0x3c00, 0x3e11, 0x3c00, 0xbb28, 0xb271, 0x3c00, 0xae69,
    0x3c00, 0x2e06, 0xb2ca, 0x3c00, 0xbdb7, 0x3c00, 0x3ab3, 0xb407,
    0x3c00, 0x3ffa, 0x3c00, 0xbc1b, 0xb4dc, 0x3c00, 0x3eb1, 0x3c00,
    0xbc18, 0xb582, 0x3c00, 0x3fe5, 0x3c00, 0xbca0, 0xb583, 0x3c00,
    0x3d1b, 0x3c00, 0xba01, 0xb5a5, 0x3c00, 0xbe61, 0x3c00, 0x3c46,
    0xb6a9, 0x251f, 0xa571, 0x251f, 0x2dd5, 0x9fc6, 0x3c00, 0xbf22,
    0x3c00, 0x3383, 0xa316, 0x3c00, 0x31f7, 0x3c00, 0x1d99, 0xa445,
    0x3c00, 0x3df3, 0x3c00, 0xb498, 0xa569, 0x3c00, 0x3e04, 0x3c00,
    0xb467, 0xa713, 0x3c00, 0x3e69, 0x3c00, 0xb7c5, 0xac2c, 0x3c00,
    0xbe65, 0x3c00, 0x365d, 0xac70, 0x3c00, 0xba5d, 0x3c00, 0x32ca,
    0xac76, 0x3c00, 0x38c0, 0x3c00, 0xb1b5, 0xacfe, 0x3c00, 0xbf72,
    0x3c00, 0x3a82, 0xb1fa, 0x3c00, 0xbfdd, 0x3c00, 0x3aeb, 0xb200,
    0x3c00, 0x3bc2, 0x3c00, 0xb788, 0xb380, 0x3c00, 0x3d87, 0x3c00,
    0xb8e9, 0xb3dd, 0x3c00, 0xba05, 0x3c00, 0x347a, 0xb538, 0x3c00,
    0xbe31, 0x3c00, 0x3b72, 0xb66c, 0x3c00, 0x3ec9, 0x3c00, 0xbcfe,
    0xb73c, 0x251f, 0x28f0, 0x251f, 0xa163, 0x8249, 0x3c00, 0xb934,
    0x3c00, 0x9825, 0x8d0d, 0x3c00, 0x3fad, 0x3c00, 0xab06, 0x9602,
    0x3c00, 0xba25, 0x3c00, 0x2cb3, 0x96a5, 0x3c00, 0xb893, 0x3c00,
    0x64d, 0x9ff3, 0x3c00, 0xbfb0, 0x3c00, 0x32b9, 0xa1a6, 0x3c00,
    0x3c9f, 0x3c00, 0xb09d, 0xa5b7, 0x3c00, 0xba3a, 0x3c00, 0x3047,
    0xa6b0, 0x3c00, 0x3d9d, 0x3c00, 0xb516, 0xa888, 0x3c00, 0xbf4c,
    0x3c00, 0x344e, 0xa891, 0x3c00, 0xb0e9, 0x3c00, 0x8f9d, 0xa9ae,
    0x3c00, 0x3aaf, 0x3c00, 0xb230, 0xab24, 0x3c00, 0xa295, 0x3c00,
    0xacf4, 0xad23, 0x3c00, 0xbe80, 0x3c00, 0x371d, 0xb000, 0x3c00,
    0xbe1b, 0x3c00, 0x3859, 0xb0c5, 0x3c00, 0xbfdc, 0x3c00, 0x3a6f,
    0xb162, 0x3c00, 0x343a, 0x3c00, 0xb2e6, 0xb2bf, 0x3c00, 0x3594,
    0x3c00, 0xb117, 0xb3f2, 0x3c00, 0x3fd9, 0x3c00, 0xbc02, 0xb406,
    0x3c00, 0x3fff, 0x3c00, 0xbc2c, 0xb462, 0x3c00, 0xbbd6, 0x3c00,
    0x3979, 0xb52e, 0x3c00, 0x3f4a, 0x3c00, 0xbc29, 0xb577, 0x3c00,
    0x2ec0, 0x3c00, 0xabd0, 0xb6c2, 0x251f, 0xa8a9, 0x251f, 0xa157,
    0x8e76, 0x3c00, 0xbf37, 0x3c00, 0xabf2, 0x945b, 0x3c00, 0xbfdb,
    0x3c00, 0x3056, 0x9ce9, 0x3c00, 0x3d4c, 0x3c00, 0xb0b5, 0xa27e,
    0x3c00, 0x3c7b, 0x3c00, 0x2a19, 0xa76d, 0x3c00, 0xbee3, 0x3c00,
    0x340a, 0xa7f2, 0x3c00, 0x3e6f, 0x3c00, 0xb713, 0xac3c, 0x3c00,
    0x3e2c, 0x3c00, 0xb6d4, 0xad58, 0x3c00, 0xbfa3, 0x3c00, 0x3871,
    0xad77, 0x3c00, 0x3c76, 0x3c00, 0xb61d, 0xafa3, 0x3c00, 0x3acd,
    0x3c00, 0xb437, 0xb010, 0x3c00, 0x3a5a, 0x3c00, 0xa0e2, 0xb15f,
    0x3c00, 0x3ed1, 0x3c00, 0xbaf0, 0xb2a2, 0x3c00, 0x3ef1, 0x3c00,
    0xbaea, 0xb3f6, 0x3c00, 0xbe27, 0x3c00, 0x3949, 0xb3f9, 0x3c00,
    0x3f01, 0x3c00, 0xbc7b, 0xb504, 0x3c00, 0xbfdd, 0x3c00, 0x3c88,
    0xb530, 0x3c00, 0x38b6, 0x3c00, 0x25c8, 0xb594, 0x3c00, 0x32a7,
    0x3c00, 0xb339, 0xb59b, 0x3c00, 0x3f08, 0x3c00, 0xbcff, 0xb659,
    0x3c00, 0x3db0, 0x3c00, 0xbbe0, 0xb785, 0x3c00, 0xbec3, 0x3c00,
    0x3ca7, 0xb79c, 0x3c00, 0xba0f, 0x3c00, 0x3953, 0xb7b6, 0x251f,
    0xa8dd, 0x251f, 0xaa4b, 0x919f, 0x3c00, 0x39a3, 0x3c00, 0xaa9f,
    0xa275, 0x3c00, 0xbd4f, 0x3c00, 0x324f, 0xa537, 0x3c00, 0x3964,
    0x3c00, 0x285f, 0xa58c, 0x3c00, 0x3a79, 0x3c00, 0xb524, 0xa81d,
    0x3c00, 0xbac4, 0x3c00, 0x2898, 0xa825, 0x3c00, 0xbf83, 0x3c00,
    0x37a3, 0xac1f, 0x3c00, 0x37bb, 0x3c00, 0xae2b, 0xaca7, 0x3c00,
    0x3df6, 0x3c00, 0xb58d, 0xad5f, 0x3c00, 0xb893, 0x3c00, 0x3087,
    0xaebf, 0x3c00, 0xae4b, 0x3c00, 0x2e99, 0xaf71, 0x3c00, 0xb63d,
    0x3c00, 0x31b4, 0xb135, 0x3c00, 0x3f3a, 0x3c00, 0xba3a, 0xb1a7,
    0x3c00, 0x3f84, 0x3c00, 0xbaee, 0xb247, 0x3c00, 0xc000, 0x3c00,
    0x3c27, 0xb453, 0x3c00, 0xbf1f, 0x3c00, 0x3baa, 0xb49a, 0x3c00,
    0xbf4d, 0x3c00, 0x3ca4, 0xb650, 0x3c00, 0xbfee, 0x3c00, 0x3d0e,
    0xb673, 0x3c00, 0x3d5d, 0x3c00, 0xb9b0, 0xb686, 0x3c00, 0xbda3,
    0x3c00, 0x3c2b, 0xb6c5, 0x3c00, 0xb919, 0x3c00, 0x3734, 0xb72a,
    0x3c00, 0xbcc3, 0x3c00, 0x3ab6, 0xb771, 0x3c00, 0x3015, 0x3c00,
    0xab9b, 0xb785
    };

static const uint16_t in_rand_config[18] = {
    0x0007, 0x0007, 0x0007, 0x0010, 0x0007, 0x0017, 0x0010, 0x0007,
    0x0010, 0x0010, 0x0010, 0x0017, 0x0017, 0x0007, 0x0017, 0x0010,
    0x0017, 0x0017
    };

static const uint16_t in_rand_mono_val[138] = {
    0x2dcf, 0x34c3, 0x35ec, 0xbaee, 0xb425, 0x3c00, 0xb285, 0x368f,
    0x330d, 0x35a8, 0x2d54, 0x3350, 0xb59c, 0xbbc9, 0xb6ea, 0x3c00,
    0x34f5, 0x34f7, 0xac89, 0xaa9c, 0xb378, 0xbb94, 0x39e2, 0x2911,
    0x3998, 0x343f, 0x3720, 0xb84c, 0x3ae4, 0x3875, 0x339c, 0xb527,
    0xb14c, 0xb44c, 0x9e5b, 0xbc00, 0xa30a, 0xba32, 0x3514, 0xb828,
    0xae71, 0x3b84, 0xb58c, 0x361a, 0x329e, 0xb81c, 0x34a6, 0x1dff,
    0xb794, 0xb997, 0x3c00, 0xb5ea, 0x2736, 0x35b9, 0xb544, 0xbc00,
    0x2c50, 0x3228, 0x3532, 0xb69e, 0x36aa, 0x38ac, 0xa6b7, 0x2949,
    0x3b16, 0x30b1, 0xb393, 0xb8d4, 0xb4d3, 0x2f09, 0x2002, 0x2879,
    0x3ace, 0xba11, 0xb6fe, 0xb562, 0xb721, 0xb281, 0x3967, 0x2ecb,
    0x2de4, 0x3bf5, 0xa9d4, 0xb5bc, 0xb231, 0xab9d, 0xb658, 0x388f,
    0xbbfc, 0x3a36, 0x3241, 0xbc00, 0x3350, 0x2475, 0x3c00, 0x34c5,
    0xb8d3, 0x3729, 0xb5a8, 0x3b90, 0xb58e, 0xb4c3, 0x1d69, 0xb571,
    0x38e6, 0xb8c4, 0xafc5, 0xb17f, 0x2a61, 0xa7be, 0x369f, 0xbc00,
    0x37ce, 0xb960, 0x3547, 0x3993, 0xae18, 0xb29a, 0xb110, 0x348f,
    0xafbd, 0xb33f, 0xafd4, 0xbc00, 0xac94, 0xb547, 0xb3ce, 0xaceb,
    0xb04c, 0x2e2a, 0x3986, 0xaef0, 0x2cc7, 0x3638, 0xb57c, 0x2654,
    0x36ca, 0x337a
    };

static const uint16_t ref_rand_mono[138] = {
    0x176f, 0x22b5, 0x2a76, 0x2f83, 0x32cf, 0x3517, 0x3640, 0x2033,
    0x9697, 0x9a27, 0x99cf, 0xa22e, 0x9a8f, 0xa2c2, 0x23a0, 0x2a67,
    0xc9b, 0xc96, 0xa76d, 0xabd2, 0x2612, 0xa44c, 0x2858, 0x127c,
    0x22f0, 0x99cd, 0x9807, 0xa8e5, 0x28bd, 0x26be, 0x283a, 0xacb6,
    0xa845, 0x27da, 0x2d9c, 0xa47e, 0xa9b4, 0xac28, 0x2df8, 0xa15b,
    0x25f8, 0xabe8, 0x2708, 0x1c95, 0xa1c6, 0xa36d, 0x1df3, 0xa51b,
    0x2021, 0x24b1, 0x2ad5, 0xb089, 0x2bda, 0x1f53, 0xa8aa, 0x2cb1,
    0xacc4, 0x25ba, 0x2b24, 0xb0e2, 0x3456, 0xb5e0, 0x365d, 0xb5d7,
    0x3484, 0xb0b3, 0xa1d6, 0x310f, 0xb4cf, 0x1881, 0x9b39, 0x1d3e,
    0x2054, 0xa71b, 0x27c4, 0xaad0, 0x2f23, 0xb1e2, 0x341b, 0xb598,
    0x379c, 0xb8df, 0x39e7, 0xbb2f, 0x3c33, 0xbc91, 0x3ce2, 0xbd2e,
    0x3d23, 0xbcbf, 0x3c42, 0xbb52, 0x1cae, 0x904e, 0x276e, 0x2181,
    0x2646, 0x2cee, 0xa8ef, 0x24d7, 0xa037, 0xaad9, 0xadbf, 0x31bf,
    0x3433, 0x9e83, 0xbaa4, 0xb505, 0x3aa3, 0x3eb6, 0xb9c0, 0xc07b,
    0xbd71, 0x41e8, 0x413f, 0x2323, 0xab2d, 0x3098, 0xb4bd, 0x3825,
    0xba7e, 0x3ca8, 0xbe3b, 0x3fdd, 0xc0b7, 0x4163, 0xc1e0, 0x4229,
    0xc242, 0x4238, 0xc219, 0x41e0, 0xc17f, 0x40de, 0xbfe5, 0x3d7e,
    0xb94e, 0xae1c
    };

static const uint16_t in_rand_stereo_val[276] = {
    0x2dcf, 0xb9ab, 0x34c3, 0xb470, 0x35ec, 0x3602, 0xbaee, 0xb8f5,
    0xb425, 0xb5b1, 0x3c00, 0xb84e, 0xb285, 0xbc00, 0x368f, 0x3287,
    0x330d, 0x3673, 0x35a8, 0xb2b4, 0x2d54, 0x3643, 0x3350, 0x2d95,
    0xb59c, 0xa864, 0xbbc9, 0xb8e9, 0xb6ea, 0x3af8, 0x3c00, 0x39b7,
    0x34f5, 0xb4f4, 0x34f7, 0xba75, 0xac89, 0xb81d, 0xaa9c, 0xb64f,
    0xb378, 0x3c00, 0xbb94, 0xb39e, 0x39e2, 0xb47e, 0x2911, 0x35a9,
    0x3998, 0x394f, 0x343f, 0xb313, 0x3720, 0x3a55, 0xb84c, 0x2d15,
    0x3ae4, 0x34d0, 0x3875, 0xb8a9, 0x339c, 0xb7be, 0xb527, 0xbc00,
    0xb14c, 0x3aa9, 0xb44c, 0xbbab, 0x9e5b, 0xb750, 0xbc00, 0x2c25,
    0xa30a, 0xb66b, 0xba32, 0x3917, 0x3514, 0x3924, 0xb828, 0xb908,
    0xae71, 0x36da, 0x3b84, 0xb659, 0xb58c, 0xb986, 0x361a, 0x24db,
    0x329e, 0x3272, 0xb81c, 0x2a85, 0x34a6, 0x3778, 0x1dff, 0x3818,
    0xb794, 0x2f1c, 0xb997, 0xbc00, 0x3c00, 0x34ff, 0xb5ea, 0x3962,
    0x2736, 0xb49b, 0x35b9, 0xb637, 0xb544, 0xb78f, 0xbc00, 0x3449,
    0x2c50, 0xb2b6, 0x3228, 0xb312, 0x3532, 0x36ca, 0xb69e, 0x38cc,
    0x36aa, 0x344d, 0x38ac, 0xb551, 0xa6b7, 0xb824, 0x2949, 0x35c1,
    0x3b16, 0xbc00, 0x30b1, 0xb8c0, 0xb393, 0xb97d, 0xb8d4, 0x35d8,
    0xb4d3, 0x3401, 0x2f09, 0xb76b, 0x2002, 0xb8df, 0x2879, 0x36bb,
    0x3ace, 0x30b8, 0xba11, 0xb8c6, 0xb6fe, 0xb5ec, 0xb562, 0x39dd,
    0xb721, 0xb842, 0xb281, 0xb5f9, 0x3967, 0x364f, 0x2ecb, 0x3b69,
    0x2de4, 0xb261, 0x3bf5, 0x3919, 0xa9d4, 0x38a6, 0xb5bc, 0x3c00,
    0xb231, 0x2ceb, 0xab9d, 0x357d, 0xb658, 0x3496, 0x388f, 0x3717,
    0xbbfc, 0xb8aa, 0x3a36, 0x3834, 0x3241, 0xb9c8, 0xbc00, 0xae78,
    0x3350, 0x3c00, 0x2475, 0xac93, 0x3c00, 0x341e, 0x34c5, 0xb200,
    0xb8d3, 0xb85f, 0x3729, 0xbacf, 0xb5a8, 0xb9f4, 0x3b90, 0xb4df,
    0xb58e, 0x376c, 0xb4c3, 0xb875, 0x1d69, 0x327d, 0xb571, 0xb3b1,
    0x38e6, 0xb5c6, 0xb8c4, 0xb84b, 0xafc5, 0x39a6, 0xb17f, 0x37f3,
    0x2a61, 0x3b84, 0xa7be, 0xb296, 0x369f, 0x3bfc, 0xbc00, 0x3c00,
    0x37ce, 0x28de, 0xb960, 0x33d4, 0x3547, 0xb75f, 0x3993, 0x3602,
    0xae18, 0xae20, 0xb29a, 0x2f48, 0xb110, 0xa51c, 0x348f, 0xb1bb,
    0xafbd, 0xac9b, 0xb33f, 0xb13e, 0xafd4, 0xb582, 0xbc00, 0xb4b6,
    0xac94, 0x2b88, 0xb547, 0xb792, 0xb3ce, 0xb66f, 0xaceb, 0xb15d,
    0xb04c, 0x310c, 0x2e2a, 0x3716, 0x3986, 0x3c00, 0xaef0, 0x2820,
    0x2cc7, 0xafea, 0x3638, 0x3383, 0xb57c, 0x28a1, 0x2654, 0xb30b,
    0x36ca, 0x2c9d, 0x337a, 0xb40c
    };

static const uint16_t ref_rand_stereo[276] = {
    0x176f, 0xa342, 0x22b5, 0xabdb, 0x2a76, 0xb15c, 0x2f83, 0xb5d5,
    0x32cf, 0xb93f, 0x3517, 0xbc24, 0x3640, 0xbdee, 0x2033, 0x1c2d,
    0x9697, 0x1d31, 0x9a27, 0xa2ea, 0x99cf, 0x1e7e, 0xa22e, 0x9856,
    0x9a8f, 0xa44f, 0xa2c2, 0x2231, 0x23a0, 0x2307, 0x2a67, 0x220b,
    0xc9b, 0xa0cc, 0xc96, 0xa5e1, 0xa76d, 0xa5d6, 0xabd2, 0x1ef0,
    0x2612, 0x2c43, 0xa44c, 0xa457, 0x2858, 0xa57b, 0x127c, 0x1f3e,
    0x22f0, 0x20ca, 0x99cd, 0xa3c6, 0x9807, 0x1463, 0xa8e5, 0xa290,
    0x28bd, 0x291a, 0x26be, 0xa61d, 0x283a, 0x1044, 0xacb6, 0xa6c8,
    0xa845, 0x2c41, 0x27da, 0xa277, 0x2d9c, 0xa479, 0xa47e, 0xacc3,
    0xa9b4, 0x2b15, 0xac28, 0x2b28, 0x2df8, 0x25fa, 0xa15b, 0xae0a,
    0x25f8, 0xa763, 0xabe8, 0xef9, 0x2708, 0x2e9d, 0x1c95, 0xa899,
    0xa1c6, 0x224c, 0xa36d, 0xac53, 0x1df3, 0x20c8, 0xa51b, 0xa5a2,
    0x2021, 0x9c67, 0x24b1, 0x1988, 0x2ad5, 0x2ea7, 0xb089, 0xad4c,
    0x2bda, 0xacb3, 0x1f53, 0x9ff4, 0xa8aa, 0x25e1, 0x2cb1, 0xa6d3,
    0xacc4, 0x9e77, 0x25ba, 0x2c30, 0x2b24, 0xaf66, 0xb0e2, 0x306c,
    0x3456, 0xb03a, 0xb5e0, 0x2deb, 0x365d, 0xa7b1, 0xb5d7, 0xa322,
    0x3484, 0x1ba7, 0xb0b3, 0x295d, 0xa1d6, 0xaf16, 0x310f, 0x324e,
    0xb4cf, 0xb483, 0x1881, 0xa0bf, 0x9b39, 0x1adf, 0x1d3e, 0x20a3,
    0x2054, 0x9caa, 0xa71b, 0xa4f1, 0x27c4, 0x9c42, 0xaad0, 0x2a53,
    0x2f23, 0xac74, 0xb1e2, 0x2b07, 0x341b, 0xaf20, 0xb598, 0x3352,
    0x379c, 0xb4ec, 0xb8df, 0x35c4, 0x39e7, 0xb7ec, 0xbb2f, 0x3998,
    0x3c33, 0xbad5, 0xbc91, 0x3c05, 0x3ce2, 0xbcdf, 0xbd2e, 0x3df7,
    0x3d23, 0xbec5, 0xbcbf, 0x3f99, 0x3c42, 0xc04f, 0xbb52, 0x40d7,
    0x1cae, 0x251f, 0x904e, 0x9d61, 0x276e, 0x29c8, 0x2181, 0x26ef,
    0x2646, 0xa333, 0x2cee, 0x2ca6, 0xa8ef, 0xacd2, 0x24d7, 0x9e3c,
    0xa037, 0x20f7, 0xaad9, 0x1b8f, 0xadbf, 0x2418, 0x31bf, 0xac9e,
    0x3433, 0x26a0, 0x9e83, 0xa143, 0xbaa4, 0x3327, 0xb505, 0xb1b8,
    0x3aa3, 0x27c5, 0x3eb6, 0xb85b, 0xb9c0, 0x383c, 0xc07b, 0xa811,
    0xbd71, 0x3cdb, 0x41e8, 0xbdce, 0x413f, 0xb16e, 0x2323, 0x1fb1,
    0xab2d, 0xa7f6, 0x3098, 0x2d75, 0xb4bd, 0xb1e9, 0x3825, 0x354d,
    0xba7e, 0xb831, 0x3ca8, 0x39f4, 0xbe3b, 0xbbcf, 0x3fdd, 0x3cd3,
    0xc0b7, 0xbdb0, 0x4163, 0x3e7a, 0xc1e0, 0xbf2a, 0x4229, 0x3fb6,
    0xc242, 0xc00c, 0x4238, 0x4029, 0xc219, 0xc02e, 0x41e0, 0x4017,
    0xc17f, 0xbfb9, 0x40de, 0x3ed8, 0xbfe5, 0xbd83, 0x3d7e, 0x3b76,
    0xb94e, 0xb649, 0xae1c, 0xb251
    };

