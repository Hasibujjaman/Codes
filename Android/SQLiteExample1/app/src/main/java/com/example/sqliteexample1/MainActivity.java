package com.example.sqliteexample1;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import java.util.ArrayList;
public class MainActivity extends AppCompatActivity {
    public MyDBHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //creating database
        dbHelper = new MyDBHelper(this);
        //inserting data to database
        dbHelper.insertData("Emon","01892400322");
        dbHelper.insertData("Husneara", "01767349306");
        dbHelper.insertData("Kamal", "01776283781");

        //fetching data from database
        ArrayList<ContactModel> contactList =  dbHelper.getData();
        for(int i = 0; i < contactList.size(); i++){
            Log.d("Contact info main act", "ID : " + contactList.get(i).id + " Name : " + contactList.get(i).name + " Phone : " + contactList.get(i).phone);
        }

        //updating data of database
        dbHelper.updateData(new ContactModel(4,"","01900000000"));

        //deleting data of database
        dbHelper.deleteData(5);


    }

}