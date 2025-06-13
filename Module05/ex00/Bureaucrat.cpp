/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:12:56 by volmer            #+#    #+#             */
/*   Updated: 2025/06/13 14:02:46 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {};

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) :
_name(name) {
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

std::string const& Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return(this->_grade);
}

void Bureaucrat::IncrementGrade(void) {
	this->_grade--;
	if (this->_grade < 1)
		GradeTooHighException;
}

void Bureaucrat::DecrementGrade(void) {
	this->_grade++;
	if (this->_grade > 150)
		GradeTooLowException;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	std::cout << "Grade too high" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	std::cout << !"Grade too low" << std::endl;
}