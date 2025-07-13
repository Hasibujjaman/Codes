package com.example.dailyroutine;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class RVAdapter extends RecyclerView.Adapter<RVAdapter.ViewHolder>{
    //private String day = DayActivity.day;


    //Inner ViewHolder class
    public static class ViewHolder extends RecyclerView.ViewHolder{
        RelativeLayout rlRow;
        ImageView imgDes;
        TextView txtTask, txtTime, txtAI;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            rlRow = itemView.findViewById(R.id.rlRow);
            imgDes = itemView.findViewById(R.id.imgDes);
            txtTask = itemView.findViewById(R.id.txtTask);
            txtTime = itemView.findViewById(R.id.txtTime);
            txtAI = itemView.findViewById(R.id.txtAI);

        }
    }





    Context context;
    ArrayList<TaskSat> arrListRVAdapterSat; // these arrays hold all the data that are needed to show on RV
    ArrayList<TaskSun> arrListRVAdapterSun;
    ArrayList<TaskMon> arrListRVAdapterMon;
    ArrayList<TaskTue> arrListRVAdapterTue;
    ArrayList<TaskWed> arrListRVAdapterWed;
    ArrayList<TaskThu> arrListRVAdapterThu;
    ArrayList<TaskFri> arrListRVAdapterFri;
    //DB declared
    DBHelper dbHelperRVAdapter;

    public RVAdapter(Context context) {
        this.context = context;
        dbHelperRVAdapter = DBHelper.getDB(context); //The DB of DayActivity is referenced here
    }


    public void setArrListRVAdapterSat(ArrayList<TaskSat> arrListRVAdapterSat) {
        this.arrListRVAdapterSat = arrListRVAdapterSat;
    }

    public void setArrListRVAdapterSun(ArrayList<TaskSun> arrListRVAdapterSun) {
        this.arrListRVAdapterSun = arrListRVAdapterSun;
    }

    public void setArrListRVAdapterMon(ArrayList<TaskMon> arrListRVAdapterMon) {
        this.arrListRVAdapterMon = arrListRVAdapterMon;
    }

    public void setArrListRVAdapterTue(ArrayList<TaskTue> arrListRVAdapterTue) {
        this.arrListRVAdapterTue = arrListRVAdapterTue;
    }

    public void setArrListRVAdapterWed(ArrayList<TaskWed> arrListRVAdapterWed) {
        this.arrListRVAdapterWed = arrListRVAdapterWed;
    }

    public void setArrListRVAdapterThu(ArrayList<TaskThu> arrListRVAdapterThu) {
        this.arrListRVAdapterThu = arrListRVAdapterThu;
    }

    public void setArrListRVAdapterFri(ArrayList<TaskFri> arrListRVAdapterFri) {
        this.arrListRVAdapterFri = arrListRVAdapterFri;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_model, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        switch (DayActivity.day){
            case "Saturday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterSat.get(position).task);
                holder.txtTime.setText(arrListRVAdapterSat.get(position).time);
                holder.txtAI.setText(arrListRVAdapterSat.get(position).ai);


                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        int k = holder.getAdapterPosition(); //most important mystery


                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterSat.get(holder.getAdapterPosition()).task);
                        edtTime.setText(arrListRVAdapterSat.get(holder.getAdapterPosition()).time);
                        edtAI.setText(arrListRVAdapterSat.get(holder.getAdapterPosition()).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {

                                String updatedTask = "", updatedTime = "", updateAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updateAI = edtAI.getText().toString();

                                    arrListRVAdapterSat.set(k, new TaskSat(k, updateAI, arrListRVAdapterSat.get(k).img,
                                                                                updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(holder.getAdapterPosition());

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskSatDAO().updateTask(new TaskSat(k, updateAI, arrListRVAdapterSat.get(k).img,
                                                                                            updatedTask, updatedTime)); //DB updated

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {
                        int k = holder.getAdapterPosition();
                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterSat.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskSatDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterSat.size(); j++) {
                                            dbHelperRVAdapter.taskSatDAO().insertTask(new TaskSat(j, arrListRVAdapterSat.get(j).ai,arrListRVAdapterSat.get(j).img,
                                                                                            arrListRVAdapterSat.get(j).task, arrListRVAdapterSat.get(j).time));
                                        }

                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Sunday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterSun.get(position).task);
                holder.txtTime.setText(arrListRVAdapterSun.get(position).time);
                holder.txtAI.setText(arrListRVAdapterSun.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {

                        int k = holder.getAdapterPosition();

                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterSun.get(k).task);
                        edtTime.setText(arrListRVAdapterSun.get(k).time);
                        edtAI.setText(arrListRVAdapterSun.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updatedAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updatedAI = edtAI.getText().toString();
                                    arrListRVAdapterSun.set(k,
                                            new TaskSun(k, updatedAI, arrListRVAdapterSun.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskSunDAO().updateTask(new TaskSun(k, updatedAI, arrListRVAdapterSun.get(k).img,
                                                                                    updatedTask, updatedTime)); //DB updated

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterSun.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskSunDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterSun.size(); j++) {
                                            dbHelperRVAdapter.taskSunDAO().insertTask(new TaskSun(j, arrListRVAdapterSun.get(j).ai, arrListRVAdapterSun.get(j).img,
                                                    arrListRVAdapterSun.get(j).task, arrListRVAdapterSun.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Monday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterMon.get(position).task);
                holder.txtTime.setText(arrListRVAdapterMon.get(position).time);
                holder.txtAI.setText(arrListRVAdapterMon.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {

                    int k = holder.getAdapterPosition();

                    @Override
                    public void onClick(View view) {
                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterMon.get(k).task);
                        edtTime.setText(arrListRVAdapterMon.get(k).time);
                        edtAI.setText(arrListRVAdapterMon.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updatedAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updatedAI = edtAI.getText().toString();
                                    arrListRVAdapterMon.set(k,
                                            new TaskMon(k, updatedAI, arrListRVAdapterMon.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskMonDAO().updateTask(new TaskMon(k, updatedAI, arrListRVAdapterMon.get(k).img,
                                                                        updatedTask, updatedTime));

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterMon.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskMonDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterMon.size(); j++) {
                                            dbHelperRVAdapter.taskMonDAO().insertTask(new TaskMon(j, arrListRVAdapterMon.get(j).ai, arrListRVAdapterMon.get(j).img,
                                                    arrListRVAdapterMon.get(j).task, arrListRVAdapterMon.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Tuesday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterTue.get(position).task);
                holder.txtTime.setText(arrListRVAdapterTue.get(position).time);
                holder.txtAI.setText(arrListRVAdapterTue.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {

                        int k = holder.getAdapterPosition();

                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterTue.get(k).task);
                        edtTime.setText(arrListRVAdapterTue.get(k).time);
                        edtAI.setText(arrListRVAdapterTue.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updatedAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updatedAI = edtAI.getText().toString();
                                    arrListRVAdapterTue.set(k,
                                            new TaskTue(k, updatedAI, arrListRVAdapterTue.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskTueDAO().updateTask(new TaskTue(k, updatedAI, arrListRVAdapterTue.get(k).img,
                                            updatedTask, updatedTime));

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterTue.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskTueDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterTue.size(); j++) {
                                            dbHelperRVAdapter.taskTueDAO().insertTask(new TaskTue(j, arrListRVAdapterTue.get(j).ai, arrListRVAdapterTue.get(j).img,
                                                    arrListRVAdapterTue.get(j).task, arrListRVAdapterTue.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Wednesday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterWed.get(position).task);
                holder.txtTime.setText(arrListRVAdapterWed.get(position).time);
                holder.txtAI.setText(arrListRVAdapterWed.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {

                        int k = holder.getAdapterPosition();

                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterWed.get(k).task);
                        edtTime.setText(arrListRVAdapterWed.get(k).time);
                        edtAI.setText(arrListRVAdapterWed.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updatedAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updatedAI = edtAI.getText().toString();
                                    arrListRVAdapterWed.set(k,
                                            new TaskWed(k, updatedAI, arrListRVAdapterWed.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskWedDAO().updateTask(new TaskWed(k, updatedAI, arrListRVAdapterWed.get(k).img,
                                            updatedTask, updatedTime));

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterWed.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskWedDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterWed.size(); j++) {
                                            dbHelperRVAdapter.taskWedDAO().insertTask(new TaskWed(j, arrListRVAdapterWed.get(j).ai, arrListRVAdapterWed.get(j).img,
                                                    arrListRVAdapterWed.get(j).task, arrListRVAdapterWed.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Thursday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterThu.get(position).task);
                holder.txtTime.setText(arrListRVAdapterThu.get(position).time);
                holder.txtAI.setText(arrListRVAdapterThu.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {

                        int k = holder.getAdapterPosition();

                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterThu.get(k).task);
                        edtTime.setText(arrListRVAdapterThu.get(k).time);
                        edtAI.setText(arrListRVAdapterThu.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updateAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updateAI = edtAI.getText().toString();
                                    arrListRVAdapterThu.set(k,
                                            new TaskThu(k, updateAI, arrListRVAdapterThu.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskThuDAO().updateTask(new TaskThu(k, updateAI, arrListRVAdapterThu.get(k).img,
                                            updatedTask, updatedTime));

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterThu.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskThuDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterThu.size(); j++) {
                                            dbHelperRVAdapter.taskThuDAO().insertTask(new TaskThu(j, arrListRVAdapterThu.get(j).ai, arrListRVAdapterThu.get(j).img,
                                                    arrListRVAdapterThu.get(j).task, arrListRVAdapterThu.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            case "Friday" :{
                //holder.imgDes.setImageResource(arrListRVAdapterSat.get(position).img);
                holder.txtTask.setText(arrListRVAdapterFri.get(position).task);
                holder.txtTime.setText(arrListRVAdapterFri.get(position).time);
                holder.txtAI.setText(arrListRVAdapterFri.get(position).ai);

                //(1) Edit recycler view item and (2) update DB
                //(1)
                holder.rlRow.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {

                        int k = holder.getAdapterPosition();

                        Dialog dialog = new Dialog(context);
                        dialog.setContentView(R.layout.add_update_task);
                        dialog.show();

                        TextView txtDialogTitle = dialog.findViewById(R.id.txtTitle);
                        EditText edtTask = dialog.findViewById(R.id.edtTask);
                        EditText edtTime = dialog.findViewById(R.id.edtTime);
                        EditText edtAI = dialog.findViewById(R.id.edtAI);
                        Button btnAction = dialog.findViewById(R.id.btnAddOrUpdate);

                        txtDialogTitle.setText("Edit Task");
                        btnAction.setText("Update");
                        edtTask.setText(arrListRVAdapterFri.get(k).task);
                        edtTime.setText(arrListRVAdapterFri.get(k).time);
                        edtAI.setText(arrListRVAdapterFri.get(k).ai);

                        btnAction.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View view) {
                                String updatedTask = "", updatedTime = "", updatedAI = "";
                                if(!edtTask.getText().toString().equals("") && !edtTime.getText().toString().equals("")){
                                    updatedTask = edtTask.getText().toString();
                                    updatedTime = edtTime.getText().toString();
                                    updatedAI = edtAI.getText().toString();
                                    arrListRVAdapterFri.set(k,
                                            new TaskFri(k, updatedAI, arrListRVAdapterFri.get(k).img,
                                                    updatedTask, updatedTime)); //task updated
                                    notifyItemChanged(k);

                                    //(2)
                                    //DBHelper dbHelperRVAdapter = DBHelper.getDB(context);
                                    dbHelperRVAdapter.taskFriDAO().updateTask(new TaskFri(k, updatedAI, arrListRVAdapterFri.get(k).img,
                                            updatedTask, updatedTime));

                                    dialog.dismiss();
                                    Toast.makeText(context,"Task has been updated",Toast.LENGTH_SHORT).show();

                                }
                                else
                                    Toast.makeText(context,"Invalid name or number",Toast.LENGTH_SHORT).show();


                            }
                        });

                    }
                });
                //Delete recycler view item
                holder.rlRow.setOnLongClickListener(new View.OnLongClickListener() {
                    @Override
                    public boolean onLongClick(View view) {

                        int k = holder.getAdapterPosition();

                        AlertDialog.Builder builder = new AlertDialog.Builder(context)
                                .setTitle("Delete Task")
                                .setMessage("Selected task will be deleted")
                                .setIcon(R.drawable.baseline_delete_24)
                                .setPositiveButton("Delete", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {
                                        arrListRVAdapterFri.remove(k); //task removed from AL
                                        notifyItemRemoved(k);
                                        //Delete from DB here also
                                        dbHelperRVAdapter.taskFriDAO().deleteAllTasks();
                                        for(int j = 0; j < arrListRVAdapterFri.size(); j++) {
                                            dbHelperRVAdapter.taskFriDAO().insertTask(new TaskFri(j, arrListRVAdapterFri.get(j).ai, arrListRVAdapterFri.get(j).img,
                                                    arrListRVAdapterFri.get(j).task, arrListRVAdapterFri.get(j).time));
                                        }



                                    }
                                })
                                .setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i) {

                                    }
                                });
                        builder.show();

                        return true;
                    }
                });

                break;
            }
            default:

        }


    }




    @Override
    public int getItemCount() {
        switch (DayActivity.day){
            case "Saturday" :{
                return arrListRVAdapterSat.size();
            }
            case "Sunday" :{
                return arrListRVAdapterSun.size();
            }
            case "Monday" :{
                return arrListRVAdapterMon.size();
            }
            case "Tuesday" :{
                return arrListRVAdapterTue.size();

            }
            case "Wednesday" :{
                return arrListRVAdapterWed.size();
            }
            case "Thursday" :{
                return arrListRVAdapterThu.size();
            }
            case "Friday" :{
                return arrListRVAdapterFri.size();
            }
            default:

        }
        return -1;
    }



}
