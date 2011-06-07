// Copyright (c) 2011, XMOS Ltd, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libusb.h"


#include <string.h>
#include <stdio.h>

unsigned int burnData[] = {
  0xfed1684b, 0xf00417ec, 0xfec2688b, 0xd04a1fec,
  0x2ff0d00f, 0x7780f001, 0xd82cf003, 0xf00337fb,
  0x37ebd839, 0x06d486c3, 0x72ccb0b4, 0x7705d01e,
  0xffbb6acb, 0xf00317ec, 0x0a3cd81b, 0x77c0160b,
  0x7327f02b, 0x17f01ff0, 0xd01f17e0, 0xd3a1f002,
  0xeac86ac6, 0x6800eacf, 0x6040f000, 0xd026f000,
  0xf02b7002, 0xf02b7306, 0xf003731a, 0x1f4dd803,
  0xd810f003, 0xd8060f4d, 0x77c0074d, 0x90009000,
  0x7335f02a, 0xd00ed002, 0x680007ee, 0x68806840,
  0x690068c0, 0x69806940, 0x6a0069c0, 0x6a806a40,
  0x77c06ac0, 0x07ffdc13, 0x77c077c0, 0x5506776b,
  0x55885547, 0x560a55c9, 0x568c564b, 0x540d86c1,
  0xf001640f, 0x644fd001, 0x00066800, 0x69c46a00,
  0x650f654e, 0xf0006a40, 0xfc636186, 0x68113fec,
  0x1639648e, 0x4fe1c81c, 0xcbd788fb, 0xfcb94fe1,
  0x92158fec, 0x744bc3d7, 0xf9906802, 0xf01f3fec,
  0x10646838, 0xf0005c0d, 0xf0005843, 0xf0005884,
  0x558158c5, 0xa7555542, 0x55045643, 0x5645a755,
  0xd110f001, 0x5c0d9129, 0x5843f000, 0x5884f000,
  0x58c5f000, 0x55425581, 0x5583a719, 0xa7195504,
  0xf0015585, 0x9201d0ff, 0x743cc3c3, 0x680064aa,
  0xf0026846, 0x5caad2bf, 0x68466800, 0xd2e0f002,
  0x5c4d6800, 0x5d0617e1, 0x5d885d47, 0x5e0a5dc9,
  0x5e8c5e4b, 0x000077eb, 0x6884f200, 0x87f1aec9,
  0xb6c0e801, 0x900077c0, 0x6881f200, 0x87f1aec9,
  0xb6c0e801, 0x3801a735, 0x900077c0, 0x6ac0f004,
  0xaeccaf4e, 0x87f287f0, 0x6801f200, 0x87f1aec1,
  0x6802f004, 0xaf4eaec2, 0xaec26800, 0x77c0aec1,
  0x55017745, 0x55835542, 0x904055c4, 0x90689054,
  0xd426907c, 0x6880f008, 0xf00caf8a, 0xaf8e68c0,
  0x87f4afcc, 0xf20087f6, 0xaf856841, 0xf02c87f5,
  0xaf866842, 0xaf8aaf8e, 0xaf866840, 0x9030af85,
  0x90d490c0, 0xd43690e8, 0x5d425d01, 0x5dc45d83,
  0x900077c5, 0x55017745, 0x55835542, 0x904055c4,
  0x90689054, 0xd450907c, 0x6880f010, 0xf014af8a,
  0xaf8e68c0, 0x87f4afcc, 0xf20087f6, 0xaf856841,
  0xf03487f5, 0xaf866842, 0xaf8aaf8e, 0xaf866840,
  0x9030af85, 0x90d490c0, 0xd46090e8, 0x5d425d01,
  0x5dc45d83, 0x900077c5, 0xaf4d6ac0, 0x87f0aecc,
  0xaec26802, 0x6800f042, 0xaf4eaec2, 0x900077c0,
  0x55017746, 0x55835542, 0x560555c4, 0x90549040,
  0x908c9068, 0x9070d487, 0x90d490c0, 0xf00890e8,
  0xd48468c0, 0xaf856840, 0x87f4aee0, 0xaf826802,
  0x6800f040, 0xaf86af82, 0x90d490c0, 0x90fc90e8,
  0x5d01d493, 0x5d835d42, 0x5e055dc4, 0x900077c6,
  0x5503774a, 0x55855544, 0x560755c6, 0x56895648,
  0x90449090, 0x906c9058, 0x90045dcb, 0xd4bc9018,
  0x90c09080, 0x90e890d4, 0xd43e68c0, 0x90d09184,
  0x90f890e4, 0x6a80f028, 0x55c25681, 0xd13ef002,
  0x918490a0, 0x90e490d0, 0xf02890f8, 0x56416a42,
  0xf00255c2, 0x41f8d133, 0x90d490c0, 0x91b090e8,
  0x90ccd459, 0x5d445d03, 0x5dc65d85, 0x5e485e07,
  0x77ca5e89, 0x5503774a, 0x55855544, 0x560755c6,
  0x56895648, 0x90449090, 0x906c9058, 0x90045dcb,
  0xd4f69018, 0x90c09080, 0x90e890d4, 0xd47868c0,
  0x90d09184, 0x90f890e4, 0x6a80f020, 0x55c25681,
  0xd104f002, 0x918490a0, 0x90e490d0, 0xf02090f8,
  0x56416a42, 0xf00255c2, 0x41f8d0f9, 0x90d490c0,
  0x91b090e8, 0x90ccd493, 0x5d445d03, 0x5dc65d85,
  0x5e485e07, 0x77ca5e89, 0x30116860, 0xa6d57044,
  0x98012004, 0xa75c77c0, 0x77c0918c, 0x5507774e,
  0x55895548, 0x560b55ca, 0x568d564c, 0x90445404,
  0x54c65485, 0x5e535e92, 0x5c11684c, 0x68301051,
  0x082010c4, 0x68090d57, 0x40382004, 0x5c4590c0,
  0xd5345c86, 0x6800f001, 0x083010c4, 0x5c4590c0,
  0xd52a5c86, 0x6810f001, 0x083010c4, 0x5c4590c0,
  0xd5085c86, 0xe8015c04, 0xb6c05c04, 0x6864f001,
  0x5c441001, 0x5c0416d1, 0x5c04e809, 0x6a00b6c0,
  0x68005c50, 0x7009c801, 0x5d07a6d1, 0x5d895d48,
  0x5e0b5dca, 0x5e8d5e4c, 0x5c0f77ce, 0xa6d11490,
  0x701c3804, 0xaeeca75c, 0x5c0f87f4, 0x0da611f0,
  0x90d05c04, 0x5cc65c85, 0x5ed155c1, 0x558356c2,
  0xd09ef002, 0x38dda6d5, 0xce11704d, 0xfe084fe1,
  0x920107ec, 0xc9805c10, 0x772a7420, 0xaf806800,
  0x771d87f4, 0x4fe1ce11, 0x07ecfe08, 0x9000770e,
  0x55007742, 0x5d435541, 0x68805d04, 0x70c4c839,
  0x5d006800, 0x77c25d41, 0x1038a75d, 0x70c83cbf,
  0x4fe3ca79, 0x4fe3ca78, 0xc8399029, 0x771074ca,
  0x4fe3ca79, 0x4fe3ca78, 0x90007709, 0x5503774a,
  0x55855544, 0x560755c6, 0x56895648, 0x544190a0,
  0x909c5482, 0x5dcd5e0c, 0x91206900, 0xc8c05c01,
  0x90c07009, 0x5d445d03, 0x5dc65d85, 0x5e485e07,
  0x77ca5e89, 0xa6d1155a, 0x700f3804, 0x4fe0cd48,
  0x4a525c02, 0x4fe0cb0b, 0x8ec04bc6, 0x71633854,
  0x5c019129, 0x7412c8c8, 0xcd48771c, 0x5c024fe0,
  0x8ec44a42, 0x4fe0cb0b, 0x38544bc6, 0xf0207d4f,
  0x39886800, 0x13da7007, 0xf0005c0b, 0x7418d2a1,
  0x771a4341, 0x5d0390c4, 0x5d855d44, 0x5e075dc6,
  0x5e895e48, 0xf02077ca, 0x39886800, 0x13da7007,
  0xf0005c0b, 0x742cd28d, 0x772e4341, 0x5d0390c4,
  0x5d855d44, 0x5e075dc6, 0x5e895e48, 0x900077ca,
  0x55007742, 0x5ec35541, 0x5d455d04, 0x87f1af01,
  0xaec76842, 0xaf036900, 0xaf4e87f3, 0xaec7a6d5,
  0xb6c4e801, 0x10e6688c, 0x12550a99, 0xe80916d4,
  0xaf03b6c4, 0xaec76844, 0xb6c4e801, 0x10160a69,
  0xe80916d4, 0xbec7b6c4, 0x38046820, 0x5d00af03,
  0x77c25d41, 0x55047749, 0x55865545, 0x560855c7,
  0x905c9040, 0x5e0b5eca, 0x5d8d5dcc, 0x560256c1,
  0xd43a5583, 0xaf856848, 0xb784e901, 0x17941257,
  0xb784e909, 0xaf856840, 0xb784e901, 0x10ea688c,
  0x10160a68, 0xe9091794, 0x5d04b784, 0x5d865d45,
  0x5e085dc7, 0x900077c9, 0x55097750, 0x558b554a,
  0x560d55cc, 0x568f564e, 0x54465405, 0x54c85487,
  0x5e125d11, 0xa7195dd3, 0x70213b02, 0x680c6940,
  0x90c8115c, 0x3990d567, 0x38c48ec0, 0x8f484004,
  0x5c050a35, 0x5c875c46, 0x55015cc8, 0x56c35682,
  0xd45055c4, 0x68209129, 0x7c15ca42, 0x5d096800,
  0x5d8b5d4a, 0x5e0d5dcc, 0x5e8f5e4e, 0xa75c77d0,
  0x772391dc, 0x55097755, 0x558b554a, 0x560d55cc,
  0x568f564e, 0x54465405, 0x54c85487, 0x5e185d16,
  0x5410a6d1, 0x5c465c05, 0x5cc85c87, 0xd1745601,
  0x8f045c17, 0xaf045c06, 0x87f05c06, 0x5c086842,
  0x5c48aec4, 0xaec16800, 0x87f05c08, 0x5c465c05,
  0x5cc85c87, 0x56025501, 0xd338f001, 0x30115c57,
  0x7067f001, 0xf8615c57, 0xa6d50fec, 0xf00138d1,
  0x3a417069, 0x7037f001, 0x54116800, 0x5c465c05,
  0x5cc85c87, 0xd17e5601, 0xf0010980, 0x5c057035,
  0x5c05e801, 0xf001b6c0, 0x10016864, 0x16d15c45,
  0xe8095c05, 0xb6c05c05, 0x5412a6d1, 0x54138f82,
  0xf0005c12, 0x5c57d5df, 0x8ec43824, 0x38015c11,
  0x8f084008, 0x5c1269c0, 0xa6d19811, 0x5c132011,
  0x701f3804, 0x5c465c05, 0x5cc85c87, 0xd1525601,
  0x11d0680c, 0x5c050956, 0x5c875c46, 0x55015cc8,
  0x56435582, 0xd4da5604, 0x5c465c05, 0x5cc85c87,
  0x55825501, 0xd50c5603, 0x7006f001, 0xf001b001,
  0x5c127036, 0x54129001, 0x68205c52, 0x7c38c801,
  0x5d095c10, 0x5d8b5d4a, 0x5e0d5dcc, 0x5e8f5e4e,
  0xa6d177d5, 0x5d4a5d09, 0x5dcc5d8b, 0x5e4e5e0d,
  0x77d55e8f, 0x5c178ec4, 0x70043804, 0x56d1a75c,
  0x772cf001, 0x5d096800, 0x5d8b5d4a, 0x5e0d5dcc,
  0x5e8f5e4e, 0x680077d5, 0x5d4a5d09, 0x5dcc5d8b,
  0x5e4e5e0d, 0x77d55e8f, 0xe8015c05, 0xb6c05c05,
  0x11d1684c, 0x101108d7, 0x16d45c05, 0xe8095c05,
  0xb6c05c05, 0x7705f002, 0x913d5514, 0x5c465c05,
  0x5cc85c87, 0xd0b85601, 0x5c465c05, 0x5cc85c87,
  0x56415e54, 0x56035582, 0x7007d565, 0x7c1af001,
  0xc8dd6850, 0xf0017456, 0x5c05771f, 0x5c875c46,
  0x56015cc8, 0x08c6d0d7, 0x5c0590a0, 0x5c875c46,
  0x55015cc8, 0x56835582, 0xd5545604, 0x5c465c05,
  0x5cc85c87, 0x55825501, 0xd5865603, 0x68007721,
  0xf0015410, 0x9000773a, 0x0010a6d5, 0x00116840,
  0x77c00012, 0x55017772, 0x688a6442, 0x64c20024,
  0x6848f04e, 0x64c2001d, 0x6850f30d, 0x64c2001e,
  0x6850f09c, 0x64c2001f, 0x6864f001, 0x64c2025c,
  0x025d6844, 0x02666442, 0x68466482, 0x6482025b,
  0x04986842, 0xa6db6442, 0x644204a5, 0x04c76900,
  0x68f06442, 0x00471017, 0x10b76442, 0x019d6864,
  0x123f66c2, 0x6442019e, 0xf0041037, 0x001c6864,
  0xf0016442, 0x101768c0, 0x64420047, 0xf00810b7,
  0x019d6860, 0x123f66c2, 0x6442019e, 0x00441017,
  0xf0016442, 0x101768d0, 0x64420047, 0xf0801047,
  0x00d16848, 0x10476442, 0x684ef0c0, 0x644200d2,
  0xf2001037, 0x001c6843, 0x04a66442, 0x64427805,
  0x68a0f001, 0xd2eef001, 0x77f25d01, 0x55017744,
  0x55835542, 0x90489064, 0x9004905c, 0x902c9018,
  0xf00168c0, 0x90c8d40d, 0x90e490d0, 0xf00168c0,
  0x90c8d401, 0x90e490d0, 0xf00068c0, 0x5d01d7dd,
  0x5d835d42, 0x900077c4, 0x55017747, 0x55835542,
  0x560555c4, 0x90445646, 0x906c9058, 0x69cc5e48,
  0x68301447, 0x08211180, 0x68090e13, 0x40382004,
  0x90d490c0, 0xf00190e8, 0xf001d437, 0x11806800,
  0x09840811, 0x40342243, 0x90d490c0, 0xf00190e8,
  0xf001d431, 0x11806810, 0x90c00831, 0x90e890d4,
  0xd410f001, 0x5d425d01, 0x5dc45d83, 0x5e465e05,
  0x900077c7, 0x55017747, 0x55835542, 0x560555c4,
  0x90445646, 0x906c9058, 0x69cc5e48, 0x68301447,
  0x08221180, 0x68090e13, 0x40382004, 0x90d490c0,
  0xf00190e8, 0xf001d46d, 0x11806800, 0x09840812,
  0x40342243, 0x90d490c0, 0xf00190e8, 0xf001d467,
  0x11806810, 0x90c00832, 0x90e890d4, 0xd446f001,
  0x5d425d01, 0x5dc45d83, 0x5e465e05, 0x900077c7,
  0x55007744, 0x55825541, 0xf02055c3, 0x38266880,
  0x69c070a0, 0x68cc6904, 0x68bcf007, 0x4fe6cb6c,
  0x3fecf91f, 0x0a3d12f1, 0x4fe672cb, 0x0a3d12f1,
  0x4fe67ad6, 0x09141291, 0x38563926, 0x71633359,
  0xcb5c913d, 0x68007555, 0x5d415d00, 0x5dc35d82,
  0x680077c4, 0x5d415d00, 0x5dc35d82, 0x4fe677c4,
  0x0a3e12f1, 0x4fe676da, 0xa6d91271, 0xf01f002e,
  0x381668bc, 0x12414fe6, 0xa6d10010, 0x5d415d00,
  0x5dc35d82, 0xa6d177c4, 0x5d415d00, 0x5dc35d82,
  0x900077c4, 0x7754f020, 0x554b550a, 0x55cd558c,
  0x564f560e, 0x54065690, 0x54885447, 0xf02054c9,
  0xf0205dd5, 0xf0205d96, 0xf0205d17, 0xf0205e18,
  0x09825d59, 0x131c7012, 0x6800f020, 0x7866c811,
  0xf001c8cc, 0x68007810, 0x5d4b5d0a, 0x5dcd5d8c,
  0x5e4f5e0e, 0xf0205e90, 0x6ac077d4, 0x7c15cbcc,
  0xf0206491, 0xa22d6800, 0x4fe1cbdd, 0xc9b84ddb,
  0xfd1a4fe3, 0x4fe107ec, 0x92194d7b, 0x4fe1c994,
  0x07ecfcb9, 0xcbdc923d, 0x772b7452, 0x70130982,
  0x5c475c06, 0x5cc95c88, 0x558255c1, 0x56045503,
  0xd0565545, 0x5d4b5d0a, 0x5dcd5d8c, 0x5e4f5e0e,
  0xf0205e90, 0xa12d77d4, 0xa1016551, 0x5c475c06,
  0x5cc95c88, 0x55425581, 0x56045503, 0x6900f020,
  0xd03e5505, 0x5d4b5d0a, 0x5dcd5d8c, 0x5e4f5e0e,
  0xf0205e90, 0xf02077d4, 0xf0205611, 0x5e095552,
  0x5e875d48, 0xf0205c06, 0x91885413, 0xf00190d4,
  0x9090d565, 0x90d49188, 0x68c091a0, 0xd4e8f001,
  0x5c13f020, 0x90e49198, 0x55c191b0, 0x55035582,
  0x5d11f020, 0xf0205504, 0x55055d12, 0x9040d011,
  0x90d49188, 0x91b491a0, 0xd4fef001, 0x5d0a90c0,
  0x5d8c5d4b, 0x5e0e5dcd, 0x5e905e4f, 0x77d4f020,
  0x775ef021, 0x554b550a, 0x55cd558c, 0x564f560e,
  0x54065690, 0x54885447, 0xf02154c9, 0x69005e5f,
  0x5c475c06, 0x5cc95c88, 0x5c06d58f, 0x5c885c47,
  0xf0215cc9, 0x55415d62, 0xd4fef001, 0x64e9f020,
  0x6840688c, 0x07ecf81e, 0xf0206940, 0xa6da6469,
  0xa02b1a69, 0x17ecf832, 0x382ea738, 0xc8f768c4,
  0x68cc4fe3, 0x3fecf8f7, 0x69801077, 0x6984012c,
  0x4fe6cb66, 0x69801077, 0xf004012e, 0xf0207087,
  0x688465a9, 0x4fe2c8e6, 0x688010fb, 0x9115002d,
  0xc0e66884, 0x641174a4, 0xf021d62b, 0x680c5c62,
  0x64511054, 0xf00190c4, 0xf00168a0, 0xf021d11b,
  0x65e95da1, 0x5c475c06, 0x5cc95c88, 0x55825641,
  0x5da2f021, 0x55c45583, 0x6980f020, 0xf0015585,
  0xf021d4cb, 0x64a95c61, 0x5ce0f021, 0x65a9f020,
  0x55819184, 0x6980f020, 0xf0215582, 0x55835da3,
  0xd44cf001, 0x7023f003, 0x68005c48, 0x5c06aec1,
  0x5c885c47, 0xf0215cc9, 0x55815da2, 0xf021d5e3,
  0x08005c22, 0x701df003, 0xf0216940, 0x68005c61,
  0xf003c801, 0x5c067024, 0x5c06e801, 0xf001b6c0,
  0x10016864, 0x16d15c46, 0xe8095c06, 0xb6c05c06,
  0xf0216940, 0x68005c61, 0xf003c801, 0xf0207032,
  0x662965e9, 0xf0216980, 0x68005c61, 0xf004c801,
  0x68007023, 0x7034f004, 0x6469f020, 0x5c22f021,
  0x5436f020, 0x5477f020, 0xf0205c09, 0x5c085438,
  0x5439f020, 0xf0205c07, 0x5c06543a, 0x543bf020,
  0xf0206800, 0x6800543d, 0x543ef020, 0x6800f018,
  0x68093994, 0xf0212804, 0xf0215413, 0x680c5c62,
  0xf0211004, 0xf021541c, 0xa6d15c5c, 0x68000487,
  0x543cf020, 0xa6d66880, 0x5c3cf020, 0xa0021804,
  0x5414f021, 0x5c7cf020, 0xc8646804, 0xf0204fe6,
  0x680c5c7c, 0x3fecf804, 0x541bf021, 0x5c77f020,
  0x5c1bf021, 0x08021004, 0x7034f003, 0xf0204fe6,
  0xf0215c77, 0x10045c1b, 0xb0010801, 0x701af009,
  0x5c3cf020, 0x2018a003, 0x5c3ef020, 0xf0204001,
  0xf020543e, 0x90015c3c, 0x543cf020, 0x5c7cf020,
  0xc8046804, 0xf0217439, 0x68005c5c, 0xf0200487,
  0xf0095c3e, 0xf020700a, 0x5c065d3d, 0x5c885c47,
  0xd6a45cc9, 0x5c475c06, 0x5cc95c88, 0x5d62f021,
  0xf0015541, 0x9050d613, 0x5c485c07, 0x90f45c89,
  0xd642f001, 0x716df00c, 0x5d0ab0c0, 0x5d8c5d4b,
  0x5e0e5dcd, 0x5e905e4f, 0x77def021, 0x6629f020,
  0x4c32698c, 0x698c913d, 0x07ecfc32, 0x65e9f020,
  0xcb666984, 0x113f4fe6, 0x012da719, 0x65e9f020,
  0xcb666984, 0x10ff4fe6, 0xf004002c, 0x68007718,
  0x5d4b5d0a, 0x5dcd5d8c, 0x5e4f5e0e, 0xf0215e90,
  0x5c0677de, 0x5c06e801, 0x08d7b6c0, 0x5c061011,
  0x5c0616d4, 0x5c06e809, 0xf003b6c0, 0x65e9772b,
  0x6980f020, 0x4fe0cb06, 0xfb0d6800, 0x146507ec,
  0x5c23f021, 0x4fe0c8c4, 0x5c20f021, 0x5c064ac1,
  0x5c885c47, 0x56815cc9, 0xf0215602, 0x56035e22,
  0xd4aef001, 0xf0219115, 0xc8c45c21, 0xf004741d,
  0xf0207706, 0x5c066980, 0x5c885c47, 0xf0215cc9,
  0x55c15de2, 0x5c06d6ff, 0x5c06e801, 0xf001b6c0,
  0x10016864, 0x16d15c46, 0xe8095c06, 0xb6c05c06,
  0xf0211445, 0xc8c45c23, 0xf0214fe0, 0x4ab15c20,
  0x5c475c06, 0x5cc95c88, 0x55c25601, 0x5de2f021,
  0xf00155c3, 0xb000d4a9, 0x70074100, 0xf0219115,
  0xc8c45c21, 0xf0047430, 0x64697726, 0x4fe0cb06,
  0xfa45a6d1, 0x770e07ec, 0x6940f020, 0x4fe0cb09,
  0x70074bc2, 0xf0219129, 0xc8c85c21, 0xf0047409,
  0x13d67730, 0xd6d490cc, 0xa6d1740b, 0x7736f004,
  0x5d0ab0c0, 0x5d8c5d4b, 0x5e0e5dcd, 0x5e905e4f,
  0x77def021, 0x4fe64fe6, 0x5c77f020, 0x5c1bf021,
  0x08101004, 0x683cf007, 0xf0213804, 0xf0205415,
  0xf0205c3b, 0xf0205c7a, 0xf0205cb9, 0xd7825cf8,
  0x69c06a00, 0x21d06809, 0x5c77f020, 0x5c1bf021,
  0xf0211004, 0x4fe65416, 0x5c16f021, 0xf0070810,
  0x3804683c, 0xf02110c4, 0xc9915c53, 0x7060f004,
  0xf0211263, 0x11955c61, 0xf004c819, 0xf00f7859,
  0x3995687c, 0xf0043001, 0xf021700e, 0x31805c13,
  0x702af004, 0xf0204fe6, 0xf0215c77, 0x10045c1b,
  0xf0070810, 0x3804683c, 0x1c814241, 0xf0211253,
  0xc8045c23, 0xf0214fe0, 0x48315c20, 0x6483f021,
  0x1253a182, 0xca446910, 0xf8394fe0, 0x913d07ec,
  0xc8cc6804, 0x7401f001, 0x68049201, 0xf001c980,
  0xf0217410, 0xa6d15c5c, 0x69c00487, 0x68096a00,
  0xf02121d0, 0x10c45c14, 0x541df021, 0x5d5df021,
  0x5c3bf020, 0x5c7af020, 0x5cb9f020, 0x5cf8f020,
  0x69445541, 0xf0205542, 0x55435d76, 0x657ff020,
  0x69445544, 0xf0015545, 0xf021d6df, 0x68445c1d,
  0x64bff020, 0x64c3f021, 0x55416944, 0x55426950,
  0xd67af001, 0xf020413c, 0x42435c3d, 0x543df020,
  0x68049201, 0x7435c980, 0x5c3bf020, 0x5c7af020,
  0x5cb9f020, 0x5cf8f020, 0x5d76f020, 0xf0005541,
  0x6a00d7fd, 0x680969c0, 0xa18221d0, 0x5418f021,
  0x5c14f021, 0x124110cc, 0x5417f021, 0x5c18f021,
  0xca441253, 0xf0214fe0, 0x48a16403, 0x5c3bf020,
  0x5c7af020, 0x5cb9f020, 0x5cf8f020, 0x5ed7f021,
  0x568256c1, 0x5eb6f020, 0xf0015683, 0x913dd5e3,
  0xc8cc6804, 0x92017423, 0xc9806804, 0x6a00742d,
  0x680969c0, 0xa18221d0, 0x541af021, 0x5c3bf020,
  0x5c7af020, 0x5cb9f020, 0x5cf8f020, 0x5eb6f020,
  0xf0015681, 0x5c06d43f, 0x5c06e801, 0xf001b6c0,
  0x10016864, 0x16d15c46, 0xe8095c06, 0xb6c05c06,
  0x5c14f021, 0x124110cc, 0x5419f021, 0x5c1af021,
  0xca441253, 0xf0214fe0, 0x48a16403, 0x5c3bf020,
  0x5c7af020, 0x5cb9f020, 0x5cf8f020, 0x5ed9f021,
  0x568256c1, 0x5eb6f020, 0xf0015683, 0xb000d5f5,
  0x5c7df020, 0xf0204004, 0x913d543d, 0xc8cc6804,
  0x7404f001, 0x68049201, 0xf001c980, 0x4fe6740f,
  0x5c77f020, 0x5c1bf021, 0x08101004, 0x3804681c,
  0x4fe6a822, 0x5c77f020, 0x5c1bf021, 0x08101004,
  0x6820f007, 0xa8013804, 0xa7304018, 0x68083821,
  0xf0084028, 0xa6d27733, 0xc8cc3984, 0x7c13f004,
  0x5c15f021, 0x128110cc, 0x5c3bf020, 0x5c7af020,
  0x5cb9f020, 0x5cf8f020, 0xf0205501, 0x55025d36,
  0xf021d12d, 0xa19264c3, 0x69101267, 0x4fe1ca58,
  0x07ecf80e, 0x770df004, 0x3984a6d2, 0x7420c8cc,
  0x7730f004, 0xf0204fe6, 0xf0215c77, 0x10045c1b,
  0xa7300810, 0xf0093821, 0xf0207725, 0xff105c3e,
  0xf02007ec, 0xf0205c3b, 0xf0205c7a, 0xf0205cb9,
  0xf0015cf8, 0xf020d4f5, 0xf0205c3b, 0xf0205c7a,
  0xf0205cb9, 0xf0205cf8, 0x55415d76, 0xd42ef002,
  0xf0209060, 0xf0205c3a, 0xf0025c79, 0x9050d51b,
  0x5c3af020, 0x5c79f020, 0x5cb8f020, 0xf00268c0,
  0xf020d4a1, 0xf0205c3b, 0xf0205c7a, 0xf0205cb9,
  0xf0205cf8, 0x55c15df6, 0xd502f001, 0x5c22f021,
  0xf0020800, 0xf020702e, 0xf0205c3b, 0xf0205c7a,
  0xf0205cb9, 0xf0285cf8, 0x55c169c0, 0xf0205502,
  0x55c35df6, 0xd6d8f001, 0x5c3bf020, 0x5c7af020,
  0x5cb9f020, 0x5cf8f020, 0x69c0f028, 0x550255c1,
  0x5df6f020, 0xf00155c3, 0xb000d6b3, 0x5c7df020,
  0xf0204004, 0xf020543d, 0xf0205c3b, 0xf0205c7a,
  0xf0205cb9, 0xf0285cf8, 0x55c169c2, 0xf0205502,
  0x55c35df6, 0xd700f001, 0x5c3bf020, 0x5c7af020,
  0x5cb9f020, 0x5cf8f020, 0x69c2f028, 0x550255c1,
  0x5d36f020, 0xf0015503, 0xb000d6db, 0x5c7df020,
  0xf0204004, 0xf002543d, 0x41086800, 0x5c3bf020,
  0x5c7af020, 0x5cb9f020, 0x5cf8f020, 0x6980f020,
  0x55025581, 0x5db6f020, 0xf0015583, 0xf020d72b,
  0xf0205c3b, 0xf0205c7a, 0xf0205cb9, 0xf0205cf8,
  0x55816980, 0xf0205502, 0x55835db6, 0xd706f001,
  0xf020b000, 0x40045c7d, 0x543df020, 0x5c3bf020,
  0x5c7af020, 0x5cb9f020, 0x5cf8f020, 0x6982f020,
  0x55025581, 0x5db6f020, 0xf0015583, 0xf020d753,
  0xf0205c3b, 0xf0205c7a, 0xf0205cb9, 0xf0205cf8,
  0x55816982, 0xf0205502, 0x55035d36, 0xd72ef001,
  0xf020b000, 0x40045c7d, 0x543df020, 0x5c3af020,
  0x5c79f020, 0x5cb8f020, 0xf00290f4, 0xf00cd55f,
  0x5c067736, 0x5c06e801, 0xf021b6c0, 0x08175c5c,
  0x5c061011, 0x5c0616d4, 0x5c06e809, 0xf002b6c0,
  0xf200773e, 0x5c086840, 0x5c08aec4, 0x5c0787f0,
  0x5c07e801, 0xf002b6cc, 0x403c6800, 0x5c485c07,
  0xf0025c89, 0xf00dd58f, 0x90007701, 0x55007741,
  0x5d035c02, 0x87f2aec2, 0xaecb6880, 0x3ec387f3,
  0x3f5f9532, 0xaec3a6d1, 0x10c0680c, 0x118c0c81,
  0xaecb3ed3, 0xe84187f3, 0x5d00b6c1, 0x900077c1,
  0x55007741, 0x5c035ec2, 0xaf4e5d04, 0x688087f2,
  0x87f3aecb, 0x95303ec3, 0xa6d13f5f, 0x13ccaec3,
  0xaecb3ed3, 0xe84187f3, 0x5d00b6c1, 0x07ed77c1,
  0x774107ec, 0x90106800, 0xd0b8f000, 0xd0c5f000,
  0xd0f5f000, 0xd000f000, 0xf0006807, 0x07edd0ad,
  0x901007ec, 0xf0006800, 0x07edd0a7, 0x774207ec,
  0x90405501, 0xf0006840, 0xf000d0a1, 0xf000d0ae,
  0x90c0d0de, 0xd413f000, 0x55047745, 0x55825543,
  0x560055c1, 0x473c9034, 0x69006ac0, 0x730691dc,
  0x71fa3136, 0x8fecfb18, 0x91159a3d, 0x913812a1,
  0x75ca471e, 0xa71a14cb, 0x7925cb48, 0x40f3a4cc,
  0x4103a4cd, 0x699014bb, 0x1291ca7e, 0x698070d1,
  0x0104a7dc, 0x01060105, 0x14bb0107, 0xfa7c10fb,
  0xc94fa7ec, 0xa7ecfb68, 0x9fecfb54, 0x7301760e,
  0xa6da14bb, 0x7889c82b, 0x0104a6da, 0xc8bb9a7c,
  0x76c59354, 0x14bb7302, 0x78c61291, 0xf8d66880,
  0x90298fec, 0x7ec530bb, 0x5dc15e00, 0x5d435d82,
  0x77c55d04, 0x70e2acb1, 0x70e0acb5, 0xf30c86ce,
  0x73076acc, 0x70daacb1, 0x70d8acb5, 0xf30886ce,
  0xa4816acc, 0x16d34483, 0x6ac1f003, 0xac8c4f2f,
  0xad34a480, 0xaec34483, 0x4edd0ed7, 0xb00386d3,
  0xb6c77802, 0xcedd0018, 0x77c017e3, 0x77c06800,
  0x70e0acb1, 0x70deacb5, 0xf30c86ce, 0x73076acc,
  0x70d8acb1, 0x70d6acb5, 0xf30886ce, 0xa4816acc,
  0x16d34483, 0x6ac0f003, 0xac8c4f2f, 0xad34a480,
  0xaec34483, 0xaecb0ed7, 0x86d34edd, 0xceddb003,
  0x77c017e3, 0x77c06800, 0x77c0a6d0, 0xf0007741,
  0x77c1d07c, 0x98297885, 0xf8b288b6, 0x74858fec,
  0x878177c0, 0x500ef000, 0x774177c0, 0xd06ef000,
  0x774177c1, 0xd87ef000, 0x6840918c, 0xd87af000,
  0xf00019ac, 0xf000d4b7, 0x918cd891, 0xf0006840,
  0x19acd89d, 0xd4c0f000, 0xd41df000, 0xd884f000,
  0xf000918c, 0x6880604f, 0xf00268c0, 0xf000d792,
  0xa902590c, 0xf000790b, 0x91dcd851, 0x598bf000,
  0x99011b66, 0x12424b04, 0x750527e0, 0x774177c1,
  0x55017785, 0x55835542, 0xf00055c4, 0xa93e59c2,
  0x690079cd, 0xd840f000, 0xf00091dc, 0x1b665981,
  0x12424b04, 0x910127e0, 0x76c6cbb3, 0x5d425d01,
  0x5dc45d83, 0x77c16785, 0x5803f000, 0x6846e808,
  0x0fecfed4, 0xf00077c0, 0xe8005803, 0xf00077c0,
  0xe8085804, 0xfed46846, 0x77c00fec, 0x5804f000,
  0x77c0e800, 0x5805f000, 0x6846e808, 0x0fecfed4,
  0xf00077c0, 0xe8005805, 0x77c077c0, 0x568677c0,
  0x00010000, 0x00000011, 0xfffffffe, 0x00011828,
  0x0001183e, 0x00011854, 0x00011836, 0x0001184c,
  0x00011862, 0x00000000, 0x00011888, 0x0000000c,
  0x00200100, 0x00100200, 0x00100300, 0x58585858,
  0x58585858, 0x58585858, 0x58585858, 0x00000000,
  0x0001187c, 0x0000000c, 0x00000000, 0xb70a771b,
};

