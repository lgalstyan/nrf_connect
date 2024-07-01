static const q15_t in_default_val[100] = {
    0xE62B, 0x1CF7, 0x3208, 0x37FC, 0x2781, 0x3AD3, 0x69CF, 0x5E5B,
    0x2BC7, 0xF39B, 0xFACD, 0xFC7A, 0xD180, 0xBC84, 0xAEE2, 0xDA97,
    0xD292, 0xD9FC, 0xAF9D, 0xCA17, 0xFAD5, 0x4342, 0x2821, 0x2EB8,
    0x3F63, 0x46A5, 0x4E09, 0x3C16, 0x1876, 0x1355, 0x04C3, 0x1530,
    0xD8FB, 0x95D8, 0x9DDB, 0xD93C, 0xDC86, 0xD476, 0xC63A, 0xCDC3,
    0x267F, 0x3926, 0x25C3, 0x31E3, 0x4759, 0x5D47, 0x690D, 0x3D75,
    0x12E4, 0xF69C, 0xF606, 0x0373, 0xCB95, 0x8000, 0xA910, 0xB61A,
    0xDDFF, 0xA016, 0xC5D5, 0xDF9E, 0x1FA5, 0x3811, 0x29D2, 0x061A,
    0x291F, 0x570A, 0x6886, 0x383D, 0x12A8, 0x15C2, 0xE5EE, 0xEADA,
    0xB11B, 0x9FC1, 0x9EDD, 0xBEE8, 0xC9B5, 0xB03B, 0xB88E, 0xE495,
    0x2595, 0x5D53, 0x2599, 0x295B, 0x4C34, 0x6936, 0x5B61, 0x15D5,
    0x07B1, 0x056F, 0x08EE, 0xF182, 0xD6CE, 0xABFD, 0xB1BC, 0xC994,
    0xEC29, 0xC002, 0xC69B, 0x168A
    };

static const q15_t in_default_coeff[18] = {
    0x00A4, 0x0000, 0xFF4F, 0x00A4, 0x37CF, 0xE614, 0x2000, 0x0000,
    0xCD0D, 0x2000, 0x37E6, 0xE1E4, 0x2000, 0x0000, 0xC003, 0x2000,
    0x3EA4, 0xE144
    };

static const q15_t ref_default[100] = {
    0xFF7C, 0x002E, 0x0092, 0x0195, 0x0324, 0x0618, 0x0A77, 0x0F3E,
    0x1487, 0x19BA, 0x1EB8, 0x219D, 0x2141, 0x1DE7, 0x169B, 0x0C5C,
    0xFE58, 0xEF0A, 0xDE9A, 0xD05E, 0xC538, 0xBF56, 0xBE37, 0xC44B,
    0xD056, 0xE104, 0xF4F7, 0x09C0, 0x1D29, 0x2DA1, 0x38BC, 0x3E46,
    0x3C2F, 0x3397, 0x2617, 0x14EA, 0x00F7, 0xED60, 0xDBD4, 0xCE0E,
    0xC652, 0xC375, 0xC67F, 0xCFAD, 0xDD6C, 0xEE73, 0x0148, 0x138E,
    0x242A, 0x314B, 0x39D4, 0x3D0E, 0x399C, 0x302B, 0x2306, 0x1120,
    0xFDB2, 0xE88B, 0xD68F, 0xC761, 0xBDD7, 0xBA29, 0xBD05, 0xC5FF,
    0xD530, 0xE847, 0xFD79, 0x1256, 0x25A3, 0x358B, 0x3F18, 0x4334,
    0x3F99, 0x363C, 0x2764, 0x150A, 0x007C, 0xEB9B, 0xD930, 0xCACC,
    0xC200, 0xBFE2, 0xC359, 0xCE50, 0xDEC4, 0xF2F7, 0x08D3, 0x1DD8,
    0x3119, 0x3FA3, 0x483F, 0x49DD, 0x44C7, 0x3912, 0x28C3, 0x151E,
    0x008B, 0xEBE5, 0xDAE7, 0xCF40
    };

