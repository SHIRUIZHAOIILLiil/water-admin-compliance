
//普通
"1,1,1,2-Tetrachloroethane, 1,1,1-Trichloroethane, 1,1,2,2-Tetrachloroethane, 1,1,2-Trichloroethane, 
1,1-Dichloroethane, 1,1-Dichloroethylene (1,1-Dichloroethene), 1,1-Dichloropropylene (1,1-Dichloropropene), 
1,2,3-Trimethylbenzene, 1,2,4-Trimethylbenzene, 1,2-Dibromo-3-chloropropane, 1,2-Dibromoethane, 1,2-Dichlorobenzene,
1,2-Dichloroethane, 1,2-Dichloropropane, 1,2-Dimethylbenzene :- {o-Xylene}, 1,3,5-Trimethylbenzene :- {Mesitylene},
1,3-Dichlorobenzene, 1,3-Dichloropropane, 1,4-Dichlorobenzene, 1-Butanol :- {Butan-1-ol}, 1-Propanol :- {n-Propanol},
17alpha ethynyloestradiol :- {EE2}, 17beta oestradiol :- {E2}, 2,2-Dichloropropane, 2,3,5,6-Tetrachloroaniline, 
2,3,5,6-Tetrachlorothioanisole, 2,3,6-TBA :- {2,3,6-Trichlorobenzoic acid}, 2,3-Dichlorophenol, 2,3-Dimethylphenol :- {2,3-Xylenol},
2,4,5-T :- {2,4,5-Trichlorophenoxyacetic acid}, 2,4,5-Trichlorophenol, 2,4,6-Trichlorophenol, 2,4-D :- {2,4-Dichlorophenoxyacetic acid},
2,4-DB :- {4-(2,4-dichlorophenoxy)butyric acid}, 2,4-Dichlorophenol, 2,4-Dimethylphenol :- {2,4-Xylenol}, 2,5-Dichlorophenol, 2,5-Dimethylphenol :- {2,5-Xylenol},
2,6-Dichlorophenol, 2,6-Dimethylphenol :- {2,6-Xylenol}, 2-Butanol :- {Butan-2-ol}, 2-Chlorophenol, 2-Chlorotoluene :- {1-Chloro-2-methylbenzene}, 2-Ethyl phenol,
2-Methylphenol :- {o-Cresol}, 2-Methylpropan-1-ol :- {Iso-Butanol}, 2-Phenoxypropionic acid :- {PPA}, 2-Propanol :- {iso-Propanol}, 3,4-Dimethylphenol :- {3,4-Xylenol},
3,5-Dimethylphenol :- {3,5-Xylenol}, 3-Chlorophenol, 3-Chlorotoluene :- {3-Chloromethylbenzene}, 3-Methylphenol :- {m-Cresol}, 4-Chloro-3,5-dimethylphenol :- {PCMX}, 
4-Chloro-3-methylphenol :- {p-Chloro-m-cresol}, 4-Chlorophenol, 4-Chlorophenoxyacetic acid, 4-Chlorotoluene :- {1-Chloro-4-methylbenzene}, 4-Methylphenol :- {p-Cresol},
4-Nonylphenol Branched, 4-Phenoxybutyric acid :- {PBA}, 4-tert-Octylphenol (p-tert-Octylphenol),


"

//持久性
"1,2,3-Trichlorobenzene, 1,2,3-Trichloropropane, 1,2,4-Trichlorobenzene, 1,3,5-Trichlorobenzene, 2,2,3,4,4,5,6-Heptabromodiphenyl ether :- {PBDE 183},
2,2,3,4,4,5-Hexabromodiphenyl ether :- {PBDE 138}, 2,2,3,4,4-Pentabromodiphenyl ether :- {PBDE 85}, 2,2,4,4,5,5-Hexabromodiphenyl ether :- {PBDE 153},
2,2,4,4,5,6-Hexabromodiphenyl ether :- {PBDE 154}, 2,2,4,4,5-Pentabromodiphenyl ether :- {PBDE 99}, 2,2,4,4,6-Pentabromodiphenyl ether :- {PBDE 100},
2,2,4,4-Tetrabromodiphenyl ether :- {PBDE 47}, 2,3,4,4-Tetrabromodiphenyl ether :- {PBDE 66}, 2,4,4-TriBromoDiphenylEther, 
"

//物理类
""

//氟化物
"11-chloroeicosafluoro-3-oxaundecane-1-sulfonic acid (F-53B Minor), 2-(N-Ethylperfluorooctanesulfonamido)acetic acid (B), 2-(N-Ethylperfluorooctanesulfonamido)acetic acid (L),
2-(N-Methylperfluorooctanesulfonamido)acetic acid (B), 2-(N-Methylperfluorooctanesulfonamido)acetic acid (L), 2H,2H,3H,3H-Perfluorooctanoic acid, 3-Perfluoroheptylpropanoic acid,
3:3 Fluorotelomer carboxylic acid, 4,8-Dioxa-3H-perfluorononanoic acid (ADONA), 4-Chloro-2-methylphenol :- {p-Chloro-o-cresol}, 4:2 Fluorotelomer sulfonic acid, 6:2 Fluorotelomer sulfonic acid,
8:2 Fluorotelomer sulfonic acid, 9-chlorohexadecafluoro-3-oxanonane-1-sulfonic acid,

"

14 53 14