#define XMOS_VID 0x20b1
#define JTAG_PID 0xf7d1

/* the device's endpoints */

#define EP_IN 0x82
#define EP_OUT 0x01


#define LOADER_BUF_SIZE 512
#define LOADER_CMD_SUCCESS 0
#define LOADER_CMD_FAIL -1



enum loader_cmd_type {
  LOADER_CMD_NONE,
  LOADER_CMD_WRITE_MEM,
  LOADER_CMD_WRITE_MEM_ACK,
  LOADER_CMD_GET_VERSION,
  LOADER_CMD_GET_VERSION_ACK,
  LOADER_CMD_JUMP,
  LOADER_CMD_JUMP_ACK
};




static libusb_device_handle *devh = NULL;



static int dbg_usb_bulk_io(int ep, char *bytes, int size, int timeout) {
    int actual_length;
    int r;
    void *ofunc = signal(SIGINT, SIG_IGN);
    r = libusb_bulk_transfer(devh, ep & 0xff, (unsigned char*)bytes, size, &actual_length, timeout);
    signal(SIGINT, ofunc);
    if (r == 0) {
        return 0;
    }
    if (r == LIBUSB_ERROR_TIMEOUT) {
        //printf("\n***** DEVICE ACCESS TIMEOUT *****\n");
        return -2;
    } 
    if (r == LIBUSB_ERROR_NO_DEVICE) {
        return -1;
    }
    return  -3;
}

