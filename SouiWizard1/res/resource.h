//stamp:0749d4a41688a0ca
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
			}
			const TCHAR * XML_MAINWND;
		}LAYOUT;
		class _values{
			public:
			_values(){
				string = _T("values:string");
				color = _T("values:color");
				skin = _T("values:skin");
			}
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
		}values;
		class _IMG{
			public:
			_IMG(){
			}
		}IMG;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"btn_close",65536},
		{L"btn_max",65537},
		{L"btn_min",65539},
		{L"btn_restore",65538},
		{L"button_ping",65541},
		{L"edit_ping",65540},
		{L"lv_ping_result",65542},
		{L"text_bytes",65544},
		{L"text_from",65543},
		{L"text_time",65545},
		{L"text_ttl",65546}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			btn_close = namedXmlID[0].strName;
			btn_max = namedXmlID[1].strName;
			btn_min = namedXmlID[2].strName;
			btn_restore = namedXmlID[3].strName;
			button_ping = namedXmlID[4].strName;
			edit_ping = namedXmlID[5].strName;
			lv_ping_result = namedXmlID[6].strName;
			text_bytes = namedXmlID[7].strName;
			text_from = namedXmlID[8].strName;
			text_time = namedXmlID[9].strName;
			text_ttl = namedXmlID[10].strName;
		}
		 const wchar_t * btn_close;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * button_ping;
		 const wchar_t * edit_ping;
		 const wchar_t * lv_ping_result;
		 const wchar_t * text_bytes;
		 const wchar_t * text_from;
		 const wchar_t * text_time;
		 const wchar_t * text_ttl;
		}name;

		class _id{
		public:
		const static int btn_close	=	65536;
		const static int btn_max	=	65537;
		const static int btn_min	=	65539;
		const static int btn_restore	=	65538;
		const static int button_ping	=	65541;
		const static int edit_ping	=	65540;
		const static int lv_ping_result	=	65542;
		const static int text_bytes	=	65544;
		const static int text_from	=	65543;
		const static int text_time	=	65545;
		const static int text_ttl	=	65546;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		const static int blue	=	0;
		const static int gray	=	1;
		const static int green	=	2;
		const static int red	=	3;
		const static int white	=	4;
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
