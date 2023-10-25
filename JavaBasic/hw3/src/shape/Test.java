package shape;

import testutil.TestRunner;

public class Test {
	public static void main(String[] args) {

		TestRunner.enableException(true);

		TestRunner.runTest(()->{
			Rectangle r0 = new Rectangle();
			r0.setWidth(1);
			r0.setHeight(2);
			System.out.println("Ans: "+r0.getArea()+" "+r0.getPerimeter()+" "+r0.isFilled());
			System.out.println("Expected: 2.0 6.0 false");
			if (r0.getArea() == 2 && r0.getPerimeter() == 6 && r0.isFilled() == false) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Rectangle r1 = new Rectangle(3, 1);
			System.out.println("Ans: "+r1.getArea()+" "+r1.getPerimeter());
			System.out.println("Expected: 3.0 8.0");
			if (r1.getArea() == 3 && r1.getPerimeter() == 8) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Rectangle r2 = new Rectangle(2, 4, "Red");
			System.out.println("Ans: "+r2.getArea()+" "+r2.getPerimeter()+" "+r2.isFilled()+" "+r2.getColor()
								+" "+r2);
			System.out.println("Expected: 8.0 12.0 true Red Rectangle(Red)");
			if (r2.getArea() == 8 && r2.getPerimeter() == 12 && r2.isFilled() == true
				&& r2.getColor().equals( "Red") && r2.toString().equals("Rectangle(Red)"))
				System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Circle c0 = new Circle(1);
			System.out.printf("Ans: %.2f %.2f\n", c0.getArea(), c0.getPerimeter());
			System.out.println("Expected: 3.14 6.28");
			if (c0.getArea() == Math.PI && c0.getPerimeter() == Math.PI * 2)
				System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Circle c0 = new Circle(1);
			c0.setRadius(2);
			System.out.println("Ans: "+(c0.getArea() == c0.getPerimeter())+" "+c0.isFilled()+" "+c0);
			System.out.println("Expected: true false Circle(#)");
			if (c0.getArea() == c0.getPerimeter() && c0.isFilled() == false && c0.toString().equals("Circle(#)"))
				System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Circle c0 = new Circle(1);
			c0.setRadius(2);
			c0.setColor("Blue");
			System.out.println("Ans: "+c0);
			System.out.println("Expected: Circle(Blue)");
			if (c0.toString().equals("Circle(Blue)"))
				System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);


		TestRunner.runTest(()->{
			Circle c1 = new Circle();
			System.out.println("Ans: "+c1.isFilled());
			System.out.println("Expected: false");
			if (c1.isFilled() == false)
				System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		System.exit(0);
	}
}
