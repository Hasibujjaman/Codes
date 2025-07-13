package com.example.navigationviewexample;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.view.GravityCompat;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.os.Bundle;
import android.view.Gravity;
import android.view.MenuItem;
import android.widget.Toast;

import com.google.android.material.navigation.NavigationView;

public class MainActivity extends AppCompatActivity {
    DrawerLayout drawerLayout;
    NavigationView navigationView;
    Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        drawerLayout = findViewById(R.id.drawerLayout);
        navigationView = findViewById(R.id.navigationView);
        toolbar = findViewById(R.id.toolbar);

        //setting fragment for startup of app
        loadFragment(new FragmentSat(), false);

        //step 1: setting toolbar
        setSupportActionBar(toolbar); // make sure that a theme with no actionbar is set in manifest file
        //step 2: setting action bar toggle
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(this,drawerLayout,toolbar,R.string.open_drawer,R.string.close_drawer);
        drawerLayout.addDrawerListener(toggle);
        toggle.syncState();
        //step 3:setting click listener on navigation view item
        navigationView.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                int id = item.getItemId();

                if(id == R.id.itemSat){
                    loadFragment(new FragmentSat(), true);
                    Toast.makeText(MainActivity.this,"Fragment Sat is loaded",Toast.LENGTH_SHORT).show();
                }
                else if(id == R.id.itemSun){

                }
                else if(id == R.id.itemMon){

                }
                else if(id == R.id.itemTue){

                }
                else if(id == R.id.itemWed){

                }
                else if(id == R.id.itemThu){

                }
                else{
                    loadFragment(new FragmentFri(), true);
                    Toast.makeText(MainActivity.this,"Fragment Fri is loaded",Toast.LENGTH_SHORT).show();

                }

                drawerLayout.closeDrawer(GravityCompat.START); // closes drawer on clicking drawer item

                return true;
            }
        });


    }

    private void loadFragment(Fragment fragment, boolean is_loaded){
        FragmentManager fm = getSupportFragmentManager();
        FragmentTransaction ft = fm.beginTransaction();
        if(is_loaded){
            ft.replace(R.id.frameContainer,fragment);
        }
        else{
            ft.add(R.id.frameContainer,fragment);
        }
        ft.commit();
    }

    @Override
    public void onBackPressed() {
        if(drawerLayout.isDrawerOpen(GravityCompat.START))
            drawerLayout.closeDrawer(GravityCompat.START);
        else
            super.onBackPressed();
    }
}