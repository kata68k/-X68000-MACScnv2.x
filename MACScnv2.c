#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "usr_style.h"
#include "usr_macro.h"
#include "usr_define.h"

/* �\���̒�` */

enum
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7,
	S8,
	S9,
};

int32_t g_nEffectType = 1;
int32_t g_nEffectFixedWait = 2;

int8_t sStingCMD[10][10] = {	"_G64K",
							"_G256",
							"_G384",
							"_T512",
							"_T512_C4",
							"_T768",
							"_T512_V256",
							"_T256",
							"_G256_V128",
							"_G384_V128",
						};

int32_t g_nFPS=7;

int8_t sStingFPS[9][10] = {	"15",
							"15_X68",
							"20_X68",
							"24",
							"24_NTSC",
							"30",
							"30_NTSC",
							"30_X68",
							"60_X68",
						};
						
int32_t g_nSound = 1;

int8_t sStingPCM[3][16] = {	"",
							"44",
							"22",
							};
							
int8_t sStingBld[6][38] = {	"has060 -t . MACSList.s",
							"has060 -t . -u MACSsrc.s",
							"060high 1",
							"hlk -t --makemcs MACSsrc MACSList",
							"MakeMCS MACSsrc",
							"060high 0"
						};
						
int8_t sStingTitle[32768] = {0};
int8_t sStingComment[32768] = {0};;

						
/* �֐��̃v���g�^�C�v�錾 */
void HelpMessage2(void);
int16_t main(int16_t, int8_t**);

int16_t cnt[3];

/* �֐� */

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MakeTxTp(int16_t start_cnt, int16_t inc_val, int16_t end_cnt)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	int16_t cnt;

	fp = fopen("00_MakeAll_Win.bat", "a");
	
	/* �t�@�C�����J���� */
	switch(g_nEffectType)
	{
	case S0:
	case S5:
		strcpy(fname, "0_MakeTx.bat");
		fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);
		break;
	case S1:
	case S2:
		strcpy(fname, "0_MakeTxTp_Win.bat");
		fprintf(fp, "call %s\n", fname);
		break;
	case S3:
	case S4:
	case S6:
	case S7:
	case S8:
	case S9:
		strcpy(fname, "0_MakeTxTp.bat");
		fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);
		break;
	default:
		break;
	}
	
	fclose (fp);

	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* �t�@�C���ɏ������� */
	fprintf(fp, "\n");
	
	for(cnt = start_cnt; cnt <= end_cnt; cnt += inc_val)
	{
		/* �t�@�C���ɏ������� */
		
		switch(g_nEffectType)
		{
		case S0:
		case S5:
			fprintf(fp, "APICG CG%05d.bmp\n", cnt);
			fprintf(fp, "gvrsave -s%d -oTx%05d\n\n", g_nEffectType, cnt, cnt);
			fprintf(fp, "\n");
			break;
		case S1:
		case S2:
			fprintf(fp, "macscnv.exe CG*.bmp\n");
			cnt = end_cnt + 1;
			break;
		case S3:
		case S4:
		case S6:
		case S7:
		case S8:
		case S9:
			fprintf(fp, "APICG CG%05d.bmp\n", cnt);
			fprintf(fp, "gvrsave -s%d -oTx%05d -pTp%05d\n\n", g_nEffectType, cnt, cnt);
			fprintf(fp, "\n");
			break;
		default:
			break;
		}
	}

	/* �t�@�C������� */
	fclose (fp);
	
	printf("%s ���쐬���܂����B\n",fname);
	
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MakePCM(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* �t�@�C�����J���� */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "1_MakePCM.bat");
	fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);

	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* �t�@�C���ɏ������� */
	fprintf(fp, "pcm3pcm.x AD.WAV AD.PCM\n");
	if(g_nSound > 0)
	{
		fprintf(fp, "pcm3pcm.x AD.WAV AD.S%s\n", sStingPCM[g_nSound]);
	}
	/* �t�@�C������� */
	fclose (fp);
	
	printf("%s ���쐬���܂����B\n",fname);
	printf("---------------------------\n");

	return ret;
}
	
