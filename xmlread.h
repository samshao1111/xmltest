// xmlread.h : main header file for the XMLREAD application
//

#if !defined(AFX_XMLREAD_H__4345CACF_AA2D_4F8A_8503_461C37076ACD__INCLUDED_)
#define AFX_XMLREAD_H__4345CACF_AA2D_4F8A_8503_461C37076ACD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

//#include "HardwareDef.h"

/////////////////////////////////////////////////////////////////////////////
// CXmlreadApp:
// See xmlread.cpp for the implementation of this class
//

class CXmlreadApp : public CWinApp
{
public:
	CXmlreadApp();
//	CHardwareDef m_xml_data;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXmlreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CXmlreadApp)
	afx_msg void OnAppAbout();
	afx_msg void OnMyFileOpen();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLREAD_H__4345CACF_AA2D_4F8A_8503_461C37076ACD__INCLUDED_)
