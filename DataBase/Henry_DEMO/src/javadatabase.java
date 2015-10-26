import java.sql.*;
public class javadatabase {
	public static void main(String args[]){
		try
		{Class.forName("sun.jdbc.odbc.JdbcOdbcDriver"); }
		catch (ClassNotFoundException ce)
		{ System.out.println("SQLException:"+ce.getMessage());}
	
	try{
		Connection con=DriverManager.getConnection("jdbc:odbc:student2","user2","u002");
		Statement stmt=con.createStatement();
		ResultSet rs=stmt.executeQuery("select * from student");
		while(rs.next()){
			System.out.println(
				rs.getString(1)+"\t"+	
				rs.getString(2)+"\t"+
				rs.getString(3)
			);
		}
		rs.close();
		stmt.close();
		
	
	}
	catch(SQLException e){
		System.out.println("SQLException:"+e.getMessage());
	}
		
	}
	
}		