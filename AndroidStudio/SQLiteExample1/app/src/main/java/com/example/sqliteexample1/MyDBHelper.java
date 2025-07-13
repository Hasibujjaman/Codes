package com.example.sqliteexample1;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;


public class MyDBHelper extends SQLiteOpenHelper {
    private static final String DB_NAME = "Database 1";
    private static final int DB_VERSION = 1;
    private static final String TABLE_CONTACT = "Contacts_Table";
    private static final String COLUMN_KEY = "ID";
    private static final String COLUMN_NAME = "Name";
    private static final String COLUMN_PHONE = "Phone_Number";


    /* public MyDB(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }*/

    public MyDBHelper(Context context){
        super(context, DB_NAME, null, DB_VERSION);
    }

    public MyDBHelper(Context context, String dbName){
        super(context, dbName, null, DB_VERSION);
    }


    @Override  // will run when database is created
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        //to create a table in database 1 when app is run for the first time
        sqLiteDatabase.execSQL( "create table " + TABLE_CONTACT
                + "("
                + COLUMN_KEY + "integer primary key autoincrement, "
                + COLUMN_NAME + "text not null, " // Name column must have values for each row
                + COLUMN_PHONE + "text unique "  // Phone_Number column must have unique values
                + ")" );

    }

    @Override // will execute when there is some change in database scheme (addition or removal of table, column etc) and will create the upgraded table
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

        sqLiteDatabase.execSQL("drop table if exists " + TABLE_CONTACT);
        onCreate(sqLiteDatabase);

    }

    //method for inserting table data
    public void insertData(String name, String phone){

        SQLiteDatabase db = this.getWritableDatabase(); //opening the existing database
        ContentValues values = new ContentValues();
        values.put(COLUMN_NAME, name); // must put value in each Name column as it has the constraint not null
        values.put(COLUMN_PHONE, phone); //
        db.insert(TABLE_CONTACT, null, values);
        //db.close();
    }

    //method for fetching table data
    public ArrayList<ContactModel> getData(){

        SQLiteDatabase db = getReadableDatabase();
        Cursor cursor = db.rawQuery("select * from " + TABLE_CONTACT , null); // * will select all the columns in the table
        ArrayList<ContactModel> arrList = new ArrayList<>();                                  // column names can also be used to select particular columns
        while (cursor.moveToNext()){
            int id = cursor.getInt(0);
            String name = cursor.getString(1);
            String phone = cursor.getString(2);
            arrList.add(new ContactModel(id,name,phone));
        }
        cursor.close();
        return  arrList;
    }

    //method for updating table data
    public void updateData(ContactModel cm){

        SQLiteDatabase db = getWritableDatabase();

        ContentValues cv = new ContentValues();
        cv.put(COLUMN_PHONE, cm.phone);

        db.update(TABLE_CONTACT, cv, COLUMN_KEY + " = " + cm.id, null);

    }

    //method for deleting table data
    public void deleteData(int id){
        SQLiteDatabase db = getWritableDatabase();
       // db.delete(TABLE_CONTACT, COLUMN_KEY + " = ?", new String[]{String.valueOf(id)} );
        db.delete(TABLE_CONTACT, "ID = ? and Name = ?", new String[]{String.valueOf(id),"Kamal"} );
    }



}
