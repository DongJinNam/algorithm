#include <iostream>
#include <vector>

using namespace std;

void m_sort(std::vector<int> &, int, int); // merge sort �Լ�
void merge(std::vector<int> &, int, int, int, int);

// merge sort
void m_sort(std::vector<int> &a, int left, int right) {
	if (left == right) return; // ���Ұ� �ϳ��� ���� ���
	int mid = (left + right) / 2; // �߰�
	m_sort(a, left, mid); // divide
	m_sort(a, mid + 1, right); // divide
	merge(a, left, mid - left + 1, mid + 1, right - mid); // merge
}

// merge ����
void merge(std::vector<int> &a, int left, int l_size, int right, int r_size) {
	int i = 0, j = 0, k = 0;
	std::vector<int> c(l_size + r_size, 0); // �ӽ� ����
	while (i < l_size && j < r_size) { // i : left vector index, r : right vector index
		if (a[left + i] < a[right + j]) {
			c[k++] = a[left + i];
			i++;
		}
		else if (a[left + i] > a[right + j]) {
			c[k++] = a[right + j];
			j++;
		}
		else {
			c[k++] = a[left + i];
			i++;
		}
	}
	while (i < l_size) { // left vector �ܿ� ��ҵ� ó��
		c[k++] = a[left + i];
		i++;
	}
	while (j < r_size) { // right vector �ܿ� ��ҵ� ó��
		c[k++] = a[right + j];
		j++;
	}
	for (i = left; i < left + l_size + r_size; i++) // Copy and Paste
		a[i] = c[i-left];
}

int main() {
	int n;
	cin >> n;
	std::vector<int> vec(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	m_sort(vec, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
	return 0;
}