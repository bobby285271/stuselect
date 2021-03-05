/* students.vala
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

    public class Students : GLib.Object {

        // The number of girls in the student array.
        private const int GIRLS = 11;

        // The number of names to display in a single line.
        private const int NAMES = 8;

        // The number of done operations.
        // Should be reset when cnt exceeds the actual number of the gender.
        private int femalecnt;
        private int malecnt;

        private struct student {
            string name;
            int ismale;
            uint val; // Expect a random value, only used in sorting.
            student (string name) {
                this.name = name;
                this.ismale = 1;
                this.val = 0;
            }
        }

        private student[] s = {
            // List of girls, the number of girls should match the variable GIRLS.
            student("姜文婷"),
            student("蔡卓琳"),
            student("黄贝苗"),
            student("李晓芳"),
            student("林芷泳"),
            student("邓子曼"),
            student("曾宇璐"),
            student("陈佳茵"),
            student("陈芷茵"),
            student("李晓钰"),
            student("陈晓琪"),

            // List of boys.
            student("李玮楠"),
            student("商汇川"),
            student("沈德增"),
            student("王凯峰"),
            student("陈锦川"),
            student("黄俊"),
            student("徐旗"),
            student("谭恩泽"),
            student("郭一梵"),
            student("刘坚豪"),
            student("陈诗伟"),
            student("王仁杰"),
            student("杨泽祺"),
            student("王文威"),
            student("邓思阳"),
            student("潘国俊"),
            student("赖艳鹏"),
            student("雷昊禧"),
            student("陈佳浚"),
            student("王玮璟"),
            student("梁滔"),
            student("马家豪"),
            student("吴凡"),
            student("樊曦阳"),
            student("王佳业"),
            student("孙铭哲"),
            student("旷恒毅"),
            student("蒋泽明"),
            student("林晓东"),
            student("何泳良"),
            student("香南斌"),
            student("李志成"),
            student("谢嘉欢"),
            student("谢城"),
            student("丁汉基"),
            student("罗仕鑫"),
            student("黄彬源"),
            student("吴中其"),
            student("陈隽淇"),
            student("李志文"),
            student("黄树华"),
            student("王明生")
        };

        public Students() {
            // ismale should be set only once, before the array is shuffled.
            // The default value of ismale is already 1, so we only need to deal with girls.
            for (int i = 0; i < GIRLS; i++) {
                s[i].ismale = 0;
            }
            reset();
        }

        // Reset the counter. Without calling this function, the result will never be duplicate.
        public void reset() {
            malecnt = femalecnt = 0;
        }

        // Returns a list of names from the student array.
        // sex == 1: returns a list of a random name of boys.
        // sex == 0: returns a list of a random name of girls.
        // sex == -1: returns a list of random names.
        // sex == others: returns an error report.
        public string getNames(int num, int sex = -1) {
            if ((sex == 1 && num + malecnt + GIRLS > s.length) ||
                (sex == 0 && num + femalecnt > GIRLS) ||
                (sex == -1 && num + malecnt + femalecnt > s.length)) {
                return "请先重置";
            }
            if (sex > 1 || sex < -1 || num < 0) {
                return "出错";
            }
            if (num == 0) {
                return "请指定人数";
            }
            string ret = "";
            for (int i = 1; i <= num; i++) {
                ret += getName(sex);
                if (i != num) {
                    ret += (i % NAMES != 0) ? " " : "\n";
                }
            }
            return ret;
        }

        // Returns a random name from the student array which is not chosen yet.
        private string getName(int sex = -1) {
            if ((sex == 1 && 1 + malecnt + GIRLS > s.length) ||
                (sex == 0 && 1 + femalecnt > GIRLS) ||
                (sex == -1 && 1 + malecnt + femalecnt > s.length)) {
                return "出错";
            }

            // Do a shuffle every time, so we can handle the situation where the gender selection is updated.
            shuffle(s.length - malecnt - femalecnt);

            if (sex == -1) {
                return update(0);
            } else if (sex == 1 || sex == 0) {
                bool ok = false;
                for (int i = 0; i + malecnt + femalecnt < s.length; i++) {
                    if (s[i].ismale == sex) {
                        ok = true;
                        return update(i);
                    }
                }
                if (ok == false) {
                    return "出错";
                }
            }
            return "出错";
        }

        // Provide each element with a random number, then perform a bubble sort according to the number.
        private void shuffle(int len = s.length) {
            Rand rnd = new Rand();
            for (int i = 0; i < len; i++) {
                s[i].val = rnd.next_int();
            }
            for (int i = 0; i < len - 1; i++) {
                for (int j = 0; j < len - i - 1; j++) {
                    if (s[j].val > s[j + 1].val) {
                        student tmp = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = tmp;
                    }
                }
            }
        }

        // Update the counter, and perform a shift.
        private string update(int x) {
            if (x < 0 || x >= s.length) return "出错";
            string ret = s[x].name;
            if (s[x].ismale == 1) {
                malecnt++;
            } else {
                femalecnt++;
            }
            shift(x);
            return ret;
        }

        // Mark s[x] as already selected, move it to the last place of the array.
        private void shift(int x) {
            if (x < 0 || x >= s.length) return;
            student tmp = s[x];
            for (int i = x + 1; i < s.length; i++) {
                s[i - 1] = s[i];
            }
            s[s.length - 1] = tmp;
        }
    }
}

