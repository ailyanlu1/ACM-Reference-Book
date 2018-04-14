acm_notebook.pdf: acm_notebook.tex combine
	./combine
	xelatex acm_notebook.tex
	xelatex acm_notebook.tex

acm_notebook.tex: combine

combine: combine.cpp
	g++ -std=c++1z -I /usr/local/opt/boost/include -L /usr/local/opt/boost/lib combine.cpp -lboost_filesystem -lboost_system -o combine

clean:
	rm *.aux *.toc *.o *.log *.pdf combine acm_notebook.tex

clean_src:
	find ./src -type f -not -name '*.cpp' -delete
