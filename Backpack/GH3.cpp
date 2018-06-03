#include "GH3.h"
#include <list>



GH3::GH3() {
}


GH3::~GH3() {
}

void GH3::QS(Package2* pack2, int s, int e) {
	int p, l, r;
	Package2 tmp;
	l = s - 1;
	r = e + 1;
	p = pack2[(l + r) / 2].value;
	while (true) {
		while (pack2[++l].value > p);
		while ((--r >= l) && (pack2[r].value < p));
		if (l <= r)
		{
			tmp = pack2[r];
			pack2[r] = pack2[l];
			pack2[l] = tmp;
		}
		else break;
	}
	if (l < e) QS(pack2, l, e);
	if (s < r) QS(pack2, s, r);
}

bool* GH3::solve(Package* packages, int n, int b, int& maxValue) {
	int i = 0, s = 0;
	bool* solution = new bool[n];
	Package2* pack2 = new Package2[n];
	for (int j = 0; j < n; j++)
	{
		pack2[j].size = packages[j].size;
		pack2[j].value = packages[j].value;
		pack2[j].key = j;
	}
	QS(pack2, 0, n - 1);
	while (s + pack2[i].size < b)
	{
		s += pack2[i].size;
		solution[pack2[i++].key] = true;
	}
	return solution;
}

std::string GH3::getName() {
	return "Maksymalna warto��";
}

