// CntrItem.h : interface of the CXmlreadCntrItem class
//

#if !defined(AFX_CNTRITEM_H__A1411EB2_0CDF_4520_8325_FD9AFAF499FB__INCLUDED_)
#define AFX_CNTRITEM_H__A1411EB2_0CDF_4520_8325_FD9AFAF499FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CXmlreadDoc;
class CXmlreadView;

class CXmlreadCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CXmlreadCntrItem)

// Constructors
public:
	CXmlreadCntrItem(CXmlreadDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CXmlreadDoc* GetDocument()
		{ return (CXmlreadDoc*)COleClientItem::GetDocument(); }
	CXmlreadView* GetActiveView()
		{ return (CXmlreadView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXmlreadCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CXmlreadCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__A1411EB2_0CDF_4520_8325_FD9AFAF499FB__INCLUDED_)
