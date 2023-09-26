#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

#ifndef __FIGLET_H
#define __FIGLET_H

namespace ahm {

    // REQUIRES: "filget" package installed on your system
    class figlet {
    private:
        std::string query;
        std::string cmd;
        std::string font_path;
        std::vector<std::string> flags;

        const std::string& get_query() const {
            return this->query;
        }

        std::string get_flags() const {
            std::ostringstream oss;
            for (const auto& flag : this->flags) {
                oss << flag << " ";
            }
            return oss.str();
        }

        std::string get_font_path() const {
            return this->font_path;
        }

        void cmd_append(const std::string& _cmd) {
            this->cmd += _cmd + " ";
        }

        void cmd_load() {
            this->cmd.clear();
            cmd_append("figlet");

            if (get_flags() != "") {
                cmd_append(get_flags());
            }
            if (get_font_path() != "") {
                cmd_append("-f");
                cmd_append(get_font_path());
            }
            if (get_query() == "") {
                throw std::logic_error("You must set the query before printing");
            }
            else {
                cmd_append(get_query());
            }
        }

    public:
        figlet() {
            reset();
        }

        figlet& set_flags(const std::vector<std::string>& _flags) {
            this->flags = _flags;
            return *this;
        }

        figlet& set_font_path(const std::string& _path) {
            this->font_path = _path;
            return *this;
        }

        // add a string to print.
        figlet& set_query(const std::string& _query) {
            this->query = _query;
            return *this;
        }

        // print with figlet.
        void norm_print() {
            cmd_load();
            std::system(this->cmd.c_str());
        }

        // print with figlet and lolcat.
        // REQUIRES: "lolcat" package installed on your system.
        void lolcat_print() {
            cmd_load();
            cmd_append("| lolcat");
            std::system(this->cmd.c_str());
        }

        void reset() {
            this->cmd = "figlet ";
            this->flags.clear();
            this->query.clear();
            this->font_path.clear();
        }
    };

}

#endif // __FIGLET_H