int device_read(char *data, unsigned int length, unsigned int timeout) {
    int result = 0;
    result = dbg_usb_bulk_io(EP_IN, data, length, timeout);
    return result;
}

int device_write(char *data, unsigned int length, unsigned int timeout) {
    int result = 0;
    result = dbg_usb_bulk_io(EP_OUT, data, length, timeout);
    return result;
}


static void burnSerial() {
  unsigned int i = 0;
  unsigned int address = 0;
  unsigned int num_blocks = 0;
  unsigned int block_size = 0;
  unsigned int remainder = 0;
  unsigned int data_ptr = 0;
  int cmd_buf[LOADER_BUF_SIZE/4];
  int bin_len = sizeof(burnData);
  char *charBurnData = (char *)burnData;

  memset(cmd_buf, 0, LOADER_BUF_SIZE);

  address = 0x10000;
  block_size = LOADER_BUF_SIZE - 12; 
  num_blocks = bin_len / block_size;
  remainder = bin_len - (num_blocks * block_size);

  for (i = 0; i < num_blocks; i++) {
    cmd_buf[0] = LOADER_CMD_WRITE_MEM;
    cmd_buf[1] = address;
    cmd_buf[2] = block_size;
    memcpy(&cmd_buf[3], &charBurnData[data_ptr], block_size);
    device_write((char *)cmd_buf, LOADER_BUF_SIZE, 1000);
    device_read((char *)cmd_buf, 8, 1000);
    address += block_size;
    data_ptr += block_size;
  }

  if (remainder) {
    cmd_buf[0] = LOADER_CMD_WRITE_MEM;
    cmd_buf[1] = address;
    cmd_buf[2] = remainder;
    memcpy(&cmd_buf[3], &charBurnData[data_ptr], remainder);
    device_write((char *)cmd_buf, LOADER_BUF_SIZE, 1000);
    device_read((char *)cmd_buf, 8, 1000);
  }

  printf("Burning starting...\n");

  cmd_buf[0] = LOADER_CMD_JUMP;
  device_write((char *)cmd_buf, 4, 1000);
  device_read((char *)cmd_buf, 8, 1000);
}



