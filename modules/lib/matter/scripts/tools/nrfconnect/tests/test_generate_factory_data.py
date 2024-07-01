#!/usr/bin/env python3
#
#    Copyright (c) 2022 Project CHIP Authors
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#

import base64
import json
import os
import subprocess
import tempfile
import unittest
from os.path import exists

TOOLS_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))

DAC_DER_KEY = bytes([0x30, 0x77, 0x02, 0x01, 0x01, 0x04, 0x20, 0xbf, 0x26, 0xd5, 0xd2, 0x25,
                     0xeb, 0x6b, 0x09, 0x6d, 0xd5, 0xa6, 0xb9, 0x03, 0x04, 0x8e, 0xf2, 0xd7,
                     0x6e, 0xf2, 0xe8, 0x56, 0x25, 0x39, 0x0b, 0xd5, 0x70, 0xb2, 0xf1, 0x65,
                     0x99, 0x30, 0xeb, 0xa0, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
                     0x03, 0x01, 0x07, 0xa1, 0x44, 0x03, 0x42, 0x00, 0x04, 0x48, 0x36, 0x32,
                     0x85, 0x68, 0x70, 0x00, 0x9e, 0xd6, 0x8e, 0x78, 0xc0, 0xd9, 0x4b, 0xe7,
                     0xd9, 0xb5, 0x97, 0xb7, 0x88, 0x1d, 0xfb, 0x96, 0x00, 0xbb, 0x47, 0x1d,
                     0x8b, 0x70, 0xbb, 0xce, 0x1d, 0xf4, 0x47, 0xa7, 0x93, 0x60, 0x2e, 0x14,
                     0xde, 0x07, 0xdb, 0x80, 0xef, 0x75, 0xd8, 0x6c, 0x55, 0x6c, 0x7a, 0xc4,
                     0xb4, 0x06, 0x0d, 0x50, 0xe1, 0x0f, 0xe2, 0x26, 0x06, 0xb4, 0xdd, 0x1b,
                     0x4f])

DAC_RAW_KEY = bytes([0xbf, 0x26, 0xd5, 0xd2, 0x25, 0xeb, 0x6b, 0x09, 0x6d, 0xd5, 0xa6, 0xb9,
                     0x03, 0x04, 0x8e, 0xf2, 0xd7, 0x6e, 0xf2, 0xe8, 0x56, 0x25, 0x39, 0x0b,
                     0xd5, 0x70, 0xb2, 0xf1, 0x65, 0x99, 0x30, 0xeb])

