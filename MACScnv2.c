#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "usr_style.h"
#include "usr_macro.h"
#include "usr_define.h"

/* 構造体定義 */

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

						
/* 関数のプロトタイプ宣言 */
void HelpMessage2(void);
int16_t main(int16_t, int8_t**);

int16_t cnt[3];

/* 関数 */

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MakeTxTp(int16_t start_cnt, int16_t inc_val, int16_t end_cnt)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	int16_t cnt;

	fp = fopen("00_MakeAll_Win.bat", "a");
	
	/* ファイルを開ける */
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
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* ファイルに書き込む */
	fprintf(fp, "\n");
	
	for(cnt = start_cnt; cnt <= end_cnt; cnt += inc_val)
	{
		/* ファイルに書き込む */
		
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

	/* ファイルを閉じる */
	fclose (fp);
	
	printf("%s を作成しました。\n",fname);
	
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MakePCM(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* ファイルを開ける */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "1_MakePCM.bat");
	fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);

	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* ファイルに書き込む */
	fprintf(fp, "pcm3pcm.x AD.WAV AD.PCM\n");
	if(g_nSound > 0)
	{
		fprintf(fp, "pcm3pcm.x AD.WAV AD.S%s\n", sStingPCM[g_nSound]);
	}
	/* ファイルを閉じる */
	fclose (fp);
	
	printf("%s を作成しました。\n",fname);
	printf("---------------------------\n");

	return ret;
}
	