static int find_device(unsigned int id, unsigned int open, char *new) {
    libusb_device *dev;
    libusb_device **devs;
    int i = 0;
    int found = 0;
    char string[18];

    libusb_get_device_list(NULL, &devs);
    
    while ((dev = devs[i++]) != NULL) {
        struct libusb_device_descriptor desc;
        libusb_get_device_descriptor(dev, &desc); 

        if (desc.idVendor != 0x20B1 || desc.idProduct != 0xF7D1) {
            continue;
        }
        if (!open) {
            printf("%d - VID = 0x%x, PID = 0x%x\n", found, desc.idVendor, desc.idProduct);
        } else {
            if (found == id) {
                printf("PROGRAM %d - VID = 0x%x, PID = 0x%x\n", found, desc.idVendor, desc.idProduct);
                if (desc.bcdDevice & 0xff00) {
                    fprintf(stderr, "Device need to be unplugged and plugged back in\n");	
                    exit(1);
                }
                if (libusb_open(dev, &devh) < 0) {
                    return -1;
                }
                libusb_get_string_descriptor_ascii(devh, desc.iSerialNumber, string, 17);
                if (strcmp(string,"XXXXXXXXXXXXXXXX")!= 0) {
                    if (strcmp(string, new) != 0) {
                        fprintf(stderr, "Serial number is not all X's: %s\n", string);
                        exit(1);
                    }
                    fprintf(stderr, "Overwriting identical serial number - I hope this was a test\n");
                }
                break;
            }
        }
        found++;
    }
    
    libusb_free_device_list(devs, 1);
    
    return devh ? 0 : -1;
}

