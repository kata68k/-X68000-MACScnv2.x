# �g���O���t�B�b�N���[�h�œ���(MACS�f�[�^)������Ă݂悤�I

# �ڎ�
1. [MACS�Ƃ́H](#anchor1)
1. [MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)�ɂ���](#anchor2)
1. [�H��](#anchor3)
1. [�K�v�Ȋ�](#anchor4)
1. [�����N](#anchor5)
1. [�菇](#anchor6)
	1. [����t�@�C�����������悤�I](#anchor6)
	1. [VideoProc Converter�œ���t�@�C������摜�f�[�^(PNG)���o�͂��悤�I](#anchor7)
	1. [VideoProc Converter�œ���t�@�C�����特���f�[�^(WAV)���o�͂��悤�I](#anchor8)
	1. [IrfanView�Ń��T�C�Y�����F��PNG��BMP�ϊ����悤�I](#anchor9)
	1. [MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)��MACS�f�[�^�쐬�o�b�`�t�@�C�����쐬���悤�I](#anchor10)
	1. [�Đ����Ă݂悤�I](#anchor11)

<a id="anchor1"></a>

MACS�Ƃ́H
------------

#### MACSDRV.doc ���p

>MACS�Ƃ�X680x0�ɂ�����'�A�j���[�V����'�������Ǝ�y�Ɉ������߂ɐ��܂ꂽ  
>�풓�^�̃A�j���[�V�����R���g���[���ł��B

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

>  PCM8A,PCM8pp���Ή����邷�ׂĂ̌`��  

<a id="anchor2"></a>

## MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)�ɂ���
#### �������ƖړI
MACS�f�[�^�́A�v���O����(�A�Z���u��)�{�摜�f�[�^�{�����f�[�^�̑g�ݍ��킹�ł��B  
MACS�f�[�^���͑�ςȂ̂ŁAMACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)�����܂����B  
#### �T�v
�{�c�[��(MACScnv2.x)�́AMACS�f�[�^����邽�߂̕⏕�c�[���ł��B  
�摜�f�[�^�Ɖ����f�[�^��p�ӂ��A�⏕�c�[�����o�͂���o�b�`�t�@�C�������s����΁A  
MACS�f�[�^������d�g�݂ɂȂ��Ă��܂��B  

<a id="anchor3"></a>
------------
### �H��
MACS�f�[�^�쐬�ɂ́A���L�̂Q�H��������܂��B  

   1.***�f�[�^���o �H��***  

Windows�����œ���f�[�^����A�摜�f�[�^�Ɖ����f�[�^�𒊏o���AMACS�f�[�^�̑f�ނ��������܂��B  

   2.***�f�[�^���H �H��***  

| No. | �o�b�`�t�@�C����    | �T�v                                    |
|-----|---------------------|-----------------------------------------|
| 0 | 00_MakeAll_Win.bat ��  | ���LBAT�t�@�C����Windows������s���邽�߂�BAT�t�@�C��<BR>�iWindows�Ŏ��s�j|
| 1-1 | 0_MakeTxTp_Win.bat  | �摜����(-s1,-s2�̂�) �iWindows�Ŏ��s�j |
| 1-2 | 0_MakeTxTp.bat      | �摜����               |
| 1-3 | 0_MakeTx.bat        | �摜����(-s0,-s5�̂�)  |
| 2   | 1_MakePCM.bat       | �����f�[�^�ϊ�  |
| 3   | 2_MakeLZSA_Win.bat  | �摜���k�iWindows�Ŏ��s�j  |
| 4   | 3_MakeMACS.bat      | �A�Z���u���A�����N�AMACS�f�[�^�쐬  |

��L�̂悤��MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)���A�S�̃o�b�`�t�@�C���𐶐����܂��B  
������ォ�珇�ԂɎ��s����MACS�f�[�^�����܂��B  
��XEiJ���g���΁A�S�Ă�BAT�t�@�C����Windows������s���邱�Ƃ��\�ł��B

<a id="anchor4"></a>
### �K�v�Ȋ�
Windows��X68000�ԂŃf�[�^�̂���肪�ł��邱�ƁB
#### Windows �\�t�g�E�F�A
| No.| �c�[����            |Version | �T�v                                |����|
|----|---------------------|--------|-------------------------------------|----|
| 1  | VideoProc Converter | 5.0    |������摜�f�[�^�Ɖ����f�[�^�ɕ���  |�C���^�[�l�b�g|
| 2  | IrfanView           | 4.53   |�����̉摜�f�[�^���ꊇ�ŉ��H�ł���  |�C���^�[�l�b�g|
| 3  | macscnv.exe         | 0.1.7  |MACS�pBMP��Tx/Tp�ϊ��c�[�� v0.1 for Windows |X68K BBS|
| 4  | lzsa.exe            |        |�f�[�^���k                          |�C���^�[�l�b�g|

��AviUtl�ł��v���O�C�������p����Γ����̂��Ƃ��\�ł��B�v��X68000�ŕ\���o����悤�ɂ����OK  

#### X68k �\�t�g�E�F�A
| No.| �c�[����         |Version | �T�v                                |����|
|----|------------------|--------|-------------------------------------|----|
| 1  | FLOATx.X         |x=2,3,4 | ���������_�^(float)��������         |�V�X�e���f�B�X�N�ɓ���|
| 2  | (V)TwentyOne.sys |v1.36c+14 | �����t�@�C������������              |�����N�Q��|
| 3  | MACSDRV.x        |0.15.11 | �풓�^�̃A�j���[�V�����R���g���[��  |X68K BBS|
| 4  | MakeMCS.x        |1.01    | MACS�f�[�^����                      |MACS116.LZH�ɓ���  |
| 5  | 060high.x        |0.10    | �v���O������high�������Ŏ��s        |�����N�Q��|
| 6 | HAS060.x         |3.09+89 | �A�Z���u��                          |�����N�Q��|
| 7 | hlk.r            |3.01+15 | �����J                              |�����N�Q��|
| 8 | pcm3pcm.x        |2.15    | WAV����PCM�֕ϊ�����                |�ǂ��H|
| 9 | MACScnv2.x        |2.01    | MACS�f�[�^�쐬�⏕                  |X68K BBS|

�����̊��̃I�v�V�����ݒ�
DEVICE    = \DEV\060turbo\060turbo.sys -bs512 -cm1 -dv -ld4ma -lr -ls -lt -np -sd -ss -ts512 -xm

#### X68k �w�b�_�t�@�C��
| No.| �t�@�C����       | �T�v                |����               |
|----|------------------|---------------------|-------------------|
| 1  | MACS_sch.h       | MACS�p�w�b�_�t�@�C��|MACSDRV Version 1.16�̏���ɉ����ɓ���  |

#### X68k �n�[�h�E�F�A
�{�́FX68000+PhantomX(030,040,060���[�h�j�AX68030+060turbo�A�������́A�G�~�����[�^ XEiJ(060turbo)��    
�������F�n�C������128MB�ȏ�i�����j  
�g���{�[�h�F�܁[�����[��ɂ��Ɓi�����j  

��Windows�h���C�u��HFS�Ń}�E���g���Ď��{��������  
��Windows�h���C�u��ō�Ƃ��邽�߁A�G�~�����[�^XM6g�ł́A�����p�ł��܂���B  

<a id="anchor5"></a>
### �����N

- [�V�X�e���f�B�X�N](http://retropc.net/x68000/software/sharp/human302/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [MACSDRV](http://retropc.net/x68000/software/movie/macs/macsmoon/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [(V)TwentyOne](http://gorry.haun.org/x68index.html):GORRY����́u�|���o�P�c�w�v...X680x0�̃y�[�W
- [APICG](http://gorry.haun.org/x68index.html):GORRY����́u�|���o�P�c�w�v...X680x0�̃y�[�W
- [HAS](http://http://retropc.net/x68000/software/develop/as/has/):Makoto Kamada�����X68000 LIBRARY�̃y�[�W
- [hlk](https://github.com/kg68k/hlk-ev/releases/):����@�K���Z�������GitHub

<a id="anchor6"></a>
## �菇

---
### 1. ����t�@�C�����������悤�I<BR>
VideoProc Converter�̋@�\���֗��ł��B<BR>
�̌��ł́A�T���܂ł̐��񂪂���܂����AX68000�ł͈�������Ȃ��T�C�Y�Ȃ̂Ŗ�肠��܂���B(��)

<a id="anchor7"></a>
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

<a id="anchor8"></a>
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

<a id="anchor9"></a>
---
### 4. IrfanView�Ń��T�C�Y�����F��PNG��BMP�ϊ����悤�I<BR>
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
�u�J�n�ԍ��v�� 10000<BR>
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
����̗Ⴞ�ƌ��摜��960x720��4:3�̉摜�Ȃ̂ŉ�����256�ɂ���ƍ�����192�ɂȂ�܂��B<BR>
256x192�̉摜����256x256�ɃT�C�Y��ύX����ɂ́A<BR>
����������ĂȂ��̂ŏ㉺32�s�N�Z�������₷�B<BR>
�uCanvas Color�v�́A���ɂ��Ă����܂��傤�B<BR>
![���H1](img/CG10.png)<BR>
���Ɍ��摜��1280x720��16:9�̉摜�͉�����256�ɂ���ƍ�����144�ɂȂ�܂��B<BR>
256x144�̉摜����256x256�ɃT�C�Y��ύX����ɂ́A<BR>
����������ĂȂ��̂ŏ㉺56�s�N�Z�������₷�悤�ɂ��܂�<BR>
---
�u���ׂĒǉ��v�������āu��ƃt�@�C���̐��v�ɓo�^����B<BR>
�u���בւ��v�������āA�u�����̖��O�v��I�����A�t�@�C�������P���珇�Ԃɕ��Ԃ悤�ɂ���B<BR>
![���H1](img/CG5.png)<BR>
---
�u�ݒ�̍�Ə����ŕҏW�v�Ƀ`�F�b�N�����āu���ʐݒ�v�������B
![���H1](img/CG14.png)<BR>
�u�T�C�Y�ύX�v���u�L�����o�X�T�C�Y�ύX�v���u�\���F�ύX�v�̏��ɐݒ肷��B
![���H1](img/CG13.png)<BR>
���u�ݒ���t�@�C���ɂĕۑ��v�Őݒ�t�@�C����ۑ�����Ƃ����ł��傤�B
---
�S�Đݒ�ł�����u���s�v�������B
![���H1](img/CG6.png)<BR>
---
�A�X�y�N�g�䂪�ێ����ꂽBMP�摜���ł���B<BR>
![���H2](img/CG12.png)<BR>

<a id="anchor10"></a>
---
### 5. MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)��MACS�f�[�^�쐬�o�b�`�t�@�C�����쐬���悤�I<BR>
X68000�̃G�~�����[�^���N�����āA�ϊ�����BMP���u���Ă���p�X�Ɉړ�����B<BR>
MACScnv2.x�AMACS_SCH.h�Amacscnv.exe�Alzsa.exe xeijwin.dll���R�s�[���Ă����B<BR>
�ϊ��ŕK�v�ȃc�[���́A�o�b�`�t�@�C���̃R�}���h�����s�ł���悤��PATH�ݒ肵�Ă����B<BR>
![MACS](img/MC1.png)<BR>
---
MACS�f�[�^�쐬�⏕�c�[���iMACScnv2.x)�����s����B<BR>
�f�[�^�̃t�H�[�}�b�g  
>    -S0�@256x256 65536�F  
>    -S1�@256x256 256�F  (default)  
>    -S2�@384x256 256�F  
>    -S3�@512x512 16�F  
>    -S4�@512x512 4�F  
>    -S5�@768x512 1�F  
>    -S6�@512x512 16�F  
>    -S7�@256x256 16�F  
---
�����̃t�H�[�}�b�g  
>    -M0�@ADPCM only  
>    -M1�@ADPCM+PCM 44kHz (default)  
>    -M2�@ADPCM+PCM 22kHz  
---
�t���[�����[�g  
>    -F0�@15.0   fps  
>    -F1�@13.865 fps 31kHz  
>    -F2�@18.486 fps 31kHz  
>    -F3�@24.0   fps  
>    -F4�@23.976 fps  
>    -F5�@30.0   fps  
>    -F6�@29.97  fps  
>    -F7�@27.729 fps(default)  
>    -F8�@55.458 fps  
>    -F���l  �C�ӂ�fps ��  <BR>
      ex1: 20fps�̓���Ȃ� -F20    �iS/W����1000�{���Ă܂��j <BR>
      ex2: 28.456fps�̓���Ȃ� -F20456   <BR>
      �����l��10���傫���l����͂�������  <BR>
---
�^�C�g���ƃR�����g  
>    -T <�^�C�g��>  
>    -C <�R�����g>  
---
���L�̗Ⴞ��1944����256x256�T�C�Y��256�F�̉摜�� ADPCM��PCM 44kHz���g����MACS�f�[�^�����Ƃ���<BR>
�������� �� 256x256 256�F<BR>
�������� �� ADPCM+PCM 44kHz<BR>
����O���� �� 24 fps  <BR>
�@�@�@�@�@�@�@�@�@�@�@���́H-F3��I�������̂��H 1944[f]��81[s]��24[fps]���<BR>
����l���� �� CC_sakura_OP<BR>
����܈��� �� moe<BR>
����Z���� �J�n�ԍ��� �ŏ��̉摜�t�@�C������CG10000�Ȃ�10000<BR>
���掵���� �I���ԍ��� �Ō�̉摜�t�@�C������CG11943�Ȃ�11943<BR>

���s����ƃo�b�`�t�@�C���ƃo�C�i���t�@�C�����X�g�A�A�Z���u���\�[�X���쐬�����B<BR>
![MACS](img/MC3.png)<BR>
-T�I�v�V�����A-C�I�v�V�������g��Ȃ��Ă��A���MACSsrc.s���e�L�X�g�G�f�B�^�ŊJ����TITLE��COMMENT��ҏW���Ă��悢�B<BR>

��MACScnv2.x -q �Ŏ��s����ƁA�Θb���ŃI�v�V�����ݒ�ł���悤�ɂȂ����̂ŁA�I�v�V�����ݒ���o���ĂȂ��Ă��ł��܂��B(��)
![MACS](img/MC3-1.png)<BR>

---
(�����ō��ꍇ)  
XEiJ��060turbo��������΁AXEiJ�N����AHFS�h���C�u����MACS�̑f�ނ�����t�H���_�Ɉړ����Ă��������B  
Windows����u00_MakeAll_Win.bat�v�����s����ƁA��͉��������AMACS�f�[�^������悤�ɂȂ�܂��B
![MACS](img/MC4-1.png)<BR>
---
(�蓮�ō��ꍇ)  
0_MakeTxTp_Win.bat�����s���āAMACS�f�[�^�ɕK�v�ȉ摜�����B<BR>
�i_Win.bat�����t�@�C�����́AWindows�̃G�N�X�v���[���[������s�j<BR>
�I���I�v�V��������ł́AX68000�ō�Ƃ���K�v����<BR>
![MACS](img/MC5.png)<BR>
���┚���I�I
![MACS](img/MC6.png)<BR>
---
1_MakePCM.bat�����s���āAWAV�t�@�C����ADPCM�Ƃ܁[�����[��ɂ��Ƃ̃f�[�^�ɕϊ�����<BR>
![MACS](img/MC6-1.png)<BR>
---
2_MakeLZSA_Win.bat�����s���ĉ摜�����k����B<BR>
�i_Win.bat�����t�@�C�����́AWindows�̃G�N�X�v���[���[������s�j<BR>
![MACS](img/MC7.png)<BR>
������������������Ԃ������邪�AX68000�ō�Ƃ����������<BR>
![MACS](img/MC7-1.png)<BR>
---
3_MakeMACS.bat�����s���āA�A�Z���u���A�����N(�R���o�[�g)�AMACS�f�[�^�����s��<BR>
MACSsrc.MCS�t�@�C�����쐬�����B  
�������Ńn�C���������K�v�ɂȂ�܂��B�쐬����f�[�^�̔{�T�C�Y�̃��������K�v�ł��B<BR>
���t�@�C�����iMACSsrc.MCS�j�́A���ƂœK���Ƀ��l�[�����܂��傤�B<BR>
![MACS](img/MC8-1.png)<BR>

<a id="anchor11"></a>
---
### 6. �Đ����Ă݂悤�I<BR>
#### MACS�h���C�o���풓���悤�I
PCM8A.X �������́APCM8PP.X���풓��������ɁAMACSDRV.X���풓����B<BR>
![MACS](img/MC9.png)<BR>
#### ������Đ����悤�I
\>MACSplay.x MACSsrc.MCS<BR>
![MACS](img/MC9-1.png)<BR>
���悪�Đ��ł����犮���ł��I<BR>
![MACS](img/MC9-2.png)<BR>
---
# �����
