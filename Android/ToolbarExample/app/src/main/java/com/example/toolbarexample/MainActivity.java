//N.B: setting a theme with actionbar in manifest crashes the app
package com.example.toolbarexample;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Toolbar toolBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        toolBar = findViewById(R.id.toolBar);

        //Step 1: Setting actionbar
       // setActionBar(toolBar); //for normal toolbar
        setSupportActionBar(toolBar);
        //Step : setting back button
        if(getSupportActionBar()!=null){
            getSupportActionBar().setDisplayHomeAsUpEnabled(true);
            getSupportActionBar().setTitle("Toolbar Title");
        }
        toolBar.setTitle("Toolbar Title"); //won't work cause has low priority
        toolBar.setSubtitle("Toolbar Subtitle");


    }
    //Step 2: setting menu on action bar
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        new MenuInflater(this).inflate(R.menu.opt_menu,menu);
        return super.onCreateOptionsMenu(menu);
    }
    //Step 3: setting onclick listener on menu items
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int itemId = item.getItemId();

        if(itemId == R.id.opt_new){
            Toast.makeText(this,"'New' item selected",Toast.LENGTH_SHORT).show();
        }
        else if(itemId == R.id.opt_open){
            Toast.makeText(this,"'Open' item selected",Toast.LENGTH_SHORT).show();
        }
        else if(itemId == R.id.opt_save){
            Toast.makeText(this,"'Save' item selected",Toast.LENGTH_SHORT).show();
        }
        else if(itemId == android.R.id.home){
            super.onBackPressed();
        }


        return super.onOptionsItemSelected(item);
    }
}