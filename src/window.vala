/* window.vala
 *
 * Copyright 2021 Bobby Rong
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace Stuselect {
	[GtkTemplate (ui = "/top/bobby285271/stuselect/window.ui")]
	public class Window : Gtk.ApplicationWindow {
		[GtkChild]
		Gtk.Label label;
		[GtkChild]
		Gtk.Button start_btn;
		[GtkChild]
		Gtk.Button clear_btn;
		[GtkChild]
		Gtk.CheckButton male_check;
		[GtkChild]
		Gtk.CheckButton female_check;
		[GtkChild]
		Gtk.Entry number;

        Students stu = new Students();

		public Window (Gtk.Application app) {
			Object (application: app);

			start_btn.clicked.connect (() => {
			    bool getmale = male_check.get_active();
			    bool getfemale = female_check.get_active();
			    string getnum = number.get_text();
			    int actnum = 0;
			    for (int i = 0; i < getnum.length; i++) {
			        actnum *= 10;
			        actnum += getnum[i] - '0';
			    }
			    if (getmale && !getfemale) {
			        label.label = stu.getNames(actnum, 1);
			    } else if (getfemale && !getmale) {
			        label.label = stu.getNames(actnum, 0);
			    } else {
			        label.label = stu.getNames(actnum);
			    }
		    });

		    clear_btn.clicked.connect (() => {
                stu.reset();
                label.label = "女生节快乐";
		    });
		}
	}
}
