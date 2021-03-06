/*************************************************************************/
/*  editor_log.h                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef EDITOR_LOG_H
#define EDITOR_LOG_H

#include "scene/gui/control.h"
#include "scene/gui/label.h"
#include "scene/gui/rich_text_label.h"
#include "scene/gui/texture_button.h"
#include "scene/gui/empty_control.h"
#include "scene/gui/box_container.h"
#include "scene/gui/panel_container.h"
#include "scene/gui/texture_frame.h"
#include "scene/gui/tool_button.h"
#include "pane_drag.h"
#include "os/thread.h"
class EditorLog : public PanelContainer {

	OBJ_TYPE( EditorLog, PanelContainer );

	ToolButton *button;
	Label *title;
	RichTextLabel *log;
	TextureButton *tb;
	HBoxContainer *title_hb;
//	PaneDrag *pd;
	EmptyControl *ec;

	static void _error_handler(void *p_self, const char*p_func, const char*p_file,int p_line, const char*p_error,const char*p_errorexp,ErrorHandlerType p_type);

	ErrorHandlerList eh;

	Thread::ID current;


//	void _dragged(const Point2& p_ofs);
	void _close_request();
	void _flip_request();
	static void _undo_redo_cbk(void *p_self,const String& p_name);
protected:

	static void _bind_methods();
	void _notification(int p_what);
public:

	void add_message(const String& p_msg, bool p_error=false);
	void deinit();

	ToolButton *get_button();
	EditorLog();
	~EditorLog();
};

#endif // EDITOR_LOG_H
