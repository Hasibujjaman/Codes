package com.example.dailyroutinev2;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar;
        ListView listView;

        toolbar = findViewById(R.id.toolbarMain);
        listView = findViewById(R.id.listView);

        setSupportActionBar(toolbar);
        getSupportActionBar().setTitle("Daily Routine");

        // String[] title = getResources().getStringArray(R.array.Days);
        String[] title = new String[]{"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
        String[] time = new String[]{"", "", "", "", "", "", ""};
        String[] ai = new String[]{"", "", "", "", "", "", ""};


        SimpleAdapter adapter = new SimpleAdapter(MainActivity.this,title,time,ai);
        listView.setAdapter(adapter);

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                switch (position){
                    case 0 : {
                        Toast.makeText(MainActivity.this,"Saturday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Saturday");
                        startActivity(intentToDay);
                        break;
                    }
                    case 1 : {
                        Toast.makeText(MainActivity.this,"Sunday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Sunday");
                        startActivity(intentToDay);
                        break;
                    }
                    case 2 : {
                        Toast.makeText(MainActivity.this,"Monday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Monday");
                        startActivity(intentToDay);

                        break;
                    }
                    case 3 : {
                        Toast.makeText(MainActivity.this,"Tuesday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Tuesday");
                        startActivity(intentToDay);

                        break;
                    }
                    case 4 : {
                        Toast.makeText(MainActivity.this,"Wednesday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Wednesday");
                        startActivity(intentToDay);

                        break;
                    }
                    case 5 : {
                        Toast.makeText(MainActivity.this,"Thursday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Thursday");
                        startActivity(intentToDay);

                        break;
                    }
                    case 6 : {
                        Toast.makeText(MainActivity.this,"Friday selected",Toast.LENGTH_SHORT).show();
                        Intent intentToDay = new Intent(MainActivity.this, DayActivity.class);
                        intentToDay.putExtra("Day","Friday");
                        startActivity(intentToDay);
                        Toast.makeText(MainActivity.this,"Friday selected",Toast.LENGTH_SHORT).show();
                        break;

                    }
                    default:
                        Toast.makeText(MainActivity.this,"Invalid",Toast.LENGTH_SHORT).show();
                }
            }
        });

    }
}