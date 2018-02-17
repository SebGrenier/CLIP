#pragma once
#include <algorithm>

namespace clip { namespace math {

	/*
	* 2D matrix.
	*/
	template <typename T>
	class Matrix
	{
	public:
		using size_type = size_t;
		using value_type = T;
		using value_type_ptr = value_type*;
		using const_value_type_ptr = const value_type*;

		Matrix(const size_type nbRows, const size_type nbCols, const_value_type_ptr data)
			: _data(nullptr)
			, _nbRows(nbRows)
			, _nbCols(nbCols)
		{
			// TODO: might overflow!
			const auto length = nbRows * nbCols;
			_data = new value_type[length];
			if (data != nullptr)
				std::copy(data, data + length, _data);
		}

		Matrix(const size_type nbRows, const size_type nbCols, value_type initValue)
			: _data(nullptr)
			, _nbRows(nbRows)
			, _nbCols(nbCols)
		{
			// TODO: might overflow!
			const auto length = nbRows * nbCols;
			_data = new value_type[length];
			std::fill(_data, _data + length, initValue);
		}

		Matrix(const Matrix& mat)
			: _data(nullptr)
			, _nbRows(mat.nbRows())
			, _nbCols(mat.nbCols())
		{
			// TODO: Shallow copy with deep copy on write
			auto matData = mat.data();
			if (matData != nullptr) {
				const auto length = _nbRows * _nbCols;
				_data = new value_type[length];
				std::copy(matData, matData + length, _data);
			}
		}

		value_type_ptr data() { return _data; }
		const_value_type_ptr data() const { return _data; }

		size_type nbRows() const { return _nbRows; }
		size_type nbCols() const { return _nbCols; }

		value_type_ptr operator [] (const size_type rowIndex) { return _data[rowIndex * _nbCols]; }
		const_value_type_ptr operator [] (const size_type rowIndex) const { return _data[rowIndex * _nbCols]; }

	private:
		T* _data;
		size_type _nbRows, _nbCols;
	};

}}
