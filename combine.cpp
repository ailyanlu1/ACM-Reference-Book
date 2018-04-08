/*
 * On Mac OSX, compile with:
 * g++ -std=c++1z -I /usr/local/opt/boost/include -L /usr/local/opt/boost/lib combine.cpp -lboost_filesystem -lboost_system -o combine
 *
 *
 */
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using std::cout;
using std::endl;

#define GREEN_S "\033[1;32m"
#define GREEN_E "\033[0m"

string scanCapital(const string &s) {
    string res= "";

    for (string::size_type i = 0; i < s.size(); ++i) {
        if (i != 0 && isupper(s[i])) {
            res += " ";
        }
        res += s[i];
    }

    return res;
}

string app_each_cpp(ofstream &out) {
    int cnt = 0;

    using namespace boost::filesystem;
    recursive_directory_iterator dir_iter("./src"), end;

    while (dir_iter != end) {
        path p = dir_iter->path();
        string str_name = scanCapital(p.stem().string());

        if (is_directory(p)) {
            // add its name as section
            cout << str_name << endl;
            out << "\\newpage" << endl;
            out << "\\section{" << str_name << "}" << endl;
        } else if (extension(p.filename()) == ".cpp") {
            cout << "\t" << str_name << endl;

            // add its name as subsection
            out << "\\vspace{3ex}" << endl;
            out << "\\subsection{" << str_name << "}" << endl;

            // add its content in lstlisting
            out << "\\begin{lstlisting}" << endl;

            boost::filesystem::ifstream in(p);
            out << in.rdbuf();

            out << endl << "\\end{lstlisting}" << endl << endl;

            out.flush();
            in.close();

            cnt++;
        }

        dir_iter++;
    }

    out.flush();

    return (GREEN_S + std::to_string(cnt) + " files appended" + GREEN_E);
}

int main() {
    ofstream fout("acm_notebook.tex", ios::out | ios::trunc);

    // append start of latex template
    ifstream fin("latex_start.tex");

    fout << fin.rdbuf();
    fout.flush();
    fin.close();

    // iterate each directories
    string status = app_each_cpp(fout);
    cout << status << endl;

    fout << "\\end{document}" << endl;

    fout.close();
}
