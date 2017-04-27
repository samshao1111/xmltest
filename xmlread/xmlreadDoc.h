// xmlreadDoc.h : interface of the CXmlreadDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLREADDOC_H__E747387B_AAEF_4811_A894_FDE6C3A63986__INCLUDED_)
#define AFX_XMLREADDOC_H__E747387B_AAEF_4811_A894_FDE6C3A63986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CXmlreadDoc : public COleDocument
{
protected: // create from serialization only
	CXmlreadDoc();
	DECLARE_DYNCREATE(CXmlreadDoc)

// Attributes
public:
    CString	m_xml_file_data; 
	BOOL	m_newflag;
// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXmlreadDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName); 
	virtual	void OnFileSave() ;
	virtual	void OnFileSaveAs() ;
	virtual BOOL OnSaveDocument( LPCTSTR lpszPathName );
	virtual BOOL SaveModified( );
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXmlreadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXmlreadDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileClose();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XMLREADDOC_H__E747387B_AAEF_4811_A894_FDE6C3A63986__INCLUDED_)