DAC_DER_CERT = bytes([0x30, 0x82, 0x01, 0xe8, 0x30, 0x82, 0x01, 0x8e, 0xa0, 0x03, 0x02, 0x01,
                      0x02, 0x02, 0x08, 0x49, 0x2e, 0x20, 0xdb, 0x59, 0x76, 0xa8, 0x90, 0x30,
                      0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x30,
                      0x3e, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x1d,
                      0x4e, 0x6f, 0x72, 0x64, 0x69, 0x63, 0x20, 0x53, 0x65, 0x6d, 0x69, 0x63,
                      0x6f, 0x6e, 0x64, 0x75, 0x63, 0x74, 0x6f, 0x72, 0x20, 0x41, 0x53, 0x41,
                      0x5f, 0x4c, 0x6f, 0x63, 0x6b, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b,
                      0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x31,
                      0x32, 0x37, 0x46, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x32, 0x30, 0x37, 0x31,
                      0x39, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x17, 0x0d, 0x34, 0x39,
                      0x31, 0x32, 0x30, 0x33, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5a, 0x30,
                      0x54, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x1d,
                      0x4e, 0x6f, 0x72, 0x64, 0x69, 0x63, 0x20, 0x53, 0x65, 0x6d, 0x69, 0x63,
                      0x6f, 0x6e, 0x64, 0x75, 0x63, 0x74, 0x6f, 0x72, 0x20, 0x41, 0x53, 0x41,
                      0x5f, 0x4c, 0x6f, 0x63, 0x6b, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b,
                      0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x31,
                      0x32, 0x37, 0x46, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b, 0x06, 0x01,
                      0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x02, 0x0c, 0x04, 0x41, 0x42, 0x43,
                      0x44, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d,
                      0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07,
                      0x03, 0x42, 0x00, 0x04, 0x48, 0x36, 0x32, 0x85, 0x68, 0x70, 0x00, 0x9e,
                      0xd6, 0x8e, 0x78, 0xc0, 0xd9, 0x4b, 0xe7, 0xd9, 0xb5, 0x97, 0xb7, 0x88,
                      0x1d, 0xfb, 0x96, 0x00, 0xbb, 0x47, 0x1d, 0x8b, 0x70, 0xbb, 0xce, 0x1d,
                      0xf4, 0x47, 0xa7, 0x93, 0x60, 0x2e, 0x14, 0xde, 0x07, 0xdb, 0x80, 0xef,
                      0x75, 0xd8, 0x6c, 0x55, 0x6c, 0x7a, 0xc4, 0xb4, 0x06, 0x0d, 0x50, 0xe1,
                      0x0f, 0xe2, 0x26, 0x06, 0xb4, 0xdd, 0x1b, 0x4f, 0xa3, 0x60, 0x30, 0x5e,
                      0x30, 0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff, 0x04, 0x02,
                      0x30, 0x00, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff,
                      0x04, 0x04, 0x03, 0x02, 0x07, 0x80, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d,
                      0x0e, 0x04, 0x16, 0x04, 0x14, 0xbc, 0x6a, 0xa5, 0x79, 0x3c, 0x51, 0xa7,
                      0x60, 0x18, 0x38, 0x66, 0x4b, 0x26, 0xa7, 0xd3, 0xec, 0x25, 0x87, 0x46,
                      0x18, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16,
                      0x80, 0x14, 0x4b, 0x5b, 0xd0, 0x91, 0x60, 0xa3, 0x0e, 0xac, 0x2f, 0x94,
                      0xa4, 0x82, 0x6b, 0xd7, 0x6e, 0x96, 0x39, 0xca, 0xd3, 0xb3, 0x30, 0x0a,
                      0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x48,
                      0x00, 0x30, 0x45, 0x02, 0x20, 0x38, 0xf4, 0x2f, 0xd7, 0x06, 0x9a, 0xbc,
                      0xfc, 0x83, 0x2b, 0x74, 0xe1, 0xb6, 0x11, 0xb0, 0x2f, 0x72, 0xfd, 0xc2,
                      0x75, 0x59, 0xdd, 0x7d, 0x04, 0x9c, 0x81, 0x37, 0x01, 0x74, 0x98, 0x77,
                      0x22, 0x02, 0x21, 0x00, 0xb8, 0x9d, 0x63, 0x5b, 0xe2, 0xd3, 0x03, 0xe3,
                      0xbc, 0xcb, 0x7e, 0x95, 0x18, 0xc2, 0xbb, 0x0c, 0x1d, 0xff, 0x3b, 0x3d,
                      0x37, 0x41, 0x72, 0x2a, 0xd3, 0x4d, 0x38, 0x5c, 0x64, 0x2b, 0xc1, 0x46])