/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MakeLZE(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* ファイルを開ける */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "2_MakeLZE_Win.bat");
	
	fprintf(fp, "call %s\n", fname);
	
	fclose (fp);
	
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* ファイルに書き込む */
	fprintf(fp, "for %%%%i in (Tx*.) do lze e %%%%i %%%%i.lze\n");
	
	/* ファイルを閉じる */
	fclose (fp);
	
	printf("%s を作成しました。\n",fname);
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MakeLZSA(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* ファイルを開ける */
	fp = fopen("00_MakeAll_Win.bat", "a");

	strcpy(fname, "2_MakeLZSA_Win.bat");
	
	fprintf(fp, "call %s\n", fname);
	
	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	/* ファイルに書き込む */
	fprintf(fp, "for %%%%i in (Tx*.) do lzsa -f1 %%%%i %%%%i.lzs\n");
	
	/* ファイルを閉じる */
	fclose (fp);
	
	printf("%s を作成しました。\n",fname);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MACSListS(void)
{
	FILE *fp;
	int16_t ret = 0;
	int8_t fname[256];
	
	
	strcpy(fname, "MACSList.s");
	/* ファイルを開ける */
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	
	/* ファイルに書き込む */
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
	
	/* ファイルを閉じる */
	fclose (fp);
	
	printf("%s を作成しました。\n",fname);

	printf("---------------------------\n");

	return ret;
}


/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MACSsrcS(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* ファイルを開ける */
	strcpy(fname, "MACSsrc.s");
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
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
	
	/* ファイルを閉じる */
	fclose (fp);

	printf("%s を作成しました。\n",fname);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MACSbuild(void)
{
	FILE *fp;
	int8_t fname[256];
	int16_t ret = 0;
	
	/* ファイルを開ける */
	fp = fopen("00_MakeAll_Win.bat", "a");
	
	strcpy(fname, "3_MakeMACS.bat");
	
	fprintf(fp, "echo %s > \\\\.\\pipe\\XEiJPaste\n", fname);
	
	fclose (fp);
	
	fp = fopen(fname, "r");
	if(fp != NULL)
	{
		printf("ファイルが既に存在します。(%s)\n", fname);
		printf("__Clean.bat を実行してください\n");
		/* ファイルを閉じる */
		fclose (fp);
		return -1;
	}
	
	fp = fopen(fname, "w");
	
	fprintf(fp, "%s\n", sStingBld[0]);
	fprintf(fp, "%s\n", sStingBld[1]);
	fprintf(fp, "%s\n", sStingBld[2]);
	fprintf(fp, "%s\n", sStingBld[3]);
//	fprintf(fp, "%s\n", sStingBld[4]);	/* 最新のhlkに実装されたので不要 */
	fprintf(fp, "%s\n", sStingBld[5]);

	/* ファイルを閉じる */
	fclose (fp);

	printf("%s を作成しました。\n",fname);
	printf("---------------------------\n");

	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t MakeStatus(void)
{
	int16_t ret = 0;
	
	printf("---------------------------\n");
	puts("拡張グラフィックモード");
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
			printf("未知のModeです=%d\n", g_nEffectType );
		break;
	}
	printf("---------------------------\n");

	puts("サウンドモード");
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
			printf("未知のサウンドモード設定です=%d\n", g_nSound );
		break;
	}
	printf("---------------------------\n");

	puts("フレームレート");
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
			printf("フレームレート=%f.3 fps\n", (float)g_nFPS/1000 );
		break;
	}
	printf("---------------------------\n");
	
	printf("CG%05d ～ CG%05d まで %d ずつ処理するバッチファイルを作成します(合計：%d枚)\n", cnt[0], cnt[2], cnt[1],((cnt[2]+1)-(cnt[0]))/cnt[1]);
	printf("---------------------------\n");
	
	return ret;
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage2(void)
{
	printf("MACScnv.x -S[n] -M[n] -F[n] <開始番号> <終了番号>\n");
	printf("ex.CG10000.bmp～CG11620.bmpの画像より30fpsの256x256 color 256の解像度MACSを作る場合\n");
	printf(">MACScnv.x -S1 -F5 10000 11620\n");
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_S(void)
{
	printf("-S0 256x256 65536色  \n");
	printf("-S1 256x256 256色  (default)\n");
	printf("-S2 384x256 256色  \n");
	printf("-S3 512x512 16色  \n");
	printf("-S4 512x512 4色  \n");
	printf("-S5 768x512 1色  \n");
	printf("-S6 512x512 16色  \n");
	printf("-S7 256x256 16色  \n");
	printf("-S8 256x128 256色 \n");
	printf("-S9 384x128 256色 \n");
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_M(void)
{
	printf("-M0 ADPCM only\n");
	printf("-M1 ADPCM+PCM 44kHz (default)\n");
	printf("-M2 ADPCM+PCM 22kHz \n");
}
/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
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
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_T_C(void)
{
	printf("-T <タイトル>\n");
	printf("-C <コメント>\n");
}


/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_BAT(void)
{
	printf("変換に必要なツール＆ファイル：\n");
	printf("=< 0_MakeTxTp.bat/0_MakeTx.bat>=<-S1,-S2>以外==\n");
	printf("    画像表示　　　　：APICG.r\n");
	printf("    画像保存　　　　：gvrsave.x\n");
	printf("=< 0_MakeTxTp_Win.bat >=<-S1,-S2>==============\n");
	printf("    画像変換保存　　：macscnv.exe\n");
	printf("=< 1_MakePCM.bat >=============================\n");
	printf("    Wav to ADPCM　　：pcm3pcm.x\n");
//	printf("=< 2_MakeLZE_Win.bat >=========================\n");
//	printf("    画像圧縮　　　　：lze.exe\n");
	printf("=< 2_MakeLZSA_Win.bat >========================\n");
	printf("    画像圧縮　　　　：lzsa.exe\n");
	printf("=< 3_MakeMACS.bat >============================\n");
	printf("    MACSヘッダ　　　：MACS_SCH.h\n");
	printf("    アセンブラ　　　：has060.x\n");
	printf("    リンカ　　　　　：hlk.r\n");
	printf("    MACSデータ変換　：MakeMCS.x\n");
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_Sept(void)
{
	printf("-----------------------------------------------\n");
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
void HelpMessage_Key(void)
{
	printf("Hit Any Key\n");
	getchar();
}

/*===========================================================================================*/
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
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
		
		bOption	= ((argv[i][0] == '-') || (argv[i][0] == '/')) ? TRUE : FALSE;	/* １文字目 */

		if(bOption == TRUE)
		{
			/* グラフィック拡張モード */
			bFlag	= ((argv[i][1] == 's') || (argv[i][1] == 'S')) ? TRUE : FALSE;	/* ２文字目 */
			Flag2	= strlen(&argv[i][2]);	/* ３文字目の長さ */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nEffectType = atoi(&argv[i][2]);
				if(g_nEffectType < 0)			g_nEffectType = 255;
				else if(g_nEffectType > 255)	g_nEffectType = 255;
				
				g_nEffectFixedWait = 2;	/* waitは2で固定 */
				
				continue;
			}
			
			/* 音声のサンプリングレート（まーきゅりーゆにっと） */
			bFlag	= ((argv[i][1] == 'm') || (argv[i][1] == 'M')) ? TRUE : FALSE;	/* ２文字目 */
			Flag2	= strlen(&argv[i][2]);	/* ３文字目の長さ */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nSound = atoi(&argv[i][2]);
				if(g_nSound <= 0)		g_nSound = 0;
				else if(g_nSound > 2)	g_nSound = 1;
				
				continue;
			}
			
			/* フレームレート */
			bFlag	= ((argv[i][1] == 'f') || (argv[i][1] == 'F')) ? TRUE : FALSE;	/* ２文字目 */
			Flag2	= strlen(&argv[i][2]);	/* ３文字目の長さ */
			if((bFlag == TRUE) && (Flag2 > 0))
			{
				g_nFPS = atoi(&argv[i][2]);
				if(g_nFPS <= 0)		g_nFPS = 0;
				else if(g_nFPS > 10000);
				else if(g_nFPS > 10)	g_nFPS *= 1000;
				
				continue;
			}
			
			/* タイトル */
			bFlag	= ((argv[i][1] == 't') || (argv[i][1] == 'T')) ? TRUE : FALSE;	/* ２文字目 */
			if(bFlag == TRUE)
			{
				bStrFlag[0] = TRUE;
				continue;
			}
			
			/* コメント */
			bFlag	= ((argv[i][1] == 'c') || (argv[i][1] == 'C')) ? TRUE : FALSE;	/* ２文字目 */
			if(bFlag == TRUE)
			{
				bStrFlag[1] = TRUE;
				continue;
			}
			
			/* 逐次変換方式 */
			bFlag	= ((argv[i][1] == 'q') || (argv[i][1] == 'Q')) ? TRUE : FALSE;
			if(bFlag == TRUE)
			{
				ret = 1;
				break;
			}
			
			/* ヘルプ表示 */
			bFlag	= ((argv[i][1] == '?') || (argv[i][1] == 'h') || (argv[i][1] == 'H')) ? TRUE : FALSE;
			if(bFlag == TRUE)
			{
				HelpMessage2();	/* ヘルプ2 */
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
			
			puts("オプションエラー");
			HelpMessage2();	/* ヘルプ2 */
			
			ret = -1;
			break;
		}
		else
		{
			if(bStrFlag[0] == TRUE)			/* タイトル文字列取得 */
			{
				bStrFlag[0] = FALSE;
				
				Flag2 = strlen(&argv[i][0]);	/* 次の文字列の長さ */
				if(Flag2 > 0)
				{
					memset(sStingTitle, 0, sizeof(sStingTitle));
					memcpy(sStingTitle, &argv[i][0], Flag2 );
					printf("TITLE:%s\n", sStingTitle);
				}
			}
			else if(bStrFlag[1] == TRUE)	/* コメント文字列取得 */
			{
				bStrFlag[1] = FALSE;
				
				Flag2 = strlen(&argv[i][0]);	/* 次の文字列の長さ */
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
				
				/* 引数チェック */
				if(argc > 2)	/* オプションチェック */
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
/* 関数名	：	*/
/* 引数		：	*/
/* 戻り値	：	*/
/*-------------------------------------------------------------------------------------------*/
/* 機能		：	*/
/*===========================================================================================*/
int16_t main(int16_t argc, int8_t** argv)
{
	int16_t ret = 0;
	
	puts("勝手に改造MACSデータ作成補助ツール「MACScnv2.x」 v2.02 (c)2022-2023 カタ");

	ret = Option(argc, argv);	/* オプションチェック */
	
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
			g_nEffectFixedWait = 2;	/* waitは2で固定 */

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
			MakeStatus();	/* これから作ろうとしている動画の設定情報 */
			
			MakeTxTp(cnt[0], cnt[1], cnt[2]);	/* 画像変換BATファイル生成 */
			MakePCM();							/* 音声変換BATファイル生成 */
	//		MakeLZE();							/* 圧縮BATファイル生成 */
			MakeLZSA();							/* 圧縮BATファイル生成 */
			MACSListS();						/* MACSList.s生成 */
			MACSsrcS();							/* MACSsrc.s生成 */
			MACSbuild();						/* ビルド用BATファイル生成 */
			
			break;
		}
	default:
		{
			HelpMessage2();	/* ヘルプ2 */
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