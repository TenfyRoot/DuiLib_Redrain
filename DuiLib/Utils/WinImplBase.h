#include "StdAfx.h"

#ifndef WIN_IMPL_BASE_HPP
#define WIN_IMPL_BASE_HPP

namespace DuiLib
{

	enum UILIB_RESOURCETYPE
	{
		UILIB_FILE=1,		// 来自磁盘文件
		UILIB_ZIP,			// 来自磁盘zip压缩包
		UILIB_RESOURCE,		// 来自资源
		UILIB_ZIPRESOURCE,	// 来自资源的zip压缩包
	};

	enum UILIB_MAXMINTYPE
	{
		UILIB_NO =1,		// 不设置
		UILIB_FULLSCREEN,	// 全屏
		UILIB_WORK,		// 工作区最大
	};

	class UILIB_API WindowImplBase
		: public CWindowWnd
		, public CNotifyPump
		, public INotifyUI
		, public IMessageFilterUI
		, public IDialogBuilderCallback
	{
	public:
		WindowImplBase(){};
		virtual ~WindowImplBase(){};
		virtual void OnFinalMessage( HWND hWnd );
		virtual void Notify(TNotifyUI& msg);

		static void Cleanup();

		DUI_DECLARE_MESSAGE_MAP()
		virtual void OnWindowInit(TNotifyUI& msg) {};
		virtual void OnClick(TNotifyUI& msg);
		virtual void OnItemClick(TNotifyUI& msg) {};
		virtual void OnItemSelect(TNotifyUI& msg) {};
		virtual void OnItemActivate(TNotifyUI& msg) {};
		virtual void OnItemDbclk(TNotifyUI& msg) {};
		virtual void OnItemExpand(TNotifyUI& msg) {};
		virtual void OnItemRClick(TNotifyUI& msg) {};
		virtual void OnMouseEnter(TNotifyUI& msg) {};
		virtual void OnMouseLeave(TNotifyUI& msg) {};
		virtual void OnScroll(TNotifyUI& msg) {};
		virtual void OnDropDown(TNotifyUI& msg) {};
		virtual void OnTabSelect(TNotifyUI& msg) {};
		virtual void OnHeaderClick(TNotifyUI& msg) {};
		virtual void OnTextChanged(TNotifyUI& msg) {};
		virtual void OnValueChanged(TNotifyUI& msg) {};
		virtual void OnSelectChanged(TNotifyUI& msg) {};
		virtual void OnUnselected(TNotifyUI& msg) {};

	protected:
		virtual CDuiString GetSkinFolder() = 0;
		virtual CDuiString GetSkinFile() = 0;
		virtual LRESULT ResponseDefaultKeyEvent(WPARAM wParam);
		CControlUI* FindControl(POINT pt);
		CControlUI* FindControl(LPCTSTR pstrName);

		CPaintManagerUI m_PaintManager;

	public:
		virtual UINT GetClassStyle() const;
		virtual LPCTSTR GetWindowClassName() const;
		virtual UILIB_RESOURCETYPE GetResourceType() const;
		virtual UILIB_MAXMINTYPE GetMaxMinType() const;
		virtual CDuiString GetZIPFileName() const;
		virtual LPCTSTR GetResourceID() const;
		virtual CControlUI* CreateControl(LPCTSTR pstrClass) { return NULL; }
		virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, bool& bHandled);
		virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

#if defined(WIN32) && !defined(UNDER_CE)
		virtual LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnWindowPosChanging(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseHover(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		
#endif
		virtual LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnLButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LONG GetStyle();

	private:
		static LPBYTE m_lpResourceZIPBuffer;
	};
}

#endif // WIN_IMPL_BASE_HPP
