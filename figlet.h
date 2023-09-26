#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

#ifndef __FIGLET_H
#define __FIGLET_H

namespace ahm {

    // REQUIRES: filget package installed on your system
    class figlet {
    private:
        std::string cmd;

    public:
        figlet() {
            cmd = "figlet ";
        }

        figlet(const std::string& _text) {
            cmd = "figlet ";
            text(_text);
            execute();
        }

        void flags(const std::vector< std::string>& _flags) {
            std::ostringstream oss;
            for (const auto& flag : _flags) {
                oss << flag << " ";
            }
            cmd += oss.str();
        }

        void font_path(const std::string& _path) {
            cmd += "-f " + _path + " ";
        }

        void text(const std::string& _text) {
            cmd += _text;
        }

        void execute() {
            std::system(cmd.c_str());
        }

        // REQUIRES: lolcat package installed on your system
        void lolcat() {
            cmd += " | lolcat";
            std::system(cmd.c_str());
        }

    };

}

#endif // __FIGLET_H