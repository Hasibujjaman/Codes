package com.example.dailyroutinev2;

import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.ActionBarDrawerToggle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.view.GravityCompat;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.navigation.NavigationView;

import java.util.ArrayList;

public class DayActivity extends AppCompatActivity {

    DrawerLayout drawerLayoutDayAct;
    public static String day;
    private RecyclerView recView;
    private RVAdapter adapter;
    private DBHelper dbHelper;

    private ArrayList<TaskSat> arrListDayActSat = new ArrayList<>();
    private ArrayList<TaskSun> arrListDayActSun = new ArrayList<>();
    private ArrayList<TaskMon> arrListDayActMon = new ArrayList<>();
    private ArrayList<TaskTue> arrListDayActTue = new ArrayList<>();
    private ArrayList<TaskWed> arrListDayActWed = new ArrayList<>();
    private ArrayList<TaskThu> arrListDayActThu = new ArrayList<>();
    private ArrayList<TaskFri> arrListDayActFri = new ArrayList<>();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_day);

        Intent intentFromMain = getIntent();
        day = intentFromMain.getStringExtra("Day");

        //Setting toolbar
        Toolbar toolbarDayAct= findViewById(R.id.toolbarDay);
        setSupportActionBar(toolbarDayAct);
        getSupportActionBar().setTitle(day);

        //setting navigation drawer
        drawerLayoutDayAct = findViewById(R.id.drawerLayoutDayAct);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(this, drawerLayoutDayAct, toolbarDayAct, R.string.open_drawer, R.string.close_drawer);
        drawerLayoutDayAct.addDrawerListener(toggle);
        toggle.syncState();
        NavigationView navigationViewDayAct = findViewById(R.id.navigationViewDayAct);
//        navigationViewDayAct.setNavigationItemSelectedListener(new NavigationView.OnNavigationItemSelectedListener() {
//            @Override
//            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
//                int id = item.getItemId();
//
//                if(id == R.id.itemSat){
//                    day = "Saturday";
//                    recreate();
//
//                }
//                else if(id == R.id.itemSun){
//
//                }
//                else if(id == R.id.itemMon){
//
//                }
//                else if(id == R.id.itemTue){
//
//                }
//                else if(id == R.id.itemWed){
//
//                }
//                else if(id == R.id.itemThu){
//
//                }
//                else{
//
//                }
//
//                return false;
//            }
//        });





        //creating DB
        dbHelper = DBHelper.getDB(this);
        Context contextDayActivity = DayActivity.this;

        adapter = new RVAdapter(contextDayActivity);

        recView = findViewById(R.id.recyclerView);

        //(1)Fetching data matching day from DB and store it to arrListDayActX to use in Recyclerview adapter and
        //(2)Setting views  on recyclerview by recyclerview adapter
        switch (day) {
            case "Saturday": {
                arrListDayActSat = (ArrayList<TaskSat>) dbHelper.taskSatDAO().getAllTasks(); //(1)

                adapter.setArrListRVAdapterSat(arrListDayActSat); //(2)
                recView.setAdapter(adapter); //(2)
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this)); //(2)
                break;
            }
            case "Sunday": {
                arrListDayActSun = (ArrayList<TaskSun>) dbHelper.taskSunDAO().getAllTasks();

                adapter.setArrListRVAdapterSun(arrListDayActSun);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Monday": {
                arrListDayActMon = (ArrayList<TaskMon>) dbHelper.taskMonDAO().getAllTasks();

                adapter.setArrListRVAdapterMon(arrListDayActMon);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;

            }
            case "Tuesday": {
                arrListDayActTue = (ArrayList<TaskTue>) dbHelper.taskTueDAO().getAllTasks();

                adapter.setArrListRVAdapterTue(arrListDayActTue);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Wednesday": {
                arrListDayActWed = (ArrayList<TaskWed>) dbHelper.taskWedDAO().getAllTasks();

                adapter.setArrListRVAdapterWed(arrListDayActWed);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Thursday": {
                arrListDayActThu = (ArrayList<TaskThu>) dbHelper.taskThuDAO().getAllTasks();

                adapter.setArrListRVAdapterThu(arrListDayActThu);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Friday": {
                arrListDayActFri = (ArrayList<TaskFri>) dbHelper.taskFriDAO().getAllTasks();

                adapter.setArrListRVAdapterFri(arrListDayActFri);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            default:


        }

        FloatingActionButton btnAddTask = findViewById(R.id.btnAddTask);

        //Adding new task to recyclerview
        btnAddTask.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Dialog dialog = new Dialog(DayActivity.this);
                dialog.setContentView(R.layout.add_update_task);
                dialog.show();

                EditText edtTask, edtTime, edtAI;
                Button btnAdd;
                edtTask = dialog.findViewById(R.id.edtTask);
                edtTime = dialog.findViewById(R.id.edtTime);
                edtAI = dialog.findViewById(R.id.edtAI);
                btnAdd = dialog.findViewById(R.id.btnAddOrUpdate);

                btnAdd.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        //(1)store new data to arraylist and reflect it on RV and (2) store new data to DB
                        String task = "", time = "", ai = "";
                        if (!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")) {
                            task = edtTask.getText().toString();
                            time = edtTime.getText().toString();
                            ai = edtAI.getText().toString();

                            edtTask.setText("");
                            edtTime.setText("");
                            edtAI.setText("");

                            switch (day) {
                                case "Saturday": {
                                    arrListDayActSat.add(new TaskSat(arrListDayActSat.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActSat.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActSat.size() - 1); // (1)
                                    //adapter.notifyDataSetChanged(); also works

                                    dbHelper.taskSatDAO().insertTask(new TaskSat(arrListDayActSat.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Sunday": {
                                    arrListDayActSun.add(new TaskSun(arrListDayActSun.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActSun.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActSun.size() - 1); // (1)

                                    dbHelper.taskSunDAO().insertTask(new TaskSun(arrListDayActSun.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Monday": {
                                    arrListDayActMon.add(new TaskMon(arrListDayActMon.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActMon.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActMon.size() - 1); // (1)

                                    dbHelper.taskMonDAO().insertTask(new TaskMon(arrListDayActMon.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Tuesday": {
                                    arrListDayActTue.add(new TaskTue(arrListDayActTue.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActTue.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActTue.size() - 1); // (1)

                                    dbHelper.taskTueDAO().insertTask(new TaskTue(arrListDayActTue.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Wednesday": {
                                    arrListDayActWed.add(new TaskWed(arrListDayActWed.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActWed.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActWed.size() - 1); // (1)

                                    dbHelper.taskWedDAO().insertTask(new TaskWed(arrListDayActWed.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Thursday": {
                                    arrListDayActThu.add(new TaskThu(arrListDayActThu.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActThu.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActThu.size() - 1); // (1)

                                    dbHelper.taskThuDAO().insertTask(new TaskThu(arrListDayActThu.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Friday": {
                                    arrListDayActFri.add(new TaskFri(arrListDayActFri.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActFri.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActFri.size() - 1); // (1)

                                    dbHelper.taskFriDAO().insertTask(new TaskFri(arrListDayActFri.size() - 1, ai, task, time)); //(2)
                                    break;
                                }
                                default:
                                    Toast.makeText(DayActivity.this, "Error in data inserting to DB", Toast.LENGTH_SHORT).show();

                            }

                            dialog.dismiss();
                            Toast.makeText(DayActivity.this, "Task added", Toast.LENGTH_SHORT).show();
                        }
                        else
                            Toast.makeText(contextDayActivity,"Enter Task and Time both",Toast.LENGTH_SHORT).show();
                    }
                });


            }
        });


    }

    //for appbar menu
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        new MenuInflater(DayActivity.this).inflate(R.menu.toolbar_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        int itemId = item.getItemId();

        if (itemId == R.id.opt_clear) {
            switch (day) {
                case "Saturday": {
                    int size = arrListDayActSat.size();
                    arrListDayActSat.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskSatDAO().deleteAllTasks();
                    break;

                }
                case "Sunday": {
                    int size = arrListDayActSun.size();
                    arrListDayActSun.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskSunDAO().deleteAllTasks();
                    break;

                }
                case "Monday": {
                    int size = arrListDayActMon.size();
                    arrListDayActMon.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskMonDAO().deleteAllTasks();
                    break;

                }
                case "Tuesday": {
                    int size = arrListDayActTue.size();
                    arrListDayActTue.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskTueDAO().deleteAllTasks();
                    break;

                }
                case "Wednesday": {
                    int size = arrListDayActWed.size();
                    arrListDayActWed.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskWedDAO().deleteAllTasks();
                    break;

                }
                case "Thursday": {
                    int size = arrListDayActThu.size();
                    arrListDayActThu.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskThuDAO().deleteAllTasks();
                    break;

                }
                case "Friday": {
                    int size = arrListDayActFri.size();
                    arrListDayActFri.clear();
                    adapter.notifyItemRangeRemoved(0,size);
                    dbHelper.taskFriDAO().deleteAllTasks();
                    break;

                }
                default:

            }

        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onBackPressed() {
        if(drawerLayoutDayAct.isDrawerOpen(GravityCompat.START))
            drawerLayoutDayAct.closeDrawer(GravityCompat.START);
        else
            super.onBackPressed();
    }
}