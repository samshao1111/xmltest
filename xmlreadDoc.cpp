// xmlreadDoc.cpp : implementation of the CXmlreadDoc class
//

#include "stdafx.h"
#include "xmlread.h"

#include "xmlreadDoc.h"
#include "CntrItem.h"
#include "xmlreadView.h"

#include "tinyxml2.h"
#include "ChildFrm.h"

#include <afxres.h>
#include <iostream>  

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//#include "HardwareDef.h"

using namespace std;  
using namespace tinyxml2 ;  

/*
CXmlreadView* GetView(CRuntimeClass* pClass) 
{ 
	//	CXmlreadDoc* pDoc=CXmlreadDoc::GetDocument(); 
		CXmlreadView* pView; 
		POSITION pos=this->GetFirstViewPosition(); 
		while(pos!=NULL){ 
		pView=this->GetNextView(pos); 
		if(!pView->IsKindOf(pClass)) 
			break; 
		} 
		if(!pView->IsKindOf(pClass)){ 
		AfxMessageBox("Connt Locate the View."); 
		return NULL; 
		}
		return pView; 
} */

/////////////////////////////////////////////////////////////////////////////
// CXmlreadDoc

IMPLEMENT_DYNCREATE(CXmlreadDoc, COleDocument)

BEGIN_MESSAGE_MAP(CXmlreadDoc, COleDocument)
	//{{AFX_MSG_MAP(CXmlreadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
//	ON_COMMAND(ID_FILE_SAVE£¬OnSaveDocument)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXmlreadDoc construction/destruction

CXmlreadDoc::CXmlreadDoc()
{
	// Use OLE compound files
	EnableCompoundFile();
	m_xml_file_data=_T(""); 
	m_newflag= FALSE;
	// TODO: add one-time construction code here

}

CXmlreadDoc::~CXmlreadDoc()
{
}

BOOL CXmlreadDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;
	

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

BOOL CXmlreadDoc::OnSaveDocument( LPCTSTR lpszPathName )
{
	OnFileSave();
	return TRUE;
}

BOOL CXmlreadDoc::SaveModified(  )
{
	//OnFileSave();
	return TRUE;
}


BOOL CXmlreadDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	
	CString str ;
	str = lpszPathName;
	if ( str.Find(_T(".xml"),0) == -1)
		return FALSE;


	if (m_newflag == FALSE)
	{
		DeleteContents();

		tinyxml2::XMLDocument  doc;  
		doc.LoadFile (lpszPathName);  

		tinyxml2::XMLPrinter visitor;

		int memlen= 0 , i;
		char* str=NULL;
		m_xml_file_data = _T("");
	
  
	//	 while(doc.Accept( &visitor ))
		{
			 doc.Print(&visitor) ;
			 memlen	= visitor.CStrSize();
			 str	= new char[memlen + 1];
			 memcpy(str,visitor.CStr(),memlen);
	 
			 for(i=0;i<=memlen;i++)
			 {
				 if (str[i] == (char)0x0a) 
					 m_xml_file_data += _T("\r\n");
				 else
					 m_xml_file_data = m_xml_file_data + str[i];
				 //if (str[i] == '>') m_xml_file_data += _T("\r\n");
			 }

			 if (str != NULL ) {delete[] str; str=NULL ; memlen= 0 ;}
		//	 visitor.ClearBuffer();
		 }
	 


			SetModifiedFlag();
			m_newflag = TRUE;


			CXmlreadView* pView; 
			CFont m_cFont;
	
			POSITION pos=GetFirstViewPosition(); 
			while(pos!=NULL){ 
				pView=(CXmlreadView*)GetNextView(pos); 
				if(!pView->IsKindOf(RUNTIME_CLASS(CXmlreadView))) 
				break; 
			} 
			if(pView->IsKindOf(RUNTIME_CLASS(CXmlreadView))){ 
			//	pView->ShowScrollBar(SB_HORZ      , FALSE );
    
			//	m_cFont.CreateFont(-11,0,0,0,FW_NORMAL,FALSE,FALSE,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,/*fontname*/"Arial");
			m_cFont.CreateFont(20,	0, 0, 0,
								FW_THIN, FALSE,	FALSE, 0,
										DEFAULT_CHARSET,
										OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 
										DEFAULT_QUALITY, DEFAULT_PITCH,
										_T("Times New Roman"));	

				pView->SetFont(&m_cFont,TRUE);

				pView->SetWindowText(m_xml_file_data);
			}
			
	}
 
	UpdateAllViews(NULL); 


	//if (!COleDocument::OnOpenDocument(lpszPathName))
		//return FALSE;

	return TRUE;
}




/////////////////////////////////////////////////////////////////////////////
// CXmlreadDoc serialization

void CXmlreadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here

	}
	else
	{
		// TODO: add loading code here

	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CXmlreadDoc diagnostics

#ifdef _DEBUG
void CXmlreadDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CXmlreadDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXmlreadDoc commands
void CXmlreadDoc:: OnFileSaveAs() 
{
	OnFileSave();
}




void CXmlreadDoc:: OnFileSave() 
{
	char szFileFilter[]	= "All File (*.xml)|*.xml||";
	
	CFileDialog	FileDialog(FALSE, "xml", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT|OFN_NONETWORKBUTTON, szFileFilter, NULL);  

	if(FileDialog.DoModal() == IDOK )
	{
		CString	savefile	= FileDialog.GetPathName();
		
		CFile	xml(savefile, CFile::modeCreate | CFile::modeWrite) ;


					CXmlreadView* pView; 
		
			POSITION pos=GetFirstViewPosition(); 
			while(pos!=NULL){ 
				pView=(CXmlreadView*)GetNextView(pos); 
				if(!pView->IsKindOf(RUNTIME_CLASS(CXmlreadView))) 
				break; 
			} 
			if(pView->IsKindOf(RUNTIME_CLASS(CXmlreadView))) 
				pView->GetWindowText(m_xml_file_data);

		xml.Write(m_xml_file_data, m_xml_file_data.GetLength());

		xml.Close();

		//return TRUE;
			
	}
	
//	return FALSE;

}