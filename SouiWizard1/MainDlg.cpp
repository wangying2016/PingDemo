// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "MainDlg.h"
#include <windows.h>
#include "Ping/ping.h"
#include "Ping/DNSLookup.h"
	
#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
#define PINGTEST 1000
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
	, m_bPing(FALSE)
{
	m_bLayoutInited = FALSE;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	// 创建listview
	SListView *pLstViewFix = FindChildByName2<SListView>("lv_ping_result");
	if (pLstViewFix) {
		CPingResultAdapter *pAdapter = new CPingResultAdapter(m_vecPingResult);
		pLstViewFix->SetAdapter(pAdapter);
		pAdapter->Release();
	}

	return 0;
}

HRESULT CMainDlg::_PingTest()
{
	// 获取URL
	/*SOUI::SWindow *pEdit = FindChildByName2<SOUI::SWindow>(L"edit_ping");
	assert(pEdit);
	SStringT strURL = pEdit->GetWindowText();
	LPTSTR pf = (LPTSTR)(LPCTSTR)strURL;
	char *url = (char *)malloc(2 * wcslen(pf) + 1);
	wcstombs(url, pf, 2 * wcslen(pf) + 1);*/
	char *url = "";
	if (m_vecIP.size() > 0) {
		url = (LPSTR)m_vecIP[0].c_str();
	}
	// ping
	CPing objPing;
	PingReply reply;
	CPingReresult result;
	objPing.Ping(url, &reply);
	result.detiIp = url;
	result.bytes = reply.m_dwBytes;
	result.time = reply.m_dwRoundTripTime;
	result.ttl = reply.m_dwTTL;
	m_vecPingResult.push_back(result);
	SListView *pLstViewFix = FindChildByName2<SListView>("lv_ping_result");
	if (pLstViewFix) {
		CPingResultAdapter *pAdapter = static_cast<CPingResultAdapter*>(pLstViewFix->GetAdapter());
		pAdapter->UpdateResult(m_vecPingResult);
		pAdapter->notifyDataSetChanged();
	}
	INT nMin = 0;
	INT nMax = 0;
	pLstViewFix->GetScrollRange(TRUE, &nMin, &nMax);
	pLstViewFix->SetScrollPos(TRUE, nMax, TRUE);

	return S_OK;
}

void  CMainDlg::OnPingButtonClick()
{
	// 判断输入是否有效
	SOUI::SWindow *pEdit = FindChildByName2<SOUI::SWindow>(L"edit_ping");
	assert(pEdit);
	SStringT strURL = pEdit->GetWindowText();
	SStringT strText = strURL.Trim();
	if (0 == strText.GetLength()) {
		SMessageBox(GetActiveWindow(), L"请输入URL", L"提示", MB_OK);
		return;
	}
	// 解析DNS
	LPTSTR pf = (LPTSTR)(LPCTSTR)strURL;
	char *url = (char *)malloc(2 * wcslen(pf) + 1);
	wcstombs(url, pf, 2 * wcslen(pf) + 1);
	if (S_FALSE == _GetDNS(url)) {
		return;
	}
	// 开始计时
	m_bPing = !m_bPing;
	if (TRUE == m_bPing) {
		SetTimer(PINGTEST, 1000);
	}
	// 结束计时
	else {
		KillTimer(PINGTEST);
		m_bPing = FALSE;
	}
}

void CMainDlg::OnTimer(UINT_PTR idEvent)
{
	switch (idEvent) {
	case PINGTEST:
	{
		_PingTest();
	}
	break;
	}
}

HRESULT CMainDlg::_GetDNS(char *strURL)
{
	ULONG ulTimeSpent = 0;
	CDNSLookup dnslookup;
	std::vector<std::string> vecCNameList;
	BOOL bRet = dnslookup.DNSLookup(inet_addr("114.114.114.114"), strURL, &m_vecIP, &vecCNameList, 1000, &ulTimeSpent);

	if (!bRet) {
		SMessageBox(GetActiveWindow(), L"查询DNS失败", L"提示", MB_OK);
		return S_FALSE;
	} else {
		return S_OK;
	}
}

//TODO:消息映射
void CMainDlg::OnClose()
{
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

