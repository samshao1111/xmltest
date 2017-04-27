// xmlreadView.h : interface of the CXmlreadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLREADVIEW_H__78E23AD3_7F40_4C02_A8C4_CEFDA3CB3272__INCLUDED_)
#define AFX_XMLREADVIEW_H__78E23AD3_7F40_4C02_A8C4_CEFDA3CB3272__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CXmlreadCntrItem;

class CXmlreadView : public CEditView
{
protected: // create from serialization only
	CXmlreadView();
	DECLARE_DYNCREATE(CXmlreadView)

// Attributes
public:
	CXmlreadDoc* GetDocument();
	// m_pSelection holds the selection to the current CXmlreadCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CXmlreadCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CXmlreadCntrItem* m_pSelection;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXmlreadView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXmlreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXmlreadView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in xmlreadView.cpp
inline CXmlreadDoc* CXmlreadView::GetDocument()
   { return (CXmlreadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLREADVIEW_H__78E23AD3_7F40_4C02_A8C4_CEFDA3CB3272__INCLUDED_)
