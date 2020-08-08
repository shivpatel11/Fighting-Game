/***************************************************************
*file: Main.cpp
*author: Shiv Patel
*class: CS 2560 – C++
*assignment: program 6
*date last modified: 12/6/19
*
*purpose: This program simulates a enemy list and it continues until there is one enemy left
*
****************************************************************/
#pragma once
class Enemy
{
	//private variables
	private:
		double x_position;
		double y_position;
		double width;
		double height;
		double status;
	protected:
		//constructors
		Enemy()
		{
			x_position = 0;
			y_position = 0;
			width = 0;
			height = 0;
			status = 0;
		}
		Enemy(double x, double y, double w, double h, double s)
		{
			x_position = x;
			y_position = y;
			width = w;
			height = h;
			status = s;
		}
		double getXPosition() const
		{
			return x_position;
		}
		double getYPosition() const
		{
			return y_position;
		}
		double getWidth() const
		{
			return width;
		}
		double getHeight() const
		{
			return height;
		}
	public : 
		double getStatus() const
		{
			return status;
		}
		void setXPosition(double x)
		{
			x_position = x;
		}
		void setYPosition(double y)
		{
			y_position = y;
		}
		void setWidth(double w)
		{
			width = w;
		}
		void setHeight(double h)
		{
			height = h;
		}
		void setStatus(double s)
		{
			status = s;
		}
	public:
		//virtual functions for the child classes
		virtual void move_position();
		virtual void fire_weapon();
		virtual void update_status();
};