/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MakeLZE(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* �t�@�C�����J���� */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "2_MakeLZE_Win.bat");
	
	fprintf(fp, "call %s\n", fname);
	
	fclose (fp);
	
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* �t�@�C���ɏ������� */
	fprintf(fp, "for %%%%i in (Tx*.) do lze e %%%%i %%%%i.lze\n");
	
	/* �t�@�C������� */
	fclose (fp);
	
	printf("%s ���쐬���܂����B\n",fname);
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MakeLZSA(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* �t�@�C�����J���� */
	fp = fopen("00_MakeAll_Win.bat", "a");

	strcpy(fname, "2_MakeLZSA_Win.bat");
	
	fprintf(fp, "call %s\n", fname);
	
	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* �t�@�C���ɏ������� */
	fprintf(fp, "for %%%%i in (Tx*.) do lzsa -f1 %%%%i %%%%i.lzs\n");
	
	/* �t�@�C������� */
	fclose (fp);
	
	printf("%s ���쐬���܂����B\n",fname);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MACSListS(void)
{
	FILE *fp;
	int16_t ret = 0;
	int8_t fname[256];
	
	
	strcpy(fname, "MACSList.s");
	/* �t�@�C�����J���� */
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	
	/* �t�@�C���ɏ������� */
	fprintf(fp, "i=%d\n", cnt[0]);
	fprintf(fp, "    .rept    %d\n", ((cnt[2]+1)-(cnt[0]))/cnt[1]);
	fprintf(fp, "Tx%%i:: .insert Tx%%i.lzs\n");
	switch(g_nEffectType)
	{
	case S0:
	case S5:
		break;
	case S1:
	case S2:
	case S3:
	case S4:
	case S6:
	case S7:
	case S8:
	case S9:
	fprintf(fp, "Tp%%i:: .insert Tp%%i\n");
		break;
	default:
		break;
	}
	fprintf(fp, "i=i+%d\n", cnt[1]);
	fprintf(fp, "    .endm\n\n");
	if(g_nSound > 0)
	{
		fprintf(fp, "pcmdat:: .insert AD.S%s\n", sStingPCM[g_nSound]);
	}
	fprintf(fp, "pcmend::\n");
	fprintf(fp, "adpcmdat:: .insert AD.PCM\n");
	fprintf(fp, "adpcmend::\n");
	
	/* �t�@�C������� */
	fclose (fp);
	
	printf("%s ���쐬���܂����B\n",fname);

	printf("---------------------------\n");

	return ret;
}


/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MACSsrcS(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* �t�@�C�����J���� */
	strcpy(fname, "MACSsrc.s");
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	
	fprintf(fp, ".include MACS_SCH.h\n\n");

	fprintf(fp, "SET_OFFSET\n\n");
	
	if(g_nSound > 0)
	{
		fprintf(fp, "USE_DUALPCM 'S%s'\n", sStingPCM[g_nSound]);
	}
	fprintf(fp, "TITLE '%s'\n", sStingTitle);
	fprintf(fp, "COMMENT '%s'\n\n", sStingComment);

	fprintf(fp, "SCREEN_ON%s\n\n", sStingCMD[g_nEffectType]);
	if(g_nFPS < 10)
	{
		fprintf(fp, "SET_FPS%s\n\n", sStingFPS[g_nFPS]);
	}
	else
	{
		fprintf(fp, "SET_FPS %d\n\n", g_nFPS);
	}
	
	
	fprintf(fp, "DRAW Tx%05d\n", cnt[0]);
	fprintf(fp, "WAIT %d\n", g_nEffectFixedWait);
	
	switch(g_nEffectType)
	{
	case S0:
	case S5:
		break;
	case S1:
	case S2:
	case S3:
	case S4:
	case S6:
	case S7:
	case S8:
	case S9:
	fprintf(fp, "PALETTE Tp%05d\n", cnt[0]);
		break;
	default:
		break;
	}
	
	fprintf(fp, "CHANGE_POSITION\n\n");

	if(g_nSound > 0)
	{
		fprintf(fp, "PCM_PLAY_S%s pcmdat,pcmend-pcmdat\n", sStingPCM[g_nSound]);
	}
	fprintf(fp, "PCM_PLAY_SUBADPCM adpcmdat,adpcmend-adpcmdat\n\n");

	fprintf(fp, "i=%d\n", cnt[0]+1);
	fprintf(fp, "    .rept    %d\n", (((cnt[2]+1)-(cnt[0]))/cnt[1]) - 1);
	fprintf(fp, "DRAW Tx%%i\n");
	fprintf(fp, "WAIT 2\n");
	
	switch(g_nEffectType)
	{
	case S0:
	case S5:
		break;
	case S1:
	case S2:
	case S3:
	case S4:
	case S6:
	case S7:
	case S8:
	case S9:
	fprintf(fp, "PALETTE Tp%%i\n");
		break;
	default:
		break;
	}
	
	fprintf(fp, "CHANGE_POSITION\n");
	fprintf(fp, "i=i+%d\n", cnt[1]);
	fprintf(fp, "    .endm\n\n");
	
	fprintf(fp, "WAIT 60\n");
	fprintf(fp, "PCM_STOP\n");
	fprintf(fp, "EXIT\n");
	
	/* �t�@�C������� */
	fclose (fp);

	printf("%s ���쐬���܂����B\n",fname);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MACSbuild(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* �t�@�C�����J���� */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "3_MakeMACS.bat");
	
	fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);
	
	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("�t�@�C�������ɑ��݂��܂��B(%s)\n", fname);
		printf("__Clean.bat �����s���Ă�������\n");
		/* �t�@�C������� */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	
	fprintf(fp, "%s\n", sStingBld[0]);
	fprintf(fp, "%s\n", sStingBld[1]);
	fprintf(fp, "%s\n", sStingBld[2]);
	fprintf(fp, "%s\n", sStingBld[3]);
//	fprintf(fp, "%s\n", sStingBld[4]);	/* �ŐV��hlk�Ɏ������ꂽ�̂ŕs�v */
	fprintf(fp, "%s\n", sStingBld[5]);

	/* �t�@�C������� */
	fclose (fp);

	printf("%s ���쐬���܂����B\n",fname);
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t MakeStatus(void)
{
	int16_t ret = 0;
	
	printf("---------------------------\n");
	puts("�g���O���t�B�b�N���[�h");
	switch(g_nEffectType)
	{
	case S0:
			puts("Mode=0 as 256x256 color 65536");
		break;
	case S1:
			puts("Mode=1 as 256x256 color 256");
		break;
	case S2:
			puts("Mode=2 as 384x256 color 256");
		break;
	case S3:
			puts("Mode=3 as 512x512 color 16");
		break;
	case S4:
			puts("Mode=4 as 512x512 color 4");
		break;
	case S5:
			puts("Mode=5 as 768x512 color 1");
		break;
	case S6:
			puts("Mode=6 as 512x512 color 16");
		break;
	case S7:
			puts("Mode=7 as 256x256 color 16");
		break;
	case S8:
			puts("Mode=8 as 256x128 color 256");
		break;
	case S9:
			puts("Mode=9 as 384x128 color 256");
		break;
	default:
			printf("���m��Mode�ł�=%d\n", g_nEffectType );
		break;
	}
	printf("---------------------------\n");

	puts("�T�E���h���[�h");
	switch(g_nSound)
	{
	case 0:
			puts("-M0 ADPCM");
		break;
	case 1:
			puts("-M1 ADPCM/PCM S44");
		break;
	case 2:
			puts("-M2 ADPCM/PCM S22");
		break;
	default:
			printf("���m�̃T�E���h���[�h�ݒ�ł�=%d\n", g_nSound );
		break;
	}
	printf("---------------------------\n");

	puts("�t���[�����[�g");
	switch(g_nFPS)
	{
	case 0:
	printf("-F0 15.0   fps\n");
		break;
	case 1:
	printf("-F1 13.865 fps 31kHz\n");
		break;
	case 2:
	printf("-F2 18.486 fps 31kHz\n");
		break;
	case 3:
	printf("-F3 24.0   fps\n");
		break;
	case 4:
	printf("-F4 23.976 fps\n");
		break;
	case 5:
	printf("-F5 30.0   fps\n");
		break;
	case 6:
	printf("-F6 29.97  fps(default)\n");
		break;
	case 7:
	printf("-F7 27.729 fps\n");
		break;
	case 8:
	printf("-F8 55.458 fps\n");
		break;
	default:
			printf("�t���[�����[�g=%f.3 fps\n", (float)g_nFPS/1000 );
		break;
	}
	printf("---------------------------\n");
	
	printf("CG%05d �` CG%05d �܂� %d ����������o�b�`�t�@�C�����쐬���܂�(���v�F%d��)\n", cnt[0], cnt[2], cnt[1],((cnt[2]+1)-(cnt[0]))/cnt[1]);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage2(void)
{
	printf("MACScnv.x -S[n] -M[n] -F[n] <�J�n�ԍ�> <�I���ԍ�>\n");
	printf("ex.CG10000.bmp�`CG11620.bmp�̉摜���30fps��256x256 color 256�̉𑜓xMACS�����ꍇ\n");
	printf(">MACScnv.x -S1 -F5 10000 11620\n");
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_S(void)
{
	printf("-S0 256x256 65536�F  \n");
	printf("-S1 256x256 256�F  (default)\n");
	printf("-S2 384x256 256�F  \n");
	printf("-S3 512x512 16�F  \n");
	printf("-S4 512x512 4�F  \n");
	printf("-S5 768x512 1�F  \n");
	printf("-S6 512x512 16�F  \n");
	printf("-S7 256x256 16�F  \n");
	printf("-S8 256x128 256�F \n");
	printf("-S9 384x128 256�F \n");
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_M(void)
{
	printf("-M0 ADPCM only\n");
	printf("-M1 ADPCM+PCM 44kHz (default)\n");
	printf("-M2 ADPCM+PCM 22kHz \n");
}
/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_F(void)
{
	printf("-F0 15.0   fps\n");
	printf("-F1 13.865 fps 31kHz\n");
	printf("-F2 18.486 fps 31kHz\n");
	printf("-F3 24.0   fps\n");
	printf("-F4 23.976 fps\n");
	printf("-F5 30.0   fps\n");
	printf("-F6 29.97  fps\n");
	printf("-F7 27.729 fps(default)\n");
	printf("-F8 55.458 fps\n");
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_T_C(void)
{
	printf("-T <�^�C�g��>\n");
	printf("-C <�R�����g>\n");
}


/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_BAT(void)
{
	printf("�ϊ��ɕK�v�ȃc�[�����t�@�C���F\n");
	printf("=< 0_MakeTxTp.bat/0_MakeTx.bat>=<-S1,-S2>�ȊO==\n");
	printf("    �摜�\���@�@�@�@�FAPICG.r\n");
	printf("    �摜�ۑ��@�@�@�@�Fgvrsave.x\n");
	printf("=< 0_MakeTxTp_Win.bat >=<-S1,-S2>==============\n");
	printf("    �摜�ϊ��ۑ��@�@�Fmacscnv.exe\n");
	printf("=< 1_MakePCM.bat >=============================\n");
	printf("    Wav to ADPCM�@�@�Fpcm3pcm.x\n");
//	printf("=< 2_MakeLZE_Win.bat >=========================\n");
//	printf("    �摜���k�@�@�@�@�Flze.exe\n");
	printf("=< 2_MakeLZSA_Win.bat >========================\n");
	printf("    �摜���k�@�@�@�@�Flzsa.exe\n");
	printf("=< 3_MakeMACS.bat >============================\n");
	printf("    MACS�w�b�_�@�@�@�FMACS_SCH.h\n");
	printf("    �A�Z���u���@�@�@�Fhas060.x\n");
	printf("    �����J�@�@�@�@�@�Fhlk.r\n");
	printf("    MACS�f�[�^�ϊ��@�FMakeMCS.x\n");
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_Sept(void)
{
	printf("-----------------------------------------------\n");
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
void HelpMessage_Key(void)
{
	printf("Hit Any Key\n");
	getchar();
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t Option(int16_t argc, int8_t** argv)
{
	int16_t ret = -1;
	
	int16_t i;
	int8_t	bStrFlag[2] = {FALSE};
	
	for(i = 1; i < argc; i++)
	{
		int8_t	bOption;
		int8_t	bFlag;
		int16_t	Flag2;
		
		bOption	= ((argv[i][0] == '-') || (argv[i][0] == '/')) ? TRUE : FALSE;	/* �P������ */

		if(bOption == TRUE)
		{
			/* �O���t�B�b�N�g�����[�h */
			bFlag	= ((argv[i][1] == 's') || (argv[i][1] == 'S')) ? TRUE : FALSE;	/* �Q������ */
			Flag2	= strlen(&argv[i][2]);	/* �R�����ڂ̒��� */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nEffectType = atoi(&argv[i][2]);
				if(g_nEffectType < 0)			g_nEffectType = 255;
				else if(g_nEffectType > 255)	g_nEffectType = 255;
				
				g_nEffectFixedWait = 2;	/* wait��2�ŌŒ� */
				
				continue;
			}
			
			/* �����̃T���v�����O���[�g�i�܁[�����[��ɂ��Ɓj */
			bFlag	= ((argv[i][1] == 'm') || (argv[i][1] == 'M')) ? TRUE : FALSE;	/* �Q������ */
			Flag2	= strlen(&argv[i][2]);	/* �R�����ڂ̒��� */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nSound = atoi(&argv[i][2]);
				if(g_nSound <= 0)		g_nSound = 0;
				else if(g_nSound > 2)	g_nSound = 1;
				
				continue;
			}
			
			/* �t���[�����[�g */
			bFlag	= ((argv[i][1] == 'f') || (argv[i][1] == 'F')) ? TRUE : FALSE;	/* �Q������ */
			Flag2	= strlen(&argv[i][2]);	/* �R�����ڂ̒��� */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nFPS = atoi(&argv[i][2]);
				if(g_nFPS <= 0)		g_nFPS = 0;
				else if(g_nFPS > 10000);
				else if(g_nFPS > 10)	g_nFPS *= 1000;
				
				continue;
			}
			
			/* �^�C�g�� */
			bFlag	= ((argv[i][1] == 't') || (argv[i][1] == 'T')) ? TRUE : FALSE;	/* �Q������ */
			if(bFlag == TRUE)
			{
				bStrFlag[0] = TRUE;
				continue;
			}
			
			/* �R�����g */
			bFlag	= ((argv[i][1] == 'c') || (argv[i][1] == 'C')) ? TRUE : FALSE;	/* �Q������ */
			if(bFlag == TRUE)
			{
				bStrFlag[1] = TRUE;
				continue;
			}
			
			/* �����ϊ����� */
			bFlag	= ((argv[i][1] == 'q') || (argv[i][1] == 'Q')) ? TRUE : FALSE;
			if(bFlag == TRUE)
			{
				ret = 1;
				break;
			}
			
			/* �w���v�\�� */
			bFlag	= ((argv[i][1] == '?') || (argv[i][1] == 'h') || (argv[i][1] == 'H')) ? TRUE : FALSE;
			if(bFlag == TRUE)
			{
				HelpMessage2();	/* �w���v2 */
				HelpMessage_Sept();
				HelpMessage_S();
				HelpMessage_Sept();
				HelpMessage_M();
				HelpMessage_Sept();
				HelpMessage_F();
				HelpMessage_Key();
				HelpMessage_Sept();
				HelpMessage_T_C();
				HelpMessage_Sept();
				HelpMessage_BAT();
				HelpMessage_Sept();
				ret = -1;
				break;
			}
			
			puts("�I�v�V�����G���[");
			HelpMessage2();	/* �w���v2 */
			
			ret = -1;
			break;
		}
		else
		{
			if(bStrFlag[0] == TRUE)			/* �^�C�g��������擾 */
			{
				bStrFlag[0] = FALSE;
				
				Flag2 = strlen(&argv[i][0]);	/* ���̕�����̒��� */
				if(Flag2 > 0)
				{
					memset(sStingTitle, 0, sizeof(sStingTitle));
					memcpy(sStingTitle, &argv[i][0], Flag2 );
					printf("TITLE:%s\n", sStingTitle);
				}
			}
			else if(bStrFlag[1] == TRUE)	/* �R�����g������擾 */
			{
				bStrFlag[1] = FALSE;
				
				Flag2 = strlen(&argv[i][0]);	/* ���̕�����̒��� */
				if(Flag2 > 0)
				{
					memset(sStingComment, 0, sizeof(sStingComment));
					memcpy(sStingComment, &argv[i][0], Flag2);
					printf("COMMENT:%s\n", sStingComment);
				}
			}
			else
			{
				cnt[0] = atoi(argv[i+0]);
				cnt[1] = 1;
				cnt[2] = atoi(argv[i+1]);
				
				/* �����`�F�b�N */
				if(argc > 2)	/* �I�v�V�����`�F�b�N */
				{
					if( (cnt[0] > cnt[2]) )
					{
						ret = -1;
						break;
					}
					else
					{
						break;
					}
				}
				else
				{
					ret = -1;
				}
			}
		}
	}
		
	return ret;
}

/*===========================================================================================*/
/* �֐���	�F	*/
/* ����		�F	*/
/* �߂�l	�F	*/
/*-------------------------------------------------------------------------------------------*/
/* �@�\		�F	*/
/*===========================================================================================*/
int16_t main(int16_t argc, int8_t** argv)
{
	int16_t ret = 0;
	
	puts("����ɉ���MACS�f�[�^�쐬�⏕�c�[���uMACScnv2.x�v v2.02 (c)2022-2023 �J�^");

	ret = Option(argc, argv);	/* �I�v�V�����`�F�b�N */
	
	switch(ret)
	{
	case 1:
		{
			int32_t num;
			
			HelpMessage_S();
			printf("Input Num[0-9]:-S");
			scanf("%d", &g_nEffectType);
			if(g_nEffectType < 0)			g_nEffectType = 255;
			else if(g_nEffectType > 255)	g_nEffectType = 255;
			g_nEffectFixedWait = 2;	/* wait��2�ŌŒ� */

			HelpMessage_Sept();
			HelpMessage_M();
			printf("Input Num[0-2]:-M");
			scanf("%d", &g_nSound);
			if(g_nSound <= 0)		g_nSound = 0;
			else if(g_nSound > 2)	g_nSound = 1;
			
			HelpMessage_Sept();
			HelpMessage_F();
			printf("Input Num[0-8 or >10]:-F");
			scanf("%d", &g_nFPS);
			if(g_nFPS <= 0)		g_nFPS = 0;
			else if(g_nFPS > 10000);
			else if(g_nFPS > 10)	g_nFPS *= 1000;
			
			HelpMessage_Sept();
			HelpMessage_T_C();
			printf("Input Title  :-T ");
			scanf("%s", &sStingTitle[0]);
			
			printf("Input Comment:-C ");
			scanf("%s", &sStingComment[0]);
			
			HelpMessage_Sept();
			printf("Input CG Start number:CG");
			scanf("%d", &num);
			cnt[0] = (int16_t)num;

			cnt[1] = 1;
			
			printf("Input CG End   number:CG");
			scanf("%d", &num);
			cnt[2] = (int16_t)num;
		}
	case 0:
		{
			MakeStatus();	/* ���ꂩ���낤�Ƃ��Ă��铮��̐ݒ��� */
			
			MakeTxTp(cnt[0], cnt[1], cnt[2]);	/* �摜�ϊ�BAT�t�@�C������ */
			MakePCM();							/* �����ϊ�BAT�t�@�C������ */
	//		MakeLZE();							/* ���kBAT�t�@�C������ */
			MakeLZSA();							/* ���kBAT�t�@�C������ */
			MACSListS();						/* MACSList.s���� */
			MACSsrcS();							/* MACSsrc.s���� */
			MACSbuild();						/* �r���h�pBAT�t�@�C������ */
			
			break;
		}
	default:
		{
			HelpMessage2();	/* �w���v2 */
			HelpMessage_Sept();
			HelpMessage_S();
			HelpMessage_Sept();
			HelpMessage_M();
			HelpMessage_Sept();
			HelpMessage_F();
			HelpMessage_Key();
			HelpMessage_Sept();
			HelpMessage_T_C();
			HelpMessage_Sept();
			HelpMessage_BAT();
			HelpMessage_Sept();
			break;
		}
	}
	
	return ret;
}


