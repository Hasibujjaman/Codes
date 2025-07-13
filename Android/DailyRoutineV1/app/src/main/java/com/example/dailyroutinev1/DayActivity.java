package com.example.dailyroutinev1;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class DayActivity extends AppCompatActivity {
    public static String day;
    private RecyclerView recView;

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

        recView = findViewById(R.id.recyclerView);

        Intent intentFromMain = getIntent();
        day = intentFromMain.getStringExtra("Day");

        Toolbar toolbarDay = findViewById(R.id.toolbarDay);
        setSupportActionBar(toolbarDay);
        getSupportActionBar().setTitle(day);

        //creating DB
        DBHelper dbHelper = DBHelper.getDB(this);
        Context contextDayActivity = DayActivity.this;

        RVAdapter adapter = new RVAdapter(contextDayActivity);

        //(1)Fetching data matching day from DB and store it to arrListDayActX to use in Recyclerview adapter and
        //(2)Setting views  on recyclerview by recyclerview adapter
        switch (day){
            case "Saturday" : {
                arrListDayActSat = (ArrayList<TaskSat>)dbHelper.taskSatDAO().getAllTasks(); //(1)

                adapter.setArrListRVAdapterSat(arrListDayActSat); //(2)
                recView.setAdapter(adapter); //(2)
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this)); //(2)
                break;
            }
            case "Sunday" : {
                arrListDayActSun = (ArrayList<TaskSun>)dbHelper.taskSunDAO().getAllTasks();

                adapter.setArrListRVAdapterSun(arrListDayActSun);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Monday" : {
                arrListDayActMon = (ArrayList<TaskMon>)dbHelper.taskMonDAO().getAllTasks();

                adapter.setArrListRVAdapterMon(arrListDayActMon);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;

            }
            case "Tuesday" : {
                arrListDayActTue = (ArrayList<TaskTue>)dbHelper.taskTueDAO().getAllTasks();

                adapter.setArrListRVAdapterTue(arrListDayActTue);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Wednesday" : {
                arrListDayActWed = (ArrayList<TaskWed>)dbHelper.taskWedDAO().getAllTasks();

                adapter.setArrListRVAdapterWed(arrListDayActWed);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Thursday" : {
                arrListDayActThu = (ArrayList<TaskThu>)dbHelper.taskThuDAO().getAllTasks();

                adapter.setArrListRVAdapterThu(arrListDayActThu);
                recView.setAdapter(adapter);
                recView.setLayoutManager(new LinearLayoutManager(DayActivity.this));
                break;
            }
            case "Friday" : {
                arrListDayActFri = (ArrayList<TaskFri>)dbHelper.taskFriDAO().getAllTasks();

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
                        if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")) {
                            task = edtTask.getText().toString();
                            time = edtTime.getText().toString();
                            ai = edtAI.getText().toString();

                            edtTask.setText("");
                            edtTime.setText("");
                            edtAI.setText("");

                            switch (day){
                                case "Saturday" :{
                                    arrListDayActSat.add(new TaskSat(arrListDayActSat.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActSat.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActSat.size() - 1); // (1)
                                    //adapter.notifyDataSetChanged(); also works

                                    dbHelper.taskSatDAO().insertTask(new TaskSat(arrListDayActSat.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Sunday" : {
                                    arrListDayActSun.add(new TaskSun(arrListDayActSun.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActSun.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActSun.size() - 1); // (1)

                                    dbHelper.taskSunDAO().insertTask(new TaskSun(arrListDayActSun.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Monday" : {
                                    arrListDayActMon.add(new TaskMon(arrListDayActMon.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActMon.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActMon.size() - 1); // (1)

                                    dbHelper.taskMonDAO().insertTask(new TaskMon(arrListDayActMon.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Tuesday" : {
                                    arrListDayActTue.add(new TaskTue(arrListDayActTue.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActTue.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActTue.size() - 1); // (1)

                                    dbHelper.taskTueDAO().insertTask(new TaskTue(arrListDayActTue.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Wednesday" : {
                                    arrListDayActWed.add(new TaskWed(arrListDayActWed.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActWed.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActWed.size() - 1); // (1)

                                    dbHelper.taskWedDAO().insertTask(new TaskWed(arrListDayActWed.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Thursday" : {
                                    arrListDayActThu.add(new TaskThu(arrListDayActThu.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActThu.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActThu.size() - 1); // (1)

                                    dbHelper.taskThuDAO().insertTask(new TaskThu(arrListDayActThu.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                case "Friday" : {
                                    arrListDayActFri.add(new TaskFri(arrListDayActFri.size(), ai, task, time)); // (1)
                                    recView.scrollToPosition(arrListDayActFri.size() - 1);
                                    adapter.notifyItemInserted(arrListDayActFri.size() - 1); // (1)

                                    dbHelper.taskFriDAO().insertTask(new TaskFri(arrListDayActFri.size()-1, ai, task, time)); //(2)
                                    break;
                                }
                                default:
                                    Toast.makeText(DayActivity.this,"Error in data inserting to DB",Toast.LENGTH_SHORT).show();

                            }

                            dialog.dismiss();
                            Toast.makeText(DayActivity.this, "Task added", Toast.LENGTH_SHORT).show();
                        }
                    }
                });



            }
        });




    }
}