PAI_DER_CERT = bytes([0x30, 0x82, 0x01, 0xb4, 0x30, 0x82, 0x01, 0x5a, 0xa0, 0x03, 0x02, 0x01,
                      0x02, 0x02, 0x08, 0x09, 0x10, 0x34, 0x50, 0x40, 0x83, 0x6a, 0x05, 0x30,
                      0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x30,
                      0x1a, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x0f,
                      0x4d, 0x61, 0x74, 0x74, 0x65, 0x72, 0x20, 0x54, 0x65, 0x73, 0x74, 0x20,
                      0x50, 0x41, 0x41, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x32, 0x30, 0x37, 0x31,
                      0x39, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x5a, 0x17, 0x0d, 0x34, 0x39,
                      0x31, 0x32, 0x30, 0x33, 0x32, 0x33, 0x35, 0x39, 0x35, 0x39, 0x5a, 0x30,
                      0x3e, 0x31, 0x26, 0x30, 0x24, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x1d,
                      0x4e, 0x6f, 0x72, 0x64, 0x69, 0x63, 0x20, 0x53, 0x65, 0x6d, 0x69, 0x63,
                      0x6f, 0x6e, 0x64, 0x75, 0x63, 0x74, 0x6f, 0x72, 0x20, 0x41, 0x53, 0x41,
                      0x5f, 0x4c, 0x6f, 0x63, 0x6b, 0x31, 0x14, 0x30, 0x12, 0x06, 0x0a, 0x2b,
                      0x06, 0x01, 0x04, 0x01, 0x82, 0xa2, 0x7c, 0x02, 0x01, 0x0c, 0x04, 0x31,
                      0x32, 0x37, 0x46, 0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48,
                      0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03,
                      0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xd7, 0x0c, 0x57, 0xcd, 0xac, 0x0c,
                      0x8b, 0x0b, 0x25, 0xfc, 0x64, 0x70, 0xa4, 0x2f, 0xb3, 0xf1, 0x37, 0xf7,
                      0x5f, 0x65, 0x2c, 0xd0, 0xb2, 0x15, 0xf1, 0xfe, 0x13, 0x53, 0x52, 0x3f,
                      0x59, 0x81, 0xd2, 0x3d, 0xf7, 0xf1, 0x59, 0x88, 0xbd, 0xce, 0xe4, 0x3a,
                      0x20, 0x84, 0xe6, 0x1d, 0xe7, 0x3c, 0x83, 0xfb, 0xc4, 0x86, 0x5e, 0x5c,
                      0xb8, 0x45, 0x5e, 0x2b, 0xa3, 0x70, 0x08, 0xfb, 0x05, 0x1b, 0xa3, 0x66,
                      0x30, 0x64, 0x30, 0x12, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x01, 0x01, 0xff,
                      0x04, 0x08, 0x30, 0x06, 0x01, 0x01, 0xff, 0x02, 0x01, 0x01, 0x30, 0x0e,
                      0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02,
                      0x01, 0x06, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04,
                      0x14, 0x4b, 0x5b, 0xd0, 0x91, 0x60, 0xa3, 0x0e, 0xac, 0x2f, 0x94, 0xa4,
                      0x82, 0x6b, 0xd7, 0x6e, 0x96, 0x39, 0xca, 0xd3, 0xb3, 0x30, 0x1f, 0x06,
                      0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0x78, 0x5c,
                      0xe7, 0x05, 0xb8, 0x6b, 0x8f, 0x4e, 0x6f, 0xc7, 0x93, 0xaa, 0x60, 0xcb,
                      0x43, 0xea, 0x69, 0x68, 0x82, 0xd5, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86,
                      0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02,
                      0x20, 0x60, 0x22, 0xfc, 0xeb, 0x83, 0x4c, 0x6f, 0xb1, 0x4b, 0xa0, 0x72,
                      0x3b, 0xcd, 0x8f, 0x68, 0x51, 0x5b, 0x29, 0x04, 0xa9, 0x6f, 0x5d, 0xb7,
                      0xec, 0xe1, 0xf2, 0x30, 0x93, 0xd7, 0x49, 0x7e, 0xee, 0x02, 0x21, 0x00,
                      0xdf, 0xe7, 0x72, 0xe6, 0xdc, 0x1a, 0xad, 0xf0, 0x2c, 0x58, 0x7a, 0x0d,
                      0xde, 0x3d, 0xc0, 0x14, 0x3a, 0x97, 0xe1, 0x35, 0x38, 0xf7, 0xff, 0x76,
                      0x05, 0x5e, 0xbf, 0x27, 0x90, 0x6f, 0x50, 0x0f])