void createRandom(char *startAddr, int from, int to) {
    int i;
    srandomdev();
    for(i = from; i < to; i++) {
        startAddr[i] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"[random() & 63];
    }
}

int main(int argc, char **argv) {
    int r = 1;
    int id = 0;
    int list = 0;
    char *startAddr = (char*)&burnData[sizeof(burnData)/sizeof(int) - 9];
    int i;
    if (strcmp(startAddr, "XXXXXXXXXXXXXXXX") != 0) {
        printf("Internal error, expected lots of Xs, not \"%s\"\n", startAddr);
        exit(1);
    }
    if (argc == 2 && strcmp(argv[1], "-l") == 0) {
        list = 1;
    } else if (argc == 4 && strcmp(argv[1], "-s") == 0 && strlen(argv[2]) == 16) {
        for(i = 0; i < 16; i++) {
            startAddr[i] = argv[2][i];
        }
        id = atoi(argv[3]);
    } else if (argc == 4 && strcmp(argv[1], "-r") == 0 && strlen(argv[2]) == 3) {
        for(i = 0; i < 3; i++) {
            startAddr[i] = argv[2][i];
        }
        startAddr[3] = 'R';
        createRandom(startAddr, 4, 16);
        id = atoi(argv[3]);
    } else if (argc == 4 && strcmp(argv[1], "-x") == 0 && strlen(argv[2]) == 8) {
        for(i = 0; i < 8; i++) {
            startAddr[i] = argv[2][i];
        }
        createRandom(startAddr, 8, 16);
        id = atoi(argv[3]);
    } else {
        fprintf(stderr, "Usage: blowUSBserial -s SERIAL_NUMBER ID (16 characters)\n       or            -r THREECHARS ID (random starting with those 3 chars)\n       or            -x XMOSDEVICE ID  (6 char XMOS ID plus 2 char batch, 8 random)\n       or            -l   (list devices)\n");
        return 1;
    }

    r = libusb_init(NULL);
    if (r < 0) {
        fprintf(stderr, "failed to initialise libusb\n");
        return -1;
    }

    
    if (list) {
        find_device(0,0,"");
    } else {
        if (find_device(id,1, startAddr) < 0) {
            fprintf(stderr, "Device not found\n", r);
            return -1;
        }

        r = libusb_claim_interface(devh, 0);
        if (r < 0) {
            fprintf(stderr, "usb_claim_interface error %d\n", r);
            return -1;
        }
        printf("Programming serial %s\n", startAddr);
        burnSerial();
        sleep(1);
        printf("Burning done...\n");
        libusb_reset_device(devh);
        libusb_close(devh);
    } 

    libusb_exit(NULL);
    
    return 0;
}
