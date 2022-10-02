# �g���O���t�B�b�N���[�h�œ���(MACS�f�[�^)������Ă݂悤�I

MACS�Ƃ́H
------------

#### MACSDRV.doc ���p

>MACS�Ƃ�X680x0�ɂ�����'�A�j���[�V����'�������Ǝ�y�Ɉ������߂ɐ��܂ꂽ�풓�^��
>�A�j���[�V�����R���g���[���ł��B

#### MACSDRV Version 1.16�̏���ɉ��� ���p
>�T�v  
>MACS�Ɉȉ��̉��/�������[�h��ǉ����܂��B�i�vHIMEM.SYS�݊�IOCS�{�n�C�������j  
>    -s0     256x256 65536�F (�p���b�g�ۑ�����)  
>    -s1     256x256 256�F  
>    -s2     384x256 256�F   (�vIPLROM1.6)  
>    -s3     512x512 16�F  
>    -s4     512x512 4�F     (�p���b�g��16�F���ۑ�)  
>    -s5     768x512 1�F     (�p���b�g�ۑ�����)  
>    -s6     512x256 16�F  
>    -s7     256x256 16�F    (�I���W�i��MACS�Ɠ�����ʃ��[�h�̉����Łj  

>  PCM8++���Ή����邷�ׂĂ̌`��  


## MACS�f�[�^�쐬�⏕�c�[���iMACScnv.x)�ɂ���
#### �������ƖړI
MACS�f�[�^�́A�v���O����(�A�Z���u��)�{�摜�f�[�^�{�����f�[�^�̑g�ݍ��킹�ł��B  
MACS�f�[�^���͑�ςȂ̂ŁAMACS�f�[�^�쐬�⏕�c�[���iMACScnv.x)�����܂����B  
#### �T�v
�{�c�[��(MACScnv.x)�́AMACS�f�[�^����邽�߂̕⏕�c�[���ł��B  
�摜�f�[�^�Ɖ����f�[�^��p�ӂ��A�⏕�c�[�����o�͂���o�b�`�t�@�C�������s����΁AMACS�f�[�^������d�g�݂ɂȂ��Ă��܂��B  

------------
### �H��
MACS�f�[�^�쐬�ɂ́A���L�̂Q�H��������܂��B  

   1.***�f�[�^���o �H��***  

Windows�����œ���f�[�^����A�摜�f�[�^�Ɖ����f�[�^�𒊏o���AMACS�f�[�^�̑f�ނ��������܂��B  

   2.***�f�[�^���H �H��***  

| No.| �o�b�`�t�@�C����    | �T�v                                |
|----|---------------------|-------------------------------------|
| 1  | 0_MakeTxTp.bat      | �摜����  |
| 2  | 1_MakePCM.bat       | �����f�[�^�ϊ�  |
| 3  | 2_MakeLZE.bat       | �摜���k�iWindows�Ŏ��s�����j  |
| 4  | 3_MakeBLK.bat       | �f�[�^�I�u�W�F�N�g����  |
| 5  | 4_MakeMACS.bat      | �A�Z���u���A�����N�AMACS�f�[�^�쐬  |

��L�̂悤��MACS�f�[�^�쐬�⏕�c�[���iMACScnv.x)���A�T�̃o�b�`�t�@�C���𐶐�����̂ŁA���ԂɎ��s����MACS�f�[�^�����܂��B

### �K�v�Ȋ�
Windows��X68000�ԂŃf�[�^�̂���肪�ł��邱�ƁB
#### Windows �\�t�g�E�F�A
| No.| �c�[����            |Version | �T�v                                |
|----|---------------------|--------|-------------------------------------|
| 1  | VideoProc Converter |        |������摜�f�[�^�Ɖ����f�[�^�ɕ���  |
|    | AviUtl              |0.06    |�A��BMP�o��Plugin  |
|    |                     |        |ResizeFilter  |
| 2  | IrfanView           |        |�����̉摜�f�[�^���ꊇ�ŉ��H�ł���  |

#### X68k �\�t�g�E�F�A
| No.| �c�[����         |Version | �T�v                                |����|
|----|------------------|--------|-------------------------------------|----|
| 1  | FLOATx.X         |        | ���������_�^(float)��������         |�V�X�e���f�B�X�N�ɓ���|
| 2  | (V)TwentyOne.sys |        | �����t�@�C������������              |�����N�Q��|
| 3  | MACSDRV.x        |0.15.11 | �풓�^�̃A�j���[�V�����R���g���[��  |X68K BBS|
| 4  | MakeMCS.x        |1.01    | MACS�f�[�^����                      |MACS116.LZH�ɓ���  |
| 5  | APICG.r          |2.11A   | �摜���[�_�[                        |�����N�Q��|
| 6  | gvrsave.x        |0.2.15   | �摜�Z�[�o�[                        |�����N�Q��|
| 7  | lze.x            |        | �f�[�^���k                          |MACSDRV Version 1.16�̏���ɉ����ɓ���|
| 8  | lze.exe          |        | �f�[�^���k(Windows�p)               |MACSDRV Version 1.16�̏���ɉ����ɓ���|
| 9  | 060high.x        |0.10    | �v���O������high�������Ŏ��s        |�����N�Q��|
| 10 | HAS060.x         |3.09+89 | �A�Z���u��                          |�����N�Q��|
| 11 | hlk.r            |3.01+15 | �����J                              |�����N�Q��|
| 12 | pcm3pcm.x        |2.15    | WAV����PCM�֕ϊ�����                |�ǂ��H|
| 13 | MACScnv.x        |1.04    | MACS�f�[�^�쐬�⏕                  |X68K BBS|

#### X68k �w�b�_�t�@�C��
| No.| �t�@�C����       | �T�v                |����               |
|----|------------------|---------------------|-------------------|
| 1  | MACS_sch.h       | MACS�p�w�b�_�t�@�C��|MACSDRV Version 1.16�̏���ɉ����ɓ���  |

#### X68k �n�[�h�E�F�A
�{�́FX68000+PhantomX(060���[�h�j�AX68030+060turbo�A�������́A�G�~�����[�^ XEiJ(060turbo)  
�������F�n�C������128MB�ȏ�i�����j  
�g���{�[�h�F�܁[�����[��ɂ��Ɓi�����j  
### �����N

- [�V�X�e���f�B�X�N](http://retropc.net/x68000/software/sharp/human302/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [MACSDRV](http://retropc.net/x68000/software/movie/macs/macsmoon/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [(V)TwentyOne](http://gorry.haun.org/x68index.html):GORRY����́u�|���o�P�c�w�v...X680x0�̃y�[�W
- [APICG](http://gorry.haun.org/x68index.html):GORRY����́u�|���o�P�c�w�v...X680x0�̃y�[�W
- [HAS](http://http://retropc.net/x68000/software/develop/as/has/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [hlk](https://github.com/kg68k/hlk-ev/releases/):����@�K���Z�������GitHub

## �菇

---
### 1. �D���ȓ���t�@�C�����������悤�I<BR>
VideoProc Converter�̋@�\���֗��ł��B<BR>
�̌��ł́A�T���܂ł̐��񂪂���܂����AX68000�ł͈�������Ȃ��T�C�Y�Ȃ̂Ŗ�肠��܂���B(��)

---
### 2. VideoProc Converter�œ���t�@�C������摜�f�[�^(PNG)���o�͂��悤�I<BR>
�u�r�f�I�v��I�����܂��B<BR>
![�Î~��](img/GP1.png)<BR>
---
���̃��j���[����u�X�i�b�v�V���b�g�v��I�����܂��B<BR>
![�Î~��](img/GP2.png)<BR>
---
�u��f���v���ő�l�ɂȂ�悤�ɏグ�܂��B�����ړ��͂ł͂Ȃ��A�J�[�\���L�[���APageUp���I�X�X��<BR>
![�Î~��](img/GP3.png)<BR>
---
�E���́u�o�̓t�H���_�v�œK���ȏꏊ��I�����A�uRUN�v�������ĉ摜�𒊏o���܂��B<BR>
![�Î~��](img/GP4.png)<BR>
---
PNG�t�@�C�������o����܂��B<BR>
![�Î~��](img/GP5.png)<BR>

---
### 3. VideoProc Converter�œ���t�@�C�����特���f�[�^(WAV)���o�͂��悤�I<BR>
���̃��j���[����uPCM�v��I�����܂��B<BR>
![����](img/WA1.png)<BR>
---
�I�v�V�����̕ύX�͕s�v�ł��B
![����](img/WA2.png)<BR>
---
WAV�t�@�C�����쐬�����̂ŁA���������uAD.WAV�v�Ƀt�@�C������ύX���������B<BR>
![����](img/WA4.png)<BR>

---
### 4. ���T�C�Y�����F��PNG��BMP�ϊ����悤�I<BR>
�u�t�@�C���v���u�ꊇ�����v<BR>
![���H1](img/CG1.png)<BR>
---
�u�`���ݒ�v�� BMP - Windows Bitmap<BR>
�u���l�[���ݒ�v���uCG#####�v #�͂T��<BR>
�u�t�@�C���Ǘ��t�H���_�v ���u�ϊ���̃t�@�C�����ۑ������Ƃ���v<BR>
�u�t�@�C���̏ꏊ�v���uPNG�t�@�C�����ۑ�����Ă���ꏊ�v<BR>
�u�t�@�C���̎�ށv�� �uPNG - Portable Network Graphics �v<BR>
![���H1](img/CG2.png)<BR>
---
�u�ڍאݒ�v������<BR>
�u�J�n�ԍ��v�� 0<BR>
�u���Z���v �� 1<BR>
![���H1](img/CG3.png)<BR>
---
�u�ǉ��ݒ�v������<BR>
�u�T�C�Y�ύX�v�Ƀ`�F�b�N������<BR>
�u���T�C�Y�v256<BR>
�u�A�X�y�N�g����ێ����� �v�Ƀ`�F�b�N������<BR>
�u�摜�����T���v������v�Ƀ`�F�b�N������<BR>
�u256�F�v��I������<BR>
�u�L�����o�X�T�C�Y�ύX�v�Ƀ`�F�b�N������<BR>
![���H1](img/CG4.png)<BR>
------
�u�L�����o�X�T�C�Y�ύX�v�Ƀ`�F�b�N�������<BR>
�u�ݒ�m�F�v������
�uMethod1�v�́uTop side�v�uBottom side�v���L����<BR>
����̗Ⴞ�� 256x192��256x256�ɃT�C�Y��ύX����ɂ́A<BR>
����������ĂȂ��̂ŏ㉺32�s�N�Z�������₷�B<BR>
�uCanvas Color�v�́A���ɂ��Ă����܂��傤�B<BR>
![���H1](img/CG10.png)<BR>
---
�u���ׂĒǉ��v�������āu��ƃt�@�C���̐��v�ɓo�^����B<BR>
�u���בւ��v�������āA�u�����̖��O�v��I�����A�t�@�C�������P���珇�Ԃɕ��Ԃ悤�ɂ���B<BR>
![���H1](img/CG5.png)<BR>
---
�u�ݒ�̍�Ə����ŕҏW�v�Ƀ`�F�b�N�����āu���ʐݒ�v�������B
![���H1](img/CG14.png)<BR>
�u�T�C�Y�ύX�v���u�L�����o�X�T�C�Y�ύX�v���u�\���F�ύX�v�̏��ɐݒ肷��B
![���H1](img/CG13.png)<BR>
---
�S�Đݒ�ł�����u���s�v�������B
![���H1](img/CG6.png)<BR>
---
�A�X�y�N�g�䂪�ێ����ꂽBMP�摜���ł���B<BR>
![���H2](img/CG12.png)<BR>

---
### 6. MACS�f�[�^�쐬�⏕�c�[���iMACScnv.x)�����s���悤�I<BR>
X68000�̃G�~�����[�^���N�����āA�ϊ�����BMP���u���Ă���p�X�Ɉړ�����B<BR>
MACScnv.x�AMACS_SCH.h�Alze.exe���R�s�[���Ă����B<BR>
�ϊ��ŕK�v�ȃc�[���́A�o�b�`�t�@�C���̃R�}���h�����s�ł���悤��PATH�ݒ肵�Ă����B<BR>
![MACS](img/MC1.png)<BR>
---
MACS�f�[�^�쐬�⏕�c�[���iMACScnv.x)�����s����B<BR>
���L�̗Ⴞ��<BR>
�������� �f�[�^�̃t�H�[�}�b�g�I���� -s1�Ȃ�256x256 256�F��MACS�f�[�^�����B<BR>
�������� �J�n�ԍ��� 0�Ȃ�CG00000���ŏ��̉摜�ɂȂ�B<BR>
����O���� �����l  �� 1�Ȃ�CG00000�ACG00001�ACG00002�ACG00003��+1����������B<BR>
����l���� �I���ԍ��� 1943�Ȃ�CG01943�܂ŏ����ΏۂƂȂ�B<BR>
����܈��� ����̍Đ����� or ����̉����̍Đ����ԁ� ex. 1��21�b�̓���Ȃ�81�b�Ȃ̂�81�Ɠ��͂���B<BR><BR>
����ɂ��A1621��4���S405���̉摜���g����MACS�f�[�^���ł���B�i1�b������5���̉摜�j
�f�[�^�̃t�H�[�}�b�g  
>    -s0     256x256 65536�F (�p���b�g�ۑ�����)  
>    -s1     256x256 256�F  
>    -s2     384x256 256�F   (�vIPLROM1.6)  
>    -s3     512x512 16�F  
>    -s4     512x512 4�F     (�p���b�g��16�F���ۑ�)  
>    -s5     768x512 1�F     (�p���b�g�ۑ�����)  
>    -s6     512x256 16�F  
>    -s7     256x256 16�F    (�I���W�i��MACS�Ɠ�����ʃ��[�h�̉����Łj  
![MACS](img/MC2.png)<BR>
�o�b�`�t�@�C���ƃo�C�i���t�@�C�����X�g�A�A�Z���u���\�[�X���쐬�����B<BR>
![MACS](img/MC3.png)<BR>
MACSsrc.s���G�f�B�^�ŊJ����TITLE��COMMENT��ҏW���Ă����B
![MACS](img/MC3.png)<BR>
---
0_MakeTxTp.bat�����s���āAMACS�f�[�^�ɕK�v�ȉ摜�����B
![MACS](img/MC5.png)<BR>
BMP�摜��ϊ����Ă���l�q�i2000����40�����炢�j<BR>
![MACS](img/MC5-1.png)<BR>
---
1_MakePCM.bat�����s���āAWAV�t�@�C����ADPCM�Ƃ܁[�����[��ɂ��Ƃ̃f�[�^�ɕϊ�����<BR>
![MACS](img/MC6.png)<BR>
�ϊ����Ă�l�q<BR>
![MACS](img/MC6-1.png)<BR>
---
2_MakeLZE.bat�����s���ĉ摜�����k����B�i��������Windows�̃G�N�X�v���[���[������s�j<BR>
![MACS](img/MC7.png)<BR>
������������������Ԃ������邪�AX68000�ō�Ƃ������30�{���炢����<BR>
![MACS](img/MC7-1.png)<BR>
---
3_MakeBLK.bat�����s���ĕϊ����ꂽ�f�[�^���I�u�W�F�N�g�ɕϊ�����i����A���������XEiJ�ō�Ƃ��邱�Ƃ��I�X�X�����܂��j<BR>
![MACS](img/MC10.png)<BR>
�ϊ����Ă���l�q  
���e���|�����ݒ��RAM�f�B�X�N���ɐݒ肵�Ă���ƃT�C�Y������Ȃ��̂�-t <�p�X��>��ǉ����č�Ƃ��Ă���<BR>
![MACS](img/MC10-1.png)<BR>
---
4_MakeMACS�����s���āA�A�Z���u���A�����N(�R���o�[�g)�AMACS�f�[�^�����s��<BR>
![MACS](img/MC8.png)<BR>
MACSsrc.MCS�t�@�C�����쐬�����B  
���t�@�C�����iMACSsrc.MCS�j�́A�K���Ƀ��l�[�����Ă����Ƃ����ł��傤�B<BR>
![MACS](img/MC8-1.png)<BR>

---
### 6. �Đ����Ă݂悤�I<BR>
PCM8A.X �������́APCM8PP.X���풓��������ɁAMACSDRV.X���풓����B<BR>
![MACS](img/MC9.png)<BR>
\>MACSplay.x MACSsrc.MCS<BR>
![MACS](img/MC9-1.png)<BR>
���悪�Đ��ł����犮���ł��I<BR>
![MACS](img/MC9-2.png)<BR>
---
# �����
