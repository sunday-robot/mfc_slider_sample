
// SlidersSample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CSlidersSampleApp:
// このクラスの実装については、SlidersSample.cpp を参照してください。
//

class CSlidersSampleApp : public CWinApp
{
public:
	CSlidersSampleApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CSlidersSampleApp theApp;