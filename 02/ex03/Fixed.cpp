/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:16:00 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/09 16:37:00 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	setRawBits(value << fractionalBits);
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1 << fractionalBits)));
};

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(src.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &src) {
	o << src.toFloat();
	return o;
}

bool Fixed::operator>(const Fixed &src) const {
	return (getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src) const {
	return (getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src) const {
	return (getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src) const {
	return (getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src) const {
	return (getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src) const {
	return (getRawBits() != src.getRawBits());
}

Fixed Fixed::operator+(const Fixed &src) {
	return Fixed(toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) {
	return Fixed(toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) {
	return Fixed(toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) {
	if (src.toFloat() == 0)
		return Fixed(0);
	return Fixed(toFloat() / src.toFloat());
}

Fixed &Fixed::operator++(void) {
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed &Fixed::operator--(void) {
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(getRawBits()) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return getRawBits() >> fractionalBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