TEST_MANUAL_CODE = "Manualcode : 35442608082"

TEST_QR_CODE = "QRCode : MT:KAYA3EYF15ND8B1OA00"


def write_file(path: str, content: bytes) -> None:
    with open(path, 'wb') as f:
        f.write(content)


def read_json(path: str) -> object:
    with open(path) as f:
        return json.load(f)


def bytes_to_json(content: bytes) -> str:
    return f'hex:{content.hex()}'


def base64_to_json(content: str) -> str:
    return bytes_to_json(base64.b64decode(content))


class TestGenerateFactoryData(unittest.TestCase):

    def test_generate_factory_data_all_specified(self):
        with tempfile.TemporaryDirectory() as outdir:
            write_file(os.path.join(outdir, 'DAC_key.der'), DAC_DER_KEY)
            write_file(os.path.join(outdir, 'DAC_cert.der'), DAC_DER_CERT)
            write_file(os.path.join(outdir, 'PAI_cert.der'), PAI_DER_CERT)

            subprocess.check_call(['python3', os.path.join(TOOLS_DIR, 'generate_nrfconnect_chip_factory_data.py'),
                                   '-s', os.path.join(TOOLS_DIR, 'nrfconnect_factory_data.schema'),
                                   '--include_passcode',
                                   '--sn', 'SN:12345678',
                                   '--vendor_id', '0x127F',
                                   '--product_id', '0xABCD',
                                   '--vendor_name', 'Nordic Semiconductor ASA',
                                   '--product_name', 'Lock Gen2',
                                   '--part_number', 'PCA10056',
                                   '--product_url', 'https://example.com/lock',
                                   '--product_label', 'Lock',
                                   '--date', '2022-07-20',
                                   '--hw_ver', '101',
                                   '--hw_ver_str', 'v1.1',
                                   '--dac_key', os.path.join(outdir, 'DAC_key.der'),
                                   '--dac_cert', os.path.join(outdir, 'DAC_cert.der'),
                                   '--pai_cert', os.path.join(outdir, 'PAI_cert.der'),
                                   '--spake2_it', '2000',
                                   '--spake2_salt', 'U1BBS0UyUCBLZXkgU2FsdA==',
                                   '--passcode', '13243546',
                                   '--spake2_verifier', ('WN0SgEXLfUN19BbJqp6qn4pS69EtdNLReIMZwv/CIM0ECMP7ytiAJ7txIYJ0Ovlha/'
                                                         'rQ3E+88mj3qaqqnviMaZzG+OyXEdSocDIT9ZhmkTCgWwERaHz4Vdh3G37RT6kqbw=='),
                                   '--discriminator', '0xFED',
                                   '--rd_uid', '91a9c12a7c80700a31ddcfa7fce63e44',
                                   '--enable_key', '00112233445566778899aabbccddeeff',
                                   '--product_color', 'red',
                                   '--product_finish', 'satin',
                                   '--user', '{"name": "product_name", "version": 123, "revision": "0x123"}',
                                   '-o', os.path.join(outdir, 'fd.json')
                                   ])

            factory_data = read_json(os.path.join(outdir, 'fd.json'))

            self.assertEqual(factory_data.get('version'), 1)
            self.assertEqual(factory_data.get('sn'), 'SN:12345678')
            self.assertEqual(factory_data.get('vendor_id'), 0x127F)
            self.assertEqual(factory_data.get('product_id'), 0xABCD)
            self.assertEqual(factory_data.get('vendor_name'), 'Nordic Semiconductor ASA')
            self.assertEqual(factory_data.get('product_name'), 'Lock Gen2')
            self.assertEqual(factory_data.get('part_number'), 'PCA10056')
            self.assertEqual(factory_data.get('product_url'), 'https://example.com/lock')
            self.assertEqual(factory_data.get('product_label'), 'Lock')
            self.assertEqual(factory_data.get('date'), '2022-07-20')
            self.assertEqual(factory_data.get('hw_ver'), 101)
            self.assertEqual(factory_data.get('hw_ver_str'), 'v1.1')
            self.assertEqual(factory_data.get('dac_key'), bytes_to_json(DAC_RAW_KEY))
            self.assertEqual(factory_data.get('dac_cert'), bytes_to_json(DAC_DER_CERT))
            self.assertEqual(factory_data.get('pai_cert'), bytes_to_json(PAI_DER_CERT))
            self.assertEqual(factory_data.get('spake2_it'), 2000)
            self.assertEqual(factory_data.get('spake2_salt'), base64_to_json('U1BBS0UyUCBLZXkgU2FsdA=='))
            self.assertEqual(factory_data.get('spake2_verifier'), base64_to_json(
                'WN0SgEXLfUN19BbJqp6qn4pS69EtdNLReIMZwv/CIM0ECMP7ytiAJ7txIYJ0Ovlha/'
                'rQ3E+88mj3qaqqnviMaZzG+OyXEdSocDIT9ZhmkTCgWwERaHz4Vdh3G37RT6kqbw=='))
            self.assertEqual(factory_data.get('discriminator'), 0xFED)
            self.assertEqual(factory_data.get('passcode'), 13243546)
            self.assertEqual(factory_data.get('rd_uid'), 'hex:91a9c12a7c80700a31ddcfa7fce63e44')
            self.assertEqual(factory_data.get('enable_key'), 'hex:00112233445566778899aabbccddeeff')
            self.assertEqual(factory_data.get('product_finish'), 2)
            self.assertEqual(factory_data.get('primary_color'), 11)
            self.assertEqual(factory_data.get('user'), {'name': 'product_name', 'version': 123, 'revision': '0x123'})

            subprocess.check_call(['python3', os.path.join(TOOLS_DIR, 'nrfconnect_generate_partition.py'),
                                   '-i', os.path.join(outdir, 'fd.json'),
                                   '-o', os.path.join(outdir, 'fd'),
                                   '--offset', "0xfb000",
                                   '--size', "0x1000",
                                   '--raw'
                                   ])

    def test_generate_spake2p_verifier_default(self):
        with tempfile.TemporaryDirectory() as outdir:
            write_file(os.path.join(outdir, 'DAC_key.der'), DAC_DER_KEY)
            write_file(os.path.join(outdir, 'DAC_cert.der'), DAC_DER_CERT)
            write_file(os.path.join(outdir, 'PAI_cert.der'), PAI_DER_CERT)

            subprocess.check_call(['python3', os.path.join(TOOLS_DIR, 'generate_nrfconnect_chip_factory_data.py'),
                                   '-s', os.path.join(TOOLS_DIR, 'nrfconnect_factory_data.schema'),
                                   '--sn', 'SN:12345678',
                                   '--vendor_id', '0x127F',
                                   '--product_id', '0xABCD',
                                   '--vendor_name', 'Nordic Semiconductor ASA',
                                   '--product_name', 'Lock',
                                   '--date', '2022-07-20',
                                   '--hw_ver', '101',
                                   '--hw_ver_str', 'v1.1',
                                   '--dac_key', os.path.join(outdir, 'DAC_key.der'),
                                   '--dac_cert', os.path.join(outdir, 'DAC_cert.der'),
                                   '--pai_cert', os.path.join(outdir, 'PAI_cert.der'),
                                   '--spake2_it', '1000',
                                   '--spake2_salt', 'U1BBS0UyUCBLZXkgU2FsdA==',
                                   '--passcode', '20202021',
                                   '--discriminator', '0xFED',
                                   '--user', '{"name": "product_name", "version": 123, "revision": "0x123"}',
                                   '-o', os.path.join(outdir, 'fd.json')
                                   ])

            factory_data = read_json(os.path.join(outdir, 'fd.json'))

            self.assertEqual(factory_data.get('passcode'), None)
            self.assertEqual(factory_data.get('spake2_salt'),
                             base64_to_json('U1BBS0UyUCBLZXkgU2FsdA=='))
            self.assertEqual(factory_data.get('spake2_it'), 1000)
            self.assertEqual(factory_data.get('spake2_verifier'), base64_to_json(
                'uWFwqugDNGiEck/po7KHwwMwwqZgN10XuyBajPGuyzUEV/'
                'iree4lOrao5GuwnlQ65CJzbeUB49s31EH+NEkg0JVI5MGCQGMMT/SRPFNRODm3wH/MBiehuFc6FJ/NH6Rmzw=='))
            self.assertEqual(factory_data.get('user'), {'name': 'product_name', 'version': 123, 'revision': '0x123'})

            subprocess.check_call(['python3', os.path.join(TOOLS_DIR, 'nrfconnect_generate_partition.py'),
                                   '-i', os.path.join(outdir, 'fd.json'),
                                   '-o', os.path.join(outdir, 'fd'),
                                   '--offset', "0xfb000",
                                   '--size', "0x1000",
                                   '--raw'
                                   ])

    def test_generate_onboarding_codes(self):
        with tempfile.TemporaryDirectory() as outdir:
            write_file(os.path.join(outdir, 'DAC_key.der'), DAC_DER_KEY)
            write_file(os.path.join(outdir, 'DAC_cert.der'), DAC_DER_CERT)
            write_file(os.path.join(outdir, 'PAI_cert.der'), PAI_DER_CERT)

            subprocess.check_call(['python3', os.path.join(TOOLS_DIR, 'generate_nrfconnect_chip_factory_data.py'),
                                   '-s', os.path.join(TOOLS_DIR, 'nrfconnect_factory_data.schema'),
                                   '--include_passcode',
                                   '--sn', 'SN:12345678',
                                   '--vendor_id', '0x127F',
                                   '--product_id', '0xABCD',
                                   '--vendor_name', 'Nordic Semiconductor ASA',
                                   '--product_name', 'Lock Gen2',
                                   '--part_number', 'PCA10056',
                                   '--product_url', 'https://example.com/lock',
                                   '--product_label', 'Lock',
                                   '--date', '2022-07-20',
                                   '--hw_ver', '101',
                                   '--hw_ver_str', 'v1.1',
                                   '--dac_key', os.path.join(outdir, 'DAC_key.der'),
                                   '--dac_cert', os.path.join(outdir, 'DAC_cert.der'),
                                   '--pai_cert', os.path.join(outdir, 'PAI_cert.der'),
                                   '--spake2_it', '2000',
                                   '--spake2_salt', 'U1BBS0UyUCBLZXkgU2FsdA==',
                                   '--passcode', '13243546',
                                   '--spake2_verifier', ('WN0SgEXLfUN19BbJqp6qn4pS69EtdNLReIMZwv/CIM0ECMP7ytiAJ7txIYJ0Ovlha/'
                                                         'rQ3E+88mj3qaqqnviMaZzG+OyXEdSocDIT9ZhmkTCgWwERaHz4Vdh3G37RT6kqbw=='),
                                   '--discriminator', '0xFED',
                                   '--rd_uid', '91a9c12a7c80700a31ddcfa7fce63e44',
                                   '--enable_key', '00112233445566778899aabbccddeeff',
                                   '--user', '{"name": "product_name", "version": 123, "revision": "0x123"}',
                                   '-o', os.path.join(outdir, 'fd.json'),
                                   '--generate_onboarding'
                                   ])

            self.assertTrue(exists(os.path.join(outdir, 'fd.txt')))
            self.assertTrue(exists(os.path.join(outdir, 'fd.png')))

            with open(os.path.join(outdir, 'fd.txt'), 'r') as onboarding_code_file:
                onboarding = onboarding_code_file.readlines()
                self.assertEqual(onboarding[0][:-1], TEST_MANUAL_CODE)
                self.assertEqual(onboarding[1], TEST_QR_CODE)


if __name__ == '__main__':
    unittest.main()
