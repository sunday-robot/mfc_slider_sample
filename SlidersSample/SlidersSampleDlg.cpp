
// SlidersSampleDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "SlidersSample.h"
#include "SlidersSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSlidersSampleDlg ダイアログ



CSlidersSampleDlg::CSlidersSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSlidersSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// @@
// スライダーコントロールに設定された変数がここに定義されている
void CSlidersSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_sldr1);
	DDX_Control(pDX, IDC_SLIDER2, m_sldr2);
}

BEGIN_MESSAGE_MAP(CSlidersSampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSlidersSampleDlg メッセージ ハンドラー

BOOL CSlidersSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダーサンプル"));

	// @@
	// スライダーの範囲を設定
	m_sldr1.SetRange(0, 100);
	m_sldr2.SetRange(0, 200);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CSlidersSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CSlidersSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CSlidersSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// @@スライダーの動作の取得
// クラスビューでCSlidersSampleDlgを選択する
// プロパティが表示されたらアイコンから「メッセージ」を選択
// WM_HSCROLLを探して右側のプルダウンメニューで<Add>ON_WM_HSCROLLを選択する
// この↓関数のドンガラができるので中身を実装する
// ダイアログ上のどのスライダーが操作されてもここに来る
// スライダーはpScrollBardeで、動作はnSBCodeで識別、nPosから位置を取得できる
void CSlidersSampleDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	switch (pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:	// スライダー1
		switch (nSBCode)
		{
		case SB_THUMBTRACK:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 ドラッグして移動中"));
			break;
		case SB_THUMBPOSITION:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 ドラッグを終了"));
			break;
		case SB_PAGELEFT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 ボックスの左側（上側）をクリック"));
			break;
		case SB_PAGERIGHT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 ボックスの右側（下側）をクリック"));
			break;
		case SB_TOP:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 最左（最上）へのスクロール命令"));
			break;
		case SB_BOTTOM:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 最右（最下）へのスクロール命令"));
			break;
		case SB_LINELEFT:
			//case SB_LINEUP:	// 上側の[∧]ボタンを押した
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 左端の[＜]ボタンを押した"));
			break;
		case SB_LINERIGHT:
			//case SB_LINEDOWN:	// 下側の[∨]ボタンを押した
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー1 右端の[＞]ボタンを押した"));
			break;
		default:
			break;
		}
		break;
	case IDC_SLIDER2:	// スライダー2
		switch (nSBCode)
		{
		case SB_THUMBTRACK:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 ドラッグして移動中"));
			break;
		case SB_THUMBPOSITION:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 ドラッグを終了"));
			break;
		case SB_PAGELEFT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 ボックスの左側（上側）をクリック"));
			break;
		case SB_PAGERIGHT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 ボックスの右側（下側）をクリック"));
			break;
		case SB_TOP:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 最左（最上）へのスクロール命令"));
			break;
		case SB_BOTTOM:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 最右（最下）へのスクロール命令"));
			break;
		case SB_LINELEFT:
		//case SB_LINEUP:	// 上側の[∧]ボタンを押した
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 左端の[＜]ボタンを押した"));
			break;
		case SB_LINERIGHT:
		//case SB_LINEDOWN:	// 下側の[∨]ボタンを押した
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("スライダー2 右端の[＞]ボタンを押した"));
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
