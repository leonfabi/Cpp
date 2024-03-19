/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkrug <fkrug@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:37:12 by fkrug             #+#    #+#             */
/*   Updated: 2024/03/19 11:02:20 by fkrug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array{
    public:
        Array(): _array(NULL), _size(0) {};
        Array(unsigned int n): _array(new T[n]()), _size(n) {};
        ~Array() {
            if (_size > 0)
                delete[] _array;
        };
        Array& operator=(const Array& old_obj){
            if (this != &old_obj){
                if (_size > 0)
                    delete[] _array;
                _size = old_obj._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = old_obj._array[i];
            }
            return *this;
        };
        Array(const Array& old_obj): _array(NULL), _size(0){
            *this = old_obj;
        };
        T& operator[](unsigned int index){
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        };
        const T& operator[](unsigned int index) const{
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        };
        unsigned int size() const{ return _size; };
    private:
        T* _array;
        unsigned int _size;
};
#endif