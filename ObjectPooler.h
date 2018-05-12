#pragma once
#include <vector>
#include <assert.h>

template <typename T>
class ObjectPooler
{
public:
	ObjectPooler(int size, bool expand = false, T def = T()) {
		m_size = size;
		m_shouldExpand = expand;
		m_default = def;
		m_pool = std::vector<T>();

		for (int i = 0; i < size; i++) {
			m_pool.push_back(T(m_default));
		}
	}

	~ObjectPooler() {

	}

	int Create() {
		Activate(m_active);
		return m_active-1;
	}

	T& Get(int index) {

		assert(index < m_size);

		return m_pool[index];
	}

	T& operator[](int i) {
		return Get(i);
	}

	const int& ActiveTotal() const {
		return m_active;
	}

	void Activate(int index) {

		if (index >= m_size) // trop grand
			return;
		if (index < m_active) // déjà actif
			return;

		T temp = m_pool[m_active];
		m_pool[m_active] = m_pool[index];
		m_pool[index] = temp;

		m_active++;
	}

	void Deactivate(int index) {
		if (index >= m_size) // trop grand
			return;
		if (index >= m_active) // déjà inactif
			return;

		m_active--;

		m_pool[index] = m_pool[m_active];
		m_pool[m_active] = m_default;
	}

private:
	bool m_shouldExpand;
	int m_size;
	int m_active;
	T m_default;
	std::vector<T> m_pool;
};
