package com.example.listviewexample;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView listView = findViewById(R.id.listView);

        ArrayList<String> arrList = new ArrayList<>();
        arrList.add("List item 1");
        arrList.add("List item 2");
        arrList.add("List item 3");
        arrList.add("List item 4");
        arrList.add("List item 5");
        arrList.add("List item 6");
        arrList.add("List item 7");
        arrList.add("List item 8");
        arrList.add("List item 9");
        arrList.add("List item 10");
        arrList.add("List item 11");
        arrList.add("List item 12");
        arrList.add("List item 13");
        arrList.add("List item 14");
        arrList.add("List item 15");

        ArrayAdapter<String> arrAdapter = new ArrayAdapter<>(getApplicationContext(),R.layout.mytextview,arrList);
        listView.setAdapter(arrAdapter);




    }
}