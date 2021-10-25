
// SlidersSampleDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "SlidersSample.h"
#include "SlidersSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
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


// CSlidersSampleDlg �_�C�A���O



CSlidersSampleDlg::CSlidersSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSlidersSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// @@
// �X���C�_�[�R���g���[���ɐݒ肳�ꂽ�ϐ��������ɒ�`����Ă���
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


// CSlidersSampleDlg ���b�Z�[�W �n���h���[

BOOL CSlidersSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[�T���v��"));

	// @@
	// �X���C�_�[�͈̔͂�ݒ�
	m_sldr1.SetRange(0, 100);
	m_sldr2.SetRange(0, 200);

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
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

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CSlidersSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CSlidersSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// @@�X���C�_�[�̓���̎擾
// �N���X�r���[��CSlidersSampleDlg��I������
// �v���p�e�B���\�����ꂽ��A�C�R������u���b�Z�[�W�v��I��
// WM_HSCROLL��T���ĉE���̃v���_�E�����j���[��<Add>ON_WM_HSCROLL��I������
// ���́��֐��̃h���K�����ł���̂Œ��g����������
// �_�C�A���O��̂ǂ̃X���C�_�[�����삳��Ă������ɗ���
// �X���C�_�[��pScrollBarde�ŁA�����nSBCode�Ŏ��ʁAnPos����ʒu���擾�ł���
void CSlidersSampleDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B

	switch (pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:	// �X���C�_�[1
		switch (nSBCode)
		{
		case SB_THUMBTRACK:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �h���b�O���Ĉړ���"));
			break;
		case SB_THUMBPOSITION:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �h���b�O���I��"));
			break;
		case SB_PAGELEFT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �{�b�N�X�̍����i�㑤�j���N���b�N"));
			break;
		case SB_PAGERIGHT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �{�b�N�X�̉E���i�����j���N���b�N"));
			break;
		case SB_TOP:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �ō��i�ŏ�j�ւ̃X�N���[������"));
			break;
		case SB_BOTTOM:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �ŉE�i�ŉ��j�ւ̃X�N���[������"));
			break;
		case SB_LINELEFT:
			//case SB_LINEUP:	// �㑤��[��]�{�^����������
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 ���[��[��]�{�^����������"));
			break;
		case SB_LINERIGHT:
			//case SB_LINEDOWN:	// ������[��]�{�^����������
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[1 �E�[��[��]�{�^����������"));
			break;
		default:
			break;
		}
		break;
	case IDC_SLIDER2:	// �X���C�_�[2
		switch (nSBCode)
		{
		case SB_THUMBTRACK:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �h���b�O���Ĉړ���"));
			break;
		case SB_THUMBPOSITION:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �h���b�O���I��"));
			break;
		case SB_PAGELEFT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �{�b�N�X�̍����i�㑤�j���N���b�N"));
			break;
		case SB_PAGERIGHT:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �{�b�N�X�̉E���i�����j���N���b�N"));
			break;
		case SB_TOP:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �ō��i�ŏ�j�ւ̃X�N���[������"));
			break;
		case SB_BOTTOM:
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �ŉE�i�ŉ��j�ւ̃X�N���[������"));
			break;
		case SB_LINELEFT:
		//case SB_LINEUP:	// �㑤��[��]�{�^����������
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 ���[��[��]�{�^����������"));
			break;
		case SB_LINERIGHT:
		//case SB_LINEDOWN:	// ������[��]�{�^����������
			GetDlgItem(IDC_STATIC)->SetWindowTextW(_T("�X���C�_�[2 �E�[��[��]�{�^����������"));
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
