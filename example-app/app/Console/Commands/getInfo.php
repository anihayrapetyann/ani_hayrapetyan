<?php

namespace App\Console\Commands;

use App\Models\User;
use Illuminate\Console\Command;

class getInfo extends Command
{
    /**
     * The name and signature of the console command.
     *
     * @var string
     */
    protected $signature = 'get:user {userid}';

    /**
     * The console command description.
     *
     * @var string
     */
    protected $description = 'Gef info about user from db';

    /**
     * Execute the console command.
     */
    public function handle()
    {
        $id = $this->argument('userid');
        $user = User::query()->where('id', $id)->first();
        if(!$user){
            return $this->error('There is no user with '.$id.' id');
        }
        dd($user->toArray());
        return $user;
    }
}
