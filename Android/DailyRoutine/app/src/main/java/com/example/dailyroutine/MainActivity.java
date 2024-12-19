package com.example.dailyroutine;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.view.GravityCompat;
import androidx.drawerlayout.widget.DrawerLayout;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.navigation.NavigationView;

public class MainActivity extends AppCompatActivity {
    DrawerLayout drawerLayoutMainAct;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbarMainAct;
        ListView listView;

        toolbarMainAct = findViewById(R.id.toolbarMain);
        listView = findViewById(R.id.listView);

        setSupportActionBar(toolbarMainAct);
        getSupportActionBar().setTitle("Daily Routine");

        //setting navigation drawer
        drawerLayoutMainAct = findViewById(R.id.drawerLayoutMainAct);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(this, drawerLayoutMainAct, toolbarMainAct, R.string.open_drawer, R.string.close_drawer);
        drawerLayoutMainAct.addDrawerListener(toggle);
        toggle.syncState();
        NavigationView navigationViewMainAct = findViewById(R.id.navigationViewMainAct);
        navigationViewMainAct.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                int id = item.getItemId();

                if(id == R.id.itemSat){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Saturday");
                    startActivity(intent);
                }
                else if(id == R.id.itemSun){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Sunday");
                    startActivity(intent);
                }
                else if(id == R.id.itemMon){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Monday");
                    startActivity(intent);

                }
                else if(id == R.id.itemTue){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Tuesday");
                    startActivity(intent);

                }
                else if(id == R.id.itemWed){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Wednesday");
                    startActivity(intent);

                }
                else if(id == R.id.itemThu){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Thursday");
                    startActivity(intent);

                }
                else if(id == R.id.itemFri){
                    Intent intent = new Intent(MainActivity.this, DayActivity.class);
                    intent.putExtra("Day", "Friday");
                    startActivity(intent);
                }
                else
                    Toast.makeText(MainActivity.this,"Already in Home",Toast.LENGTH_SHORT).show();

                drawerLayoutMainAct.closeDrawer(GravityCompat.START);

                return false;
            }
        });

        //setting adapter on listview
        // String[] title = getResources().getStringArray(R.array.Days);
        String[] title = new String[]{"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
        String[] time = new String[]{"", "", "", "", "", "", ""};
        String[] ai = new String[]{"", "", "", "", "", "", ""};


        SimpleAdapter adapter = new SimpleAdapter(MainActivity.this,title,time,ai);
        listView.setAdapter(adapter);

        //setting listener on listview items
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

    @Override
    public void onBackPressed() {
        if(drawerLayoutMainAct.isDrawerOpen(GravityCompat.START))
            drawerLayoutMainAct.closeDrawer(GravityCompat.START);
        else{
            Intent intentTOHomeWindow = new Intent(Intent.ACTION_MAIN);
            intentTOHomeWindow.addCategory(Intent.CATEGORY_HOME);
            intentTOHomeWindow.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            startActivity(intentTOHomeWindow);
        }

    }
}