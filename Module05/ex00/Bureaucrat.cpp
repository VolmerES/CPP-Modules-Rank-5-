/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volmer <volmer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:12:56 by volmer            #+#    #+#             */
/*   Updated: 2025/06/13 14:13:43 by volmer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Burocrata"), _grade(150) {}

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
_name(name), _grade(grade) {
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

void Bureaucrat::incrementGrade(void) {
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if ((this->_grade + 1) > 150)
	 throw GradeTooLowException();
	this->_grade++;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}