package shapes;

public class MyPic {
	public static void main(String[] args) 
	{
		Picture pic = new Picture(666,444);
		Circle c1 = new Circle(444, 121, 50);
		Circle c2 = new Circle(222, 121, 50);
//		Line l1 = new Line(222, 101, 666, 233);
		Rectangle r1 = new Rectangle(122, 40, 422, 330);
		Triangle t1 = new Triangle(272, 333, 394, 333, 333, 221);
		pic.add(c1);
		pic.add(c2);
//		pic.add(l1);
		pic.add(r1);
		pic.add(t1);
		pic.draw();	

//		Picture pic = new Picture(420,300);
//		Circle c1 = new Circle(320,40,80);
//		Rectangle r1 = new Rectangle(100, 100, 100, 100);
//		Triangle t1 = new Triangle(100, 100, 200, 100, 150, 50);
//		Line l1 = new Line(0,205,400,205);
//		Circle c2 = new Circle(200,200,50);
//		pic.add(c1);
//		pic.add(r1);
//		pic.add(t1);
//		pic.add(l1);
//		pic.add(c2);
	}
}