SELECT DISTINCT determinand_definition
FROM waterdata
WHERE determinand_definition IN (
'1,1,1,2-Tetrachloroethane', '1,1,1-Trichloroethane', '1,1,2,2-Tetrachloroethane', '1,1,2-Trichloroethane', 
'1,1-Dichloroethane', '1,1-Dichloroethylene :- {1,1-Dichloroethene}', '1,1-Dichloropropylene :- {1,1-Dichloropropene}', 
'1,2,3-Trimethylbenzene', '1,2,4-Trimethylbenzene', '1,2-Dibromo-3-chloropropane', '1,2-Dibromoethane', '1,2-Dichlorobenzene',
'1,2-Dichloroethane', '1,2-Dichloropropane', '1,2-Dimethylbenzene :- {o-Xylene}', '1,3,5-Trimethylbenzene :- {Mesitylene}',
'1,3-Dichlorobenzene', '1,3-Dichloropropane', '1,4-Dichlorobenzene', '1-Butanol :- {Butan-1-ol}', '1-Propanol :- {n-Propanol}',
'17alpha ethynyloestradiol :- {EE2}', '17beta oestradiol :- {E2}', '2,2-Dichloropropane', '2,3,5,6-Tetrachloroaniline', 
'2,3,5,6-Tetrachlorothioanisole', '2,3,6-TBA :- {2,3,6-Trichlorobenzoic acid}', '2,3-Dichlorophenol', '2,3-Dimethylphenol :- {2,3-Xylenol}',
'2,4,5-T :- {2,4,5-Trichlorophenoxyacetic acid}', '2,4,5-Trichlorophenol', '2,4,6-Trichlorophenol', '2,4-D :- {2,4-Dichlorophenoxyacetic acid}',
'2,4-DB :- {4-(2,4-dichlorophenoxy)butyric acid}', '2,4-Dichlorophenol', '2,4-Dimethylphenol :- {2,4-Xylenol}', '2,5-Dichlorophenol', '2,5-Dimethylphenol :- {2,5-Xylenol}',
'2,6-Dichlorophenol', '2,6-Dimethylphenol :- {2,6-Xylenol}', '2-Butanol :- {Butan-2-ol}', '2-Chlorophenol', '2-Chlorotoluene :- {1-Chloro-2-methylbenzene}', '2-Ethyl phenol',
'2-Methylphenol :- {o-Cresol}', '2-Methylpropan-1-ol :- {Iso-Butanol}', '2-Phenoxypropionic acid :- {PPA}', '2-Propanol :- {iso-Propanol}', '3,4-Dimethylphenol :- {3,4-Xylenol}',
'3,5-Dimethylphenol :- {3,5-Xylenol}', '3-Chlorophenol', '3-Chlorotoluene :- {3-Chloromethylbenzene}', '3-Methylphenol :- {m-Cresol}', '4-Chloro-3,5-dimethylphenol :- {PCMX}', 
'4-Chloro-3-methylphenol :- {p-Chloro-m-cresol}', '4-Chlorophenol', '4-Chlorophenoxyacetic acid', '4-Chlorotoluene :- {1-Chloro-4-methylbenzene}', '4-Methylphenol :- {p-Cresol}',
'4-Nonylphenol Branched', '4-Phenoxybutyric acid :- {PBA}', '4-tert-Octylphenol :- {p-tert-Octylphenol}', '4-Isopropyltoluene :- {4-methyl-Isopropylbenzene}'
);


SELECT DISTINCT determinand_definition 
FROM waterdata
WHERE determinand_definition = '4-Phenoxybutyric acid :- {PBA}'



SELECT DISTINCT determinand_definition
FROM waterdata
WHERE determinand_definition IN (
'1,2,3-Trichlorobenzene', '1,2,3-Trichloropropane', '1,2,4-Trichlorobenzene', '1,3,5-Trichlorobenzene', '2,2,3,4,4,5,6-Heptabromodiphenyl ether :- {PBDE 183}',
'2,2,3,4,4,5-Hexabromodiphenyl ether :- {PBDE 138}', '2,2,3,4,4-Pentabromodiphenyl ether :- {PBDE 85}', '2,2,4,4,5,5-Hexabromodiphenyl ether :- {PBDE 153}',
'2,2,4,4,5,6-Hexabromodiphenyl ether :- {PBDE 154}', '2,2,4,4,5-Pentabromodiphenyl ether :- {PBDE 99}', '2,2,4,4,6-Pentabromodiphenyl ether :- {PBDE 100}',
'2,2,4,4-Tetrabromodiphenyl ether :- {PBDE 47}', '2,3,4,4-Tetrabromodiphenyl ether :- {PBDE 66}', '2,4,4-TriBromoDiphenylEther'
);


SELECT DISTINCT determinand_definition
FROM waterdata
WHERE determinand_definition IN (
'11-chloroeicosafluoro-3-oxaundecane-1-sulfonic acid (F-53B Minor)', '2-(N-Ethylperfluorooctanesulfonamido)acetic acid (B)', '2-(N-Ethylperfluorooctanesulfonamido)acetic acid (L)',
'2-(N-Methylperfluorooctanesulfonamido)acetic acid (B)', '2-(N-Methylperfluorooctanesulfonamido)acetic acid (L)', '2H,2H,3H,3H-Perfluorooctanoic acid', '3-Perfluoroheptylpropanoic acid',
'3:3 Fluorotelomer carboxylic acid', '4,8-Dioxa-3H-perfluorononanoic acid (ADONA)', '4-Chloro-2-methylphenol :- {p-Chloro-o-cresol}', '4:2 Fluorotelomer sulfonic acid', '6:2 Fluorotelomer sulfonic acid',
'8:2 Fluorotelomer sulfonic acid', '9-chlorohexadecafluoro-3-oxanonane-1-sulfonic acid'
);


SELECT DISTINCT determinand_definition
FROM waterdata
WHERE determinand_definition IN (
);
