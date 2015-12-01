import java.util.ArrayList;

public class Database {
//	private ArrayList<CD> listCD = new ArrayList<CD>();
//	private ArrayList<DVD> listDVD = new ArrayList<DVD>();
	private ArrayList<Item> listItem = new ArrayList<Item>();
//	public void add(CD cd){
//		listCD.add(cd);
//	}
//	
//	public void add(DVD dvd){
//		listDVD.add(dvd);
//	}
	public void add(Item item){
		listItem.add(item);
	}
	public void list(){
//		for(CD cd:listCD){
//			cd.print();
//		}
//		for(DVD dvd:listDVD){
//			dvd.print();
//		}
		for(Item item:listItem){
			item.print();
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Database db = new Database();
		db.add(new CD("abc", "abc", 4, 60, false, "..."));
		db.add(new CD("def", "def", 4, 60, false, "..."));
		db.add(new DVD("movie", "me", 60, false, "------"));
		db.add(new MP3("funny boy", 5, "nice music", false, "lovelive", "all right reserved", 128, 5));
		db.list();
	}

}
